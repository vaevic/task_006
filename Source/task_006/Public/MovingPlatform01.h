#pragma once

#include "CoreMinimal.h"
#include "RandomPlatform.h"
#include "MovingPlatform01.generated.h"

UCLASS(Blueprintable,BlueprintType)
class TASK_006_API AMovingPlatform01 : public ARandomPlatform
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform01();

protected:
	virtual void BeginPlay() override;	

public:

	virtual void Tick(float DeltaTime) override;
	
	FVector StartLocation; // 처음 좌표값을 저장하는 변수
	FVector CurrentLocation; // 현재 좌표값
	float RunTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Properties")
	float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Properties")
	float MoveSpeed;

};
