#pragma once
#include <iostream>
#include <iomanip>

#define HD_ALIGN_DOWN(x)  ((x) & ~15)
#define HD_ALIGN_UP(x)    (HD_ALIGN_DOWN(x) + 15)

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

    static void draw_header(size_t offset, uint64_t size) {
        if(_Style::want_offset()) {
            Writer::pad(std::max<int>(9, calc_offsetlen(offset, size)));
            Writer::put("    ");
            Writer::pad(0);
            Writer::put("  ");
        }

        bool mark = false;
        for(size_t i = 0; i < 16; ++i) {
            if(i > 7 && !mark) {
                Writer::put(" -");
                mark = true;
            }

            Writer::put(" 0");
            Writer::put(g_hextab[i]);
        }

        Writer::put("\n");

        if(_Style::want_offset()) {
            Writer::pad(std::max<int>(9, calc_offsetlen(offset, size)));
            Writer::put("    ");
            Writer::pad(0);
            Writer::put("  ");
        }

        mark = false;
        for(size_t i = 0; i < 16; ++i) {
            if(i > 7 && !mark) {
                Writer::put(" -");
                mark = true;
            }

            Writer::put(" --");
        }

        Writer::put("\n");
    }

    template <typename _PointerType>
    static void draw_data(_PointerType* buf, size_t size, uint64_t offset) {
        bool offset_time = true;
        uint64_t aligned_start = HD_ALIGN_DOWN(offset);
        int offsetlen = std::max<int>(9, calc_offsetlen(aligned_start, size));
        int i = 0;
        bool mark = false;

        while(aligned_start < size + offset) {
            if(offset_time) {
                char buf2[32];
                sprintf(buf2, "%llx", (long long unsigned int) aligned_start);
                Writer::pad(offsetlen);
                Writer::put(buf2);
                Writer::put("   ");
                offset_time = false;
                mark = false;
            }

            if(aligned_start >= offset) {
                char buf2[3] = { 0, 0, 0 };

                uint8_t b = buf[aligned_start - offset];
                buf2[0] = g_hextab[(b & 0xF0) >> 4];
                buf2[1] = g_hextab[b & 15];

                if(i > 7 && !mark) {
                    Writer::put("  ");
                    mark = true;
                }

                Writer::put(buf2);
                Writer::put(" ");
            } else {
                Writer::put("   ");
            }

            aligned_start++;
            i++;

            if(i >= 16) {
                Writer::put("\n");
                offset_time = true;
                i = 0;
            }
        }
    }

public:
    template <typename _PointerType>
    static void print(_PointerType* buf, size_t size, uint64_t offset) {
        if(_Style::want_header()) {
            draw_header(offset, size);
        }

        draw_data(buf, size, offset);
        Writer::put("\n");
    }
};

typedef StyledHexDumper<
            HexDumperNS::GenericStyle<
                true,
                true,
                HexDumperNS::CoutWriter
            >
        > HexDumper;

#undef HD_ALIGN_UP
#undef HD_ALIGN_DOWN
