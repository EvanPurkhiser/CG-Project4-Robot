#include "Application.hpp"

/**
 * Setup application configuration options
 */
bool Robot::Application::configure()
{
	// Setup the root object
	mRoot = OGRE_NEW Ogre::Root("", "ogre.cfg", "ogre.log");

	// Always load the GL render system
	mRoot->loadPlugin("RenderSystem_GL");

	// Get the GL Render system and set it on the root
	Ogre::RenderSystem* RS = mRoot->getAvailableRenderers()[0];
	mRoot->setRenderSystem(RS);

	// Dont use full-screen
	RS->setConfigOption("Full Screen", "no");

	// Setup the root window
	mWindow = mRoot->initialise(true);

	return true;
}


/**
 * Createe the Scene
 */
void Robot::Application::createScene()
{

}
