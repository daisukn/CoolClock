#include "Application.h"
#include "Actor.h"
#include "Renderer.h"
#include "BackgroundComponent.h"
#include "Texture.h"
#include "Shader.h"

#include <GL/glew.h>

// コンストラクタ
BackgroundComponent::BackgroundComponent(Actor* actor, int drawOrder)
    : Component(actor)
    , texture(nullptr)
    , DrawOrder(drawOrder)
    , TexWidth(0)
    , TexHeight(0)
{
    owner->GetApp()->GetRenderer()->AddBackground(this);
}

// デストラクタ
BackgroundComponent::~BackgroundComponent()
{
    // Rendererから削除
    owner->GetApp()->GetRenderer()->RemoveBackground(this);
}

// 描画
void BackgroundComponent::Draw(Shader* shader)
{
    if (texture){
        // Textureサイズからスケールマトリックスを作成
        Matrix4 scaleMat = Matrix4::CreateScale(static_cast<float>(TexWidth), static_cast<float>(TexHeight), 1.0f);
        // ワールド座標生成
        Matrix4 world = scaleMat * owner->GetWorldTransform();
        
        // シェーダー に送る
        shader->SetMatrixUniform("uWorldTransform", world);
        // アクティブ化
        texture->SetActive();
        // 描画
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    }
}

// テクスチャを設定
void BackgroundComponent::SetTexture(Texture* tex)
{
    texture = tex;
    TexWidth = texture->GetWidth();
    TexHeight = texture->GetHeight();
}
