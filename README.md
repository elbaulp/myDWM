> This repo is inpired in [jceb/dwm-patches](https://github.com/jceb/dwm-patches)

# Installation

## Clone the repo

    git clone https://github.com/elbaulp/myDWM

## init and load dwm submodule

    cd myDWM
    git submodule update --init --recursive

## activate all patches, including the personal configuration

    quilt push -a

## build dwm (or us the ./build script)

    cd dwm
    rm -f config.h
    make

# Patch References

* [pertag.patch](patches/pertag.patch)                                   (http://dwm.suckless.org/patches/pertag)
* [systray.patch](patches/systray.patch)                                 (http://dwm.suckless.org/patches/systray)

# Quilt tutorial

If you want to understand how to use quilt, here are some useful resources:

* [How to manage multiple patches - A Quilt tutorial](https://elbauldelprogramador.com/en/how-to-mantain-patchs-quilt-tutorial/)
* [Using Quilt](https://wiki.debian.org/UsingQuilt)
* [How To Survive With Many Patches or Introduction to Quilt](https://stuff.mit.edu/afs/athena/system/i386_deb50/os/usr/share/doc/quilt/quilt.html)
