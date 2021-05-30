#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "ShotgunAmmoUpdateNotify.generated.h"

/**
 * 
 */
UCLASS()
class SANDBOX_API UShotgunAmmoUpdateNotify : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
