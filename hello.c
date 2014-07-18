#include<X11/Xlib.h>

#include<stdio.h>
#include<stdlib.h>

int main()
{
    Display *dpy;
    Window rootwin;
    Window win;
    Colormap cmap;
    XEvent e;
    int scr;
    GC gc;
    
    if(!(dpy=XOpenDisplay(NULL))) {
        fprintf(stderr, "ERROR: could not open display\n");
        exit(1);
    }
    scr = DefaultScreen(dpy);
        rootwin = RootWindow(dpy, scr);
            cmap = DefaultColormap(dpy, scr);

    win=XCreateSimpleWindow(dpy, rootwin, 1, 1, 100, 50, 0, 
    BlackPixel(dpy, scr), BlackPixel(dpy, scr));
    XStoreName(dpy, win, "hello");
    gc=XCreateGC(dpy, win, 0, NULL);
    XSetForeground(dpy, gc, 0x00ff00/*WhitePixel(dpy, scr)*/);
    XSelectInput(dpy, win, ExposureMask|ButtonPressMask);
    XMapWindow(dpy, win);

    while(1) {
        XNextEvent(dpy, &e);
        if(e.type==Expose && e.xexpose.count<1)
        XDrawString(dpy, win, gc, 10, 10, "Hello World!", 12);
        else if(e.type==ButtonPress) break;
    }

    XCloseDisplay(dpy);
    return 0;
}
