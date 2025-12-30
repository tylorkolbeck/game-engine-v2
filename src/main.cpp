#include <GLFW/glfw3.h>

int main() {
  if (!glfwInit())
    return -1;

  GLFWwindow *window =
      glfwCreateWindow(1280, 720, "Hello GLFW", nullptr, nullptr);

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
}
