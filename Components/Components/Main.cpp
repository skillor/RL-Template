#include "Main.hpp"
#include "../Includes.hpp"
#include "../Modules/Includes.hpp"


MainComponent::MainComponent() : Component("Main", "Interface to game interacton") { OnCreate(); }

MainComponent::~MainComponent() { OnDestroy(); }

void MainComponent::OnCreate() {}

void MainComponent::OnDestroy() {}

void MainComponent::Initialize() {

}

void MainComponent::SpawnNotification(const std::string& Title, const std::string& Content, int Duration, UClass* NotificationClass)
{
	if (UNotificationManager_TA* NotificationManager = Instances.GetInstanceOf<UNotificationManager_TA>()) {
		if (!NotificationClass)
		{
			NotificationClass = UGenericNotification_TA::StaticClass();
		}

		UNotification_TA* Notification = NotificationManager->PopUpOnlyNotification(NotificationClass);

		if (Notification) {
			Notification->SetTitle(Format::ToFString(Title));
			Notification->SetBody(Format::ToFString(Content));
			Notification->PopUpDuration = Duration;
		}
	}
}


std::vector<std::function<void()>> MainComponent::GameFunctions;

class MainComponent Main {};