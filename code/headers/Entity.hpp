#pragma once

#include <Model.hpp>
#include <Model_Obj.hpp>
#include <TransformComponent.hpp>
#include <RigidbodyComponent.hpp>
#include <RenderComponent.hpp>
#include <memory>
#include <string>


namespace BulletAssignment
{

    class Entity
    {
        TransformComponent transform;   

        std::shared_ptr <RenderComponent> render_component;
        std::shared_ptr <RigidbodyComponent> rigidbody_component;

        Entity* parent;
        class Scene* scene;

        std::string name;

    public:
        
        Entity(class Scene * scene, std::string name, Entity * parent = nullptr);

        TransformComponent& get_transform()
        {
            return transform;
        }

        Entity* get_parent()
        {
            return parent;
        }

        void update(float delta)
        {
            if (render_component && rigidbody_component)
            {
                btTransform physic_transform;
                glm::mat4 model_view;

                //rigidbody_component->get_motion_state()->setWorldTransform()
                rigidbody_component->get_motion_state()->getWorldTransform(physic_transform);
                physic_transform.getOpenGLMatrix(glm::value_ptr(model_view));

                render_component->get_model()->set_transformation(model_view);
            }
        }

        void add_render_component(std::string file_path);
        
        void add_rigidbody(std::shared_ptr<Collider>& collider, RigidbodyComponent::RigidbodyTypes type);       

        std::string get_name()
        {
            return name;
        }
    };
}
