#pragma once
#include <limits>
#include <cmath>

namespace mu::detail
{
    constexpr double Abs(double a_)
    {
        return a_ >= 0 ? a_ : -a_;
    }

    constexpr bool AlmostEqual(double a_, double b_)
    {
        // the machine epsilon has to be scaled to the magnitude of the values used
        // and multiplied by the desired precision in ULPs (units in the last place)
        return Abs(a_ - b_) <= std::numeric_limits<double>::epsilon() * Abs(a_ + b_)
            // unless the result is subnormal
            || Abs(a_ - b_) < std::numeric_limits<double>::min();
    }
}
