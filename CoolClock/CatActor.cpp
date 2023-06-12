#include "CatActor.h"
#include "Application.h"
#include "SkeletalMeshComponent.h"
#include "MoveComponent.h"
#include "Mesh.h"
#include "Renderer.h"
#include "ParticleComponent.h"


CatActor::CatActor(Application* app)
    : Actor(app)
    , bVisible(false)
{
    
    meshComp = new SkeletalMeshComponent(this);
    meshComp->SetMesh(app->GetRenderer()->GetMesh("Assets/cat.fbx"));
    meshComp->SetAnimID(0, PLAY_CYCLIC, 72.0f, 112.0f);
    
//    meshComp->SetAnimID(0, PLAY_CYCLIC, 1.0f, 20.0f);
//    meshComp->SetAnimID(0, PLAY_CYCLIC, 21.0f, 37.0f);
//    meshComp->SetAnimID(0, PLAY_CYCLIC, 55.0f, 71.0f);


    SetPosition(Vector3(80.0f, -100.0f, 100.0f));
    //SetScale(0.01);
    auto rot = Quaternion(Vector3::UnitY, Math::ToRadians(-3.0f));
    SetRotation(rot);
    
    moveComp = new MoveComponent(this);


    // パーティクルエフェクト
    Actor* a = new Actor(app);
    partComp = new ParticleComponent(a);
    partComp->SetTexture(app->GetRenderer()->GetTexture("Assets/smoke.jpg"));
    

    
}


void CatActor::UpdateActor(float deltaTime)
{
    
    if(bVisible)
    {
        
        float forwardSpeed = 60.0f;
        float angularSpeed = 0.0f;
        float dropSpeed = 0.0f;
        
        
        
        moveComp->SetForwardSpeed(forwardSpeed);
        moveComp->SetAngularSpeed(angularSpeed);
        moveComp->SetDropSpeed(dropSpeed);
        
        if(GetPosition().z > 0)
        {
            bVisible = false;
            meshComp->SetVisible(false);
        }
        

    }
    else
    {
        time_t t = time(nullptr);
        const tm* localTime = localtime(&t);
//        if( localTime->tm_min % 5 == 0)
        if( localTime->tm_sec == 0 )
        {
            SetPosition(Vector3(80.0f, -100.0f, -600.0f));
            //meshComp->SetAnimID(0, PLAY_CYCLIC, 72.0f, 112.0f);
            //meshComp->SetAnimID(0, PLAY_CYCLIC, 1.0f, 20.0f);
            meshComp->SetAnimID(0, PLAY_CYCLIC, 21.0f, 37.0f);
            //meshComp->SetAnimID(0, PLAY_CYCLIC, 55.0f, 71.0f);
            bVisible = true;
            meshComp->SetVisible(true);
            
//            Vector3 v = GetPosition() + Vector3::Transform(Vector3::UnitZ, GetRotation()) * 20;
 //           v += Vector3::Transform(Vector3::UnitY, GetRotation()) * 20;
            Vector3 v = GetPosition() + Vector3(0, 0, 100);
            partComp->GetOwner()->SetPosition(v);
            partComp->CreateParticles(Vector3(0,0,0), 5, 0.8f, 1.0f, 200.0f, false);
            
        }
      
    }
}
