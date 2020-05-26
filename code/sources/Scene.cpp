/*
 * File: Scene.cpp
 * File Created: 26 May 2020
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

#include <Scene.hpp>

namespace BulletAssignment
{
    Scene::Scene(
                    std::string window_name,
                    unsigned int width,
                    unsigned int height
                ) :
                    view{ window_name, width, height },
                    world{}
    {
        aspect_ratio = float(width) / float(height);


        //Player creation           
        std::shared_ptr<Entity> player(new Entity(this, "player", nullptr));
        player->add_render_component("../../assets/sphere.obj", glm::vec3(1.25f, 1.25f, 1.25f), glm::vec3(-0.25f, -0.25f, -0.25f));
        std::shared_ptr<CapsuleCollider> player_collider(new CapsuleCollider(1, btVector3(0.0, 0.0, 0.0), CapsuleCollider::Dimensions(0.5f, 0.5f)));
        player->add_rigidbody(btVector3(0.f, 3.f, -8.f), player_collider, RigidbodyComponent::RigidbodyTypes::DYNAMIC);

        entities["player"] = player;

        // Floor
        std::shared_ptr<Entity> floor(new Entity(this, "floor", nullptr));
        floor->add_render_component("../../assets/cube.obj", glm::vec3(2.5f, 1.5f, 2.5f), glm::vec3(-0.5f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> floor_collider(new BoxCollider(10, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(1.f, 1.f, 1.f)));
        floor->add_rigidbody(btVector3(0.f, -10.f, -8.f), floor_collider, RigidbodyComponent::RigidbodyTypes::STATIC);

        entities["floor"] = floor;

        // Stair 1

        // step1 
        std::shared_ptr<Entity> step_1(new Entity(this, "step_1", nullptr));
        step_1->add_render_component("../../assets/cube.obj", glm::vec3(1.f, 1.5f, 2.5f), glm::vec3(-0.2f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> step_1_collider(new BoxCollider(10, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(0.4f, 1.f, 1.f)));
        step_1->add_rigidbody(btVector3(-5.f, -10.f, -8.f), step_1_collider, RigidbodyComponent::RigidbodyTypes::STATIC);

        entities["step_1"] = step_1;

        // step2 
        std::shared_ptr<Entity> step_2(new Entity(this, "step_2", nullptr));
        step_2->add_render_component("../../assets/cube.obj", glm::vec3(1.f, 1.5f, 2.5f), glm::vec3(-0.2f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> step_2_collider(new BoxCollider(10, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(0.4f, 1.f, 1.f)));
        step_2->add_rigidbody(btVector3(-6.f, -9.5f, -8.f), step_2_collider, RigidbodyComponent::RigidbodyTypes::STATIC);

        entities["step_2"] = step_2;

        // step3 
        std::shared_ptr<Entity> step_3(new Entity(this, "step_3", nullptr));
        step_3->add_render_component("../../assets/cube.obj", glm::vec3(1.f, 1.5f, 2.5f), glm::vec3(-0.2f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> step_3_collider(new BoxCollider(10, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(0.4f, 1.f, 1.f)));
        step_3->add_rigidbody(btVector3(-7.f, -9.f, -8.f), step_3_collider, RigidbodyComponent::RigidbodyTypes::STATIC);

        entities["step_3"] = step_3;

        // step4 
        std::shared_ptr<Entity> step_4(new Entity(this, "step_4", nullptr));
        step_4->add_render_component("../../assets/cube.obj", glm::vec3(1.f, 1.5f, 2.5f), glm::vec3(-0.2f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> step_4_collider(new BoxCollider(10, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(0.4f, 1.f, 1.f)));
        step_4->add_rigidbody(btVector3(-8.f, -8.5f, -8.f), step_4_collider, RigidbodyComponent::RigidbodyTypes::STATIC);

        entities["step_4"] = step_4;

        // End stair platform

        std::shared_ptr<Entity> end_stair(new Entity(this, "end_stair", nullptr));
        end_stair->add_render_component("../../assets/cube.obj", glm::vec3(2.5f, 1.5f, 2.5f), glm::vec3(-0.5f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> end_stair_collider(new BoxCollider(10, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(1.f, 1.f, 1.f)));
        end_stair->add_rigidbody(btVector3(-9.5f, -8.f, -8.f), end_stair_collider, RigidbodyComponent::RigidbodyTypes::STATIC);

        entities["end_stair"] = end_stair;

        // Horizontal platform

        std::shared_ptr<Entity> horizontal_platform(new Entity(this, "horizontal_platform", nullptr));
        horizontal_platform->add_render_component("../../assets/cube.obj", glm::vec3(2.5f, 0.75f, 2.5f), glm::vec3(-0.5f, -0.375f, -0.5f));

        std::shared_ptr<BoxCollider> horizontal_platform_collider(new BoxCollider(500, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(1.f, 1.f, 1.f)));
        horizontal_platform->add_rigidbody(btVector3(-12.f, -8.f, -8.f), horizontal_platform_collider, RigidbodyComponent::RigidbodyTypes::DYNAMIC);
        horizontal_platform->get_rigidbody_component()->get_rigidbody()->setGravity(btVector3(0.f, 0.f, 0.f));
        entities["horizontal_platform"] = horizontal_platform;

        // key platform

        std::shared_ptr<Entity> key_platform(new Entity(this, "key_platform", nullptr));
        key_platform->add_render_component("../../assets/cube.obj", glm::vec3(2.5f, 1.5f, 2.5f), glm::vec3(-0.5f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> key_platform_collider(new BoxCollider(10, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(1.f, 1.f, 1.f)));
        key_platform->add_rigidbody(btVector3(-9.5f, -8.f, -18.f), key_platform_collider, RigidbodyComponent::RigidbodyTypes::STATIC);
        
        entities["key_platform"] = key_platform;


        // key 
        
        std::shared_ptr<Entity> key(new Entity(this, "key", nullptr));
        key->add_render_component("../../assets/bunny.obj", glm::vec3(1.25f, 1.25f, 1.25f), glm::vec3(-0.5f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> key_collider(new BoxCollider(500, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(1.f, 1.f, 1.f)));
        key->add_rigidbody(btVector3(-8.5f, -5.f, -18.f), key_collider, RigidbodyComponent::RigidbodyTypes::DYNAMIC);
        key->get_rigidbody_component()->get_rigidbody()->setGravity(btVector3(0.f, 0.f, 0.f));
        key->get_rigidbody_component()->get_rigidbody()->setAngularVelocity(btVector3(0.f, 1.f, 0.f));

        entities["key"] = key;


        // Stair 2

        // step5
        std::shared_ptr<Entity> step_5(new Entity(this, "step_5", nullptr));
        step_5->add_render_component("../../assets/cube.obj", glm::vec3(1.f, 1.5f, 2.5f), glm::vec3(-0.2f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> step_5_collider(new BoxCollider(10, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(0.4f, 1.f, 1.f)));
        step_5->add_rigidbody(btVector3(-7.f, -7.5f, -18.f), step_5_collider, RigidbodyComponent::RigidbodyTypes::STATIC);

        entities["step_5"] = step_5;

        // step6 
        std::shared_ptr<Entity> step_6(new Entity(this, "step_6", nullptr));
        step_6->add_render_component("../../assets/cube.obj", glm::vec3(1.f, 1.5f, 2.5f), glm::vec3(-0.2f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> step_6_collider(new BoxCollider(10, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(0.4f, 1.f, 1.f)));
        step_6->add_rigidbody(btVector3(-6.f, -7.f, -18.f), step_6_collider, RigidbodyComponent::RigidbodyTypes::STATIC);

        entities["step_6"] = step_6;

        // step7
        std::shared_ptr<Entity> step_7(new Entity(this, "step_7", nullptr));
        step_7->add_render_component("../../assets/cube.obj", glm::vec3(1.f, 1.5f, 2.5f), glm::vec3(-0.2f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> step_7_collider(new BoxCollider(10, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(0.4f, 1.f, 1.f)));
        step_7->add_rigidbody(btVector3(-5.f, -6.5f, -18.f), step_7_collider, RigidbodyComponent::RigidbodyTypes::STATIC);

        entities["step_7"] = step_7;

        // step8 
        std::shared_ptr<Entity> step_8(new Entity(this, "step_8", nullptr));
        step_8->add_render_component("../../assets/cube.obj", glm::vec3(1.f, 1.5f, 2.5f), glm::vec3(-0.2f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> step_8_collider(new BoxCollider(10, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(0.4f, 1.f, 1.f)));
        step_8->add_rigidbody(btVector3(-4.f, -6.f, -18.f), step_8_collider, RigidbodyComponent::RigidbodyTypes::STATIC);

        entities["step_8"] = step_8;

        // vertical platform

        std::shared_ptr<Entity> vertical_platform(new Entity(this, "vertical_platform", nullptr));
        vertical_platform->add_render_component("../../assets/cube.obj", glm::vec3(2.5f, 0.75f, 2.5f), glm::vec3(-0.5f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> vertical_platform_collider(new BoxCollider(500, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(1.f, 1.f, 1.f)));
        vertical_platform->add_rigidbody(btVector3(-2.f, -6.f, -18.f), vertical_platform_collider, RigidbodyComponent::RigidbodyTypes::DYNAMIC);
        vertical_platform->get_rigidbody_component()->get_rigidbody()->setGravity(btVector3(0.f, 0.f, 0.f));

        entities["vertical_platform"] = vertical_platform;

        // high platform
        std::shared_ptr<Entity> high_platform(new Entity(this, "high_platform", nullptr));
        high_platform->add_render_component("../../assets/cube.obj", glm::vec3(2.5f, 0.75f, 2.5f), glm::vec3(-0.5f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> high_platform_collider(new BoxCollider(500, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(1.f, 1.f, 1.f)));
        high_platform->add_rigidbody(btVector3(0.f, 7.f, -18.f), high_platform_collider, RigidbodyComponent::RigidbodyTypes::STATIC);        

        entities["high_platform"] = high_platform;

        // high horizontal platform
        std::shared_ptr<Entity> high_horizontal_platform(new Entity(this, "high_horizontal_platform", nullptr));
        high_horizontal_platform->add_render_component("../../assets/cube.obj", glm::vec3(2.5f, 0.75f, 2.5f), glm::vec3(-0.5f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> high_horizontal_platform_collider(new BoxCollider(500, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(1.f, 1.f, 1.f)));
        high_horizontal_platform->add_rigidbody(btVector3(2.5f, 7.f, -10.f), high_horizontal_platform_collider, RigidbodyComponent::RigidbodyTypes::DYNAMIC);
        high_horizontal_platform->get_rigidbody_component()->get_rigidbody()->setGravity(btVector3(0.f, 0.f, 0.f));
        
        entities["high_horizontal_platform"] = high_horizontal_platform;

        // door
        std::shared_ptr<Entity> door(new Entity(this, "door", nullptr));
        door->add_render_component("../../assets/cube.obj", glm::vec3(2.5f, 0.5f, 2.5f), glm::vec3(-0.5f, -0.5f, -0.5f));

        std::shared_ptr<BoxCollider> door_collider(new BoxCollider(10, btVector3(0.0, 0.0, 0.0), BoxCollider::Dimensions(1.f, 1.f, 1.f)));
        door->add_rigidbody(btVector3(0.f, 7.f, -8.f), door_collider, RigidbodyComponent::RigidbodyTypes::STATIC);

        entities["door"] = door;


        


    }

    void Scene::platform_movements(float delta)
    {
        enum MovementStates { TOPOSITIVE, TONEGATIVE };

        float static platform_speed = 2.f;
        static MovementStates horizontal_movement_state = TONEGATIVE;
        static MovementStates vertical_movement_state = TONEGATIVE;
        static MovementStates high_horizontal_movement_state = TONEGATIVE;

        btVector3 horizontal_platform_position = entities["horizontal_platform"]->get_rigidbody_component()->get_rigidbody()->getWorldTransform().getOrigin();
        btVector3 high_horizontal_platform_position = entities["high_horizontal_platform"]->get_rigidbody_component()->get_rigidbody()->getWorldTransform().getOrigin();
        btVector3 vertical_platform_position = entities["vertical_platform"]->get_rigidbody_component()->get_rigidbody()->getWorldTransform().getOrigin();

        if (horizontal_platform_position[2] > -7.0f)
        {
            horizontal_movement_state = TONEGATIVE;
        }

        else if (horizontal_platform_position[2] < -19.0f)
        {
            horizontal_movement_state = TOPOSITIVE;
        }

        if (high_horizontal_platform_position[2] > -7.0f)
        {
            high_horizontal_movement_state = TONEGATIVE;
        }

        else if (high_horizontal_platform_position[2] < -19.0f)
        {
            high_horizontal_movement_state = TOPOSITIVE;
        }

        if (vertical_platform_position[1] < -6.f)
        {
            vertical_movement_state = TOPOSITIVE;
        }
        else if (vertical_platform_position[1] > 7.f)
        {
            vertical_movement_state = TONEGATIVE;
        }

        switch (horizontal_movement_state)
        {
        case TOPOSITIVE: entities["horizontal_platform"]->get_rigidbody_component()->get_rigidbody()->setLinearVelocity(btVector3(0, 0, +platform_speed)); break;
        case TONEGATIVE: entities["horizontal_platform"]->get_rigidbody_component()->get_rigidbody()->setLinearVelocity(btVector3(0, 0, -platform_speed)); break;
        }

        switch (high_horizontal_movement_state)
        {
        case TOPOSITIVE: entities["high_horizontal_platform"]->get_rigidbody_component()->get_rigidbody()->setLinearVelocity(btVector3(0, 0, +platform_speed)); break;
        case TONEGATIVE: entities["high_horizontal_platform"]->get_rigidbody_component()->get_rigidbody()->setLinearVelocity(btVector3(0, 0, -platform_speed)); break;
        }

        switch (vertical_movement_state)
        {
        case TOPOSITIVE: entities["vertical_platform"]->get_rigidbody_component()->get_rigidbody()->setLinearVelocity(btVector3(0, +platform_speed, 0)); break;
        case TONEGATIVE: entities["vertical_platform"]->get_rigidbody_component()->get_rigidbody()->setLinearVelocity(btVector3(0, -platform_speed, 0)); break;
        }

        entities["horizontal_platform"]->get_rigidbody_component()->get_rigidbody()->setAngularVelocity(btVector3(0, 0, 0));
        entities["high_horizontal_platform"]->get_rigidbody_component()->get_rigidbody()->setAngularVelocity(btVector3(0, 0, 0));
        entities["vertical_platform"]->get_rigidbody_component()->get_rigidbody()->setAngularVelocity(btVector3(0, 0, 0));

    }

}