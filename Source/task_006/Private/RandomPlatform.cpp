#include "RandomPlatform.h"

ARandomPlatform::ARandomPlatform()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

}

void ARandomPlatform::BeginPlay()
{
	Super::BeginPlay();	

}

void ARandomPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

