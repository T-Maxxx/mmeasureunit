#pragma once

#include "measure_units.hpp"


namespace mu::speed
{
    namespace detail
    {
        struct speed {};

        template<class Period = std::ratio<1, 1>>
        using unit = ::mu::detail::unit<speed, double, Period>;

        inline constexpr auto kmphN = 5;
        inline constexpr auto kmphD = 18;
        using kmphRatio = std::ratio<kmphN, kmphD>;

        inline constexpr auto mphN = 1397;
        inline constexpr auto mphD = 3125;
        using miphRatio = std::ratio<mphN, mphD>;

        inline constexpr auto knN = 463;
        inline constexpr auto knD = 900;
        using knRatio = std::ratio<knN, knD>;
    }

    /// Meters per second.
    using mps = detail::unit<>;
    /// Kilometers per hour.
    using kmph = detail::unit<detail::kmphRatio>;
    /// Miles per hour.
    using miph = detail::unit<detail::miphRatio>;
    /// Knot.
    using kn = detail::unit<detail::knRatio>;


    /// Perform cast from one speed type to another.
    /// \tparam To Destination value type
    /// \tparam Period std::ratio that represents source value
    /// \param From_ Convert from this value
    /// \return Converted speed to type \a To
    template<class To, class Period>
    constexpr To cast(const detail::unit<Period>& From_) noexcept
    {
        return ::mu::detail::measure_unit_cast<detail::speed, To>(From_);
    }

    inline namespace literals
    {
        constexpr mps operator ""_mps(long double Value_) { return mps{ static_cast<double>(Value_) }; }
        constexpr mps operator ""_mps(unsigned long long Value_) { return mps{ 1.0 * Value_ }; }

        constexpr kmph operator ""_kmph(long double Value_) { return kmph{ static_cast<double>(Value_) }; }
        constexpr kmph operator ""_kmph(unsigned long long Value_) { return kmph{ 1.0 * Value_ }; }

        constexpr miph operator ""_miph(long double Value_) { return miph{ static_cast<double>(Value_) }; }
        constexpr miph operator ""_miph(unsigned long long Value_) { return miph{ 1.0 * Value_ }; }

        constexpr kn operator ""_kn(long double Value_) { return kn{ static_cast<double>(Value_) }; }
        constexpr kn operator ""_kn(unsigned long long Value_) { return kn{ 1.0 * Value_ }; }
    }
}
