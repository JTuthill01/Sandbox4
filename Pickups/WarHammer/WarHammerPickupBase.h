#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sandbox/Interfaces/OnInteract.h"
#include "WarHammerPickupBase.generated.h"

UCLASS()
class SANDBOX_API AWarHammerPickupBase : public AActor, public IOnInteract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWarHammerPickupBase();

	virtual void OnInteract_Implementation() override;

protected:
	UFUNCTION(BlueprintCallable)
	void OnBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	void OnEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AddWidget(AActor* OtherActor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RemoveWidget(AActor* OtherActor);

	UFUNCTION(BlueprintCallable)
	void SpawnHammer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	class USphereComponent* Sphere;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	class UStaticMeshComponent* HammerMesh;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class APlayerCharacter* PlayerRef;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName WeaponName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AWarHammer> Hammer;
};
