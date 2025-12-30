#include "Events/ApplicationEvent.hpp"
#include "Events/Event.hpp"
#include "Windows/Window.hpp"
#include <memory>

class Engine {
public:
  Engine();
  virtual ~Engine();

  void Run();

  void OnEvent(Event &e);

private:
  bool OnWindowClose(WindowCloseEvent &e);

  std::unique_ptr<Window> m_Window;
  bool m_Running = true;

  Engine *CreateEngine();
};
