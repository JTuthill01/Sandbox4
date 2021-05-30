#pragma once

#include "CoreMinimal.h"
#include "Sandbox/Actors/Grenades/GrenadeBase.h"
#include "M18_Red.generated.h"

UCLASS()
class SANDBOX_API AM18_Red : public AGrenadeBase
{
	GENERATED_BODY()

public:
	AM18_Red();
	
	virtual void OnReleased(FVector ForwardVector) override;

	virtual void Explode() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Emitter)
	class UParticleSystem* SmokeEmitter;
};
