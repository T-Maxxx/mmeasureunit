#include <mmu/pressure.hpp>

using namespace mu::pressure::literals;

static_assert(1000_Pa == 1_kPa);
static_assert(1000_kPa == 1_MPa);
static_assert(100'000_Pa == 1_bar);
static_assert(1000_mbar == 1_bar);
static_assert(98'066.5_Pa == 1_at);
static_assert(101325_Pa == 1_atm);
static_assert(760_mmHg == 1_atm);
static_assert(760_mmHg == 1_atm);
static_assert(6'894.757'29_Pa == 1_psi);

int main()
{
    return 0;
}