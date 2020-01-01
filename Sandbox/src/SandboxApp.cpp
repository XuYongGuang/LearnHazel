#include "Hazel.h"
#include "gtc/type_ptr.hpp"

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