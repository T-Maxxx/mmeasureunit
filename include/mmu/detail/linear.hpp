#pragma once
#include <stdexcept>

#include "comparison.hpp"

namespace mu::detail
{
    /// Represents linear function y = kx + b in a such way that
    /// y = (numerator/denumerator) * x + offset
    class linear
    {
    public:
        constexpr linear(double n_ = 1, double d_ = 1, double o_ = 0)
            : Numerator(n_)
            , Denumerator(d_)
            , Offset(o_)
        {
            if (Denumerator == 0.0)
                throw std::invalid_argument{ "denumerator can not be zero" };
        }


        /// Evaluate linear function.
        /// \param x_ Value of parameter, x.
        /// \return Linear function result, y.
        [[nodiscard]] constexpr double eval(double x_) const
        {
            return (Numerator / Denumerator) * x_ + Offset;
        }

        /// Evaluate inverse linear function.
        /// \param y_ Value of linear function, y.
        /// \return Value of parameter, x.
        [[nodiscard]] constexpr double inverse(double y_) const
        {
            if (Numerator == 0.0)
                throw std::invalid_argument{ "numerator can not be zero" };

            return (y_ - Offset) * (Denumerator / Numerator);
        }


        constexpr bool operator==(const linear& other_) const
        {
            return
                AlmostEqual(Numerator, other_.Numerator) &&
                AlmostEqual(Denumerator, other_.Denumerator) &&
                AlmostEqual(Offset, other_.Offset);
        }

        double Numerator = 0;
        double Denumerator= 0;
        double Offset = 0;
    };


    /// Performs value cast from one linear ratio to another.
    /// \param from_ Ratio description of source value.
    /// \param to_ Ratio description of target value.
    /// \param fromValue_ The value to be casted from.
    /// \return Casted value in terms of target linear ratio.
    constexpr double LinearCast(const linear& from_, const linear& to_, double fromValue_)
    {
        if (from_.Denumerator == 0.0)
            throw std::invalid_argument{ "denumerator of linear-numerator can not be 0" };

        if (to_.Numerator == 0.0)
            throw std::invalid_argument{ "numerator of linear-denumerator can not be 0" };

        return (to_.Denumerator / to_.Numerator) * (from_.Numerator / from_.Denumerator * fromValue_ + from_.Offset - to_.Offset);
    }
}
