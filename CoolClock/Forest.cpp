#include "Forest.h"
#include "Application.h"
#include "MeshComponent.h"
#include "Renderer.h"
#include "BackgroundComponent.h"

ForestActor::ForestActor(Application* app)
    : Actor(app)
    , mode(MODE_0)
{


    SetPosition(Vector3(-0.0f, -0.0f, 0.0f));
    bgComp = new BackgroundComponent(this);
    bgComp->SetTexture(app->GetRenderer()->GetTexture("Assets/bg3.jpg"));
    
    
    texturename[0] = "Assets/bg1.jpg";
    texturename[1] = "Assets/bg2.jpg";
    texturename[2] = "Assets/bg3.jpg";
    texturename[3] = "Assets/bg4.jpg";

}

void ForestActor::UpdateActor(float deltaTime)
{

    time_t t = time(nullptr);
    const tm* localTime = localtime(&t);
    
    auto hour = localTime->tm_hour;
    
    //hour = 16;
    
    switch (hour)
    {
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            mode = MODE_0;
            GetApp()->GetRenderer()->SetAmbientLight(Vector3(0.3f, 0.3f, 0.3f));
            GetApp()->GetRenderer()->SetDirectionalLight(Vector3(0.8f, 0.8f, 0.8f));
            break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            mode = MODE_1;
            GetApp()->GetRenderer()->SetAmbientLight(Vector3(1.0f, 1.0f, 1.0f));
            GetApp()->GetRenderer()->SetDirectionalLight(Vector3(1.0f, 1.0f, 1.0f));
            break;
        case 16:
        case 17:
        case 18:
        case 19:
            mode = MODE_2;
            GetApp()->GetRenderer()->SetAmbientLight(Vector3(0.6f, 0.6f, 0.5f));
            GetApp()->GetRenderer()->SetDirectionalLight(Vector3(0.6f, 0.3f, 0.1f));
            break;
        case 20:
        case 21:
        case 22:
        case 23:
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            mode = MODE_3;
            GetApp()->GetRenderer()->SetAmbientLight(Vector3(0.5f, 0.5f, 0.6f));
            GetApp()->GetRenderer()->SetDirectionalLight(Vector3(0.35f, 0.25f, 0.45f));
            break;
        default:
            mode = MODE_0;
            break;
     }
    
    bgComp->SetTexture(GetApp()->GetRenderer()->GetTexture(texturename[(int)mode]));
}
