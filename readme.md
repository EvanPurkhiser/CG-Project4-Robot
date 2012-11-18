## Computer Graphics - Project 4

The goal of this project was to play with OpenGL and understand the concepts
behind openGL. After spending over 5 hours working with pure OpenGL 3.3 using
the GLFW and GLEW libraries, I've given up on attempting to animate an object
in pure OpenGL. Instead I've opted to use the OGRE framework which abstracts
away the complexities of OpenGL and allows us to easily create a scene with
an animated model.


### Requirements

This project is based upon the OGRE framework. You must have the OGRE libraries
and header files installed to build this project from source. It's also required
to have the dynamicly linked librires `OgreMain`, `OIS`, and `Render_System_GL`
in the root of this project directory.

The BOOST library is also required.

### Building

I've tested building this project using MinGWx32 on windows using the MinGW-Make
utility.

Steps for building and testing (assuming GNU make)

    $ make
    $ make execute
