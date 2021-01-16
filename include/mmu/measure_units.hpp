#pragma once
#include <chrono>


namespace mu::detail
{
    // Measure unit template.
    template<class Tag, class Rep, class Ratio = std::ratio<1>,
        class TBase = std::chrono::duration<Rep, Ratio>>
    struct unit : Tag, TBase
    {
        using base = TBase;
        using rep = Rep;

        explicit constexpr unit(const Rep& Value_) : base(Value_) {}

        // construct from underlying duration type.
        explicit constexpr unit(const base& From_)
        {
            base::operator=(From_);
        }
    };


    /// Measure unit cast common function template. Specialized only if To based on Tag type.
    template<class Tag, class To, class Rep, class Period,
        std::enable_if_t<std::is_base_of_v<Tag, To>, int> = 0
    >
    [[nodiscard]] constexpr To measure_unit_cast(const unit<Tag, Rep, Period>& From_) noexcept
    {
        // Fail to deduce types for this function means cast type mismatch.
        // From is auto casted to its base.
        return To{ std::chrono::duration_cast<To::base>(From_) };
    }
}
