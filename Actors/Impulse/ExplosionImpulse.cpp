#include "ExplosionImpulse.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
AExplosionImpulse::AExplosionImpulse()
{
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));

	RadialForce = CreateDefaultSubobject<URadialForceComponent>(TEXT("Radial Force"));
	RadialForce->SetupAttachment(Scene);

	SetRootComponent(Scene);
}

// Called when the game starts or when spawned
void AExplosionImpulse::BeginPlay()
{
	Super::BeginPlay();
	
	RadialForce->FireImpulse();
}
