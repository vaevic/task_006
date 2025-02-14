#pragma once

#include "CoreMinimal.h"
#include "RandomPlatform.h"
#include "RotationPlatform001.generated.h"

UCLASS(Blueprintable, BlueprintType)
class TASK_006_API ARotationPlatform001 : public ARandomPlatform
{
	GENERATED_BODY()
	
public:	
	ARotationPlatform001();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Properties")
	float RotationSpeed;//회전 속도

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
