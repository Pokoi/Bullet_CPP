#pragma once

#include <btBulletDynamicsCommon.h>
#include <memory>

class PhysicWorld
{

    // Collision configuration contains default setup for memory, collision setup.
    // Advanced users can create their own configuration.

    btDefaultCollisionConfiguration collisionConfiguration;

    // Use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded).

    btCollisionDispatcher collisionDispatcher;

    // btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.

    btDbvtBroadphase overlappingPairCache;

    // The default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded).

    btSequentialImpulseConstraintSolver constraintSolver;

    // Create and configure the physiscs world:

    std::shared_ptr< btDiscreteDynamicsWorld > dynamicsWorld;
    


public:

    PhysicWorld() : 
                    collisionDispatcher (&collisionDispatcher),
                    dynamicsWorld (new btDiscreteDynamicsWorld 
                                                                (
                                                                &collisionDispatcher,
                                                                &overlappingPairCache,
                                                                &constraintSolver,
                                                                &collisionConfiguration
                                                                )
                                   )
    {
    
        dynamicsWorld->setGravity(btVector3(0, -10, 0));


    }


};
