#include "SVD.h"
#include "../Plugins/FX/Niagara/Source/Niagara/Public/NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Sandbox/Instances/SandboxGameInstance.h"
#include "Sandbox/Actors/Attachments/SightAttachment.h"

ASVD::ASVD() = default;

void ASVD::WeaponFire(EFireType FireType)
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

void ASVD::WeaponReload()
{
	Super::WeaponReload();

	WeaponReloadAnim = WeaponMesh->GetAnimInstance();

	if (WeaponReloadAnim)
	{
		WeaponReloadAnim->Montage_Play(WeaponReloadMontage);
	}
}

void ASVD::BeginPlay()
{
	Super::BeginPlay();

	USandboxGameInstance* Instance = Cast<USandboxGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	AmmoData = Instance->SVDData();

	SpawnScope();
}

void ASVD::SpawnScope()
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

		Sight->ShowRisAdapter(2);
	}
}

void ASVD::ScopeSetup_Implementation(){}

void ASVD::RemoveScopeWidget_Implementation(){}
