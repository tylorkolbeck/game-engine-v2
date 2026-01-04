#include "ImGuiLayer.h"
#include "Engine/Engine.hpp"
#include "Events/MouseEvent.hpp"
#include "GLFW/glfw3.h" // This is a temp include
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}

ImGuiLayer::~ImGuiLayer() {}

void ImGuiLayer::OnAttatch() {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui::StyleColorsDark();

  auto *glfwWindow =
      static_cast<GLFWwindow *>(Engine::Get().GetWindow().GetNativeWindow());

  ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
  ImGui_ImplOpenGL3_Init("#version 430");

  float xscale = 1.0f, yscale = 1.0f;
  glfwGetWindowContentScale(glfwWindow, &xscale, &yscale);
  float scale = (xscale + yscale) * 0.5f;

  ImGuiStyle &style = ImGui::GetStyle();
  style.ScaleAllSizes(scale);

  ImGuiIO &io = ImGui::GetIO();
  io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
  io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
  io.Fonts->Clear();
  io.Fonts->AddFontDefault(); // or AddFontFromFileTTF(...)
  style.FontScaleMain = scale;
}

void ImGuiLayer::OnUpdate() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGuiIO &io = ImGui::GetIO();
  Engine &app = Engine::Get();
  io.DisplaySize =
      ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

  float time = (float)glfwGetTime();
  io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
  m_Time = time;

  static bool show = true;
  ImGui::ShowDemoWindow(&show);

  ImGui::Render();

  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiLayer::OnEvent(Event &event) {
  EventDispatcher dispatcher(event);
  dispatcher.Dispatch<MouseButtonPressedEvent>(
      BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
  dispatcher.Dispatch<MouseButtonReleasedEvent>(
      BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
  dispatcher.Dispatch<MouseMovedEvent>(
      BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
  dispatcher.Dispatch<MouseScrolledEvent>(
      BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
  dispatcher.Dispatch<KeyPressedEvent>(
      BIND_EVENT_FN(ImGuiLayer::OnPressedEvent));
  dispatcher.Dispatch<KeyReleasedEvent>(
      BIND_EVENT_FN(ImGuiLayer::OnReleasedEvent));
  dispatcher.Dispatch<MouseButtonPressedEvent>(
      BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
  dispatcher.Dispatch<WindowResizeEvent>(
      BIND_EVENT_FN(ImGuiLayer::OnWindowResizedEvent));
}
bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent &e) {
  ImGuiIO &io = ImGui::GetIO();
  io.MouseDown[e.GetMouseButton()] = true;
  return false;
}
bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &e) {
  ImGuiIO &io = ImGui::GetIO();
  io.MouseDown[e.GetMouseButton()] = false;
  return false;
}
bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent &e) {
  ImGuiIO &io = ImGui::GetIO();
  io.MousePos = ImVec2(e.GetX(), e.GetY());
  return false;
}
bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent &e) {
  ImGuiIO &io = ImGui::GetIO();
  io.MouseWheel += e.GetYOffset();
  io.MouseWheelH += e.GetXOffset();
  return false;
}

bool ImGuiLayer::OnPressedEvent(KeyPressedEvent &e) {
  ImGuiIO &io = ImGui::GetIO();
  // io.KeysData[e.GetKeyCode()] = true;
  return false;
}

bool ImGuiLayer::OnReleasedEvent(KeyReleasedEvent &e) { return false; }
bool ImGuiLayer::OnWindowResizedEvent(WindowResizeEvent &e) {
  ImGuiIO &io = ImGui::GetIO();
  io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
  io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

  return false;
}

void ImGuiLayer::OnDetach() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}
