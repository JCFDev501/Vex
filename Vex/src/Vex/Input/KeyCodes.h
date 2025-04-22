#pragma once

namespace Vex
{
    using KeyCode = uint16_t;

    namespace Key
    {
        enum : KeyCode
        {
            // SDL Keycodes
            Space               = 32,   // Space bar
            Apostrophe          = 39,   // '
            Comma               = 44,   // ,
            Minus               = 45,   // -
            Period              = 46,   // .
            Slash               = 47,   // /

            D0                  = 48,   // 0
            D1                  = 49,   // 1
            D2                  = 50,   // 2
            D3                  = 51,   // 3
            D4                  = 52,   // 4
            D5                  = 53,   // 5
            D6                  = 54,   // 6
            D7                  = 55,   // 7
            D8                  = 56,   // 8
            D9                  = 57,   // 9

            Semicolon           = 59,   // ;
            Equal               = 61,   // =

            A                   = 97,   // A
            B                   = 98,   // B
            C                   = 99,   // C
            D                   = 100,  // D
            E                   = 101,  // E
            F                   = 102,  // F
            G                   = 103,  // G
            H                   = 104,  // H
            I                   = 105,  // I
            J                   = 106,  // J
            K                   = 107,  // K
            L                   = 108,  // L
            M                   = 109,  // M
            N                   = 110,  // N
            O                   = 111,  // O
            P                   = 112,  // P
            Q                   = 113,  // Q
            R                   = 114,  // R
            S                   = 115,  // S
            T                   = 116,  // T
            U                   = 117,  // U
            V                   = 118,  // V
            W                   = 119,  // W
            X                   = 120,  // X
            Y                   = 121,  // Y
            Z                   = 122,  // Z

            LeftBracket         = 91,   // [
            Backslash           = 92,   // \
            RightBracket        = 93,   // ]
            GraveAccent         = 96,   // `

            World1              = 161,  // non-US #1
            World2              = 162,  // non-US #2

            // Function keys
            Escape              = 27,   // Escape
            Enter               = 13,   // Enter
            Tab                 = 9,    // Tab
            Backspace           = 8,    // Backspace
            Insert              = 277,  // Insert
            Delete              = 127,  // Delete
            Right               = 275,  // Right Arrow
            Left                = 276,  // Left Arrow
            Down                = 274,  // Down Arrow
            Up                  = 273,  // Up Arrow
            PageUp              = 280,  // Page Up
            PageDown            = 281,  // Page Down
            Home                = 278,  // Home
            End                 = 279,  // End
            CapsLock            = 304,  // Caps Lock
            ScrollLock          = 305,  // Scroll Lock
            NumLock             = 300,  // Num Lock
            PrintScreen         = 316,  // Print Screen
            Pause               = 19,   // Pause
            F1                  = 282,  // F1
            F2                  = 283,  // F2
            F3                  = 284,  // F3
            F4                  = 285,  // F4
            F5                  = 286,  // F5
            F6                  = 287,  // F6
            F7                  = 288,  // F7
            F8                  = 289,  // F8
            F9                  = 290,  // F9
            F10                 = 291,  // F10
            F11                 = 292,  // F11
            F12                 = 293,  // F12

            // Keypad keys
            KP0                 = 320,  // Numpad 0
            KP1                 = 321,  // Numpad 1
            KP2                 = 322,  // Numpad 2
            KP3                 = 323,  // Numpad 3
            KP4                 = 324,  // Numpad 4
            KP5                 = 325,  // Numpad 5
            KP6                 = 326,  // Numpad 6
            KP7                 = 327,  // Numpad 7
            KP8                 = 328,  // Numpad 8
            KP9                 = 329,  // Numpad 9
            KPDecimal           = 330,  // Numpad .
            KPDivide            = 331,  // Numpad /
            KPMultiply          = 332,  // Numpad *
            KPSubtract          = 333,  // Numpad -
            KPAdd               = 334,  // Numpad +
            KPEnter             = 335,  // Numpad Enter
            KPEqual             = 336,  // Numpad =

            LeftShift           = 303,  // Left Shift
            LeftControl         = 305,  // Left Control
            LeftAlt             = 306,  // Left Alt
            LeftSuper           = 1073742048, // Left Super (Win/Command)
            RightShift          = 304,  // Right Shift
            RightControl        = 306,  // Right Control
            RightAlt            = 307,  // Right Alt
            RightSuper          = 1073742050, // Right Super (Win/Command)
            Menu                = 1073742081 // Menu key (sometimes used as "App" key)
        };
    }
}
