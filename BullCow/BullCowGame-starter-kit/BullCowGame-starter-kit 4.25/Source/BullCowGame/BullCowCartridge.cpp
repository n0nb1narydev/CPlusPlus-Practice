// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The hidden word is: %s."), *HiddenWord); // debug line
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Checking Player Guess
    {
        if (Input == HiddenWord.ToLower())
        {
            PrintLine(TEXT("Huzzah! You guessed the hidden word!"));
            EndGame();
        }
        else if (Input.Len() != HiddenWord.Len()) // || Input not isogram)
        {
            PrintLine(TEXT("The hidden word is an isogram\nthat is %i characters long."), HiddenWord.Len());
        }
        else
        {
            PrintLine("Moo... You got it wrong. Try again!");
            --Lives;
            if (Lives == 0)
            {
                PrintLine(TEXT("You ran out of lives."));
                PrintLine((TEXT("The HiddenWord was: %s..."), *HiddenWord));
                EndGame();
            }
            else if (Lives == 1)
            {
                PrintLine(TEXT("***You have %i life left!***"), Lives);
            }
            else
            {
                PrintLine(TEXT("**You have %i lives left!**"), Lives);
            }
            // check guess
            // check if isogram
            // guess again no lives lost
            // check if correct number of chars
            // guess again no lives lost
            // Guess again
        }
    }

    // Prompt to play again
    // PrintLine(TEXT("Would you like to play again?"));
    /*      
    Check input
    Play again or quit 
    */
}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Mooooo! Let's play some Bull Cows!"));

    HiddenWord = TEXT("dung");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!\nYou have %i lives."), HiddenWord.Len(), Lives);
    PrintLine(TEXT("Type in your guess and press ENTER."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press ENTER to play again!"));

} /* 
Game Loop 
Start the game
Set the Hidden Word
Prompt for the gues
is the guess correct
did they win or lose?
play again?
*/