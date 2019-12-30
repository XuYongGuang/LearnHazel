#include "Hazel.h"
#include "glm/gtc/type_ptr.hpp"

class Sandbox : public Hazel::Application
{
public:
    Sandbox()
    {

    }
    ~Sandbox()
    {

    }

};

Hazel::Application* Hazel::CreateApplication()
{

    return new Sandbox();
}