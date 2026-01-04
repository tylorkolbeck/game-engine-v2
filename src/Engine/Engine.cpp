#include "Engine.hpp"
#include "Events/KeyCodes.h"
#include <glad/glad.h>

#define BIND_EVENT_FN(x) std::bind(&Engine::x, this, std::placeholders::_1)

Engine *Engine::s_Instance = nullptr;

Engine::Engine() {
  s_Instance = this;
  WindowProps window_props;
  window_props.Title = "test";
  window_props.Width = 2560;
  window_props.Height = 1440;

  m_Window = std::unique_ptr<Window>(Window::Create(window_props));
  m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

  unsigned int id;
  glGenVertexArrays(1, &id);
};

Engine::~Engine() {}

void Engine::PushLayer(Layer *layer) {
  m_LayerStack.PushLayer(layer);
  layer->OnAttatch();
}

void Engine::PushOverlay(Layer *layer) {
  m_LayerStack.PushOverlay(layer);
  layer->OnAttatch();
}

bool Engine::OnKeyPressed(KeyPressedEvent &e) {
  if (e.GetKeyCode() == Key::Escape) {
    m_Running = false;
  }
  return false;
}

void Engine::OnEvent(Event &e) {
  EventDispatcher dispatcher(e);
  dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
  dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(OnKeyPressed));

  for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
    (*--it)->OnEvent(e);
    if (e.Handled)
      break;
  }
}

void Engine::Run() {
  while (m_Running) {
    m_Window->OnUpdate();

    glClearColor(0.5, 0.5, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    for (Layer *layer : m_LayerStack)
      layer->OnUpdate();
  }
}

bool Engine::OnWindowClose(WindowCloseEvent &e) {
  m_Running = false;
  return true;
}
