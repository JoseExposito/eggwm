# Introduction #

One of the main objectives of Egg Window Manager is to implement fully all the standards that a good window manager should comply.

On this page you can view the status of the current implementation of EWMH standard, also known as NetWM, in the development branch of Egg Window Manager (SVN repository).



# Documentation #

If you are a developer and are interested in helping implementing or improving any of these standards this documentation can be useful:

http://standards.freedesktop.org/wm-spec/latest/


# Current implementation of standards EWMH #

To facilitate the implementation of the standard EWMH it has been divided into two:

  * EWMH - Root: The first part is implemented in the _src/eggwm/tandards/EWMHRoot.h_ class and then sends to the root window a series of properties that EggWM accept.


  * EWMH - Client: The second part is implemented in _src/eggwm/standards/EWMHClient.h_ class and manages a number of properties extra properties similar to ICCCM.

## EWMH - Root ##

  * _NET\_SUPPORTED_

  * _NET\_CLIENT\_LIST
    *_NET\_CLIENT\_LIST
    * _NET\_CLIENT\_LIST\_STACKING_

  * _NET\_ACTIVE\_WINDOW_

  * _NET\_SUPPORTING\_WM\_CHECK_

  * _NET\_NUMBER\_OF\_DESKTOPS_

  * _NET\_DESKTOP\_NAMES_

  * _NET\_DESKTOP\_GEOMETRY_

  * _NET\_DESKTOP\_VIEWPORT_

  * _NET\_WORKAREA_

  * _NET\_CURRENT\_DESKTOP_

  * _NET\_SHOWING\_DESKTOP_

  * _NET\_VIRTUAL\_ROOTS_

  * _NET\_DESKTOP\_LAYOUT_


## EWMH - Client ##

  * _NET\_WM\_NAME_

  * _NET\_WM\_VISIBLE\_NAME_

  * _NET\_WM\_DESKTOP_

  * _NET\_WM\_WINDOW\_TYPE_

  * 