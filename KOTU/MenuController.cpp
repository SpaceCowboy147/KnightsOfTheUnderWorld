// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuController.h"
#include "MenuHUD.h"

AMenuController::AMenuController()
{

}
void AMenuController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AMenuController::OpenMenu);
	}
}

void AMenuController::OpenMenu()
{

	if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(GetHUD()))
	{

	MenuHUD->ShowMenu();
}
}