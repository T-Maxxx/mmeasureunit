#include <mmu/frequency.hpp>

using namespace mu::frequency::literals;

static_assert(1000_Hz == 1_kHz);
static_assert(1000_kHz == 1_MHz);
static_assert(1000_MHz == 1_GHz);

int main()
{
    return 0;
}
