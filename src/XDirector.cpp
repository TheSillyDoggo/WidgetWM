#include "XDirector.hpp"

XDirector* XDirector::get()
{
    static XDirector* instance = nullptr;

    if (!instance)
    {
        instance = new XDirector();
        instance->init();
    }

    return instance;
}

void XDirector::init()
{
    display = XOpenDisplay(NULL);

    if (!display)
    {
        std::cerr << "Unable to open X display!" << std::endl;
        return;
    }

    screen = DefaultScreen(display);

    window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, 480, 272, 1, BlackPixel(display, screen), WhitePixel(display, screen));

    XStoreName(display, window, "XDirector");
    XSelectInput(display, window, ExposureMask | KeyPressMask | StructureNotifyMask);
    XMapWindow(display, window);
}

void XDirector::drawScene()
{
    XClearWindow(display, window);
}

int XDirector::run()
{
    XEvent event;

    while (!shouldQuit)
    {
        XNextEvent(display, &event);

        switch (event.type)
        {
            case Expose:
                drawScene();

                break;

            case KeyPress:
                std::cout << "btn: " << event.xbutton.button << std::endl;
                break;

            case DestroyNotify:
                break;
        }
    }

    XDestroyWindow(display, window);
    XCloseDisplay(display);

    return 0;
}

Window& XDirector::getWindow()
{
    return window;
}