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
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Mooooo! Let's play some Bull Cows!"));

    HiddenWord = TEXT("dung");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!\nYou have %i lives."), HiddenWord.Len(), Lives);
    PrintLine(TEXT("Type in your guess and press ENTER."));

    const TCHAR HW[] = TEXT(dung);
    PrintLine(TEXT("Character 1 of the hidden word is: %c."), HiddenWord[0]);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press ENTER to play again!"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord.ToLower())
    {
        PrintLine(TEXT("Huzzah! You guessed the hidden word!"));
        EndGame();
        return;
    }

    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden word is %i characters long."), HiddenWord.Len());
        return;
    }

    if (!IsIsogram(Guess))
    {
        PrintLine("The hidden word has no repeating letters. \nTry again!");
        return;
    }

    PrintLine("Moo... You got it wrong and lost a life. \nTry again!");

    --Lives;

    if (Lives == 0)
    {
        PrintLine(TEXT("You ran out of lives."));
        PrintLine(TEXT("The HiddenWord was: %s..."), *HiddenWord);
        EndGame();
        return;
    }

    if (Lives == 1)
    {
        PrintLine(TEXT("***You have %i life left!***"), Lives);
        return;
    }

    if (Lives > 1)
    {
        PrintLine(TEXT("**You have %i lives left!**"), Lives);
        return;
    }

    // Show player Bulls and Cows
}

bool UBullCowCartridge::IsIsoGram(FString Word)
{
    // is bIsIsogram function
    // guess passed in a parameter
    // for each letter starting at 0
    // does guess have more of a particular letter?
    // until we reach word.len() - 1

    // if any letterd sre the same, return false

    // first step: does first letter in guess match first letter in word
    //      does it match any letter in word?
    // repeat this with all letters in guess.
}