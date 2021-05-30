#include "SandboxGameModeBase.h"
#include "Sandbox/Actors/ExplosiveProps/ExplosivePropsBase.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"

ASandboxGameModeBase::ASandboxGameModeBase() = default;

void ASandboxGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);

	SpawnBarrel();
}

void ASandboxGameModeBase::SpawnBarrel()
{
	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	uint8 WaypointIndex = Waypoints.Num();
	uint8 BarrelIndex = 0;
	uint8 BarrelSizeIndex = BarrelToSpawn.Num();

	for (size_t i = 0; i < WaypointIndex; ++i)
	{
		BarrelIndex = FMath::RandRange(0, BarrelSizeIndex);

		if (BarrelIndex >= BarrelSizeIndex)
		{
			BarrelIndex = 0;
		}

		Cast<ATargetPoint>(Waypoints[i]);

		FVector TempVector = Waypoints[i]->GetActorLocation();

		FRotator TempRotator = Waypoints[i]->GetActorRotation();

		Prop = GetWorld()->SpawnActor<AExplosivePropsBase>(BarrelToSpawn[BarrelIndex], TempVector, TempRotator, Params);

		Prop->GetPropMesh()->SetSimulatePhysics(true);
	}
}

