#include "M18_Yellow.h"
#include "Kismet/GameplayStatics.h"

AM18_Yellow::AM18_Yellow() = default;

void AM18_Yellow::OnReleased(FVector ForwardVector)
{
	Super::OnReleased(ForwardVector);

	ForwardVector *= ImpulseForce;
}

void AM18_Yellow::Explode()
{
	Super::Explode();

	FVector TempVector = GrenadeMesh->GetComponentLocation();

	FRotator TempRotator = GrenadeMesh->GetComponentRotation();

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), SmokeEmitter, TempVector, TempRotator);

	UGameplayStatics::SpawnSoundAtLocation(GetWorld(), ExplosiveSound, TempVector);

	Destroy();
}
