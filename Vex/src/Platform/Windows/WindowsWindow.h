#pragma once

#include "Vex/Window.h"
#include <SDL.h>

namespace Vex
{
    /**
     * Platform-specific implementation of the Window interface using SDL.
     */
    class WindowsWindow : public Window
    {
    public:
        /**
         * Constructs a new WindowsWindow with the specified properties.
         * @param props The properties to initialize the window with.
         */
        WindowsWindow(const WindowProps& props);

        /**
         * Destroys the window and performs any necessary cleanup.
         */
        virtual ~WindowsWindow();

        /**
         * Processes events and updates the window (e.g., swaps buffers).
         */
        void OnUpdate() override;

        /**
         * @return The current width of the window.
         */
        unsigned int GetWidth() override { return m_Data.Width; }

        /**
         * @return The current height of the window.
         */
        unsigned int GetHeight() override { return m_Data.Height; }

        /**
         * Sets the callback function that will be used to handle events.
         * @param callback The function to call when events are dispatched.
         */
        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

    private:
        /**
         * Initializes the window with the given properties.
         * @param props The properties to initialize with.
         */
        void Init(const WindowProps& props);

        /**
         * Shuts down the window and releases all resources.
         */
        void Shutdown();

    private:
        SDL_Window* m_Window = nullptr;

        struct WindowData
        {
            std::string Title;
            unsigned int Width = 0, Height = 0;
            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}
