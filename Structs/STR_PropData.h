#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STR_PropData.generated.h"

USTRUCT(BlueprintType)
struct FPropData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DamageToDeal;
};

UCLASS()
class SANDBOX_API ASTR_PropData : public AActor
{
	GENERATED_BODY()
	
public:	
	ASTR_PropData();
};
