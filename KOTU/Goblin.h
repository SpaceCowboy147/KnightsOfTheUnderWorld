

#pragma once

#include "Engine.h"
#include "GameFramework/Character.h"

//unreal engine components. files need to be quoted
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "Blueprint/UserWidget.h"


// any includes need to be above default class
#include "Goblin.generated.h"

UCLASS()
class SKYRIMPS1_API AGoblin : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGoblin();

																		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera) //VisibleAnywhere: be able to see the variable we mark in details panel in UnrealEngine
		USpringArmComponent* CameraBoom; //*pointer		        //BlueprintReadOnly: read only variables in blueprint and not be able to edit them
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* FollowCamera;

	/** Collection sphere - only needed for AutoPickups */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* CollectionSphere;


	void MoveForward(float Axis);
	void MoveRight(float Axis);




	bool bDead; //determines if character is dead or not
	
	TArray<FString> Inventory;
	bool bIsPickingUp = false;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	/** Function to collect every AutoPickup in range. */
	void CollectAutoPickups();

	/** Function to check for the closest Interactable in sight and in range. */
	void CheckForInteractables();

	void BeginPickup();
	void EndPickup();
	void ShowInventory();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//virtual void Tick(float DeltaTime) override; required to collect any pickup

	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	//Items and weapons
	void manPickup();
	void LMBUp();
	void LMBDown();

	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Items)
		class AWeapon* EquippedWeapon;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Items)
	class AItem* ActiveOverlappingItem;

	FORCEINLINE void SetEquippedWeapon(AWeapon* WeaponToSet) { EquippedWeapon = WeaponToSet; }
	FORCEINLINE void SetActiveOverlappingItem(AItem* Item) { ActiveOverlappingItem = Item; }
};
