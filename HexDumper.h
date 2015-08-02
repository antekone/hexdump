#pragma once
#include <iostream>
#include <iomanip>

namespace HexDumperNS {

class CoutWriter {
public:
    static void put(const char* str) {
        std::cout << str;
    }

    static void put(const char ch) {
        char buf[2] = { ch, 0 };
        put(buf);
    }

    static void pad(size_t len) {
        std::cout << std::setw(len);
    }
};

template <bool _want_offset,
          bool _want_header,
          typename _Writer>

class GenericStyle {
public:
    typedef _Writer Writer;
    static bool want_offset() { return _want_offset; }
    static bool want_header() { return _want_header; }
};

}

static const char* g_hextab = "0123456789ABCDEF";

template <typename _Style>
class StyledHexDumper {
public:
    typedef _Style Style;
    typedef typename Style::Writer Writer;

private:
    static uint64_t count_bchop(uint64_t n) {
        int r = 1;

        if(n < 0)
            n = (n == 0) ? UINT64_MAX : -n;

        if(n >= 100000000) {
            r += 8;
            n /= 100000000;
        }

        if(n >= 10000) {
            r += 4;
            n /= 10000;
        }

        if(n >= 100) {
            r += 2;
            n /= 100;
        }

        if(n >= 10)
            r++;

        return r;
    }

    static size_t calc_widelen(size_t size) {
        if(size > 15)
            return 16;

        return size;
    }

    static size_t calc_offsetlen(size_t offset, size_t size) {
        size_t n = count_bchop(offset + size);
        return n;
    }

    static void draw_header(size_t offset, size_t size) {
        size_t widelen = calc_widelen(offset);
        if(_Style::want_offset()) {
            Writer::pad(3 + calc_offsetlen(offset, size));
            Writer::put("-");
            Writer::pad(0);
            Writer::put("   ");
        }

        for(size_t i = 0; i < widelen; ++i) {
            Writer::put(" 0");
            Writer::put(g_hextab[i]);
        }

        Writer::put("\n");
    }

    template <typename _PointerType>
    static void draw_data(_PointerType* buf, size_t size, size_t offset) {
        bool offset_time = true;
        for(size_t i = 0; i < size; ++i) {
            char buf[3] = { g_hextab[buf[i] & 0xF0 >> 4], g_hextab[buf[i] & 0x0F], 0 };

            if(i % 16 == 0) {
                offset_time = true;
            }

            if(Style::want_offset() && offset_time) {
                char buf2[64];
                sprintf(buf2, "%llx", offset + i);
                Writer::put("\n");
                Writer::pad(3 + calc_offsetlen(offset + i, size));
                Writer::put(buf2);
                Writer::pad(0);
                Writer::put("    ");
                offset_time = false;
            }

            Writer::put(buf);
            Writer::put(" ");
        }
    }

public:
    template <typename _PointerType>
    static void print(_PointerType* buf, size_t size, size_t offset) {
        if(_Style::want_header()) {
            draw_header(offset, size);
        }

        draw_data(buf, size, offset);
    }
};

typedef StyledHexDumper<
            HexDumperNS::GenericStyle<
                true,
                true,
                HexDumperNS::CoutWriter
            >
        > HexDumper;
