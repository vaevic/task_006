#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomPlatform.h"
#include "TimerPlatform.h"
#include "PlatformSpawner.generated.h"

UCLASS()
class TASK_006_API APlatformSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	APlatformSpawner();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Random")
	TSubclassOf<ARandomPlatform> PlatformClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random")
	TArray<TSubclassOf<ARandomPlatform>> PlatformsToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random")
	int32 NumOfSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random")
	float SpawnRange;

	FVector RandomValue;

};
