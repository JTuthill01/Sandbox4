#include "ShotgunAmmoUpdateNotify.h"
#include "Sandbox/Character/PlayerCharacter.h"

void UShotgunAmmoUpdateNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp != NULL && MeshComp->GetOwner() != NULL)
	{
		APlayerCharacter* Player = Cast<APlayerCharacter>(MeshComp->GetOwner());

		if (Player != NULL)
		{
			Player->UpdateShotgunAmmo();
		}
	}
}
