#pragma once
#include "measure_units.hpp"

namespace mu::pressure
{
    namespace detail
    {
        struct pressure {};

        template<class TRatio = std::ratio<1>>
        using unit = mu::detail::unit<pressure, double, TRatio>;

        constexpr auto barN = 100'000;
        using barRatio = std::ratio<barN>;

        constexpr auto atN = 980'665;
        constexpr auto atD = 10;
        using atRatio = std::ratio<atN, atD>;

        constexpr auto atmN = 101'325;
        using atmRatio = std::ratio<atmN>;

        constexpr auto mmHgN = atmN;
        constexpr auto mmHgD = 760;
        using mmHgRatio = std::ratio<mmHgN, mmHgD>;

        constexpr auto psiN = 689'475'729;
        constexpr auto psiD = 100'000;
        using psiRatio = std::ratio<psiN, psiD>;
    }


    /// Pascal.
    using Pa = detail::unit<>;
    /// Kilopascal.
    using kPa = detail::unit<std::kilo>;
    /// Megapascal.
    using MPa = detail::unit<std::mega>;
    /// Bar.
    using bar = detail::unit<detail::barRatio>;
    /// Millibar.
    using mbar = detail::unit<std::hecto>;
    /// Technical atmosphere.
    using at = detail::unit<detail::atRatio>;
    /// Standard atmosphere.
    using atm = detail::unit<detail::atmRatio>;
    /// Millimetre of mercury.
    using mmHg = detail::unit<detail::mmHgRatio>;
    // Pound-force per squared inch.
    using psi = detail::unit<detail::psiRatio>;


    template<class To, class Period>
    constexpr To cast(const detail::unit<Period>& from_)
    {
        return ::mu::detail::measure_unit_cast<detail::pressure, To>(from_);
    }


    inline namespace literals
    {
        constexpr Pa operator ""_Pa(long double value_) { return Pa{ static_cast<double>(value_) }; }
        constexpr Pa operator ""_Pa(unsigned long long value_) { return Pa{ 1.0 * value_ }; }

        constexpr kPa operator ""_kPa(long double value_) { return kPa{ static_cast<double>(value_) }; }
        constexpr kPa operator ""_kPa(unsigned long long value_) { return kPa{ 1.0 * value_ }; }

        constexpr MPa operator ""_MPa(long double value_) { return MPa{ static_cast<double>(value_) }; }
        constexpr MPa operator ""_MPa(unsigned long long value_) { return MPa{ 1.0 * value_ }; }

        constexpr bar operator ""_bar(long double value_) { return bar{ static_cast<double>(value_) }; }
        constexpr bar operator ""_bar(unsigned long long value_) { return bar{ 1.0 * value_ }; }

        constexpr mbar operator ""_mbar(long double value_) { return mbar{ static_cast<double>(value_) }; }
        constexpr mbar operator ""_mbar(unsigned long long value_) { return mbar{ 1.0 * value_ }; }

        constexpr at operator ""_at(long double value_) { return at{ static_cast<double>(value_) }; }
        constexpr at operator ""_at(unsigned long long value_) { return at{ 1.0 * value_ }; }

        constexpr atm operator ""_atm(long double value_) { return atm{ static_cast<double>(value_) }; }
        constexpr atm operator ""_atm(unsigned long long value_) { return atm{ 1.0 * value_ }; }

        constexpr mmHg operator ""_mmHg(long double value_) { return mmHg{ static_cast<double>(value_) }; }
        constexpr mmHg operator ""_mmHg(unsigned long long value_) { return mmHg{ 1.0 * value_ }; }

        constexpr psi operator ""_psi(long double value_) { return psi{ static_cast<double>(value_) }; }
        constexpr psi operator ""_psi(unsigned long long value_) { return psi{ 1.0 * value_ }; }
    }
}
