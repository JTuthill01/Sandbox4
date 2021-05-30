#include "LevelObjectSpawner.h"
#include "Sandbox/Actors/ExplosiveProps/ExplosivePropsBase.h"
#include "Engine/TargetPoint.h"

ALevelObjectSpawner::ALevelObjectSpawner() = default;

void ALevelObjectSpawner::BeginPlay()
{
	Super::BeginPlay();
}

void ALevelObjectSpawner::SpawnBarrel(TArray<class ATargetPoint*> Point)
{
	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector TempVector = FVector(0.F);

	FRotator TempRotation = FRotator(0.F);

	uint8 Num = PropToSpawn.Num();

	for (size_t i = 0; i < Num; ++i)
	{
		TempVector = Point[i]->GetActorLocation();

		TempRotation = Point[i]->GetActorRotation();

		Prop = GetWorld()->SpawnActor<AExplosivePropsBase>(PropToSpawn[i], TempVector, TempRotation, Params);

		//OnSpawn.Broadcast(Prop);
	}
}

	