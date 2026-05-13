#pragma once

#include <cstddef>
#include <string>
#include "types.hpp"

struct SHA256 {
    u8 buf[64] = {};
    u32 len = 0;
    u64 bits = 0;
    u32 s[8] = {};

    SHA256();

    static u32 rotr(u32 x, int n);
    static u32 ch(u32 x, u32 y, u32 z);
    static u32 maj(u32 x, u32 y, u32 z);
    static u32 ep0(u32 x);
    static u32 ep1(u32 x);
    static u32 sig0(u32 x);
    static u32 sig1(u32 x);

    void transform();

    void update(const u8* data, size_t n);

    void final(u8 out[32]);
};

std::string exe_path();
std::string compute_self_sha256();
