// Copyright (c) 2019 Nineva Studios

#include "MqttUtilitiesLB.h"

#if PLATFORM_WINDOWS
#include "Windows/MqttClient.h"
#endif

#if PLATFORM_MAC
#include "Mac/MqttClient.h"
#endif

#if PLATFORM_IOS
#include "IOS/MqttClient.h"
#endif

#if PLATFORM_ANDROID
#include "Android/MqttClient.h"
#endif

#if PLATFORM_LINUX
#include "Linux/MqttClient.h"
#endif

TScriptInterface<IMqttClientInterface> UMqttUtilitiesLB::CreateMqttClient(FMqttClientConfig config)
{
	UE_LOG(LogTemp, Warning, TEXT("MQTT => Creating MQTT client..."));

#if PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_LINUX

	UMqttClient* MqttClient = NewObject<UMqttClient>();
	// fuck you unreal GC
	MqttClient->AddToRoot();
	MqttClient->Init(config);
	TScriptInterface<IMqttClientInterface> MqttClientInterface;
	MqttClientInterface.SetObject(MqttClient);
	MqttClientInterface.SetInterface(Cast<IMqttClientInterface>(MqttClient));
	return MqttClientInterface;
	
#endif

	return nullptr;
}
