#include <iostream>
#include <string>

using std::string;

string Items[10] =
    {
        "A fractured canine and 5 shiney pebbles.",
        "Waterlogged supplies and 2 lesser healing potions",
        "Mail leggings and a rusty dagger.",
        "A Scroll of Agility, and an unlit torch.",
        "A mail helmet and leather spaulders.",
        "The Belt of Dwarven Kind. This looks interesting.",
        "Bag of Beans. Hmmm. Plant them maybe?",
        "Wand of Wonder. I wonder what this does...",
        "The Ring Of Winter. Brrr is it cold in here?",
        "The Deck Of Many Things. Time to play some cards?"};

void GreetPlayer()
{
    std::cout << std::endl;
    std::cout << R"(
    *******************************************************************************
              |                   |                  |                     |
     _________|________________.=""_;=.______________|_____________________|_______
    |                   |  ,-"_,=""     `"=.|                  |
    |___________________|__"=._o`"-._        `"=.______________|___________________
              |                `"=._o`"=._      _`"=._                     |
     _________|_____________________:=._o "=._."_.-="'"=.__________________|_______
    |                   |    __.--" , ; `"=._o." ,-"""-._ ".   |
    |___________________|_._"  ,. .` ` `` ,  `"-._"-._   ". '__|___________________
              |           |o`"=._` , "` `; .". ,  "-._"-._; ;              |
     _________|___________| ;`-.o`"=._; ." ` '`."\` . "-._ /_______________|_______
    |                   | |o;    `"-.o`"=._``  '` " ,__.--o;   |
    |___________________|_| ;    (###) `-.o `"=.`_.--"_o.-; ;___|__________________
    ____/______/______/___|o;._    "      `".o|o_.--"    ;o;____/______/______/____
    /______/______/______/_"=._o--._        ; | ;        ; ;/______/______/______/_
    ____/______/______/______/__"=._o--._   ;o|o;     _._;o;____/______/______/____
    /______/______/______/______/____"=._o._; | ;_.--"o.--"_/______/______/______/_
    ____/______/______/______/______/_____"=.o|o_.--""___/______/______/______/____
    /______/______/______/______/______/______/______/______/______/______/[Mel R.]
    *******************************************************************************
)" << '\n';
    std::cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+= Welcome Traveler =+=+=+=+=+=+=+=+=+=+=+=+=+=\n";
    std::cout << "While exploring, you have found a strange looking cave.\n"; //  << std::endl also ends the line.
    std::cout << "Upon entering you see a large room filled with 10 chests of varying sizes.\n";
    std::cout << "You notice, all of them have a locking mechanism that has 3 number dials.\n";
    std::cout << "Start with the smallest chest first to crack the code an gain the loot.\n";
    std::cout << "But, hurry.There is probably someone or some... thing supposed to be guarding this room.\n\n";
}

bool PlayGame(int Difficulty)
{
    // Declare 3 number code
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << std::endl;
    std::cout << "\n\n* There are 3 numbers in the code.";
    std::cout << "\n* The code numbers add-up to: " << CodeSum;
    std::cout << "\n* The code numbers multiply to give: " << CodeProduct << std::endl;
    std::cout << "\nEnter each number to unlock the level " << Difficulty << " chest." << std::endl;

    // Gets Guess input from Player
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You have unlocked the chest!\n";
        std::cout << "You receive " << Items[Difficulty - 1];
        return true;
    }
    else
    {
        std::cout << "Your combination was incorrect!\nYou have set off a trap and are now stuck in a net 20ft off the ground.";
        return false;
    }
}

// Main function
int main()
{
    GreetPlayer();

    int Difficulty = 1;

    while (true)
    {
        bool bLevelComplete = PlayGame(Difficulty);
        std::cin.clear();  // clears the failbit
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete)
        {
            ++Difficulty;
        }
    }
    return 0;
}

// int main() // int is to let you know what value type the function is returning.
// {
//     int difficulty = 2;
//     int maxDifficulty = 10;
//     while (difficulty <= maxDifficulty)
//     {
//         PlayGame(difficulty);

//         ++difficulty;
//     }
//      std::cout << "You have unlocked all of the chests! Uh oh... You see a large pair of eyes peering at you from the darkness. RUN!"
//      return 0; // exits the program with no errors
// }
