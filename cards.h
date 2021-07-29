//cards.h
//Authors: Dingfan Zheng
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <string>
#include <ostream>

using namespace std;

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
class Card{
public:
    string cardname;
    bool operator==(const Card &rhs) const;
    Card();
    Card(const string &cardname);

    friend ostream &operator<<(ostream &os, const Card &card);
};
class CardList{
public:
    CardList(); //constructor
    ~CardList();  //destructor
    CardList(const CardList& source); //copy constructor
    CardList& operator=(const CardList& source);
    void append(string value); //append

    void remove(Card card);//remove
    bool contains(Card card); //contains

    friend ostream& operator<<(ostream& out, CardList list);


    struct Node {
        Card card;
        Node *next;
    };
    Node *first;
};


class player{
public:
    player(string name, const CardList &cards);
    Card nextCard();
    bool isDone();
    void remove(Card card);
    bool contains(Card card);

    friend ostream& operator<<(ostream& out, player p);
private:
    string name;
    CardList cards;
    CardList::Node* nextNode;
};

#endif