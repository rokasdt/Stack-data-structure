#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to get the user's input
string getPlayerChoice()
{
    string choice;
    cout << "Please enter your choice (rock, paper, or scissors): ";
    cin >> choice;

    // Validate the user's input
    while (choice != "rock" && choice != "paper" && choice != "scissors")
    {
        cout << "Invalid choice. Please enter rock, paper, or scissors: ";
        cin >> choice;
    }

    return choice;
}

// Function to get the computer's choice
string getComputerChoice()
{
    int choice = rand() % 3;
    if (choice == 0)
    {
        return "rock";
    }
    else if (choice == 1)
    {
        return "paper";
    }
    else
    {
        return "scissors";
    }
}

// Function to determine the winner of the game
string determineWinner(string playerChoice, string computerChoice)
{
    if (playerChoice == "rock")
    {
        if (computerChoice == "rock")
        {
            return "It's a tie!";
        }
        else if (computerChoice == "paper")
        {
            return "Computer wins!";
        }
        else
        {
            return "Player wins!";
        }
    }
    else if (playerChoice == "paper")
    {
        if (computerChoice == "rock")
        {
            return "Player wins!";
        }
        else if (computerChoice == "paper")
        {
            return "It's a tie!";
        }
        else
        {
            return "Computer wins!";
        }
    }
    else
    {
        if (computerChoice == "rock")
        {
            return "Computer wins!";
        }
        else if (computerChoice == "paper")
        {
            return "Player wins!";
        }
        else
        {
            return "It's a tie!";
        }
    }
}

int main()
{
    // Seed the random number generator
    srand(time(0));

    // Get the player's choice
    string playerChoice = getPlayerChoice();

    // Get the computer's choice
    string computerChoice = getComputerChoice();

    // Determine the winner of the game
    string winner = determineWinner(playerChoice, computerChoice);

    // Print the results
    cout << "Player chose: " << playerChoice << endl;
    cout << "Computer chose: " << computerChoice << endl;
    cout << winner << endl;

    return 0;
}
