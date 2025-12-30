#include <GLFW/glfw3.h>
#include <memory>

#include "Windows/Window.hpp"

int main() {
  std::unique_ptr<Window> m_Window;
  bool running = true;
  m_Window = std::unique_ptr<Window>(Window::Create());

  while (running) {
    m_Window->OnUpdate();
  }

  return 0;
  // if (!glfwInit())
  //   return -1;
  //
  // GLFWwindow *window =
  //     glfwCreateWindow(1280, 720, "Hello GLFW", nullptr, nullptr);
  //
  // glfwMakeContextCurrent(window);
  //
  // while (!glfwWindowShouldClose(window)) {
  //   glfwSwapBuffers(window);
  //   glfwPollEvents();
  // }
  //
  // glfwDestroyWindow(window);
  // glfwTerminate();
}
