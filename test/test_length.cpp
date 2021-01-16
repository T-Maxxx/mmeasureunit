#include <mmu/length.hpp>


using namespace mu::length::literals;

static_assert(1000_nm == 1_mcm, "MCM and NM conversion mismatch");
static_assert(1000_mcm == 1_mm, "MM and MCM conversion mismatch");
static_assert(10_mm == 1_cm, "CM and MM conversion mismatch");
static_assert(100_cm == 1_m, "CM and MM conversion mismatch");
static_assert(1000_m == 1_km, "M and KM conversion mismatch");
static_assert(1_in == 2.54_cm, "IN and CM conversion mismatch");
static_assert(1250_ft == 381_m, "FT and M conversion mismatch");
static_assert(1_yd == 3_ft, "YD and FT conversion mismatch");
static_assert(1_yd == 3_ft, "YD and FT conversion mismatch");
static_assert(125_mi == 201168_m, "MI and M conversion mismatch");
static_assert(1_nmi == 1852_m, "NMI and M conversion mismatch");

int main()
{
    return 0;
}
