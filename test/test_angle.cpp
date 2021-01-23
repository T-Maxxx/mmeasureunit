#include <mmu/angle.hpp>

using namespace mu::angle::literals;

static_assert(60_moa == 1_deg, "MOA and DEG conversion mismatch");
static_assert(60_soa == 1_moa, "SOA and MOA conversion mismatch");
static_assert(10_grad == 9_deg, "GRAD and DEG conversion mismatch");
static_assert(1_grad == 0.9_deg, "GRAD and DEG conversion mismatch");


int main()
{
    return 0;
}