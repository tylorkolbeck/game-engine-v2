#pragma once
#include "Events/MouseEvent.hpp"
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
  void OnMouseButtonPressedEvent(MouseButtonPressedEvent &e);
  void OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &e);

private:
  float m_Time;
};
