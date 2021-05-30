#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sandbox/Interfaces/OnInteract.h"
#include "PickupBase.generated.h"

UENUM(BlueprintType)
enum class EPickupType : uint8 { None, Weapon, Health, Ammo };

UENUM(BlueprintType)
enum class EPickupHealthType : uint8 { None, HealthSmall, HealthMedium, HealthLarge };

UENUM(BlueprintType)
enum class EPickupAmmoType : uint8 { None, PistolAmmo, RifleAmmo, ShotgunAmmo };

UCLASS()
class SANDBOX_API APickupBase : public AActor, public IOnInteract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupBase();

	virtual void OnInteract_Implementation() override;

	virtual void OnBeginInteract_Implementation(AActor* OtherActor) override;

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AddWidget(AActor* OtherActor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RemoveWidget(AActor* OtherActor);

public:
	FORCEINLINE UStaticMeshComponent* GetMesh() { return PickupMesh; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void InteractionCalled();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HealthHUDUpdate();

	UFUNCTION(BlueprintCallable)
	virtual void SetHealth(bool& IsSuccessful);

	UFUNCTION(BlueprintCallable)
	virtual void AmmoPickup(bool& IsSuccessful);

	UFUNCTION()
	void Remove(AActor* OtherActor);

protected:
	UPROPERTY()
	class APlayerCharacter* PlayerRef;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsSuccessful;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMeshComponent* PickupMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName PickupName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UMaterialInstance* Icon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Weapon)
	TSubclassOf<class AWeaponBase> Weapon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Enums)
	EPickupType PickupType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Enums)
	EPickupHealthType PickupHealthType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Enums)
	EPickupAmmoType PickupAmmoType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Health)
	int HealthPackValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Health)
	bool bIsHealthFull;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Ammo)
	int PistolAmmoValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Ammo)
	int RifleAmmoValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Ammo)
	int ShotgunAmmoValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Switch)
	bool bCanSwitch;

private:
	bool bIsHealthSuccessful;
	bool bIsAmmoSuccessful;

	float RemoveWidgetTimer;

	FTimerHandle RemoveWidgetHandle;
};
