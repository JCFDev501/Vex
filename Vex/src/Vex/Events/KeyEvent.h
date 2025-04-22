#pragma once

#include <sstream>
#include "Vex/Events/Event.h"
#include "Vex/Input/KeyCodes.h"

// TODO: Implement KeyCodes

namespace Vex {

    /**
     * @class KeyEvent
     * @brief Base class for all keyboard-related events.
     * 
     * This class is the base class for events related to key presses, releases, and typing.
     * It contains common functionality such as the key code.
     */
    class KeyEvent : public Event
    {
    public:
        /**
         * @brief Gets the key code associated with the event.
         * @return The key code of the event.
         */
        KeyCode GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput) ///< Event category for keyboard and input events.
    protected:
        /**
         * @brief Constructor for creating a key event with a specific key code.
         * @param keycode The key code associated with the event.
         */
        KeyEvent(const KeyCode keycode)
            : m_KeyCode(keycode) {}

        KeyCode m_KeyCode; ///< The key code associated with the event.
    };

    /**
     * @class KeyPressedEvent
     * @brief Represents an event that occurs when a key is pressed.
     * 
     * This event contains information about whether the key press is a repeat (when holding a key).
     */
    class KeyPressedEvent : public KeyEvent
    {
    public:
        /**
         * @brief Constructor for creating a key pressed event.
         * @param keycode The key code associated with the key press.
         * @param isRepeat Indicates if the key press is a repeat (default is false).
         */
        KeyPressedEvent(const KeyCode keycode, bool isRepeat = false)
            : KeyEvent(keycode), m_IsRepeat(isRepeat) {}

        /**
         * @brief Checks if the key press is a repeat.
         * @return True if the key press is a repeat, otherwise false.
         */
        bool IsRepeat() const { return m_IsRepeat; }

        /**
         * @brief Converts the event to a string representation for logging or debugging.
         * @return A string describing the event, including the key code and repeat status.
         */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_IsRepeat << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed) ///< Event type for key pressed.
    private:
        bool m_IsRepeat; ///< Indicates if the key press is a repeat.
    };

    /**
     * @class KeyReleasedEvent
     * @brief Represents an event that occurs when a key is released.
     * 
     * This event contains information about the key code that was released.
     */
    class KeyReleasedEvent : public KeyEvent
    {
    public:
        /**
         * @brief Constructor for creating a key released event.
         * @param keycode The key code associated with the key release.
         */
        KeyReleasedEvent(const KeyCode keycode)
            : KeyEvent(keycode) {}

        /**
         * @brief Converts the event to a string representation for logging or debugging.
         * @return A string describing the event, including the key code.
         */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased) ///< Event type for key released.
    };

    /**
     * @class KeyTypedEvent
     * @brief Represents an event that occurs when a key is typed.
     * 
     * This event contains information about the key code that was typed.
     */
    class KeyTypedEvent : public KeyEvent
    {
    public:
        /**
         * @brief Constructor for creating a key typed event.
         * @param keycode The key code associated with the key type.
         */
        KeyTypedEvent(const KeyCode keycode)
            : KeyEvent(keycode) {}

        /**
         * @brief Converts the event to a string representation for logging or debugging.
         * @return A string describing the event, including the key code.
         */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyTyped) ///< Event type for key typed.
    };
}
