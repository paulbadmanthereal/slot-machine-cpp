#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::string spin() {
    std::vector<std::string> symbols = {"🍒", "🍒", "🍒", "🍊", "🍊", "🍇", "🍇", "🔔", "7️⃣", "🌟"};
    int index = rand() % symbols.size();
    return symbols[index];
}

void play_slot_machine() {
    std::cout << "Welcome to the C++ Slot Machine!" << std::endl;
    int coins = 1000;

    while (true) {
        std::cout << "You have " << coins << " coins." << std::endl;
        int bet;
        std::cout << "Enter your bet (0 to quit): ";
        std::cin >> bet;

        if (bet == 0) {
            break;
        } else if (bet > coins) {
            std::cout << "Insufficient coins. Please enter a valid bet." << std::endl;
            continue;
        }

        std::cout << "Press Enter to spin the reels...";
        std::cin.ignore();
        std::cin.get();

        std::string reel1 = spin();
        std::string reel2 = spin();
        std::string reel3 = spin();
        std::cout << reel1 << " | " << reel2 << " | " << reel3 << std::endl;

        if (reel1 == reel2 && reel2 == reel3 && reel1 == "🌟") {
            std::cout << "Jackpot! You win 1000 times your bet!" << std::endl;
            coins += bet * 1000;
        } else if (reel1 == reel2 && reel2 == reel3) {
            std::cout << "Three symbols match! You win 10 times your bet!" << std::endl;
            coins += bet * 10;
        } else if (reel1 == reel2 || reel1 == reel3 || reel2 == reel3) {
            std::cout << "Two symbols match! You win twice your bet!" << std::endl;
            coins += bet * 2;
        } else {
            std::cout << "No match. You lose your bet." << std::endl;
            coins -= bet;
        }

        if (coins == 0) {
            std::cout << "You've run out of coins. Game over!" << std::endl;
            break;
        }
    }

    std::cout << "You ended the game with " << coins << " coins." << std::endl;
    std::cout << "Thank you for playing!" << std::endl;
    std::cout << "the creator's github is at https://github.com/paulbadmanthereal" << std::endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    play_slot_machine();
    return 0;
}

