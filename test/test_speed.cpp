#include <iostream>

#include <mmu/speed.hpp>


using namespace mu::speed;

static_assert(1_mps == 3.6_kmph, "MPS and KMPH conversion mismatch");
static_assert(18_kmph == 5_mps, "MPS and KMPH conversion mismatch");
static_assert(3125_miph == 1397_mps, "MIPH and MPS conversion mismatch");
static_assert(900_kn == 463_mps, "KN and MPS conversion mismatch");

int main()
{
    return 0;
}