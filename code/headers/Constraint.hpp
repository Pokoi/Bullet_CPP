/*
 * File: Constraint.hpp
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
#include <RigidbodyComponent.hpp>

#include <memory>
#include <string>


namespace BulletAssignment
{
    class Constraint
    {
        std::shared_ptr<btHingeConstraint> constraint;

        struct Motor
        {
            bool linear;
            bool angular;

            float linear_speed;
            float angular_speed; 

            float motor_impulse;

            Motor()
            {}

            Motor(float linear_speed, float angular_speed, float motor_impulse)
            {
                this->linear_speed  = linear_speed;
                this->angular_speed = angular_speed;
                this->motor_impulse = motor_impulse;
            }

            void activate_angular_motor(std::shared_ptr<btHingeConstraint> &constraint)
            {
                angular = true;
                constraint->enableAngularMotor(angular, angular_speed, motor_impulse);
            }

            void activate_linear_motor(std::shared_ptr <btHingeConstraint>& constraint)
            {
                linear = true;
                constraint->setMaxMotorImpulse(motor_impulse);
                constraint->setMotorTargetVelocity(linear_speed);
            }

            void deactivate_angular_motor(std::shared_ptr<btHingeConstraint>& constraint)
            {
                angular = false;
                constraint->enableAngularMotor(angular, angular_speed, motor_impulse);
            }

            void deactivate_linear_motor(std::shared_ptr <btHingeConstraint>& constraint)
            {
                linear = false;
                constraint->setMaxMotorImpulse(0.f);
                constraint->setMotorTargetVelocity(0.f);
            }

        } motor;

    public:

        Constraint  (
                        std::shared_ptr<RigidbodyComponent> & rigidbody_1,
                        std::shared_ptr<RigidbodyComponent> & rigidbody_2,
                        btVector3 pivot_rb_1,
                        btVector3 pivot_rb_2,
                        btVector3 axis_rb_1,
                        btVector3 axis_rb_2
                    )
        {
            
            constraint = std::make_shared <btHingeConstraint>   (
                                                                    * (rigidbody_1->get_rigidbody()),
                                                                    * (rigidbody_1->get_rigidbody()),
                                                                    pivot_rb_1,
                                                                    pivot_rb_2,
                                                                    axis_rb_1,
                                                                    axis_rb_2
                                                                ); 

        }

        std::shared_ptr<btHingeConstraint> get_constraint()
        {
            return constraint;
        }

        Motor& get_motor()
        {
            return motor;
        }

    };

}