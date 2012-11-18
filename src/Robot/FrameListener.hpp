#ifndef ROBOT_FRAMELISTENER_HPP
#define ROBOT_FRAMELISTENER_HPP

#include <OIS/OIS.h>
#include <OGRE/OgreFrameListener.h>

namespace Robot
{

class FrameListener : public Ogre::FrameListener
{

private:

	OIS::InputManager* inputManager;
	OIS::Keyboard*     inputKeyboard;

	Ogre::Root*   root;
	Ogre::Entity* robotEntity;

	Ogre::AnimationState* currentAnimation;

public:

	/**
	 * Setup the frame listener
	 */
	FrameListener(Ogre::Root* root);

	/**
	 * Handle each frame tick
	 *
	 * @param evt The frame event
	 */
	bool frameRenderingQueued(const Ogre::FrameEvent& evt);

};

}

#endif
