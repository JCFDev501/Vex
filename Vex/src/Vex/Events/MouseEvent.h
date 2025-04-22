#pragma once

#include "Vex/Events/Event.h"
#include <sstream>
#include "Vex/Input/MouseCodes.h"

namespace Vex {

    /**
     * @class MouseMovedEvent
     * @brief Represents an event where the mouse is moved.
     * 
     * This event contains the X and Y coordinates of the mouse at the time of movement.
     */
    class MouseMovedEvent : public Vex::Event
    {
    public:
        /**
         * @brief Constructs a MouseMovedEvent with specific X and Y coordinates.
         * @param x The X coordinate of the mouse.
         * @param y The Y coordinate of the mouse.
         */
        MouseMovedEvent(float x, float y)
            : m_MouseX(x), m_MouseY(y) {}

        /**
         * @brief Gets the X coordinate of the mouse.
         * @return The X coordinate of the mouse.
         */
        float GetX() const { return m_MouseX; }

        /**
         * @brief Gets the Y coordinate of the mouse.
         * @return The Y coordinate of the mouse.
         */
        float GetY() const { return m_MouseY; }

        /**
         * @brief Converts the event to a string representation.
         * @return A string describing the mouse move event, including X and Y coordinates.
         */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        // Specifies the event type for MouseMoved events.
        EVENT_CLASS_TYPE(MouseMoved)

        // Specifies the event categories for MouseMoved events.
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_MouseX, m_MouseY; ///< The X and Y coordinates of the mouse.
    };

    /**
     * @class MouseScrolledEvent
     * @brief Represents an event where the mouse is scrolled.
     * 
     * This event contains the X and Y offset of the mouse scroll.
     */
    class MouseScrolledEvent : public Event
    {
    public:
        /**
         * @brief Constructs a MouseScrolledEvent with specific scroll offsets.
         * @param xOffset The X offset of the mouse scroll.
         * @param yOffset The Y offset of the mouse scroll.
         */
        MouseScrolledEvent(float xOffset, float yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset) {}

        /**
         * @brief Gets the X offset of the scroll.
         * @return The X offset of the scroll.
         */
        float GetXOffset() const { return m_XOffset; }

        /**
         * @brief Gets the Y offset of the scroll.
         * @return The Y offset of the scroll.
         */
        float GetYOffset() const { return m_YOffset; }

        /**
         * @brief Converts the event to a string representation.
         * @return A string describing the mouse scroll event, including X and Y offsets.
         */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        // Specifies the event type for MouseScrolled events.
        EVENT_CLASS_TYPE(MouseScrolled)

        // Specifies the event categories for MouseScrolled events.
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_XOffset, m_YOffset; ///< The X and Y offsets of the mouse scroll.
    };

    /**
     * @class MouseButtonEvent
     * @brief Base class for mouse button related events.
     * 
     * This class contains the button code for the mouse button involved in the event.
     */
    class MouseButtonEvent : public Event
    {
    public:
        /**
         * @brief Gets the mouse button involved in the event.
         * @return The button code of the mouse button.
         */
        MouseCode GetMouseButton() const { return m_Button; }

        // Specifies the event categories for mouse button events.
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)

    protected:
        /**
         * @brief Constructor for creating a mouse button event with a specific button.
         * @param button The mouse button involved in the event.
         */
        MouseButtonEvent(MouseCode button)
            : m_Button(button) {}

        MouseCode m_Button; ///< The mouse button code.
    };

    /**
     * @class MouseButtonPressedEvent
     * @brief Represents an event where a mouse button is pressed.
     * 
     * This event contains the button code of the mouse button that was pressed.
     */
    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        /**
         * @brief Constructs a MouseButtonPressedEvent with a specific button.
         * @param button The mouse button that was pressed.
         */
        MouseButtonPressedEvent(MouseCode button)
            : MouseButtonEvent(button) {}

        /**
         * @brief Converts the event to a string representation.
         * @return A string describing the mouse button pressed event, including the button code.
         */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        // Specifies the event type for MouseButtonPressed events.
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    /**
     * @class MouseButtonReleasedEvent
     * @brief Represents an event where a mouse button is released.
     * 
     * This event contains the button code of the mouse button that was released.
     */
    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        /**
         * @brief Constructs a MouseButtonReleasedEvent with a specific button.
         * @param button The mouse button that was released.
         */
        MouseButtonReleasedEvent(MouseCode button)
            : MouseButtonEvent(button) {}

        /**
         * @brief Converts the event to a string representation.
         * @return A string describing the mouse button released event, including the button code.
         */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

        // Specifies the event type for MouseButtonReleased events.
        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

}
