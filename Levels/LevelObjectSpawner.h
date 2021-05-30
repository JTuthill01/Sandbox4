#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LevelObjectSpawner.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPropSpawn, AExplosivePropsBase*, SpawnedProp);

UCLASS()
class SANDBOX_API ALevelObjectSpawner : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:
	ALevelObjectSpawner();

	UPROPERTY(BlueprintAssignable)
	FOnPropSpawn OnSpawn;

protected:
	virtual void BeginPlay() override;

protected:
	UFUNCTION(BlueprintCallable)
	void SpawnBarrel(TArray<class ATargetPoint*> Point);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AExplosivePropsBase* Prop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ExplosiveProp)
	TArray<TSubclassOf<class AExplosivePropsBase>> PropToSpawn;
};
