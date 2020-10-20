#include <iostream>

int GreetPlayer()
{
    std::cout << "You are an explorer who has found a strange looking cave.\n"; //  << std::endl also ends the line.
    std::cout << "Upon entering you see a strange room filled with chests of varying sizes.\n";
    std::cout << "You notice, all of them have a locking mechanism that has 3 number dials.\n";
    std::cout << "Start with the smallest chest first to crack the code an gain the loot.\n";
    std::cout << "But, hurry.There is probably someone or some... thing supposed to be guarding this room.\n";

    return 0;
}

// Need to find a valid combination of codes

// starts easy and becomes much harder

// Main function
int main()
{
    // Declare 3 number code
    const int codeA = 4;
    const int codeB = 3;
    const int codeC = 2;

    const int codeSum = codeA + codeB + codeC;
    const int codeProduct = codeA * codeB * codeC;

    //Print sum and product to the terminal
    std::cout << std::endl;
    std::cout << "* There are 3 numbers in the code." << std::endl;
    std::cout << "* The code numbers add-up to: " << codeSum << std::endl;
    std::cout << "* The code numbers multiply to give: " << codeProduct << std::endl;
}

=
    // int main() // int is to let you know what value type the function is returning.
    // {
    //     int difficulty = 2;
    //     int maxDifficulty = 10;
    //     while (difficulty <= maxDifficulty)
    //     {
    //         PlayGame(difficulty);
    //         std::cin.clear(); // clears the failbit
    //         std::cin.ignore(); // discards the buffer
    //         ++difficulty;
    //     }
    //      std::cout << "You have unlocked all of the chests! Uh oh... You see a large pair of eyes peering at you from the darkness. RUN!"
    //      return 0; // exits the program with no errors
    // }
