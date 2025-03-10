/// @file
/// @brief Class @ref cubos::engine::InputAxis.
/// @ingroup input-plugin

#pragma once

#include <vector>

#include <cubos/core/io/gamepad.hpp>
#include <cubos/core/io/keyboard.hpp>

namespace cubos::engine
{
    /// @brief Stores the state of a single input axis, such as "move forward" or "move right".
    ///
    /// Can be bound to multiple keys, and will have a value in the range [-1, 1] based on the the
    /// state of its bindings.
    ///
    /// @ingroup input-plugin
    class InputAxis final
    {
    public:
        ~InputAxis() = default;

        /// @brief Constructs without any bindings.
        InputAxis() = default;

        /// @brief Constructs with existing bindings.
        /// @param positive Positive key bindings.
        /// @param negative Negative key bindings.
        /// @param gamepadAxes Gamepad axis bindings.
        InputAxis(std::vector<std::pair<core::io::Key, core::io::Modifiers>> positive,
                  std::vector<std::pair<core::io::Key, core::io::Modifiers>> negative,
                  std::vector<core::io::GamepadAxis> gamepadAxes)
            : mPositive(std::move(positive))
            , mNegative(std::move(negative))
            , mGamepadAxes(std::move(gamepadAxes))
        {
        }

        /// @brief Gets the positive key bindings.
        /// @return Vector of positive keys.
        const std::vector<std::pair<core::io::Key, core::io::Modifiers>>& positive() const;

        /// @brief Gets the negative key bindings.
        /// @return Vector of negative keys.
        const std::vector<std::pair<core::io::Key, core::io::Modifiers>>& negative() const;

        /// @brief Gets the gamepad axis bindings.
        /// @return Vector of gamepad axes.
        const std::vector<core::io::GamepadAxis>& gamepadAxes() const;

        /// @brief Gets the positive key bindings.
        /// @return Vector of positive keys.
        std::vector<std::pair<core::io::Key, core::io::Modifiers>>& positive();

        /// @brief Gets the negative key bindings.
        /// @return Vector of negative keys.
        std::vector<std::pair<core::io::Key, core::io::Modifiers>>& negative();

        /// @brief Gets the gamepad axis bindings.
        /// @return Vector of gamepad axes.
        std::vector<core::io::GamepadAxis>& gamepadAxes();

        /// @brief Gets the value.
        /// @return Value.
        float value() const;

        /// @brief Sets the value.
        /// @param value New value.
        void value(float value);

    private:
        std::vector<std::pair<core::io::Key, core::io::Modifiers>> mPositive;
        std::vector<std::pair<core::io::Key, core::io::Modifiers>> mNegative;
        std::vector<core::io::GamepadAxis> mGamepadAxes;

        float mValue; ///< Not serialized.
    };
} // namespace cubos::engine
