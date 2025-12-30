#include "Engine/Engine.hpp"
#include <GLFW/glfw3.h>

int main() {
  Engine *engine = new Engine();
  engine->Run();
  return 0;
}
