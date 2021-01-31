#pragma once
#include "measure_units.hpp"


namespace mu::frequency
{
    namespace detail
    {
        struct freq {};

        template<class TRatio = std::ratio<1>>
        using unit = ::mu::detail::unit<freq, double, TRatio>;
    }

    // Hertz.
    using Hz = detail::unit<>;
    // Kilohertz.
    using kHz = detail::unit<std::kilo>;
    // Megahertz.
    using MHz = detail::unit<std::mega>;
    // Gigahertz.
    using GHz = detail::unit<std::giga>;

    template<class To, class Period>
    constexpr To cast(const detail::unit<Period>& from_)
    {
        return ::mu::detail::measure_unit_cast<detail::freq, To>(from_);
    }

    inline namespace literals
    {
        constexpr Hz operator ""_Hz(long double value_) { return Hz{ static_cast<double>(value_) }; }
        constexpr Hz operator ""_Hz(unsigned long long value_) { return Hz{ 1.0 * value_ }; }

        constexpr kHz operator ""_kHz(long double value_) { return kHz{ static_cast<double>(value_) }; }
        constexpr kHz operator ""_kHz(unsigned long long value_) { return kHz{ 1.0 * value_ }; }

        constexpr MHz operator ""_MHz(long double value_) { return MHz{ static_cast<double>(value_) }; }
        constexpr MHz operator ""_MHz(unsigned long long value_) { return MHz{ 1.0 * value_ }; }

        constexpr GHz operator ""_GHz(long double value_) { return GHz{ static_cast<double>(value_) }; }
        constexpr GHz operator ""_GHz(unsigned long long value_) { return GHz{ 1.0 * value_ }; }
    }
}
