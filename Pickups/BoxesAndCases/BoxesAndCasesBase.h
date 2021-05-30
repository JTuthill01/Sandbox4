#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sandbox/Interfaces/OnInteract.h"
#include "BoxesAndCasesBase.generated.h"

class APickupBase;

UCLASS()
class SANDBOX_API ABoxesAndCasesBase : public AActor, public IOnInteract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoxesAndCasesBase();

	virtual void OnInteract_Implementation() override;

	virtual void OnBeginInteract_Implementation(AActor* OtherActor) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AddWidget(AActor* OtherActor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RemoveWidget();

	UFUNCTION(BlueprintCallable)
	void StopLidMovement();

	UFUNCTION(BlueprintCallable)
	void Open();

	UFUNCTION(BlueprintCallable)
	virtual void SpawnCasePickup();

	UFUNCTION()
	void Remove();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	class UStaticMeshComponent* Hull;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	class UStaticMeshComponent* Lid;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	FVector MeshLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Impulse)
	float ImpulseForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	float Radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	float Strength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Booleans)
	bool bHasBeenOpened;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Varaibles)
	float TimeToMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	int32 PickupIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	int32 CurrentIndex;

protected:
	bool bShouldLidMove;

	float RemoveWidgetTimer;
	float SpawnTimer;

	FTimerHandle SpawnTimerHandle;
	FTimerHandle MoveLidTimerHandle;
	FTimerHandle RemoveWidgetHandle;
};
