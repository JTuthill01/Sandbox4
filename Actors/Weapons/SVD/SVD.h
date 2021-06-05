#pragma once

#include "CoreMinimal.h"
#include "Sandbox/Actors/Weapons/WeaponBase.h"
#include "SVD.generated.h"

UCLASS()
class SANDBOX_API ASVD : public AWeaponBase
{
	GENERATED_BODY()
	
public:
	ASVD();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ScopeSetup();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RemoveScopeWidget();

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
