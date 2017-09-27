# GameEngine
QGDC Game Engine

Please make sure, when working to properly link opengl, glew and glfw ( follow these instruction [LINK HERE](http://www.41post.com/5178/programming/opengl-configuring-glfw-and-glew-in-visual-cplusplus-express) ) to properly link on visual studio).

Game Engine Architecture:

A basic architecture that we are using for the GameEngine is as follows:

![Game Engine Architecture](https://www.blaenkdenum.com/images/notes/game-development/engine-architecture.png)

TODO:

We still have a lot to work on.

For starters, a proper implementation of the rendering engine still needs to be complete.

The main game loop needs to be properly implemented so that all game objects passed into the scene are properly updated.

A proper template class for components, transforms, gameobjects etc still needs implementation

A threaded audio engine is still required (I believe OpenAL is the one most people use.)

FUTURE WORK:

An implementation of a physics engine.

A virtual file system implementation.

Anything else????
