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
	// Get the robot entity
	this->robotEntity = this->root
		->getSceneManager("ExampleSMInstance")->getEntity("Robot");

	// Get the current window ID
	std::size_t winId;
	this->root->getAutoCreatedWindow()->getCustomAttribute("WINDOW", &winId);

	// Setup the input manager
	this->inputManager = OIS::InputManager::createInputSystem(winId);

	// Setup the keyboard input listener
	this->inputKeyboard = static_cast<OIS::Keyboard*>
		(this->inputManager->createInputObject(OIS::OISKeyboard, false));
}

/**
 * Cleanup the input systems
 */
Robot::FrameListener::~FrameListener()
{
	this->inputManager->destroyInputObject(this->inputKeyboard);
	OIS::InputManager::destroyInputSystem(this->inputManager);
}

/**
 * Handle each frame tick
 *
 * @param evt The frame event
 */
bool Robot::FrameListener::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
	this->inputKeyboard->capture();

	// Set the robot to idle by default
	this->currentAnimation = this->robotEntity->getAnimationState("Idle");

	// Handle waving (shooting)
	if (this->inputKeyboard->isKeyDown(OIS::KC_R))
	{
		this->currentAnimation = this->robotEntity->getAnimationState("Shoot");
	}

	// Handle walking
	if (this->inputKeyboard->isKeyDown(OIS::KC_W))
	{
		this->currentAnimation = this->robotEntity->getAnimationState("Walk");

		// Move it forward
		this->robotEntity->getParentNode()
			->translate(20 * evt.timeSinceLastFrame, 0, 0);

		// Follow it with the camera
		this->root
			->getSceneManager("ExampleSMInstance")
			->getCamera("PlayerCam")
			->lookAt(this->robotEntity->getParentNode()
				->getPosition() + Ogre::Vector3(0, 35, 0));
	}

	// Handle quiting
	if (this->inputKeyboard->isKeyDown(OIS::KC_ESCAPE)
		|| this->inputKeyboard->isKeyDown(OIS::KC_Q)
		|| this->root->getAutoCreatedWindow()->isClosed())
	{
		return false;
	}

	// Increment the animation
	this->currentAnimation->setEnabled(true);
	this->currentAnimation->setLoop(true);
	this->currentAnimation->addTime(evt.timeSinceLastFrame);

	return true;
}
