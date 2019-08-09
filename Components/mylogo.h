
#ifndef MYLOGO_H
#define MYLOGO_H

#include <Urho3D/Urho3D.h>

#include <Urho3D/Container/Vector.h>
#include <Urho3D/Scene/LogicComponent.h>
#include <Urho3D/Scene/Component.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/Sprite.h>
#include <Urho3D/Input/Input.h>

using namespace Urho3D;

class MyLogo : public Component
{
    URHO3D_OBJECT(MyLogo, Component)
public:
    explicit MyLogo(Context* context);

    /// Create logo.
    void OnNodeSet(Node* node) override;

    /// Logo sprite.
    SharedPtr<Sprite> logoSprite_;
};

#endif // MYLOGO_H
