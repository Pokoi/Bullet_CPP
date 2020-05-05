#pragma once

#include <Model.hpp>
#include <Model_Obj.hpp>
#include <memory>
#include <string>
#include "Rigidbody.hpp"

class Entity
{
    std::shared_ptr<glt::Model> model;
    Rigidbody rigidbody;


public:

    Entity()
    {
    }


    /**
    @brief Add a model by its filepath in format obj
    @param path The path of the file
    */
    void add_model(std::string path)
    {
        model = std::make_shared<glt::Model>(new glt::Model_Obj("../../assets/sphere.obj"));
    }

    /**
    @brief Get the model of the entity
    @return The model attached to this entity. If the entity does not have one, this returns nullptr
    */
    std::shared_ptr<glt::Model>& get_model()
    {
        return model;
    }

};
