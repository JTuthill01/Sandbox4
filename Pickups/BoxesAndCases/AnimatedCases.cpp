#include "AnimatedCases.h"
#include "Components/SkeletalMeshComponent.h"
#include "Sandbox/Character/PlayerCharacter.h"
#include "Sandbox/Pickups/PickupBase.h"

// Sets default values
AAnimatedCases::AAnimatedCases()
{
	CaseMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Case Mesh"));

	SetRootComponent(CaseMesh);
}

void AAnimatedCases::OnBeginInteract_Implementation(AActor* OtherActor) 
{ 
	if (bHasBeenOpened == false)
	{
		RemoveWidgetTimer = 0.45F;

		AddWidget(OtherActor);

		GetWorldTimerManager().SetTimer(RemoveWidgetHandle, this, &AAnimatedCases::Remove, RemoveWidgetTimer, false);
	}
}

void AAnimatedCases::OnInteract_Implementation()
{
	if (bHasBeenOpened == false)
	{
		Open();
	}
}

// Called when the game starts or when spawned
void AAnimatedCases::BeginPlay()
{
	Super::BeginPlay();
}

void AAnimatedCases::SpawnCasePickups()
{
	FActorSpawnParameters Parms;
	Parms.Owner = this;
	Parms.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	int32 DefaultIndex = 0;

	for (size_t i = 0; i < NumOfPickupsToSpawn; ++i)
	{
		SpawnLocation = CaseMesh->GetSocketLocation(SocketNameArray[i]);

		SpawnRotator = CaseMesh->GetSocketRotation(SocketNameArray[i]);

		CurrentIndex = FMath::RandRange(0, PickupIndex);

		if (SpawnArray.IsValidIndex(CurrentIndex))
		{
			BasePickup = GetWorld()->SpawnActor<APickupBase>(SpawnArray[CurrentIndex], SpawnLocation, SpawnRotator, Parms);

			BasePickup->GetMesh()->SetSimulatePhysics(false);
		}

		else
		{
			BasePickup = GetWorld()->SpawnActor<APickupBase>(SpawnArray[DefaultIndex], SpawnLocation, SpawnRotator, Parms);

			BasePickup->GetMesh()->SetSimulatePhysics(false);
		}
	}
}

void AAnimatedCases::Open()
{
	CaseMesh->PlayAnimation(CaseOpenAnimation, false);

	SpawnCasePickups();

	bHasBeenOpened = true;
}

void AAnimatedCases::Remove()
{
	RemoveWidget();

	GetWorldTimerManager().ClearTimer(RemoveWidgetHandle);
}

void AAnimatedCases::AddWidget_Implementation(AActor* OtherActor) {}

void AAnimatedCases::RemoveWidget_Implementation() {}
