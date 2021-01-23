#pragma once
#include "measure_units.hpp"


namespace mu::area
{
    namespace detail
    {
        struct area {};

        template<class Ratio = std::ratio<1, 1>>
        using unit = ::mu::detail::unit<area, double, Ratio>;

        inline constexpr auto cmRatioD = 10'000;
        using cmRatio = std::ratio<1, cmRatioD>;

        inline constexpr auto haRatioN = 10'000;
        using haRatio = std::ratio<haRatioN>;

        inline constexpr auto inRatioN = 254LL * 254LL;
        inline constexpr auto inRatioD = 100'000'000;
        using inRatio = std::ratio<inRatioN, inRatioD>;

        inline constexpr auto ftRatioN = 144 * inRatioN;
        inline constexpr auto ftRatioD = inRatioD;
        using ftRatio = std::ratio<ftRatioN, ftRatioD>;

        inline constexpr auto ydRatioN = 9 * ftRatioN;
        inline constexpr auto ydRatioD = ftRatioD;
        using ydRatio = std::ratio<ydRatioN, ydRatioD>;

        inline constexpr auto acRatioN = 4'840 * ydRatioN;
        inline constexpr auto acRatioD = ydRatioD;
        using acRatio = std::ratio<acRatioN, acRatioD>;

        inline constexpr auto mi2RatioN = 640 * acRatioN;
        inline constexpr auto mi2RatioD = acRatioD;
        using miRatio = std::ratio<mi2RatioN, mi2RatioD>;
    }


    /// Square millimeter.
    using mm2 = detail::unit<std::micro>;
    /// Square centimeter.
    using cm2 = detail::unit<detail::cmRatio>;
    /// Square decimeter.
    using dm2 = detail::unit<std::centi>;
    /// Square meter.
    using m2 = detail::unit<>;
    /// Square kilometer.
    using km2 = detail::unit<std::mega>;
    /// Are.
    using a = detail::unit<std::hecto>;
    /// Hectare.
    using ha = detail::unit<detail::haRatio>;
    /// Square inch.
    using in2 = detail::unit<detail::inRatio>;
    /// Square feet.
    using ft2 = detail::unit<detail::ftRatio>;
    /// Square yard.
    using yd2 = detail::unit<detail::ydRatio>;
    /// Acre.
    using ac = detail::unit<detail::acRatio>;
    /// Square miles.
    using mi2 = detail::unit<detail::miRatio>;


    template<class To, class Period>
    constexpr To cast(const detail::unit<Period>& from_)
    {
        return ::mu::detail::measure_unit_cast<detail::area, To>(from_);
    }


    inline namespace literals
    {
        constexpr mm2 operator ""_mm2(long double value_) { return mm2{ static_cast<double>(value_) }; }
        constexpr mm2 operator ""_mm2(unsigned long long value_) { return mm2{ 1.0 * value_ }; }

        constexpr cm2 operator ""_cm2(long double value_) { return cm2{ static_cast<double>(value_) }; }
        constexpr cm2 operator ""_cm2(unsigned long long value_) { return cm2{ 1.0 * value_ }; }

        constexpr dm2 operator ""_dm2(long double value_) { return dm2{ static_cast<double>(value_) }; }
        constexpr dm2 operator ""_dm2(unsigned long long value_) { return dm2{ 1.0 * value_ }; }

        constexpr m2 operator ""_m2(long double value_) { return m2{ static_cast<double>(value_) }; }
        constexpr m2 operator ""_m2(unsigned long long value_) { return m2{ 1.0 * value_ }; }

        constexpr km2 operator ""_km2(long double value_) { return km2{ static_cast<double>(value_) }; }
        constexpr km2 operator ""_km2(unsigned long long value_) { return km2{ 1.0 * value_ }; }

        constexpr a operator ""_a(long double value_) { return a{ static_cast<double>(value_) }; }
        constexpr a operator ""_a(unsigned long long value_) { return a{ 1.0 * value_ }; }

        constexpr ha operator ""_ha(long double value_) { return ha{ static_cast<double>(value_) }; }
        constexpr ha operator ""_ha(unsigned long long value_) { return ha{ 1.0 * value_ }; }

        constexpr in2 operator ""_in2(long double value_) { return in2{ static_cast<double>(value_) }; }
        constexpr in2 operator ""_in2(unsigned long long value_) { return in2{ 1.0 * value_ }; }

        constexpr ft2 operator ""_ft2(long double value_) { return ft2{ static_cast<double>(value_) }; }
        constexpr ft2 operator ""_ft2(unsigned long long value_) { return ft2{ 1.0 * value_ }; }

        constexpr yd2 operator ""_yd2(long double value_) { return yd2{ static_cast<double>(value_) }; }
        constexpr yd2 operator ""_yd2(unsigned long long value_) { return yd2{ 1.0 * value_ }; }

        constexpr ac operator ""_ac(long double value_) { return ac{ static_cast<double>(value_) }; }
        constexpr ac operator ""_ac(unsigned long long value_) { return ac{ 1.0 * value_ }; }

        constexpr mi2 operator ""_mi2(long double value_) { return mi2{ static_cast<double>(value_) }; }
        constexpr mi2 operator ""_mi2(unsigned long long value_) { return mi2{ 1.0 * value_ }; }
    }
}
