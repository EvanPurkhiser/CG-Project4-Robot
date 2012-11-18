#ifndef ROBOT_FRAMELISTENER_HPP
#define ROBOT_FRAMELISTENER_HPP

#include <OIS/OIS.h>
#include <OGRE/OgreFrameListener.h>

namespace Robot
{

class FrameListener : public Ogre::FrameListener
{

private:

	Ogre::Root*   root;

public:

	/**
	 * Setup the frame listener
	 */
	FrameListener(Ogre::Root* root);

};

}

#endif
