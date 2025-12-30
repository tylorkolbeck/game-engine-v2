#include "Engine.hpp"

#define BIND_EVENT_FN(x) std::bind(&Engine::x, this, std::placeholders::_1)

Engine::Engine() {
  m_Window = std::unique_ptr<Window>(Window::Create());
  m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
};

Engine::~Engine() {}

void Engine::OnEvent(Event &e) {
  EventDispatcher dispatcher(e);
  dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
}

void Engine::Run() {
  while (m_Running) {

    m_Window->OnUpdate();
  }
}

bool Engine::OnWindowClose(WindowCloseEvent &e) {
  m_Running = false;
  return true;
}
