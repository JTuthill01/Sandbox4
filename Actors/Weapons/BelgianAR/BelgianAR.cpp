#include "BelgianAR.h"
#include "../Plugins/FX/Niagara/Source/Niagara/Public/NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Sandbox/Instances/SandboxGameInstance.h"
#include "Sandbox/Actors/Attachments/SightAttachment.h"

ABelgianAR::ABelgianAR() = default;

void ABelgianAR::WeaponFire(EFireType FireType)
{
	Super::WeaponFire(fireType);

	EjectTransform = WeaponMesh->GetSocketTransform("AmmoEject");

	EjectTransform.GetRotation() = EjectQuat;

	FireTransform = WeaponMesh->GetSocketTransform("Fire_FX_Slot");

	FireTransform.GetRotation() = FireQuat;

	WeaponFireAnim = WeaponMesh->GetAnimInstance();

	if (WeaponFireAnim)
	{
		WeaponFireAnim->Montage_Play(WeaponFireMontage);

		UGameplayStatics::SpawnSoundAttached(FireSound, WeaponMesh);

		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), AmmoEject, EjectTransform.GetTranslation(), EjectQuat.Rotator());

		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), FireFX, FireTransform.GetTranslation(), FireQuat.Rotator());
	}
}

void ABelgianAR::WeaponReload()
{
	Super::WeaponReload();

	WeaponReloadAnim = WeaponMesh->GetAnimInstance();

	if (WeaponReloadAnim)
	{
		WeaponReloadAnim->Montage_Play(WeaponReloadMontage);
	}
}

void ABelgianAR::BeginPlay()
{
	Super::BeginPlay();

	USandboxGameInstance* Instance = Cast<USandboxGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	AmmoData = Instance->BelgianARData();

	//SpawnScope();
}

void ABelgianAR::SpawnScope()
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector TempVector = WeaponMesh->GetSocketLocation(ScopeSocketName);

	FRotator TempRotator = WeaponMesh->GetSocketRotation(ScopeSocketName);

	Sight = GetWorld()->SpawnActor<ASightAttachment>(Attachment, TempVector, TempRotator, SpawnInfo);

	if (IsValid(Sight))
	{
		Sight->AttachToComponent(WeaponMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, ScopeSocketName);

		Sight->ShowRisAdapter(0);
	}
}

void ABelgianAR::BelgianScopeSetup_Implementation(){}

void ABelgianAR::BelgianRemoveScopeWidget_Implementation(){}

