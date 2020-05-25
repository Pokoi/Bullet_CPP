#include <Entity.hpp>
#include <Scene.hpp>

namespace BulletAssignment
{
    Entity::Entity(
                    Scene* scene,
                    std::string name,
                    Entity* parent = nullptr
                  ):
                    transform {this},
                    name {name}
    {
        this->scene = scene;
    }


    void Entity::add_render_component(std::string file_path)
    {
        render_component = std::make_shared<RenderComponent>(file_path, this);
        scene->get_render_task().add_render_model(render_component);

    }

    void Entity::add_rigidbody(std::shared_ptr<Collider>& collider, RigidbodyComponent::RigidbodyTypes type)
    {
        rigidbody_component = std::make_shared<RigidbodyComponent>(collider, this, type);
        scene->get_physic_task().add_rigidbody(rigidbody_component);
    }


}