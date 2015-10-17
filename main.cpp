#include <iostream>
#include "HexDumper.h"

int main() {
    const unsigned char data[523] = {
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x06, 0x00, 0x00, 0x00, 0xf0, 0xbd, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0xbd, 0x61, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0xbd, 0x61, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x64, 0x08, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xd0, 0x16, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x06, 0x00, 0x00, 0x00, 0x08, 0xbe, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x08, 0xbe, 0x61, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x08, 0xbe, 0x61, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00, 0x54, 0x02, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x54, 0x02, 0x40, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x54, 0x02, 0x40, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x50, 0xe5, 0x74, 0x64,
        0x04, 0x00, 0x00, 0x00, 0x9c, 0x89, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x9c, 0x89, 0x41, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x9c, 0x89, 0x41, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x1c, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x1c, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x51, 0xe5, 0x74, 0x64,
        0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x52, 0xe5, 0x74, 0x64,
        0x04, 0x00, 0x00, 0x00, 0xf0, 0xbd, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0xbd, 0x61, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0xbd, 0x61, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x2f, 0x6c, 0x69, 0x62,
        0x36, 0x34, 0x2f, 0x6c, 0x64, 0x2d, 0x6c, 0x69,
        0x6e, 0x75, 0x78, 0x2d, 0x78, 0x38, 0x36, 0x2d,
        0x36, 0x34, 0x2e, 0x73, 0x6f, 0x2e, 0x32, 0x00,
        0x04, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x47, 0x4e, 0x55, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x06, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x47, 0x4e, 0x55, 0x00,
        0x70, 0xc5, 0x0d, 0xb4, 0x18, 0x4f, 0xd3, 0x9f,
        0x2b, 0x1a, 0x80, 0x55, 0x76, 0xf2, 0x1c, 0x1e,
        0xbe, 0x05, 0x2e, 0xbb, 0x16, 0x00, 0x00, 0x00,
        0x71, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x07, 0x00, 0x00, 0x00, 0xa2, 0x01, 0x40, 0x0c,
        0x12, 0x01, 0x0c, 0x3f, 0x28, 0x44, 0x00, 0x03,
        0xa8, 0x04, 0x00, 0x00, 0x71, 0x00, 0x00, 0x00,
        0x72, 0x00, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00,
        0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x75, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00,
        0x77, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00,
        0x7a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
    };

    const unsigned char data2[3] = { 1, 2, 3 };

    uint64_t ofs = 0x12345678;
    HexDumper::print(data, sizeof(data), ofs);

    std::cout << std::endl;

    HexDumper::print(data2, sizeof(data2), 0x14FA);
    return 0;
}
