// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();

    if (bGameOver == true)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {

        PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
        PrintLine(TEXT("Type in your guess and press enter."));

        // check guess
        // check if isogram
        // guess again no lives lost
        // check if correct number of chars
        // guess again no lives lost

        if (Input == HiddenWord.ToLower())
        {
            PrintLine(TEXT("Huzzah! You guessed the hidden word!"));
            EndGame();
        }
        else if (Input.Len() != HiddenWord.Len()) // || Input not isogram)
        {
            PrintLine(TEXT("The hidden word is an isogram that is %i characters long."), HiddenWord.Len());
        }
        else
        {
            PrintLine("Moo... You got it wrong. Try again!");
            Lives--;
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
    HiddenWord = TEXT("dung");
    Lives = HiddenWord.Len();
    bGameOver = false;
    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); // Debug Line
    PrintLine(TEXT("Mooooo! Let's play some Bull Cows!"));
    PrintLine(TEXT("Press Enter to start..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press ENTER to restart!"))
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