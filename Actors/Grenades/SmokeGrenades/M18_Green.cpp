#include "M18_Green.h"
#include "Kismet/GameplayStatics.h"

AM18_Green::AM18_Green() = default;

void AM18_Green::OnReleased(FVector ForwardVector)
{
	Super::OnReleased(ForwardVector);

	ForwardVector *= ImpulseForce;
}

void AM18_Green::Explode()
{
	Super::Explode();

	FVector TempVector = GrenadeMesh->GetComponentLocation();

	FRotator TempRotator = GrenadeMesh->GetComponentRotation();

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), SmokeEmitter, TempVector, TempRotator);

	UGameplayStatics::SpawnSoundAtLocation(GetWorld(), ExplosiveSound, TempVector);

	Destroy();
}
