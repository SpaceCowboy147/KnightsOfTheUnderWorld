// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SKYRIMPS1_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
		//Base Shape collision : MoneyAutoPickups
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item | Collision")
		class USphereComponent* CollisionVolume;


		//base mesh component
		UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item | Mesh")
		class UStaticMeshComponent* Mesh;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Particles")
			class UParticleSystemComponent* IdleParticlesComponent;
		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Particles")
		class UParticleSystem* OverlapParticles;

		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Sounds")
		class USoundCue* OverlapSound;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | ItemProperties")
		bool bRotate;
		float RotationRate;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
