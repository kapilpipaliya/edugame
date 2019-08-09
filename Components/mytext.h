
#ifndef MYTEXT_H
#define MYTEXT_H

#include <Urho3D/Urho3D.h>

#include <Urho3D/Scene/LogicComponent.h>
#include <Urho3D/Scene/Component.h>
#include <Urho3D/Scene/Node.h>

using namespace Urho3D;

class MyText : public Component
{
    URHO3D_OBJECT(MyText, Component)
public:
    explicit MyText(Context* context);

    /// Construct a new Text instance, containing the 'Hello World' String, and add it to the UI root element.
    void OnNodeSet(Node* node) override;
};

#endif // MYTEXT_H
