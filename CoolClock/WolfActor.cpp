#include "WolfActor.h"
#include "Application.h"
#include "SkeletalMeshComponent.h"
#include "MoveComponent.h"
#include "Mesh.h"
#include "Renderer.h"


WolfActor::WolfActor(Application* app)
    : Actor(app)
{
    
    meshComp = new SkeletalMeshComponent(this);
    meshComp->SetMesh(app->GetRenderer()->GetMesh("Assets/wolf.fbx"));
    meshComp->SetAnimID(2, PLAY_CYCLIC);
    

    SetPosition(Vector3(100.0f, -100.0f, -200.0f));
    //SetScale(0.01);
    
    
    //app->GetPhysWorld()->AddActor(this);
    moveComp = new MoveComponent(this);


   

}


void WolfActor::UpdateActor(float deltaTime)
{
    float forwardSpeed = 0.0f;
    float angularSpeed = 0.0f;
    float dropSpeed = 0.0f;
    
 
    
    moveComp->SetForwardSpeed(forwardSpeed);
    moveComp->SetAngularSpeed(angularSpeed);
    moveComp->SetDropSpeed(dropSpeed);
    
/*
    SetPosition(GetPosition());
    SetRotation(GetRotation());
    SetScale(GetScale());
 */
    
    
}


