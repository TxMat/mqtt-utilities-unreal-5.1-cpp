// Copyright (c) 2019 Nineva Studios

#pragma once

#include "Interface/MqttClientInterface.h"
#include "Entities/MqttClientConfig.h"

#include "Kismet/BlueprintFunctionLibrary.h"

#include "MqttUtilitiesLB.generated.h"

UCLASS()
class MQTTUTILITIES_API UMqttUtilitiesLB : public UObject
{
	GENERATED_BODY()

	/**
	 * Create new instance of MQTT client
	 *
	 * @return - reference to MQTT client interface object
	 */
public:
	UFUNCTION(BlueprintCallable, Category = "MQTT")
	static TScriptInterface<IMqttClientInterface> CreateMqttClient(FMqttClientConfig config);
};