#include "MovingPlatform01.h"

AMovingPlatform01::AMovingPlatform01()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot->SetWorldLocation(FVector(276.0f, -200.0f, 176.0f));

	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/Floor_400x400.Floor_400x400"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Wood_Pine.M_Wood_Pine"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial	(0, MaterialAsset.Object);
	}

	MoveSpeed = 10.0f;
	MaxRange = 100.0f;

}

void AMovingPlatform01::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation(); // 스타트 위치 get으로 가져옴
	CurrentLocation = GetActorLocation();
}

void AMovingPlatform01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunTime += DeltaTime;

	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		
		CurrentLocation.Y = StartLocation.Y + MaxRange * FMath::Sin(MoveSpeed*RunTime*0.1f);
		SetActorLocation(CurrentLocation);
	}
}



