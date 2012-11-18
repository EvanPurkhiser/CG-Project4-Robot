#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Robot {

private:

	GLuint VertexArrayID;
	GLuint vertexbuffer;
	GLuint colorbuffer;
	GLuint programID;
	GLuint MatrixID;

	glm::mat4 MVP;

	float rotation;

public:

	/**
	 * Generate the robot and begin the execution of the program
	 *
	 * @return int The return status
	 */
	static int factory();

	/**
	 * Constructor for the robot, should setup all OpenGL directives and contexts
	 * using GLEW and GLFW.
	 *
	 * @return void
	 */
	Robot();

	/**
	 * Destruct the robot, cleanup all Vertex Buffers and Shaders, and finally
	 * terminate the program
	 *
	 * @return void
	 */
	~Robot();

	/**
	 * Determine if the program should be exited after each rendering tick
	 *
	 * @return bool
	 */
	bool testExit();

	/**
	 * The main loop for rendering the program
	 */
	void mainLoop();

};
