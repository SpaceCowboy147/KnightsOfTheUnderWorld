// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GoblinHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SKYRIMPS1_API UGoblinHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGoblinHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health") 
	float DefaultHealth;

	UPROPERTY(BlueprintReadOnly)
	float Health;

	//function
	
	UFUNCTION() //WILL NOT COMPILE IF THERE'S NO UFUNCTION IF THERE'S A DYNAMIC BINDING. 
	void takeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser); //taken from ontakedamage definition on actor


	//no ticks for health
		
};
