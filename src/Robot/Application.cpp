#include "Application.hpp"
#include "FrameListener.hpp"

/**
 * Setup application configuration options
 */
bool Robot::Application::configure()
{
	// Always load the GL render system
	this->mRoot->loadPlugin("RenderSystem_GL");

	// Get the GL Render system and set it on the root
	Ogre::RenderSystem* RS = this->mRoot->getAvailableRenderers()[0];
	this->mRoot->setRenderSystem(RS);

	// Dont use full-screen
	RS->setConfigOption("Full Screen", "no");

	// Setup the root window
	this->mWindow = this->mRoot->initialise(true, "CG - Project 4");

	return true;
}

/**
 * Create the Scene.
 *
 * Add a ground plane and a robot.
 */
void Robot::Application::createScene()
{
	// Create a plane for the robot to stand on
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

	// Add the plane into the mesh manager
	Ogre::MeshManager::getSingletonPtr()->createPlane("plane",
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, plane,
		1500, 1500, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);

	// Get the ground plane as an entity
	Ogre::Entity* ground = this->mSceneMgr->createEntity("Ground", "plane");

	// Use the rockwall material
	ground->setMaterialName("Examples/Rockwall");

	// Create the scene node to add the plane to
	Ogre::SceneNode* groundSceneNode = this->mSceneMgr->getRootSceneNode()
		->createChildSceneNode("GroundNode", Ogre::Vector3(0, 0, 0));

	// Add the ground to the node
	groundSceneNode->attachObject(ground);


	// Create a scene node for the robot
	Ogre::SceneNode* robotSceneNode = this->mSceneMgr->getRootSceneNode()
		->createChildSceneNode("RobotNode", Ogre::Vector3(0, 5, 0));

	// Create the robot entity
	this->robotEntity = this->mSceneMgr->createEntity("Robot", "robot.mesh");

	// Add the robot to the scene node
	robotSceneNode->attachObject(this->robotEntity);
}

/**
 * Cleanup the scene
 */
void Robot::Application::destroyScene()
{
	this->mSceneMgr->destroyEntity(this->robotEntity);
	this->mSceneMgr->clearScene();
}

/**
 * Setup the camera pointing to the center of the scene
 */
void Robot::Application::createCamera()
{
	ExampleApplication::createCamera();

	this->mCamera->setPosition(100, 100, 100);
	this->mCamera->lookAt(0, 40, 0);
}

/**
 * Setup our frame listener
 */
void Robot::Application::createFrameListener()
{
	this->mRoot->addFrameListener(new Robot::FrameListener(this->mRoot));
}
