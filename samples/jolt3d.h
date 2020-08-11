#ifndef JOLT3D_H
#define JOLT3D_H

// silence VC++ about deprecated stuff; this is only for VC++ compilers and before headers.
#ifdef _MSC_VER
   #define _CRT_SECURE_NO_WARNINGS
   #define _HAS_ITERATOR_DEBUGGING    0   // disable the iterator debugging (unclear if it's disabled in release builds)
   #pragma warning(disable: 4503)         // supress some more warnings
#endif

// silence most GNU warnings on GNU/Linux based compilers
#ifdef __GNUC__
   #pragma GCC system_header
#endif

#ifndef __FUNCTION_NAME__
#ifdef _WIN32
   #define __FUNCTION_NAME__   __FUNCTION__
#else
   #define __FUNCTION_NAME__   __func__
#endif
#endif

// Solaris requires this (fixes GLM)
#if defined(__sun)
   #define _GLIBCXX_USE_C99_MATH 1
#endif

// std
#include <cstdlib>         // namespace 'std'
#include <cstdint>         // data types such as 'uint32_t' etc.
#include <cstring>         // std::string, memset
#include <string>          // prevents compilation errors (cstring and string aren't the same)
#include <vector>          // std::vector<foo>
#include <map>             // std::map<foo>
#include <algorithm>       // std::find, std::remove
#include <functional>      // std::function

// key events //////////////////////////////////////////////////////////////////////

/*jdoc
{"type":"define",
"group":"Key events"
}*/
#define J3D_KEYEVENT_NONE        -1
#define J3D_KEYEVENT_PRESSED      0
#define J3D_KEYEVENT_RELEASED     1

// mouse events ////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"type":"define",
"group":"Mouse events"
}*/
#define J3D_MOUSEEVENT_NONE                 -1
#define J3D_MOUSEEVENT_BUTTON_PRESSED        2
#define J3D_MOUSEEVENT_BUTTON_RELEASED       3
#define J3D_MOUSEEVENT_MOUSE_MOVED           4
#define J3D_MOUSEEVENT_WHEEL_ROTATED         5

// platform-based events
#ifdef _WIN32
   // mouse button mapping //////////////////////////////////////////////////////////////////////
/*jdoc
{"type":"define",
"group":"Mouse button mapping"
}*/
   #define J3D_MOUSEBUTTON_LEFT      0x0001  // MK_LBUTTON
   #define J3D_MOUSEBUTTON_RIGHT     0x0002  // MK_RBUTTON
   #define J3D_MOUSEBUTTON_MIDDLE    0x0010  // MK_MBUTTON
   
   // mouse button mapping //////////////////////////////////////////////////////////////////////
/*jdoc
{"type":"define",
"group":"Mouse wheel mapping"
}*/
   #define J3D_MOUSEWHEEL_UP         0
   #define J3D_MOUSEWHEEL_DOWN       1

   // key mapping
   // source:  http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731%28v=vs.85%29.aspx

   // key mapping //////////////////////////////////////////////////////////////////////
/*jdoc
{"type":"define",
"group":"Key mapping"
}*/
   #define J3D_KEY_NONE              -1
   #define J3D_KEY_0                 48
   #define J3D_KEY_1                 0x31
   #define J3D_KEY_2                 0x32
   #define J3D_KEY_3                 0x33
   #define J3D_KEY_4                 0x34
   #define J3D_KEY_5                 0x35
   #define J3D_KEY_6                 0x36
   #define J3D_KEY_7                 0x37
   #define J3D_KEY_8                 0x38
   #define J3D_KEY_9                 0x39
   #define J3D_KEY_A                 0x41
   #define J3D_KEY_ALTL              0xA4  // VK_LMENU
   #define J3D_KEY_ALTR              0xA5  // VK_RMENU
   #define J3D_KEY_B                 0x42
   #define J3D_KEY_BACKSPACE         0x08  // VK_BACK
   #define J3D_KEY_C                 0x43
   #define J3D_KEY_CAPSLOCK          0x14  // VK_CAPITAL
   #define J3D_KEY_CONTROLL          0xA2  // VK_LCONTROL
   #define J3D_KEY_CONTROLR          0xA3  // VK_RCONTROL
   #define J3D_KEY_D                 0x44
   #define J3D_KEY_DELETE            0x2E  // VK_DELETE
   #define J3D_KEY_DOWN              0x28  // VK_DOWN
   #define J3D_KEY_E                 0x45
   #define J3D_KEY_ENTER             0x0D  // VK_RETURN
   #define J3D_KEY_END               0x23  // VK_END
   #define J3D_KEY_ESCAPE            0x1B  // VK_ESCAPE
   #define J3D_KEY_F                 0x46
   #define J3D_KEY_F1                0x70  // VK_F1
   #define J3D_KEY_F2                0x71  // VK_F2
   #define J3D_KEY_F3                0x72  // VK_F3
   #define J3D_KEY_F4                0x73  // VK_F4
   #define J3D_KEY_F5                0x74  // VK_F5
   #define J3D_KEY_F6                0x75  // VK_F6
   #define J3D_KEY_F7                0x76  // VK_F7
   #define J3D_KEY_F8                0x77  // VK_F8
   #define J3D_KEY_F9                0x78  // VK_F9
   #define J3D_KEY_F10               0x79  // VK_F10
   #define J3D_KEY_F11               0x7A  // VK_F11
   #define J3D_KEY_F12               0x7B  // VK_F12
   #define J3D_KEY_F13               0x7C  // VK_F13
   #define J3D_KEY_F14               0x7D  // VK_F14
   #define J3D_KEY_F15               0x7E  // VK_F15
   #define J3D_KEY_G                 0x47
   #define J3D_KEY_H                 0x48
   #define J3D_KEY_HOME              0x24  // VK_HOME
   #define J3D_KEY_I                 0x49
   #define J3D_KEY_INSERT            0x2D  // VK_INSERT
   #define J3D_KEY_J                 0x4A
   #define J3D_KEY_K                 0x4B
   #define J3D_KEY_L                 0x4C
   #define J3D_KEY_LEFT              0x25  // VK_LEFT
   #define J3D_KEY_M                 0x4D
   #define J3D_KEY_N                 0x4E
   #define J3D_KEY_NUMLOCK           0x90  // VK_NUMLOCK
   #define J3D_KEY_NUMPAD_0          0x60  // VK_NUMPAD0
   #define J3D_KEY_NUMPAD_1          0x61  // VK_NUMPAD1
   #define J3D_KEY_NUMPAD_2          0x62  // VK_NUMPAD2
   #define J3D_KEY_NUMPAD_3          0x63  // VK_NUMPAD3
   #define J3D_KEY_NUMPAD_4          0x64  // VK_NUMPAD4
   #define J3D_KEY_NUMPAD_5          0x65  // VK_NUMPAD5
   #define J3D_KEY_NUMPAD_6          0x66  // VK_NUMPAD6
   #define J3D_KEY_NUMPAD_7          0x67  // VK_NUMPAD7
   #define J3D_KEY_NUMPAD_8          0x68  // VK_NUMPAD8
   #define J3D_KEY_NUMPAD_9          0x69  // VK_NUMPAD9
   #define J3D_KEY_NUMPAD_ADD        0x6B  // VK_ADD
   #define J3D_KEY_NUMPAD_DECIMAL    0x6E  // VK_DECIMAL
   #define J3D_KEY_NUMPAD_DIVIDE     0x6F  // VK_DIVIDE
   #define J3D_KEY_NUMPAD_MULTIPLY   0x6A  // VK_MULTIPLY
   #define J3D_KEY_NUMPAD_SUBTRACT   0x6D  // VK_SUBTRACT
   #define J3D_KEY_O                 0x4F
   #define J3D_KEY_P                 0x50
   #define J3D_KEY_PAGEDOWN          0x22  // VK_NEXT
   #define J3D_KEY_PAGEUP            0x21  // VK_PRIOR
   #define J3D_KEY_PAUSE             0x13  // VK_PAUSE
   #define J3D_KEY_PRINT             0x2A  // VK_PRINT
   #define J3D_KEY_Q                 0x51
   #define J3D_KEY_R                 0x52
   #define J3D_KEY_RIGHT             0x27  // VK_RIGHT
   #define J3D_KEY_S                 0x53
   #define J3D_KEY_SPACE             0x20  // VK_SPACE
   #define J3D_KEY_SHIFTL            0xA0  // VK_LSHIFT
   #define J3D_KEY_SHIFTR            0xA1  // VK_RSHIFT
   #define J3D_KEY_T                 0x54
   #define J3D_KEY_TAB               0x09  // VK_TAB
   #define J3D_KEY_U                 0x55
   #define J3D_KEY_UP                0x26  // VK_UP
   #define J3D_KEY_V                 0x56
   #define J3D_KEY_W                 0x57
   #define J3D_KEY_X                 0x58
   #define J3D_KEY_Y                 0x59
   #define J3D_KEY_Z                 0x5A
/*jdoc
{"type":"define",
"group":"Key modifiers"
}*/
   #define J3D_KEY_MOD_NONE          -1
   #define J3D_KEY_MOD_SHIFT         0x0004  // MOD_SHIFT
   #define J3D_KEY_MOD_CONTROL       0x0002  // MOD_CONTROL
#elif __ANDROID__
   // mouse mapping
   #define J3D_MOUSEBUTTON_LEFT      0
   #define J3D_MOUSEBUTTON_RIGHT     0
   #define J3D_MOUSEBUTTON_MIDDLE    0
   #define J3D_MOUSEWHEEL_UP         1
   #define J3D_MOUSEWHEEL_DOWN       1
   // key mapping
   // source:  http://mobilepearls.com/labs/native-android-api/
   // FIXME:  numerous keys seems to be missing; probably one needs a keyboard app
   #define J3D_KEY_NONE              -1
   #define J3D_KEY_0                 AKEYCODE_0
   #define J3D_KEY_1                 AKEYCODE_1
   #define J3D_KEY_2                 AKEYCODE_2
   #define J3D_KEY_3                 AKEYCODE_3
   #define J3D_KEY_4                 AKEYCODE_4
   #define J3D_KEY_5                 AKEYCODE_5
   #define J3D_KEY_6                 AKEYCODE_6
   #define J3D_KEY_7                 AKEYCODE_7
   #define J3D_KEY_8                 AKEYCODE_8
   #define J3D_KEY_9                 AKEYCODE_9
   #define J3D_KEY_A                 AKEYCODE_A
   #define J3D_KEY_ALTL              AKEYCODE_ALT_LEFT
   #define J3D_KEY_ALTR              AKEYCODE_ALT_RIGHT
   #define J3D_KEY_B                 AKEYCODE_B
   #define J3D_KEY_BACKSPACE         AKEYCODE_BACK
   #define J3D_KEY_C                 AKEYCODE_C
   #define J3D_KEY_CAPSLOCK          -1
   #define J3D_KEY_CONTROLL          -1
   #define J3D_KEY_CONTROLR          -1
   #define J3D_KEY_D                 AKEYCODE_D
   #define J3D_KEY_DELETE            AKEYCODE_DEL
   #define J3D_KEY_DOWN              AKEYCODE_DPAD_DOWN
   #define J3D_KEY_E                 AKEYCODE_E
   #define J3D_KEY_ENTER             AKEYCODE_ENTER
   // FIXME:  end key doesn't seem exist in Android
   #define J3D_KEY_END               -1
   #define J3D_KEY_ESCAPE            -1
   #define J3D_KEY_F                 AKEYCODE_F
   #define J3D_KEY_F1                -1
   #define J3D_KEY_F2                -1
   #define J3D_KEY_F3                -1
   #define J3D_KEY_F4                -1
   #define J3D_KEY_F5                -1
   #define J3D_KEY_F6                -1
   #define J3D_KEY_F7                -1
   #define J3D_KEY_F8                -1
   #define J3D_KEY_F9                -1
   #define J3D_KEY_F10               -1
   #define J3D_KEY_F11               -1
   #define J3D_KEY_F12               -1
   #define J3D_KEY_F13               -1
   #define J3D_KEY_F14               -1
   #define J3D_KEY_F15               -1
   #define J3D_KEY_G                 AKEYCODE_G
   #define J3D_KEY_H                 AKEYCODE_H
   #define J3D_KEY_HOME              AKEYCODE_HOME
   #define J3D_KEY_I                 AKEYCODE_I
   #define J3D_KEY_INSERT            -1
   #define J3D_KEY_J                 AKEYCODE_J
   #define J3D_KEY_K                 AKEYCODE_K
   #define J3D_KEY_L                 AKEYCODE_L
   #define J3D_KEY_LEFT              AKEYCODE_DPAD_LEFT
   #define J3D_KEY_M                 AKEYCODE_M
   #define J3D_KEY_N                 AKEYCODE_N
   #define J3D_KEY_NUMLOCK           AKEYCODE_NUM
   #define J3D_KEY_NUMPAD_0          AKEYCODE_0
   #define J3D_KEY_NUMPAD_1          AKEYCODE_1
   #define J3D_KEY_NUMPAD_2          AKEYCODE_2
   #define J3D_KEY_NUMPAD_3          AKEYCODE_3
   #define J3D_KEY_NUMPAD_4          AKEYCODE_4
   #define J3D_KEY_NUMPAD_5          AKEYCODE_5
   #define J3D_KEY_NUMPAD_6          AKEYCODE_6
   #define J3D_KEY_NUMPAD_7          AKEYCODE_7
   #define J3D_KEY_NUMPAD_8          AKEYCODE_8
   #define J3D_KEY_NUMPAD_9          AKEYCODE_9
   #define J3D_KEY_NUMPAD_ADD        AKEYCODE_PLUS
   #define J3D_KEY_NUMPAD_DECIMAL    AKEYCODE_PERIOD
   #define J3D_KEY_NUMPAD_DIVIDE     AKEYCODE_SLASH
   #define J3D_KEY_NUMPAD_MULTIPLY   -1
   #define J3D_KEY_NUMPAD_SUBTRACT   AKEYCODE_MINUS
   #define J3D_KEY_O                 AKEYCODE_O
   #define J3D_KEY_P                 AKEYCODE_P
   #define J3D_KEY_PAGEDOWN          AKEYCODE_PAGE_DOWN
   #define J3D_KEY_PAGEUP            AKEYCODE_PAGE_UP
   #define J3D_KEY_PAUSE             -1
   #define J3D_KEY_PRINT             -1
   #define J3D_KEY_Q                 AKEYCODE_Q
   #define J3D_KEY_R                 AKEYCODE_R
   #define J3D_KEY_RIGHT             AKEYCODE_DPAD_RIGHT
   #define J3D_KEY_S                 AKEYCODE_S
   #define J3D_KEY_SPACE             AKEYCODE_SPACE
   #define J3D_KEY_SHIFTL            AKEYCODE_SHIFT_LEFT
   #define J3D_KEY_SHIFTR            AKEYCODE_SHIFT_RIGHT
   #define J3D_KEY_T                 AKEYCODE_T
   #define J3D_KEY_TAB               AKEYCODE_TAB
   #define J3D_KEY_U                 AKEYCODE_U
   #define J3D_KEY_UP                AKEYCODE_DPAD_UP
   #define J3D_KEY_V                 AKEYCODE_V
   #define J3D_KEY_W                 AKEYCODE_W
   #define J3D_KEY_X                 AKEYCODE_X
   #define J3D_KEY_Y                 AKEYCODE_Y
   #define J3D_KEY_Z                 AKEYCODE_Z
   // modifiers (used in 'J3D_input_set_global_key')
   #define J3D_KEY_MOD_NONE             -1
   #define J3D_KEY_MOD_SHIFT            -1
   #define J3D_KEY_MOD_CONTROL          -1
#elif defined(__linux__) || defined(__sun)
   // mouse mapping
   #define J3D_MOUSEBUTTON_LEFT      1   // Button1
   #define J3D_MOUSEBUTTON_RIGHT     3   // Button3
   #define J3D_MOUSEBUTTON_MIDDLE    2   // Button2
   #define J3D_MOUSEWHEEL_UP         4
   #define J3D_MOUSEWHEEL_DOWN       5
   // key mapping
   // source:  http://xmonad.org/xmonad-docs/X11/src/Graphics-X11-Types.html
   #define J3D_KEY_NONE              -1
   #define J3D_KEY_0                 48  // XK_0
   #define J3D_KEY_1                 49  // XK_1
   #define J3D_KEY_2                 50  // XK_2
   #define J3D_KEY_3                 51  // XK_3
   #define J3D_KEY_4                 52  // XK_4
   #define J3D_KEY_5                 53  // XK_5
   #define J3D_KEY_6                 54  // XK_6
   #define J3D_KEY_7                 55  // XK_7
   #define J3D_KEY_8                 56  // XK_8
   #define J3D_KEY_9                 57  // XK_9
   #define J3D_KEY_A                 97  // XK_a
   #define J3D_KEY_ALTL              65513  // XK_Alt_L
   #define J3D_KEY_ALTR              65514  // XK_Alt_R
   #define J3D_KEY_B                 98  // XK_b
   #define J3D_KEY_BACKSPACE         65288  // XK_BackSpace
   #define J3D_KEY_C                 99  // XK_c
   #define J3D_KEY_CAPSLOCK          65509  // XK_Caps_Lock
   #define J3D_KEY_CONTROLL          65507  // XK_Control_L
   #define J3D_KEY_CONTROLR          65508  // XK_Control_R
   #define J3D_KEY_D                 100  // XK_d
   #define J3D_KEY_DELETE            65535  // XK_Delete
   #define J3D_KEY_DOWN              65364  // XK_Down
   #define J3D_KEY_E                 101  // XK_e
   #define J3D_KEY_ENTER             65293  // XK_Return
   #define J3D_KEY_END               65367  // XK_End
   #define J3D_KEY_ESCAPE            65307  // XK_Escape
   #define J3D_KEY_F                 102  // XK_f
   #define J3D_KEY_F1                65470  // XK_F1
   #define J3D_KEY_F2                65471  // XK_F2
   #define J3D_KEY_F3                65472  // XK_F3
   #define J3D_KEY_F4                65473  // XK_F4
   #define J3D_KEY_F5                65474  // XK_F5
   #define J3D_KEY_F6                65475  // XK_F6
   #define J3D_KEY_F7                65476  // XK_F7
   #define J3D_KEY_F8                65477  // XK_F8
   #define J3D_KEY_F9                65478  // XK_F9
   #define J3D_KEY_F10               65479  // XK_F10
   #define J3D_KEY_F11               65480  // XK_F11
   #define J3D_KEY_F12               65481  // XK_F12
   #define J3D_KEY_F13               65482  // XK_F13
   #define J3D_KEY_F14               65483  // XK_F14
   #define J3D_KEY_F15               65484  // XK_F15
   #define J3D_KEY_G                 103  // XK_g
   #define J3D_KEY_H                 104  // XK_h
   #define J3D_KEY_HOME              65360  // XK_Home
   #define J3D_KEY_I                 105  // XK_i
   #define J3D_KEY_INSERT            65379  // XK_Insert
   #define J3D_KEY_J                 106  // XK_j
   #define J3D_KEY_K                 107  // XK_k
   #define J3D_KEY_L                 108  // XK_l
   #define J3D_KEY_LEFT              65361  // XK_Left
   #define J3D_KEY_M                 109  // XK_m
   #define J3D_KEY_N                 110  // XK_n
   #define J3D_KEY_NUMLOCK           65407  // XK_Num_Lock
   // * '_NUMPAD_x' requires the NUM-LOCK to be enabled
   #define J3D_KEY_NUMPAD_0          65456  // XK_KP_0
   #define J3D_KEY_NUMPAD_1          65457  // XK_KP_1
   #define J3D_KEY_NUMPAD_2          65458  // XK_KP_2
   #define J3D_KEY_NUMPAD_3          65459  // XK_KP_3
   #define J3D_KEY_NUMPAD_4          65460  // XK_KP_4
   #define J3D_KEY_NUMPAD_5          65461  // XK_KP_5
   #define J3D_KEY_NUMPAD_6          65462  // XK_KP_6
   #define J3D_KEY_NUMPAD_7          65463  // XK_KP_7
   #define J3D_KEY_NUMPAD_8          65464  // XK_KP_8
   #define J3D_KEY_NUMPAD_9          65465  // XK_KP_9
   #define J3D_KEY_NUMPAD_ADD        65451  // XK_KP_Add
   #define J3D_KEY_NUMPAD_DECIMAL    65454  // XK_KP_Decimal
   #define J3D_KEY_NUMPAD_DIVIDE     65455  // XK_KP_Divide
   #define J3D_KEY_NUMPAD_MULTIPLY   65450  // XK_KP_Multiply
   #define J3D_KEY_NUMPAD_SUBTRACT   65453  // XK_KP_Subtract
   #define J3D_KEY_O                 111  // XK_o
   #define J3D_KEY_P                 112  // XK_p
   #define J3D_KEY_PAGEDOWN          65366  // XK_Page_Down
   #define J3D_KEY_PAGEUP            65365  // XK_Page_Up
   #define J3D_KEY_PAUSE             65299  // XK_Pause
   #define J3D_KEY_PRINT             65377  // XK_Print
   #define J3D_KEY_Q                 113  // XK_q
   #define J3D_KEY_R                 114  // XK_r
   #define J3D_KEY_RIGHT             65363  // XK_Right
   #define J3D_KEY_S                 115  // XK_s
   #define J3D_KEY_SPACE             32  // XK_space
   #define J3D_KEY_SHIFTL            65505  // XK_Shift_L
   #define J3D_KEY_SHIFTR            65506  // XK_Shift_R
   #define J3D_KEY_T                 116  // XK_t
   #define J3D_KEY_TAB               65289  // XK_Tab
   #define J3D_KEY_U                 117  // XK_u
   #define J3D_KEY_UP                65362  // XK_Up
   #define J3D_KEY_V                 118  // XK_v
   #define J3D_KEY_W                 119  // XK_w
   #define J3D_KEY_X                 120  // XK_x
   #define J3D_KEY_Y                 121  // XK_y
   #define J3D_KEY_Z                 122  // XK_z
   // modifiers (used in 'J3D_input_set_global_key')
   #define J3D_KEY_MOD_NONE             -1
   #define J3D_KEY_MOD_SHIFT            1  // ShiftMask
   #define J3D_KEY_MOD_CONTROL          4  // ControlMask
#elif __APPLE__
   #include <TargetConditionals.h>          // this one defines all TARGET_x macros
   #if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
      // mouse mapping
      #define J3D_MOUSEBUTTON_LEFT      0
      #define J3D_MOUSEBUTTON_RIGHT     1
      #define J3D_MOUSEBUTTON_MIDDLE    2
      #define J3D_MOUSEWHEEL_UP         3
      #define J3D_MOUSEWHEEL_DOWN       4
   #elif TARGET_OS_MAC
      // mouse mapping
      #define J3D_MOUSEBUTTON_LEFT      NSLeftMouseDown
      #define J3D_MOUSEBUTTON_RIGHT     NSRightMouseDown
      #define J3D_MOUSEBUTTON_MIDDLE    NSOtherMouseDown
      #define J3D_MOUSEWHEEL_UP         0
      #define J3D_MOUSEWHEEL_DOWN       1
   #endif
   // key mapping
   // source:  http://web.archive.org/web/20100501161453/http://www.classicteck.com/rbarticles/mackeyboard.php
   #define J3D_KEY_NONE              -1
   #define J3D_KEY_0                 29
   #define J3D_KEY_1                 18
   #define J3D_KEY_2                 19
   #define J3D_KEY_3                 20
   #define J3D_KEY_4                 21
   #define J3D_KEY_5                 23
   #define J3D_KEY_6                 22
   #define J3D_KEY_7                 26
   #define J3D_KEY_8                 28
   #define J3D_KEY_9                 25
   #define J3D_KEY_A                 0
   #define J3D_KEY_ALTL              58
   #define J3D_KEY_ALTR              61
   #define J3D_KEY_B                 11
   #define J3D_KEY_BACKSPACE         51
   #define J3D_KEY_C                 8
   #define J3D_KEY_CAPSLOCK          57
   #define J3D_KEY_CONTROLL          59
   // FIXME:  right-control can't be detected, either normally or as a flag change
   #define J3D_KEY_CONTROLR          -1
   #define J3D_KEY_D                 2
   #define J3D_KEY_DELETE            117
   #define J3D_KEY_DOWN              125
   #define J3D_KEY_E                 14
   #define J3D_KEY_ENTER             36
   #define J3D_KEY_END               119
   #define J3D_KEY_ESCAPE            53
   #define J3D_KEY_F                 3
   #define J3D_KEY_F1                122
   #define J3D_KEY_F2                120
   #define J3D_KEY_F3                99
   #define J3D_KEY_F4                118
   #define J3D_KEY_F5                96
   #define J3D_KEY_F6                97
   #define J3D_KEY_F7                98
   #define J3D_KEY_F8                100
   #define J3D_KEY_F9                101
   #define J3D_KEY_F10               109
   #define J3D_KEY_F11               103
   #define J3D_KEY_F12               111
   #define J3D_KEY_F13               105
   #define J3D_KEY_F14               107
   #define J3D_KEY_F15               113
   #define J3D_KEY_G                 5
   #define J3D_KEY_H                 4
   #define J3D_KEY_HOME              115
   #define J3D_KEY_I                 34
   #define J3D_KEY_INSERT            114
   #define J3D_KEY_J                 38
   #define J3D_KEY_K                 40
   #define J3D_KEY_L                 37
   #define J3D_KEY_LEFT              123
   #define J3D_KEY_M                 46
   #define J3D_KEY_N                 45
   #define J3D_KEY_NUMLOCK           71
   // * '_NUMPAD_x' does not require the num-lock to be turned-on
   #define J3D_KEY_NUMPAD_0          82
   #define J3D_KEY_NUMPAD_1          83
   #define J3D_KEY_NUMPAD_2          84
   #define J3D_KEY_NUMPAD_3          85
   #define J3D_KEY_NUMPAD_4          86
   #define J3D_KEY_NUMPAD_5          87
   #define J3D_KEY_NUMPAD_6          88
   #define J3D_KEY_NUMPAD_7          89
   #define J3D_KEY_NUMPAD_8          91
   #define J3D_KEY_NUMPAD_9          92
   #define J3D_KEY_NUMPAD_ADD        69
   #define J3D_KEY_NUMPAD_DECIMAL    65
   #define J3D_KEY_NUMPAD_DIVIDE     75
   #define J3D_KEY_NUMPAD_MULTIPLY   67
   #define J3D_KEY_NUMPAD_SUBTRACT   78
   #define J3D_KEY_O                 31
   #define J3D_KEY_P                 35
   #define J3D_KEY_PAGEDOWN          121
   #define J3D_KEY_PAGEUP            116
   #define J3D_KEY_PAUSE             71
   #define J3D_KEY_PRINT             105
   #define J3D_KEY_Q                 12
   #define J3D_KEY_R                 15
   #define J3D_KEY_RIGHT             125
   #define J3D_KEY_S                 1
   #define J3D_KEY_SPACE             49
   #define J3D_KEY_SHIFTL            56
   #define J3D_KEY_SHIFTR            60
   #define J3D_KEY_T                 17
   #define J3D_KEY_TAB               48
   #define J3D_KEY_U                 32
   #define J3D_KEY_UP                126
   #define J3D_KEY_V                 9
   #define J3D_KEY_W                 13
   #define J3D_KEY_X                 7
   #define J3D_KEY_Y                 16
   #define J3D_KEY_Z                 6
   // modifiers (used in 'J3D_input_set_global_key')
   #define J3D_KEY_MOD_NONE             -1
   #define J3D_KEY_MOD_SHIFT            -1
   #define J3D_KEY_MOD_CONTROL          -1
#endif

// use specific classes from std (without std:: prefix)
using std::string;
using std::wstring;
using std::vector;
using std::map;

// OpenAL
typedef struct ALCdevice_struct ALCdevice;
typedef struct ALCcontext_struct ALCcontext;
typedef int ALenum, ALCenum;
// FreeType
typedef int FT_Error;
typedef struct FT_LibraryRec_* FT_Library;
typedef struct FT_FaceRec_* FT_Face;
// SQLite
typedef struct sqlite3 sqlite3;
// Ogg Vorbis
typedef struct OggVorbis_File OggVorbis_File;
// miniz
typedef struct mz_zip_archive_tag mz_zip_archive_tag;
typedef struct mz_zip_archive_tag mz_zip_archive;
// Pugi XML
namespace pugi {
   class xml_node;
};

// platform-based headers + libraries
#ifdef _WIN32
   #define NOMINMAX                         // get rid 'min(), max()' Win32 functions
   #include <windows.h>                     // windows header
   typedef void* HINTERNET;
#ifdef __MINGW32__
   #include <float.h>                       // FLT_MAX
#endif
#elif __ANDROID__
   // OpenSL ES
   typedef const struct SLObjectItf_ * const * SLObjectItf;
   typedef const struct SLEngineItf_ * const * SLEngineItf;
   typedef const struct SLPlayItf_ * const * SLPlayItf;
   typedef const struct SLBufferQueueItf_ * const * SLBufferQueueItf;
   // EGL
   typedef void *EGLDisplay;
   typedef void *EGLSurface;
   typedef void *EGLContext;
   // input
   typedef struct AInputEvent AInputEvent;
   #include <android/keycodes.h>            // AKEYCODE_xxx   
   #include <SLES/OpenSLES.h>
   #include <SLES/OpenSLES_Android.h>
#elif defined(__linux__) || defined(__sun)
   #include <float.h>         // FLT_MAX
#ifdef __sun
   typedef struct __glXContextRec *GLXContext;
#else
   typedef struct __GLXcontextRec *GLXContext;
#endif
   typedef union sigval sigval;
   #include <X11/X.h>                       // X Window system header
   #include <X11/Xlib.h>                    // 'Display', 'XKeyEvent' + more
#elif __APPLE__
   #include <TargetConditionals.h>          // this one defines all TARGET_x macros
#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
   #import <CoreFoundation/CoreFoundation.h> // Core foundation
#elif TARGET_OS_MAC
   #import <Cocoa/cocoa.h>                 // Cocoa windowed system; NSWindow, NSCursor etc.
#endif
#endif

// DEFINES //////////////////////////////////////////////////////

/*jdoc
{"type":"define",
"group":"Window events"
}*/
#define J3D_WINDOW_INIT    0
#define J3D_WINDOW_DEINIT  1
#define J3D_WINDOW_LOOP    2

// OS types
#define J3D_OS_WINDOWS                   "Windows"
#define J3D_OS_LINUX                     "Linux"
#define J3D_OS_SOLARIS                   "Solaris"
#define J3D_OS_MACOSX                    "MacOSX"
#define J3D_OS_IOS                       "iOS"
#define J3D_OS_ANDROID                   "Android"
// OS names
// windows
#define J3D_OS_WINDOWS_2000              "Windows 2000"
#define J3D_OS_WINDOWS_XP                "Windows XP"
#define J3D_OS_WINDOWS_XP64              "Windows XP 64-bit"
#define J3D_OS_WINDOWS_SERVER_2003       "Windows Server 2003"
#define J3D_OS_WINDOWS_SERVER_2003_R2    "Windows Server 2003 R2"
#define J3D_OS_WINDOWS_VISTA             "Windows Vista"
#define J3D_OS_WINDOWS_SERVER_2008       "Windows Server 2008"
#define J3D_OS_WINDOWS_SERVER_2008_R2    "Windows Server 2008 R2"
#define J3D_OS_WINDOWS_7                 "Windows 7"
#define J3D_OS_WINDOWS_SERVER_2012       "Windows Server 2012"
#define J3D_OS_WINDOWS_8                 "Windows 8"
#define J3D_OS_WINDOWS_SERVER_2012_R2    "Windows Server 2012 R2"
#define J3D_OS_WINDOWS_81                "Windows 8.1"
// mac osx
#define J3D_OS_MACOSX_MAVERICKS          "MacOSX Mavericks"
#define J3D_OS_MACOSX_MOUNTAINLION       "MacOSX Mountain Lion"
#define J3D_OS_MACOSX_LION               "MacOSX Lion"
#define J3D_OS_MACOSX_SNOWLEOPARD        "MacOSX Snow Leopard"
#define J3D_OS_MACOSX_LEOPARD            "MacOSX Leopard"
#define J3D_OS_MACOSX_TIGER              "MacOSX Tiger"
#define J3D_OS_MACOSX_PANTHER            "MacOSX Panther"
#define J3D_OS_MACOSX_JAGUAR             "MacOSX Jaguar"
#define J3D_OS_MACOSX_PUMA               "MacOSX Puma"
// ios
#define J3D_OS_IOS_ALPINE                "iOS Alpine"
#define J3D_OS_IOS_LITTLEBEAR            "iOS Little bear"
#define J3D_OS_IOS_BIGBEAR               "iOS Big Bear"
#define J3D_OS_IOS_SUGARBOWL             "iOS Sugarbowl"
#define J3D_OS_IOS_TIMBERLINE            "iOS Timberline"
#define J3D_OS_IOS_KIRKWOOD              "iOS Kirkwood"
#define J3D_OS_IOS_NORTHSTAR             "iOS Northstar"
#define J3D_OS_IOS_WILDCAT               "iOS Wildcat"
#define J3D_OS_IOS_APEX                  "iOS Apex"
#define J3D_OS_IOS_BAKER                 "iOS Baker"
#define J3D_OS_IOS_JASPER                "iOS Jasper"
#define J3D_OS_IOS_DURANGO               "iOS Durango"
#define J3D_OS_IOS_TELLURIDE             "iOS Telluride"
#define J3D_OS_IOS_HOODOO                "iOS Hoodoo"
#define J3D_OS_IOS_SUNDANCE              "iOS Sundance"
#define J3D_OS_IOS_BRIGHTON              "iOS Brighton"
#define J3D_OS_IOS_INNSBRUCK             "iOS Innsbruck"
#define J3D_OS_IOS_SOCHI                 "iOS Sochi"
#define J3D_OS_IOS_OKEMO                 "iOS Okemo"
#define J3D_OS_IOS_OKEMOTAOS             "iOS OkemoTaos"
#define J3D_OS_IOS_OKEMOZURS             "iOS OkemoZurs"
#define J3D_OS_IOS_STOWE                 "iOS Stowe"
#define J3D_OS_IOS_COPPER                "iOS Copper"
#define J3D_OS_IOS_MONARCH               "iOS Monarch"
// android
#define J3D_OS_ANDROID_10                "Android 1.0"
#define J3D_OS_ANDROID_11                "Android 1.1"
#define J3D_OS_ANDROID_CUPCAKE           "Android Cupcake"
#define J3D_OS_ANDROID_DONUT             "Android Donut"
#define J3D_OS_ANDROID_ECLAIR            "Android Eclair"
#define J3D_OS_ANDROID_FROYO             "Android Froyo"
#define J3D_OS_ANDROID_GINGERBREAD       "Android Gingerbread"
#define J3D_OS_ANDROID_HONEYCOMB         "Android Honeycomb"
#define J3D_OS_ANDROID_ICECREAM_SANDWICH "Android Ice Cream Sandwich"
#define J3D_OS_ANDROID_JELLY_BEAN        "Android Jelly Bean"
#define J3D_OS_ANDROID_KITKAT            "Android KitKat"
#define J3D_OS_ANDROID_LOLLILOP          "Android Lollipop"

/*jdoc
{"type":"define",
"group":"Image formats"
}*/
#define J3D_IMAGETYPE_NONE               ""
#define J3D_IMAGETYPE_BMP                "bmp"
#define J3D_IMAGETYPE_CUR                "cur"   // Microsoft cursors
#define J3D_IMAGETYPE_GIF                "gif"   // Compuserve graphics interchange
#define J3D_IMAGETYPE_ICO                "ico"   // Microsoft icons
#define J3D_IMAGETYPE_JPG                "jpg"
#define J3D_IMAGETYPE_PNG                "png"   // Portable network graphics
#define J3D_IMAGETYPE_PPM                "ppm"   // Portable pixel map
#define J3D_IMAGETYPE_PSD                "psd"   // Photoshop
#define J3D_IMAGETYPE_TGA                "tga"   // Truevision Graphics Adapter
#define J3D_IMAGETYPE_XCM                "xcm"   // X11 cursor, mostly without extension

/*jdoc
{"type":"define",
"group":"Audio formats"
}*/
#define J3D_AUDIOTYPE_NONE               ""
#define J3D_AUDIOTYPE_WAV                "wav"
#define J3D_AUDIOTYPE_OGG                "ogg"
#define J3D_AUDIOTYPE_OGV                "ogv"

/*jdoc
{"type":"define",
"group":"Audio states"
}*/
#define J3D_AUDIOSTATE_NONE        -1    // no audio state
#define J3D_AUDIOSTATE_PLAYING      0    // audio is playing
#define J3D_AUDIOSTATE_PAUSED       1    // audio is paused
#define J3D_AUDIOSTATE_STOPPED      2    // audio is stopped

/*jdoc
{"type":"define",
"group":"Video formats"
}*/
#define J3D_VIDEOTYPE_NONE               ""
#define J3D_VIDEOTYPE_OGV                "ogv"

/*jdoc
{"type":"define",
"group":"Video states"
}*/
#define J3D_VIDEOSTATE_NONE        -1    // no video state
#define J3D_VIDEOSTATE_PLAYING      0    // video is playing
#define J3D_VIDEOSTATE_PAUSED       1    // video is paused
#define J3D_VIDEOSTATE_STOPPED      2    // video is stopped

/*jdoc
{"type":"define",
"group":"Model formats"
}*/
#define J3D_MODELTYPE_NONE               ""
#define J3D_MODELTYPE_SHAPE              "shape" // prefixed Jolt3D! mode shapes (etc. quad, cubes)
#define J3D_MODELTYPE_OBJ                "obj"
#define J3D_MODELTYPE_DAE                "dae"
#define J3D_MODELTYPE_TERRAIN            "terrain"

// terrain types
#define J3D_TERRAIN_NONE                 "wav"
#define J3D_TERRAIN_HFF                  "hff"

/*jdoc
{"type":"define",
"group":"Font languages"
}*/
#define J3D_FONT_LANGUAGE_NONE           1
#define J3D_FONT_LANGUAGE_LATIN          2
#define J3D_FONT_LANGUAGE_GREEK          4
#define J3D_FONT_LANGUAGE_CYRILLIC       8
#define J3D_FONT_LANGUAGE_CHINESE        16   // simplified
#define J3D_FONT_LANGUAGE_ALL            (J3D_FONT_LANGUAGE_CHINESE * 2) - 1

/*jdoc
{"type":"define",
"group":"Camera move"
}*/
#define J3D_CAMERA_MOVE_DISABLED       -1
#define J3D_CAMERA_MOVE_TURNUP          0
#define J3D_CAMERA_MOVE_TURNDOWN        1
#define J3D_CAMERA_MOVE_MOVEUP          2
#define J3D_CAMERA_MOVE_MOVEDOWN        3
#define J3D_CAMERA_MOVE_TURNLEFT        4
#define J3D_CAMERA_MOVE_TURNRIGHT       5
#define J3D_CAMERA_MOVE_MOVEFORWARD     6
#define J3D_CAMERA_MOVE_MOVEBACKWARD    7

/*jdoc
{"type":"define",
"group":"Model quad facing"
}*/
#define J3D_MODEL_QUAD_FACING_ZAXIS      0     // create a quad facing the Z axis (default)
#define J3D_MODEL_QUAD_FACING_YAXIS      1     // create a quad facing the Y axis

/*jdoc
{"type":"define",
"group":"Model cube facing"
}*/
#define J3D_MODEL_CUBE_FACING_FRONT      0     // create a cube facing front eg. using CCW ordering (default)
#define J3D_MODEL_CUBE_FACING_BACK       1     // create a quad facing back eg. using CW ordering

/*jdoc
{"type":"define",
"group":"Texture filters"
}*/
#define J3D_TEXTURE_FILTER_LINEAR          0x2601   // GL_LINEAR
#define J3D_TEXTURE_FILTER_NEAREST         0x2600   // GL_NEAREST

/*jdoc
{"type":"define",
"group":"Texture mip-mapping filters"
}*/
#define J3D_TEXTURE_MIPMAP_FILTER_NEAREST         0x2600   // GL_NEAREST
#define J3D_TEXTURE_MIPMAP_FILTER_LINEAR          0x2601   // GL_LINEAR
#define J3D_TEXTURE_MIPMAP_FILTER_NEARESTNEAREST  0x2700   // GL_NEAREST_MIPMAP_NEAREST
#define J3D_TEXTURE_MIPMAP_FILTER_LINEARNEAREST   0x2701   // GL_LINEAR_MIPMAP_NEAREST
#define J3D_TEXTURE_MIPMAP_FILTER_NEARESTLINEAR   0x2702   // GL_NEAREST_MIPMAP_LINEAR
#define J3D_TEXTURE_MIPMAP_FILTER_LINEARLINEAR    0x2703   // GL_LINEAR_MIPMAP_LINEAR

/*jdoc
{"type":"define",
"group":"Texture wrap"
}*/
#define J3D_TEXTURE_WRAP_CLAMP_TO_EDGE   0x812F   // GL_CLAMP_TO_EDGE
#define J3D_TEXTURE_WRAP_REPEAT          0x2901   // GL_REPEAT

/*jdoc
{"type":"define",
"group":"Texture orientation"
}*/
#define J3D_TEXTURE_ORIENTATION_NORMAL    1
#define J3D_TEXTURE_ORIENTATION_MIRROR    2
#define J3D_TEXTURE_ORIENTATION_FLIP      4

/*jdoc
{"type":"define",
"group":"Draw usage"
}*/
#define J3D_DRAW_USAGE_STATIC_DRAW       0x88E4   // GL_STATIC_DRAW, modified once, used many times
#define J3D_DRAW_USAGE_DYNAMIC_DRAW      0x88E8   // GL_DYNAMIC_DRAW, modified and used many times

/*jdoc
{"type":"define",
"group":"Vertex attributes"
}*/
#define J3D_ATTR_VERTEXPOSITION          "aVertexPosition"
#define J3D_ATTR_VERTEXCOLOR             "aVertexColor"
#define J3D_ATTR_TEXTURECOORD            "aTextureCoord"
#define J3D_ATTR_VERTEXNORMAL            "aVertexNormal"

#define J3D_ATTR_VERTEXPOSITION_VBO      0
#define J3D_ATTR_VERTEXCOLOR_VBO         1
#define J3D_ATTR_TEXTURECOORD_VBO        2
#define J3D_ATTR_VERTEXNORMAL_VBO        3

/*jdoc
{"type":"define",
"group":"Bound vertex attributes"
}*/
#define J3D_ATTR_VERTEXPOSITION_BOUND    1
#define J3D_ATTR_VERTEXCOLOR_BOUND       2
#define J3D_ATTR_TEXTURECOORD_BOUND      4
#define J3D_ATTR_VERTEXNORMAL_BOUND      8
#define J3D_ATTR_ALL_BOUND               (J3D_ATTR_VERTEXNORMAL_BOUND * 2) - 1

// gui controls
#define J3D_GUI_NONE                    -1
#define J3D_GUI_WINDOW                   0
#define J3D_GUI_BUTTON                   1
#define J3D_GUI_SCROLLBAR                2
#define J3D_GUI_CHECKBOX                 3
#define J3D_GUI_LISTBOX                  4
#define J3D_GUI_TEXT                     5
#define J3D_GUI_IMAGE                    6
#define J3D_GUI_DROPBOX                  7
#define J3D_GUI_EDITBOX                  8

/*jdoc
{"type":"define",
"group":"Scrollbar orientation"
}*/
#define J3D_GUI_SCROLLBAR_HOR            0     // horizontal scrollbar
#define J3D_GUI_SCROLLBAR_VER            1     // vertical scrollbar

/*jdoc
{"type":"define",
"group":"Scrollbar thumbposition modes"
}*/
#define J3D_STP_BYPIXELS                 0     // return position by pixels
#define J3D_STP_BYPERCENTAGE             1     // return position by percentage

/*jdoc
{"type":"define",
"group":"Gui events"
}*/
#define J3D_GUIEVENT_NONE                    -1     // no gui event is performed
#define J3D_GUIEVENT_RENDER                   0     // render the controls
#define J3D_GUIEVENT_WINDOW_MOVING            10    // window is moving
#define J3D_GUIEVENT_WINDOW_MOVED             11    // window is moved
#define J3D_GUIEVENT_BUTTON_CLICKING          20    // button is clicked and not released
#define J3D_GUIEVENT_BUTTON_CLICKED           21    // button is clicked
#define J3D_GUIEVENT_SCROLLBAR_THUMB_CLICKED  30    // thumb is clicked (once)
#define J3D_GUIEVENT_SCROLLBAR_THUMB_MOVING   31    // thumb is moving
#define J3D_GUIEVENT_SCROLLBAR_THUMB_MOVED    32    // thumb is moved
#define J3D_GUIEVENT_CHECKBOX_CLICKING        40    // checkbox is clicked and not released
#define J3D_GUIEVENT_CHECKBOX_CLICKED         41    // checkbox is clicked
#define J3D_GUIEVENT_LISTBOX_ENTRY_CLICKING   50    // listbox entry is clicking
#define J3D_GUIEVENT_LISTBOX_ENTRY_CLICKED    51    // listbox entry is clicked
#define J3D_GUIEVENT_DROPBOX_CLICKING         60    // dropbox button is clicked and not released
#define J3D_GUIEVENT_DROPBOX_CLICKED          61    // dropbox button is clicked
#define J3D_GUIEVENT_DROPBOX_ENTRY_CLICKED    62    // dropbox entry is clicked
#define J3D_GUIEVENT_EDITBOX_CLICKED          70    // editbox is clicked
#define J3D_GUIEVENT_EDITBOX_INPUT            71    // editbox has taken a key input
#define J3D_GUIEVENT_EDITBOX_COMPLETED        72    // editbox input has completed

/*jdoc
{"type":"define",
"group":"Asynchronous events"
}*/
#define J3D_ASYNC_URLGRAB_COMPLETE            0     // the async request ended and the data is ready
#define J3D_ASYNC_URLGRAB_ERROR               1     // the async request ended abnormally
#define J3D_ASYNC_TIMEREVENT_COMPLETE         10    // the async timer event ended and triggered the callback

/*jdoc
{"type":"define",
"group":"File reading string methods"
}*/
#define J3D_FRS_ENTIREFILE        -1   // Reads the entire file, regardless file position
#define J3D_FRS_RESTFILE          -5   // Reads the rest of the file, from file position
#define J3D_FRS_WHITESPACEEOL     -4   // Reads white-space or newline chars, from file position
#define J3D_FRS_NOWHITESPACEEOL   -3   // Reads no white-space or newline chars, from file position
#define J3D_FRS_LINE              -2   // Reads to the next newline character, from file position

/*jdoc
{"type":"define",
"group":"File seeking methods"
}*/
#define J3D_FS_SEEK_SET      SEEK_SET   // Seek from the beginning of file
#define J3D_FS_SEEK_CUR      SEEK_CUR   // Seek from the current file position
#define J3D_FS_SEEK_END      SEEK_END   // Seek from the end of the file

/*jdoc
{"type":"define",
"group":"Buffer filling methods"
}*/
#define J3D_BF_SHADOWCOPY    0          // copy data only to internal buffer (CPU)
#define J3D_BF_GPUCOPY       1          // copy data only to GPU
#define J3D_BF_COPYBOTH      2          // copy data to both CPU and GPU

/*jdoc
{"type":"define",
"group":"File compression methods"
}*/
#define J3D_ZIP_NOCOMPRESSION      0   // No compression, best speed
#define J3D_ZIP_FASTCOMPRESSION    1   // Good compression, good speed
#define J3D_ZIP_BESTCOMPRESSION    2   // Best compression, worst speed

// STRUCTURES ///////////////////////////////////////////////////

struct J3D_FILE {
   // if there's a file and has been opened normally, this is used
   FILE* fp;
   // otherwise, if data has been given as a file, these are used
   string data;
   uint32_t data_offset;
   // methods
   static void get_folders_within_folder_recursive(const string& path, vector<string>& folders, bool recursive = true);
   static void folder_remove(const string& folder);
   // constructors
   J3D_FILE() {
      this->data_offset = 0;
   }
};

struct J3D_AUDIO_OGGFILE {
   int8_t* curPtr;
   int8_t* filePtr;
   size_t fileSize;
};

struct J3D_AUDIO {
   string name;
   string filename;
   string filetype;   // etc.  J3D_AUDIOTYPE_OGG
   // audio info
   int64_t pcmdata_size;      // the uncompressed PCM data size; this is for choosing whether to stream the audio or load it directly.
   uint32_t pcmdata_offset;   // file offset where PCM data begin; this is used for restarting audio and avoiding headers.
   uint16_t channels;         // Mono = 1, Stereo = 2, etc.
   int32_t sampleRate;        // 8000, 44100, etc.
   uint16_t bitsPerSample;    // 8 bits = 8, 16 bits = 16, etc.
   float onesample_time;      // duration of one sample
   static int BUFFER_SIZE;    // the streaming buffer for decoded audio; by default its 64KB
   bool is_streamed;          // this is TRUE for large audio
   // misc
   int32_t state_internal;    // used internally to fix against bogus states
   bool has_completed;        // used internally to indicate that an audio has reached the end of playback
   bool is_looping;           // TRUE if a looping has been specified on 'J3D_audio_play' call
// OpenSL ES (on mobiles)
#ifdef __ANDROID__
   pthread_mutex_t audio_mutex;
   SLObjectItf mPlayerObj;
   SLPlayItf mPlayer;
   SLBufferQueueItf mPlayerQueue;
   SLVolumeItf mVolume;
   char* data;   // this will always have the latest audio data; it always has 'BUFFER_SIZE' size of data
   static J3D_AUDIO* get_j3d_audio_from_bufferqueue(SLBufferQueueItf bq);
   static void bufferqueue(SLBufferQueueItf bq, void *context);
// OpenAL (on desktop)
#elif defined(_WIN32) || defined(__linux__) || defined(__sun) || defined(__APPLE__) || defined(__MINGW32__)
   unsigned int source;
   unsigned int buffers[2];   // streaming
   int format;       // format, etc 8/16 bits, mono/stereo
#endif
   // wav
   J3D_FILE file;
   string wav_fromdata_data;      // used when 'fromdata' is used on loading
   // ogg
   OggVorbis_File* ogg_file;
   vector<int8_t> ogg_fromdata_data;       // used when 'fromdata' is used on loading
   J3D_AUDIO_OGGFILE ogg_fromdata_oggfile;
   // misc
   static map<string,int32_t> volume;      // used to hold volumes, set for each audio
   // methods
   static void init();     // initializes the overall sound engine (either OpenAL / OpenSL ES)
   static void deinit();   // de-init either OpenAL / OpenSL ES
   static void create(J3D_AUDIO* audio);    // create/initialize individual audios, based on sound engine
   static void destroy(J3D_AUDIO* audio);   // destroy/deinit individual audios, based on sound engine
   static void unqueue_buffers(J3D_AUDIO* audio);
   static bool fetch_data(J3D_AUDIO* audio, vector<int8_t>& data);
   static void play(J3D_AUDIO* audio, bool is_looping);
   static void stop(J3D_AUDIO* audio, bool rewind);
   static void update(J3D_AUDIO* audio);   // this update a specific streamed audio; it called by 'update_all_audios'
   static void position_stream(J3D_AUDIO* audio, float seconds);   // moves the file stream in specific position, in seconds
   static void rewind_stream(J3D_AUDIO* audio);   // rewind the file stream to the start of sound data (format specific)
   static void close_stream(J3D_AUDIO* audio);
   static void update_all_audios();   // this update all (currently playing) streamed audios; its called once for all windows
   static string vorbis_error_to_string(int e);   // log ogg vorbis error
// platform-based methods
#ifdef __ANDROID__
#elif defined(_WIN32) || defined(__linux__) || defined(__APPLE__) || defined(__sun) || defined(__MINGW32__)
   static string openal_error_to_string(ALenum e);
   static string openal_context_error_to_string(ALCenum e);
#endif
   // wav
   static bool load_WAV(string name, string fromfile = "", string fromdata = "");
   // ogg
   static bool load_OGG(string name, string fromfile = "", string fromdata = "");
   static size_t ogg_fromdata_read(void* dst, size_t size1, size_t size2, void* fh);
   static int ogg_fromdata_seek(void *fh, int64_t to, int type);
   static int ogg_fromdata_close(void* fh);
   static long ogg_fromdata_tell(void *fh);
   // constructors
   J3D_AUDIO(string name, string filename) {
      this->name = name;
      this->filename = filename;
	  this->state_internal = J3D_AUDIOSTATE_NONE;
	  this->has_completed = false;
	  this->is_looping = false;
   }
   J3D_AUDIO() {}
};

// vec2
struct J3D_VEC2 {
   float x;
   float y;
   // operators
   J3D_VEC2 operator+(const J3D_VEC2& p) { return J3D_VEC2(this->x+p.x, this->y+p.y); }
   J3D_VEC2 operator+(const double& p) { return J3D_VEC2(this->x+(float)p, this->y+(float)p); }
   J3D_VEC2& operator+=(const J3D_VEC2& p) { this->x += p.x; this->y += p.y; return *this; }
   J3D_VEC2& operator+=(const double& p) { this->x += (float)p; this->y += (float)p; return *this; }
   J3D_VEC2 operator-(const J3D_VEC2& p) { return J3D_VEC2(this->x-p.x, this->y-p.y); }
   J3D_VEC2 operator-(const double& p) { return J3D_VEC2(this->x-(float)p, this->y-(float)p); }
   J3D_VEC2& operator-=(const J3D_VEC2& p) { this->x -= p.x; this->y -= p.y; return *this; }
   J3D_VEC2& operator-=(const double& p) { this->x -= (float)p; this->y -= (float)p; return *this; }
   J3D_VEC2 operator*(const J3D_VEC2& p) { return J3D_VEC2(this->x*p.x, this->y*p.y); }
   J3D_VEC2 operator*(const double& p) { return J3D_VEC2(this->x*(float)p, this->y*(float)p); }
   J3D_VEC2& operator*=(const J3D_VEC2& p) { this->x *= p.x; this->y *= p.y; return *this; }
   J3D_VEC2& operator*=(const double& p) { this->x *= (float)p; this->y *= (float)p; return *this; }
   J3D_VEC2 operator/(const J3D_VEC2& p) { return J3D_VEC2(this->x/p.x, this->y/p.y); }
   J3D_VEC2 operator/(const double& p) { return J3D_VEC2(this->x/(float)p, this->y/(float)p); }
   J3D_VEC2& operator/=(const J3D_VEC2& p) { this->x /= p.x; this->y /= p.y; return *this; }
   J3D_VEC2& operator/=(const double& p) { this->x /= (float)p; this->y /= (float)p; return *this; }
   // constructors
   J3D_VEC2(float x, float y) {
      this->x = x; this->y = y;
   }
   J3D_VEC2() {
      this->x = this->y = 0.0f;
   }
};

// vec3
struct J3D_VEC3 {
   float x;
   float y;
   float z;
   // operators
   J3D_VEC3 operator+(const J3D_VEC3& p) { return J3D_VEC3(this->x+p.x, this->y+p.y, this->z+p.z); }
   J3D_VEC3 operator+(const double& p) { return J3D_VEC3(this->x+(float)p, this->y+(float)p, this->z+(float)p); }
   J3D_VEC3& operator+=(const J3D_VEC3& p) { this->x += p.x; this->y += p.y; this->z += p.z; return *this; }
   J3D_VEC3& operator+=(const double& p) { this->x += (float)p; this->y += (float)p; this->z += (float)p; return *this; }
   J3D_VEC3 operator-(const J3D_VEC3& p) { return J3D_VEC3(this->x-p.x, this->y-p.y, this->z-p.z); }
   J3D_VEC3 operator-(const double& p) { return J3D_VEC3(this->x-(float)p, this->y-(float)p, this->z-(float)p); }
   J3D_VEC3& operator-=(const J3D_VEC3& p) { this->x -= p.x; this->y -= p.y; this->z -= p.z; return *this; }
   J3D_VEC3& operator-=(const double& p) { this->x -= (float)p; this->y -= (float)p; this->z -= (float)p; return *this; }
   J3D_VEC3 operator*(const J3D_VEC3& p) { return J3D_VEC3(this->x*p.x, this->y*p.y, this->z*p.z); }
   J3D_VEC3 operator*(const double& p) { return J3D_VEC3(this->x*(float)p, this->y*(float)p, this->z*(float)p); }
   J3D_VEC3& operator*=(const J3D_VEC3& p) { this->x *= p.x; this->y *= p.y; this->z *= p.z; return *this; }
   J3D_VEC3& operator*=(const double& p) { this->x *= (float)p; this->y *= (float)p; this->z *= (float)p; return *this; }
   J3D_VEC3 operator/(const J3D_VEC3& p) { return J3D_VEC3(this->x/p.x, this->y/p.y, this->z/p.z); }
   J3D_VEC3 operator/(const double& p) { return J3D_VEC3(this->x/(float)p, this->y/(float)p, this->z/(float)p); }
   J3D_VEC3& operator/=(const J3D_VEC3& p) { this->x /= p.x; this->y /= p.y; this->z /= p.z; return *this; }
   J3D_VEC3& operator/=(const double& p) { this->x /= (float)p; this->y /= (float)p; this->z /= (float)p; return *this; }
   // methods
   static J3D_VEC3 compute_normal(J3D_VEC3 v1, J3D_VEC3 v2, J3D_VEC3 v3);
   // constructors
   J3D_VEC3(float x, float y, float z) {
      this->x = x; this->y = y; this->z = z;
   }
   J3D_VEC3() {
      this->x = this->y = this->z = 0.0f;
   }
};

// bounding box
struct J3D_BBOX {
   J3D_VEC3 corners[8];   // the 8 bbox corners (local points from min/max)
   J3D_BBOX() {
      memset(this->corners, 0, 8 * sizeof(J3D_VEC3));
   }
};

// mat4x4
struct J3D_MAT4X4 {
   float mat[4][4];
   // constructors
   J3D_MAT4X4() {
      memset(this->mat, 0, (4 * 4) * sizeof(float));
      for(size_t x=0;x<4;x++) {
         this->mat[x][x] = 1.0f;
	  }
   }
};

struct J3D_CAMERA {
   string name;
   // camera specific
   J3D_VEC3 pos;
   float yaw;
   float pitch;
   float yawRate;
   float pitchRate;
   float speed;
   float speedInterval;
   float yawPitchInterval;
   map<int32_t, vector<int32_t> > move_keymapping;   // programmable camera move key mapping
   // frustum
   float frustum[6][4];                // holds the 6 frustum planes, resulted with a call to '.extract_frustum_planes'
   // shader
   J3D_MAT4X4 uPMatrix;                // projection matrix (uniform)
   J3D_MAT4X4 uMVMatrix;               // model-view matrix (uniform, defaults to identity)
   vector<J3D_MAT4X4> mvMatrixStack;   // stack of model-view matrices (for push/pop mechanism)
   J3D_MAT4X4 objectMatrix;            // this matrix holds the current object matrix. Resets on 'J3D_transform_push()'.
   // methods
   static void compute_MV_matrix(J3D_CAMERA* camera);          // computes the model-view matrix for the active camera, by its type
   static void extract_frustum_planes(J3D_CAMERA* camera);   // extract frustum 6 planes (near,far,left,right,up,down)
   static void handle_input(J3D_CAMERA* camera);              // input supported by camera type (fixed)
   static void modify_camera(J3D_CAMERA* camera);             // modify active camera by user input
   static void validate(string name);
   static void destroy(J3D_CAMERA* c);
   // constructors
   J3D_CAMERA(string name) {
	  this->name = name;
	  // shader initial
	  this->uPMatrix = J3D_MAT4X4();
	  this->uMVMatrix = J3D_MAT4X4();
	  this->mvMatrixStack.clear();
	  this->objectMatrix = J3D_MAT4X4();
	  // camera specific initial
	  this->pos = J3D_VEC3(0,0,0);
	  this->yaw = 0.0f;
	  this->pitch = 0.0f;
	  this->yawRate = 0.0f;
	  this->pitchRate = 0.0f;
	  this->speed = 0.0f;
	  this->speedInterval = 0.0f;
	  this->yawPitchInterval = 0.0f;
	  this->move_keymapping.clear();
   }
   J3D_CAMERA() { }
};

struct J3D_COLOR {
   uint8_t r,g,b,a;
   J3D_COLOR() {
      this->r = this->g = this->b = this->a = 0;
   }
   J3D_COLOR(uint8_t r, uint8_t g, uint8_t b) {
      this->r = r;
	  this->g = g;
	  this->b = b;
	  this->a = 255;
   }
   J3D_COLOR(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
      this->r = r;
	  this->g = g;
	  this->b = b;
	  this->a = a;
   }
   J3D_COLOR(const uint8_t* c) {
      this->r = c[0];
	  this->g = c[1];
	  this->b = c[2];
	  this->a = 255;
   }
   bool operator == (J3D_COLOR c) const {
      return (r == c.r && g == c.g && b == c.b);
   }
};

struct J3D_COLOR_GRADIENT {
   bool use_gradient;
   J3D_COLOR color1;
   J3D_COLOR color2;
   J3D_COLOR_GRADIENT() {
      this->use_gradient = false;
   }
   J3D_COLOR_GRADIENT(J3D_COLOR color1, J3D_COLOR color2) {
      this->use_gradient = true;
      this->color1 = color1;
      this->color2 = color2;
   }
};

struct J3D_CURSOR {
// platform-based window, context and (optional) methods
#ifdef _WIN32
   HCURSOR cursor;
#elif __ANDROID__
#elif defined(__linux__) || defined(__sun)
   Cursor cursor;
#elif __APPLE__
#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
#elif TARGET_OS_MAC
   NSCursor* cursor;
   #endif
#endif
   // method
   static void destroy(J3D_CURSOR* cursor);
   // constructor
   J3D_CURSOR() {
#ifdef _WIN32
   this->cursor = NULL;
#elif __ANDROID__
#elif defined(__linux__) || defined(__sun)
   this->cursor = None;
#elif __APPLE__
#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
#elif TARGET_OS_MAC
   this->cursor = nil;
#endif
#endif
   }
};

struct J3D_DB_QUERYRESULT {
   map<uint32_t, map<uint32_t, string> > rows_num;   // records sorted by numerical-indices as:   [index][column index] = [value]
   map<uint32_t, map<string, string> > rows_assoc;   // records sorted by associative-names as:   [index][column name]  = [value]
   J3D_DB_QUERYRESULT() {
	  this->rows_num.clear();
	  this->rows_assoc.clear();
   }
};

struct J3D_DB_BINDING {
   int32_t type;
   double double_value;
   int32_t int_value;
   string text_value;
   J3D_DB_BINDING() {
      this->type = -1;
   }
   J3D_DB_BINDING(double value) {
	  this->type = 0;   // double
      this->double_value = value;
   }
   J3D_DB_BINDING(int32_t value) {
	  this->type = 1;   // int
      this->int_value = value;
   }
   J3D_DB_BINDING(string value) {
	  this->type = 2;   // text
      this->text_value = value;
   }
};

struct J3D_RECT {
   int32_t left;
   int32_t top;
   int32_t right;
   int32_t bottom;
   // operators
   J3D_RECT operator+(const J3D_RECT& p) { return J3D_RECT(this->left+p.left, this->top+p.top, this->right+p.right, this->bottom+p.bottom); }
   J3D_RECT operator-(const J3D_RECT& p) { return J3D_RECT(this->left-p.left, this->top-p.top, this->right-p.right, this->bottom-p.bottom); }
   bool operator==(J3D_RECT r) const { return (left==r.left && top==r.top && right==r.right && bottom==r.bottom); }
   // constructors
   J3D_RECT(int32_t left, int32_t top, int32_t right, int32_t bottom) {
      this->left = left; this->top = top; this->right = right; this->bottom = bottom;
   }
   J3D_RECT() {
      this->left = this->top = this->right = this->bottom = 0;
   }
};

struct J3D_RECTF {
   float left;
   float top;
   float right;
   float bottom;
   // overloads
   J3D_RECTF operator+(const J3D_RECTF& p) { return J3D_RECTF(this->left+p.left, this->top+p.top, this->right+p.right, this->bottom+p.bottom); }
   J3D_RECTF operator-(const J3D_RECTF& p) { return J3D_RECTF(this->left-p.left, this->top-p.top, this->right-p.right, this->bottom-p.bottom); }
   // constructors
   J3D_RECTF(float left, float top, float right, float bottom) {
      this->left = left; this->top = top; this->right = right; this->bottom = bottom;
   }
   J3D_RECTF() {
      this->left = this->top = this->right = this->bottom = 0.0f;
   }
};

struct J3D_ENUMWINDOW {
// platform-based window handle
#ifdef _WIN32
   HWND window;
#elif __ANDROID__
   int window;
#elif defined(__linux__) || defined(__sun)
   Window window;
#elif __APPLE__
   int window;
#endif
   string title;
   bool is_minimized;
   // filter
   static string by_titlefragment;
   // constructors
   J3D_ENUMWINDOW() {
	  this->window = 0;
      this->is_minimized = false;
   }
};

struct J3D_INT3 {
   int32_t n1;
   int32_t n2;
   int32_t n3;
   J3D_INT3() { this->n1 = this->n2 = this->n3 = 0; }
   J3D_INT3(int32_t n1, int32_t n2, int32_t n3) { this->n1 = n1; this->n2 = n2; this->n3 = n3; }
};

struct J3D_INT4 {
   int32_t n1;
   int32_t n2;
   int32_t n3;
   int32_t n4;
   J3D_INT4() { this->n1 = this->n2 = this->n3 = this->n4 = 0; }
   J3D_INT4(int32_t n1, int32_t n2, int32_t n3, int32_t n4) { this->n1 = n1; this->n2 = n2; this->n3 = n3; this->n4 = n4; }
};

struct J3D_OS {
   string generic;                        // etc. "Windows", "Linux" (the generic OS name)
   string name;                           // etc. "Windows XP", "Ubuntu" (the OS name)
   string version;                        // etc. "6.1" (windows 7) or "12.09" (ubuntu) or "10.8.2" (OSX mountain lion)
   string extra;                          // optional extra information; filled in some OS
   J3D_OS() {
      this->generic = this->name = this->version = this->extra = "";
   }
};

struct J3D_POINT {
   int32_t x;
   int32_t y;
   // overloads + operators
   J3D_POINT operator+(const J3D_POINT &p) { return J3D_POINT(this->x+p.x, this->y+p.y); }
   J3D_POINT operator+(const int32_t &p) { return J3D_POINT(this->x+p, this->y+p); }
   J3D_POINT operator-(const J3D_POINT &p) { return J3D_POINT(this->x-p.x, this->y-p.y); }
   J3D_POINT operator-(const int32_t &p) { return J3D_POINT(this->x-p, this->y-p); }
   J3D_POINT operator*(const J3D_POINT &p) { return J3D_POINT(this->x*p.x, this->y*p.y); }
   J3D_POINT operator*(const float &p) { return J3D_POINT((int32_t)(this->x*p), (int32_t)(this->y*p)); }
   J3D_POINT operator/(const J3D_POINT &p) { return J3D_POINT(this->x/p.x, this->y/p.y); }
   J3D_POINT operator/(const float &p) { return J3D_POINT((int32_t)(this->x/p), (int32_t)(this->y/p)); }
   bool operator==(J3D_POINT p) const { return (x==p.x && y==p.y); }
   bool operator!=(J3D_POINT p) const { return !(x==p.x && y==p.y); }
   // constructors
   J3D_POINT(int32_t x,int32_t y) {
      this->x = x; this->y = y;
   }
   J3D_POINT() {
      this->x = this->y = 0;
   }
};

struct J3D_RECTPACK {
   vector<J3D_POINT> pages;  // the w/h dimensions of each page
   struct J3D_RECTPACK_RC {
      J3D_RECT pc;      // the packed rectangle as pixel coords:      x,y,w,h
      J3D_RECTF tc;     // the packed rectangle as texture coords:    u1,v1,u2,v2
      uint32_t page;    // the page the rectangle belongs to; usually 0 (first)
   };
   vector<J3D_RECTPACK_RC> rcp;      // the packed rectangle
   J3D_RECTPACK() { }
};

struct J3D_2D_MULTIDRAW {
   J3D_POINT pos;
   J3D_POINT size;
   string text;                   // used on 'J3D_2d_text_draw' only
   wstring wtext;                 // #
   float scale;                   // #
   vector<J3D_COLOR> rangecolor;  // #
   J3D_POINT ul, ur, dr, dl;      // used on 'J3D_2d_trapezoid_draw' only
   vector<J3D_POINT> points;      // used on 'J3D_2d_polygon_draw' and 'J3D_2d_eliipsoid_draw' only
   J3D_POINT radius;              // used on 'J3D_2d_ellipsoid_draw'
   int32_t quality;               // used on 'J3D_2d_ellipsoid_draw'
   J3D_COLOR color;
   uint8_t opacity;
   J3D_RECT texpixelcoords;
   J3D_COLOR_GRADIENT colorgradient;
   int32_t orientation;
   // constructors
   J3D_2D_MULTIDRAW() {
      this->pos = J3D_POINT();
      this->size = J3D_POINT();
      this->color = J3D_COLOR(255,255,255);
      this->opacity = 100;
      this->texpixelcoords = J3D_RECT();
      this->colorgradient = J3D_COLOR_GRADIENT();
	  this->orientation = J3D_TEXTURE_ORIENTATION_NORMAL;
   }
   // used for 'J3D_2d_text_draw'
   J3D_2D_MULTIDRAW(J3D_POINT pos, string text, wstring wtext = L"", J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100, float scale = 1.0f, J3D_COLOR_GRADIENT colorgradient = J3D_COLOR_GRADIENT(), vector<J3D_COLOR> rangecolor = vector<J3D_COLOR>()) {
      this->pos = pos;
      this->text = text;
      this->wtext = wtext;
      this->color = color;
      this->opacity = opacity;
	  this->scale = scale;
      this->colorgradient = colorgradient;
	  this->rangecolor = rangecolor;
   }
   // used for 'J3D_2d_quad_draw', 'J3D_2d_rect_draw'
   J3D_2D_MULTIDRAW(J3D_POINT pos, J3D_POINT size, J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100, J3D_RECT texpixelcoords = J3D_RECT(), J3D_COLOR_GRADIENT colorgradient = J3D_COLOR_GRADIENT(), int32_t orientation = J3D_TEXTURE_ORIENTATION_NORMAL) {
      this->pos = pos;
      this->size = size;
      this->color = color;
      this->opacity = opacity;
      this->texpixelcoords = texpixelcoords;
      this->colorgradient = colorgradient;
	  this->orientation = orientation;
   }
   // used for 'J3D_2d_trapezoid_draw'
   J3D_2D_MULTIDRAW(J3D_POINT ul, J3D_POINT ur, J3D_POINT dr, J3D_POINT dl, J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100, J3D_RECT texpixelcoords = J3D_RECT(), J3D_COLOR_GRADIENT colorgradient = J3D_COLOR_GRADIENT(), int32_t orientation = J3D_TEXTURE_ORIENTATION_NORMAL) {
      this->ul = ul;
      this->ur = ur;
      this->dr = dr;
      this->dl = dl;
      this->color = color;
      this->opacity = opacity;
      this->texpixelcoords = texpixelcoords;
      this->colorgradient = colorgradient;
	  this->orientation = orientation;
   }
   // used for 'J3D_2d_polygon_draw'
   J3D_2D_MULTIDRAW(vector<J3D_POINT> points, J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100) {
      this->points = points;
      this->color = color;
      this->opacity = opacity;
   }
   // used for 'J3D_2d_ellipsoid_draw'
   J3D_2D_MULTIDRAW(J3D_POINT pos, J3D_POINT radius, int32_t quality, J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100) {
      this->pos = pos;
	  this->radius = radius;
	  this->quality = quality;
      this->color = color;
      this->opacity = opacity;
   }
};

struct J3D_FONT {
   // basic
   string filename;                    // holds the font's filename
   int16_t height;                     // holds The Height Of The Font.
   bool antialiased;                   // TRUE if antialiased
   bool bold;                          // TRUE if bold
   // internal
   string texturename;                 // the texture name font is using
   int16_t bearing_max_y;              // holds the maximum Y bearing (or the tallest glyph in pixels)   
   int16_t glyph_max_x;                // holds the number of pixels in X axis for the flattest glyph (used on advancing in X)
   int16_t glyph_max_y;                // holds the number of pixels in Y axis for the tallest glyph (used on advancing in Y)
   vector<uint32_t> charcode;          // holds all the inserted glyph codes, sorted;  it's language agnostic; codes are sorted by value
    struct GLYPH {
      int16_t advance_x;        // the horizontal 'advance' for each glyph. the pixel distance for a character to next
	  int16_t bearing_x;
	  int16_t offset_y;         // the pixel distance to the glyph's Y start (it's a pre-calculated value, using bearing, max bearing and height)
      J3D_RECTF pixelcoord;     // holds the pixel coords for the glyph into texture; used to build the quads for rendering
      J3D_RECTF texcoord;       // holds the texture coords for the glyph into texture;
      J3D_POINT size;           // the texture dimensions of the glyph (used to handle the rendering and gen UVs)
      J3D_POINT size_orig;      // the real dimensions of the glyph etc. the internal sizes given by Freetype
   };
   vector<GLYPH> glyph;
   // methods
   static string ft_error_to_string(FT_Error e);
   static void create_glyph_texture(J3D_FONT* font, const FT_Face& face, uint32_t ch, bool antialiased, int16_t& bearing_y, vector<J3D_COLOR>& pixels);
   static vector<uint32_t> get_chinese_codepoints();
   static void destroy(J3D_FONT* font);
   // constructors
   J3D_FONT() { }
};

struct J3D_BUFFER {
   unsigned int vbo[10];   // 10 VBOs are typically more than enough (vertex, color, texcoords, ..)
   bool vbo_generated;     // TRUE if buffers are generated (called once)
   bool use_compression;   // TRUE if copies are compressed (string) or not (vector); By default is FALSE
   static bool compressed_copies;   // TRUE for enabling buffer compression for the next operations (global)
   // compressed shadow copies (slower, less RAM)
   string copy_cmp[10];    // Zlib-compressed copies of all buffer data; they're compressed through 'J3D_buffer_fill'
   uint32_t size_cmp[10];  // the uncompressed size of the above compressed copies; used to alloc enough size for decompression
   // non-compressed shadow copies (faster, more RAM)
   vector< vector<float> > copy_ucmp;
   // methods
   static void buffer_compress(J3D_BUFFER* b, string attr_name, const float* data, uint32_t datasize);    // compress a vector<float> into a string using Zlib (miniz)
   static vector<float> buffer_uncompress(const J3D_BUFFER* b, string attr_name);            // uncompress a Zlib-compressed string to vector<float>
   // constructors
   J3D_BUFFER() {
	  vbo_generated = false;
	  // resize the non-compressed copies in case user wants to use compression
	  copy_ucmp.resize(10);
	  use_compression = false;   // false by default
   }
};

struct J3D_MODEL {
   string name;
   string type;                         // this is the resource type of model etc. J3D_MODELTYPE_xx
   J3D_BUFFER buffer;                   // holding the buffer
   string shader;                       // the shader to use for rendering, then restore it at the end; if left empty, it uses the currently active one (default)
   map<string, map<string, int> > firstindex;    // first vertex index as:  [object][segment] = [vertex index, integer]
   map<string, map<string, int> > numtriangles;  // number of triangles as:  [object][segment] = [number of tris, integer]
   map<string, map<string, string> > textures;   // the texture name as:  [object][segment] = [texture name]. A non-exist texture just uses the current active one.
   map<string, map<string, string> > texture_filenames;   // the texture filename as:  [object][segment] = [texture filename]. A non-exist texture just uses the current active one.
   map<string, bool> material_filenames;                  // (only for debug) the material files used by the model; they store materials, texture filenames etc.
   bool use_frustumculling;                // If TRUE (default), it enables the frustum culling for this model
   static float frustumculling_distance;   // if has a value > 0, it will check each model's object for frustum visibility by this distance

   // used for textured triangle simplification - functionality is experimental
   struct VERTEX_INDICES {
      J3D_INT3 vp;   // 3 position indices for current triangle
      J3D_INT3 vn;   // 3 normals indices for current triangle
      J3D_INT3 vt;   // 3 texcoords indices for current triangle
	  VERTEX_INDICES() {}
   };
   
   map<string, vector<J3D_VEC3> > positions;   // original by-file vertex positions
   map<string, vector<J3D_VEC3> > normals;     // original by-file vertex normals
   map<string, vector<J3D_VEC2> > texcoords;   // original by-file texture coords
   map<string, vector<VERTEX_INDICES> > triangles;   // original by-file triangles

   map<string, J3D_BBOX> bbox;     // the bbox as:  [object] = [bounding box]
   // methods
   static J3D_BBOX bbox_compute(const float* data, uint32_t datasize);
   static void destroy(J3D_MODEL *m);
   // loaders (they're implemented on '/model' folder
   static bool load_OBJ(string fromfile, string fromdata = "", uint16_t filter = J3D_TEXTURE_FILTER_LINEAR, uint16_t mipmap_filter = J3D_TEXTURE_MIPMAP_FILTER_LINEAR, map<string,string>* material_files = NULL, J3D_MODEL* m = NULL);
   static bool load_DAE(string fromfile, string fromdata = "", uint16_t filter = J3D_TEXTURE_FILTER_LINEAR, uint16_t mipmap_filter = J3D_TEXTURE_MIPMAP_FILTER_LINEAR, J3D_MODEL* m = NULL);
   // constructors
   J3D_MODEL(string name) {
	  this->name = name;
	  this->type = J3D_MODELTYPE_NONE;
	  this->buffer = J3D_BUFFER();
	  this->use_frustumculling = true;
	  this->firstindex.clear();
	  this->numtriangles.clear();
	  this->textures.clear();
	  this->texture_filenames.clear();
	  this->material_filenames.clear();
   }
   J3D_MODEL() { }
};

struct J3D_SHADERPROGRAM {
   unsigned int program;
   map<string, int> attributes;
   map<string, int> uniforms;
   // methods
   static unsigned int shader_load(string name, const char *shadertext, unsigned int type);
   static void validate(string name);
   static void destroy(J3D_SHADERPROGRAM *program);
   // constructors
   J3D_SHADERPROGRAM(int32_t program) {
      this->program = program;
   }
   J3D_SHADERPROGRAM() { }
};

struct J3D_TERRAIN {
   string name;
   J3D_POINT size;          // terrain size; defaults to 32x32
   J3D_VEC2 quadsize;       // terrain quad size; defaults to 1.0f x 1.0f
   float scaleheight;       // some terrain methods use this to modify the result; defaults to 1
   bool reversed_normals;   // TRUE to always use reversed normal to light-up the other side of terrain (def: FALSE)
   J3D_MODEL* model;   // pointer to model, holding the terrain buffer
   // texture code; holds information about added textures and their coordinates (converted from pixel sizes)
   struct TEXCODE {
      string texture;
	  J3D_RECTF texcoords;            // texture coords describing a quad in texture, in the form of:   left, top, right, bottom
	  J3D_RECT pixelcoords;           // texture pixel coords describing a quad in texture, in the form of:   left, top, right, bottom
   };
   map<int32_t, TEXCODE> texcodes;   // [texcode] = [texcode struct]
   // terrain modifying commands structure
   struct MODIFY_COMMAND {
      // the quad x/z if commands has to do with one quad
      uint32_t x;
      uint32_t z;
      float height;          // the quad's height; it contains a height (float) or FLT_MAX if its ignored (etc. stay the same)
      int32_t texturecode;   // the quad's (new) texture code; it contains an uint16_t texturecode or -1 for ignoring it
   };
   vector<MODIFY_COMMAND> modify_commands;
   vector< vector<int32_t> > quadtexcode;   // holds the texture code for each quad as:  [z][x] = [texture code]
   vector< vector<float> > quadheight;      // holds the height for each quad as:  [z][x] = [height]
   // grid info + accelerators
   uint16_t gridsize;                       // the base grid size, for example 8 means 8x8 grid sized objects
   map<string, J3D_POINT> gridsizeobj;      // holds the grid size of object like, as:  [object] = J3D_POINT; this can be different from 'gridsize'
   map<string, uint32_t> floats_per_grid;                   // holds the number of floats per grid, per attribute; this is used for finding a quad fast
   map<string, uint32_t> floats_per_grid_terrain_line;      // holds the number of floats per grid per terrain line, per attribute; this is used for finding a quad fast
   map<string, uint32_t> floats_per_quad_terrain_line;      // holds the number of floats per quad per terrain line, per attribute; this is used for finding a quad fast
   map<uint32_t, map<uint32_t, string> > grid_int_to_str;    // accelerator, providing pre-converted versions of int to strings (perf++)
   map<string, uint16_t> num_components_per_triangle;    // holds the number of components (eg. VP has 3) per triangle (VP has 9)
   vector< vector<uint32_t> >  vp_offset;    // holds the pre-computed vertex offset for [VP] (perf++)
   // methods
   static uint32_t get_offset_from_pos(J3D_TERRAIN* ter, const string& attr_name, uint32_t x, uint32_t z);
   static void validate(string name);
   static void destroy(J3D_TERRAIN* t);
   // constructors
   J3D_TERRAIN(string name) {
	  this->name = name;
	  this->scaleheight = 1.0f;
   }
   J3D_TERRAIN() { }
};

struct J3D_TERRAIN_TEXCODE {
   int32_t texcode;
   int32_t percentage;
   // constructors
   J3D_TERRAIN_TEXCODE(int32_t texcode, int32_t percentage) {
      this->texcode = texcode;
      this->percentage = percentage;
   }
   J3D_TERRAIN_TEXCODE() {
      this->texcode = -1;
      this->percentage = 0;
   }
};

struct J3D_TEXTURE {
   string name;
   string filename;   // to avoid reloading same files
   uint16_t filter;   // likewise
   int wrap;        // likewise
   // dimensions powered-by-2 (in most of cases, they don't reflect the real image size)
   size_t width;
   size_t height;
   // original file dimensions
   size_t width_orig;
   size_t height_orig;
   // context
   unsigned int textureid;          // opengl texture
   unsigned int textureid_depth;    // opengl texture depth (opt, used on render-to-texture)
   // misc
   static bool transparency;        // TRUE to skip transparent pixels (i.e. PNG) from rendering (both 2D/3D)
   // methods
   static void destroy(J3D_TEXTURE* texture);
   // constructors
   J3D_TEXTURE(string name) {
	  this->name = name;
	  this->textureid = 0;
	  this->textureid_depth = 0;
   }
   J3D_TEXTURE() { }
};

struct J3D_TEXTUREPIXELS {
   string filename;
   string format;   // J3D_IMAGETYPE_xx
   // pixels are always in RGBA format (32-bit)
   vector<uint8_t> pixels;
   // texture dimensions
   uint32_t width;
   uint32_t height;
   // extra information per-format
     // hotspot x/y for .CUR files
     int16_t cur_hotspot_x;
     int16_t cur_hotspot_y;
   // methods
   static void resize_pixels(vector<uint8_t>& pixels, uint32_t width, uint32_t height, uint32_t new_width, uint32_t new_height, bool flip = true);
   static void flip_pixels(uint8_t* dest_pixels, uint8_t* src_pixels, J3D_POINT size);
   static void convert_to_pow2(uint32_t& width, uint32_t& height);
   static void write_pixels(const J3D_TEXTUREPIXELS& src, J3D_TEXTUREPIXELS* dest, const J3D_POINT& dest_position);
   static int32_t color_distance(const J3D_COLOR& c1, const J3D_COLOR& c2);
   // loaders
   static bool load_ICOCUR(J3D_TEXTUREPIXELS* tp, string filetype, string fromfile, string fromdata = "");
   static bool load_PPM(J3D_TEXTUREPIXELS* tp, string fromfile, string fromdata = "");
   static bool load_XCM(J3D_TEXTUREPIXELS* tp, string fromfile, string fromdata = "");
   // savers
   static bool save_PPM(string filename, const J3D_TEXTUREPIXELS& tp);
// per-platform methods
#ifdef _WIN32
   static void convert_pixels_to_andxor_masks(const J3D_TEXTUREPIXELS& tp, HWND hwnd, HBITMAP* cur_andmask, HBITMAP* cur_xormask);
#elif __ANDROID__
#elif defined(__linux__) || defined(__sun)
#elif __APPLE__
#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
#elif TARGET_OS_MAC
   static NSImage* convert_pixels_to_NSImage(const J3D_TEXTUREPIXELS& tp);
#endif
#endif
   // constructors
   J3D_TEXTUREPIXELS(string filename) {
	  this->filename = filename;
      this->format = J3D_IMAGETYPE_NONE;
      this->cur_hotspot_x = this->cur_hotspot_y = 0;
   }
   J3D_TEXTUREPIXELS() {
      this->format = J3D_IMAGETYPE_NONE;
      this->cur_hotspot_x = this->cur_hotspot_y = 0;
   }
};

struct J3D_TEXTURERENDER {
   int viewport[4];      // the viewport to store/restore before/after rendering
   unsigned int FFrameBuffer;    // the front frame buffer
   int default_frame_buffer;   // the default frame buffer (the one before rendering-to-texture)
   J3D_TEXTURE texture;    // the texture for render to
   J3D_TEXTURERENDER() { }
};

struct OGVLOADER;
struct J3D_VIDEO {
   string name;
   string filename;
   string filetype;        // etc.  J3D_VIDEOTYPE_OGV
   J3D_POINT size;         // video size in pixels
   // video info
   uint32_t videodata_offset;   // file offset where video data begin; this is used for restarting video and avoiding headers.
   int32_t state;          // the playing state
   float video_offset;   // current video offset (used for sync when no audio is present)
   // streams
   J3D_AUDIO* audio;       // pointer to audio
   J3D_TEXTURE* texture;   // pointer to texture (for frame rendering)
   // ogv
   OGVLOADER *ogvloader;
   // methods
   static void create(J3D_VIDEO* video);    // create/initialize individual videos
   static void validate(string name);
   static void destroy(J3D_VIDEO* video);   // destroy/deinit individual audios, based on sound engine
   static void pause(J3D_VIDEO* video);
   static void update(J3D_VIDEO* video);   // this update a specific streamed VIDEO; it called by 'update_all_videos'
   static void update_all_videos();   // this update all (currently playing) streamed videos; its called once for all windows
   // loaders
   static void load_OGV(J3D_VIDEO* video, string filename);
   // constructors
   J3D_VIDEO(string name, string filename) {
	  this->name = name;
	  this->filename = filename;
	  this->size = J3D_POINT(0,0);
	  this->state = J3D_VIDEOSTATE_NONE;
	  this->video_offset = 0.0f;
	  this->audio = NULL;
	  this->texture = NULL;
   }
   J3D_VIDEO() { }
};

// for OSX: window and context (view) interfaces must be set before the 'J3D_WINDOW' structure
#ifdef __APPLE__
#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
#elif TARGET_OS_MAC
   @interface mac_window : NSWindow {
   }
   @end

   @interface mac_openglview : NSOpenGLView {
   }
   - (void) drawRect: (NSRect) bounds;
   @end
#endif
#endif

struct J3D_WINDOW {
// platform-based window, context and (optional) methods
#ifdef _WIN32
   HWND window;
   HGLRC context;
   HDC hdc;      // this is the 'Display' equivalent for Win32
   HICON icon;   // since windows sends an HICON for setting the icon with WM_SETICON, we need to store it
   // methods
   static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT message,WPARAM wParam, LPARAM lParam);
   static BOOL CALLBACK enum_windows_proc(HWND hwnd, LPARAM lParam);
   static J3D_WINDOW* get_j3d_window_from_hwnd(HWND hwnd);
#elif __ANDROID__
   int window;
   int context;
   // methods
   static void engine_init_display();
   static void engine_term_display();
   static int32_t engine_handle_input(struct android_app* app, AInputEvent* event);
   static void engine_handle_cmd(struct android_app* app, int32_t cmd);
   static void handle_events();
   static int32_t translate_key(int32_t key);
   static int32_t engine_get_android_api_level();
#elif defined(__linux__) || defined(__sun)
   Window window;
   GLXContext context;
   // methods
   static J3D_WINDOW* get_j3d_window_from_xwindow(Window window);
   static void handle_events(J3D_WINDOW* window);
   static int32_t translate_key(XKeyEvent key);
   static unsigned long* get_window_property(Window w, string prop, unsigned long& num_items);
#elif __APPLE__
#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
   int window;   // fake for compiling!
   int context;
#elif TARGET_OS_MAC
   mac_window* window;
   mac_openglview* context;
   // methods
   static J3D_WINDOW* get_j3d_window_from_nswindow(NSWindow* window);
   static void handle_events();
#endif
#endif
   string name;         // title
   J3D_POINT size;      // window size
   J3D_VEC2 ratio_2d;   // rendering ratio used in 2D
   // fps
   struct _fps {
	  bool firstframe_started;       // this used to signify the start of the first frame (so the calculation would be as close to perfect)
      uint32_t framecount;           // current number of frames counted (not the real fps)
      uint32_t currenttime;
      uint32_t lastupdatetime;
	  // last frame rendered, either including all stuff or only the graphics loop
	  uint32_t lastFrameTime_render;        // the time needed to render the last frame; only the graphics loop is measured (used in frame limiter)
	  uint32_t lastFrameTime_render_start;  // start of the frame in ms (used to calculate 'lastFrameTime')
	  uint32_t lastFrameTime_full;          // the time needed to render the last frame, including other all stuff like input handling etc. a full scene (precision, used in smooth animation)
	  uint32_t lastFrameTime_full_start;    // start of the frame in ms (used to calculate 'lastFrameTime_full')
      float fps;                     // the current frames-per-second
	  uint32_t fps_limit;            // the FPS to restrict the application (default =0, no restrict)
   } fps;
   // GL performance-wise information
   struct _performance {
      uint32_t trianglesDrawn;     // number of triangles drawn in specific window's scene
	  uint32_t drawCalls;          // number of 'glDrawArrays' calls; fewer calls are increasing performance
   } performance;
   // methods
   static void calculate_fps(J3D_WINDOW* window);
   static void make_current_opengl_context(J3D_WINDOW* window);
   static void scene_begin(J3D_WINDOW* w);    // called before scene render
   static void scene_end(J3D_WINDOW* w);      // called after scene render and before swapping
   static void swap_buffers(J3D_WINDOW* w);
   static void destroy(J3D_WINDOW* window);
   // constructors
   J3D_WINDOW() {
// platform-based initialization
#ifdef _WIN32
      this->icon = NULL;
#endif
      this->window = 0;
      this->context = 0;
	  // 2D ratio
	  this->name = "";
      this->ratio_2d = J3D_VEC2(1.0f, 1.0f);
	  // fps
	  this->fps.firstframe_started = false;
	  this->fps.framecount = 0;
	  this->fps.currenttime = 0;
	  this->fps.lastupdatetime = 0;
	  this->fps.lastFrameTime_full = 0;
	  this->fps.lastFrameTime_full_start = 0;
	  this->fps.lastFrameTime_render = 0;
	  this->fps.lastFrameTime_render_start = 0;
	  this->fps.fps = 0;
	  this->fps.fps_limit = 0;
	  // misc
	  this->performance.trianglesDrawn = 0;
	  this->performance.drawCalls = 0;
   }
};

struct J3D_WINDOWEVENT {
   J3D_WINDOW window;
   int32_t event;
   // constructors
   J3D_WINDOWEVENT(const J3D_WINDOW& window, int32_t event) {
	  this->window = window;
	  this->event = event;
   }
   J3D_WINDOWEVENT() { }
};

struct J3D_KEYEVENT {
   J3D_WINDOW window;
   int32_t event;
   int32_t key;
   int32_t stamp;
   // constructors
   J3D_KEYEVENT(const J3D_WINDOW& window, int32_t event, int32_t key, int32_t stamp) {
	  this->window = window;
	  this->event = event;
	  this->key = key;
	  this->stamp = stamp;
   }
   J3D_KEYEVENT() {
      this->window = J3D_WINDOW();
	  this->event = J3D_KEYEVENT_NONE;
	  this->key = J3D_KEY_NONE;
	  this->stamp = 0;
   }
};

struct J3D_MOUSEEVENT {
   J3D_WINDOW window;
   int32_t event;
   int32_t button;
   int8_t wheel_direction;
   // constructors
   J3D_MOUSEEVENT(const J3D_WINDOW& window, int32_t event, int32_t button = -1, int8_t wheel_direction = -1) {
	  this->window = window;
	  this->event = event;
	  this->button = button;
	  this->wheel_direction = wheel_direction;
   }
   J3D_MOUSEEVENT() { }
};

struct J3D_GUIEVENT;
struct J3D_GUICONTROL {
   // global
   static string gui_xmlfile;      // the XML file
   static string gui_fontfolder;   // the font folder (blank for same XML-folder)
   static bool gui_enabled;     // enable/disable globally the gui
   static string gui_texture;   // holds the texture's string; this is always "J3D_texture_gui"
   // general control variables
   string name;
   J3D_WINDOW* window;    // the real window (eg. the one with OpenGL context) the control is attached (only for containers like windows)
   uint16_t type;         // control type; one of J3D_GUI_xx defines
   bool is_container;     // TRUE for container-type controls (eg. windows), FALSE for non-container controls (eg. buttons)
   string containername;  // the container the controls belongs (etc. windows); only for non-container controls
   bool visibility;       // TRUE if the control is visible (default)
   J3D_POINT pos;         // position of control; all controls have a position, either containers or child ones
   float scale;           // the rendering scale; all controls have this, a 1.0f means render to original size (as defined in XML)
   void* data;            // custom control data
   map<string, int32_t> basefromdata;     // the data used on 'basefrom' strings on template
   map<int32_t, std::function<void(J3D_GUIEVENT e)> > events;   // event callbacks for overriding default callback 'j3d.gui_callback'
   // render; it's used to render entities defined in XML to "dress-up" the control
   struct CRENDER {
      string id;         // optional, some rendering provide that to be able to change it by custom means
      string type;       // eg. "quad"
	  bool render;       // TRUE for render normally the object; by default is TRUE
      J3D_RECT rc;       // placement of rendering type, either rect or point etc. Some types may use parts of these members
	  J3D_RECT rc_base;  // holds the base source of placement eg. where is the center. Values:  0=cx, 1=cy, 2=width, 3=height
      string basefrom[4];    // used for custom base skinning values, in the form:  'basex_from', 'basey_from', 'basew_from', 'baseh_from'
	  J3D_RECT texpixelcoords;   // (optional) for 'quad/rect' the texture pixel coordinates
      J3D_COLOR color;   // the color
	  string text_source;  // holds the source text for 'text' render type; if missing, the control's title is given, otherwise plain text
	  CRENDER() {
	     this->render = true;
	  }
   };
   map<string, vector<CRENDER> > crender;   // [rendertype] = [vector of CRENDER]
   // pointer to control's specialized object
   void* control;
   // methods
   static void handle_input();    // handle control input by type (window movement, button clicking etc.)
   static void* handle_event(J3D_GUIEVENT e);
   static void parse_render(J3D_GUICONTROL* gc, const pugi::xml_node& firstrender, const string& title);     // parse <render> tags
   static void render_by_type(const J3D_GUICONTROL& c, const string& rendertype, J3D_POINT* cp);    // render a list of entities by a type
   static void render();           // render all gui controls associated with current main window being rendered
   static void** preprocess_render(J3D_GUICONTROL* c);     // compute variables, specified by control type, to be used on rendering controls
   static void destroy(J3D_GUICONTROL* gc);
   // misc
   static void openfile_callback(J3D_GUIEVENT e);    // called to implement openfile functionality
   // constructors
   J3D_GUICONTROL(string name) {
	  this->type = J3D_GUI_NONE;
	  this->name = name;
      this->visibility = true;
	  this->scale = 1.0f;
	  this->control = NULL;
   }
   J3D_GUICONTROL() {
	  this->type = J3D_GUI_NONE;
	  this->name = "";
      this->visibility = true;
	  this->scale = 1.0f;
	  this->control = NULL;
   }
};

struct J3D_GUIEVENT {
   static int32_t current_event;      // holds the current event being handled (etc. window moving, scrollling or none)
   static string current_control;     // holds the current control handled by an event
   J3D_WINDOW window;
   int32_t event;
   J3D_GUICONTROL control;
   void** data;                       // additional data by event; event itself should convert the data by known types
   // constructors
   J3D_GUIEVENT(const J3D_WINDOW& w, int32_t e, const J3D_GUICONTROL& c, void** d = NULL) {
      this->window = w;
	  this->event = e;
	  this->control = c;
	  this->data = (d!=NULL ? d : NULL);
   }
   J3D_GUIEVENT() { }
};

struct J3D_GUICONTROL_WINDOW {
   string font;
   string title;
   int32_t zorder;   // generic z-order between other window controls
   int32_t width;    // size of window
   int32_t height;
   bool havetitlebar;
   bool permanent_focus;   // TRUE if the window wont allow the selection of another window
   struct SKIN {
      J3D_RECT dragarea;
	  J3D_POINT clientarea;
   } skin;
};

struct J3D_GUICONTROL_BUTTON {
   string font;
   string title;
   int32_t width;         // size of button; calculated either by title or plainly
   int32_t height;
   bool on_clicking;      // TRUE if the button is being clicked (not clicked yet)
   struct SKIN {
	  J3D_RECT clickarea;
   } skin;
};

struct J3D_GUICONTROL_SCROLLBAR {
   int8_t orientation;    // J3D_GUI_SCROLLBAR_HOR or J3D_GUI_SCROLLBAR_VER (horizontal or vertical)
   int32_t size;          // size of scrollbar, in pixels
   double pos;            // position of scrollbar's cube, in pixels. Limited to 'size'.
   bool on_thumbmoving;   // TRUE if the thumb has been clicked and moving (not released)
   struct SKIN {
	  int32_t baroffset;
      J3D_RECT thumbarea;
   } skin;
};

struct J3D_GUICONTROL_CHECKBOX {
   bool on_clicking;      // TRUE if the checkbox is being clicked (not clicked yet)
   bool checked;          // TRUE if the checkbox is checked
   struct SKIN {
      J3D_RECT clickarea;
   } skin;
};

struct J3D_GUICONTROL_LISTBOX {
   string entriesfont;
   int32_t width;    // size of listbox
   int32_t height;
   int32_t numentriesshown;
   int32_t selected;   // selected entry
   bool on_clicking;   // TRUE if the listbox entry is being clicked (not clicked yet)
   struct ENTRY {
	  string text;
      string templateid;
      void* data;
      ENTRY(string text, string templateid, void* data) {
		 this->text = text;
		 this->templateid = templateid;
		 this->data = data;
      }
   };
   vector<ENTRY> entries;    // [index] = [entry]
   struct SKIN {
      int32_t entriesoffset;
   } skin;
   J3D_GUICONTROL_LISTBOX() {
	  this->selected = -1;
   }
};

struct J3D_GUICONTROL_TEXT {
   string font;
   string text;
   int32_t width;         // size of text; calculated by text (internally)
   int32_t height;
};

struct J3D_GUICONTROL_IMAGE {
   int32_t width;         // size of image
   int32_t height;
   string texturename;
};

struct J3D_GUICONTROL_DROPBOX {
   string font;
   string title;
   bool title_as_selectedentry;
   int32_t width;    // size of dropbox (computed by all entries)
   int32_t height;
   int32_t on_clicking;   // 1 = the dropbox button is being clicked, 2 = the dropbox button is clicked, 3 = the entries are shown
   struct ENTRY {
	  string text;
      string templateid;
      void* data;
      ENTRY(string text, string templateid, void* data) {
		 this->text = text;
		 this->templateid = templateid;
		 this->data = data;
      }
   };
   vector<ENTRY> entries;       // [index] = [entry]
   int32_t selected_by_hover;     // the currently selected entry, by hovering
   int32_t selected_by_click;     // the currently selected entry, by clicking
   struct SKIN {
      J3D_POINT entriesoffset;
	  J3D_RECT clickarea;
   } skin;
   J3D_GUICONTROL_DROPBOX() {
	  this->title_as_selectedentry = false;
      this->on_clicking = 0;
	  this->selected_by_hover = -1;
	  this->selected_by_click = -1;
   }
};

struct J3D_GUICONTROL_EDITBOX {
   string font;
   string text;
   int32_t width;       // size of editbox
   int32_t height;
   bool on_input;       // TRUE = the editbox is clicked
   bool caret_on;          // if TRUE, caret will be shown
   int32_t caret_timer;    // it's used to blink caret symbol
   int32_t caret_pos;      // the caret position by character
   struct SKIN {
	  J3D_RECT clickarea;
   } skin;
};

struct J3D_URLGRABASYNC {
   string name;
// platform-based url grab methods
#ifdef _WIN32
   // these members are used also as a context to async callback
   HINTERNET request_;
   HINTERNET connect_;
   HINTERNET session_;
   DWORD size_;             // Size of the latest data block
   DWORD totalSize_;        // Size of the total data
   LPSTR lpBuffer_;         // Buffer for storing read data
   wstring response_;
   string* response_raw_;
   static void __stdcall async_callback(HINTERNET hInternet, DWORD_PTR dwContext, DWORD dwInternetStatus,
	                                    LPVOID lpvStatusInformation, DWORD dwStatusInformationLength);
   static void clean_up(J3D_URLGRABASYNC* context);   // clean up connection
#elif __ANDROID__
// NON-IMPLEMENTED
#elif defined(__linux__) || defined(__sun)
// NON-IMPLEMENTED
#elif __APPLE__
// NON-IMPLEMENTED
#endif
   // constructors
   J3D_URLGRABASYNC() {
// platform-based url grab methods
#ifdef _WIN32
      request_ = NULL;
      connect_ = NULL;
      session_ = NULL;
      size_ = 0;
      totalSize_ = 0;
      lpBuffer_ = NULL;
      response_raw_ = NULL;
#elif __ANDROID__
// NON-IMPLEMENTED
#elif defined(__linux__) || defined(__sun)
// NON-IMPLEMENTED
#elif __APPLE__
// NON-IMPLEMENTED
#endif
   }
};

struct J3D_TIMEREVENT {
   string name;
   bool onetime;
// platform-based timer ids (to stop them)
#ifdef _WIN32
   UINT_PTR timer;
   static void timer_callback(HWND hwnd, UINT umsg, UINT_PTR idevent, DWORD dwtime);
#elif defined(__ANDROID__) || defined(__linux__) || defined(__sun)
   timer_t timer;
   static void timer_callback(sigval val);
#elif __APPLE__
   CFRunLoopTimerRef timer;
   static void timer_callback(CFRunLoopTimerRef timer, void *info);
#endif
   // methods
   static void validate(string name);
   static void destroy(J3D_TIMEREVENT *t);
};

// the event sent to user for handling
struct J3D_ASYNCEVENT {
   int32_t event;
   string name;
   string data;    // the data passed to event
   // constructors
   J3D_ASYNCEVENT(int32_t event, string name, string data) {
	  this->event = event;
	  this->name = name;
	  this->data = data;
   }
   J3D_ASYNCEVENT() { }
};

struct J3D_FILE_ZIP {
   mz_zip_archive* zip;
   string zipfile;
   bool addfiles;
   // constructor
   J3D_FILE_ZIP() {
      this->zip = NULL;
   }
};

// animation
struct J3D_ANIMATION {   
   int32_t timer_start;
   int32_t timer_step_ms;
   int32_t frame_cur;
   int32_t frame_stop_at;
   double custom[5];        // context based
   vector<double> customv;  // context based
   bool updated;        // TRUE if there was an update to animation (to apply one-time changes real-time)
   bool completed;      // TRUE if animation has been completed (in the next run, animation will be removed)
   bool paused;         // TRUE if animation has been paused (it will show the last frame, plus will not be updated)
   // constructors
   J3D_ANIMATION() {
      this->timer_start = 0;
      this->timer_step_ms = 0;
      this->frame_cur = 0;
      this->frame_stop_at = 0;
      std::fill(&this->custom[0], &this->custom[5], -1);
      this->customv.clear();
	  this->updated = false;
	  this->completed = false;
	  this->paused = false;
   }
   // timer_step_ms = time in-between frames
   // frame_stop_at = number of frame to stop
   J3D_ANIMATION(uint32_t timer_step_ms, uint32_t frame_stop_at, double custom0 = 0, double custom1 = 0, double custom2 = 0, 
                 double custom3 = 0, double custom4 = 0, const vector<double>& customv = vector<double>()) {
      this->timer_start = 0;   // set internally
      this->timer_step_ms = timer_step_ms;
      this->frame_cur = 0;
      this->frame_stop_at = frame_stop_at;
      this->custom[0] = custom0;
      this->custom[1] = custom1;
      this->custom[2] = custom2;
      this->custom[3] = custom3;
      this->custom[4] = custom4;
      this->customv = customv;
	  this->updated = false;
      this->completed = false;
      this->paused = false;
   }
};

struct J3D {
// platform-based
#ifdef _WIN32
   HWND parent_window;
   LARGE_INTEGER qpf_timerfreq;   // frequency in counts per second (taken once by 'QueryPerformanceFrequency')
#elif __ANDROID__
   // handles the app
   struct _engine {
      struct android_app* app;
      EGLDisplay display;
	  EGLSurface surface;
	  EGLContext context;
	  int32_t touchX;
	  int32_t touchY;
	  engine() {
		 this->touchX = this->touchY = 0;
	  }
   } engine;
   int32_t parent_window;
   static void extract_file_from_apk(string filename);   // this extract the 'filename' from the APK and save it directory-wise on app's folder
#elif defined(__linux__) || defined(__sun)
   Display* x11_display;
   Cursor x11_invinsible_cursor;   // serves to hide the active cursor
   Window parent_window;
   static void timer_callback(sigval val);
#elif __APPLE__
   static void timer_callback(CFRunLoopTimerRef timer, void *info);
#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
   int32_t parent_window;
   int32_t touchX;
   int32_t touchY;
#elif TARGET_OS_MAC
   mac_window* parent_window;
#endif
#endif
   // for all platforms
   FT_Library font_library;   // font library (freetype)
   // platform-based audio device (initialized once per-application)
   bool use_openal;   // if TRUE (default), it will require .dll / .so as well
#ifdef __ANDROID__
   // OpenSL ES (cross-platform audio for embedded systems)
   SLObjectItf audio_context;
   SLEngineItf mEngine;
   SLObjectItf mOutputMixObj;
   SLVolumeItf mVolume;
#elif defined(_WIN32) || defined(__linux__) || defined(__APPLE__) || defined(__sun)
   // OpenAL (cross-platform audio for desktop)
   ALCdevice* audio_device;
   ALCcontext* audio_context;
#endif
   // SQLite database connection
   sqlite3* db;
   // misc
   uint32_t basetime;        // this will be set to current milliseconds on first 'J3D::log_write' call
   bool debug;               // TRUE for output debugging information per-function (by default FALSE)
   map<string, bool> logs;   // holds the logging state for every specified function
   string log_file;          // holds the log filename
   J3D_WINDOW* window;       // the current window being rendered
   bool glew_initialized;
   bool escape_to_quit;      // TRUE for quitting by pressing ESC (good and portable rather X button on every platform)
   bool run_mainloop;        // as long it's TRUE, the main loop will run
   bool window_rendering;    // if TRUE, the windows have started rendering
   J3D_POINT desktop;        // desktop width/height
   bool fullscreen;          // TRUE if system set to fullscreen
   // active
   string shader_active;     // the name of active shader
   string cursor_active;     // the name of active cursor
   string camera_active;     // the name of active camera
   // opengl
   bool opengl_context_created;       // this holds TRUE after the first context created (etc. through a window)
   map<string, bool> opengl_ext;      // holds an array of specific OpenGL extensions (and state) Jolt3D! uses (quick lookup)
   string opengl_extensions;          // holds a string of all OpenGL extensions
   // resources
   map<string, J3D_SHADERPROGRAM>        resource_shaderprogram;  // list of shader programs
   map<string, J3D_CAMERA>               resource_camera;         // list of cameras
   map<string, J3D_MODEL>                resource_model;          // list of models
   map<string, J3D_FONT>                 resource_font;           // list of fonts
   map<string, J3D_TERRAIN>              resource_terrain;        // list of terrains
   map<string, J3D_TEXTURE>              resource_texture;        // list of textures
   map<string, J3D_CURSOR>               resource_cursor;         // list of cursors
   map<string, J3D_AUDIO>                resource_audio;          // list of audios
   map<string, J3D_VIDEO>                resource_video;          // list of videos
   map<string, J3D_WINDOW>               resource_window;         // list of windows
   map<string, J3D_TIMEREVENT>           resource_asynctimer;     // list of async timers
   // render to texture list
   map<string, J3D_TEXTURERENDER>        rendertotexture;         // for storing render-to-texture OPs
   // async input maps
   map<int32_t, J3D_KEYEVENT>            async_key_state;
   vector<J3D_KEYEVENT>                  async_key_state_latest;  // holds the latest key / state combination(s)
   map<int32_t, uint32_t>                async_key_stamp;         // holds the stamp time (ms) for the key pressed first time
   map<int32_t, J3D_MOUSEEVENT>          async_mouse_state;
   map<int32_t, uint32_t>                async_mouse_stamp;       // holds the stamp time (ms) for the mouse button pressed first time
   map<int32_t, J3D_WINDOW>              globalkeys;              // registered global keys
   // animation
   map<string, J3D_ANIMATION>            resource_animation;      // animation
   // gui   
   map<string, J3D_GUICONTROL>           resource_guicontrol;     // list of gui controls (basic info)
   map<string, J3D_GUICONTROL_WINDOW>    resource_gui_window;     // window control
   map<string, J3D_GUICONTROL_BUTTON>    resource_gui_button;     // button control
   map<string, J3D_GUICONTROL_SCROLLBAR> resource_gui_scrollbar;  // scrollbar control
   map<string, J3D_GUICONTROL_CHECKBOX>  resource_gui_checkbox;   // checkbox control
   map<string, J3D_GUICONTROL_LISTBOX>   resource_gui_listbox;    // listbox control
   map<string, J3D_GUICONTROL_TEXT>      resource_gui_text;       // text control
   map<string, J3D_GUICONTROL_IMAGE>     resource_gui_image;      // image control
   map<string, J3D_GUICONTROL_DROPBOX>   resource_gui_dropbox;    // dropbox control
   map<string, J3D_GUICONTROL_EDITBOX>   resource_gui_editbox;    // editbox control
   // shader attributes and internal shader functionality
   struct _glsl {
	  map<string, uint8_t> num_components;   // the size (1,2,3 or 4) of each of the attributes above, as:  [attr] = [num components]
	  map<string, uint8_t> attr_to_vbo;      // the vbo index from attribute name, as:  [attr] = [vbo index]
      static map<string, std::function<void()> > on_transform;    // shader code that executes on 'J3D_transform', as:  [shader] = [function]
	  // SHADERS
	  // shader: 3d
	  struct _shader_3d {
	     // methods
         static void create();                   // create shader program
         static void destroy();                  // release resources
	  } shader_3d;
	  // shader: 2d
	  struct _shader_2d {
         unsigned int vbo[3];                    // 3 buffers; position, color and texcoords buffers for 2D shader
	     // methods
         static void create();            // create shader and required buffers
         static void destroy();           // destroy shader and buffers
	  } shader_2d;
	  // shader: liquid
	  struct _shader_liquid {
	     // methods
         static void create();                   // create shader program
         static void destroy();                  // release resources
	  } liquid;
	  // shader: dynamic resolution
	  struct _shader_dr {
         unsigned int vbo[2];                   // position, texcoords buffers for dynamic resolution shader
	     unsigned int quad_texture;             // the entire scene will be rendered onto this texture
	     unsigned int frame_buffer;
	     unsigned int depth_buffer;
         int default_frame_buffer;
         J3D_POINT resolution;
		 uint32_t scaled_desktop_x;       // scaled version of j3d.desktop.x, to be used on texture creation and elsewhere
		 uint32_t scaled_desktop_y;
		 bool fullscreen_filtering;       // used to apply bi-linear texture filtering to screen texture
	     // methods
         static void create();            // create shader and required buffers
         static void destroy();           // destroy shader and buffers
         static void scene_begin();       // set the scene target to texture
         static void scene_end();         // restore the render target and render the scene texture to backbuffer
      } shader_dr;
   } glsl;
   // callbacks
   void (*window_callback)(J3D_WINDOWEVENT e);
   void (*key_callback)(J3D_KEYEVENT e);
   void (*mouse_callback)(J3D_MOUSEEVENT e);
   void (*gui_callback)(J3D_GUIEVENT e);
   void (*async_callback)(J3D_ASYNCEVENT e);
   // methods
   static void log_opengl_error();
   static void log_write(string function, string error);
   static void input_unregister_hotkeys(int32_t key, J3D_WINDOW w);
   static void reset_async_input_states();
   static int32_t translate_key_to_char(int32_t key);
   static double fast_atof(const char* p);
   static int32_t fast_atoi(const char* p);
   uint32_t g_seed;
   static void fast_srand(uint32_t seed);
   static int fast_rand();
   static bool compare_string_array(string a, string b);
   static void deinit();
   // constructors
   J3D() {
	  this->glew_initialized = false;
	  this->window = NULL;
	  this->run_mainloop = true;
	  this->window_rendering = false;
	  this->fullscreen = false;
	  this->basetime = 0;
      this->debug = false;
	  this->log_file = "";
	  this->escape_to_quit = true;
	  this->db = NULL;
	  this->opengl_context_created = false;
	  // misc
	  this->shader_active = "";
	  this->cursor_active = "";
	  this->camera_active = "";
	  // GLSL attribute lookups
	  this->glsl.num_components[ J3D_ATTR_VERTEXPOSITION ] = 3;
	  this->glsl.num_components[ J3D_ATTR_VERTEXCOLOR ]    = 4;
	  this->glsl.num_components[ J3D_ATTR_TEXTURECOORD ]   = 2;
	  this->glsl.num_components[ J3D_ATTR_VERTEXNORMAL ]   = 3;
	  // attr name to vbo index
	  this->glsl.attr_to_vbo[ J3D_ATTR_VERTEXPOSITION ]    = 0;
	  this->glsl.attr_to_vbo[ J3D_ATTR_VERTEXCOLOR ]       = 1;
	  this->glsl.attr_to_vbo[ J3D_ATTR_TEXTURECOORD ]      = 2;
	  this->glsl.attr_to_vbo[ J3D_ATTR_VERTEXNORMAL ]      = 3;
// platform-based initiaze
#ifdef _WIN32
      this->parent_window = 0;
	  this->qpf_timerfreq.QuadPart = 0;
#elif __ANDROID__
      this->parent_window = 0;
#elif defined(__linux__) || defined(__sun)
      this->parent_window = 0;
#elif __APPLE__
#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
	  this->touchX = 0;
      this->touchY = 0;
#elif TARGET_OS_MAC
#endif
      this->parent_window = 0;
#endif
// platform-based audio device initialization
#ifdef __ANDROID__
      // OpenSL ES
      this->audio_context = NULL;
	  this->mEngine = NULL;
      this->mOutputMixObj = NULL;
#elif defined(_WIN32) || defined(__linux__) || defined(__sun) || defined(__APPLE__)
      // OpenAL
      this->audio_device = NULL;
      this->audio_context = NULL;
#endif
   }
};

// DECLARATIONS /////////////////////////////////////////////////

// callbacks ///////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Callbacks",
"params":["The key event object"],
"desc":"This function is called when a <i>key event</i> is triggered via user action.<br/>When an event is triggered:<br/><ul><li><b>e.event</b> will be set to the triggered event, see [Key events]</li><li><b>e.window.name</b> will be set to the window name (specified in [J3D_window_create])</li><li><b>e.key</b> will be set to the key that triggered the event, see [Key mapping]<br/><b>NOTE:</b> The Windows mapping is used on the guide for simplicity. Every platform has it's own implementation.</li></ul>",
"return":"Nothing"}*/
void J3D_callback_key(J3D_KEYEVENT e);

/*jdoc
{"params":["The mouse event object"],
"desc":"This function is called when a <i>mouse event</i> is triggered via user action.<br/>When an event is triggered:<br/><ul><li><b>e.event</b> will be set to the triggered event, see [Mouse events]</li><li><b>e.window.name</b> will be set to the window name (specified in [J3D_window_create])</li><li><b>e.button</b> will be set to the button that triggered the event<br/><i>(if the event can be triggered by buttons)</i>, see [Mouse button mapping]<br/><b>NOTE:</b> The Windows mapping is used on the guide for simplicity. Every platform has it's own implementation.</li><li><b>e.wheel_direction</b> will be set to the wheel direction that triggered the event, see [Mouse wheel mapping]</li></ul>",
"return":"Nothing"}*/
void J3D_callback_mouse(J3D_MOUSEEVENT e);

/*jdoc
{"params":["The window event object"],
"desc":"This function is called by the system when a window event is triggered.<br/>This includes:<ul><li>Window initialization event, triggered by [J3D_window_create].<br/>In this case <b>e.event</b> will be set to <b>J3D_WINDOW_INIT</b> and <b>e.window.name</b> will be set to the window name specified in [J3D_window_create].<br/><b>NOTE:</b> This is where developers should load their resources for the specified window.</li><li>Window de-initialization event, triggered by [J3D_window_create].<br/>In this case <b>e.event</b> will be set to <b>J3D_WINDOW_DEINIT</b> and <b>e.name</b> will be set to the name specified in [J3D_window_create].<br/><b>NOTE:</b> This is only for developer custom data, as <i>Jolt3D!</i> releases itself automatically.</li><li>Window rendering loop event, triggered by [J3D_window_create].<br/>In this case <b>e.event</b> will be set to <b>J3D_WINDOW_LOOP</b> and <b>e.name</b> will be set to the name specified in [J3D_window_create].<br/><b>NOTE:</b> This is where developers should render their content, sorted by window.</li></ul>",
"return":"Nothing"}*/
void J3D_callback_window(J3D_WINDOWEVENT e);

/*jdoc
{"params":["The gui event object"],
"desc":"This function is called when a <i>gui event</i> is triggered via user action, see [Gui events] for a quick reference.<br/>When an event is triggered:<br/><ul><li><b>e.event</b> will be set to the triggered event.</li><li><b>e.window.name</b> will be set to the window name (specified in [J3D_window_create]) the control is using as parent.</li><li><b>e.control.name</b> will be set to the control that triggered the event.</li></ul>",
"return":"Nothing"}*/
void J3D_callback_gui(J3D_GUIEVENT e);

/*jdoc
{"params":["The async event object"],
"desc":"This function is called by the system when an asynchronous event is triggered.<br/>This includes:<ul><li>Aynchronous URL grab event, triggered by [J3D_url_grab_async].<br/>In this case <b>e.event</b> will be set to <b>J3D_ASYNC_URLGRAB_COMPLETE</b>, <b>e.name</b> will be set to the name specified in [J3D_url_grab_async] and the data will be set in <b>e.data</b>.</li><li>Asynchronous time event, triggered by [J3D_time_event_start].<br/>In this case <b>e.event</b> will be set to <b>J3D_ASYNC_TIMEREVENT_COMPLETE</b> and <b>e.name</b> will be set to the name specified in [J3D_time_event_start].</li></ul>",
"return":"Nothing"}*/
void J3D_callback_async(J3D_ASYNCEVENT e);

// core ///////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Core",
"desc":"This function is the entry point of your application.<br/>It's the <i>Jolt3D!</i> equivalent to <b>int main();</b> you find in all C programs.<br/>All supported platforms are eventually call this function<br/>to pass the control to developers.",
"return":"Nothing"}*/
void J3D_main();

/*jdoc
{"params":["Set <i>TRUE</i> (default) if you want to exit quickly from application<br/>by hitting the <b>Escape</b> key (where it supported).<br/>This is intended for quick, example applications, without the need<br/>of setting first a quit mechanism. For released applications,<br/>developers should pass <i>FALSE</i> here and develop a better exit mechanism.","The callback used to handle window events, see [Window events].","The callback used to handle key events, see [Key events].","The callback used to handle mouse events, see [Mouse events].","The callback used to handle gui events, see [Gui events].","The callback used to handle asynchronous events, see [Asynchronous events]."],
"desc":"This function initializes <i>Jolt3D!</i> and should be the first function to call in [J3D_main] function.",
"return":"Nothing"}*/
void J3D_init(bool escape_to_quit = true, void (*window_callback)(J3D_WINDOWEVENT e) = J3D_callback_window, void (*key_callback)(J3D_KEYEVENT e) = J3D_callback_key, void (*mouse_callback)(J3D_MOUSEEVENT e) = J3D_callback_mouse, void (*gui_callback)(J3D_GUIEVENT e) = J3D_callback_gui, void (*async_callback)(J3D_ASYNCEVENT e) = J3D_callback_async);

/*jdoc
{"desc":"This function pass the control to <i>Jolt3D!</i> to handle all rendering and events.<br/>It must be called inside [J3D_main] and after [J3D_init].",
"return":"Nothing"}*/
void J3D_loop();

/*jdoc
{"params":["The color to fill the screen."],
"desc":"This function clears the <i>screen</i> with a color, resetting as well the depth buffer in 3D applications.<br><b>NOTE: </b>Intended to be used inside <b>J3D_WINDOW_LOOP</b> event of [J3D_callback_window] function.",
"return":"Nothing"}*/
void J3D_clear(J3D_COLOR color);

/*jdoc
{"desc":"This function exits the application at the end of the current frame drawn.<br/><b>NOTE:</b> There are devices like <i>iPhone</i> where the rules forbid to quit <b>programmatically</b>, therefore in such devices this function is ignored and user should quit the intended way.",
"return":"Nothing"}*/
void J3D_quit();

/*jdoc
{"params":["The debugging state."],
"desc":"This function enables the debugging of any function that is called afterwards.<br/>The debug information are saved in the <b>log</b> file, line-by-line.<br/>Note that <i>debug information</i> are not errors, merely information logged by the function.<br/><br/><b>NOTE:</b> Each function is responsible for the debug information it provides,<br/>some functions just does not debug anything <i>(work in progress)</i>.<br/>Expect longer times of engine's initialization when this is set to <b>TRUE</b>.",
"return":"Nothing"}*/
void J3D_log_debug(bool enable);

/*jdoc
{"params":["The function name.","The logging state."],
"desc":"This function enables or disables the error logging for the specified function.<br/>The log information are saved in the <b>log</b> file, line-by-line.<br/><b>NOTE:</b> By default, all functions have error logging <i>enabled</i>.",
"return":"Nothing"}*/
void J3D_log_function(string function, bool enable);

/*jdoc
{"desc":"This function gets the filename for the logging.<br/>It can be changed with [J3D_log_set].<br/><b>NOTE:</b> By default, the log filename is set to <b>log.txt</b>.",
"return":"The currently used log file."}*/
string J3D_log_get();

/*jdoc
{"params":["The filename."],
"desc":"This function sets the filename for the logging.<br/>In addition, it deletes both the default log file and the file provided to prevent leftovers.<br/><b>NOTE:</b> By default, the log filename is set to <b>log.txt</b>.",
"return":"Nothing"}*/
void J3D_log_set(string file);

/*jdoc
{"params":["The text."],
"desc":"This function writes text to the logging file.<br/><b>NOTE:</b> By default, the log filename is set to <b>log.txt</b>.",
"return":"Nothing"}*/
void J3D_log_write(string text);

/*jdoc
{"desc":"This function retrieves the Jolt3D! object.<br/>This object contains everything the engine is using.",
"return":"The Jolt3D! object."}*/
J3D* J3D_get();

/*jdoc
{"desc":"This function retrieves information about the current operating system.",
"return":"The OS information."}*/
J3D_OS J3D_get_os();

/*jdoc
{"desc":"This function retrieves the current <i>OpenGL</i> version.<br/><b>NOTE: </b>The version returned is strictly tied to current OpenGL <i>context</i><br/>in use and the combination of settings that were used to create it.",
"return":"The current <i>OpenGL</i> version, as a <i>J3D_POINT</i>."}*/
J3D_POINT J3D_get_opengl_version();

/*jdoc
{"desc":"This function retrieves all supported OpenGL extensions.",
"return":"The supported OpenGL extensions, as a <i>string</i>."}*/
string J3D_get_opengl_extensions();

/*jdoc
{"params":["The command to run in shell."],
"desc":"This function executes a shell command and retrieves the output in a string.",
"return":"The output result, as <i>string</i>."}*/
string J3D_shell_exec(string command);

/*jdoc
{"params":["The integer to be used as seed."],
"desc":"This function sets an integer to be used as seed<br/>for all functions that generate random results.",
"return":"Nothing."}*/
void J3D_random_seed(uint32_t seed);

// display ////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Display",
"params":["The screen width. By default is set to use the original <i>desktop width</i>.<br/><b>NOTE: </b>Bigger than desktop resolutions can also be provided.","The screen height. By default is set to use the original <i>desktop height</i>","(optional) If set to <i>TRUE</i>, the screen will be bi-Linear filtered, which is used to smoouth out the pixelation effect. Useful on low display resolutions (i.e. <i>800x600</i>) where the pixelation effect may be noticeable.<br/><b>NOTE: </b>Texture filtering causes the display to be darker than usual sometimes. It's advised to use [J3D_display_set_brightness] when this happens with a value of at least <b>1.1</b>"],
"desc":"This function sets the specified resolution, effectively turning the application fullscreen. <i>Jolt3D!</i> does not change the desktop resolution dynamically, instead it <i>downscales</i> the original desktop resolution down to specified resolution on <i>3D level (texture)</i>. Because of this any kind of resolution is supported, even bigger to current desktop resolution.<br/><br/><b>NOTE: </b>This function can only be called before the first [J3D_window_create] call. That is because the window creation or rendering loop itself uses the resolution provided through this function to set the viewport and <i>on-the-fly</i> changing will mess the output or crash the application.",
"return":"Nothing"}*/
void J3D_display_set_resolution(uint32_t width, uint32_t height, bool fullscreen_filtering = false);

/*jdoc
{"desc":"This function retrieves the internal application resolution, filtered by scaling.<br/>Resolution scaling is performed by previous call to [J3D_display_set_resolution] function.",
"return":"The display resolution, as <i>J3D_POINT</i>."}*/
J3D_POINT J3D_display_get_resolution();

/*jdoc
{"desc":"This function retrieves the system's desktop resolution.",
"return":"The desktop resolution, as <i>J3D_POINT</i>."}*/
J3D_POINT J3D_display_get_desktop_resolution();

/*jdoc
{"params":["The brightness factor. By default is <b>1.0</b>."],
"desc":"This function sets the display brightness.<br/>Useful to lightening or darkening the display output.<br/><br/><b>NOTE: </b>This function must be called after a window creation i.e.<br/>the <b>J3D_WINDOW_INIT</b> of [J3D_callback_window] is the preferred place.",
"return":"Nothing"}*/
void J3D_display_set_brightness(float brightness = 1.0f);

/*jdoc
{"desc":"This function retrieves the display brightness.",
"return":"The display brighness, as <i>float</i>."}*/
float J3D_display_get_brightness();

/*jdoc
{"params":["The vsync state."],
"desc":"This function sets the <i>vertical synchronization</i> (ie. vsync) for the application. When vsync is <i>enabled</i>, it limits the framerate to match the refresh rate of your device. Otherwise, when it's <i>disabled</i>, there no control and the application runs as fast as it can, often producing a phenomenon called <b>Tearing</b>. A <i>disabled vsync</i> always gives the best performance.<br><b>NOTE: </b>VSync control is not always supported, especially on mobile devices, due to drivers. If vsync is not supported by hardware & <i>vsync</i> is required, the system calls [J3D_display_fps_set_limit] to emulate vsync <i>in software</i>.<br/><b>NOTE: </b>A created window is required before calling this function, so call this after a [J3D_window_create] call.",
"return":"Nothing"}*/
void J3D_display_vsync(bool vsync);

/*jdoc
{"desc":"This function retrieves the current <i>frames per second</i>,<br/>as a measure of how fast an application is rendering.",
"return":"The frames per second, as <i>float</i>."}*/
float J3D_display_fps_get();

/*jdoc
{"desc":"This function retrieves the time spent for the last frame to get rendered.",
"return":"The time, in <i>seconds</i>."}*/
float J3D_display_fps_get_last_frame_time();

/*jdoc
{"params":["The frames per second."],
"desc":"This function defines a <i>frames per second</i> limitation.<br/>This is useful in cases where <i>V-Sync</i> is disabled (not really useful for enabled V-Sync) or where maximum 3D performance is not really required, to save battery or energy in general.<br/><b>NOTE: </b>A created window is required before calling this function, so call this after a [J3D_window_create] call.",
"return":"Nothing"}*/
void J3D_display_fps_set_limit(uint32_t fps);

/*jdoc
{"desc":"This function locks the front buffer for direct rendering into it.<br/>After the call, regular <i>Jolt3D!</i> drawing functions can be used.<br/><b>NOTE: </b>You need to call this function outside of windows's<br/><b>J3D_WINDOW_LOOP</b> to prevent undefined behaviour.",
"return":"Nothing."}*/
void J3D_display_frontbuffer_render_begin();

/*jdoc
{"desc":"This function renders directly the <i>Jolt3D!</i> content that preceded<br/> up to this call and unlocks the front buffer.<br/>This will give the illusion of <i>drawing directly</i> to the screen.",
"return":"Nothing."}*/
void J3D_display_frontbuffer_render_end();

/*jdoc
{"desc":"This function returns the current number of <b>OpenGL</b> drawing calls, for the current window.<br/><b>NOTE: </b>This can be used to spot bottlenecks between Jolt3D!, OpenGL driver and application itself.",
"return":"The number of internal <b>OpenGL</b> drawing calls, such as <a href='https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glDrawArrays.xhtml'>glDrawArrays</a>"}*/
uint32_t J3D_display_performance_num_draw_calls();

/*jdoc
{"desc":"This function returns the current number of drawn triangles, for the current window.<br/>Every element in Jolt3D! consists of triangles, even 2D, text drawing and GUI.<br/><b>NOTE: </b>This can be used to spot bottlenecks between Jolt3D!, OpenGL driver and application itself.",
"return":"The number of drawn triangles."}*/
uint32_t J3D_display_performance_num_triangles_drawn();;

/*jdoc
{"desc":"This function returns the Jolt3D! performance as a rough percentage. This function follows the common theory that says an <b>OpenGL</b> drawing call should consist of at least 100 triangles. If there are many calls of less than <b>100 triangles</b>, the performance percentage decreases.",
"return":"The performance percentage."}*/
uint8_t J3D_display_performance_percentage();

// window /////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Window",
"params":["The window name.","The parent window name. There should be only one <i>parent</i> window per application. For parent window, you must set a <i>blank</i> string here, while additional windows should have the <i>name</i> of the parent window in this parameter.<br/>The main difference between the parent and normal windows is that a closed parent window <i>will terminate</i> the application as well.","The screen position of window, in X-axis. This is only used on <i>windowed</i> applications.","The screen position of window, in Y-axis. This is only used on <i>windowed</i> applications.","The width of window. This is only used on <i>windowed</i> applications.","The height of window. This is only used on <i>windowed</i> applications.","The title of window. This is showing on title bar on <i>windowed</i> applications.","A borderless window doesn't have a title bar, in addition they can't move or resize. <i>Windowed</i> applications can be borderless as well (although you must be careful to provide a quit mechanism). <i>Fullscreen</i> applications are essentially borderless.","Icon images are only showing on <i>windowed</i> applications, specifically on title bars and/or when minimized. Supported formats (see [J3D_texture_load])."],
"desc":"This function creates a window. Windows are the first objects to create and they're used as <i>graphics contexts</i> for your application. They're also one of the few functions that can be called directly inside [J3D_main], at least the <b>parent</b> window.<br/>This function triggers a number of events via [J3D_callback_window] function, which it's intended for developers to build their application.",
"return":"Nothing"}*/
void J3D_window_create(string name, string parent, int32_t xpos, int32_t ypos, uint32_t width, uint32_t height, string title, bool borderless = false, string iconfile = "");

/*jdoc
{"params":["The window name. You can also give the title name of<br/>an external window (not created by <i>Jolt3D!</i>).<br/><b>NOTE: </b>If left blank, the currently rendered window will be returned.","The window object"],
"desc":"This function returns the object of a created window.",
"return":"Returns <i>TRUE</i> if the window is found, otherwise <i>FALSE</i>."}*/
bool J3D_window_get(string name, J3D_WINDOW& window);

/*jdoc
{"desc":"This function returns the viewport size of a created window.<br/><b>NOTE: </b>If the viewport has not been changed manually, this simply returns the window size; For <i>fullscreen</i> applications, the system desktop resolution is returned, since application's window covers the entire desktop.<br/>For actual application resolution, one should call [J3D_display_get_resolution].",
"return":"Returns the width/height of viewport, as <i>J3D_POINT</i>."}*/
J3D_POINT J3D_window_get_viewport();

/*jdoc
{"params":["The window name.<br/><b>NOTE: </b>External window names can also be provided (not created by <i>Jolt3D</i>).","(optional) The window handle.<br/><b>NOTE: </b> It's only considered if <i>name</i> is empty."],
"desc":"This function returns the client rectangle of a created window.<br/>A <i>Client</i> rectangle is the <b>body</b> of the window, excluding borders,<br/>title bar and any styles applied to the window.<br/><b>NOTE:</b> The coordinates retrieved are always <i>absolute</i>.",
"return":"Returns the client rectangle of window, as <i>J3D_RECT</i>."}*/
J3D_RECT J3D_window_get_client_rect(string name, J3D_WINDOW* w = NULL);

/*jdoc
{"params":["The window object"],
"desc":"This function returns the currently active window. It also supports windows not created by <i>Jolt3D!</i>",
"return":"Nothing"}*/
void J3D_window_get_active(J3D_WINDOW& window);

/*jdoc
{"params":["(optional) The title fragment to limit the number of enumerated windows.<br/>If left blank, all windows will be retrieved."],
"desc":"This function enumerates all system windows (also non <i>Jolt3D!</i> ones) and stores them into a vector. Enumeration can be filtered to meet only a specific <i>title fragment</i> of window's title.",
"return":"The enumerated windows, as a <i>vector</i>."}*/
vector<J3D_ENUMWINDOW> J3D_window_enum_windows(string by_titlefragment = "");

// opengl /////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"OpenGL",
"params":["Specifies the symbolic constant of an OpenGL capability."],
"desc":"This function calls directly the <a href='https://www.khronos.org/registry/OpenGL-Refpages/es2.0/xhtml/glEnable.xml'>glEnable</a> function of the OpenGL API.<br/><b>NOTE: </b>Jolt3D! doesn't provide OpenGL constant values, check online <a href='https://www.khronos.org/registry/OpenGL/api/GL/glcorearb.h'>here</a>.",
"return":"Nothing"}*/
void J3D_opengl_enable(int32_t cap);

/*jdoc
{"params":["Specifies the symbolic constant of an OpenGL capability."],
"desc":"This function calls directly the <a href='https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glEnable.xml'>glDisable</a> function of the OpenGL API.<br/><b>NOTE: </b>Jolt3D! doesn't provide OpenGL constant values, check online <a href='https://www.khronos.org/registry/OpenGL/api/GL/glcorearb.h'>here</a>.",
"return":"Nothing"}*/
void J3D_opengl_disable(int32_t cap);

/*jdoc
{"params":["Specifies whether the depth buffer is enabled for writing.<br/><b>NOTE: </b>By default, depth writing is <i>enabled</i>."],
"desc":"This function calls directly the <a href='https://www.khronos.org/registry/OpenGL-Refpages/es2.0/xhtml/glDepthMask.xml'>glDepthMask</a> function of the OpenGL API.",
"return":"Nothing"}*/
void J3D_opengl_depth_mask(bool flag);

// cursor /////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Cursor",
"params":["The cursor name.","The cursor filename.<br/><b>NOTE: </b>If left blank, <i>fromdata</i> will be used.","(optional) The cursor data, as a string.","The cursor size. By default <i>(=0)</i> this taken from the image/cursor dimensions itself or a custom size can be provided.<br/><b>NOTE: </b>Custom cursor sizing relies to the OS itself; bogus sizes may reset to default ones."],
"desc":"This function loads a cursor or image file to be used as cursor.<br/>Supported formats can be found on [Image formats].<br/><b>NOTE: </b>only <i>cur, ico and xcur</i> are natively cursor files and have hotspot cursor information.",
"return":"Nothing"}*/
void J3D_cursor_load(string name, string fromfile = "", string fromdata = "", uint16_t size = 0);

/*jdoc
{"params":["The cursor name."],
"desc":"This function sets a loaded cursor as the current cursor.",
"return":"Nothing"}*/
void J3D_cursor_set(string name);

/*jdoc
{"params":["The cursor name"],
"desc":"This function returns the object of a created cursor.",
"return":"The cursor object or NULL if there's no cursor with the given <i>name<i>"}*/
J3D_CURSOR* J3D_cursor_get(string name);

/*jdoc
{"params":["Show/hide the current cursor."],
"desc":"This function shows or hides the current cursor.",
"return":"Nothing"}*/
void J3D_cursor_show(bool show);

/*jdoc
{"params":["If <b>FALSE</b> (default), then mouse position is relative to application window.<br/>Otherwise, it's relative to desktop window (absolute position)."],
"desc":"This function retrieves the current cursor position.",
"return":"The cursor position, as <i>J3D_POINT</i>."}*/
J3D_POINT J3D_cursor_get_pos(bool absolute = false);

/*jdoc
{"params":["The cursor position, in X-axis","The cursor position, in Y-axis","If <b>FALSE</b> (default), then mouse position is relative to application window.<br/>Otherwise, it's relative to desktop window (absolute position)."],
"desc":"This function sets the current cursor position.",
"return":"Nothing"}*/
void J3D_cursor_set_pos(int32_t x, int32_t y, bool absolute = false);

/*jdoc
{"params":["The cursor name"],
"desc":"This function releases a loaded cursor from the memory.<br/><b>NOTE:</b> This is optional since <i>Jolt3D!</i> releases all objects automatically.",
"return":"Nothing"}*/
void J3D_cursor_release(string name);

// database ///////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Database",
"params":["The database filename.<br/><b>NOTE: </b>If the database does not exist, it will be created."],
"desc":"This function opens a connection to an <i>SQLite</i> database file.",
"return":"Nothing"}*/
void J3D_db_open(string filename);

/*jdoc
{"desc":"This function checks if the database is opened.",
"return":"<i>TRUE</i> if the database is already opened."}*/
bool J3D_db_is_open();

/*jdoc
{"params":["The SQL query to the database.","The object the holds the query's results.","(optional) The bound variables as a <i>vector</i>, if provided.<br/><b/>NOTE: </b>The symbol <b>?</b> should be placed in the place of variables in query."],
"desc":"This function performs a query to an opened <i>SQLite</i> database file.",
"return":"Nothing"}*/
void J3D_db_query(string query, J3D_DB_QUERYRESULT* result = NULL, const vector<J3D_DB_BINDING>& bindings = vector<J3D_DB_BINDING>());

/*jdoc
{"desc":"This function begins a transaction to an opened <i>SQLite</i> database file.<br/>A <b>Transaction</b> gathers all sequential and <i>modifying</i> queries into one,<br/>increasing consistency and decreasing execution time.<br/>A call to [J3D_db_transaction_end] is required for the actual execution.",
"return":"Nothing"}*/
void J3D_db_transaction_begin();

/*jdoc
{"desc":"This function ends a transaction to an opened <i>SQLite</i> database file.<br/>This is where the queries that followed [J3D_db_transaction_begin] gets executed.",
"return":"Nothing"}*/
void J3D_db_transaction_end();

/*jdoc
{"desc":"This function closes the connection to an opened <i>SQLite</i> database file.",
"return":"Nothing"}*/
void J3D_db_close();

// url ///////////////////////////////////////////////////////////////////////////////////////

// convert an integer from network byte order to host (local) byte order, regardless of endianess

/*jdoc
{"group":"URL",
"params":["The integer to convert."],
"desc":"This function converts the provided integer from <i>network byte order</i><br/>to host (local) byte order, regardless the endianess of the local system.",
"return":"The converted integer."}*/
uint32_t J3D_url_ntohl(uint32_t num);

/*jdoc
{"params":["The string to encode."],
"desc":"This function converts the provided string into a url-compatible string.<br/><b>NOTE: </b>Full URLs are not a good candicate for conversion<br/>since they contain characters that must remain unchanged (/ or :).<br/>",
"return":"The converted string."}*/
string J3D_url_encode_string(string str);

/*jdoc
{"params":["The original string."],
"desc":"This function encodes a string, using the Base64 algorithm.<br/><b>NOTE: </b>The resulted string still needs to <i>url-encoded</i> before passed into URL.<br/>",
"return":"The base64-encoded string."}*/
string J3D_url_encode_base64(const string& original_string);

/*jdoc
{"params":["The base64-encoded string."],
"desc":"This function decodes a <i>base64-encoded</i> string, back into the original string.",
"return":"The original string."}*/
string J3D_url_decode_base64(const string& encoded_string);

/*jdoc
{"params":["The URL to send the request.<br/>If <i>protocol</i> is missing, system assumes it's <i>http://</i>.<br/><i>url</i> can be either a host, a file or a query.","The maximum time period (in seconds) before the operation is cancelled.<br/><b>NOTE: </b>By default is <i>15 seconds</i>.","If provided, it specifies the url from which the <i>url</i> obtained from.","If not empty, the request will be sent Asynchronously (not immediate return).<br/>In this case, the name passed here will be triggered through<br/><b>J3D_ASYNC_URLGRAB_COMPLETE</b> on [J3D_callback_async] callback.","If Sync mode is used i.e. <i>async_name</i> is empty,<br/>then this will contain the returned HTML data as string."],
"desc":"This function makes a request to a URL and either:<ul><li>fetch the HTML contents directly if <i>async_name</i> is blank (Sync mode).</li><li>direct the fetching to the [J3D_callback_async] if <i>async_name</i> is provided (Async mode).</li></ul>",
"return":"<i>TRUE</i> if operation was successful."}*/
bool J3D_url_grab(string url, uint32_t timeout = 15, string referrer = "", string async_name = "", string* sync_data = NULL);

// shader //////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Shader",
"params":["The shader name","The vertex shader, as string","The fragment shader, as string"],
"desc":"This function loads a shader by text data.",
"return":"Nothing"}*/
void J3D_shader_load_by_text(string name, string shaderVS, string shaderFS);

/*jdoc
{"params":["The shader name"],
"desc":"This function sets a loaded shader to be used on next rendering operations.<br/>The system provides the following basic shaders:<ul><li><b>\"J3D_shader_3d\"</b><br/>The basic shader for 3D rendering.<br/>This shader is automatically used on <i>J3D_model_xxx();</i> functions.</li><li><b>\"J3D_shader_2d\"</b><br/>The basic shader for 2D rendering.<br/>This shader is automatically used on <i>J3D_2d_xxx();</i> functions.</li><li><b>\"J3D_shader_liquid\"</b><br/>A special shader for 3D liquid rendering.<br/>This shader is specifically used on <i>J3D_model_create_liquid();</i> function.</li><li><b>\"J3D_shader_dr\"</b><br/>A special shader used for rendering to a texture for the entire application.<br/>This shader is used internally and is not meant for general usage.</li></ul>",
"return":"Nothing"}*/
void J3D_shader_set(string name);

/*jdoc
{"params":["(optional) The shader name.<br/><b>NOTE: </b>If left blank, the active shader is retrieved."],
"desc":"This function returns the object of either the currently active shader<br/>(there's always an <i>active</i> one) or a specific shader by name.",
"return":"The shader object."}*/
J3D_SHADERPROGRAM* J3D_shader_get(string name = "");

/*jdoc
{"desc":"This function returns the name of the currently active shader (there's always an active one).",
"return":"The shader name."}*/
string J3D_shader_get_active();

/*jdoc
{"params":["The shader attribute name.<br/>Must been defined in <i>vertex shader</i>.","(optional) The shader to use."],
"desc":"This function adds an attribute to the currently active shader. Attributes are used for <i>communication</i> between your app and vertex shader, where your app fills with data an attribute and vertex shader use the attribute to process all vertices, one-by-one.<br/>The attribute must be added through this function to let system know it's <i>location</i> inside vertex shader.",
"return":"Nothing"}*/
void J3D_shader_add_attribute(string attr_name, string shader_name = "");

/*jdoc
{"params":["The shader attribute name.<br/>Must been defined in <i>vertex shader</i>.","(optional) The shader to use."],
"desc":"This function gets the <i>location</i> of an attribute from the currently active shader.",
"return":"The attribute <i>location</i> inside vertex shader or -1 if attribute does not exist."}*/
int J3D_shader_get_attribute(string attr_name, string shader_name = "");

/*jdoc
{"params":["The shader uniform name.<br/>Must been defined in either <i>vertex shader or fragment shader</i>, based on which one they're used.<br/><b>NOTE: </b>If <i>uniform_name</i> is an array, it's mandatory to specify the elements as well.<br>This is possible by using square brackets <b>&#91;]</b> to specify the element.<br/>For example:<div class='code'>J3D_shader_add_uniform(<b>\"array&#91;0]\"</b>);<br/>J3D_shader_add_uniform(<b>\"array&#91;1]\"</b>);<br/>J3D_shader_add_uniform(<b>\"array&#91;2]\"</b>);</div>will add the uniform locations for the elements <b>0,1</b> and <b>2</b> of the array.","(optional) The shader to use."],
"desc":"This function adds a uniform to the currently active shader. Uniforms are the <i>variables</i> of shaders and can be passed directly from app to shader. They're typically used as <i>flags or variables</i> used to change the typical behaviour of a shader program, as variables are used to do the same for regular programs.<br/>The uniform must be added through this function to let system know it's <i>location</i> inside vertex or fragment shader.",
"return":"Nothing"}*/
void J3D_shader_add_uniform(string uniform_name, string shader_name = "");

/*jdoc
{"params":["The shader uniform name.<br/>Must been defined in either <i>vertex shader or fragment shader</i>, based on which one they're used.<br/><b>NOTE: </b>If <i>uniform_name</i> is an array and a specific element is required,<br>then the square brackets <b>&#91;]</b> can be used to specify the element.<br/>For example:<div class='code'>J3D_shader_get_uniform(<b>\"array&#91;2]\"</b>);</div>will retrieve the uniform location for the element <b>&#91;2]</b> of the array.","(optional) The shader to use."],
"desc":"This function gets the <i>location</i> of a uniform from the currently active shader.",
"return":"The uniform <i>location</i> inside vertex or fragment shader or -1 if uniform does not exist."}*/
int J3D_shader_get_uniform(string uniform_name, string shader_name = "");

/*jdoc
{"params":["(optional) The shader name.<br/><b>NOTE: </b>If left blank, the active shader is retrieved."],
"desc":"This function releases a loaded shader from the memory.<br/><b>NOTE:</b> This is optional since <i>Jolt3D!</i> releases all objects automatically.",
"return":"Nothing"}*/
void J3D_shader_release(string name = "");

// shader core ////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Shader core",
"desc":"This function disables lighting (default).<br/><b>NOTE: </b>This is only used on default 3D shader.",
"return":"Nothing"}*/
void J3D_shader_core_light_set_none();

/*jdoc
{"params":["The light direction in <i>x/y/z</i> axes.<br/><b>NOTE: </b>This is the direction <i>where the light goes to</i>,</br>if its source was positioned at <i>(0,0,0)</i>.","The ambient color for lighting.<br/>This is used on non-lit areas.","The light color, typically white."],
"desc":"This function sets a <i>directional</i> light.<br/>A <i>directional</i> light has a direction, but not a position i.e. it's rays are travelling through the scene in a specified direction and not from a single source.<br/>The <i>Sun</i> is such an example. (technically it's a <i>point</i> light, but in relative sizes it's a diretional light)",
"return":"Nothing"}*/
void J3D_shader_core_light_set_directional(J3D_VEC3 lightDirection = J3D_VEC3(-0.5f,-2.0f,-2.0f), J3D_COLOR colorAmbient = J3D_COLOR(96,96,96), J3D_COLOR colorLight = J3D_COLOR(255,255,255));

/*jdoc
{"params":["The light position in <i>x/y/z</i> axes.","The light color, typically white.","The attenuation factor, used to describe the loss of light intensity over distance. As the value gets bigger, the loss of light insensity becomes more and more visible.","The source insensity is used to make the intensify the light source, regardless of how much the light intensity is loss (attenuation). By default is <b>0.0f</b>. Can be used to apply stronger (than normal) light sources."],
"desc":"This function sets a <i>point</i> light.<br/>A <i>point</i> light has a position, light and attenuation (loss of intensity by distance). It radiates light to all directions and it's influenced by distance. The <i>bulb</i> is such an example.",
"return":"Nothing"}*/
void J3D_shader_core_light_set_point(J3D_VEC3 lightPosition = J3D_VEC3(0.0f,0.0f,0.0f), J3D_COLOR colorLight = J3D_COLOR(255,255,255), float attenuationFactor = 0.0f, float sourceIntensity = 0.0f);

/*jdoc
{"desc":"This function disables fog (default).<br/><b>NOTE: </b>This is only used on default 3D shader.",
"return":"Nothing"}*/
void J3D_shader_core_fog_set_none();

/*jdoc
{"params":["The fog distance.","The fog color."],
"desc":"This function enables linear fog.<br/><b>NOTE: </b>This is only used on default 3D shader",
"return":"Nothing"}*/
void J3D_shader_core_fog_set_linear(float distance, J3D_COLOR color = J3D_COLOR(255,255,255));

/*jdoc
{"params":["The start distance where transparency starts (models are fully <b>opaque</b>).","The end distance where transparency stops (models become fully <b>transparent</b>)."],
"desc":"This function enables model transparency by distance.<br/><b>NOTE: </b>This is only used on default 3D shader",
"return":"Nothing"}*/
void J3D_shader_core_transparency_set_distance(float from = 0.0f, float to = 0.0f);

// font ////////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Font",
"params":["The font filename.<br/><b>NOTE: </b>If left blank, <i>fromdata</i> will be used.","(optional) The font data, as a string."],
"desc":"This function returns the contained languages from a font file in a variable.<br/>For example, to check if cyrillic language exist, simply check:<div class='code'>bool cyrillic_found = (<b>languages</b> & J3D_FONT_LANGUAGE_CYRILLIC);</div>where <b>languages</b> is the result of this function.",
"return":"The font languages, see [Font languages]."}*/
uint32_t J3D_font_get_languages(string fromfile = "", string fromdata = "");

/*jdoc
{"params":["The font name","The font filename.<br/><b>NOTE: </b>If left blank, <i>fromdata</i> will be used.","(optional) The font data, as a string.","Height, in pixels.<br/><b>NOTE: </b>by default, it is set to <b>16</b>","The languages(s) to load from the font, see [Font languages].<br/><b>NOTE: </b>You can set more than one via <i>OR</i> operator, provided<br/>the language <i>is found</i> in the font file.","Whether the font will be antialiased (smooth edges)","Whether the font will be rendered bold.<br/><b>NOTE: </b>This just emulates <i>boldness</i> on a font by adding +1 pixel<br/>to the right of original pixel. If there's a font with <b>bold</b> style file,<br/>use that instead.","(optional) The additional ranges of code points you wish to load."],
"desc":"This function loads a font file to be used on text drawing.<br/>Supported formats are: <b>ttf, otf</b><br/><br/><b>NOTE: </b>The function is creating a texture of fixed size to store all characters, for all specified languages; the more you add (especially chinese), the larger the texture will likely to get.<br/>The combination of large number of characters and/or their size may lead to texture sizes that target hardware can't handle. In this event, a warning will be sent to log.<br/>The only solution will be to either downgrade font size or add fewer languages.<br/>You can check the texture's size a font is using by calling the following:<div class='code'>J3D_TEXTURE* tex = J3D_texture_get( J3D_font_get(<b>\"font\"</b>)->texturename );</div>where <b>font</b> is your font name, then use <b>tex->width, tex->height</b>.<br/>Platforms have wide differences on <i>maximum texture size</i>, a rule of thumb is to keep the texture at most <i>2048 x 2048</i> size (this mostly helps on mobile platforms, as desktop platforms have far bigger limits) and/or using scaling on rendering.",
"return":"Nothing"}*/
void J3D_font_load(string name, string fromfile = "", string fromdata = "", int16_t height = 16, uint32_t language = J3D_FONT_LANGUAGE_LATIN, bool antialiased = true, bool bold = false, vector<J3D_POINT> range_codepoints = vector<J3D_POINT>());

/*jdoc
{"params":["The font name"],
"desc":"This function returns the object of a loaded font.",
"return":"The font object or NULL if there's no font with the given <i>name<i>"}*/
J3D_FONT* J3D_font_get(string name);

/*jdoc
{"params":["The font name"],
"desc":"This function releases a loaded font from the memory.<br/><b>NOTE:</b> This is optional since <i>Jolt3D!</i> releases all objects automatically.",
"return":"Nothing"}*/
void J3D_font_release(string name);

// texture /////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Texture",
"params":["The texture name","Width, in pixels","Height, in pixels","Color to fill texture's surface.<br><b>NOTE: </b>For transparent texture, use <i>J3D_COLOR(r,g,b,<b>0</b>)</i>"],
"desc":"This function creates a colored texture. The dimensions may be  modified<br/>to ensure a <i>powered-by-2</i> resolution, for portability reasons.<br/>Use always the dimensions returned by [J3D_texture_get]",
"return":"Nothing"}*/
void J3D_texture_create_by_color(string name, uint32_t width = 1, uint32_t height = 1, J3D_COLOR color = J3D_COLOR(255,255,255));

/*jdoc
{"params":["The texture name","The texture filename.<br/><b>NOTE: </b>If left blank, <i>fromdata</i> will be used.","(optional) The texture data, as a string.","The texture filtering, see [Texture filters].","The mipmap texture filtering, see [Texture mip-mapping filters].","The texture wrapping, see [Texture wrap]."],
"desc":"This function loads an image file to be used as texture.<br/>Supported formats can be found on [Image formats].",
"return":"Nothing"}*/
void J3D_texture_load(string name, string fromfile = "", string fromdata = "", uint16_t filter = J3D_TEXTURE_FILTER_LINEAR, uint16_t mipmap_filter = J3D_TEXTURE_MIPMAP_FILTER_LINEAR, int wrap = J3D_TEXTURE_WRAP_CLAMP_TO_EDGE);

/*jdoc
{"params":["The object to hold the pixels","The texture filename.<br/><b>NOTE: </b>If left blank, <i>fromdata</i> will be used.","(optional) The texture data, as a string.<br/><b>NOTE: </b>If left blank, <i>fromtexture</i> will be used.","(optional) The <i>valid</i> (created) texture name.","(optional) If <b>TRUE</b>, the pixels will be flipped vertically.<br/><b>NOTE: </b>By default, necessary flipping is done automatically by the engine."],
"desc":"This function retrieves the pixels from either an image file,<br/>memory or a valid texture.<br/>Supported formats can be found on [Image formats].",
"return":"<i>TRUE</i> if the retrieval of pixels succeeded."}*/
bool J3D_texture_get_pixels_from_source(J3D_TEXTUREPIXELS* tp, string fromfile = "", string fromdata = "", string fromtexture = "", bool flip = false);

/*jdoc
{"params":["The retrieved size","The texture filename.<br/><b>NOTE: </b>If left blank, <i>fromdata</i> will be used.","(optional) The texture data, as a string.<br/><b>NOTE: </b>If left blank, <i>fromtexture</i> will be used.","(optional) The <i>valid</i> (created) texture name."],
"desc":"This function retrieves the dimensions from either an image file,<br/>memory or a valid texture.<br/>Supported formats can be found on [Image formats].",
"return":"<i>TRUE</i> if the retrieval of size succeeded."}*/
bool J3D_texture_get_size_from_source(J3D_POINT& size, string fromfile = "", string fromdata = "", string fromtexture = "");

/*jdoc
{"params":["The object to slice the pixels from","The object to hold the sliced pixels.<br/><b>NOTE: </b>The object gets released first.","The rectangle of source texture to slice the pixels from.<br/><b>NOTE: </b>Sizes must be given into <i>.right, .bottom</i> members."],
"desc":"This function slices a rectangular area of pixels,<br/>from the given source object to another object.",
"return":"<i>TRUE</i> if the slicing of pixels succeeded."}*/
bool J3D_texture_slice_pixels(const J3D_TEXTUREPIXELS& src, J3D_TEXTUREPIXELS& dest, J3D_RECT rc);

/*jdoc
{"params":["The first object to compare its pixels.<br/><b>NOTE: </b>Transparent pixels will be skipped.","The second object to compare its pixels","This controls the <i>similarity tolerance</i>, as a <i>percentage</i>.<br/>Example: an <b>20%</b> difference (or <i>distance</i>) will cause this function<br/>to fail if one of the pixels of the 2 objects is more different than <b>20%</b>.","(optional) A rectangular area on <i>second texture</i> to be used for comparison.<br/>The <i>.right</i> and <i>.bottom</i> are used for width and height respectively.<br/><b>NOTE: </b>By default, the entire area of source object is used.","(optional) It will hold a specific 2D position (in texture object)<br/>where the pixels are more different than provided <i>diff_colordistance</i>,<br/>assuming the function fails the test."],
"desc":"This function compares two texture objects and returns a boolean result,<br/>based on provided <i>color difference</i> tolerance.<br/><b>NOTE: </b>The function uses the <a href='https://en.wikipedia.org/wiki/Euclidean_distance'>Euclidean distance</a> algorithm and </br><a href='https://en.wikipedia.org/wiki/CIE_1931_color_space#Definition_of_the_CIE_XYZ_color_space'>CIE XYZ color space</a> to compare the pixels in <i>human-perception</i> level.",
"return":"<i>TRUE</i> if the two texture objects are similar, based on provided <i>color difference</i>."}*/
bool J3D_texture_compare_pixels(const J3D_TEXTUREPIXELS& src1, const J3D_TEXTUREPIXELS& src2, int32_t colordistance, const J3D_RECT& area = J3D_RECT(), J3D_POINT* pointdiff = NULL);

/*jdoc
{"params":["The object to resize pixels from","The new size for the resized object","(optional) <b>TRUE</b> to convert the provided new size to powered-by-2 values.<br/><b>NOTE: </b>By default pixels are not converted to powered-by-2 values.","(optional) <b>TRUE</b> to flip the resulted pixels vertically.<br/><b>NOTE: </b>By default pixels are not flipped."],
"desc":"This function resizes the pixels from the provided object to a new size,<br/>potentially with powered-by-2 sizes supported by the current hardware.",
"return":"<i>TRUE</i> if the resizing of pixels succeeded."}*/
bool J3D_texture_resize_pixels(J3D_TEXTUREPIXELS& tp, J3D_POINT new_size, bool pow2 = false, bool flip = false);

/*jdoc
{"params":["The filename","The file format to save the pixels to, see [Image formats].<br/><b>NOTE:</b> Not all formats are supported, check <i>description</i>.","The object to retrieve the pixels from"],
"desc":"This function saves the pixels from a given source to a specific file.<br/>Supported formats are: <b>bmp, png, ppm, tga</b>",
"return":"<i>TRUE</i> if the saving of pixels succeeded."}*/
bool J3D_texture_save_pixels_to_file(string filename, string fileformat, const J3D_TEXTUREPIXELS& tp);

/*jdoc
{"params":["The texture name","The object to update the texture pixels with"],
"desc":"This function updates the pixels of a created texture.",
"return":"<i>TRUE</i> if the updating of pixels succeeded."}*/
bool J3D_texture_update_pixels(string name, const J3D_TEXTUREPIXELS& tp);

/*jdoc
{"params":["The texture name","The color"],
"desc":"This function fills the pixels of a created texture with the specified <i>color</i>.<br/><b>NOTE: </b>For transparent pixels, set 0 as the <b>a</b> component.",
"return":"Nothing"}*/
void J3D_texture_fill_pixels(string name, J3D_COLOR color = J3D_COLOR(255,255,255));

/*jdoc
{"params":["The atlas image filename","The file format to save the pixels to, see [Image formats].<br/><b>NOTE:</b> Not all formats are supported, check <i>description</i>.","The list of images to be included","If <i>TRUE</i>, the final texture name will be the filename, without extension and path.<br/><b>NOTE: </b>Useful when filenames never have the same filename (i.e. on different folders)","(optional) The background color of the atlas.<br/><b>NOTE: </b>By default it is transparent."],
"desc":"This function builds an image file (atlas) from a list of other images.<br/>In addition, an <i>XML</i> file is created (with the same name), holding information on atlas file.<br/>Supported formats (for saving the atlas) are: <b>bmp, png, ppm, tga</b>",
"return":"<i>TRUE</i> if the building of atlas succeeded."}*/
bool J3D_texture_build_atlas(const string& atlasfile, string fileformat, const vector<string>& filenames, bool exclude_path = true, J3D_COLOR background_color = J3D_COLOR(255,255,255,0));

/*jdoc
{"params":["The atlas XML data.<br/><b>NOTE: </b>This is not the XML file but the raw data. You can use [J3D_file_read] to read the file.","The rectangles holding the pixel coordinates for each texture in atlas.<br/><b>NOTE: </b>The first index holds the texture names inside the atlas.","The texture name","The texture filename.<br/><b>NOTE: </b>If left blank, <i>fromdata</i> will be used.","(optional) The texture data, as a string.","The texture filtering, see [Texture filters].","The mipmap texture filtering, see [Texture mip-mapping filters].","The texture wrapping, see [Texture wrap]."],
"desc":"This function loads an atlas image file to be used as texture.<br/>Supported formats can be found on [Image formats].",
"return":"<i>TRUE</i> if the loading of atlas succeeded."}*/
bool J3D_texture_load_atlas(const string& xmldata, map<string,J3D_RECT>& rects, string name, string fromfile = "", string fromdata = "", uint16_t filter = J3D_TEXTURE_FILTER_LINEAR, uint16_t mipmap_filter = J3D_TEXTURE_MIPMAP_FILTER_LINEAR, int wrap = J3D_TEXTURE_WRAP_CLAMP_TO_EDGE);

/*jdoc
{"desc":"This function returns the global texture transparency state.",
"return":"The texture transparency state"}*/
bool J3D_texture_get_transparency();

/*jdoc
{"params":["The texture transparency state.<br/>If set to <i>TRUE</i>, the transparent texture pixels wont be drawn.<br/><b>NOTE: </b>By default the texture transparency is enabled."],
"desc":"This function sets the global texture transparency for all texture rendering.<br/>This applies to both 2D/3D functions i.e. [J3D_model_draw] or [J3D_2d_quad_draw] and any function that uses [J3D_texture_set].<br/>Transparent pixels are the ones that are not meant to be drawn i.e. like in PNG images.",
"return":"Nothing"}*/
void J3D_texture_set_transparency(bool enable);

/*jdoc
{"params":["The texture name","Logging if no texture object found under that name.<br/>If set to <i>TRUE</i>, a non-found texture name will be logged.<br/><b>NOTE: </b>By default it is enabled."],
"desc":"This function returns the object of a created texture.",
"return":"The texture object or NULL if there's no texture with the given <i>name<i>"}*/
J3D_TEXTURE* J3D_texture_get(string name, bool log_ifnotfound = true);

/*jdoc
{"params":["The texture name"],
"desc":"This function sets the current texture for the next 3D operations. If <i>name</i> does not exist or param was not given, an internal white texture of 1x1 is provided.",
"return":"Nothing"}*/
void J3D_texture_set(string name = "");

/*jdoc
{"params":["The texture name"],
"desc":"This function releases a loaded texture from the memory.<br/><b>NOTE:</b> This is optional since <i>Jolt3D!</i> releases all objects automatically.",
"return":"Nothing"}*/
void J3D_texture_release(string name);

/*jdoc
{"params":["The render-to-texture name","The texture name"],
"desc":"This function locks the system to use a specific texture for the rendering.",
"return":"Nothing"}*/
bool J3D_texture_render_begin(string name, string texturename);

/*jdoc
{"params":["The render-to-texture name","Screen position to convert into texture position","The width, if texture is scaled in X-axis","The height, if texture is scaled in Y-axis","Optional texture to use, without the need to open the texture for rendering first. If <i>custom_texture</i> is not empty, the <i>name</i> is not used at all, however the conversion is computed normally for the provided custom texture."],
"desc":"This function projects a 2D screen position on attached texture.",
"return":"Nothing"}*/
J3D_POINT J3D_texture_render_to_screen_pos(string name, J3D_POINT pos, uint32_t scaled_texture_width = 0, uint32_t scaled_texture_height = 0, string custom_texture = "");

/*jdoc
{"params":["The render-to-texture name"],
"desc":"This function unlocks the system from using specific texture for the rendering.",
"return":"Nothing"}*/
void J3D_texture_render_end(string name);

// audio //////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Audio",
"params":["The audio name","The audio filename.<br/><b>NOTE: </b>If left blank, <i>fromdata</i> will be used.","(optional) The audio data, as a string."],
"desc":"This function loads an audio file for playback, see [Audio formats].<br/><b>NOTE: </b>Depending on the file size, the system will either load the audio entirely or in chunks (streaming). By default, the buffer size for streaming is <b>64 KB</b>.",
"return":"Nothing"}*/
void J3D_audio_load(string name, string fromfile = "", string fromdata = "");

/*jdoc
{"params":["The audio name","(optional) Indicates whether the specified audio<br/>will be looping when it reaches its playback end.<br/><b>NOTE: </b>By default is <b>FALSE</b> (not looping)."],
"desc":"This function plays an audio file from it's <i>current position</i>. A paused audio will start playing from it's paused position, while a stopped audio will play from start. If the audio is already playing, this call is ignored.",
"return":"Nothing"}*/
void J3D_audio_play(string name, bool is_looping = false);

/*jdoc
{"params":["The audio name"],
"desc":"This function pauses a <i>playing</i> audio file in its current position.<br/>Playback will be continued from the paused position.",
"return":"Nothing"}*/
void J3D_audio_pause(string name);

/*jdoc
{"params":["The audio name"],
"desc":"This function stops a <i>playing</i> audio file and rewind it to the beginning of audio file. Playback will be continued from the beginning.",
"return":"Nothing"}*/
void J3D_audio_stop(string name);

/*jdoc
{"params":["The audio name"],
"desc":"This function checks the <i>playback</i> state of an audio file and<br/>returns <b>TRUE</b> if it has been completed.",
"return":"<b>TRUE</b> if the audio has reached the end."}*/
bool J3D_audio_completed(string name);

/*jdoc
{"params":["The audio name"],
"desc":"This function retrieves the playing state of a loaded audio, check [Audio states].<br/><b>NOTE: </b>Initially, the audio state is set to <b>J3D_AUDIOSTATE_STOPPED</b>",
"return":"The playing state"}*/
int32_t J3D_audio_get_state(string name);

/*jdoc
{"params":["The buffer size used for <i>streaming</i>. By default, this is <b>64 KB</b>."],
"desc":"This function sets the buffer size for <i>streaming</i>.<br/><b>NOTE: </b>Depending on the file size, the system will either load the audio entirely or in chunks (streaming). By default, the buffer size for streaming is <b>64 KB</b>.",
"return":"Nothing"}*/
void J3D_audio_set_buffer_size(int32_t buffer_size);

/*jdoc
{"params":["The volume, as percentage"],
"desc":"This function sets the device audio volume, as <i>percentage</i>.<br/><b>NOTE: </b>Device volume applies to all audio resources (global volume).",
"return":"Nothing"}*/
void J3D_audio_set_volume_device(int32_t percentage);

/*jdoc
{"desc":"This function retrieves the device audio volume.<br/><b>NOTE: </b>Device volume applies to all audio resources (global volume).",
"return":"The device volume, as <i>percentage</i>"}*/
int32_t J3D_audio_get_volume_device();

/*jdoc
{"params":["The audio name","The volume, as percentage"],
"desc":"This function sets the audio volume, as <i>percentage</i>.",
"return":"Nothing"}*/
void J3D_audio_set_volume(string name, int32_t percentage);

/*jdoc
{"params":["The audio name"],
"desc":"This function retrieves the audio volume.",
"return":"The audio volume, as <i>percentage</i>"}*/
int32_t J3D_audio_get_volume(string name);

/*jdoc
{"params":["The audio name"],
"desc":"This function retrieves the total duration of a loaded audio, in <i>seconds</i>.",
"return":"The total duration, in <i>seconds</i>"}*/
float J3D_audio_get_total_seconds(string name);

/*jdoc
{"params":["The audio name"],
"desc":"This function retrieves the playback position of a loaded audio, in <i>seconds</i>.",
"return":"The playback position, in <i>seconds</i>"}*/
float J3D_audio_get_position_seconds(string name);

/*jdoc
{"params":["The audio name"],
"desc":"This function returns the object of a created audio.",
"return":"The audio object or NULL if there's no audio with the given <i>name<i>"}*/
J3D_AUDIO* J3D_audio_get(string name);

/*jdoc
{"params":["The audio name"],
"desc":"This function releases a loaded audio file from the memory.<br/><b>NOTE:</b> This is optional since <i>Jolt3D!</i> releases all objects automatically.",
"return":"Nothing"}*/
void J3D_audio_release(string name);

// video //////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Video",
"params":["The video name","The video filename"],
"desc":"This function loads a video file for playback, see [Video formats].<br/><b>NOTE: </b>The video is rendered on a texture. To get access to this texture<br/>and rendering it on screen, simply call the following:<div class='code'>J3D_VIDEO* <b>video</b> = J3D_video_get(<b>\"video\"</b>);<br/>J3D_2d_quad_draw(0,0,640,480,J3D_COLOR(255,255,255),<b>video->texture->name</b>,100,0,J3D_RECT(0,0,<b>video->size.x</b>,<b>video->size.y</b>)</b>);</div>where <i>video</i> string is your video name.<br/>This example will display the video at <b>640x480</b> pixels but original video size could be provided instead.<br/>Since the texture has always <i>powered-by-2</i> dimensions but video dimensions may be not, we should also provide the original video size for correct pixel coordinates (last parameter) to pull only the video data.",
"return":"Nothing"}*/
void J3D_video_load(string name, string filename);

/*jdoc
{"params":["The video name"],
"desc":"This function plays a video file from it's <i>current position</i>. A paused video will start playing from it's paused position, while a stopped video will play from start. If the video is already playing, this call is ignored.",
"return":"Nothing"}*/
void J3D_video_play(string name);

/*jdoc
{"params":["The video name"],
"desc":"This function pauses a <i>playing</i> video file in its current position.<br/>Playback will be continued from the paused position.",
"return":"Nothing"}*/
void J3D_video_pause(string name);

/*jdoc
{"params":["The video name"],
"desc":"This function stops a <i>playing</i> video file and rewind it to the beginning of video file. Playback will be continued from the beginning.",
"return":"Nothing"}*/
void J3D_video_stop(string name);

/*jdoc
{"params":["The video name"],
"desc":"This function retrieves the playing state of a loaded video, check [Video states].",
"return":"The playing state"}*/
int32_t J3D_video_get_state(string name);

/*jdoc
{"params":["The video name"],
"desc":"This function retrieves the playback position of a loaded video, in <i>seconds</i>.",
"return":"The playback position, in <i>seconds</i>"}*/
float J3D_video_get_position_seconds(string name);

/*jdoc
{"params":["The video name"],
"desc":"This function returns the object of a created video.",
"return":"The video object or NULL if there's no video with the given <i>name<i>"}*/
J3D_VIDEO* J3D_video_get(string name);

/*jdoc
{"params":["The video name"],
"desc":"This function releases a loaded video file from the memory.<br/><b>NOTE:</b> This is optional since <i>Jolt3D!</i> releases all objects automatically.",
"return":"Nothing"}*/
void J3D_video_release(string name);

// 2d /////////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"2D",
"params":["The 2D area used to specify the clipping.<br/>The <i>area</i> is using sizes i.e. <i>J3D_RECT(50,50,100,100)</i> will clip to a 100x100 rectangle.<br/><b>NOTE: </b>A value of <i>J3D_RECT()</i> essentially disables clipping i.e. renders to the entire viewport."],
"desc":"This function defines a specific screen area as <i>drawable</i> i.e. graphic elements will only appear if they're positioned in that region, otherwise they will be rejected (not drawn).<br/><b>NOTE: </b>This is particulary useful to GUI systems and generally in graphics elements that are meant to belong to a specific screen rectangle (the parent) and not exceed its area in any case.",
"return":"Nothing"}*/
void J3D_2d_set_clipping(const J3D_RECT& area = J3D_RECT());

/*jdoc
{"params":["The font used for the calculation.","The text.","(optional) The unicode text.<br/>This is only considered if <i>text</i> is empty and <i>wtext</i> has data. It can be used when you want to draw unicode strings, provided that the required language has been loaded through [J3D_font_load] and font file is guaranteed to contain the language.<br/><b>NOTE: </b>The unicode text needs to be in either <i>UTF-8</i> or <i>UTF-8 with BOM (preferred)</i> file or read from database with correct encoding.","The font scale, with a scale of <b>1.0f</b> being the original font size."],
"desc":"This function calculates the width of a text (in pixels), based on a previously loaded font.<br/><b>NOTE: </b>The function also works on multi-line text, calculating the largest width across all text lines.",
"return":"The text's width, in pixels."}*/
int32_t J3D_2d_text_get_width(const string& fontname, string text, wstring wtext = L"", float scale = 1.0f);

/*jdoc
{"params":["The font used for the calculation.","The text.","(optional) The unicode text.<br/>This is only considered if <i>text</i> is empty and <i>wtext</i> has data. It can be used when you want to draw unicode strings, provided that the required language has been loaded through [J3D_font_load] and font file is guaranteed to contain the language.<br/><b>NOTE: </b>The unicode text needs to be in either <i>UTF-8</i> or <i>UTF-8 with BOM (preferred)</i> file or read from database with correct encoding.","The font scale, with a scale of <b>1.0f</b> being the original font size."],
"desc":"This function calculates the height of a text (in pixels), based on a previously loaded font.<br/><b>NOTE: </b>Multi-line strings are supported by the use of newline character.",
"return":"The text's height, in pixels."}*/
int32_t J3D_2d_text_get_height(const string& fontname, string text, wstring wtext = L"", float scale = 1.0f);

/*jdoc
{"params":["The font used for the calculation.","The text.","(optional) The font scale, with a scale of <b>1.0f</b> being the original font size.","(optional) The desired width to fit the text, in pixels.","(optional) If <b>TRUE</b>, the smaller text per-line will be centered against the larger text."],
"desc":"This function converts the text into a multi-line text so it can fit into the desired width.",
"return":"Nothing"}*/
void J3D_2d_text_fit_by_width(const string& fontname, string& text, float scale = 1.0f, int32_t width = 0, bool center = false);

/*jdoc
{"params":["The font used for the calculation.","(optional) The unicode text.<br/>This is only considered if <i>text</i> is empty and <i>wtext</i> has data. It can be used when you want to draw unicode strings, provided that the required language has been loaded through [J3D_font_load] and font file is guaranteed to contain the language.<br/><b>NOTE: </b>The unicode text needs to be in either <i>UTF-8</i> or <i>UTF-8 with BOM (preferred)</i> file or read from database with correct encoding.","(optional) The font scale, with a scale of <b>1.0f</b> being the original font size.","(optional) The desired width to fit the text, in pixels.","(optional) If <b>TRUE</b>, the smaller text per-line will be centered against the larger text."],
"desc":"This function converts the text into a multi-line text so it can fit into the desired width.",
"return":"Nothing"}*/
void J3D_2d_text_fit_by_width_wide(const string& fontname, wstring& text, float scale = 1.0f, int32_t width = 0, bool center = false);

/*jdoc
{"params":["The font used for drawing","Screen position in X-axis","Screen position in Y-axis","The text.<br/><b>NOTE: </b>You can use [J3D_string_format] to pass a formatted string.<br/>In addition, the character <b>\\f</b> (fat) can be used to start an emulated <b>bold</b> sequence. Another <b>\\f</b> will disable the sequence.","(optional) The unicode text.<br/>This is only considered if <i>text</i> is empty and <i>wtext</i> has data. It can be used when you want to draw unicode strings, provided that the required language has been loaded through [J3D_font_load] and font file is guaranteed to contain the language.<br/><b>NOTE: </b>The unicode text needs to be in either <i>UTF-8</i> or <i>UTF-8 with BOM (preferred)</i> file or read from database with correct encoding.","Color","Opacity (with 100 being fully opaque)","Rotation, in degrees (0-360)","The rendering scale, with a scale of <b>1.0f</b> being the original font size.","(optional) The gradient color.<br/><b>NOTE: </b>Overrides the <i>color</i> if it's set.","(optional) The range of colors on a multi-colored text.<br/>The character <b>\\b</b> is used on text to advance the colors in the list.<br/><b>NOTE: </b><i>rangecolor</i> is used if it's set and <i>colorgradient</i> is not set.","(optional) Allows for <b>multiple</b> objects rendering under the same font.<br/>It greatly <i>increases performance</i> by packing multiple objects under a single draw call."],
"desc":"This function renders a 2D text on the screen.",
"return":"Nothing"}*/
void J3D_2d_text_draw(string fontname, int32_t x, int32_t y, string text = "", wstring wtext = L"", J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100, uint16_t rotateZ = 0, float scale = 1.0f, J3D_COLOR_GRADIENT colorgradient = J3D_COLOR_GRADIENT(), vector<J3D_COLOR> rangecolor = vector<J3D_COLOR>(), vector<J3D_2D_MULTIDRAW>* md = NULL);

/*jdoc
{"params":["The font used for drawing","The packed multiple draw objects."],
"desc":"This function renders multiple 2D texts on the screen with a single draw call.<br/><b>NOTE: </b>The objects can be created using an appropriate <i>J3D_2D_MULTIDRAW()</i> constructor.",
"return":"Nothing"}*/
void J3D_2d_text_draw_multi(string fontname, vector<J3D_2D_MULTIDRAW>* md);

/*jdoc
{"params":["Screen position in X-axis","Screen position in Y-axis","Width in X-axis.<br><b>NOTE: </b>If a valid <i>texture</i> was given, a value of <i>0</i> will use the texture's original width.","Height in Y-axis.<br><b>NOTE: </b>If a valid <i>texture</i> was given, a value of <i>0</i> will use the texture's original height.","Color","Texture to be used (the <i>color</i> still applies in this case)","Opacity (with 100 being fully opaque)","Rotation, in degrees (0-360)","The texture pixel coordinates (if <i>texture</i> is used)","The texture directional orientation (if <i>texture</i> is used), see [Texture orientation]<br/><b>NOTE: </b>Values can be OR-ed to apply multiple orientations.","(optional) The gradient color.","(optional) Allows for <b>multiple</b> objects rendering under the same texture.<br/>It greatly <i>increases performance</i> by packing multiple objects under a single draw call."],
"desc":"This function renders a 2D quad (square) on the screen.<br/><b>NOTE: </b>If many quads needs to be drawn on the screen, consider using [J3D_2d_quad_multiple_draw] to avoid a performance bottleneck.",
"return":"Nothing"}*/
void J3D_2d_quad_draw(int32_t x, int32_t y, int32_t width, int32_t height, J3D_COLOR color = J3D_COLOR(255,255,255), string texture = "", uint8_t opacity = 100, uint16_t rotateZ = 0, J3D_RECT texpixelcoords = J3D_RECT(), int32_t orientation = J3D_TEXTURE_ORIENTATION_NORMAL, J3D_COLOR_GRADIENT colorgradient = J3D_COLOR_GRADIENT(), vector<J3D_2D_MULTIDRAW>* md = NULL);

/*jdoc
{"params":["Texture to be used.<br/><b>NOTE: </b>A blank texture will only use color.","The packed multiple draw objects."],
"desc":"This function renders multiple 2D quads on the screen with a single draw call.<br/><b>NOTE: </b>The objects can be created using an appropriate <i>J3D_2D_MULTIDRAW()</i> constructor.",
"return":"Nothing"}*/
void J3D_2d_quad_draw_multi(string texture = "", vector<J3D_2D_MULTIDRAW>* md = NULL);

/*jdoc
{"params":["Screen position, in X-axis","Screen position, in Y-axis","Width, in X-axis","Height, in Y-axis","Color","Opacity (with 100 being fully opaque)","Rotation, in degrees (0-360)","(optional) The gradient color.","(optional) Allows for <b>multiple</b> objects rendering under the same texture.<br/>It greatly <i>increases performance</i> by packing multiple objects under a single draw call."],
"desc":"This function renders a 2D rectangle on the screen.",
"return":"Nothing"}*/
void J3D_2d_rect_draw(int32_t x, int32_t y, int32_t width, int32_t height, J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100, uint16_t rotateZ = 0, J3D_COLOR_GRADIENT colorgradient = J3D_COLOR_GRADIENT(), vector<J3D_2D_MULTIDRAW>* md = NULL);

/*jdoc
{"params":["The packed multiple draw objects."],
"desc":"This function renders multiple 2D rects on the screen with a single draw call.<br/><b>NOTE: </b>The objects can be created using an appropriate <i>J3D_2D_MULTIDRAW()</i> constructor.",
"return":"Nothing"}*/
void J3D_2d_rect_draw_multi(vector<J3D_2D_MULTIDRAW>* md);

/*jdoc
{"params":["Up-left screen position in XY-axes","Up-right screen position in XY-axes","Down-right screen position in XY-axes","Down-left screen position in XY-axes","Color","Texture to be used (the <i>color</i> still applies in this case)","Opacity (with 100 being fully opaque)","Rotation, in degrees (0-360)","The texture pixel coordinates (if <i>texture</i> is used).","The texture directional orientation (if <i>texture</i> is used), see [Texture orientation]<br/><b>NOTE: </b>Values can be OR-ed to apply multiple orientations.","(optional) The gradient color.","(optional) Allows for <b>multiple</b> objects rendering under the same texture.<br/>It greatly <i>increases performance</i> by packing multiple objects under a single draw call."],
"desc":"This function renders a 2D <i>trapezoid</i> on the screen.",
"return":"Nothing"}*/
void J3D_2d_trapezoid_draw(J3D_POINT ul, J3D_POINT ur, J3D_POINT dr, J3D_POINT dl, J3D_COLOR color = J3D_COLOR(255,255,255), string texture = "", uint8_t opacity = 100, uint16_t rotateZ = 0, J3D_RECT texpixelcoords = J3D_RECT(), int32_t orientation = J3D_TEXTURE_ORIENTATION_NORMAL, J3D_COLOR_GRADIENT colorgradient = J3D_COLOR_GRADIENT(), vector<J3D_2D_MULTIDRAW>* md = NULL);

/*jdoc
{"params":["Texture to be used.<br/><b>NOTE: </b>A blank texture will only use color.","The packed multiple draw objects."],
"desc":"This function renders multiple 2D trapezoids on the screen with a single draw call.<br/><b>NOTE: </b>The objects can be created using an appropriate <i>J3D_2D_MULTIDRAW()</i> constructor.",
"return":"Nothing"}*/
void J3D_2d_trapezoid_draw_multi(string texture = "", vector<J3D_2D_MULTIDRAW>* md = NULL);

/*jdoc
{"params":["The points used to form the polygon.","Color","Opacity (with 100 being fully opaque)","Rotation, in degrees (0-360)","(optional) Allows for <b>multiple</b> objects rendering under the same texture.<br/>It greatly <i>increases performance</i> by packing multiple objects under a single draw call."],
"desc":"This function renders a 2D <i>polygon</i> on the screen.",
"return":"Nothing"}*/
void J3D_2d_polygon_draw(vector<J3D_POINT>& points, J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100, uint16_t rotateZ = 0, vector<J3D_2D_MULTIDRAW>* md = NULL);

/*jdoc
{"params":["The packed multiple draw objects."],
"desc":"This function renders multiple 2D polygons on the screen with a single draw call.<br/><b>NOTE: </b>The objects can be created using an appropriate <i>J3D_2D_MULTIDRAW()</i> constructor.",
"return":"Nothing"}*/
void J3D_2d_polygon_draw_multi(vector<J3D_2D_MULTIDRAW>* md);

/*jdoc
{"params":["Screen position, in X-axis.","Screen position, in Y-axis","The radius, in X-axis.","The radius, in Y-axis.","The <i>quality</i> defines roughly the pixel distance between points to form the ellipsis.<br/>Lesser values forms a high quality ellipsoid, while bigger values worsen the quality in favor of drawing performance.","Color","Opacity (with 100 being fully opaque)","Rotation, in degrees (0-360)","(optional) Allows for <b>multiple</b> objects rendering under the same texture.<br/>It greatly <i>increases performance</i> by packing multiple objects under a single draw call."],
"desc":"This function renders a 2D <i>ellipsoid</i> on the screen.",
"return":"Nothing"}*/
void J3D_2d_ellipsoid_draw(int32_t x, int32_t y, int32_t radiusX, int32_t radiusY, int32_t quality = 1, J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100, uint16_t rotateZ = 0, vector<J3D_2D_MULTIDRAW>* md = NULL);

/*jdoc
{"params":["The packed multiple draw objects."],
"desc":"This function renders multiple 2D ellipsoids on the screen with a single draw call.<br/><b>NOTE: </b>The objects can be created using an appropriate <i>J3D_2D_MULTIDRAW()</i> constructor.",
"return":"Nothing"}*/
void J3D_2d_ellipsoid_draw_multi(vector<J3D_2D_MULTIDRAW>* md);

/*jdoc
{"params":["The point positions, in screen","Color for each point","Opacity (with 100 being fully opaque)"],
"desc":"This function renders pixels from a series of points on the screen.<br/><b>NOTE: </b>The <i>points</i> and <i>colors</i> are getting cleared automatically after the call.",
"return":"Nothing"}*/
void J3D_2d_point_draw(vector<J3D_POINT>& points, vector<J3D_COLOR>& colors, uint8_t opacity = 100);

/*jdoc
{"params":["The points used to connect the line.<br/><b>NOTE: </b>The line is <i>stripped</i>, therefore 2 points draw a line,<br/>3 points draw two lines etc.","Color for each line<br/><b>NOTE: </b>Vector size for <i>colors</i> & <i>points</i> should match.","Opacity (with 100 being fully opaque)"],
"desc":"This function renders a 2D line from a series of points on the screen.<br/><b>NOTE: </b>The <i>points</i> and <i>colors</i> are getting cleared automatically after the call.",
"return":"Nothing"}*/
void J3D_2d_line_draw(vector<J3D_POINT>& points, vector<J3D_COLOR>& colors, uint8_t opacity = 100);

/*jdoc
{"params":["The computed points that form the line","The starting point, in pixels","The ending point, in pixels"],
"desc":"This function computes a series of points between a start / end point, producing a straight line. The algorithm is based on Bresenham's line algorithm.",
"return":"Nothing"}*/
void J3D_2d_get_line_points(vector<J3D_POINT>& points, J3D_POINT from, J3D_POINT to);

/*jdoc
{"params":["The object holding the pixels.<br/><b>NOTE: </b>If <i>tp</i> has already data, it's automatically released.","Screen position, in X-axis","Screen position, in Y-axis","Width, in X-axis.<br/><b>NOTE: </b>If <i>0</i> is provided, the entire desktop width will be used.","Height, in Y-axis.<br/><b>NOTE: </b>If <i>0</i> is provided, the entire desktop height will be used."],
"desc":"This function reads directly the pixels from a 2D rectangular screen area.<br/>On <i>Fullscreen</i> applications, it reads the pixels directly from front buffer context.<br/>On <i>Windowed</i> applications, the entire desktop's pixels can be retrieved.",
"return":"Nothing"}*/
void J3D_2d_get_screen(J3D_TEXTUREPIXELS* tp, int32_t x = 0, int32_t y = 0, int32_t w = 0, int32_t h = 0);

/*jdoc
{"params":["The list of 2D rectangles.","The object holding all packed rectangles."],
"desc":"This function fits a number of 2D rectangles <i>efficiently</i> into a much bigger 2D rectangle.",
"return":"Nothing"}*/
void J3D_2d_pack_rectangles(const vector<J3D_RECT>& rects, J3D_RECTPACK& rectspack);

/*jdoc
{"group":"Animation",
"desc":"This function updates all created animations.",
"return":"Nothing."}*/
void J3D_anim_update();

/*jdoc
{"params":["The animation name.","The animation step, in <i>milliseconds</i>.","The total number of frames.","(optional) The first custom value.","(optional) The second custom value.","(optional) The third custom value.","(optional) The fourth custom value.","(optional) The fifth custom value.","(optional) A list of custom values, as a <i>vector</i> of doubles."],
"desc":"This function creates an animation, which is automatically starts.",
"return":"Nothing"}*/
void J3D_anim_create(const string& name, uint32_t timer_step_ms, uint32_t frame_stop_at, double custom0 = 0, 
                     double custom1 = 0, double custom2 = 0, double custom3 = 0, double custom4 = 0, 
					 const vector<double>& customv = vector<double>());

/*jdoc
{"params":["The animation name."],
"desc":"This function deletes a created animation.",
"return":"Nothing"}*/
void J3D_anim_delete(const string& name);

/*jdoc
{"params":["The animation name."],
"desc":"This function returns the object of a created animation.",
"return":"The animation object or NULL if there's no animation with the given <i>name<i>"}*/
J3D_ANIMATION* J3D_anim_get(const string& name);

/*jdoc
{"params":["The animation name."],
"desc":"This function plays an animation from it's <i>current position</i>.",
"return":"Nothing."}*/
void J3D_anim_play(const string& name);

/*jdoc
{"params":["The animation name."],
"desc":"This function pauses a <i>running</i> animation.<br/>Playback will be continued from the paused position.",
"return":"Nothing."}*/
void J3D_anim_pause(const string& name);

/*jdoc
{"params":["The animation name."],
"desc":"This function returns the time (in <i>milliseconds</i>) of a created animation,<br/>when the animation had been created.",
"return":"The time, in milliseconds."}*/
int32_t J3D_anim_get_timer_start(const string& name);

/*jdoc
{"params":["The animation name."],
"desc":"This function returns the time step (in <i>milliseconds</i>) of a created animation,<br/>on which the animation is updated.",
"return":"The time, in milliseconds."}*/
int32_t J3D_anim_get_timer_step_ms(const string& name);

/*jdoc
{"params":["The animation name.","The time, in milliseconds."],
"desc":"This function sets the time step (in <i>milliseconds</i>) of a created animation,<br/>on which the animation is updated.",
"return":"Nothing."}*/
void J3D_anim_set_timer_step_ms(const string& name, uint32_t timer_step_ms);

/*jdoc
{"params":["The animation name."],
"desc":"This function returns the current frame of a created animation.",
"return":"The current frame."}*/
int32_t J3D_anim_get_frame_cur(const string& name);

/*jdoc
{"params":["The animation name.","The current frame."],
"desc":"This function sets the current frame of a created animation.",
"return":"Nothing."}*/
void J3D_anim_set_frame_cur(const string& name, int32_t frame);

/*jdoc
{"params":["The animation name."],
"desc":"This function returns the total number of frames of a created animation.",
"return":"The total number of frames."}*/
int32_t J3D_anim_get_frame_stop_at(const string& name);

/*jdoc
{"params":["The animation name.","The total number of frames."],
"desc":"This function sets the total number of frames of a created animation.",
"return":"Nothing."}*/
void J3D_anim_set_frame_stop_at(const string& name, uint32_t frame_stop_at);

/*jdoc
{"params":["The animation name.","The index of custom value.<br/><b>NOTE: </b>Up to 5 custom values can be set."],
"desc":"This function returns a specific custom value of a created animation, by an index.",
"return":"The custom value, as double."}*/
double J3D_anim_get_custom_byindex(const string& name, int32_t index);

/*jdoc
{"params":["The animation name.","The index of custom value.<br/><b>NOTE: </b>Up to 5 custom values can be set.","The custom value."],
"desc":"This function sets a specific custom value of a created animation, by an index.",
"return":"Nothing."}*/
void J3D_anim_set_custom_byindex(const string& name, int32_t index, double custom);

/*jdoc
{"params":["The animation name."],
"desc":"This function returns the custom values of a created animation, as an array.",
"return":"The custom values, as array of doubles."}*/
double* J3D_anim_get_custom(const string& name);

/*jdoc
{"params":["The animation name.","The custom values, as array of doubles."],
"desc":"This function sets the custom values of a created animation, as an array.",
"return":"Nothing."}*/
void J3D_anim_set_custom(const string& name, double* custom);

/*jdoc
{"params":["The animation name."],
"desc":"This function returns a list of custom values of a created animation.",
"return":"The list of values, as a <i>vector</i> of doubles."}*/
vector<double> J3D_anim_get_customv(const string& name);

/*jdoc
{"params":["The animation name.","The list of values, as a <i>vector</i> of doubles."],
"desc":"This function sets a list of custom values of a created animation.",
"return":"Nothing."}*/
void J3D_anim_set_customv(const string& name, vector<double> custom);

/*jdoc
{"params":["The animation name."],
"desc":"This function returns <b>TRUE</b> if the specified animation exists.",
"return":"The state of animation."}*/
bool J3D_anim_is_found(const string& name);

/*jdoc
{"params":["The animation name."],
"desc":"This function returns <b>TRUE</b> if the specified animation is completed.",
"return":"The state of animation."}*/
bool J3D_anim_is_completed(const string& name);

/*jdoc
{"params":["The animation name."],
"desc":"This function returns <b>TRUE</b> if the specified animation is updated.",
"return":"The state of animation."}*/
bool J3D_anim_is_updated(const string& name);

/*jdoc
{"params":["The animation name."],
"desc":"This function returns <b>TRUE</b> if the specified animation is paused.",
"return":"The state of animation."}*/
bool J3D_anim_is_paused(const string& name);

// gui ///////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"GUI",
"params":["The xml gui template filename.","(optional) The fonts folder.<br/>If left blank, the <i>xmlfile</i> folder will be used."],
"desc":"This function loads an <i>xml-based</i> gui template file from disk.<br/>This file describes the behaviour of all gui controls in template,<br/>both in rendering and event level.<br/>All consequent gui calls will use this template.",
"return":"<i>TRUE</i> on success"}*/
bool J3D_gui_init(string xmlfile, string fontfolder = "");

/*jdoc
{"params":["The gui state."],
"desc":"This function enables/disables the initialized gui system.<br/>By default, the gui system is <b>disabled</b>. When the gui is disabled,<br/>there's no rendering or any event for gui controls.",
"return":"Nothing"}*/
void J3D_gui_enable(bool enable);

/*jdoc
{"desc":"This function returns the state of the gui system.<br/>By default, the gui system is <b>disabled</b>, therefore <b>FALSE</b> will be returned.",
"return":"<b>TRUE</b> if the gui system is enabled."}*/
bool J3D_gui_is_enabled();

/*jdoc
{"desc":"This function retrieves the <b>base texture</b> (not the actual filename, but the <i>Jolt3D!</i> name for the texture) that gui template is using for all control rendering. There's only one texture file, that is set on <i>gui template</i> file, and all controls are using it for rendering, using precise texture pixel coordinates.",
"return":"Nothing"}*/
string J3D_gui_get_texture();

/*jdoc
{"params":["The control name.","The event to handle.","The callback for the event.<br/><b>NOTE: </b>For reverting back to default handler, a <i>NULL</i> value can be passed."],
"desc":"This function defines an additional callback for a specific control and event. Whenever this event is triggered for this control, this callback will be called <i>after</i> the default handler [J3D_callback_gui].",
"return":"Nothing"}*/
void J3D_gui_set_event_handler(string name, int32_t event, void (*callback)(J3D_GUIEVENT e));

/*jdoc
{"desc":"This function retrieves the <i>event</i> that gui system is currently<br/>performing, see [Gui events].",
"return":"The current gui event."}*/
int32_t J3D_gui_get_current_event();

/*jdoc
{"params":["The control name.","The event to set."],
"desc":"This function sets an event to specified control.<br/>This also triggers the default handler [J3D_callback_gui].",
"return":"Nothing"}*/
void J3D_gui_set_current_event(string name, int32_t event);

/*jdoc
{"params":["The control name."],
"desc":"This function returns the <i>base</i> object of a created gui control.<br/><b>NOTE: </b>The base object doesn't hold unique control properties, for this you need <b>J3D_gui_XXX_get</b> functions where <b>XXX</b> the control type.",
"return":"The base gui control object or NULL if there's no gui control with the given <i>name<i>"}*/
J3D_GUICONTROL* J3D_gui_control_get(string name);

/*jdoc
{"params":["The control name.","(optional) If <b>TRUE</b>, the relative position to container will be returned."],
"desc":"This function returns the screen or relative position of a created gui control.<br/><b>NOTE: </b>For containers, the screen position is always returned.",
"return":"The screen position of the gui control or <i>J3D_POINT(0, 0)</i> if there's<br/>no gui control with the given <i>name</i>."}*/
J3D_POINT J3D_gui_control_get_position(string name, bool relative_pos = false);

/*jdoc
{"params":["The control name."],
"desc":"This function sets the screen or relative position of a created gui control.<br/><b>NOTE: </b>For containers, the screen position is always set, otherwise the relative is set.",
"return":"Nothing"}*/
void J3D_gui_control_set_position(string name, J3D_POINT pos);

/*jdoc
{"params":["The control name."],
"desc":"This function returns the visibility for a created gui control.",
"return":"<i>TRUE</i> if the control is visible."}*/
bool J3D_gui_control_get_visibility(string name);

/*jdoc
{"params":["The control name.","The visibility state, where <i>TRUE</i> means it's visible."],
"desc":"This function sets the visibility for a created gui control.<br/><b>NOTE: </b>A hidden control is not rendered and will not send any messages.",
"return":"Nothing"}*/
void J3D_gui_control_set_visibility(string name, bool visibility);

/*jdoc
{"params":["The control name."],
"desc":"This function releases a created gui control from the memory. This can be used to destroy controls not needed anymore, instead of hiding them.<br/><b>NOTE: </b>This is optional since <i>Jolt3D!</i> releases all objects automatically.",
"return":"Nothing"}*/
void J3D_gui_control_release(string name);

/*jdoc
{"desc":"This function retrieves all created gui controls, inside a container.<br/>All gui controls are retrieved, except <i>window</i> controls and those<br/>found on <i>another container</i>, in the format of:<br/>  <b>|control name| = gui control object</b>.<br/><br/><b>NOTE: </b> A <i>container</i> is typically a window but other controls may be used to contain other controls.",
"return":"A list of gui controls, as a <i>map</i> of pointers."}*/
map<string,J3D_GUICONTROL*> J3D_gui_control_get_all_by_container(string containername);

/*jdoc
{"params":["The control name.","The screen position, in X-axis.","The screen position, in Y-axis.","Width, in pixels.","Height, in pixels.","If <i>TRUE</i>, window will render its body and titlebar (if specified).<br/><b>NOTE: </b> Disabling the body rendering is useful in cases where you want to show <i>isolated</i> controls anywhere in the screen, without their parent window.","If <i>TRUE</i>, window will have a titlebar and can be moved.","Title, as string.","(optional) If <i>TRUE</i>, the window wont allow the selection of another window.<br/><b>NOTE: </b>By default this is <i>FALSE</i>.","(optional) The custom data to set for the control."],
"desc":"This function creates a gui window. A <i>window</i> itself is a gui control, with the exception that is a <i>container</i> control. <i>Containers</i> differ from other controls because they can contain other controls as well. Also container's position affects (eg. moves) its contained controls as well.",
"return":"<i>TRUE</i> on success"}*/
bool J3D_gui_window_create(string name, int32_t x, int32_t y, int32_t width, int32_t height, bool havebody = true, bool havetitlebar = true, string title = "", bool permanent_focus = false, void* data = NULL);

/*jdoc
{"params":["The control name.","The screen position, in X-axis.","The screen position, in Y-axis.","Width, in pixels.","If <i>TRUE</i>, window will render its body and titlebar (if specified).<br/><b>NOTE: </b> Disabling the body rendering is useful in cases where you want to show <i>isolated</i> controls anywhere in the screen, without their parent window.","If <i>TRUE</i>, window will have a titlebar and can be moved.","Title, as string.","The number of <i>entries</i> (eg. files/folders) to be shown at any time.<br/><b>NOTE: </b>This variable calculates the listbox height and window in general.","Include only the files with the provided extension, in a comma separated string of extensions.<br/>For example, <i>\"jpg,png\"</i> will only include .jpg and .png files.<br/><b>NOTE: </b>If left blank, all files will be shown.","(optional) The scale to use for the whole window.","(optional) If <i>TRUE</i>, the window wont allow the selection of another window.<br/><b>NOTE: </b>By default this is <i>FALSE</i>."],
"desc":"This function creates a gui window with file selection functionality. The window creates also the following gui controls: (the <i>name</i> prefix corresponds to the window name)<ul><li><b><i>name</i>_listbox</b><br/>The listbox containing all the entries.</li><li><b><i>name</i>_prev</b><br/>The previous button, which is used to go back a folder.</li><li><b><i>name</i>_ok</b><br/>The ok button, which is used to close the openfile window while having selected a file.<br/><b>NOTE: </b>Developers are advised to catch this event and then use [J3D_gui_window_openfile_get_filename] to get the filename.</li><li><b><i>name</i>_cancel</b><br/>The cancel button, which is used to close the openfile.</li></ul>",
"return":"<i>TRUE</i> on success"}*/
bool J3D_gui_window_create_openfile(string name, int32_t x, int32_t y, int32_t width, bool havebody = true, bool havetitlebar = true, string title = "", int32_t numentriesshown = 10, string extensions = "", float scale = 1.0f, bool permanent_focus = false);

/*jdoc
{"params":["The control name.","The selected filename, with fullpath."],
"desc":"This function returns the currently selected filename from an <i>openfile</i> window, along with its fullpath.",
"return":"Nothing."}*/
void J3D_gui_window_openfile_get_filename(string name, string& filename);

/*jdoc
{"params":["The control name."],
"desc":"This function returns the object of a created gui window.",
"return":"The gui window object or NULL if there's no gui control with the given <i>name<i>"}*/
J3D_GUICONTROL_WINDOW* J3D_gui_window_get(string name);

/*jdoc
{"desc":"This function returns the name of the active gui window.<br/><b>NOTE: </b>If there is no active window, an empty string will be returned",
"return":"The name of the active gui window"}*/
string J3D_gui_window_get_active();

/*jdoc
{"params":["The control name."],
"desc":"This function sets the specified window as the active gui window.",
"return":"Nothing."}*/
void J3D_gui_window_set_active(string name);

/*jdoc
{"desc":"This function retrieves all created gui windows.",
"return":"The list of all gui windows, in a <i>vector</i> of pointers."}*/
vector<J3D_GUICONTROL*> J3D_gui_window_get_all();

/*jdoc
{"params":["The screen position, as <i>J3D_POINT</i>."],
"desc":"This function finds the gui window, underneath a specific <i>screen position</i>.",
"return":"The gui window or <i>empty string</i> if no gui window found."}*/
string J3D_gui_window_get_by_point(J3D_POINT p);

/*jdoc
{"params":["The container name.","The control name","The screen position, in X-axis.","The screen position, in Y-axis.","Text, as string.","Color of text. This is <i>optional</i>, since colors are typically set in gui template file.","(optional) The rendering scale, by default is <b>1.0f</b> (original size)."],
"desc":"This function creates a gui text. A <i>text</i> is a static gui control that doesn't trigger any events through [J3D_callback_gui] function.",
"return":"<i>TRUE</i> on success"}*/
bool J3D_gui_text_create(string containername, string name, int32_t x, int32_t y, string text, J3D_COLOR color = J3D_COLOR(0,0,0,0), float scale = 1.0f);

/*jdoc
{"params":["The control name."],
"desc":"This function returns the object of a created gui text.",
"return":"The gui text object or NULL if there's no gui control with the given <i>name<i>"}*/
J3D_GUICONTROL_TEXT* J3D_gui_text_get(string name);

/*jdoc
{"params":["The control name"],
"desc":"This function returns the text of a gui text control.",
"return":"The text, as <i>string</i>."}*/
string J3D_gui_text_get_text(string name);

/*jdoc
{"params":["The control name","Text, as string"],
"desc":"This function sets the text of a gui text control.",
"return":"Nothing"}*/
void J3D_gui_text_set_text(string name, string text);

/*jdoc
{"params":["The container name.","The control name","The screen position, in X-axis.","The screen position, in Y-axis.","The image width.","The image height.","The image color.<br/><b>NOTE: </b>If <i>fromfile</i> and <i>fromtexture</i> are both invalid, a colored quad will be rendered instead.<br/>Otherwise the <i>color</i> filters the final image.","The image filename.<br/>Supported formats can be found on [Image formats].<br/><b>NOTE: </b>If left blank, <i>fromtexture</i> will be used.","(optional) The image texture, loaded by [J3D_texture_load]","The texture pixel coordinates (if either <i>fromfile</i> or <i>fromtexture</i> are used)","(optional) The rendering scale, by default is <b>1.0f</b> (original size)."],
"desc":"This function creates a gui image. An <i>image</i> is a static gui control that doesn't trigger any events through [J3D_callback_gui] function.",
"return":"<i>TRUE</i> on success"}*/
bool J3D_gui_image_create(string containername, string name, int32_t x, int32_t y, int32_t width, int32_t height, J3D_COLOR color = J3D_COLOR(255,255,255,0), string fromfile = "", string fromtexture = "", J3D_RECT texpixelcoords = J3D_RECT(), float scale = 1.0f);

/*jdoc
{"params":["The control name."],
"desc":"This function returns the object of a created gui image.",
"return":"The gui image object or NULL if there's no gui control with the given <i>name<i>"}*/
J3D_GUICONTROL_IMAGE* J3D_gui_image_get(string name);

/*jdoc
{"params":["The container name.","The control name","The screen position, in X-axis.","The screen position, in Y-axis.","Title, as string.","(optional) The rendering scale, by default is <b>1.0f</b> (original size)."],
"desc":"This function creates a gui button. A <i>button</i> is a gui control that can be clicked, triggering events through [J3D_callback_gui] function.",
"return":"<i>TRUE</i> on success"}*/
bool J3D_gui_button_create(string containername, string name, int32_t x, int32_t y, string title, float scale = 1.0f);

/*jdoc
{"params":["The control name."],
"desc":"This function returns the object of a created gui button.",
"return":"The gui button object or NULL if there's no gui control with the given <i>name<i>"}*/
J3D_GUICONTROL_BUTTON* J3D_gui_button_get(string name);

/*jdoc
{"params":["The container name.","The control name","The screen position, in X-axis.","The screen position, in Y-axis.","The scrollbar orientation, see [Scrollbar orientation].","The size, in pixels.","(optional) The rendering scale, by default is <b>1.0f</b> (original size)."],
"desc":"This function creates a gui scrollbar. A <i>scrollbar</i> is a gui control that provides a <i>scrollable</i> bar, triggering events through [J3D_callback_gui] function.",
"return":"<i>TRUE</i> on success"}*/
bool J3D_gui_scrollbar_create(string containername, string name, int32_t x, int32_t y, int8_t orientation, int32_t size, float scale = 1.0f);

/*jdoc
{"params":["The control name."],
"desc":"This function returns the object of a created gui scrollbar.",
"return":"The gui scrollbar object or NULL if there's no gui control with the given <i>name<i>"}*/
J3D_GUICONTROL_SCROLLBAR* J3D_gui_scrollbar_get(string name);

/*jdoc
{"params":["The control name.","The mode to get the thumbposition, see [Scrollbar thumbposition modes].<br/><b>NOTE: </b>By default the position is returned as <i>percentage</i> to scrollbar's size."],
"desc":"This function returns the current position of scrollbar <i>thumb</i>.<br/>The <i>thumb</i> is the draggable box of the scrollbar.",
"return":"The thumb position, as defined in <i>mode</i>."}*/
double J3D_gui_scrollbar_get_thumbposition(string name, int32_t mode = J3D_STP_BYPERCENTAGE);

/*jdoc
{"params":["The control name.","The thumb position, based on <i>mode</i>.","The mode to set the thumbposition, see [Scrollbar thumbposition modes].<br/><b>NOTE:</b> By default the position is set as percentage to scrollbar's size."],
"desc":"This function sets the current position of scrollbar <i>thumb</i>. If the position is outside of bounds based on specified <i>mode</i>, the system reverts it to default sizes.",
"return":"Nothing."}*/
void J3D_gui_scrollbar_set_thumbposition(string name, double pos, int32_t mode = J3D_STP_BYPERCENTAGE);

/*jdoc
{"params":["The control name.","The number of all content.","The number of always shown content."],
"desc":"This function can be used to combine a scrollbar thumb position and any given kind of <i>content</i>, to produce a mean for switching pages as thumb position is moving around.<br/>The <i>content</i> is an <b>abstraction</b> and can be anything, number of files on screen or pixels of a texture shown in screen; This really depends on developer's side and how he wants to <i>swap pages</i> by thumb position.<br/>For example, let's say we need to show an image having <i>1600 pixels in total width</i> (this is the <i>content_all</i>) but only showing <i>256 width</i> at any given time (this is the <i>content_shown</i>). Then, regardless of our scrollbar size, this function will use current thumb position and specified input to return the <i>number of pixels for a portion of image</i> to show; at the end of scrollbar, the image will be shown in full.",
"return":"The number of <i>units</i> (determined by content itself) to make up a content's portion."}*/
double J3D_gui_scrollbar_get_portion_by_thumbposition(string name, uint32_t content_all, uint32_t content_shown);

/*jdoc
{"params":["The control name.","The number of all content.","The number of always shown content."],
"desc":"This function returns the number of pixels required to change the scrollbar's position by a <i>step</i>, using the provided content information. A <i>step</i> is the number of pixels needed to modify the scrollbar's position by one <i>unit</i>, as it's defined by the abstract content information.<br/>Having the number of pixels, a call to [J3D_gui_scrollbar_set_thumbposition] is what is needed to update from current position, using the pixel mode.",
"return":"The number of pixels required."}*/
double J3D_gui_scrollbar_get_pixels_step(string name, uint32_t content_all, uint32_t content_shown);

/*jdoc
{"params":["The container name.","The control name.","The screen position, in X-axis.","The screen position, in Y-axis.","(optional) The rendering scale, by default is <b>1.0f</b> (original size)."],
"desc":"This function creates a gui checkbox. A <i>checkbox</i> is a gui control that provides typically a box for the users to check/uncheck a choice, triggering events through [J3D_callback_gui] function.",
"return":"<i>TRUE</i> on success"}*/
bool J3D_gui_checkbox_create(string containername, string name, int32_t x, int32_t y, float scale = 1.0f);

/*jdoc
{"params":["The control name."],
"desc":"This function returns the object of a created gui checkbox.",
"return":"The gui checkbox object or NULL if there's no gui control with the given <i>name<i>"}*/
J3D_GUICONTROL_CHECKBOX* J3D_gui_checkbox_get(string name);

/*jdoc
{"params":["The control name."],
"desc":"This function returns the state of a created gui checkbox.",
"return":"The checkbox state, <i>TRUE</i> if checked"}*/
bool J3D_gui_checkbox_get_state(string name);

/*jdoc
{"params":["The control name.","The checkbox state, <i>TRUE</i> for checked."],
"desc":"This function sets the state of a created gui checkbox.",
"return":"Nothing"}*/
void J3D_gui_checkbox_set_state(string name, bool checked);

/*jdoc
{"params":["The container name.","The control name.","The screen position, in X-axis.","The screen position, in Y-axis.","Width, in pixels.","The number of entries that always shown on screen.<br/><b>NOTE: </b>This is used to calculate the listbox's height, along with font size.","(optional) The rendering scale, by default is <b>1.0f</b> (original size)."],
"desc":"This function creates a gui listbox. A <i>listbox</i> is a gui control that provides a box for the users to select an entry (eg. files, custom lists), triggering events through [J3D_callback_gui] function.",
"return":"<i>TRUE</i> on success"}*/
bool J3D_gui_listbox_create(string containername, string name, int32_t x, int32_t y, int32_t width, int32_t numentriesshown, float scale = 1.0f);

/*jdoc
{"params":["The control name."],
"desc":"This function returns the object of a created gui listbox.",
"return":"The gui listbox object or NULL if there's no gui control with the given <i>name<i>"}*/
J3D_GUICONTROL_LISTBOX* J3D_gui_listbox_get(string name);

/*jdoc
{"params":["The control name.","The entry text.","The entry index.<br/>By default is <i>-1</i>, meaning the entry is inserted to the end of other entries. A positive number (yet smaller than number of all entries) will insert the entry in-between other entries, pushing them one position down.","(optional) The template id to use from <i>XML</i> file for rendering.<br/>The default ids are <i>entry</i> and <i>entry_selected</i>, defined in the XML file.<br/>If a template id is provided here, then another group of ids should be set in XML file, as <i>entry_templateid</i> and <i>entry_selected_templateid</i>, respectively.<br/>In this case, the gui system will use these render ids rather the default ones, providing a way to customize every entry.","(optional) The custom data to set for entry."],
"desc":"This function adds an <i>entry</i> to a gui listbox. An <i>entry</i> is simply a text fragment that can be selected through clicking.",
"return":"Nothing"}*/
void J3D_gui_listbox_add_entry(string name, string text, int32_t index = -1, string templateid = "", void* data = NULL);

/*jdoc
{"params":["The control name.","The numeric index of the entry.","The returned text of the entry.","The returned custom data of the entry."],
"desc":"This function retrieves an <i>entry</i> of a gui listbox.",
"return":"Nothing"}*/
void J3D_gui_listbox_get_entry(string name, int32_t index, string& text, void*& data);

/*jdoc
{"params":["The control name.","The entry index.<br/>By default is <i>-1</i>, meaning the entry to remove is the last one. A positive number (yet smaller than number of all entries) will remove the entry in-between other entries, pulling them one position up."],
"desc":"This function deletes an <i>entry</i> from a gui listbox.",
"return":"Nothing"}*/
void J3D_gui_listbox_delete_entry(string name, int32_t index = -1);

/*jdoc
{"params":["The control name."],
"desc":"This function deletes all <i>entries</i> from a gui listbox.",
"return":"Nothing"}*/
void J3D_gui_listbox_delete_all_entries(string name);

/*jdoc
{"params":["The control name.","The entry index.<br/><b>NOTE: </b>An index of <i>-1</i> deselects the currently selected listbox entry."],
"desc":"This function defines an <i>entry</i> of a gui listbox as the selected entry. A <i>selected entry</i> have a specific appearance (usually, it's highlighted), as defined in XML file.",
"return":"Nothing"}*/
void J3D_gui_listbox_set_selected_entry(string name, int32_t index);

/*jdoc
{"params":["The control name.","The text of the selected entry.","The numeric index of the selected entry.","The <i>optional</i> custom data of the selected entry."],
"desc":"This function retrieves the <i>selected entry</i> of a gui listbox.",
"return":"Nothing"}*/
void J3D_gui_listbox_get_selected_entry(string name, string& text, int32_t& index, void*& data);

/*jdoc
{"params":["The control name.","The entry text."],
"desc":"This function checks if the provided text exists as a listbox entry.",
"return":"<i>TRUE</i> if the specified text exists."}*/
bool J3D_gui_listbox_entry_text_exists(string name, string text);

/*jdoc
{"params":["The container name.","The control name.","The screen position, in X-axis.","The screen position, in Y-axis.","The dropbox button title.","(optional) If <i>TRUE</i> the dropbox button title will be changed to selected entry.<br/>In this case a blank text will be used instead of the specified <i>title</i>.","(optional) The dropbox width.<br/>By default is <b>-1</b>, meaning the width is calculated by title's width.", "(optional) The rendering scale, by default is <b>1.0f</b> (original size)."],
"desc":"This function creates a gui dropbox. A <i>dropbox</i> is a gui control that displays a box (after the dropbox button click) for the users to select an entry (eg. files, custom lists), triggering events through [J3D_callback_gui] function.",
"return":"<i>TRUE</i> on success"}*/
bool J3D_gui_dropbox_create(string containername, string name, int32_t x, int32_t y, string title, bool title_as_selectedentry = false, int32_t width = -1, float scale = 1.0F);

/*jdoc
{"params":["The control name."],
"desc":"This function returns the object of a created gui dropbox.",
"return":"The gui dropbox object or NULL if there's no gui control with the given <i>name<i>"}*/
J3D_GUICONTROL_DROPBOX* J3D_gui_dropbox_get(string name);

/*jdoc
{"params":["The control name.","The entry text.","The entry index.<br/>By default is <i>-1</i>, meaning the entry is inserted to the end of other entries. A positive number (yet smaller than number of all entries) will insert the entry in-between other entries, pushing them one position down.","(optional) The template id to use from <i>XML</i> file for rendering.<br/>The default ids are <i>entry</i> and <i>entry_selected</i>, defined in the XML file.<br/>If a template id is provided here, then another group of ids should be set in XML file, as <i>entry_templateid</i> and <i>entry_selected_templateid</i>, respectively.<br/>In this case, the gui system will use these render ids rather the default ones, providing a way to customize every entry.","(optional) The custom data to set for entry."],
"desc":"This function adds an <i>entry</i> to a gui dropbox. An <i>entry</i> is simply a text fragment that can be selected through clicking.",
"return":"Nothing"}*/
void J3D_gui_dropbox_add_entry(string name, string text, int32_t index = -1, string templateid = "", void* data = NULL);

/*jdoc
{"params":["The control name.","The numeric index of the entry.","The returned text of the entry.","The returned custom data of the entry."],
"desc":"This function retrieves an <i>entry</i> of a gui dropbox.",
"return":"Nothing"}*/
void J3D_gui_dropbox_get_entry(string name, int32_t index, string& text, void*& data);

/*jdoc
{"params":["The control name.","The entry index.<br/>By default is <i>-1</i>, meaning the entry to remove is the last one. A positive number (yet smaller than number of all entries) will remove the entry in-between other entries, pulling them one position up."],
"desc":"This function deletes an <i>entry</i> from a gui dropbox.",
"return":"Nothing"}*/
void J3D_gui_dropbox_delete_entry(string name, int32_t index);

/*jdoc
{"params":["The control name."],
"desc":"This function deletes all <i>entries</i> from a gui dropbox.",
"return":"Nothing"}*/
void J3D_gui_dropbox_delete_all_entries(string name);

/*jdoc
{"params":["The control name.","The entry index.<br/><b>NOTE: </b>An index of <i>-1</i> deselects the currently selected dropbox entry."],
"desc":"This function defines an <i>entry</i> of a gui dropbox as the selected entry.<br/><b>NOTE: </b>Useful if the dropbox has been created with <i>title_as_selectedentry</i> set to <b>TRUE</b> and therefore will show the selected entry.",
"return":"Nothing"}*/
void J3D_gui_dropbox_set_selected_entry(string name, int32_t index);

/*jdoc
{"params":["The control name.","The text of the selected entry.","The numeric index of the selected entry.","The <i>optional</i> custom data of the selected entry."],
"desc":"This function retrieves the <i>selected entry</i> of a gui dropbox.",
"return":"Nothing"}*/
void J3D_gui_dropbox_get_selected_entry(string name, string& text, int32_t& index, void*& data);

/*jdoc
{"params":["The control name.","The entry text."],
"desc":"This function checks if the provided text exists as a dropbox entry.",
"return":"<i>TRUE</i> if the specified text exists."}*/
bool J3D_gui_dropbox_entry_text_exists(string name, string text);

/*jdoc
{"params":["The container name.","The control name","The screen position, in X-axis.","The screen position, in Y-axis.","Width, in pixels.","(optional) Text, as string.","(optional) The rendering scale, by default is <b>1.0f</b> (original size)."],
"desc":"This function creates a gui editbox. An <i>editbox</i> is a gui control that can take keyboard data, triggering events through [J3D_callback_gui] function.",
"return":"<i>TRUE</i> on success"}*/
bool J3D_gui_editbox_create(string containername, string name, int32_t x, int32_t y, int32_t width, string text = "", float scale = 1.0f);

/*jdoc
{"params":["The control name.","The text."],
"desc":"This function sets the text of a gui editbox control.",
"return":"Nothing"}*/
void J3D_gui_editbox_set_text(string name, string text);

/*jdoc
{"params":["The control name."],
"desc":"This function retrieves the text from a gui editbox control.",
"return":"The editbox text"}*/
string J3D_gui_editbox_get_text(string name);

// buffer ////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Buffer",
"params":["The buffer compression state.<br/><b>NOTE: </b>By default, it's disabled."],
"desc":"This function enables the buffer compression. A <i>buffer</i> is simply the raw data for any loaded geometry; <i>models and terrains</i> are such geometries. This data is stored in <i>RAM</i> so to allow future <b>read/write</b> operations, for example <i>computing normals</i> for a buffer.<br/>The memory taken by storing this data for all geometries can be pretty large, so this can be solved by <i>compressing and decompressing</i> the data when it's appropriate, with minimal performance hit.<br/><b>NOTE: </b>Obviously, this creates another problem; the geometry data is duplicated, one used by <i>OpenGL</i> for rendering, and another for manipulation. This is because some devices simply <b>does not support</b> reading from vertex buffers (VRAM) once they were feed, so putting them simply in RAM is the most portable solution.<br/>Finally, note that compression mechanism is only supported for [J3D_buffer_fill] function.",
"return":"Nothing"}*/
void J3D_buffer_compression(bool enable);

/*jdoc
{"params":["The buffer.","The shader attribute name, see [Vertex attributes].","The data size, in number of <i>floats</i> (not bytes).<br/>For example, if you provide some <i>data</i> of 5 floats, you just specify 5 here.","The data itself, as an array of floats.<br/>Note that all attributes have a <i>default</i> number of floats per element. For example, to properly provide a vertex position to feed <b>J3D_ATTR_VERTEXPOSITION</b> attribute, you need to provide <i>3 floats</i> per element (position).","The <i>OpenGL</i> usage hint, see [Draw usage].","(optional) By default this function will make both a CPU and GPU copy, see [Buffer filling methods].<br/><b>NOTE: </b>A CPU copy allows the buffer to be manipulated while a GPU copy is only used for rendering."],
"desc":"This function fills a buffer with data for a specific <i>shader attribute</i>.<br/>Buffers can contain different <i>attributes</i> of data, which are specific for each shader; For example, <i>vertex positions, vertex normals or vertex colors</i> are just few of them.<br/>To properly <i>fill a buffer</i>, one has to provide all required data for <i>all used attributes</i> in the shader, meaning several calls of this function for all attributes in the shader.<br/><b>NOTE:</b> This function makes use of compression capability, offered by [J3D_buffer_compression].",
"return":"Nothing"}*/
void J3D_buffer_fill(J3D_BUFFER* b, string attr_name, uint32_t datasize, const float* data, unsigned int usage = J3D_DRAW_USAGE_STATIC_DRAW, int32_t method = J3D_BF_COPYBOTH);

/*jdoc
{"params":["The <i>OpenGL</i> vertex buffer object.<br/><b>NOTE:</b> You need to pass an <i>array of VBOs</i> here; A size of <i>10</i> is considered enough.<br/>The system will then choose one of them to store the data, based on attribute.","The shader attribute name, see [Vertex attributes].","The data size, in number of <i>floats</i> (not bytes).<br/>For example, if you provide some <i>data</i> of 5 floats, you just specify 5 here.","The data itself, as an array of floats.<br/>Note that all attributes have a <i>default</i> number of floats per element. For example, to properly provide a vertex position to feed <b>J3D_ATTR_VERTEXPOSITION</b> attribute, you need to provide <i>3 floats</i> per element (position).","The <i>OpenGL</i> usage hint, see [Draw usage]."],
"desc":"This function fills a <i>vertex buffer object</i> (vbo) with data for a specific <i>shader attribute</i>.<br/><b>NOTE:</b> This function <i>does not</i> make any use of compression capability, since you directly write to an <i>OpenGL</i> vertex buffer with intermediary buffers.",
"return":"Nothing"}*/
void J3D_buffer_fill_vbo(unsigned int* vbo, string attr_name, uint32_t datasize, const float* data, unsigned int usage = J3D_DRAW_USAGE_STATIC_DRAW);

/*jdoc
{"params":["The <i>OpenGL</i> vertex buffer object.<br/><b>NOTE:</b> You need to pass a filled <i>array of VBOs</i> here.<br/>The system will then choose the appropriate vbo, based on attribute.","The shader attribute name, see [Vertex attributes].","The number of components (eg. <i>floats</i>) per element.<br/>If left <i>unset</i> (-1), it will use the internal stored sizes (only for known attributes listed in <i>attr_name</i>). For custom attributes, one has to provide the correct number of floats per element."],
"desc":"This function binds a <i>vertex buffer object</i> (vbo) for a specific <i>shader attribute</i>.<br/><i>Binding</i> means we want to use a filled vbo for a specific <i>attribute</i>. It's the intermediary step after filling a vbo and before render it.",
"return":"Nothing"}*/
void J3D_buffer_bind(unsigned int* vbo, string attr_name, int components_size = -1);

/*jdoc
{"params":["The buffer.","The shader attribute name, see [Vertex attributes]."],
"desc":"This function retrieves the data size (as number of floats) for a specific <i>shader attribute</i>.",
"return":"The data size, as number of floats."}*/
int J3D_buffer_get_size(J3D_BUFFER* b, string attr_name);

/*jdoc
{"params":["The buffer.","The shader attribute name, see [Vertex attributes]."],
"desc":"This function retrieves the data (in a vector of floats) for a specific <i>shader attribute</i>.",
"return":"The data, as a vector of floats."}*/
vector<float> J3D_buffer_get_data(J3D_BUFFER* b, string attr_name);

/*jdoc
{"params":["The buffer.","The transformed bbox.","The matrix applied to buffer.<br/><b>NOTE: </b>If you want to use a <a href='http://glm.g-truc.net'><b>GLM</b></a> matrix, you just need to convert it first.<br/>A simple way to do it is the following:<div class='code'>glm::mat4x4 from_mat = ...;<br/>J3D_MAT4X4 to_mat;<br/>std::copy(&from_mat&#91;0]&#91;0], &from_mat&#91;0]&#91;0] + (4*4), &to_mat.mat&#91;0]&#91;0]);</div>"],
"desc":"This function transforms a <i>buffer</i> by a specific matrix, in <i>vertex level</i>.<br/>That means vertex positions and <i>normals</i> (eg. for lighting) gets transformed as well.<br/>Useful to <i>fix</i> models having wrong (in-file) orientation (eg. rotation, scaling), rather transforming them always in rendering loop.<br/>An example of transforming a <i>buffer</i> by a <i>matrix</i>, while updating the <i>bounding box</i>:<div class='code'>J3D_MODEL* m = J3D_model_get(<b>\"the_model\"</b>);<br/>J3D_transform_push();<br/>J3D_transform_scale( J3D_VEC3(0.02f,0.02f,0.02f) );<br/>J3D_MAT4X4 mat = J3D_transform_get();<br/>J3D_transform_pop();<br/>J3D_buffer_transform(&m->buffer, &m->bbox&#91;<b>\"the_object\"</b>], mat);</div>",
"return":"Nothing"}*/
void J3D_buffer_transform(J3D_BUFFER* b, J3D_BBOX* bbox, const J3D_MAT4X4& mat);

/*jdoc
{"params":["The buffer."],
"desc":"This function compute the <i>flat normals</i> for a <i>buffer</i>, in <i>vertex level</i>.<br/>This is also called <i>flat shading</i>, where each triangle uses one normal for lighting.<br/><b>NOTE: </b>Most models have their normals pre-computed. Use this function to re-compute normals in case of problematic cases (eg. wrong or not normals at all).",
"return":"Nothing"}*/
void J3D_buffer_compute_normals_flat(J3D_BUFFER* b);

// transform ///////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Transform",
"desc":"This function saves the <i>currently active camera orientation</i> so the next rendering objects can be further (and <i>correctly</i>) transformed, using the current camera orientation.<br/>This function should always precede any other transform calls, to set the basis of all calculations.<br/>An example of rendering an object, using <i>push/pop</i>:<div class='code'>J3D_transform_push();<br/>J3D_transform_translate(J3D_VEC3(0,0,0));<br/>J3D_transform();<br/>J3D_model_draw(<b>\"model\"</b>);<br/>J3D_transform_pop();</div>where <i>model</i> string is your model name.<br/><b>NOTE: </b>An <i>active camera</i> is required before calling.",
"return":"<i>TRUE</i> if the operation executed successfully."}*/
bool J3D_transform_push();

/*jdoc
{"desc":"This function restores the <i>currently active camera orientation</i> to let other rendering objects to be rendered with a new basis (see [J3D_transform_push]).<br/>This function should always be the last of other transform and rendering calls to finalize the calculations.<br/><b>NOTE: </b>An <i>active camera</i> is required before calling.",
"return":"<i>TRUE</i> if the operation executed successfully."}*/
bool J3D_transform_pop();

/*jdoc
{"desc":"This function executes all transformations and sends them all to <i>current shader</i>.<br/>This function should be called after all transformations and should always<br/>be the last before the actual drawing. Check [J3D_transform_push] for a concrete example.<br/><b>NOTE: </b>An <i>active camera</i> is required before calling.",
"return":"<i>TRUE</i> if the operation executed successfully."}*/
bool J3D_transform();

/*jdoc
{"params":["The 3D position to move"],
"desc":"This function <i>moves</i> the next rendering objects to specified <i>3D position</i>.<br/>It must always be called between [J3D_transform_push] and [J3D_transform_pop].<br/><b>NOTE: </b>An <i>active camera</i> is required before calling.",
"return":"<i>TRUE</i> if the operation executed successfully."}*/
bool J3D_transform_translate(J3D_VEC3 pos = J3D_VEC3(0.0f,0.0f,0.0f));

/*jdoc
{"params":["The axes to scale"],
"desc":"This function <i>scales</i> (or resize) the next rendering objects to specified <i>axes</i>.<br/>It must always be called between [J3D_transform_push] and [J3D_transform_pop].<br/><b>NOTE: </b>An <i>active camera</i> is required before calling.",
"return":"<i>TRUE</i> if the operation executed successfully."}*/
bool J3D_transform_scale(J3D_VEC3 scale = J3D_VEC3(1.0f,1.0f,1.0f));

/*jdoc
{"params":["The degrees (0 to 360) to rotate in X-axis"],
"desc":"This function <i>rotates</i> the next rendering objects to specified <i>axis</i>.<br/>It must always be called between [J3D_transform_push] and [J3D_transform_pop].<br/><b>NOTE: </b>An <i>active camera</i> is required before calling.",
"return":"<i>TRUE</i> if the operation executed successfully."}*/
bool J3D_transform_rotateX(uint16_t degrees = 0);

/*jdoc
{"params":["The degrees (0 to 360) to rotate in Y-axis"],
"desc":"This function <i>rotates</i> the next rendering objects to specified <i>axis</i>.<br/>It must always be called between [J3D_transform_push] and [J3D_transform_pop].<br/><b>NOTE: </b>An <i>active camera</i> is required before calling.",
"return":"<i>TRUE</i> if the operation executed successfully."}*/
bool J3D_transform_rotateY(uint16_t degrees = 0);

/*jdoc
{"params":["The degrees (0 to 360) to rotate in Z-axis"],
"desc":"This function <i>rotates</i> the next rendering objects to specified <i>axis</i>.<br/>It must always be called between [J3D_transform_push] and [J3D_transform_pop].<br/><b>NOTE: </b>An <i>active camera</i> is required before calling.",
"return":"<i>TRUE</i> if the operation executed successfully."}*/
bool J3D_transform_rotateZ(uint16_t degrees = 0);

/*jdoc
{"params":["The matrix to apply to current transformation matrix.<br/><b>NOTE: </b>If you want to use a <a href='http://glm.g-truc.net'><b>GLM</b></a> matrix, you just need to convert it first.<br/>A simple way to do it is the following:<div class='code'>glm::mat4x4 from_mat = ...;<br/>J3D_MAT4X4 to_mat;<br/>std::copy(&from_mat&#91;0]&#91;0], &from_mat&#91;0]&#91;0] + (4*4), &to_mat.mat&#91;0]&#91;0]);</div>"],
"desc":"This function <i>applies</i> (or multiplies) the specified matrix to current transformation matrix.<br/>It must always be called between [J3D_transform_push] and [J3D_transform_pop].<br/><b>NOTE: </b>An <i>active camera</i> is required before calling.",
"return":"<i>TRUE</i> if the operation executed successfully."}*/
bool J3D_transform_matrix(const J3D_MAT4X4& m);

/*jdoc
{"desc":"This function <i>retrieves</i> the current transformation matrix for the object.<br/>It must be always called after [J3D_transform_push] since it resets it.<br/>Calling the transformation functions builds the matrix dynamically.<br/><b>NOTE: </b>An <i>active camera</i> is required before calling.",
"return":"The current transformation matrix for the object"}*/
J3D_MAT4X4 J3D_transform_get();

// model ////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Model",
"params":["The model name.","The position of first vertex.","The position of second vertex.","The position of third vertex.","Color","Opacity (with 100 being fully opaque)"],
"desc":"This function creates the model of a <i>triangle</i>.",
"return":"Nothing"}*/
void J3D_model_create_triangle(string name, J3D_VEC3 v1, J3D_VEC3 v2, J3D_VEC3 v3, J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100);

/*jdoc
{"params":["The model name.","The model size.","Facing, see [Model quad facing]","Color","Opacity (with 100 being fully opaque)","(optional) The texture name.","The pixel coordinates to use for the provided texture.<br/>For example, pixel coordinates of <i>J3D_RECT(32,32,96,96)</i> will \"slice\" a texture square from <i>32x32 to 96x96</i>, resulting in a texture <i>fragment</i> of 64x64 pixels.<br/><b>NOTE: </b>Used only if a valid <i>texturename</i> has been provided."],
"desc":"This function creates the model of a <i>quad</i>.<br/>A <i>quad</i> is just 2 triangles, formed in such a way, they look like a 3D-square (or quad).",
"return":"Nothing"}*/
void J3D_model_create_quad(string name, J3D_VEC2 size = J3D_VEC2(1.0f,1.0f), uint8_t facing = J3D_MODEL_QUAD_FACING_ZAXIS, J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100, string texturename = "", J3D_RECT pixelcoords = J3D_RECT());

/*jdoc
{"params":["The model name.","The model size.","Facing, see [Model cube facing]","Color","Opacity (with 100 being fully opaque)","(optional) The texture names, one per side.<br/>The texture order is the following: <i>front, back, left, right, up, down</i>.<br/><b>NOTE: </b>If left blank, a white texture will be used instead.","The pixel coordinates to use for the provided texture(s).<br/>The pixelcoords order is the following: <i>front, back, left, right, up, down</i>.<br/>For example, pixel coordinates of <i>J3D_RECT(32,32,96,96)</i> will \"slice\" a texture square from <i>32x32 to 96x96</i>, resulting in a texture <i>fragment</i> of 64x64 pixels."],
"desc":"This function creates the model of a <i>cube</i>.",
"return":"Nothing"}*/
void J3D_model_create_cube(string name, J3D_VEC3 size = J3D_VEC3(1.0f,1.0f,1.0f), uint8_t facing = J3D_MODEL_CUBE_FACING_FRONT, J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100, vector<string> texture = vector<string>(6), vector<J3D_RECT> pixelcoords = vector<J3D_RECT>(6));

/*jdoc
{"params":["The model name.","The model size.","Up-left model incremental position, in XY-axes.<br/><b>NOTE: </b>This will modify the resulted trapezoid position <i>incrementally</i>, not absolutely.<br/>If left to zero, the result will be a perfect cube.","Up-right model incremental position, in XY-axes.","Down-right model incremental position, in XY-axes.","Down-left model incremental position, in XY-axes.","Color","Opacity (with 100 being fully opaque)","(optional) The texture names, one per side.<br/>The texture order is the following: <i>front, back, left, right, up, down</i>.<br/><b>NOTE: </b>If left blank, a white texture will be used instead.","The pixel coordinates to use for the provided texture(s).<br/>The pixelcoords order is the following: <i>front, back, left, right, up, down</i>.<br/>For example, pixel coordinates of <i>J3D_RECT(32,32,96,96)</i> will \"slice\" a texture square from <i>32x32 to 96x96</i>, resulting in a texture <i>fragment</i> of 64x64 pixels."],
"desc":"This function creates the model of a <i>trapezoid</i> i.e. a non-symmetrical cube.",
"return":"Nothing"}*/
void J3D_model_create_trapezoid(string name, J3D_VEC3 size = J3D_VEC3(1.0f,1.0f,1.0f), J3D_VEC2 ul_mod = J3D_VEC2(0.0f,0.0f), J3D_VEC2 ur_mod = J3D_VEC2(0.0f,0.0f), J3D_VEC2 dr_mod = J3D_VEC2(0.0f,0.0f), J3D_VEC2 dl_mod = J3D_VEC2(0.0f,0.0f), J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100, vector<string> texture = vector<string>(6), vector<J3D_RECT> pixelcoords = vector<J3D_RECT>(6));

/*jdoc
{"params":["The model name.","The texture folder where <i>skybox textures</i> are located.<br/><b>NOTE: </b>If left blank, <i>fromdata</i> will be used.<br/><br/>Skybox textures are always <b>six (6)</b> in number (one for each side), with the following predefined names:<br/><b><ul><li>front.jpg</li><li>back.jpg</li><li>up.jpg</li><li>down.jpg</li><li>left.jpg</li><li>right.jpg</li></ul></b>","(optional) The skybox textures data, as a <i>vector</i> of strings.<br/><b>NOTE: </b>The order is as defined on <i>fromfolder</i>.","The model size.","Color","Opacity (with 100 being fully opaque)","The texture filtering, see [Texture filters]","The mipmap texture filtering, see [Texture mip-mapping filters]."],
"desc":"This function creates the model of a <i>skybox</i>.<br/>A <i>skybox</i> are just over-sized cubes, textured with a predefined set of textures.<br/><b>NOTE: </b>In addition of providing a huge, centered cube, developers should also <i>move</i> the skybox by camera position, and also keeping it <b>unlit</b>.",
"return":"Nothing"}*/
void J3D_model_create_skybox(string name, string fromfolder, const vector<string>& fromdata = vector<string>(), J3D_VEC3 size = J3D_VEC3(10000.0f,10000.0f,10000.0f), J3D_COLOR color = J3D_COLOR(255,255,255), uint8_t opacity = 100, uint16_t texturefilter = J3D_TEXTURE_FILTER_LINEAR, uint16_t texturefilter_mipmap = J3D_TEXTURE_MIPMAP_FILTER_LINEAR);

/*jdoc
{"params":["The model name.","The model size.<br/><b>NOTE: </b>This is not the absolute size, since <i>quadsize</i> dictates how big should be each quad. Therefore <i>areasize * quadsize</i> defines the absolute size of the liquid area, on each axis.","The quad size.<br/>The liquid area is divided into smaller quads, each one having a fixed size. Bigger values <i>stretch</i> the used texture but require smaller quads to cover large areas.","The texture filename to load and use as the liquid texture.<br/>See [J3D_texture_load] for the supported formats.","The texture filtering, see [Texture filters]","The mipmap texture filtering, see [Texture mip-mapping filters]."],
"desc":"This function creates the model of a flat <i>liquid</i> area, using a specific texture.<br/>In addition, a <i>liquid shader</i> is then applied to the whole model to give the impression of a liquid area.<br/><b>NOTE: </b>The only restriction is that developers must use a <i>seamless</i> texture for this to work. The reason is because of the <i>squared</i> nature of the liquid area; every quad is placed next to previous, horizontally and vertically. In addition, all textures in the liquid area are animated and \"collide\" with the neighboring quads. Only a <i>seamless</i> texture will make it look <i>one body</i> rather many quads of the same texture.",
"return":"Nothing"}*/
void J3D_model_create_liquid(string name, J3D_POINT areasize, J3D_VEC2 quadsize, string texturefilename, uint16_t texturefilter = J3D_TEXTURE_FILTER_LINEAR, uint16_t texturefilter_mipmap = J3D_TEXTURE_MIPMAP_FILTER_LINEAR);

/*jdoc
{"params":["The model name.","The model filename.<br/><b>NOTE: </b>If left blank, <i>fromdata</i> will be used.","(optional) The model data, as a string.<br/><b>NOTE: </b>In this case, textures are not loaded since a folder is not given and its assumed that textures has to be loaded from data as well. The solution is to load the textures by hand. For this, the developer has to enable debugging before loading the model using [J3D_log_debug] and read the texture names and filenames set by the call. Finally, he needs to load the textures by using the <b>exact</b> texture names, allowing the reading of textures from <i>*any*</i> source.","The texture filtering, see [Texture filters]","The mipmap texture filtering, see [Texture mip-mapping filters].","(optional) The material files used by the model, ordered by filename and data.<br/><b>NOTE: </b>Used only when <i>fromdata</i> is provided. In this case, all resources including material files have to be read from data. <i>Material files</i> can be found on logged file, after a call to [J3D_log_debug] function. Read more on <i>fromdata</i> parameter."],
"desc":"This function loads a model file from disk.<br/>Supported formats can be found on [Model formats].",
"return":"Nothing"}*/
void J3D_model_load(string name, string fromfile = "", string fromdata = "", uint16_t texturefilter = J3D_TEXTURE_FILTER_LINEAR, uint16_t texturefilter_mipmap = J3D_TEXTURE_MIPMAP_FILTER_LINEAR, map<string,string>* material_files = NULL);

/*jdoc
{"params":["The model filename.","The positions vector.","The normals vector.","The texture coordinations vector.","The texture filename.<br/><b>NOTE: </b>Only if <i>texcoords</i> vector was provided."],
"desc":"This function creates an .OBJ (Wavefront object) model file from the specified vectors.<br/><b>NOTE: </b>Only the positions vector is mandatory.",
"return":"Nothing"}*/
void J3D_model_save_byarrays(string filename, vector<float> positions, vector<float> normals = vector<float>(), vector<float> texcoords = vector<float>(), string texture_filename = "");

/*jdoc
{"params":["The model name.","The model object (optional).<br/>If left blank, all model's objects will be drawn.","The model segment (optional).<br/>If left blank, all object's segments will be drawn.","(optional) The vertex attributes to bind.<br/>For example, a model may be rendered without normals, even if it has.<br/><b>NOTE: </b>By default all attributes are bound, see [Bound vertex attributes]"],
"desc":"This function renders a loaded model to screen.<br/> A model consists of one or several <i>objects</i>, each of which have one or several <i>segments</i>.<br/><i>Objects</i> are just a user-defined grouping of data that could be <i>rendered on their own</i> (the main idea). <i>Segments</i>, on the other hand, have a significant role on rendering, since they're used to render data with the <i>same texture</i>, in the most optimized way.<br/><br/><b>NOTE: </b>On models that have transparent textures, depth issues will be presented on transparent parts. In this case use [J3D_model_set_depthwrite] to <i>disable depth writing</i>. However, this will require to draw models in <i>back-to-front</i> order because of the disabled depth buffer. This is generally an <i>OpenGL</i> issue.<br/><br/><b>NOTE: </b><i>Jolt3D!</i> defines <i>objects</i> in a different way per model type.<ul><li>For <i>.OBJ</i> models, the engine defines a single object (named <b>\"obj\"</b>)</li><li>For <i>.DAE</i>, the engine defines as many objects as <i>geometries</i> in the model.</li></ul>The <i>segments</i> are simply the material names for both model types.",
"return":"The rendering state, specifically the following codes:<br/><ul><li><b>-1</b> = An error occured and nothing was drawn.</li><li><b>&nbsp;0</b> = No objects were drawn, either by draw distance or viewing frustum.</li><li><b>&nbsp;1</b> = Some objects were drawn, others were skipped by draw manager.</li><li><b>&nbsp;2</b> = All objects were drawn.</li></ul>"}*/
int32_t J3D_model_draw(string name, string object = "", string segment = "", uint32_t attributes = J3D_ATTR_ALL_BOUND);

/*jdoc
{"desc":"This function returns the drawing distance, see [J3D_model_set_drawdistance] for a decription of the draw distance mechanism.",
"return":"The draw distance as a <i>float</i>.<br/><b>NOTE: </b>A value of 0 indicates that draw distance mechanism is disabled."}*/
float J3D_model_get_drawdistance();

/*jdoc
{"params":["The draw distance.<br/><b>NOTE: </b>A value of <i>0</i> (default) essentially disables the mechanism."],
"desc":"This function provides a simple and efficient <i>draw distance</i> mechanism.<br/>Specifically, all models that exist on observable <a href='https://en.wikipedia.org/wiki/Viewing_frustum'>View frustum</a> will be rendered normally,<br>provided they're also closer to camera than specified <i>distance</i><br/>Objects that are outside of <i>View frustum</i> or more distant than our <i>distance</i><br/>will be excluded from rendering phase, increasing the performance on populated scenes.",
"return":"Nothing"}*/
void J3D_model_set_drawdistance(float distance);

/*jdoc
{"desc":"This function returns the global <a href='https://www.khronos.org/opengl/wiki/Face_Culling'>face culling</a> state.",
"return":"The face culling state"}*/
bool J3D_model_get_faceculling();

/*jdoc
{"params":["The face culling state. If set to <i>TRUE</i>, then only one face (side) of triangle will be visible, otherwise both sides will be visible.<br/><b>NOTE: </b>By default the face culling is enabled."],
"desc":"This function sets the global face culling for all model drawings. The <i>face culling</i> defines which face of triangles will be drawn <i>if enabled</i>, otherwise both sides are drawn, regardless camera placement.",
"return":"Nothing"}*/
void J3D_model_set_faceculling(bool enable);

/*jdoc
{"desc":"This function returns the global <a href='https://www.khronos.org/opengl/wiki/Write_Mask'>depth writing</a> state.",
"return":"The depth writing state"}*/
bool J3D_model_get_depthwrite();

/*jdoc
{"params":["The depth state. If set to <i>TRUE</i>, the depth mechanism will be enabled.<br/><b>NOTE: </b>By default the depth writing is enabled."],
"desc":"This function sets the global depth writing state. The <i>depth writing</i> enables the depth mechanism so that 3D objects will be drawn correctly, regardless the order you render them.",
"return":"None"}*/
void J3D_model_set_depthwrite(bool enable);

/*jdoc
{"params":["The model name."],
"desc":"This function returns the object of a created model.",
"return":"The model object or NULL if there's no model with the given <i>name<i>"}*/
J3D_MODEL* J3D_model_get(string name);

/*jdoc
{"params":["The model name."],
"desc":"This function releases a created model from the memory.<br/><b>NOTE:</b> This is optional since <i>Jolt3D!</i> releases all objects automatically.",
"return":"Nothing"}*/
void J3D_model_release(string name);

// terrain ////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Terrain",
"params":["The terrain name.","The terrain size, in <i>x/z</i> axes.<br/><b>NOTE: </b>Terrain system uses 8x8 grids for fast rendering, based on texture code. Therefore, the minimum terrain size should be <b>8x8</b>.","The quad size, in <i>x/z</i> axes.","(optional) If set to <i>TRUE</i>, it will reverse the normals for all future operations.<br/>Useful when the lighting is required on the other side of terrain i.e. ceilings.<br/><b>NOTE: </b>This is also preserved on future calls by [J3D_terrain_modify]"],
"desc":"This function creates the model of a <i>flat terrain</i>.<br/>A terrain can be further modified by <i>height</i> and <i>texturing.</i><br/><b>NOTE: </b>A texture code is added with <i>white</i> color and code of <i>INT_MAX</i>.<br/><b>NOTE 2: </b>A terrain is essentially a model, therefore the draw distance mechanism provided on [J3D_model_draw_distance] can be used.",
"return":"Nothing"}*/
void J3D_terrain_flat_create(string name, J3D_POINT terrainsize = J3D_POINT(32,32), J3D_VEC2 quadsize = J3D_VEC2(1.0f,1.0f), bool reversed_normals = false);

/*jdoc
{"params":["The terrain name.","The terrain size, in <i>x/z</i> axes.<br/><b>NOTE: </b>Terrain system uses 8x8 grids for fast rendering, based on texture code. Therefore, the minimum terrain size should be <b>8x8</b>.","The quad size, in <i>x/z</i> axes.","The 3D bounds for the terrain, in <i>minX, minY,maxX,maxY</i> format.<br/>Every <i>coherent-noise</i> generated terrain is infinite; this parameter is used to lock a region.<br/>In addition, this feature helps <i>connecting</i> terrains that generated with neighbouring bounds.","The height scaling is used to modify the output eg. making height taller or shorter.","A terrain will be saved to a colored <i>.bmp</i> file if this is <i>TRUE</i>.","(optional) If set to <i>TRUE</i>, it will reverse the normals for all future operations.<br/>Useful when the lighting is required on the other side of terrain i.e. ceilings.<br/><b>NOTE: </b>This is also preserved on future calls by [J3D_terrain_modify]"],
"desc":"This function creates the model of a simple, random <i>coherent-noise terrain</i>.<br/><i>Coherent noise</i> is a algorithm to produce pseudorandom, smooth and <i>infinite</i> noise, targeting terrain's geometry in this context.<br/>A terrain can be further modified by <i>height</i> and <i>texturing</i>.<br/><b>NOTE: </b>A texture code is added with <i>white</i> color and code of <i>INT_MAX</i>.",
"return":"Nothing"}*/
void J3D_terrain_noise_simple_create(string name, J3D_POINT terrainsize, J3D_VEC2 quadsize = J3D_VEC2(1.0f,1.0f), J3D_RECTF bounds = J3D_RECTF(0.0f,0.0f,5.0f,5.0f), float scaleheight = 20.0f, bool savetoimage = false, bool reversed_normals = false);

/*jdoc
{"params":["The terrain name.","The terrain size, in <i>x/z</i> axes.<br/><b>NOTE: </b>Terrain system uses 8x8 grids for fast rendering, based on texture code. Therefore, the minimum terrain size should be <b>8x8</b>.","The quad size, in <i>x/z</i> axes.","The 3D bounds for the terrain, in <i>minX, minY,maxX,maxY</i> format.<br/>Every <i>coherent-noise</i> generated terrain is infinite; this parameter is used to lock a region.<br/>In addition, this feature helps <i>connecting</i> terrains that generated with neighbouring bounds.","The height scaling is used to modify the output eg. making height taller or shorter.","A terrain will be saved to a colored <i>.bmp</i> file if this is <i>TRUE</i>.","(optional) If set to <i>TRUE</i>, it will reverse the normals for all future operations.<br/>Useful when the lighting is required on the other side of terrain i.e. ceilings.<br/><b>NOTE: </b>This is also preserved on future calls by [J3D_terrain_modify]"],
"desc":"This function creates the model of a ridged <i>coherent-noise terrain</i>.<br/><i>Coherent noise</i> is a algorithm to produce pseudorandom, smooth and <i>infinite</i> noise, targeting terrain's geometry in this context.<br/>A <i>ridged</i> coherent-noise algorithm produces vast flat terrain areas (eg. grassy or civilized areas), accompanied with realistic mountain ridges.<br/>A terrain can be further modified by <i>height</i> and <i>texturing</i>.<br/><b>NOTE: </b>A texture code is added with <i>white</i> color and code of <i>INT_MAX</i>.",
"return":"Nothing"}*/
void J3D_terrain_noise_ridged_create(string name, J3D_POINT terrainsize, J3D_VEC2 quadsize = J3D_VEC2(1.0f,1.0f), J3D_RECTF bounds = J3D_RECTF(0.0f,0.0f,5.0f,5.0f), float scaleheight = 30.0f, bool savetoimage = false, bool reversed_normals = false);

/*jdoc
{"params":["The terrain name.","The terrain filename.","The quad size, in <i>x/z</i> axes.","(optional) If set to <i>TRUE</i>, it will reverse the normals for all future operations.<br/>Useful when the lighting is required on the other side of terrain i.e. ceilings.<br/><b>NOTE: </b>This is also preserved on future calls by [J3D_terrain_modify]"],
"desc":"This function loads a terrain file to be used as a terrain.<br/>Supported formats are: <b>hff</b>.<br/><b>NOTE: </b>A texture code is added with <i>white</i> color and code of <i>INT_MAX</i>.",
"return":"Nothing"}*/
void J3D_terrain_create_from_file(string name, string filename, J3D_VEC2 quadsize = J3D_VEC2(1.0f,1.0f), bool reversed_normals = false);

/*jdoc
{"params":["The terrain name."],
"desc":"This function returns the object of a created terrain.",
"return":"The terrain object or NULL if there's no terrain with the given <i>name<i>."}*/
J3D_TERRAIN* J3D_terrain_get(string name);

/*jdoc
{"params":["The terrain name.","The quad to get, in <i>x/z</i> axes.<br/><b>NOTE: </b>y means z in this context.","(optional) The height for this quad.","(optional) The texture code for this quad."],
"desc":"This function returns a specific quad information of a created terrain.",
"return":"The terrain quad information"}*/
void J3D_terrain_get_quad(string name, J3D_POINT quad, float* height = NULL, int32_t* texturecode = NULL);

/*jdoc
{"params":["The terrain name.","The 3D position to convert from."],
"desc":"This function returns a 2D terrain quad position by the provided 3D position.<br/>If position is not above terrain, the border quad positions are returned.",
"return":"The 2D terrain quad position"}*/
J3D_POINT J3D_terrain_get_quad_by_pos(string name, J3D_VEC3 pos);

/*jdoc
{"params":["The terrain name.","The 2D terrain quad position to convert from.","(optional) The height for the resulting 3D vector.<br/><b>NOTE: </b>If left <b>FLT_MAX</b>, the quad height already set will be returned in y-axis."],
"desc":"This function returns a 3D terrain position by the provided 2D quad position.<br/>If position is not above terrain, the border 3D positions are returned.",
"return":"The 3D terrain position"}*/
J3D_VEC3 J3D_terrain_get_pos_by_quad(string name, J3D_POINT quad, float height = FLT_MAX);

/*jdoc
{"params":["The terrain name.","The name of a loaded texture to use.","The texture code to use for the combination of <i>texturename</i> and <i>pixelcoords</i>.","The pixelcoords to use from the provided <i>texturename</i>.<br/><b>NOTE: </b>If they left blank, the entire texture is used."],
"desc":"This function combines a texture and pixel coordinates into a common <i>texturecode</i>.<br/>A <i>texturecode</i> can then be used to texture directly specific quads / regions on the terrain, therefore quads are using <i>texture codes</i> rather simply a texture. It also allows creation of different texture codes for the same texture, each one having different pixel coordinates (tiling).",
"return":"Nothing"}*/
void J3D_terrain_add_texturecode(string name, string texturename, int32_t texturecode, J3D_RECT pixelcoords = J3D_RECT());

/*jdoc
{"params":["The terrain name.","The quad to modify, in <i>x/z</i> axes.<br/><b>NOTE: </b>y means z in this context.","The new height for the specified quad.<br/><b>NOTE: </b>By default is <b>FLT_MAX</b> which does not set a height.","The new texturecode for the specified quad.<br/><b>NOTE: </b>By default is <b>-1</b> which does not set a texture code."],
"desc":"This function modifies a terrain's quad by either <i>height, texturecode or both</i>.<br/><b>NOTE: </b>This function is intermediary; actual modification happens when you call [J3D_terrain_modify].",
"return":"Nothing"}*/
void J3D_terrain_modify_quad(string name, J3D_POINT quad, float height = FLT_MAX, int32_t texturecode = -1);

/*jdoc
{"params":["The terrain name.","The terrain's range to modify, in <i>minX, minY, maxX, maxY</i>.","The new height for the specified range.<br/><b>NOTE: </b>By default is <b>FLT_MAX</b> which does not set a height.","The new texturecode for the specified range.<br/><b>NOTE: </b>By default is <b>-1</b> which does not set a texture code.","(optional) A range of texcodes to be plotted randomly, using the provided percentages.<br/><b>NOTE: </b>This overrides the <i>texturecode</i> parameter."],
"desc":"This function modifies a terrain range by either <i>height, texturecode or both</i>.<br/><b>NOTE: </b>This function is intermediary; actual modification happens when you call [J3D_terrain_modify].",
"return":"Nothing"}*/
void J3D_terrain_modify_range(string name, J3D_RECT range, float height = FLT_MAX, int32_t texturecode = -1, vector<J3D_TERRAIN_TEXCODE>* texturecodes = NULL);

/*jdoc
{"params":["The terrain name.","By default <i>gouraud</i> shading (smooth) is used but <i>flat</i> shading will be used if <i>FALSE</i> is given."],
"desc":"This function modifies directly the terrain by executing all <b>J3D_terrain_modify_xxx</b> commands called previously.",
"return":"Nothing"}*/
void J3D_terrain_modify(string name, bool smoothNormals = true);

/*jdoc
{"params":["The terrain name."],
"desc":"This function releases a created terrain from the memory.<br/><b>NOTE:</b> This is optional since <i>Jolt3D!</i> releases all objects automatically.",
"return":"Nothing"}*/
void J3D_terrain_release(string name);

// camera ////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Camera",
"params":["The camera name.","The camera position, in <i>x/y/z</i> axes.","Yaw sets the camera rotation around the Y-axis, in degrees.","Pitch sets the camera rotation around the X-axis, in degrees.","The movement speed interval.","The yaw-pitch rotation speed.","(optional) The keymapping to use for the predefined camera moves.<br/>If left <b>blank</b>, the following <i>camera move</i> to <i>key mapping</i> will be set as follows:<div class='code'><b>J3D_CAMERA_MOVE_TURNUP</b> = J3D_KEY_PAGEUP<br/><b>J3D_CAMERA_MOVE_TURNDOWN</b> = J3D_KEY_PAGEDOWN<br/><b>J3D_CAMERA_MOVE_MOVEUP</b> = J3D_KEY_HOME<br/><b>J3D_CAMERA_MOVE_MOVEDOWN</b> = J3D_KEY_END<br/><b>J3D_CAMERA_MOVE_TURNLEFT</b> = J3D_KEY_LEFT or J3D_KEY_A<br/><b>J3D_CAMERA_MOVE_TURNRIGHT</b> = J3D_KEY_RIGHT or J3D_KEY_D<br/><b>J3D_CAMERA_MOVE_MOVEFORWARD</b> = J3D_KEY_UP or J3D_KEY_W<br/><b>J3D_CAMERA_MOVE_MOVEBACKWARD</b> = J3D_KEY_DOWN or J3D_KEY_S</div><b>NOTE: </b>If <i>move_keymapping</i> has an entry of <b>J3D_CAMERA_MOVE_DISABLED</b>, this will essentially <i>disable</i> the free camera movement by key combinations."],
"desc":"This function creates a camera from the provided input and should preceede other camera functions.<br/><b>NOTE: </b>This function merely sets the camera's position, orientation and movement abilities. It does not set the observable world, see [J3D_camera_set_perspective] for this. In addition, it's not active until you set it via [J3D_camera_set_active].<br/>An example of setting up a <i>world-centered</i>, without rotation camera that looks directly in front of you (negative -z axis):<div class='code'>J3D_camera_set(<b>\"camera\"</b>, J3D_VEC3(0,3.0f,0), 0, 0, 0.012f, 0.1f);<br/>J3D_camera_set_perspective(<b>\"camera\"</b>, 45.0f, 0.01f, 100000.0f);<br/>J3D_camera_set_active(<b>\"camera\"</b>);</div>",
"return":"Nothing"}*/
void J3D_camera_set(string name, J3D_VEC3 pos = J3D_VEC3(0,0,0), int16_t yaw = 0, int16_t pitch = 0, float speedInterval = 0.003f, float yawPitchInterval = 0.1f, map<int32_t,vector<int32_t> > move_keymapping = map<int32_t,vector<int32_t> >());

/*jdoc
{"params":["The camera name."],
"desc":"This function returns the object of a created camera.<br/><b>NOTE: </b>If left blank, the active camera (if exist) is retrieved.",
"return":"The camera object."}*/
J3D_CAMERA* J3D_camera_get(string name = "");

/*jdoc
{"params":["The camera name.","The <i>Field of View</i> for the camera.<br/>It's used to define the extent of the observable world.", "zNear is used to define the <i>starting</i> point of visibility, based on current camera's position.<br/>Typically, it's very close to <b>0.0</b>, which translates to current camera position.", "zFar is the opposite of zNear which defines the <i>ending</i> point of visibility, after of which nothing is rendered.<br/>Typically, it's a big number to allow good amount of visibility."],
"desc":"This function defines the perspective of a set camera.<br/><i>Perspective</i> is used to define the observable world.",
"return":"Nothing"}*/
void J3D_camera_set_perspective(string name, float fovY = 45.0f, float zNear = 0.01f, float zFar = 100.0f);

/*jdoc
{"params":["The camera name."],
"desc":"This function sets the <i>active</i> camera.<br/>This camera will be used for all incoming calculations eg. model placements or camera moving.",
"return":"Nothing"}*/
void J3D_camera_set_active(string name);

/*jdoc
{"desc":"This function returns the object of the active camera.",
"return":"The active camera object or NULL if there's no active camera."}*/
J3D_CAMERA* J3D_camera_get_active();

/*jdoc
{"params":["The first position","The second position"],
"desc":"This function computes the rotation angle (in degrees) between two 3D positions.",
"return":"The rotation degrees as an <i>integer</i>"}*/
int32_t J3D_camera_get_rotation_degrees_from_positions(J3D_VEC3 pos1, J3D_VEC3 pos2);

/*jdoc
{"params":["The method of moving the camera, see [Camera move]"],
"desc":"This function moves the active camera in a predefined way.",
"return":"Nothing."}*/
void J3D_camera_move(int32_t move);

// input ////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Input",
"params":["The key event, see [Key events].","The key, see [Key mapping].<br/><b>NOTE: </b>The Windows mapping is used on the guide for simplicity.<br/>Every platform has it's own implementation."],
"desc":"This function retrieves a key state, asynchronously ie.<br/>not just in the moment of happening and can be called anywhere.<br/>This is particulary useful in key pressing, where the pressing happens once but this function will always return TRUE since the pressing continues.<br/><b>NOTE: </b>This is simply an alternative, <i>non-callback</i> way to catch events, intended for games.",
"return":"<i>TRUE</i> if the specified <i>key</i> is under the provided <i>event</i>."}*/
bool J3D_input_get_async_key_state(int32_t event, int32_t key);

/*jdoc
{"params":["The key event, see [Key events].<br/><b>NOTE: </b>If there's no key event, <b>J3D_KEYEVENT_NONE</b> is set.","The key, see [Key mapping].<br/><b>NOTE: </b>If there's no key event, <b>J3D_KEY_NONE</b> is set.<br/><b>NOTE: </b>The Windows mapping is used on the guide for simplicity.<br/>Every platform has it's own implementation."],
"desc":"This function retrieves the latest key and its state, asynchronously.<br/><b>NOTE: </b>This is simply an alternative, <i>non-callback</i> way to catch events, intended for games.",
"return":"<i>TRUE</i> if there's a <i>key event</i> present at the moment."}*/
bool J3D_input_get_async_key_state_latest(int32_t& event, int32_t& key);

/*jdoc
{"params":["The key event, see [Key events].<br/><b>NOTE: </b>If there's no key event, <b>J3D_KEYEVENT_NONE</b> is set.","The key, see [Key mapping].<br/><b>NOTE: </b>If there's no key event, <b>J3D_KEY_NONE</b> is set.<br/><b>NOTE: </b>The Windows mapping is used on the guide for simplicity.<br/>Every platform has it's own implementation."],
"desc":"This function clears the latest asynchronous event, key and its state. If multiple combinations of <i>event</i> & <i>key</i> have been invoked, they will <i>all</i> be cleared.",
"return":"Nothing"}*/
void J3D_input_async_key_state_latest_clear(int32_t event, int32_t key);

/*jdoc
{"desc":"This function clears the entire list of latest asynchronous events, keys and their states.",
"return":"Nothing"}*/
void J3D_input_async_key_state_latest_clear_all();

/*jdoc
{"params":["The key, see [Key mapping].<br/><b>NOTE: </b>The Windows mapping is used on the guide for simplicity.<br/>Every platform has it's own implementation."],
"desc":"This function retrieves the key <i>delta</i> time, in other words the time (in milliseconds) where its current event started.<br/>For example, if that key has been pressed (initially) before <b>0.5</b> seconds and kept pressed until the time of this call, this time will be returned.",
"return":"The delta time, in <i>milliseconds</i>."}*/
uint32_t J3D_input_get_async_key_delta(int32_t key);

/*jdoc
{"params":["The key, see [Key mapping].<br/><b>NOTE: </b>The Windows mapping is used on the guide for simplicity.<br/>Every platform has it's own implementation.","(opt) The key modifiers to be used for triggering the event, see [Key modifiers].<br/><b>NOTE: </b>The Windows mapping is used on the guide for simplicity.<br/>Every platform has it's own implementation."],
"desc":"This function defines a <i>system-wide</i> key.<br/>The difference is that these keys will be triggered even when other 3rd applications have the focus.<br/><b>NOTE: </b>This feature is only supported on <i>Windows / Linux</i>, since other platforms either don't support it or requires specific system settings to be turned on.",
"return":"Nothing"}*/
void J3D_input_set_global_key(int32_t key, int32_t modifiers = J3D_KEY_MOD_NONE);

/*jdoc
{"params":["The key, see [Key mapping].<br/><b>NOTE: </b>The Windows mapping is used on the guide for simplicity.<br/>Every platform has it's own implementation."],
"desc":"This function unsets a previously set <i>system-wide</i> key.<br/><b>NOTE: </b>This feature is only supported on <i>Windows / Linux</i>, since other platforms either don't support it or requires specific system settings to be turned on.",
"return":"Nothing"}*/
void J3D_input_unset_global_key(int32_t key);

/*jdoc
{"params":["The mouse event, see [Mouse events].","The button, see [Mouse button mapping] or [Mouse wheel mapping].<br/><b>NOTE: </b>The Windows mapping is used on the guide for simplicity.<br/>Every platform has it's own implementation."],
"desc":"This function retrieves a mouse button (or touch on mobile platforms) state, asynchronously ie.<br/>not just in the moment of happening and call be called anywhere.<br/>This is particulary useful in mouse button pressing, where the pressing happens once but this function will always return TRUE since the pressing continues.<br/><b>NOTE: </b>This is simply an alternative, <i>non-callback</i> way to catch events, intended for games.<br/>An additional important note is that <i>mouse button</i> means also a finger touch on platforms interacting by touch ie. <i>android or iphone</i>.",
"return":"<i>TRUE</i> if the specified <i>mouse button</i> is under the provided <i>event</i>."}*/
bool J3D_input_get_async_mouse_state(int32_t event, int32_t button);

/*jdoc
{"params":["The mouse, see [Mouse button mapping] or [Mouse wheel mapping].<br/><b>NOTE: </b>The Windows mapping is used on the guide for simplicity.<br/>Every platform has it's own implementation."],
"desc":"This function retrieves the mouse button (or touch on mobile platforms) <i>delta</i> time,<br/> otherwise the time (in milliseconds) where its current event started.<br/>For example, if that mouse button has been pressed (initially) before <b>0.5</b> seconds and kept pressed until the time of this call, this time will be returned.",
"return":"The delta time, in <i>milliseconds</i>."}*/
uint32_t J3D_input_get_async_mouse_button_delta(int32_t button);

// files ////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Files",
"desc":"This function retrieves the current working folder.<br/>Typically, it's the folder with the <i>executable</i> but iy may change based on current platform for portability reasons. The following list shows the current directory by platform:<ul><li><b>Windows</b><br/>Same folder as the executable.</li><li><b>Linux</b><br/>Same folder as the binary.</li><li><b>Android</b><br/>Set to internal storage folder of application, where all resources will be decompressed from APK, when they're required.</li><li><b>OSX</b><br/>Set to <i>/Resources</i> subfolder in the bundle.</li><li><b>iOS</b><br/>Set to <i>/Documents</i> subfolder in the bundle.</li></ul>",
"return":"The current directory."}*/
string J3D_file_get_current_folder();

/*jdoc
{"params":["A <i>fullpath</i> can be either a folder path or a path with a filename."],
"desc":"This function retrieves only the <i>folder path</i> from a fullpath.<br/>Therefore, it simply truncates the filename from it, if one exists.",
"return":"The folder path."}*/
string J3D_file_get_folder(string fullpath);

/*jdoc
{"params":["A <i>fullpath</i> can be either a directory path or a path with a filename."],
"desc":"This function retrieves only the <i>filename</i> from a fullpath.<br/>Therefore, it simply truncates the entire directory path from it, if one exists.",
"return":"The filename."}*/
string J3D_file_get_file(string fullpath);

/*jdoc
{"params":["The filename.","(optional) The time of file's creation, as <a href='https://en.wikipedia.org/wiki/Unix_time'>unix timestamp</a>.","(optional) The time of file's last modification, as <i>unix timestamp</i>.","(optional) The time of file's last access, as <i>unix timestamp</i>."],
"desc":"This function retrieves various times of the specified file.<br/><b>NOTE: </b>One or more timer variables can be provided.",
"return":"Nothing"}*/
void J3D_file_get_time(string filename, double* create_time = NULL, double* modify_time = NULL, double* access_time = NULL);

/*jdoc
{"params":["A <i>fullpath</i> can be either a folder path or a path with a filename."],
"desc":"This function removes the <i>last folder</i> from a fullpath and return it.<br/><b>NOTE: </b>In case a filename exists in the fullpath, this function removes it as well.",
"return":"The fullpath without the last folder (without a possible filename as well)."}*/
string J3D_file_remove_last_folder(string fullpath);

/*jdoc
{"params":["The filename."],
"desc":"This function checks if the provided filename exists on disk.",
"return":"Returns <i>TRUE</i> if the file exists."}*/
bool J3D_file_exists(string filename);

/*jdoc
{"params":["The folder."],
"desc":"This function checks if the provided folder exists on disk.",
"return":"Returns <i>TRUE</i> if the folder exists."}*/
bool J3D_file_folder_exists(string folder);

/*jdoc
{"params":["The filename."],
"desc":"This function retrieves the file's extension.<br/>This is usually the last fragment after last period (.) symbol.",
"return":"The file's extension, if one exists."}*/
string J3D_file_get_extension(string filename);

/*jdoc
{"params":["The filename."],
"desc":"This function removes the file's extension and return the filename.<br/>This is usually the last fragment after last period (.) symbol.",
"return":"The filename without its extension."}*/
string J3D_file_remove_extension(string filename);

/*jdoc
{"params":["The filename.","The text to be written.<br/><b>NOTE: </b>Empty strings gets ignored! This is important because this function takes two (2) strings as input, one of which must be provided!","(optional) The unicode string to be written.<br/><b>NOTE: </b>Considered only if <i>text</i> is empty!","If <i>TRUE</i> (default), a new line will be inserted in the end of the text."],
"desc":"This function writes a string into a specific file.<br/>If the file already exists, it appends the string in the end of file.",
"return":"Nothing"}*/
void J3D_file_write(string filename, string text, wstring wtext = L"", bool newline = true);

/*jdoc
{"params":["The filename."],
"desc":"This function reads an entire file into string.",
"return":"The file's data."}*/
string J3D_file_read(string filename);

/*jdoc
{"params":["The folder.<br/><b>NOTE: </b>If left <i>blank</i>, the current directory will be used.","The list of folders.<br/><b>NOTE: </b>The list is cleared before the operation.","(optional) If <i>TRUE</i>, the <i>parent folder</i> will be appended in front of each folder.","(optional) If <i>TRUE</i>, the <i>subfolders</i> of each subfolder will be read recursively."],
"desc":"This function retrieves all folders and subfolders from a specific folder.",
"return":"Nothing"}*/
void J3D_file_get_folders_within_folder(const string& folder, vector<string>& folders, bool includeparentfolder = false, bool recursive = true);

/*jdoc
{"params":["The folder.<br/><b>NOTE: </b>If left <i>blank</i>, the current directory will be used.","If this is not blank, it only retrieves files containing <i>filefragment</i> in their name. Multiple fragments can be added by <b>comma</b> (,).<br/><b>NOTE: </b>File extensions are also part of the filename, for example <b>\".png\"</b> will retrieve all PNG files.","If this is not blank, it only retrieves files having this <i>extension</i>.<br/><b>NOTE: </b>Multiple extensions can be added by <b>comma</b> (,).","The list of files.<br/><b>NOTE: </b>The list is cleared before the operation.","The list of folders.<br/><b>NOTE: </b>The list is cleared before the operation.","(optional) If <i>TRUE</i>, the <i>folder</i> will be appended in front of each file.<br/><b>NOTE: </b>If set to <i>TRUE</i>, be sure that <i>folder</i> doesn't have an ending trailing slash."],
"desc":"This function retrieves all files and subfolders from a specific folder.",
"return":"Nothing"}*/
void J3D_file_get_files_within_folder(const string& folder, const string& filefragment, const string& extension, vector<string>& files, vector<string>& folders, bool includefolder = false);

/*jdoc
{"params":["The filepath.", "The folder to copy the file."],
"desc":"This function copies a specific file to a specific folder.",
"return":"Nothing"}*/
void J3D_file_copy(const string& filepath, const string& tofolder);

/*jdoc
{"params":["The filename."],
"desc":"This function deletes a specific file.",
"return":"Nothing"}*/
void J3D_file_delete(string filename);

/*jdoc
{"params":["The folder."],
"desc":"This function creates a folder on disk.",
"return":"Nothing"}*/
void J3D_file_folder_create(const string& folder);

/*jdoc
{"params":["The folder.", "The new folder to copy the folder contents.","If this is not blank, it only copies files containing <i>filefragment</i> in their name. Multiple fragments can be added by <b>comma</b> (,).<br/><b>NOTE: </b>File extensions are also part of the filename, for example <b>\".png\"</b> will copies all PNG files.","If this is not blank, it only copies files having this <i>extension</i>.<br/><b>NOTE: </b>Multiple extensions can be added by <b>comma</b> (,)."],
"desc":"This function copies a specific file to a specific folder.<br/><b>NOTE: </b>Subfolders of <i>folder</i> and their contents are copied as well.",
"return":"Nothing"}*/
void J3D_file_folder_copy(const string& folder, const string& newfolder, const string& filefragment, const string& extension);

/*jdoc
{"params":["The folder.","(optional) If <b>TRUE</b>, the parent folder will get deleted as well.","(optional) If <i>TRUE</i>, the <i>subfolders</i> of each subfolder will be deleted, recursively."],
"desc":"This function deletes a specific folder and its files and<br/>optionally their subfolders and files as well.",
"return":"Nothing"}*/
void J3D_file_folder_delete(const string& folder, bool delete_parentfolder = true, bool delete_subfolders = true);

/*jdoc
{"params":["The filename.<br/><b>NOTE: </b>If left blank, <i>fromdata</i> will be used."],
"desc":"This function identifies the format of the specified file or file data.<br/><b>NOTE: </b>The identification is performed by searching the <i>header bytes</i>.",
"return":"The format of the file, see [Image formats], [Audio formats] and [Model formats]"}*/
string J3D_file_identify_format(string fromfile, string fromdata = "");

/*jdoc
{"params":["The filename.<br/><b>NOTE: </b>If left blank, <i>file</i> handle will be used.","(optional) The file handle.<br/><b>NOTE: </b>It's used if <i>filename</i> is empty. A call to [J3D_file_open] is required."],
"desc":"This function returns the file size of the specified filename or file handle.",
"return":"The file size"}*/
int32_t J3D_file_size(string filename, J3D_FILE* file = NULL);

/*jdoc
{"params":["The file object.","The filename.<br><b>NOTE: </b>If left blank, <i>data</i> will be used.","The access type eg. <b>r</b> for reading, <b>w</b> for writing.</br/>Check here for a more <a href='http://www.cplusplus.com/reference/cstdio/fopen/'>detailed</a> guide.","(optional) The data to parse, as a string."],
"desc":"This function opens a file for <i>reading/writing</i> or a string data for <i>reading</i>.",
"return":"<i>TRUE</i> if the file / data has been successfully opened."}*/
bool J3D_file_open(J3D_FILE* file, string filename, string mode, string data = "");

/*jdoc
{"params":["The file object."],
"desc":"This function closes an opened file.",
"return":"Nothing."}*/
void J3D_file_close(J3D_FILE& file);

/*jdoc
{"params":["The file object.","The file position.","The method seeking to desired file position, see [File seeking methods]."],
"desc":"This function moves the file pointer of an opened file to a new position.",
"return":"Nothing."}*/
void J3D_file_seek(J3D_FILE& file, int32_t offset = 0, uint32_t origin = J3D_FS_SEEK_SET);

/*jdoc
{"params":["The file object."],
"desc":"This function returns the current file position of an opened file.",
"return":"The current file position."}*/
int32_t J3D_file_tell(J3D_FILE& file);

/*jdoc
{"params":["The file object."],
"desc":"This function returns <i>TRUE</i> if the current file position<br/>of an opened file has reached the end-of-file.",
"return":"<i>TRUE</i> if end-of-file has been reached."}*/
bool J3D_file_eof(J3D_FILE& file);

/*jdoc
{"params":["The file object."],
"desc":"This function reads a signed byte <i>(1-byte)</i> from file.<br/>The data range is <b>-128</b> to <b>127</b>.",
"return":"The signed byte."}*/
int8_t J3D_file_read_int8(J3D_FILE& file);

/*jdoc
{"params":["The file object."],
"desc":"This function reads an unsigned byte <i>(1-byte)</i> from file.<br/>The data range is <b>0</b> to <b>255</b>.",
"return":"The unsigned byte."}*/
uint8_t J3D_file_read_uint8(J3D_FILE& file);

/*jdoc
{"params":["The file object."],
"desc":"This function reads a signed short <i>(2-bytes)</i> from file.<br/>The data range is <b>-32,768</b> to <b>32,767</b>.",
"return":"The signed short."}*/
int16_t J3D_file_read_int16(J3D_FILE& file);

/*jdoc
{"params":["The file object."],
"desc":"This function reads an unsigned short <i>(2-bytes)</i> from file.<br/>The data range is <b>0</b> to <b>65,535</b>.",
"return":"The unsigned short."}*/
uint16_t J3D_file_read_uint16(J3D_FILE& file);

/*jdoc
{"params":["The file object."],
"desc":"This function reads a signed long <i>(4-bytes)</i> from file.<br/>The data range is <b>-2,147,483,648</b> to <b>2,147,483,647</b>.",
"return":"The signed long."}*/
int32_t J3D_file_read_int32(J3D_FILE& file);

/*jdoc
{"params":["The file object."],
"desc":"This function reads an unsigned long <i>(4-bytes)</i> from file.<br/>The data range is <b>0</b> to <b>4,294,967,295</b>.",
"return":"The unsigned long."}*/
uint32_t J3D_file_read_uint32(J3D_FILE& file);

/*jdoc
{"params":["The file object."],
"desc":"This function reads a float <i>(4-bytes)</i> from file.",
"return":"The float."}*/
float J3D_file_read_float(J3D_FILE& file);

/*jdoc
{"params":["The file object.","The method to read bytes, see [File reading string methods].<br/><b>NOTE: </b>If a positive number is given, the function reads<br/>this number of bytes from the file."],
"desc":"This function reads a string from file, as specified in <i>method</i> parameter.<br/><b>NOTE: </b>If end of file <i>(EOF)</i> has been reached, the function returns an empty string.",
"return":"The string."}*/
string J3D_file_read_string(J3D_FILE& file, int32_t method = J3D_FRS_ENTIREFILE);

/*jdoc
{"params":["The zip archive filename","List of files to be added in the archive","If <i>TRUE</i>, the files contained in the archive<br/>will be displayed without their directory.","The compression method, see [File compression methods]","If provided, it will be called whenever a file (in the provided list),<br/>is added in the archive. Given the specified <i>compression method</i>,<br/>this may end up fast or slow. This function could then be used<br/>to track the progression as a <i>percentage</i>."],
"desc":"This function creates a compressed zip archive <b>(.zip)</b><br/>from a number of provided files.",
"return":"<i>TRUE</i> for success."}*/
bool J3D_file_create_zip(const string& zipfilename, vector<string>& files, bool onlyfiles = false, uint32_t compression = J3D_ZIP_FASTCOMPRESSION, void (*progress_callback)(uint32_t percentage) = NULL);

/*jdoc
{"params":["The zip object","The zip archive filename","If <b>TRUE</b>, the zip archive is opened for inserting files,<br/>otherwise it will be opened to extract files.<br/><b>NOTE: </b>by default is <i>TRUE</i>"],
"desc":"This function opens either an empty compressed archive <b>(.zip)</b><br/>for insertion of files or an exist zip archive for extraction of files.",
"return":"<i>TRUE</i> for success."}*/
bool J3D_file_open_zip(J3D_FILE_ZIP& zip, const string& zipfilename, bool addfiles = true);

/*jdoc
{"params":["The zip object","The filename to be added in the archive","If <i>TRUE</i>, the file contained in the archive<br/>will be displayed without its directory.","The compression method, see [File compression methods]<br/><b>NOTE:  </b>different compression can be applied per file."],
"desc":"This function inserts a file dynamically to the provided compressed archive.",
"return":"<i>TRUE</i> for success."}*/
bool J3D_file_add_file_to_zip(J3D_FILE_ZIP& zip, const string& file, bool onlyfile = false, uint32_t compression = J3D_ZIP_FASTCOMPRESSION);

/*jdoc
{"params":["The zip object","The filename to be extracted from the archive"],
"desc":"This function extracts a file dynamically from the provided compressed archive.",
"return":"<i>TRUE</i> for success."}*/
bool J3D_file_extract_file_from_zip(J3D_FILE_ZIP& zip, const string& file);

/*jdoc
{"params":["The zip object"],
"desc":"This function closes the compressed archive and makes the file ready for use.",
"return":"<i>TRUE</i> for success."}*/
bool J3D_file_close_zip(J3D_FILE_ZIP& zip);

// math ////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Math",
"params":["The integer value to scale."],
"desc":"This function scales an integer value to the closest <i>powered by two</i> value (upwards).<br/>For example, the value <b>117</b> will be scaled to pow2 <b>128</b> value.<br/><b>NOTE: </b>This is mostly used on texture creation sizes, where many systems either support NPOW2 <i>(non powered by two)</i> sizes or not; this scaling provides the best portability, as <i>all</i> systems are guaranteed to support <i>POW2</i> sizes.",
"return":"The <i>powered by two</i> value."}*/
uint32_t J3D_math_scale_to_pow2(uint32_t val);

/*jdoc
{"params":["The minimum integer.","The maximum integer."],
"desc":"This function produces a random integer number, between a specified range.",
"return":"The random integer."}*/
int32_t J3D_math_random_integer(int32_t min, int32_t max);

/*jdoc
{"params":["The minimum float.","The maximum float."],
"desc":"This function produces a random float number, between a specified range.",
"return":"The random float."}*/
float J3D_math_random_float(float min, float max);

/*jdoc
{"params":["The unsigned integer.<br/><b>NOTE: </b>The number returns modified by bit.","The position to set, from <b>0 to 31</b>.","The bit state, either <i>true / false</i>."],
"desc":"This function sets the bit state at specific position in a given <i>32-bit unsigned integer</i>.",
"return":"Nothing"}*/
void J3D_math_set_bit(uint32_t& number, uint8_t position, bool bit);

/*jdoc
{"params":["The unsigned integer.","The position to check, from <b>0 to 31</b>."],
"desc":"This function retrieves the bit state of specific position in a given <i>32-bit unsigned integer</i>.",
"return":"The bit state, either <b>true</b> if set and <b>false</b> if not set."}*/
bool J3D_math_get_bit(uint32_t number, uint8_t position);

/*jdoc
{"params":["The integer being checked.","The vector of integers.","(out) The vector index in which the number is found."],
"desc":"This function checks if an integer value exists in a vector of integers.",
"return":"<i>TRUE</i> if the integer exists and also the vector index."}*/
bool J3D_math_in_array(int32_t num, const vector<int32_t>& array, int32_t& index);

/*jdoc
{"params":["The number"],
"desc":"This function rounds a double number.<br/><b>NOTE: </b>Added to solve the problems of <i>std::round()</i> absense<br/>on various compilers and/or their versions (i.e. C99, C++11).",
"return":"The rounded number"}*/
double J3D_math_round(double num);

/*jdoc
{"params":["The number"],
"desc":"This function determines if the provided <i>num</i> is an integer i.e. does not have fractional parts",
"return":"<i>TRUE</i> if provided number is an integer"}*/
bool J3D_math_is_integer(double num);

/*jdoc
{"params":["The first position.","The second position."],
"desc":"This function computes the distance between two 2D positions.",
"return":"The distance, as a <i>float</i>"}*/
float J3D_math_get_distance_2d(J3D_VEC2 pos1, J3D_VEC2 pos2);

/*jdoc
{"params":["The first position.","The second position."],
"desc":"This function computes the distance between two 3D positions.",
"return":"The distance, as a <i>float</i>"}*/
float J3D_math_get_distance_3d(J3D_VEC3 pos1, J3D_VEC3 pos2);

/*jdoc
{"params":["The first position.","The second position.","The percentage between the 2 positions.<br/><b>NOTE: </b>The range is between <b>0.0f</b> to <b>1.0f</b>"],
"desc":"This function computes a new 2D position between two 2D positions, based on provided percentage.",
"return":"The position, as a <i>J3D_VEC2</i>"}*/
J3D_VEC2 J3D_math_get_position_between_2d(const J3D_VEC2& pos1, const J3D_VEC2& pos2, float perc);

/*jdoc
{"params":["The first position.","The second position.","The percentage between the 2 positions.<br/><b>NOTE: </b>The range is between <b>0.0f</b> to <b>1.0f</b>"],
"desc":"This function computes a new 3D position between two 3D positions, based on provided percentage.",
"return":"The position, as a <i>J3D_VEC3</i>"}*/
J3D_VEC3 J3D_math_get_position_between_3d(const J3D_VEC3& pos1, const J3D_VEC3& pos2, float perc);

/*jdoc
{"params":["The list of integers","The threshold counter.<br/>A value that appears less that this counter, it wont get considered.","The number of common values to return.<br/><b>NOTE: </b>A value of <b>0</b> indicates all common values."],
"desc":"This function returns the most common values from a vector.",
"return":"The most common values, as a <i>vector</i> of integers"}*/
vector<int32_t> J3D_math_get_most_common_values(const vector<int32_t>& values, int32_t count_threshold, int32_t num_common_values = 0);

/*jdoc
{"params":["The degrees"],
"desc":"This function converts degrees from <i>0 to 360</i> to radians.",
"return":"The radians, as a <i>float</i>"}*/
float J3D_math_degrees_to_radians(int32_t degrees);

/*jdoc
{"params":["The radians"],
"desc":"This function converts radians from <i>0 to 3.14</i> to degrees.",
"return":"The degrees, as an <i>integer</i>"}*/
int32_t J3D_math_radians_to_degrees(float radians);

// string ////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"String",
"params":["The string format, see <a href='http://www.cplusplus.com/reference/cstdio/printf/'>here</a> for a list of <i>format specifiers</i>.","The list of variable parameters.<br/><b>NOTE: </b>Make sure the variables are appropriate for <i>format specifiers</i>."],
"desc":"This function formats a string with variable parameters.",
"return":"The formatted string."}*/
string J3D_string_format(string fmt, ...);

/*jdoc
{"params":["The string format, see <a href='http://www.cplusplus.com/reference/cstdio/printf/'>here</a> for a list of <i>format specifiers</i>.<br/><b>NOTE: </b>For wide characters or strings, one must use <i>%lc, %ls</i> instead.","The list of variable parameters.<br/><b>NOTE: </b>Make sure the variables are appropriate for <i>format specifiers</i>."],
"desc":"This function formats a <i>wide</i> (unicode) string with variable parameters.",
"return":"The formatted <i>wide</i> string."}*/
wstring J3D_string_format_wide(const wchar_t* sformat, ...);

/*jdoc
{"params":["The string length."],
"desc":"This function produces a random string of specified size, made of <i>latin</i> characters and numbers.",
"return":"The randomized string."}*/
string J3D_string_random(uint16_t length);

/*jdoc
{"params":["The string length.","(optional) The font name."],
"desc":"This function produces a random <i>wide</i> string of specified size, made of either <i>latin</i> characters (if <i>fontname</i> is not provided) or any wide character found in the font name (if provided), plus numbers.",
"return":"The randomized <i>wide</i> string."}*/
wstring J3D_string_random_wide(uint16_t length, string fontname = "");

/*jdoc
{"params":["The string to search for.","The string to replace with.","The string subject.","(optional) The subject starting offset.<br/><b>NOTE: </b>If left blank, it will start from subject's beginning.","(optional) Whether to replace a single or all occurences in <i>subject</i>.<br/><b>NOTE: </b>By default is <b>FALSE</b>."],
"desc":"This function replaces a specified fragment of text with another in a provided string.",
"return":"The replaced string."}*/
string J3D_string_replace(const string& search, const string& replace, const string& subject, size_t subjectpos = 0, bool single = false);

/*jdoc
{"params":["The string to search for.","The string to replace with.","The string subject.","(optional) The subject starting offset.<br/><b>NOTE: </b>If left blank, it will start from subject's beginning.","(optional) Whether to replace a single or all occurences in <i>subject</i>.<br/><b>NOTE: </b>By default is <b>FALSE</b>."],
"desc":"This function replaces a specified fragment of <i>wide</i> text with another in a provided string.",
"return":"The replaced <i>wide</i> string."}*/
wstring J3D_string_replace_wide(const wstring& search, const wstring& replace, const wstring& subject, size_t subjectpos = 0, bool single = false);

/*jdoc
{"params":["The delimiter used to break the string.<br/><b>NOTE: </b>To explode the string into characters, use an empty string as <i>delimiter</i>.","The string subject."],
"desc":"This function breaks a string down to a <i>vector</i>, using a specific delimiter.",
"return":"A vector of strings."}*/
vector<string> J3D_string_explode(const string& delimiter, const string& str);

/*jdoc
{"params":["The delimiter used to break the string.<br/><b>NOTE: </b>To explode the string into characters, use an empty string as <i>delimiter</i>.","The string subject."],
"desc":"This function breaks a <i>wide</i> string down to a <i>vector</i>, using a specific delimiter.",
"return":"A vector of <i>wide</i> strings."}*/
vector<wstring> J3D_string_explode_wide(const wstring& delimiter, const wstring& str);

/*jdoc
{"params":["The delimiter used to merge the vector of strings.","The vector of strings."],
"desc":"This function merges a <i>vector</i> of strings to a single string, inserting a specific delimiter between strings.",
"return":"The merged string."}*/
string J3D_string_implode(const string& delimiter, const vector<string>& array);

/*jdoc
{"params":["The delimiter used to merge the vector of strings.","The vector of strings."],
"desc":"This function merges a <i>vector</i> of <i>wide</i> strings to a single string, inserting a specific delimiter between strings.",
"return":"The merged <i>wide</i> string."}*/
wstring J3D_string_implode_wide(const wstring& delimiter, const vector<wstring>& array);

/*jdoc
{"params":["The vector of strings."],
"desc":"This function removes duplicates from a vector of strings.",
"return":"A vector of unique strings."}*/
vector<string> J3D_string_array_unique(const vector<string>& array);

/*jdoc
{"params":["The vector of strings."],
"desc":"This function removes duplicates from a vector of <i>wide</i> strings.",
"return":"A vector of unique <i>wide</i> strings."}*/
vector<wstring> J3D_string_array_unique_wide(const vector<wstring>& array);

/*jdoc
{"params":["The string being checked (the <i>needle</i>).","The string subject (the <i>haystack</i>).","(in,out) The position of the needle.<br/><b>NOTE: </b>If no string is found, this will be <b>-1</b>"],
"desc":"This function checks if a string fragment exists in another string.",
"return":"<i>TRUE</i> if the string fragment exists."}*/
bool J3D_string_in_string(const string& needle, const string& haystack, int32_t& offset);

/*jdoc
{"params":["The string being checked (the <i>needle</i>).","The string subject (the <i>haystack</i>).","(in,out) The position of the needle.<br/><b>NOTE: </b>If no string is found, this will be <b>-1</b>"],
"desc":"This function checks if a <i>wide</i> string fragment exists in another <i>wide</i> string.",
"return":"<i>TRUE</i> if the string fragment exists."}*/
bool J3D_string_in_string_wide(const wstring& needle, const wstring& haystack, int32_t& offset);

/*jdoc
{"params":["The string being checked.","The vector of strings.","(out) The vector index in which the string is found or <b>-1</b> otherwise."],
"desc":"This function checks if a string exists in a vector of strings.",
"return":"<i>TRUE</i> if the string fragment exists and also the vector index."}*/
bool J3D_string_in_array(const string& str, const vector<string>& array, int32_t& index);

/*jdoc
{"params":["The string being checked.","The vector of strings.","(out) The vector index in which the string is found or <b>-1</b> otherwise."],
"desc":"This function checks if a <i>wide</i> string exists in a vector of <i>wide</i> strings.",
"return":"<i>TRUE</i> if the string fragment exists and also the vector index."}*/
bool J3D_string_in_array_wide(const wstring& str, const vector<wstring>& array, int32_t& index);

/*jdoc
{"params":["The string."],
"desc":"This function converts multiple spaces in specified string into one space.",
"return":"The modified string."}*/
string J3D_string_multiple_spaces_to_one(string& str);

/*jdoc
{"params":["The string."],
"desc":"This function converts multiple spaces in specified <i>wide</i> string into one space.",
"return":"The modified <i>wide</i> string."}*/
wstring J3D_string_multiple_spaces_to_one_wide(wstring& str);

/*jdoc
{"params":["The string."],
"desc":"This function removes <i>whitespace</i> from both ends of a string.",
"return":"The modified string."}*/
string J3D_string_trim(const string& str);

/*jdoc
{"params":["The string."],
"desc":"This function removes <i>whitespace</i> from both ends of a <i>wide</i> string.",
"return":"The modified <i>wide</i> string."}*/
wstring J3D_string_trim_wide(const wstring& str);

/*jdoc
{"params":["The string."],
"desc":"This function converts the specified string to an integer.",
"return":"The converted integer (32-bit signed)."}*/
int32_t J3D_string_convert_to_integer(const string& str);

/*jdoc
{"params":["The string."],
"desc":"This function converts the specified string to a double.",
"return":"The converted double (64-bit)."}*/
double J3D_string_convert_to_double(const string& str);

/*jdoc
{"params":["The string."],
"desc":"This function converts a string to a <i>wide</i> string.",
"return":"The converted <i>wide</i> string."}*/
wstring J3D_string_convert_string_to_wstring(const string& s);

/*jdoc
{"params":["The string."],
"desc":"This function converts a <i>wide</i> string to a string.",
"return":"The converted string."}*/
string J3D_string_convert_wstring_to_string(const wstring& ws);

/*jdoc
{"params":["The string."],
"desc":"This function compresses the provided string using <b>deflate</b> (LZ77 / Huffman) compression.",
"return":"The compressed string."}*/
string J3D_string_compress(const string& str);

/*jdoc
{"params":["The first string.","The second string."],
"desc":"This function compares two strings using <b>Levenshtein Distance</b> algorithm,<br/>where <i>distance</i> translates into the number of deletions, insertions or substitutions<br/>required to convert the first string to second.",
"return":"The similarity between the 2 strings, in <i>percentage</i>."}*/
float J3D_string_similarity(const string& str1, const string& str2);

/*jdoc
{"params":["The string."],
"desc":"This function escapes all <b>XML illegal</b> characters from specified string.",
"return":"The escaped string."}*/
string J3D_string_escape_xml(const string& data);

// time ////////////////////////////////////////////////////////////////////////////////////////

/*jdoc
{"group":"Time",
"params":["The current day, from <b>1..31</b>","The current month, from <b>1..12</b>","The current year as 4-digits ie. <b>2016</b>","The current hour in 24-hour representation ie. <b>22</b> means 10 PM.","The current minutes, from <b>0..59</b>","The current seconds, from <b>0..59</b>"],
"desc":"This function breaks down the current time into components.",
"return":"The current time, broken into components."}*/
void J3D_time_get_current(int32_t& Day, int32_t& Month, int32_t& Year, int32_t& Hour, int32_t& Min, int32_t& Sec);

/*jdoc
{"desc":"This function retrieves the time (in <i>seconds</i>) since <b>00:00, January 1, 1970</b>,<br/>more commonly referred as <i>Unix Timestamp or Unix Epoch</i>.",
"return":"The time difference from <i>Unix Epoch</i>, in <i>seconds</i>."}*/
uint32_t J3D_time_get_seconds();

/*jdoc
{"desc":"This function retrieves the time (in <i>milliseconds</i>) since the <i>application's start</i>.<br/>It's meant to measure relative time differences between calls.",
"return":"The time, in <i>milliseconds</i>."}*/
uint32_t J3D_time_get_ms();

/*jdoc
{"params":["The time in <i>milliseconds</i>."],
"desc":"This function <i>suspends the execution</i> for the specified time period in <i>milliseconds</i>.",
"return":"Nothing"}*/
void J3D_time_sleep(uint32_t ms);

/*jdoc
{"params":["The event name.","The time in <i>milliseconds</i>.","If set to <b>FALSE</b> (default), the time event will be fired every <i>ms</i>,<br/>otherwise it will be fired only once."],
"desc":"This function starts a timed event.<br/>Specifically, it defines a <i>named</i> event and a time (in milliseconds),<br/>after which the event will be triggered via [J3D_callback_async] callback and<br/><b>J3D_ASYNC_TIMEREVENT_COMPLETE</b> event.<br/><br/><b>NOTE: </b>This function must be called after a window creation i.e.<br/>the <b>J3D_WINDOW_INIT</b> of [J3D_callback_window] is the preferred place.",
"return":"Nothing"}*/
void J3D_time_event_start(string name, uint32_t ms, bool onetime = false);

/*jdoc
{"params":["The event name."],
"desc":"This function checks if a timed event is scheduled,<br/>after its creation and before its triggering.",
"return":"<i>TRUE</i> if the scheduled event exists."}*/
bool J3D_time_event_scheduled(string name);

/*jdoc
{"params":["The event name."],
"desc":"This function cancels a timed event, after its creation and before its triggering.<br/><b>NOTE:</b> This is optional since <i>Jolt3D!</i> stops all events automatically on exit.",
"return":"Nothing"}*/
void J3D_time_event_stop(string name);

#endif