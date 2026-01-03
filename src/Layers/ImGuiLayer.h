#pragma once
#include "Layer.hpp"

class ImGuiLayer : public Layer {
public:
  ImGuiLayer();
  ~ImGuiLayer();

  void OnAttatch();
  void OnDetach();
  void OnUpdate();
  void OnEvent(Event &event);

private:
  float m_Time;
};
