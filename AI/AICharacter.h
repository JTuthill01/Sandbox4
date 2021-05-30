#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Sandbox/Interfaces/Take_Damage.h"
#include "Sandbox/Interfaces/PlayerRef.h"
#include "Sandbox/Interfaces/References.h"
#include "AICharacter.generated.h"

enum EAmmoPickup : uint8 { PistolAmmoPickup, RifleAmmoPickup, ShotgunAmmoPickup };

enum EHealthPickup : uint8 { SmallHealthPickup, MediumHealthPickup, LargeHealthPickup };

UCLASS()
class SANDBOX_API AAICharacter : public ACharacter, public ITake_Damage, public IPlayerRef, public IReferences
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAICharacter();

	virtual void Take_Damage_Implementation(FAmmoData Ammo_Data, float CriticalHitModifer, FHitResult HitResult) override;

	virtual void Take_Melee_Damage_Implementation(int32 DamageToTake, FHitResult HitResult) override;

	virtual void OnDealExplosiveDamage_Implementation(FHitResult HitResult, int32 DamageToApply) override;

	virtual void TakeGernadeDamage_Implementation(int32 DamageToApply) override;

	virtual AAICharacter* GetAICharacterRef_Implementation() override;

	FORCEINLINE bool GetIsDead() { return bIsDead; }

protected:
	UPROPERTY()
	int HealthPickupChance;

	UPROPERTY()
	int AmmoPickupChance;

	UPROPERTY()
	class APlayerCharacter* PlayerRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsDead;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class APickupBase* AmmoPickup;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class APickupBase* HealthPickup;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class APickupBase* WeaponPickup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	TArray<TSubclassOf<class APickupBase>> WeaponArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	TArray<TSubclassOf<class APickupBase>> AmmoArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	TArray<TSubclassOf<class APickupBase>> HealthArray;

protected:
	UFUNCTION(BlueprintCallable)
	void SetDamage(float Damage, float CriticalHitChance, float CriticalDamageModifier, FHitResult HitResult, float& DamageToApply, bool& bWasCritical);

	UFUNCTION(BlueprintCallable)
	void SetMeleeDamage(float Damage, FHitResult HitResult, float& DamageToApply);

	UFUNCTION(BlueprintCallable)
	void UpdateHealth(float Damage, bool& IsDead);

	UFUNCTION(BlueprintCallable)
	void Dead(FVector ImpactPoint, FName BoneName);

	UFUNCTION(BlueprintCallable)
	void OnDeathSpawnHealth();

	UFUNCTION(BlueprintCallable)
	void OnDeathSpawnAmmo();

	UFUNCTION(BlueprintCallable)
	void OnDeathSpawnWeapon();

	virtual void BeginPlay() override;
};
