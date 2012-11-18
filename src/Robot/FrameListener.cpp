#include "FrameListener.hpp"

#include <OGRE/OgreRoot.h>
#include <OGRE/OgreRenderWindow.h>
#include <OGRE/OgreEntity.h>

/**
 * Setup the frame listener
 *
 * @param root The ogre root object
 */
Robot::FrameListener::FrameListener(Ogre::Root* root) : root(root)
{

}
