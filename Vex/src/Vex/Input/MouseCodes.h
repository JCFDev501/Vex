#pragma once
#include <cstdint>

namespace Vex
{
    using MouseCode = uint16_t;

    namespace Mouse
    {
        enum : MouseCode
        {
            // SDL Mouse Button Mappings
            Button0                = 1,    // Left button
            Button1                = 2,    // Middle button
            Button2                = 3,    // Right button
            Button3                = 4,    // X1 button
            Button4                = 5,    // X2 button
            Button5                = 6,    // X3 button
            Button6                = 7,    // X4 button
            Button7                = 8,    // X5 button

            ButtonLast             = Button7,
            ButtonLeft             = Button0,   // Left button
            ButtonRight            = Button2,   // Right button
            ButtonMiddle           = Button1    // Middle button
        };
    }
}
