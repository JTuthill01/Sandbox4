#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Sandbox/Structs/STR_AmmoData.h"
#include "Sandbox/Structs/STR_PropData.h"
#include "SandboxGameInstance.generated.h"

UCLASS()
class SANDBOX_API USandboxGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	USandboxGameInstance();

	virtual void Init();

public:
	UFUNCTION()
	FAmmoData AK47Data();

	UFUNCTION()
	FAmmoData AmericanShotgunData();

	UFUNCTION()
	FAmmoData BelgianARData();

	UFUNCTION()
	FAmmoData BulldogData();

	UFUNCTION()
	FAmmoData HandCannonData();

	UFUNCTION()
	FAmmoData L86Data();

	UFUNCTION()
	FAmmoData ShortStrokeARData();

	UFUNCTION()
	FAmmoData SKSData();

	UFUNCTION()
	FAmmoData SMGData();

	UFUNCTION()
	FAmmoData T38Data();

	UFUNCTION()
	FAmmoData XM82Data();

	UFUNCTION()
	FAmmoData SVDData();

	UFUNCTION()
	FAmmoData NavySMGData();

	UFUNCTION()
	FAmmoData MicroSMGData();

	UFUNCTION()
	FAmmoData M4A1Data();

	UFUNCTION()
	FAmmoData ItalianShotgunData();

	UFUNCTION()
	FAmmoData AK74Data();

	UFUNCTION()
	FPropData RedBarrelData();

	UFUNCTION()
	FPropData OrangeBarrelData();

	UFUNCTION()
	FPropData PlainBarrelData();

	UFUNCTION()
	FPropData PlainJerryCanData();

	UFUNCTION()
	FPropData RedJerryCanData();

	UFUNCTION()
	FPropData GreenJerryCanData();

	UFUNCTION()
	FPropData PropaneGasCylinderYellowData();

	UFUNCTION()
	FPropData PropaneGasCylinderRedData();

	UFUNCTION()
	FPropData PropaneGasCylinderPlainData();

	UFUNCTION()
	FPropData PropaneCylinderTallYellowData();

	UFUNCTION()
	FPropData PropaneCylinderTallRedData();

	UFUNCTION()
	FPropData PropaneCylinderTallPlainData();

	UFUNCTION()
	FPropData PortaPottyData();

private:
	UPROPERTY()
	FAmmoData AK47AmmoData;

	UPROPERTY()
	FAmmoData AmericanShotgunAmmoData;

	UPROPERTY()
	FAmmoData BelgianARAmmoData;

	UPROPERTY()
	FAmmoData BulldogAmmoData;

	UPROPERTY()
	FAmmoData HandCannonAmmoData;

	UPROPERTY()
	FAmmoData L86AmmoData;

	UPROPERTY()
	FAmmoData ShortStrokeARAmmoData;

	UPROPERTY()
	FAmmoData SKSAmmoData;

	UPROPERTY()
	FAmmoData SMGAmmoData;

	UPROPERTY()
	FAmmoData T38AmmoData;

	UPROPERTY()
	FAmmoData XM82AmmoData;

	UPROPERTY()
	FAmmoData SVDAmmoData;

	UPROPERTY()
	FAmmoData NavySMGAmmoData;

	UPROPERTY()
	FAmmoData MicroSMGAmmoData;

	UPROPERTY()
	FAmmoData M4A1AmmoData;

	UPROPERTY()
	FAmmoData ItalianShotgunAmmoData;

	UPROPERTY()
	FAmmoData AK74AmmoData;

	UPROPERTY()
	FPropData RedBarrelPropData;

	UPROPERTY()
	FPropData OrangeBarrelPropData;

	UPROPERTY()
	FPropData PlainBarrelPropData;

	UPROPERTY()
	FPropData PlainJerryCanPropData;

	UPROPERTY()
	FPropData RedJerryCanPropData;

	UPROPERTY()
	FPropData GreenJerryCanPropData;

	UPROPERTY()
	FPropData PropaneGasCylinderYellowPropData;

	UPROPERTY()
	FPropData PropaneGasCylinderRedPropData;

	UPROPERTY()
	FPropData PropaneGasCylinderPlainPropData;

	UPROPERTY()
	FPropData PropaneCylinderTallPlainPropData;

	UPROPERTY()
	FPropData PropaneCylinderTallRedPropData;

	UPROPERTY()
	FPropData PropaneCylinderTallYellowPropData;

	UPROPERTY()
	FPropData ProtaPottyPropData;
};
