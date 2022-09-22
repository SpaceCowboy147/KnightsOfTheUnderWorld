// Fill out your copyright notice in the Description page of Project Settings.


#include "GoblinHealthComponent.h"

// Sets default values for this component's properties
UGoblinHealthComponent::UGoblinHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	DefaultHealth = 100;
	Health = DefaultHealth;
	
}


// Called when the game starts
void UGoblinHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	if (Owner)
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UGoblinHealthComponent::takeDamage);
	}
	 
	
	//don't need ticks for health
}

void UGoblinHealthComponent::takeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0)
	{
		return;
	}
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);
	//Clamp () method returns the value clamped to the inclusive range of min and max. The method returns the following: If min ≤ value ≤ max, the method returns value.
}


