// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/EditableText.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
class UButton;
class UWidgetSwitcher;
class UCheckBox;

UCLASS()
class MYPROJECT_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> MenuSwitcher;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> BTN_NavLeft;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> BTN_NavRight;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> BTN_Continue;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	TObjectPtr<UButton> BTN_Exit;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UEditableText> ETB_PlayerName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UCheckBox> CB_ShowName;
	
private:
	UFUNCTION()
	void OnContinueClicked();
	
	UFUNCTION()
	void OnExitClicked();
	
	UFUNCTION()
	void OnNavLeftClicked();
	
	UFUNCTION()
	void OnNavRightClicked();
};
