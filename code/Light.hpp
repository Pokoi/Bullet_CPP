#pragma once

#include <Light.hpp>
#include <memory>

class Light
{
    std::shared_ptr< glt::Light> light;

public:

    Light()
        :
        light (new glt::Light())
    {
        
    }

    void set_position(float x, float y, float z)
    {
        light->translate(glt::Vector3(x, y, z));
    }

};