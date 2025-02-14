#include "PlatformSpawner.h"
#include "RandomPlatform.h"

APlatformSpawner::APlatformSpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	NumOfSpawn = 10;
	SpawnRange = 50.0f;

}


void APlatformSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (int i = 0; i < NumOfSpawn; i++)
	{
		RandomValue.X = FMath::RandRange(-SpawnRange, SpawnRange);
		RandomValue.Y = FMath::RandRange(-SpawnRange, SpawnRange);
		RandomValue.Z = 0.0f;

		FVector SpawnLocation(RandomValue);
		FRotator SpawnRotation = FRotator::ZeroRotator;

		const int32 ClassIndex = FMath::RandRange(0, PlatformsToSpawn.Num() - 1);
		TSubclassOf<AActor> ChosenClass = PlatformsToSpawn[ClassIndex];


		GetWorld()->SpawnActor<ARandomPlatform>(PlatformClass, SpawnLocation, SpawnRotation);
	}
}

void APlatformSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

