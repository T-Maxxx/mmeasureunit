#include <mmu/area.hpp>

#include <iostream>


using namespace mu::area;

static_assert(1_m2 == 1'000'000_mm2);
static_assert(1_m2 == 10'000_cm2);
static_assert(1_m2 == 100_dm2);
static_assert(1_m2 == 100_dm2);

static_assert(100_mm2 == 1_cm2);
static_assert(100_cm2 == 1_dm2);
static_assert(100_dm2 == 1_m2);

static_assert(100_dm2 == 1_m2);

static_assert(1_in2 == 0.00064516_m2);

static_assert(1_ft2 == 144_in2);

static_assert(1_yd2 == 9_ft2);

static_assert(1_ac == 4'840_yd2);

static_assert(1_mi2 == 640_ac);



int main()
{
    std::cout << "1ac -> yd2: " << cast<yd2>(1_ac).count();
    return 0;
}