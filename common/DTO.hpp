#pragma once

#ifndef COMMON_DTO
#define COMMON_DTO

#include <vector>
#include <array>

template <int N>
struct DEResult {
    std::array<std::vector<double>, N> y;
};

#endif