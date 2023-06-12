#pragma once
#include "Actor.h"

#include <string>

enum ForestMode
{
    MODE_0 = 0,
    MODE_1 = 1,
    MODE_2 = 2,
    MODE_3 = 3
};


class ForestActor : public Actor
{
    
public:
    ForestActor(class Application* app);
    
    // update override
    void UpdateActor(float deltaTime) override;
    
private:
    class BackgroundComponent* bgComp;
    
    std::string texturename[4];
    ForestMode mode;

};

