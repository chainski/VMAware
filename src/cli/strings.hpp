#pragma once

#include <string>
#include <bitset>
#include "types.hpp"

#if (defined(__GNUC__) || defined(__linux__))
    #define CLI_LINUX 1
#else
    #define CLI_LINUX 0
#endif

#if (defined(__APPLE__) || defined(__APPLE_CPP__) || defined(__MACH__) || defined(__DARWIN))
    #define CLI_APPLE 1
#else
    #define CLI_APPLE 0
#endif

#if (defined(_MSC_VER) || defined(_WIN32) || defined(_WIN64) || defined(__MINGW32__))
    #define CLI_WINDOWS 1
#else
    #define CLI_WINDOWS 0
#endif

inline const std::string TH_DIM   = "\x1B[38;2;60;60;60m";
inline const std::string TH_MED   = "\x1B[38;2;120;120;120m";
inline const std::string TH_WHITE = "\x1B[38;2;255;255;255m";
inline const std::string TH_RST   = "\x1B[0m";

#if (CLI_WINDOWS)
inline const std::string TH_BRIGHT = "\x1B[38;2;180;180;180m";
inline const std::string TH_RED    = "\x1B[38;2;220;0;0m";
#endif

inline std::string bold = "\x1B[1;97m";
inline std::string underline = "\x1B[4m";
inline std::string ansi_exit = "\x1B[0m";
inline std::string red = "\x1B[31m";
inline std::string orange = "\x1B[38;2;180;50;0m";
inline std::string green = "\x1B[38;2;60;60;60m";
inline std::string red_orange = "\x1B[31m";
inline std::string green_orange = "\x1B[38;2;60;60;60m";
inline std::string grey = "\x1B[38;2;60;60;60m";
inline std::string white = "\x1B[38;2;255;255;255m";

enum arg_enum : u8 {
    HELP, VERSION, ALL, DETECT, STDOUT, BRAND, BRAND_LIST, PERCENT, CONCLUSION, NUMBER, TYPE, OUTPUT, NOTES, HIGH_THRESHOLD, NO_ANSI, DYNAMIC, VERBOSE, ENUMS, DETECTED_ONLY, JSON, NULL_ARG
};

constexpr u8 arg_bits = static_cast<u8>(NULL_ARG) + 1;
inline std::bitset<arg_bits> arg_bitset;

inline u8 unsupported_count = 0;
inline u8 supported_count   = 0;
inline u8 no_perms_count    = 0;
inline u8 disabled_count    = 0;

inline std::string detected     = ("\x1B[97m[\x1B[31m  DETECTED  \x1B[97m]\x1B[0m");
inline std::string not_detected = ("   \x1B[97m[\x1B[90mNOT DETECTED\x1B[97m]\x1B[0m");
