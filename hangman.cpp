#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class HangmanGame {
private:
    std::string word;
    std::string guessedWord;
    int maxAttempts;
    int remainingAttempts;
    std::vector<char> incorrectGuesses;

public:
    HangmanGame(const std::string& word, int maxAttempts)
        : word(word), maxAttempts(maxAttempts), remainingAttempts(maxAttempts) {
        initializeGuessedWord();
    }

    void play() {
        while (remainingAttempts > 0 && guessedWord != word) {
            displayHangman();
            displayGuessedWord();
            displayIncorrectGuesses();
            char guess = getGuess();
            updateGameState(guess);
        }

        displayResult();
    }

private:
    void initializeGuessedWord() {
        guessedWord = std::string(word.length(), '_');
    }

    void displayHangman() {
        int incorrectGuessCount = maxAttempts - remainingAttempts;
        std::cout << "Incorrect guesses: " << incorrectGuessCount << "/" << maxAttempts << std::endl;

        switch (incorrectGuessCount) {
        case 1:
            std::cout << "   +---+" << std::endl;
            std::cout << "   |   |" << std::endl;
            std::cout << "       |" << std::endl;
            std::cout << "       |" << std::endl;
            std::cout << "       |" << std::endl;
            std::cout << "       |" << std::endl;
            break;
        case 2:
            std::cout << "   +---+" << std::endl;
            std::cout << "   |   |" << std::endl;
            std::cout << "   O   |" << std::endl;
            std::cout << "       |" << std::endl;
            std::cout << "       |" << std::endl;
            std::cout << "       |" << std::endl;
            break;
        case 3:
            std::cout << "   +---+" << std::endl;
            std::cout << "   |   |" << std::endl;
            std::cout << "   O   |" << std::endl;
            std::cout << "   |   |" << std::endl;
            std::cout << "       |" << std::endl;
            std::cout << "       |" << std::endl;
            break;
        case 4:
            std::cout << "   +---+" << std::endl;
            std::cout << "   |   |" << std::endl;
            std::cout << "   O   |" << std::endl;
            std::cout << "  /|   |" << std::endl;
            std::cout << "       |" << std::endl;
            std::cout << "       |" << std::endl;
            break;
        case 5:
            std::cout << "   +---+" << std::endl;
            std::cout << "   |   |" << std::endl;
            std::cout << "   O   |" << std::endl;
            std::cout << "  /|\\  |" << std::endl;
            std::cout << "       |" << std::endl;
            std::cout << "       |" << std::endl;
            break;
        case 6:
            std::cout << "   +---+" << std::endl;
            std::cout << "   |   |" << std::endl;
            std::cout << "   O   |" << std::endl;
            std::cout << "  /|\\  |" << std::endl;
            std::cout << "  /    |" << std::endl;
            std::cout << "       |" << std::endl;
            break;
        case 7:
            std::cout << "   +---+" << std::endl;
            std::cout << "   |   |" << std::endl;
            std::cout << "   O   |" << std::endl;
            std::cout << "  /|\\  |" << std::endl;
            std::cout << "  / \\  |" << std::endl;
            std::cout << "       |" << std::endl;
            break;
        default:
            break;
        }
    }

    void displayGuessedWord() {
        std::cout << "Guessed Word: ";
        for (char letter : guessedWord) {
            std::cout << letter << " ";
        }
        std::cout << std::endl;
    }

    void displayIncorrectGuesses() {
        if (!incorrectGuesses.empty()) {
            std::cout << "Incorrect Guesses: ";
            for (char guess : incorrectGuesses) {
                std::cout << guess << " ";
            }
            std::cout << std::endl;
        }
    }

    char getGuess() {
        char guess;
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        return guess;
    }

    void updateGameState(char guess) {
        if (word.find(guess) != std::string::npos) {
            // Correct guess
            for (size_t i = 0; i < word.length(); ++i) {
                if (word[i] == guess) {
                    guessedWord[i] = guess;
                }
            }
        } else {
            // Incorrect guess
            incorrectGuesses.push_back(guess);
            --remainingAttempts;
        }
    }

    void displayResult() {
        displayHangman();
        displayGuessedWord();

        if (guessedWord == word) {
            std::cout << "Congratulations! You guessed the word correctly." << std::endl;
        } else {
            std::cout << "Sorry, you ran out of attempts. The word was: " << word << std::endl;
        }
    }
};

int main() {
    // Set a list of words and choose one randomly
    std::vector<std::string> words = {"programming", "hangman", "computer", "cplusplus", "algorithm"};
    srand(static_cast<unsigned int>(time(nullptr)));
    std::string selectedWord = words[rand() % words.size()];

    // Create a HangmanGame object and play the game
    HangmanGame game(selectedWord, 7);
    game.play();

    return 0;
}
