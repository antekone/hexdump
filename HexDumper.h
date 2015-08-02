#pragma once

namespace HexDumperNS {

template <bool _want_offset,
          bool _want_header,
          uint64_t _offset>

class GenericStyle {
public:
    static bool want_offset() { return _want_offset; }
    static bool want_header() { return _want_header; }
    static uint64_t convert_offset(uint64_t o) { return _offset + o; }
};

}

template <typename _Style>
class StyledHexDumper {
private:
    size_t calc_widelen(size_t size) {
        if(size > 15)
            return 16;

        return size;
    }

public:
    template <typename _PointerType>
    static void print(_PointerType* buf, size_t size) {
        if(_Style::want_header()) {
            draw_header(calc_widelen(size));
        }
    }
};

typedef StyledHexDumper<
            HexDumperNS::GenericStyle<
                true,
                true,
                0
            >
        > HexDumper;
