#include <conio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <Windows.h>

const std::string MarginFix = "    ";

bool IsPlayerGuessCompatible(std::string PlayerGuess)
{

    if (PlayerGuess.size() != 3)
        return false;

    if (!isdigit(PlayerGuess[0]) || !isdigit(PlayerGuess[1]) || !isdigit(PlayerGuess[2]))
        return false;

    return true;
}

void PrintIntroduction()
{
    std::cout << R"(
                  _______________
                 |  ___________  |
                 | |   X X X   | |
                 | |___________| |
                 |  ___ ___ ___  |
    TRIPLE X     | | 7 | 8 | 9 | |
                 | |___|___|___| |
                 | | 4 | 5 | 6 | |
                 | |___|___|___| |
                 | | 1 | 2 | 3 | |
                 | |___|___|___| |
                 | | . | 0 | E | |
                 | |___|___|___| |
                 |_______________|       
)" << '\n';

    std::cout << MarginFix << "Oh shit, you're locked in a weird looking room! \n";
    std::cout << MarginFix << "Looks like you can escape using a passcode! \n\n";
    std::cout << MarginFix << "Press any key to continue...";
    getch();
}

bool PlayGame(int Dificulty)
{

    // Declare 3 numbers code
    const int CodeA = rand() % Dificulty + Dificulty;
    const int CodeB = rand() % Dificulty + Dificulty;
    const int CodeC = rand() % Dificulty + Dificulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    system("cls");
    std::cout << MarginFix << "YOU'RE IN THE ROOM LEVEL " << Dificulty << "\n";
    std::cout << MarginFix << "------------------------------------\n";
    std::cout << MarginFix << "  + There are 3 numbers in the code\n";
    std::cout << MarginFix << "  + The code add-up to: " << CodeSum << "\n";
    std::cout << MarginFix << "  + The code multiply to give: " << CodeProduct << "\n\n";
    std::cout << MarginFix << "Enter the code to escape \n";
    std::cout << MarginFix << "------------------------------------";

    std::cout << std::endl;

    std::string PlayerGuess;
    std::cin >> PlayerGuess;

    while (IsPlayerGuessCompatible(PlayerGuess) == false)
    {
        std::cout << "\n\n";
        std::cout << MarginFix << "Opss... you entered an incompatible answer! \n";
        std::cout << MarginFix << "Only 3 numbers to break the code! \n";
        std::cout << MarginFix << "Lets try again: \n\n";

        std::cin >> PlayerGuess;
    }

    int GuessA = PlayerGuess[0] - '0';
    int GuessB = PlayerGuess[1] - '0';
    int GuessC = PlayerGuess[2] - '0';

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    return GuessSum == CodeSum && GuessProduct == CodeProduct;
}

int main()
{

    int LevelDificulty = 1;
    int MaxDificulty = 5;

    int PlayerAttempt = 1;
    int MaxAttempt = 3;

    PrintIntroduction();

    while (LevelDificulty <= MaxDificulty && PlayerAttempt <= MaxAttempt)
    {
        bool bLevelComplete = PlayGame(LevelDificulty);

        if (bLevelComplete)
        {
            ++LevelDificulty;

            if (LevelDificulty > MaxDificulty)
            {
                system("cls");
                std::cout << MarginFix << "CONGRATULATIONS! YOU'RE FREE NOW! RUN! \n\n";
                std::cout << MarginFix << "Press any key to exit...";
                getch();
            }

            system("cls");
            std::cout << MarginFix << "Door opened! Going to the next room";
            Sleep(1000);
            std::cout << ".";
            Sleep(1000);
            std::cout << ".";
            Sleep(1000);
            std::cout << ".";
        }

        else
        {
            ++PlayerAttempt;
            if (PlayerAttempt <= MaxAttempt)
            {
                system("cls");
                std::cout << MarginFix << "OH NO! YOU ENTERED A WRONG PASSCODE \n";
                std::cout << MarginFix << "LETS REBOOT THE SYSTEM AND TRY AGAIN \n\n";
                std::cout << MarginFix << MaxAttempt - PlayerAttempt << " Attempts remainig\n\n";
                std::cout << MarginFix << "Press any key to restart the level...";
                getch();
            }
            else
            {
                system("cls");
                std::cout << MarginFix << "!!!!!! ALARM STARTED !!!!!!\n\n";
                std::cout << MarginFix << "THERE ARE GUARDS ALL OVER THE PLACE \n\n";
                std::cout << R"( 
      O
     <\==-   -   - -   -  -  - ---
    ./ \                            _/\_\O )";
                std::cout << "\n"
                          << MarginFix << "YOU'RE DEAD NOW!\n\n\n";
                std::cout << MarginFix << "Press any key to exit...";
                getch();
            }
        }
    }

    return 0;
}