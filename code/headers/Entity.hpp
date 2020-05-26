/*
 * File: Entity.hpp
 * File Created: 25th May 2020
 * ––––––––––––––––––––––––
 * Author: Jesus Fermin, 'Pokoi', Villar  (hello@pokoidev.com)
 * ––––––––––––––––––––––––
 * MIT License
 *
 * Copyright (c) 2020 Pokoidev
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
                
                rigidbody_component->get_motion_state()->getWorldTransform(physic_transform);
                physic_transform.getOpenGLMatrix(glm::value_ptr(model_view));

                glm::vec3 render_offset = render_component->get_offset();
                glm::vec3 render_scale = render_component->get_scale();

                model_view[3][0] += render_offset[0] * render_scale[0];
                model_view[3][1] += render_offset[1] * render_scale[1];
                model_view[3][2] += render_offset[2] * render_scale[2];
                
                render_component->get_model()->set_transformation(model_view);

                render_component->get_model()->scale(render_scale[0], render_scale[1], render_scale[2]);
            }
        }

        void add_render_component(std::string file_path, glm::vec3 scale, glm::vec3 offset);
        
        void add_rigidbody(btVector3 location, std::shared_ptr<Collider> collider, RigidbodyComponent::RigidbodyTypes type);

        std::string get_name()
        {
            return name;
        }

        std::shared_ptr <RigidbodyComponent>& get_rigidbody_component()
        {
            return rigidbody_component;
        }

        std::shared_ptr <RenderComponent>& get_render_component()
        {
            return render_component;
        }

    };
}
