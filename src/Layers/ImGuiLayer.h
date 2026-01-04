#pragma once
#include "Events/ApplicationEvent.hpp"
#include "Events/KeyEvent.hpp"
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
  bool OnMouseButtonPressedEvent(MouseButtonPressedEvent &e);
  bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &e);
  bool OnMouseMovedEvent(MouseMovedEvent &e);
  bool OnMouseScrolledEvent(MouseScrolledEvent &e);
  bool OnPressedEvent(KeyPressedEvent &e);
  bool OnReleasedEvent(KeyReleasedEvent &e);
  // bool OnKeyTypedEvent(KeyTypedEvent &e);
  bool OnWindowResizedEvent(WindowResizeEvent &e);

private:
  float m_Time;
};
