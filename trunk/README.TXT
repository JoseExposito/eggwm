To compile:
$ qmake
$ make

To launch:
$ Xephyr :1 -ac -screen 900x700 &
$ ./eggwm -display :1

To launch xterm:
$ xterm -display :1