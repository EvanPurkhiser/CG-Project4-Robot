#ifndef ROBOT_SCENE_HPP
#define ROBOT_SCENE_HPP

#include <OGRE/ExampleApplication.h>

namespace Robot
{

class Application : public ExampleApplication
{

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
	 * Setup the camera
	 */
	void createCamera();

private:

	Ogre::Entity* robotEntity;

};

}

#endif
