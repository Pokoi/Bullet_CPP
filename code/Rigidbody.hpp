#pragma once

#include <btBulletDynamicsCommon.h>
#include <vector>
#include <memory>

class Rigidbody
{
    std::shared_ptr<btRigidBody         >   rigid_body;
    std::shared_ptr<btDefaultMotionState>   motion_state;
    std::shared_ptr<btCollisionShape    >   collision_shape;
    btTransform transform;

public: 

    Rigidbody(float x_offset = 0, float y_offset = 0, float z_offset = 0) {}

    void Rigidbody_for_box_shape(float x_offset, float y_offset, float z_offset)
    {
        collision_shape = std::make_shared<btBoxShape>(btVector3(50, 1, 50));

        transform.setIdentity();
        transform.setOrigin(btVector3(x_offset, y_offset, z_offset));

        motion_state = std::make_shared<btDefaultMotionState>(transform);
        btRigidBody::btRigidBodyConstructionInfo info(0, motion_state.get(), collision_shape.get());
        rigid_body = std::make_shared<btRigidBody>(info);

    }

    void Rigidbody_for_sphere_shape(float radius)

    /**
    @brief Get the rigidbody component
    @return A reference to the rigidbody component
    */
    std::shared_ptr<btRigidBody>& get_rigidbody()
    {
        return rigid_body;
    }


};