#pragma once

#include "CoreMinimal.h"
#include "Sandbox/Actors/Weapons/WeaponBase.h"
#include "BelgianAR.generated.h"

UCLASS()
class SANDBOX_API ABelgianAR : public AWeaponBase
{
	GENERATED_BODY()
	
public:
	ABelgianAR();

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BelgianScopeSetup();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BelgianRemoveScopeWidget();

protected:
	void WeaponFire(EFireType FireType) override;

	void WeaponReload() override;

	void BeginPlay() override;

protected:
	UFUNCTION(BlueprintCallable)
	void SpawnScope();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sight)
	FName ScopeSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Sight)
	class ASightAttachment* Sight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Sight)
	TSubclassOf<class ASightAttachment> Attachment;
};
