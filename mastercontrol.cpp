

#include "mastercontrol.h"

#include "Components/dragablefish.h"
#include "Components/mylogo.h"
#include "Components/mytext.h"
#include "Components/myui.h"
#include "Components/mycamera.h"

URHO3D_DEFINE_APPLICATION_MAIN(MasterControl);

MasterControl* MasterControl::instance_ = nullptr;

MasterControl* MasterControl::GetInstance()
{
    return MasterControl::instance_;
}

MasterControl::MasterControl(Context *context):Application(context)
{
    instance_ = this;
}
// Called after engine initialization. Setup application
void MasterControl::Setup()
{
    context_->RegisterFactory<MyText>();
    context_->RegisterFactory<MyLogo>();
    context_->RegisterFactory<DragableFish>();
    context_->RegisterFactory<MyUI>();
    context_->RegisterFactory<MyCamera>();

    SetRandomSeed(TIME->GetSystemTime());

    engineParameters_[EP_LOG_NAME] = GetSubsystem<FileSystem>()->GetAppPreferencesDir("luckey", "logs") + "jimmy4.log";
    engineParameters_[EP_WINDOW_TITLE] = "jimmy4";
    engineParameters_[EP_WINDOW_ICON] = "icon.png";
    engineParameters_[EP_WORKER_THREADS] = false;
    engineParameters_[EP_RESOURCE_PATHS] = "Data;CoreData;Resources;";

    // Subscribe key down event
    SubscribeToEvent(E_KEYDOWN, URHO3D_HANDLER(MasterControl, HandleKeyDown));
}
void MasterControl::Start()
{
    // Any Object can be registered to the Context as a subsystem, by using the function RegisterSubsystem(). They can then be accessed by any other Object inside the same context by calling GetSubsystem(). Only one instance of each object type can exist as a subsystem.
    // RegisterSubsystem<EffectMaster>();

    if (GRAPHICS){
        ENGINE->SetMaxFps(GRAPHICS->GetRefreshRate());
    }
    //  To avoid spinning the CPU and GPU unnecessarily, it is possible to define a smaller maximum FPS when no input focus. See SetMaxInactiveFps()

    CreateScene();
}
void MasterControl::Stop()
{
    engine_->DumpResources(true);
}
void MasterControl::Exit()
{
    engine_->Exit();
}

void MasterControl::HandleKeyDown(StringHash eventType, VariantMap &eventData)
{
    using namespace KeyDown;
    // Check for pressing ESC. Note the engine_ member variable for convenience access to the Engine object
    int key = eventData[P_KEY].GetInt();
    if (key == KEY_ESCAPE)
        engine_->Exit();
}

void MasterControl::CreateScene()
{
    scene_ = new Scene(context_);
    scene_->CreateComponent<Octree>();
    scene_->CreateComponent<PhysicsWorld>();
    scene_->CreateComponent<DebugRenderer>();

    // Set the mouse mode to use in the sample
    GetSubsystem<Input>()->SetMouseVisible(true);

    //Light
    Node* lightNode{ scene_->CreateChild("Light") };
    lightNode->SetPosition(Vector3(2.0f, 3.0f, 1.0f));
    lightNode->CreateComponent<Light>();
    //Camera
    Node* cameraNode{ scene_->CreateChild("Camera") };
    cameraNode->SetPosition(Vector3::ONE * 5.0f);
    cameraNode->LookAt(Vector3::ZERO);
    Camera* camera{ cameraNode->CreateComponent<Camera>() };
    RENDERER->SetViewport(0, new Viewport(context_, scene_, camera));
    //Box!
//    scene_->CreateChild()->CreateComponent<StaticModel>()->SetModel(CACHE->GetResource<Model>("Models/Box.mdl"));
    scene_->CreateChild()->CreateComponent<StaticModel>()->SetModel(CACHE->GetResource<Model>("Models/Cone.mdl"));

    scene_->CreateComponent<MyLogo>();
    scene_->CreateComponent<MyText>();
    scene_->CreateComponent<DragableFish>();
    scene_->CreateComponent<MyUI>(); // Two buttons that toogle light
    scene_->CreateComponent<MyCamera>(); // Just Move camera with mouse
}
