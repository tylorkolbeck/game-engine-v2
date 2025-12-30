#pragma once
#include <sstream>
#include <string>

#include "Event.hpp"

class WindowResizeEvent : public Event {
public:
  WindowResizeEvent(unsigned int width, unsigned int height)
      : m_Width(width), m_Height(height) {}

  unsigned int GetWidth() const { return m_Width; }
  unsigned int GetHeight() const { return m_Height; }

  std::string ToString() const override {
    std::stringstream ss;
    ss << "WindowReiszeEvent: " << m_Width << ", " << m_Height << std::endl;
    return ss.str();
  }

  EVENT_CLASS_TYPE(WindowResize)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)

private:
  unsigned int m_Width, m_Height;
};

class WindowCloseEvent : public Event {
public:
  WindowCloseEvent() = default;

  EVENT_CLASS_TYPE(WindowClose)
  EVENT_CLASS_CATEGORY(EventCategoryApplication)
};
