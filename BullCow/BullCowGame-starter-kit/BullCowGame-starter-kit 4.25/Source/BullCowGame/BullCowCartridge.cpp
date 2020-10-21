// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();                              // Game won't work without this
    PrintLine("Mooooo! Let's play some Bull Cows!"); // Just like std::cout << "Welcome!";
    PrintLine("Press enter to start...");            // For strings, instead of std::string Word = "Welcome!"; use FString.
                                                     // instead of int, use int32
}

void UBullCowCartridge::OnInput(const FString & Input) // When the player hits enter
{
    ClearScreen();
    FString HiddenWord = "dung";
}