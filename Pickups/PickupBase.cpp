#include "PickupBase.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Sandbox/Interfaces/PlayerRef.h"
#include "Sandbox/Character/PlayerCharacter.h"
#include "Sandbox/Actors/Weapons/WeaponBase.h"

// Sets default values
APickupBase::APickupBase()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));

	PickupMesh->SetSimulatePhysics(true);
	PickupMesh->SetGenerateOverlapEvents(true);

	SetRootComponent(PickupMesh);
}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();

	PlayerRef = IPlayerRef::Execute_GetPlayerRef(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

void APickupBase::OnInteract_Implementation()
{
	InteractionCalled();

	switch (PickupType)
	{
	case EPickupType::None:
		break;

	case EPickupType::Weapon:

		PlayerRef->SpawnWeapon(Weapon, bIsSuccessful);

		InteractionCalled();

		if (bIsSuccessful == true)
		{
			Destroy();
		}

		RemoveWidget(PlayerRef);

		PlayerRef->CanSwitchWeapon(bCanSwitch);

		if (bCanSwitch == true)
		{
			PlayerRef->SwapWeapon(Weapon, bIsSuccessful);

			PlayerRef->SpawnPickup();

			InteractionCalled();

			if (bIsSuccessful == true)
			{
				Destroy();
			}

			RemoveWidget(PlayerRef);
		}

		break;

	case EPickupType::Health:

		SetHealth(bIsHealthSuccessful);

		HealthHUDUpdate();

		if (bIsHealthSuccessful)
		{
			Destroy();
		}
		

		break;

	case EPickupType::Ammo:
		
		AmmoPickup(bIsAmmoSuccessful);

		InteractionCalled();

		if (bIsAmmoSuccessful)
		{
			Destroy();
		}
		
		break;

	default:
		break;
	}
}

void APickupBase::SetHealth(bool& IsSuccessful)
{
	if (IsValid(PlayerRef))
	{
		if (PlayerRef->IsHealthFull() == false)
		{
			bIsHealthFull = true;

			switch (PickupHealthType)
			{
			case EPickupHealthType::None:
				break;

			case EPickupHealthType::HealthSmall:

				PlayerRef->SetHealth(HealthPackValue);

				IsSuccessful = true;

				break;

			case EPickupHealthType::HealthMedium:

				PlayerRef->SetHealth(HealthPackValue); 

				IsSuccessful = true;

				break;

			case EPickupHealthType::HealthLarge:

				PlayerRef->SetHealth(HealthPackValue);

				IsSuccessful = true;

				break;

			default:
				break;
			}
		}

		else
		{
			bIsHealthFull = true;
		}
	}

	else
	{
		IsSuccessful = false;

		return;
	}
}

void APickupBase::AmmoPickup(bool& IsSuccessful)
{
	if (IsValid(PlayerRef))
	{
		if (PlayerRef->GetCurrentWeapon()->IsAmmoFull() == false)
		{
			switch (PickupAmmoType)
			{
			case EPickupAmmoType::None:
				break;

			case EPickupAmmoType::PistolAmmo:

				if (PlayerRef->GetCurrentWeapon()->WeaponClass == EWeaponClass::Pistol)
				{
					PlayerRef->GetCurrentWeapon()->SetCurrentTotalAmmo(PistolAmmoValue);

					IsSuccessful = true;
				}

				else if (PlayerRef->GetWeaponSlot_01()->WeaponClass == EWeaponClass::Pistol)
				{
					PlayerRef->GetWeaponSlot_01()->SetCurrentTotalAmmo(PistolAmmoValue);

					IsSuccessful = true;
				}

				else if (PlayerRef->GetWeaponSlot_02()->WeaponClass == EWeaponClass::Pistol)
				{
					PlayerRef->GetWeaponSlot_02()->SetCurrentTotalAmmo(PistolAmmoValue);

					IsSuccessful = true;
				}

				break;

			case EPickupAmmoType::RifleAmmo:

				if (PlayerRef->GetCurrentWeapon()->WeaponClass == EWeaponClass::Rifle)
				{
					PlayerRef->GetCurrentWeapon()->SetCurrentTotalAmmo(RifleAmmoValue);

					IsSuccessful = true;
				}

				else if (PlayerRef->GetWeaponSlot_01()->WeaponClass == EWeaponClass::Rifle)
				{
					PlayerRef->GetWeaponSlot_01()->SetCurrentTotalAmmo(RifleAmmoValue);

					IsSuccessful = true;
				}

				else if (PlayerRef->GetWeaponSlot_02()->WeaponClass == EWeaponClass::Rifle)
				{
						PlayerRef->GetWeaponSlot_02()->SetCurrentTotalAmmo(RifleAmmoValue);

						IsSuccessful = true;
				}
				

				break;

			case EPickupAmmoType::ShotgunAmmo:

				if (PlayerRef->GetCurrentWeapon()->WeaponClass == EWeaponClass::Shotgun)
				{
					PlayerRef->GetCurrentWeapon()->SetCurrentTotalAmmo(ShotgunAmmoValue);

					IsSuccessful = true;
				}

				else if (PlayerRef->GetWeaponSlot_01()->WeaponClass == EWeaponClass::Shotgun)
				{
					PlayerRef->GetWeaponSlot_01()->SetCurrentTotalAmmo(ShotgunAmmoValue);

					IsSuccessful = true;
				}

				else if (PlayerRef->GetWeaponSlot_02()->WeaponClass == EWeaponClass::Shotgun)
				{
					PlayerRef->GetWeaponSlot_02()->SetCurrentTotalAmmo(ShotgunAmmoValue);

					IsSuccessful = true;
				}

				break;

			default:
				break;
			}
		}
	}

	else
	{
		IsSuccessful = false;

		return;
	}
}

void APickupBase::OnBeginInteract_Implementation(AActor* OtherActor) 
{
	RemoveWidgetTimer = 0.45F;

	AddWidget(OtherActor); 

	FTimerDelegate TimerDel;
	TimerDel.BindUFunction(this, FName("Remove"), OtherActor);

	GetWorldTimerManager().SetTimer(RemoveWidgetHandle, TimerDel, RemoveWidgetTimer, false);
}

void APickupBase::Remove(AActor* OtherActor)
{
	RemoveWidget(OtherActor);

	GetWorldTimerManager().ClearTimer(RemoveWidgetHandle);
}

void APickupBase::InteractionCalled_Implementation() {}

void APickupBase::HealthHUDUpdate_Implementation() {}

void APickupBase::AddWidget_Implementation(AActor* OtherActor){}

void APickupBase::RemoveWidget_Implementation(AActor* OtherActor){}

