#pragma once

#include "Actor.h"



class CatActor : public Actor
{
public:
    CatActor(class Application* app);
    
    // Update Override
    void UpdateActor(float deltaTime) override;
    
private:
    class MoveComponent* moveComp;
    class SkeletalMeshComponent* meshComp;
    class ColliderComponent* collComp;
    
    bool bVisible;
    
    class ParticleComponent* partComp;

    //class BoundingVolumeComponent* boundingVolume;
};
