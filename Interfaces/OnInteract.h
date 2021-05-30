#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OnInteract.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UOnInteract : public UInterface
{
	GENERATED_BODY()
};

class SANDBOX_API IOnInteract
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnInteract();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnBeginInteract(AActor* OtherActor);
};
