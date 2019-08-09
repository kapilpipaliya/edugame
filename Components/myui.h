
#ifndef MYUI_H
#define MYUI_H

#include <Urho3D/Urho3D.h>

#include <Urho3D/Container/Vector.h>
#include <Urho3D/Scene/LogicComponent.h>
#include <Urho3D/Scene/Component.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/Sprite.h>

using namespace Urho3D;


// Taken From Sample 38_SceneAndUILoad
class MyUI : public Component
{
    URHO3D_OBJECT(MyUI, Component)
public:
    MyUI(Context* context);

    SharedPtr<Scene> scene_;

    void OnNodeSet(Node* node) override;

    /// Handle toggle button 1 being pressed.
    void ToggleLight1(StringHash eventType, VariantMap& eventData);
    /// Handle toggle button 2 being pressed.
    void ToggleLight2(StringHash eventType, VariantMap& eventData);
};

#endif // MYUI_H
