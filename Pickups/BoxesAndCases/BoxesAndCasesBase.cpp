#include "BoxesAndCasesBase.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sandbox/Interfaces/PlayerRef.h"
#include "Kismet/KismetMathLibrary.h"
#include "Sandbox/Pickups/PickupBase.h"

// Sets default values
ABoxesAndCasesBase::ABoxesAndCasesBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Hull = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hull"));

	Lid = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lid"));
	Lid->SetupAttachment(Hull);

	SetRootComponent(Hull);
}

void ABoxesAndCasesBase::OnBeginInteract_Implementation(AActor* OtherActor)
{
	if (bHasBeenOpened == false)
	{	
		RemoveWidgetTimer = 0.45F;

		AddWidget(OtherActor);

		GetWorldTimerManager().SetTimer(RemoveWidgetHandle, this, &ABoxesAndCasesBase::Remove, RemoveWidgetTimer, false);
	}
}

void ABoxesAndCasesBase::OnInteract_Implementation()
{
	if (bHasBeenOpened == false)
	{
		Open();
	}
}

// Called when the game starts or when spawned
void ABoxesAndCasesBase::BeginPlay()
{
	Super::BeginPlay();
}

void ABoxesAndCasesBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bShouldLidMove == true)
	{
		Lid->AddLocalOffset(FVector(0.F, 0.74F, 0.F));
	}
}

void ABoxesAndCasesBase::Open()
{
	TimeToMove = 0.45F;

	SpawnTimer = 0.7F;

	bHasBeenOpened = true;

	bShouldLidMove = true;

	Lid->SetSimulatePhysics(true);

	GetWorld()->GetTimerManager().SetTimer(MoveLidTimerHandle, this, &ABoxesAndCasesBase::StopLidMovement, TimeToMove, false);

	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ABoxesAndCasesBase::SpawnCasePickup, SpawnTimer, false);
}

void ABoxesAndCasesBase::SpawnCasePickup()
{
	FActorSpawnParameters Parms;
	Parms.Owner = this;
	Parms.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	int32 DefaultIndex = 0;

	for (size_t i = 0; i < NumOfPickupsToSpawn; ++i)
	{
		SpawnLocation = Hull->GetSocketLocation(SocketNameArray[i]);

		SpawnRotator = Hull->GetSocketRotation(SocketNameArray[i]);

		CurrentIndex = FMath::RandRange(0, PickupIndex);

		if (SpawnArray.IsValidIndex(CurrentIndex))
		{
			BasePickup = GetWorld()->SpawnActor<APickupBase>(SpawnArray[CurrentIndex], SpawnLocation, SpawnRotator, Parms);
		}

		else
		{
			BasePickup = GetWorld()->SpawnActor<APickupBase>(SpawnArray[DefaultIndex], SpawnLocation, SpawnRotator, Parms);
		}
	}

	GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
}

void ABoxesAndCasesBase::Remove()
{
	RemoveWidget();

	GetWorldTimerManager().ClearTimer(RemoveWidgetHandle);
}

void ABoxesAndCasesBase::StopLidMovement() 
{
	bShouldLidMove = false;

	GetWorld()->GetTimerManager().ClearTimer(MoveLidTimerHandle);
}

void ABoxesAndCasesBase::AddWidget_Implementation(AActor* OtherActor){}

void ABoxesAndCasesBase::RemoveWidget_Implementation(){}




