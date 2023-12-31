#pragma once

#include "Component.h"

// スプライト管理 Componentを継承
class BackgroundComponent : public Component
{
public:
    BackgroundComponent(class Actor* owner, int drawOrder = 100);
    ~BackgroundComponent();

    virtual void Draw(class Shader* shader);
    virtual void SetTexture(class Texture* texture);

    int GetDrawOrder() const { return DrawOrder; }
    int GetTexHeight() const { return TexHeight; }
    int GetTexWidth() const { return TexWidth; }

    
protected:
    // スプライト用のテクスチャ
    class Texture* texture;
    int DrawOrder;
    int TexWidth;
    int TexHeight;


};


