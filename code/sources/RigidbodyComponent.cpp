/*
 * File: RigidbodyComponent.cpp
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


#include <RigidbodyComponent.hpp>
#include <Entity.hpp>

namespace BulletAssignment
{
    RigidbodyComponent::RigidbodyComponent(     
                                            btVector3 location,
                                            std::shared_ptr <Collider>& collider,
                                            Entity* owner,
                                            RigidbodyTypes type
                                        )
    {
        this->owner     = owner;
        this->collider  = collider;
        this->type      = type;

        btTransform transform;
        transform.setIdentity();

        auto position = owner->get_transform().get_position();

        transform.setOrigin(location);
        
        motion_state = std::make_shared< btDefaultMotionState >(transform);

        auto configuration = collider->get_configuration();

        if (type == RigidbodyTypes::DYNAMIC)
        {
            btRigidBody::btRigidBodyConstructionInfo construction_info  (
                                                                            configuration.mass,
                                                                            &(*motion_state),
                                                                            &(*(configuration.shape)),
                                                                            configuration.inertia
                                                                        );
            rigidbody = std::make_shared<btRigidBody>(construction_info);
            rigidbody->setActivationState(DISABLE_DEACTIVATION);
        }

        else if (type == RigidbodyTypes::STATIC)
        {            

            btRigidBody::btRigidBodyConstructionInfo construction_info(
                                                                        0,
                                                                        &(*motion_state),
                                                                        &(*(configuration.shape))                                                                        
                                                                        );

            rigidbody = std::make_shared<btRigidBody>(construction_info);
            
        }

    }
}