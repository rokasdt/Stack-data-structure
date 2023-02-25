#include <iostream>
#include <queue>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Attack { ROCK, PAPER, SCISSORS };

// naudojamas map kad butu zinoma kiekvienos atakos efektyvumas
map<Attack, pair<Attack, int>> attackEffectiveness = {
  {ROCK, {SCISSORS, 2}},
  {PAPER, {ROCK, 2}},
  {SCISSORS, {PAPER, 2}}
};

// kievieno kombo efektyvumas
map<pair<Attack, Attack>, pair<Attack, int>> comboAttacks = {
  {{ROCK, SCISSORS}, {PAPER, 3}},
  {{SCISSORS, PAPER}, {ROCK, 3}},
  {{PAPER, ROCK}, {SCISSORS, 3}}
};

// Struct saugo zaidejo duomenys
struct Player {
    string name;
    int lifePoints;
    queue<Attack> attackQueue;
};

// zaidejo atakos pasirinkimo funkcija
Attack getPlayerAttackChoice(Player& player) {
    int choice;
    cout << player.name << ", choose your attack:" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cout << "4. Exit game" << endl;
    cin >> choice;
    switch (choice) {
    case 1: return ROCK;
    case 2: return PAPER;
    case 3: return SCISSORS;
    case 4: exit(0);
    default:
        cout << "Invalid choice. Try again." << endl;
        return getPlayerAttackChoice(player);
    }
}

Attack getComputerAttackChoice() {
    srand(time(0));
    int choice = rand() % 3 + 1;
    switch (choice) {
    case 1: return ROCK;
    case 2: return PAPER;
    case 3: return SCISSORS;
    }
}

// Raundo funkcija
void performRound(Player& player1, Player& player2) {
    Attack attack1, attack2;
    // jeigu pirmas zaidejas turi ataka eileje, ji naudojama, jei ne duodamas atakos pasirinkimas
    if (!player1.attackQueue.empty()) {
        attack1 = player1.attackQueue.front();
        player1.attackQueue.pop();
    }
    else {
        attack1 = getPlayerAttackChoice(player1);
    }
    if (!player2.attackQueue.empty()) {
        attack2 = player2.attackQueue.front();
        player2.attackQueue.pop();
    }
    else {
        attack2 = getComputerAttackChoice();
    }

    // patikrinimas ar yra kombo

    auto comboIt = comboAttacks.find({ attack1, attack2 });
    if (comboIt != comboAttacks.end()) {
        cout << player1.name << " used combo attack " << comboIt->second.first << "!" << endl;
        player2.lifePoints -= comboIt->second.second;
        cout << player2.name << " lost " << comboIt->second.second << " life points." << endl;
        return;
    }

    // jeigu nera kombo, patikrinama atakos efektyvumas
    auto attackIt = attackEffectiveness.find(attack1);
    if (attackIt->second.first == attack2) {
        cout << player1.name << "'s attack was effective!" << endl;
        player2.lifePoints -= attackIt->second.second;
        cout << player2.name << " lost " << attackIt->second.second << " life points." << endl;
    }
    else {
        cout << player2.name << "'s attack was effective!" << endl;
        player1.lifePoints -= attackEffectiveness[attack2].second;
        cout << player1.name << " lost " << attackEffectiveness[attack2].second << " life points." << endl;
    }
}

int main() {
    cout << "Welcome to the rock-paper-scissors game!" << endl;
    cout << "Enter player 1's name: ";
    string player1Name;
    cin >> player1Name;
    cout << "Enter player 2's name: ";
    string player2Name;
    cin >> player2Name;
    cout << "Is player 2 a computer player? (y/n) ";
    char isComputer;
    cin >> isComputer;

    Player player1 = { player1Name, 20 };
    Player player2;
    if (isComputer == 'y') {
        player2 = { "Computer", 20 };
        player2.attackQueue.push(getComputerAttackChoice());
    }
    else {
        player2 = { player2Name, 20 };
    }

    while (player1.lifePoints > 0 && player2.lifePoints > 0) {
        cout << "Player 1 life points: " << player1.lifePoints << endl;
        cout << "Player 2 life points: " << player2.lifePoints << endl;
        performRound(player1, player2);
    }

    if (player1.lifePoints <= 0) {
        cout << player2.name << " wins!" << endl;
    }
    else {
        cout << player1.name << " wins!" << endl;
    }
    return 0;
}
   