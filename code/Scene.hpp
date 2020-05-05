

#pragma once

#include <vector>
#include "Entity.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include <Render_Node.hpp>
#include <memory>
#include <string>
#include "PhysicWorld.hpp"

class Scene
{
private:

    std::vector<Entity&> entities;
    std::vector<std::shared_ptr<glt::Light>>  lights;

    Camera camera;

    std::shared_ptr< glt::Render_Node > scene; 

    PhysicWorld world;

public:

    Scene()
            : 
               scene(new glt::Render_Node),
               camera(20.f, 1.f, 50.f, 1.f)
    {
        scene->add("Camera", camera.get_opengltoolkit_camera());
    }

    /**
    @brief Adds a light to the scene
    @param light A reference to the light to add
    @param name The name of the light
    */
    void add_light(std::shared_ptr<glt::Light> & light, std::string name)
    {
        lights.push_back(light);
        scene->add(name, lights.at(lights.size() - 1));
    }

    /**
    @brief Adds an entity to the entity collection
    @param entity A reference to the entity to add
    @param name The name of the entity
    */
    void add_entity(Entity& entity, std::string name)
    {
        entities.push_back(entity);
        if (entity.get_model())
        {
            scene->add(name, entity.get_model());
        }
    }

    /**
    @brief Gets a reference to the render node
    @return A reference to the render node
    */
    std::shared_ptr<glt::Render_Node>& get_render_node()
    {
        return scene;
    }

    /**
    @brief Gets a reference to the physic world
    @return A reference to the physic world
    */
    PhysicWorld& get_physic_world()
    {
        return world;
    }

};