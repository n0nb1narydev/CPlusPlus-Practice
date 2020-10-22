// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();                                    // Game won't work without this
    PrintLine(TEXT("Mooooo! Let's play some Bull Cows!")); // Just like std::cout << "Welcome!";                   // using TEXT macro for strings
    // For strings, instead of std::string Word = "Welcome!"; use FString.

    // Setting up game
    HiddenWord = TEXT("dung"); // Set the HiddenWord
    lives = 4;                 // instead of int, use int32
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();

    while (lives > 0)
    {
        PrintLine(TEXT("Guess the 4 letter word!"));

        if (Input == HiddenWord)
        {
            PrintLine("Huzzah! You guessed the hidden word!");
            break;
        }
        else
        {
            PrintLine("Moo... You got it wrong. Try again!");
        }
        // check if isogram
        // check if correct number of chars
        lives--;
    }

    if (lives == 0)
    {
        PrintLine("The hidden word was: " + HiddenWord + "...");
        PrintLine("You ran out of lives. :(");
    }
    // Prompt to play again
    PrintLine("Would you like to play again?")
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