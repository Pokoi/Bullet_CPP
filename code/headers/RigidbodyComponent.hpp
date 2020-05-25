/*
 * File: RigidbodyComponent.hpp
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

#include <Collider.hpp>
#include <memory>

namespace BulletAssignment
{
    class RigidbodyComponent
    {
    public:
        enum RigidbodyTypes { DYNAMIC, STATIC };

    private:

        std::shared_ptr<btRigidBody> rigidbody;
        std::shared_ptr<Collider>    collider;
        std::shared_ptr<btDefaultMotionState> motion_state;       

        class Entity* owner;

        RigidbodyTypes type;

    public:

        

        RigidbodyComponent 
                    (
                       std::shared_ptr <Collider> & collider, 
                       class Entity * owner,
                       RigidbodyTypes type
                    );
       

        std::shared_ptr<btRigidBody> get_rigidbody()
        {
            return rigidbody;
        }

        std::shared_ptr<Collider> get_collider()
        {
            return collider;
        }

        std::shared_ptr < btDefaultMotionState> get_motion_state()
        {
            return motion_state;
        }

        class Entity* get_owner()
        {
            return owner;
        }

        RigidbodyTypes get_type()
        {
            return type;
        }

    };
}