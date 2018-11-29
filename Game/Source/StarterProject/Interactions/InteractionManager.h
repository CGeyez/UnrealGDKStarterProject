// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/DataTable.h"
#include "Interactions/InteractAction.h"
#include "UObject/NoExportTypes.h"
#include "InteractionManager.generated.h"


USTRUCT(BlueprintType)
struct STARTERPROJECT_API FInteractionActionData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactions")
	TSubclassOf<AInteractAction> ActionType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactions")
	FName FunctionToCall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactions")
	bool bRunOnServer;
};

USTRUCT(BlueprintType)
struct STARTERPROJECT_API FInteractionMenuData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactions")
	TSubclassOf<AActor> ActorType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactions")
	TSubclassOf<UUserWidget> MenuType;

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARTERPROJECT_API UInteractionManager : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UInteractionManager();

	// Opens an interaction menu to interact with the target actor.
	// Infers the menu to open based on the actor's type.
	void OpenMenu(AActor* Target);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerOpenMenu(AActor* Target);

	void CloseMenu();

	bool IsMenuOpen() { return CurrentMenu != nullptr; }

	void DoAction(FName ActionName);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDoAction(FName ActionName);

	bool IsActorInteractable(AActor* Target);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UFUNCTION()
	void OnRep_TargetActor();

	AActor* TargetActor;

	UPROPERTY()
	class UUserWidget* CurrentMenu;

	UPROPERTY(EditAnywhere, Category = "Interactions")
	class UDataTable* MenuDataTable;

	UPROPERTY(EditAnywhere, Category = "Interactions")
	class UDataTable* ActionDataTable;

	UPROPERTY()
	TMap<FName, class AInteractAction*> InteractActionCache;

	UPROPERTY()
	TMap<FName, class UUserWidget*> InteractMenuCache;
	
};