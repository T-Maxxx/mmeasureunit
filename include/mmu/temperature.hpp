#pragma once
#include "measure_units.hpp"

#include "detail/measure_unit.hpp"


namespace mu::temperature
{
    namespace detail
    {
        struct temperature {};

        using unit = mu::detail::measure_unit<temperature>;
    }

    /// Celsius.
    struct degC : detail::unit
    {
        explicit constexpr degC(double count_ = 0) : detail::unit(count_, mu::detail::linear{ 1, 1, 0 }) {}
    };

    /// Kelvin.
    struct degK : detail::unit
    {
        explicit constexpr degK(double count_ = 0) : detail::unit(count_, mu::detail::linear{ 1, 1, -273.15 }) {}
    };

    /// Fahrenheit.


    template<class To, class From>
    constexpr std::enable_if_t<std::is_base_of_v<detail::temperature, To> && std::is_base_of_v<detail::temperature, From>, To> cast(const From& from_)
    {
        To to;
        to.Count = mu::detail::LinearCast(from_.Ratio, to.Ratio, from_.Count);
        return to;
    }


    inline namespace literals
    {
        constexpr degC operator ""_degC(long double Value_) { return degC{ static_cast<double>(Value_) }; }
        constexpr degC operator ""_degC(unsigned long long Value_) { return degC{ 1.0 * Value_ }; }

        constexpr degK operator ""_degK(long double Value_) { return degK{ static_cast<double>(Value_) }; }
        constexpr degK operator ""_degK(unsigned long long Value_) { return degK{ 1.0 * Value_ }; }
    }
}
