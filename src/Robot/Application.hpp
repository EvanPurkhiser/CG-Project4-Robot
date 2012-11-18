#ifndef ROBOT_SCENE_HPP
#define ROBOT_SCENE_HPP

#include <OGRE/ExampleApplication.h>

namespace Robot
{

class Application : public ExampleApplication
{

private:

	Ogre::Entity* robotEntity;

public:

	/**
	 * Setup the application
	 */
	bool configure();

	/**
	 * Create the Scene
	 */
	void createScene();

	/**
	 * Cleanup the scene on destruct
	 */
	void destroyScene();

	/**
	 * Setup the camera
	 */
	void createCamera();

	/**
	 * Setup the frame listener
	 */
	void createFrameListener();

};

}

#endif
