#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"


using namespace std;

int main(int argv, char **argc) {
    if (argv != 3) {
        cout << "Please provide 2 file names" << endl;
        return 1;
    }

    ifstream cardFile1(argc[1]);
    ifstream cardFile2(argc[2]);
    string line;

    if (cardFile1.fail()) {
        cout << "Could not open file " << argc[1];
        return 1;
    }

    if (cardFile2.fail()) {
        cout << "Could not open file " << argc[2];
        return 1;
    }

    // Create two objects of the class you defined
    // to contain two sets of cards in two input files

    // Read each file and store cards
    CardList aliceCards;
    while (getline(cardFile1, line) && (line.length() > 0)) {
        aliceCards.append(line);
    }
    cardFile1.close();
    CardList bobCards;
    while (getline(cardFile2, line) && (line.length() > 0)) {
        bobCards.append(line);
    }
    cardFile2.close();

    player alice("Alice", aliceCards);
    player bob("Bob", bobCards);

    // Start the game

    while (!alice.isDone() || !bob.isDone()) {
        while (!alice.isDone()) {
            Card card = alice.nextCard();
            if (bob.contains(card)) {
                cout << "Alice picked matching card " << card << endl;
                alice.remove(card);
                bob.remove(card);
                break;
            }
        }

        while (!bob.isDone()) {
            Card card = bob.nextCard();
            if (alice.contains(card)) {
                cout << "Bob picked matching card " << card << endl;
                bob.remove(card);
                alice.remove(card);
                break;
            }
        }
    }

    cout<<alice;
    cout<<endl;
    cout<<bob;


    return 0;
}
