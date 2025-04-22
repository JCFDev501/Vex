#pragma once

#include "Event.h"

namespace Vex
{

    /**
     * @class WindowResizeEvent
     * @brief Represents an event that occurs when the window is resized.
     * 
     * This event contains information about the new width and height of the window.
     * It is dispatched when the window size changes.
     */
    class WindowResizeEvent : public Event
    {
    public:
        /**
         * @brief Constructor to initialize the window resize event.
         * @param width The new width of the window.
         * @param height The new height of the window.
         */
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}

        /**
         * @brief Gets the new width of the window.
         * @return The width of the window.
         */
        unsigned int GetWidth() const { return m_Width; }

        /**
         * @brief Gets the new height of the window.
         * @return The height of the window.
         */
        unsigned int GetHeight() const { return m_Height; }

        /**
         * @brief Converts the event to a string representation for logging or debugging.
         * @return A string describing the event (width and height).
         */
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize) ///< Event type for window resize.
        EVENT_CLASS_CATEGORY(EventCategoryApplication) ///< Event category for application-related events.

    private:
        unsigned int m_Width, m_Height; ///< The new width and height of the window.
    };

    /**
     * @class WindowCloseEvent
     * @brief Represents an event that occurs when the window is closed.
     * 
     * This event is dispatched when the window is closed, and it doesn't contain any specific data.
     */
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WindowClose) ///< Event type for window close.
        EVENT_CLASS_CATEGORY(EventCategoryApplication) ///< Event category for application-related events.
    };

    /**
     * @class AppTickEvent
     * @brief Represents an event that is triggered during the application's tick.
     * 
     * This event is dispatched during the application's main loop and occurs at regular intervals.
     */
    class AppTickEvent : public Event
    {
    public:
        AppTickEvent() = default;

        EVENT_CLASS_TYPE(AppTick) ///< Event type for application tick.
        EVENT_CLASS_CATEGORY(EventCategoryApplication) ///< Event category for application-related events.
    };

    /**
     * @class AppUpdateEvent
     * @brief Represents an event that is triggered during the application's update stage.
     * 
     * This event is dispatched during the update phase of the application, typically for updating 
     * game logic or other real-time operations.
     */
    class AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() = default;

        EVENT_CLASS_TYPE(AppUpdate) ///< Event type for application update.
        EVENT_CLASS_CATEGORY(EventCategoryApplication) ///< Event category for application-related events.
    };

    /**
     * @class AppRenderEvent
     * @brief Represents an event that is triggered during the application's rendering stage.
     * 
     * This event is dispatched during the rendering phase of the application, typically for drawing 
     * objects to the screen.
     */
    class AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() = default;

        EVENT_CLASS_TYPE(AppRender) ///< Event type for application render.
        EVENT_CLASS_CATEGORY(EventCategoryApplication) ///< Event category for application-related events.
    };
}


