// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "InputActionValue.h"
#include "Tank.generated.h"

/**
 *
 */
UCLASS()
class GDT_TOONTANKS_API ATank : public ABasePawn
{
    GENERATED_BODY()

  public:
    // Sets default values for this pawn's properties
    ATank();

  protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    class UInputMappingContext* TankMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    class UInputAction* MoveAction;

    void Move(const FInputActionValue& Value);

  private:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    class USpringArmComponent* SpringArm;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    class UCameraComponent* Camera;
};
