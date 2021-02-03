#include <iostream>

#include <mmu/temperature.hpp>

using namespace mu::temperature;

constexpr auto K = 273.15_degK;
constexpr auto C = 0_degC;
static_assert(K == cast<degK>(C));
static_assert(0_degC == C);
static_assert(K == C);

int main()
{
    std::cout << "0 K == " << cast<degC>(0_degK).Count << " C" << std::endl;
    std::cout << "0 C == " << cast<degK>(0_degC).Count << " K" << std::endl;
    std::cout << "20 C == " << cast<degK>(20_degC).Count << " K" << std::endl;

    const auto k = 0_degK;
    const auto c = -273.15_degC;
    std::cout << (k == c);

    return 0;
}