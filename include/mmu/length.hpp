#pragma once
#include "measure_units.hpp"


namespace mu::length
{
    namespace detail
    {
        // Tag for length units.
        struct len {};

        // Shortcut for common unit type.
        template<class Period = std::ratio<1>, class Rep = double>
        using unit = ::mu::detail::unit<len, Rep, Period>;

        inline constexpr auto inchRatioN = 127;
        inline constexpr auto inchRatioD = 5000;
        using inRatio = std::ratio<inchRatioN, inchRatioD>;

        inline constexpr auto footRatioN = 381;
        inline constexpr auto footRatioD = 1250;
        using ftRatio = std::ratio<footRatioN, footRatioD>;
        using ydRatio = std::ratio<3 * footRatioN, footRatioD>;

        inline constexpr auto mileRatioN = 201168;
        inline constexpr auto mileRatioD = 125;
        using miRatio = std::ratio<mileRatioN, mileRatioD>;

        inline constexpr auto nmileRatioN = 1852;
        using nmiRatio = std::ratio<nmileRatioN>;
    }


    /// Nanometer.
    using nm = detail::unit<std::nano>;
    /// Micrometer.
    using mcm = detail::unit<std::micro>;
    /// Millimeter.
    using mm = detail::unit<std::milli>;
    /// Centimeter.
    using cm = detail::unit<std::centi>;
    /// Meter.
    using m = detail::unit<>;
    /// Kilometer.
    using km = detail::unit<std::kilo>;
    /// Inch.
    using in = detail::unit<detail::inRatio>;
    /// Foot.
    using ft = detail::unit<detail::ftRatio>;
    /// Yard.
    using yd = detail::unit<detail::ydRatio>;
    /// Mile.
    using mi = detail::unit<detail::miRatio>;
    /// INM, International Nautical Mile.
    using nmi = detail::unit<detail::nmiRatio>;


    /// \brief Perform cast from one length type to another.
    /// \tparam To Destination value type
    /// \tparam Rep Internal source value storage type
    /// \tparam Period std::ratio that represents source value
    /// \param From_ Convert from this value
    /// \return Converted length to type \a To
    template<class To, class Rep, class Period>
    constexpr To cast(const detail::unit<Period, Rep>& From_) noexcept
    {
        return ::mu::detail::measure_unit_cast<detail::len, To>(From_);
    }


    inline namespace literals
    {
        constexpr nm operator ""_nm(long double Value_) { return nm{ static_cast<double>(Value_) }; }
        constexpr nm operator ""_nm(unsigned long long Value_) { return nm{ 1.0 * Value_ }; }

        constexpr mcm operator ""_mcm(long double Value_) { return mcm{ static_cast<double>(Value_) }; }
        constexpr mcm operator ""_mcm(unsigned long long Value_) { return mcm{ 1.0 * Value_ }; }

        constexpr mm operator ""_mm(long double Value_) { return mm{ static_cast<double>(Value_) }; }
        constexpr mm operator ""_mm(unsigned long long Value_) { return mm{ 1.0 * Value_ }; }

        constexpr cm operator ""_cm(long double Value_) { return cm{ static_cast<double>(Value_) }; }
        constexpr cm operator ""_cm(unsigned long long Value_) { return cm{ 1.0 * Value_ }; }

        constexpr m operator ""_m(long double Value_) { return m{ static_cast<double>(Value_) }; }
        constexpr m operator ""_m(unsigned long long Value_) { return m{ 1.0 * Value_ }; }

        constexpr km operator ""_km(long double Value_) { return km{ static_cast<double>(Value_) }; }
        constexpr km operator ""_km(unsigned long long Value_) { return km{ 1.0 * Value_ }; }

        constexpr in operator ""_in(long double Value_) { return in{ static_cast<double>(Value_) }; }
        constexpr in operator ""_in(unsigned long long Value_) { return in{ 1.0 * Value_ }; }

        constexpr ft operator ""_ft(long double Value_) { return ft{ static_cast<double>(Value_) }; }
        constexpr ft operator ""_ft(unsigned long long Value_) { return ft{ 1.0 * Value_ }; }

        constexpr yd operator ""_yd(long double Value_) { return yd{ static_cast<double>(Value_) }; }
        constexpr yd operator ""_yd(unsigned long long Value_) { return yd{ 1.0 * Value_ }; }

        constexpr mi operator ""_mi(long double Value_) { return mi{ static_cast<double>(Value_) }; }
        constexpr mi operator ""_mi(unsigned long long Value_) { return mi{ 1.0 * Value_ }; }

        constexpr nmi operator ""_nmi(long double Value_) { return nmi{ static_cast<double>(Value_) }; }
        constexpr nmi operator ""_nmi(unsigned long long Value_) { return nmi{ 1.0 * Value_ }; }
    }
}



