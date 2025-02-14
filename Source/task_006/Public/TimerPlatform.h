#pragma once

#include "CoreMinimal.h"
#include "RandomPlatform.h"
#include "TimerPlatform.generated.h"

UCLASS()
class TASK_006_API ATimerPlatform : public ARandomPlatform
{
	GENERATED_BODY()
	
public:	
	ATimerPlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void YawRound();

	FTimerHandle YawTimerHandle;
	FRotator StartRotate;
	FRotator CurrentRotate;

	float Frame;
};
