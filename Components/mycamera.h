
#ifndef MOUSEMOVE_H
#define MOUSEMOVE_H

#include <Urho3D/Urho3D.h>

#include <Urho3D/Graphics/Camera.h>

#include <Urho3D/Container/Vector.h>
#include <Urho3D/Scene/LogicComponent.h>
#include <Urho3D/Scene/Component.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/Sprite.h>
#include <Urho3D/Input/Input.h>


using namespace Urho3D;

class MyCamera : public Camera
{
    URHO3D_OBJECT(MyCamera, Component)
public:
    explicit MyCamera(Context* context);
    void OnNodeSet(Node* node) override;

    /// Scene.
    SharedPtr<Scene> scene_;

    /// Camera yaw angle.
    float yaw_;
    /// Camera pitch angle.
    float pitch_;
    /// Flag to indicate whether touch input has been enabled.
    bool touchEnabled_;
    /// Mouse mode option to use in the sample.
    MouseMode useMouseMode_;

    // copy from Sample 38_SceneAndUILoad
    /// Subscribe to application-wide logic update event.
    void SubscribeToEvents();
    /// Reads input and moves the camera.
    void MoveCamera(float timeStep);
    /// Handle the logic update event.
    void HandleUpdate(StringHash eventType, VariantMap& eventData);
};

#endif // MOUSEMOVE_H
