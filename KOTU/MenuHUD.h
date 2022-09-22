// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.h"

/**
 * 
 */
class SKYRIMPS1_API AMenuHUD : public AHUD
{
	//GENERATED_BODY file not generated might need to be fixed

protected: 
	TSharedPtr<class SMainMenuWidget> MenuWidget;
	TSharedPtr<class SWidget> MenuWidgetContainer;
	
	virtual void BeginPlay() override;

public:
	void ShowMenu();
	void RemoveMenu();

};
