#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sandbox/Interfaces/OnInteract.h"
#include "AnimatedCases.generated.h"

class APickupBase;

UCLASS()
class SANDBOX_API AAnimatedCases : public AActor, public IOnInteract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAnimatedCases();

	virtual void OnInteract_Implementation() override;

	virtual void OnBeginInteract_Implementation(AActor* OtherActor) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AddWidget(AActor* OtherActor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RemoveWidget();

	UFUNCTION(BlueprintCallable)
	void SpawnCasePickups();

	UFUNCTION()
	void Open();

	UFUNCTION()
	void Remove();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	class USkeletalMeshComponent* CaseMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Animation)
	class UAnimationAsset* CaseOpenAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	int32 NumOfPickupsToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	APickupBase* BasePickup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	TArray<TSubclassOf<APickupBase>> SpawnArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	FVector SpawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	TArray<FName> SocketNameArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pickup)
	FRotator SpawnRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	int32 PickupIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	int32 CurrentIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	bool bHasBeenOpened;

private:
	float RemoveWidgetTimer;

	FTimerHandle RemoveWidgetHandle;
};
