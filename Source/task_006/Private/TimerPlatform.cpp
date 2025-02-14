#include "TimerPlatform.h"
#include "TimerManager.h"

ATimerPlatform::ATimerPlatform()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_C"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	Frame = 1.0f / 24.0f; // 애니메이션24프레임
}

void ATimerPlatform::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(385.0f, -151.0f, 311.0f));
	StartRotate = GetActorRotation();

	GetWorld()->GetTimerManager().SetTimer(
		YawTimerHandle,
		this,
		&ATimerPlatform::YawRound,
		Frame,
		true);
}

void ATimerPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATimerPlatform::YawRound()
{
	CurrentRotate.Yaw += 10.0f;
	SetActorRotation(CurrentRotate);
}
