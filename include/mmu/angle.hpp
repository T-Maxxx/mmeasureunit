#pragma once

#include "measure_units.hpp"


namespace mu::angle
{
    namespace detail
    {
        // Tag for all angle units.
        struct angle {};

        template<class Period = std::ratio<1, 1>>
        using unit = ::mu::detail::unit<angle, double, Period>;

        inline constexpr auto moaD = 60;
        using moaRatio = std::ratio<1, moaD>;

        inline constexpr auto soaD = 3600;
        using soaRatio = std::ratio<1, soaD>;

        inline constexpr auto gradN = 9;
        inline constexpr auto gradD = 10;
        using gradRatio = std::ratio<gradN, gradD>;
    }


    using deg = detail::unit<>;
    using moa = detail::unit<detail::moaRatio>;
    using arcmin = moa;
    using soa = detail::unit<detail::soaRatio>;
    using arcsec = soa;
    using grad = detail::unit<detail::gradRatio>;
    // TODO: rad, mrad


    template<class To, class Period>
    constexpr To cast(const detail::unit<Period>& from_)
    {
        return ::mu::detail::measure_unit_cast<detail::angle, To>(from_);
    }


    inline namespace literals
    {
        constexpr deg operator ""_deg(long double value_) { return deg{ static_cast<double>(value_) }; }
        constexpr deg operator ""_deg(unsigned long long value_) { return deg{ 1.0 * value_ }; }

        constexpr moa operator ""_moa(long double value_) { return moa{ static_cast<double>(value_) }; }
        constexpr moa operator ""_moa(unsigned long long value_) { return moa{ 1.0 * value_ }; }

        constexpr soa operator ""_soa(long double value_) { return soa{ static_cast<double>(value_) }; }
        constexpr soa operator ""_soa(unsigned long long value_) { return soa{ 1.0 * value_ }; }

        constexpr grad operator ""_grad(long double value_) { return grad{ static_cast<double>(value_) }; }
        constexpr grad operator ""_grad(unsigned long long value_) { return grad{ 1.0 * value_ }; }
    }
}
