#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glfw.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "common/shader.hpp"
#include "common/texture.hpp"

/**
 * Setup the basic OpenGL context and options
 */
void setup()
{
	// Initialise GLFW
	if( ! glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		exit(1);
	}

	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	if( ! glfwOpenWindow(1024, 768, 0, 0, 0, 0, 32, 0, GLFW_WINDOW))
	{
		fprintf( stderr, "Failed to open GLFW window\n");
		glfwTerminate();
		exit(1);
	}

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		exit(1);
	}

	glfwSetWindowTitle("CG - Project 4");

	// Ensure we can capture keys
	glfwEnable(GLFW_STICKY_KEYS);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.3f, 0.0f);

	// Enabled depth and fragment testing
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);
}


int main()
{

}
