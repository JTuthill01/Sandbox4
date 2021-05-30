#include "M18_Red.h"
#include "Kismet/GameplayStatics.h"

AM18_Red::AM18_Red() = default;

void AM18_Red::OnReleased(FVector ForwardVector)
{
	Super::OnReleased(ForwardVector);

	ForwardVector *= ImpulseForce;
}

void AM18_Red::Explode()
{
	Super::Explode();

	FVector TempVector = GrenadeMesh->GetComponentLocation();

	FRotator TempRotator = GrenadeMesh->GetComponentRotation();

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), SmokeEmitter, TempVector, TempRotator);

	UGameplayStatics::SpawnSoundAtLocation(GetWorld(), ExplosiveSound, TempVector);

	Destroy();
}
