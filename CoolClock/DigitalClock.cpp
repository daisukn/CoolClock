#include "DigitalClock.h"
#include "Application.h"
#include "Renderer.h"
#include "SpriteComponent.h"

DigitalClock::DigitalClock(Application* app)
    : Actor(app)
{
    float x = 80.0f;
    float y = -264.0f;
    
    // 時
    Actor* a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x, y, 0.0f));
    sc1 = new SpriteComponent(a);
    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += 64.0f, y, 0.0f));
    sc2 = new SpriteComponent(a);

    // コロン
    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += 64.0f, y, 0.0f));
    scColon = new SpriteComponent(a);

    
    // 分
    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += 64.0f, y, 0.0f));
    sc3 = new SpriteComponent(a);
    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += 64.0f, y, 0.0f));
    sc4 = new SpriteComponent(a);

    // ドット
    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += 64.0f, y, 0.0f));
    scDot = new SpriteComponent(a);

    // 秒
    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += 64.0f, y, 0.0f));
    sc5 = new SpriteComponent(a);
    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += 64.0f, y, 0.0f));
    sc6 = new SpriteComponent(a);


    x = 250.0f;
    y = -180.0f;
    float sc = 0.4f;
    float w = 64.0 * sc;
    // 年
    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += w, y, 0.0f));
    a->SetScale(sc);
    sc7 = new SpriteComponent(a);

    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += w, y, 0.0f));
    a->SetScale(sc);
    sc8 = new SpriteComponent(a);

    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += w, y, 0.0f));
    a->SetScale(sc);
    sc9 = new SpriteComponent(a);

    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += w, y, 0.0f));
    a->SetScale(sc);
    sc10 = new SpriteComponent(a);

    // スラッシュ
    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += w, y, 0.0f));
    a->SetScale(sc);
    scSlash1 = new SpriteComponent(a);

    // 月
    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += w, y, 0.0f));
    a->SetScale(sc);
    sc11 = new SpriteComponent(a);

    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += w, y, 0.0f));
    a->SetScale(sc);
    sc12 = new SpriteComponent(a);


    // スラッシュ
    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += w, y, 0.0f));
    a->SetScale(sc);
    scSlash2 = new SpriteComponent(a);

    // 日
    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += w, y, 0.0f));
    a->SetScale(sc);
    sc13 = new SpriteComponent(a);

    a = new Actor(this->GetApp());
    a->SetPosition(Vector3(x += w, y, 0.0f));
    a->SetScale(sc);
    sc14 = new SpriteComponent(a);

    
    texturename[0] = "Assets/num/0.png";
    texturename[1] = "Assets/num/1.png";
    texturename[2] = "Assets/num/2.png";
    texturename[3] = "Assets/num/3.png";
    texturename[4] = "Assets/num/4.png";
    texturename[5] = "Assets/num/5.png";
    texturename[6] = "Assets/num/6.png";
    texturename[7] = "Assets/num/7.png";
    texturename[8] = "Assets/num/8.png";
    texturename[9] = "Assets/num/9.png";

}

void DigitalClock::UpdateActor(float deltaTime)
{
    
    scColon->SetTexture(GetApp()->GetRenderer()->GetTexture("Assets/num/colon.png"));
    scDot->SetTexture(GetApp()->GetRenderer()->GetTexture("Assets/num/dot.png"));
    scSlash1->SetTexture(GetApp()->GetRenderer()->GetTexture("Assets/num/slash.png"));
    scSlash2->SetTexture(GetApp()->GetRenderer()->GetTexture("Assets/num/slash.png"));
    
    time_t t = time(nullptr);
    const tm* localTime = localtime(&t);
  
    
    
    sc1->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[localTime->tm_hour / 10]));
    sc2->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[localTime->tm_hour % 10]));
    sc3->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[localTime->tm_min / 10]));
    sc4->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[localTime->tm_min % 10]));
    sc5->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[localTime->tm_sec / 10]));
    sc6->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[localTime->tm_sec % 10]));


    
    
    // 年
    auto year = localTime->tm_year + 1900;
    sc7->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[year / 1000]));
    sc8->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[(year % 1000) / 100]));
    sc9->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[(year % 100) / 10]));
    sc10->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[year % 10]));
    
    // 月
    auto mon = localTime->tm_mon + 1;
    sc11->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[mon / 10]));
    sc12->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[mon % 10]));
    // 日
    auto day = localTime->tm_mday;
    sc13->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[day / 10]));
    sc14->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[day % 10]));

    
    
/*
    sc1->SetTexture(GetApp()->GetRenderer()->GetTexture("Assets/num/1.png"));
    sc2->SetTexture(GetApp()->GetRenderer()->GetTexture("Assets/num/2.png"));
    sc3->SetTexture(GetApp()->GetRenderer()->GetTexture("Assets/num/3.png"));
    sc4->SetTexture(GetApp()->GetRenderer()->GetTexture("Assets/num/4.png"));
    sc5->SetTexture(GetApp()->GetRenderer()->GetTexture("Assets/num/5.png"));
    sc6->SetTexture(GetApp()->GetRenderer()->GetTexture("Assets/num/6.png"));
*/
}
