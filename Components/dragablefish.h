#ifndef DRAGABLEFISH_H
#define DRAGABLEFISH_H

#include <Urho3D/Urho3D.h>

#include <Urho3D/Container/Vector.h>
#include <Urho3D/Scene/LogicComponent.h>
#include <Urho3D/Scene/Component.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/UI/UI.h>

using namespace Urho3D;

namespace Urho3D {
    class Window;
}

class DragableFish : public Component
{
    URHO3D_OBJECT(DragableFish, Component)
public:
    explicit DragableFish(Context* context);

    /// Create a draggable fish button.
    void OnNodeSet(Node* node) override;

private:
    /// Handle drag begin for the fish button.
    void HandleDragBegin(StringHash eventType, VariantMap& eventData);
    /// Handle drag move for the fish button.
    void HandleDragMove(StringHash eventType, VariantMap& eventData);
    /// Handle drag end for the fish button.
    void HandleDragEnd(StringHash eventType, VariantMap& eventData);

    /// The Window.
    SharedPtr<Window> window_;
    /// The UI's root UIElement.
    SharedPtr<UIElement> uiRoot_;
    /// Remembered drag begin position.
    IntVector2 dragBeginPosition_;
};

#endif // DRAGABLEFISH_H
