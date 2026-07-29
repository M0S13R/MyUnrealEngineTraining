// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Kismet/KismetSystemLibrary.h"

#include "MyProjectCharacter.h"


void UMenuWidget::NativeConstruct()
{
	BTN_Continue->OnClicked.AddDynamic(this, &UMenuWidget::OnContinueClicked);
	
	BTN_Exit->OnClicked.AddDynamic(this, &UMenuWidget::OnExitClicked);
	
	BTN_NavLeft->OnClicked.AddDynamic(this, &UMenuWidget::OnNavLeftClicked);
	
	BTN_NavRight->OnClicked.AddDynamic(this, &UMenuWidget::OnNavRightClicked);	
}

void UMenuWidget::OnNavLeftClicked()
{
	if (MenuSwitcher) MenuSwitcher->SetActiveWidgetIndex(0);
}

void UMenuWidget::OnNavRightClicked()
{
	if (MenuSwitcher) MenuSwitcher->SetActiveWidgetIndex(1);
}

void UMenuWidget::OnContinueClicked()
{
	APlayerController* PC = GetOwningPlayer();
	if (PC)
	{
		PC->SetPause(false);
		PC->bShowMouseCursor = false;
		PC->SetInputMode(FInputModeGameOnly());
	}
	RemoveFromParent();
}

void UMenuWidget::OnExitClicked()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
}
