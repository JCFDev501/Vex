#include "Application.h"

#include "Log.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace Vex
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
{
    // Window resize event
    WindowResizeEvent e(1280, 720);

    if (e.IsInCategory(EventCategoryApplication))
    {
        VEX_TRACE(e.ToString());
    }

    if (e.IsInCategory(EventCategoryInput))
    {
        VEX_TRACE(e.ToString());
    }

    // Test MouseMovedEvent
    MouseMovedEvent mouseMoveEvent(500.0f, 300.0f); // Simulating mouse movement
    if (mouseMoveEvent.IsInCategory(EventCategoryMouse))
    {
        VEX_TRACE(mouseMoveEvent.ToString());
    }

    // Test MouseScrolledEvent
    MouseScrolledEvent mouseScrollEvent(0.0f, -1.0f); // Simulating mouse scroll
    if (mouseScrollEvent.IsInCategory(EventCategoryMouse))
    {
        VEX_TRACE(mouseScrollEvent.ToString());
    }

    // Test MouseButtonPressedEvent
    MouseButtonPressedEvent mouseButtonPressedEvent(1); // Simulating mouse button 1 press
    if (mouseButtonPressedEvent.IsInCategory(EventCategoryMouseButton))
    {
        VEX_TRACE(mouseButtonPressedEvent.ToString());
    }

    // Test MouseButtonReleasedEvent
    MouseButtonReleasedEvent mouseButtonReleasedEvent(2); // Simulating mouse button 1 release
    if (mouseButtonReleasedEvent.IsInCategory(EventCategoryMouseButton))
    {
        VEX_TRACE(mouseButtonReleasedEvent.ToString());
    }

    // Test KeyPressedEvent
    KeyPressedEvent keyPressedEvent(97, false); // Simulating "A" key press
    if (keyPressedEvent.IsInCategory(EventCategoryKeyboard))
    {
        VEX_TRACE(keyPressedEvent.ToString());
    }

    // Test KeyReleasedEvent
    KeyReleasedEvent keyReleasedEvent(97); // Simulating "A" key release
    if (keyReleasedEvent.IsInCategory(EventCategoryKeyboard))
    {
        VEX_TRACE(keyReleasedEvent.ToString());
    }

    // Test KeyTypedEvent
    KeyTypedEvent keyTypedEvent(97); // Simulating typing the "A" key
    if (keyTypedEvent.IsInCategory(EventCategoryKeyboard))
    {
        VEX_TRACE(keyTypedEvent.ToString());
    }

    // Main loop (just for illustration)
    while (true)
    {
        
    }
}

}


