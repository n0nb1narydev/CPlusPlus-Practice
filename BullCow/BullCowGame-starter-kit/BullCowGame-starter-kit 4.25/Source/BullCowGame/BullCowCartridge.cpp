// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();                                    // Game won't work without this
    PrintLine(TEXT("Mooooo! Let's play some Bull Cows!")); // Just like std::cout << "Welcome!";                   // using TEXT macro for strings
    PrintLine(TEXT("Guess the 4 letter word!"));           // make length variable in place of 4          // For strings, instead of std::string Word = "Welcome!"; use FString.
    HiddenWord = TEXT("dung");                             // instead of int, use int32
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();
    int lives = 5;

    while (lives > 0)
    {
        if (Input == HiddenWord)
        {
            PrintLine("Huzzah! You guessed the hidden word!");
            break;
        }
        else
        {
            PrintLine("Moo... You got it wrong. Try again!");
            lives--;
            continue;
        }
    }
    if (lives == 0)
    {
        PrintLine("The hidden word was: " + HiddenWord + "...");
        PrintLine("You ran out of lives. :( Play again?");
    }
}

/* 
Game Loop 
Start the game
Set the Hidden Word
Prompt for the gues
is the guess correct
did they win or lose?
play again?
*/