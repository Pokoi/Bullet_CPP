#pragma once

#include <Camera.hpp>

class Camera
{
    std::shared_ptr< glt::Camera > camera; 

public:

    Camera(float fov, float near, float far, float aspect_ratio) : camera(new glt::Camera(fov, near, far, aspect_ratio))
    {
    
    }

    std::shared_ptr<glt::Camera>& get_opengltoolkit_camera()
    {
        return camera;
    }

    void set_position(float x, float y, float z)
    {
        camera->translate(glt::Vector3(x, y, z));
    }


};