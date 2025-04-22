#pragma once
#include "Vex/Core.h"

namespace Vex
{
    /**
     * @brief Enum representing different types of events.
     *
     * These event types are used to categorize different events that occur in the application,
     * ranging from window events, input events, and application-specific events.
     */
    enum class EventType
    {
        None = 0,                ///< Represents no event.
        WindowClose,             ///< Triggered when the window is closed.
        WindowResize,            ///< Triggered when the window is resized.
        WindowFocus,             ///< Triggered when the window gains focus.
        WindowLostFocus,         ///< Triggered when the window loses focus.
        WindowMoved,             ///< Triggered when the window is moved.
        AppTick,                 ///< Triggered during the application tick.
        AppUpdate,               ///< Triggered during the application update.
        AppRender,               ///< Triggered during the application rendering.
        KeyPressed,              ///< Triggered when a key is pressed.
        KeyReleased,             ///< Triggered when a key is released.
        KeyTyped,                ///< Triggered when a character is typed.
        MouseButtonPressed,      ///< Triggered when a mouse button is pressed.
        MouseButtonReleased,     ///< Triggered when a mouse button is released.
        MouseMoved,              ///< Triggered when the mouse is moved.
        MouseScrolled            ///< Triggered when the mouse wheel is scrolled.
    };

    /**
     * @brief Enum representing different categories of events.
     *
     * These categories allow filtering of events based on the type of event (e.g., input, application).
     */
    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),   ///< Application-related events.
        EventCategoryInput = BIT(1),   ///< Input-related events.
        EventCategoryKeyboard = BIT(2),   ///< Keyboard-related events.
        EventCategoryMouse = BIT(3),   ///< Mouse-related events.
        EventCategoryMouseButton = BIT(4)    ///< Mouse button-related events.
    };

    /**
     * @brief Macro to generate static type information for an event.
     *
     * Used to simplify the implementation of event classes by automatically defining the static
     * type and event name.
     */
#define EVENT_CLASS_TYPE(type) \
        static EventType GetStaticType() { return EventType::type; } \
        virtual EventType GetEventType() const override { return GetStaticType(); } \
        virtual const char* GetName() const override { return #type; }

     /**
      * @brief Macro to associate an event with specific categories.
      *
      * This macro helps define the categories for each event, allowing filtering by category.
      */
#define EVENT_CLASS_CATEGORY(category) \
        virtual int GetCategoryFlags() const override { return category; }

      /**
       * @class Event
       * @brief Base class for all events.
       *
       * This class represents a generic event that can be handled and dispatched. It contains common
       * functionality such as the event type, category, and name. Specific event types derive from this class.
       */
    class Event
    {
    public:
        virtual ~Event() = default; ///< Virtual destructor for polymorphic use.

        bool Handled = false; ///< Flag to indicate whether the event has been handled.

        /**
         * @brief Gets the event type of this event.
         * @return EventType representing the type of event.
         */
        virtual EventType GetEventType() const = 0;

        /**
         * @brief Gets the name of this event.
         * @return A string representing the event name.
         */
        virtual const char* GetName() const = 0;

        /**
         * @brief Gets the category flags of this event.
         * @return An integer representing the categories this event belongs to.
         */
        virtual int GetCategoryFlags() const = 0;

        /**
         * @brief Converts this event to a string representation.
         * @return A string representing the event's name.
         */
        virtual std::string ToString() const { return GetName(); }

        /**
         * @brief Checks if the event is in a given category.
         * @param category The category to check against.
         * @return True if the event is in the category, false otherwise.
         */
        bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }
    };

    /**
     * @class EventDispatcher
     * @brief Dispatches events to the appropriate handlers.
     *
     * This class helps dispatch events to event handler functions. It checks if an event matches
     * the specified type and calls the provided handler function if it does.
     */
    class EventDispatcher
    {
    public:
        /**
         * @brief Constructor.
         * @param event The event to be dispatched.
         */
        EventDispatcher(Event& event)
            : m_Event(event)
        {
        }

        /**
         * @brief Dispatches an event to the provided function if the event type matches.
         *
         * @tparam T The event type to check.
         * @tparam F The handler function type.
         * @param func The function to handle the event if it matches the type.
         * @return True if the event was dispatched, false otherwise.
         */
        template<typename T, typename F>
        bool Dispatch(const F& func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.Handled |= func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }
    private:
        Event& m_Event; ///< The event being dispatched.
    };

    /**
     * @brief Overloads the stream insertion operator to convert events to strings.
     *
     * This operator allows events to be logged directly to a stream (e.g., std::cout or a logger).
     */
    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}


