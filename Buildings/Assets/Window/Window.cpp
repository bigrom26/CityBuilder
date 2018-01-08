#include "Window.hpp"

Window::Window()
{
  type = "G_WINDOW";
}

Window::~Window()
{
  ;
}

void Window::set(float w, float h)
{
  width = w;
  height = h;
  setBuiltIn();
  build();
}
