#pragma once

#include "Actor.h"

class ClockActor : public Actor
{
    
public:
    ClockActor(class Application* app);
    
    // update override
    void UpdateActor(float deltaTime) override;
    
private:
    class MeshComponent* meshComp;

    class ParticleComponent* partComp;
    
    class HourActor* ha;
    class SecActor* sa;
    class MinActor* ma;
};

// 短針
class HourActor : public Actor
{
    
public:
    HourActor(class Application* app);
    
    // update override
    void UpdateActor(float deltaTime) override;
    
private:
    class MeshComponent* meshComp;

};

// 長針
class MinActor : public Actor
{
    
public:
    MinActor(class Application* app);
    
    // update override
    void UpdateActor(float deltaTime) override;
    
private:
    class MeshComponent* meshComp;

};

// 秒針
class SecActor : public Actor
{
    
public:
    SecActor(class Application* app);
    
    // update override
    void UpdateActor(float deltaTime) override;
    
private:
    class MeshComponent* meshComp;

};

