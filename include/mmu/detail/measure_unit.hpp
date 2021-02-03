#pragma once
#include "linear.hpp"


namespace mu::detail
{
    struct measure_unit_base
    {
        constexpr measure_unit_base(double count_, const linear& ratio_)
            : Count(count_)
            , Ratio(ratio_)
        {}

        double Count = {};
        const linear Ratio;
    };


    template<class Tag>
    struct measure_unit : measure_unit_base, Tag
    {
        constexpr measure_unit(double count_, const linear& ratio_) : measure_unit_base(count_, ratio_) {}

        constexpr measure_unit& operator-()
        {
            Count = -Count;
            return *this;
        }

        constexpr measure_unit& operator=(double value_)
        {
            Count = value_;
            return *this;
        }

        /// Comparison between two measure units of same tag.
        constexpr bool operator==(const measure_unit& other_) const
        {
            return AlmostEqual(Count, LinearCast(other_.Ratio, Ratio, other_.Count));
        }
    };
}
