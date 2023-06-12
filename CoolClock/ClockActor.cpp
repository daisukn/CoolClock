#include "ClockActor.h"


#include "ClockActor.h"


#include "Application.h"
#include "MeshComponent.h"
#include "Renderer.h"
#include "Mesh.h"

#include "ParticleComponent.h"

ClockActor::ClockActor(Application* app)
    : Actor(app)
{
    meshComp = new MeshComponent(this);
    meshComp->SetMesh(app->GetRenderer()->GetMesh("Assets/dial.lwo"));

    
    this->SetScale(0.005);
    this->SetPosition(Vector3(0,0,-90));
    
    Quaternion rot = Quaternion(Vector3::UnitY,  Math::ToRadians(180.0f));
    SetRotation(rot);
    
    
    ha = new HourActor(app);
    sa = new SecActor(app);
    ma = new MinActor(app);
    
    /*
    // パーティクルエフェクト
 //   Actor* a = new Actor(app);
    partComp = new ParticleComponent(this);
 //   a->SetPosition(Vector3(-0,5.5f,-15));
    partComp->SetTexture(app->GetRenderer()->GetTexture("Assets/explosions.png"));
    
    //partComp->GetOwner()->SetPosition(Vector3(0, 0, -100));
    partComp->CreateParticles(Vector3(-0, 2.0f, -0), 10, 1000, 1.1f, 10.0f, false);
    */
}

void ClockActor::UpdateActor(float deltaTime)
{
    
    //partComp->GetOwner()->SetPosition(Vector3(0, 0, -100));
    //（アクターとの相対位置、粒の総数、総表示時間、粒の表示時間、粒の大きさ、重力モード（未実装））
    //partComp->CreateParticles(Vector3(0,0,0), 10, 0.8f, 0.5f, 10.0f, false);

 /*   float angularSpeed  = 1;
    // 回転マトリックスを設定
    Quaternion rot = GetRotation();
    float angle = angularSpeed * deltaTime;

    Quaternion inc1(Vector3::UnitY, angle);
    Quaternion inc2(Vector3::UnitZ, angle);
    Quaternion inc3(Vector3::UnitX, angle);
    rot = Quaternion::Concatenate(rot, inc1);
//    rot = Quaternion::Concatenate(rot, inc2);
 //   rot = Quaternion::Concatenate(rot, inc3);

    SetRotation(rot);
 */
}


// 短針
HourActor::HourActor(Application* app)
    : Actor(app)
{
    meshComp = new MeshComponent(this);
    meshComp->SetMesh(app->GetRenderer()->GetMesh("Assets/hour.lwo"));

    
    this->SetScale(0.08);
    this->SetPosition(Vector3(0,0,-90));
}

void HourActor::UpdateActor(float deltaTime)
{
    
    
    time_t t = time(nullptr);
    const tm* localTime = localtime(&t);
  
    
    auto ang = localTime->tm_hour % 12 * 30.0f;
    auto ang_m = localTime->tm_min / 60.0f * 30.0f;
    ang += ang_m;
        
    Quaternion rot = Quaternion(Vector3::UnitZ, Math::ToRadians(ang));
    SetRotation(rot);
    
}

// 長針
MinActor::MinActor(Application* app)
    : Actor(app)
{
    meshComp = new MeshComponent(this);
    meshComp->SetMesh(app->GetRenderer()->GetMesh("Assets/min.lwo"));

    
    this->SetScale(0.1);
    this->SetPosition(Vector3(0,0,-90));
}

void MinActor::UpdateActor(float deltaTime)
{

    
    time_t t = time(nullptr);
    const tm* localTime = localtime(&t);
  
    
    auto ang = localTime->tm_min * 6.0f;
        
    Quaternion rot = Quaternion(Vector3::UnitZ, Math::ToRadians(ang));
    SetRotation(rot);
    
}

// 秒針
SecActor::SecActor(Application* app)
    : Actor(app)
{
    meshComp = new MeshComponent(this);
    meshComp->SetMesh(app->GetRenderer()->GetMesh("Assets/sec.lwo"));

    
    this->SetScale(0.1);
    this->SetPosition(Vector3(0,0,-90));
}


void SecActor::UpdateActor(float deltaTime)
{


    
    time_t t = time(nullptr);
    const tm* localTime = localtime(&t);
  
    
    auto ang = localTime->tm_sec * 6.0f;
        
    Quaternion rot = Quaternion(Vector3::UnitZ, Math::ToRadians(ang));
    SetRotation(rot);
    
    
/*
    float angularSpeed  = 10;
    // 回転マトリックスを設定
    Quaternion rot = GetRotation();
    float angle = angularSpeed * deltaTime;

    Quaternion inc(Vector3::UnitZ, angle);
    rot = Quaternion::Concatenate(rot, inc);
    
    SetRotation(rot);
 */
}
