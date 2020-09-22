# QT: Collapsible Section

This is a fork from https://github.com/MichaelVoelkel/qt-collapsible-section

This fork adds functionality to export this widget to QT Designer and also enables autoUI compiling of this widget.


You'll see that the constructor of ```Section``` has changed to acces no arguments.
This is because when you use autoUIC to compile from a ```.ui``` file to ```ui_.h``` file, it only uses
the default constructor, so you will have a nasty compiletime error if your constructor
is not default. There will also be a couple macros in the ```Section.h``` header
that allow for widget exporting. And in the ```CmakeLists.txt```, the ```Section``` is compiled
as a shared library and installed to your Qt/designer folder as a plugin.

Instructions:
```
$ git clone https://github.com/seanngpack/qt-collapsible-section
$ cd qt-collapsible-section
$ mkdir build
$ cd build
$ cmake ..
$ sudo make install  # this step is essential installs the widget to your QT plugins folder
```


## Sample Animation

![section opening and closing](example.gif)
