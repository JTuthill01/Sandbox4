#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sandbox/Structs/STR_AmmoData.h"
#include "Sandbox/Interfaces/References.h"
#include "ProjectileBase.generated.h"

UCLASS()
class SANDBOX_API AProjectileBase : public AActor, public IReferences
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

	virtual AProjectileBase* GetProjectileRef_Implementation() override;

	UFUNCTION()
	void SetAmmoData(FAmmoData Data) { AmmoData = Data; }

	UFUNCTION()
	void SetModifier(float Modifier) { CriticalHitModifier = Modifier; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY()
	class APlayerCharacter* PlayerRef;

	UPROPERTY()
	class AAICharacter* AICharacterRef;

	UPROPERTY()
	class AImpactEffects* Effect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects)
	TSubclassOf<class AImpactEffects> EffectToSpawn;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Movement)
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Collision)
	class USphereComponent* Sphere;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Mesh)
	class UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = VFX)
	class UParticleSystemComponent* TrailFX;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = VFX)
	class UNiagaraSystem* ExplosionFX;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Damage)
	bool bIsCausingRadiusDamage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Impulses)
	class AExplosionImpulse* Impulse;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Impulses)
	TSubclassOf<class AExplosionImpulse> ImpulseToSpawn;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Damage)
	float CriticalHitModifier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Damage)
	FAmmoData AmmoData;

protected:
	UFUNCTION(BlueprintCallable)
	virtual void ProjectileStop(const FHitResult& HitResult);

	UFUNCTION(BlueprintCallable)
	virtual void ExplodeOnImpact(const FHitResult& HitResult);

	UFUNCTION()
	virtual void Spawn(const FHitResult& HitResult);

	UFUNCTION()
	void DealDamage(const FHitResult& HitResult);

	UFUNCTION()
	void SpawnImpact(const FHitResult& HitResult);

	UFUNCTION()
	void SpawnVFX();
};
