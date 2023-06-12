#include "Application.h"
#include "Actor.h"
#include "Renderer.h"
#include "SpriteComponent.h"
#include "MeshComponent.h"
#include "Mesh.h"
#include "SkeletalMeshComponent.h"
#include "ParticleComponent.h"

#include "InputSystem.h"

#include <algorithm>


#include "ClockActor.h"
#include "Forest.h"
#include "WolfActor.h"
#include "CatActor.h"
#include "DigitalClock.h"

// コンストラクタ
Application::Application()
    : bActive(false)
    , bUpdatingActors(false)
{
    renderer = new Renderer();
    inputSys = new InputSystem();
}

// デストラクタ
Application::~Application()
{

    
    delete inputSys;
    // Rendererのdeleteタイミング注意
    delete renderer;

}


// アプリ初期化
bool Application::Initialize()
{
    
    // SDL初期化
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Failed to init SDL\n";
        return false;
    }
    
    // Renderer初期化
    renderer->Initialize("Clock", 1280.0f, 720.0f);

    // 入力システム初期化
    inputSys->Initialize();
    
    // データ ロード、主にRendererに登録されるもの。
    LoadData();
    
    bActive = true;
    ticksCount = SDL_GetTicks();
    return true;
}


// メインループ
void Application::RunLoop()
{
    while (bActive)
    {
        ProcessInput();
        UpdateGame();
        Draw();
    }
}

// 描画処理 Rendererが描画する
void Application::Draw()
{
    renderer->Draw();
}

// 終了処理
void Application::Shutdown()
{
    UnloadData();
    // Unloadしなくて良いか？
    inputSys->Shutdown();
    renderer->Shutdown();
    SDL_Quit();
}

// 入力受付
void Application::ProcessInput(){
    
    // 前の状態を保存
    inputSys->PrepareForUpdate();
    
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
                
        case SDL_QUIT:
            bActive = false;
            break;
        }
    }

    inputSys->Update();
    const InputState& state = inputSys->GetState();
        
    if (state.Keyboard.GetKeyState(SDL_SCANCODE_ESCAPE) == EReleased)
    {
        bActive = false;
    }

    //UpdatingActors = true;

    //UpdatingActors = false;
    
    
    // 配下のActorsに渡す
    for (auto actor : actors)
    {
        actor->ProcessInput(state);
    }
}


// Actor追加
void Application::AddActor(Actor* actor)
{
    // メインのActorsがUpdate中はPendingに追加
    if (bUpdatingActors)
    {
        pendingActors.emplace_back(actor);
    }
    else
    {
        actors.emplace_back(actor);
    }
}

// Actor削除
void Application::RemoveActor(Actor* actor)
{
    // Pendingにないか確認
    auto iter = std::find(pendingActors.begin(), pendingActors.end(), actor);
    if (iter != pendingActors.end())
    {
        std::iter_swap(iter, pendingActors.end() - 1);
        pendingActors.pop_back();
    }

    // actorsにある場合は削除
    iter = std::find(actors.begin(), actors.end(), actor);
    if (iter != actors.end())
    {
        std::iter_swap(iter, actors.end() - 1);
        actors.pop_back();
    }
}


// データ解放
void Application::UnloadData()
{
    while (actors.empty())
    {
        delete actors.back();
    }

    if (renderer)
    {
        renderer->UnloadData();
    }
}

// Actors, Renderer関連
void Application::LoadData()
{
    

    //Actor*
/*    Actor* a = new Actor(this);
    a->SetPosition(Vector3(-350.0f, -350.0f, 0.0f));
    SpriteComponent* sc = new SpriteComponent(a);
    sc->SetTexture(renderer->GetTexture("Assets/HealthBar.png"));
*/
    
    
    Matrix4 view = Matrix4::CreateLookAt(Vector3(0,0,0), Vector3(0,0,-100), Vector3(0,1,0));
    renderer->SetViewMatrix(view);
    

    ClockActor* ca = new ClockActor(this);
    ForestActor* fa = new ForestActor(this);
    WolfActor* wa = new WolfActor(this);
    CatActor* cat = new CatActor(this);
    DigitalClock* dc = new DigitalClock(this);


    

    
    // ライト
    renderer->SetAmbientLight(Vector3(0.8f, 0.8f, 0.8f));
    DirectionalLight& dir = renderer->GetDirectionalLight();
    dir.Direction = Vector3(0.7f, -7.0f, 7.0f);
    dir.DiffuseColor = Vector3(0.5f, 0.5f, 0.5f);
    dir.SpecColor = Vector3(0.5f, 0.5f, 0.5f);
    
  
}

// ゲームメインルーチン
void Application::UpdateGame()
{
    
    // FPS60固定
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksCount + 16))
        ;

    float deltaTime = (SDL_GetTicks() - ticksCount) / 1000.0f;
    if (deltaTime > 0.05f)
    {
        deltaTime = 0.05f;
    }
    ticksCount = SDL_GetTicks();


    
    // Actorsメイン呼び出し
    bUpdatingActors = true;
    for (auto a : actors)
    {
        a->Update(deltaTime);
    }
    bUpdatingActors = false;

    // Pendingがある場合はActorsに移動
    for (auto p : pendingActors)
    {
        p->ComputeWorldTransform();
        actors.emplace_back(p);
    }
    pendingActors.clear();

    // EDeadフラグのアクターは削除
    std::vector<Actor*> deadActors;
    for (auto a : actors)
    {
        if (a->GetState() == Actor::EDead)
        {
            deadActors.emplace_back(a);
        }
    }
    
    for (auto a : deadActors)
    {
        delete a;
    }

}
