/*
 * @author: Eduardo Nascimento
 * @brief: Space invaders using openGL and GLEW
 * @lastRevision: Friday June, 07, 2024
*/

/* INCLUDES */
#include "game.h"
#include <GLFW/glfw3.h>

/* FUNCTIONS */

/* ERROR CALLBACK FUNC */
void error_callback(int error, const char *description) {
  fprintf(stderr, "[*] ERROR: %s\n", description);
  fprintf(stderr, "[*] ERROR CODE: %i\n", error);
}

/* MAIN */
int main() {

  /* SET CALLBACK FUNC */
  glfwSetErrorCallback(error_callback);

  /* INIT GLFW */
  if(!glfwInit()) {
    return 1;
  }

  /* GLFW HINTS */
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  /* CREATE WINDOW */
  GLFWwindow *window = glfwCreateWindow(900, 900, "Space Invaders", NULL, NULL);
  // err handling
  if(!window) {
    glfwTerminate();
    return 1;
  }
  
  /* SET OPENGL CONTEXT */
  glfwMakeContextCurrent(window);

  /* INIT GLEW */
  GLenum err = glewInit();
  // err handling
  if(err != GLEW_OK) {
    fprintf(stderr, "[*] ERROR, Error initializing GLEW");
    glfwTerminate();
    return 1;
  }

  /* GET OPENGL VERSION */
  int glVersion[2] = {-1, 1};
  glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
  glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);
  // print version
  printf("OpenGl Version: %i.%i\n", glVersion[0], glVersion[1]);

  /* MAIN GAME LOOP */
  glClearColor(0.0, 0.0, 0.0, 1.0); 
  while(!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  /* CLEANUP */
  glfwDestroyWindow(window);
  glfwTerminate();

  /* EXIT SUCCESS */
  return 0;
}
