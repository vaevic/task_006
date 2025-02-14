#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomPlatform.generated.h"

UCLASS()
class TASK_006_API ARandomPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ARandomPlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Platform|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "Platform|Components")
	UStaticMeshComponent* StaticMeshComp;
};
