#include "Layer.hpp"
#include <iostream>

class ExampleLayer : public Layer {
public:
  ExampleLayer() : Layer("Example") {}

  void OnUpdate() override { std::cout << "Layer Update\n"; }

  void OnEvent(Event &event) override {
    std::cout << "Event: " << event.ToString() << "\n";
  }
};
