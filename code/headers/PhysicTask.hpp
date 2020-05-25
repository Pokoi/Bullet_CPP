/*
 * File: PhysicTask.hpp
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

#include <btBulletDynamicsCommon.h>
#include <memory>
#include <RigidbodyComponent.hpp>
#include <CapsuleCollider.hpp>
#include <SphereCollider.hpp>
#include <BoxCollider.hpp>
#include <Constraint.hpp>

namespace BulletAssignment
{

    class PhysicTask
    {

        std::shared_ptr<btDiscreteDynamicsWorld>    world;
        std::shared_ptr<btCollisionDispatcher>      collision_dispatcher;

        btSequentialImpulseConstraintSolver         constraint_solver;
        btDefaultCollisionConfiguration             collision_configuration;
        btDbvtBroadphase                            overlapping;


    public:

        PhysicTask(btVector3 gravity = btVector3(0.f, -10.f, 0.f))
        {
            collision_dispatcher = std::make_shared<btCollisionDispatcher>(&collision_configuration);

            world = std::make_shared<btDiscreteDynamicsWorld>(
                                                                &collision_dispatcher, 
                                                                &overlapping,
                                                                &constraint_solver,
                                                                &collision_configuration
                                                             );
            world->setGravity(gravity);
        }

        void run(float delta)
        {
            world->stepSimulation(delta);
        }

        void add_rigidbody(std::shared_ptr <RigidbodyComponent>& rigidbody_component)
        {
            world->addRigidBody(&(*(rigidbody_component->get_rigidbody())));          
        }

        void add_constraint(std::shared_ptr <Constraint>& constraint)
        {
            world->addConstraint(&(*constraint->get_constraint()));
        }

    };
}

