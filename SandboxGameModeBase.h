#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Sandbox/Enums/Enums.h"
#include "SandboxGameModeBase.generated.h"

UCLASS()
class SANDBOX_API ASandboxGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ASandboxGameModeBase();

	class AExplosivePropsBase* GetCurrentProp() { return Prop; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ExplosiveProp)
	TArray< TSubclassOf<class AExplosivePropsBase>> BarrelToSpawn;

protected:
	virtual void BeginPlay() override;

protected:
	UFUNCTION(BlueprintCallable)
	void SpawnBarrel();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Waypoint)
	TArray<AActor*> Waypoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AExplosivePropsBase* Prop;

private:
	int32 IndexSize;
	EPropType Type;
};
