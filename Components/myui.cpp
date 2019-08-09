
#include "myui.h"
#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/UI/Button.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/UI/UIEvents.h>


MyUI::MyUI(Context* context) : Component(context)
{
}

void MyUI::OnNodeSet(Node *node)
{
    scene_ = GetScene();

    auto* cache = GetSubsystem<ResourceCache>();
    auto* ui = GetSubsystem<UI>();

    // Set up global UI style into the root UI element
    auto* style = cache->GetResource<XMLFile>("UI/DefaultStyle.xml");
    ui->GetRoot()->SetDefaultStyle(style);

    // Create a Cursor UI element because we want to be able to hide and show it at will. When hidden, the mouse cursor will
    // control the camera, and when visible, it will interact with the UI
    SharedPtr<Cursor> cursor(new Cursor(context_));
    cursor->SetStyleAuto();
    ui->SetCursor(cursor);
    // Set starting position of the cursor at the rendering window center
    auto* graphics = GetSubsystem<Graphics>();
    cursor->SetPosition(graphics->GetWidth() / 2, graphics->GetHeight() / 2);

    // Load UI content prepared in the editor and add to the UI hierarchy
    SharedPtr<UIElement> layoutRoot = ui->LoadLayout(cache->GetResource<XMLFile>("UI/MyUI.xml"));
    ui->GetRoot()->AddChild(layoutRoot);

    // Subscribe to button actions (toggle scene lights when pressed then released)
    auto* button = layoutRoot->GetChildStaticCast<Button>("ToggleLight1", true);
    if (button)
        SubscribeToEvent(button, E_RELEASED, URHO3D_HANDLER(MyUI, ToggleLight1));
    button = layoutRoot->GetChildStaticCast<Button>("ToggleLight2", true);
    if (button)
        SubscribeToEvent(button, E_RELEASED, URHO3D_HANDLER(MyUI, ToggleLight2));

}

void MyUI::ToggleLight1(StringHash eventType, VariantMap &eventData)
{
    Node* lightNode = scene_->GetChild("Light", true);
    if (lightNode)
        lightNode->SetEnabled(!lightNode->IsEnabled());
}

void MyUI::ToggleLight2(StringHash eventType, VariantMap &eventData)
{
    Node* lightNode = scene_->GetChild("Light", true);
    if (lightNode)
        lightNode->SetEnabled(!lightNode->IsEnabled());
}



