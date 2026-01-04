#include "Engine/Engine.hpp"
#include "Layers/ImGuiLayer.h"
#include "Layers/Layer.hpp"
#include <glad/glad.h>

class ExampleLayer : public Layer {
public:
  ExampleLayer() : Layer("Example") {}

  void OnUpdate() override {}

  void OnEvent(Event &event) override {
    // std::cout << "Event: " << event.ToString() << "\n";
  }
};

int main() {
  Layer *exampleLayer = new ExampleLayer();
  Layer *imguiLayer = new ImGuiLayer();

  Engine *engine = new Engine();
  engine->PushLayer(exampleLayer);
  engine->PushLayer(imguiLayer);
  engine->Run();
  return 0;
}
