#pragma once

#include "Actor.h"
#include <string>

class DigitalClock : Actor
{
public:
    DigitalClock(class Application* app);
    
    // Update Override
    void UpdateActor(float deltaTime) override;
    
private:
    
    std::string texturename[10];
    
    // 時
    class SpriteComponent* sc1;
    class SpriteComponent* sc2;

    // コロン
    class SpriteComponent* scColon;

    // 分
    class SpriteComponent* sc3;
    class SpriteComponent* sc4;

    // ドット
    class SpriteComponent* scDot;

    // 秒
    class SpriteComponent* sc5;
    class SpriteComponent* sc6;
    

    // 年
    class SpriteComponent* sc7;
    class SpriteComponent* sc8;
    class SpriteComponent* sc9;
    class SpriteComponent* sc10;
    // スラッシュ
    class SpriteComponent* scSlash1;

    // 月
    class SpriteComponent* sc11;
    class SpriteComponent* sc12;

    // スラッシュ
    class SpriteComponent* scSlash2;

    
    // 日
    class SpriteComponent* sc13;
    class SpriteComponent* sc14;


};
