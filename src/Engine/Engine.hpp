#include "Events/ApplicationEvent.hpp"
#include "Events/Event.hpp"
#include "Layers/Layer.hpp"
#include "Layers/LayerStack.hpp"
#include "Windows/Window.hpp"
#include <memory>

class Engine {
public:
  Engine();
  virtual ~Engine();

  void Run();

  void OnEvent(Event &e);
  inline static Engine &Get() { return *s_Instance; }
  inline Window &GetWindow() { return *m_Window; }
  void PushLayer(Layer *layer);
  void PushOverlay(Layer *layer);

private:
  bool OnWindowClose(WindowCloseEvent &e);

  std::unique_ptr<Window> m_Window;
  bool m_Running = true;
  LayerStack m_LayerStack;
  Engine *CreateEngine();
  static Engine *s_Instance;
};
