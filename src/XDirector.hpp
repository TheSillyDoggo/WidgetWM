#pragma once

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>

class XDirector
{
    private:
        int screen;
        Window window;
        Display* display;
        bool shouldQuit = false;

    public:
        static XDirector* get();

        Window& getWindow();
        Display* getDisplay();

        void init();
        void drawScene();
        int run();
};