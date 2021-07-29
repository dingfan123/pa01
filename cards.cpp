#include "cards.h"
#include <iostream>

using namespace std;
//cards.cpp
//Authors: Dingfan Zheng
//Implementation of the classes defined in cards.h



// copy constructor
CardList::CardList(const CardList &source) {
    first = nullptr;
    Node *prev = nullptr;
    for (Node *sourceNode = source.first; sourceNode != nullptr; sourceNode = sourceNode->next) {

        Node *copy = new Node;
        copy->card = sourceNode->card;
        copy->next = nullptr;

        if (first == nullptr) {
            first = copy;
        }
        if (prev != nullptr) {
            prev->next = copy;
        }
        prev = copy;
    }
}

// destructor
CardList::~CardList() {
    Node *node = first;
    while (node != nullptr) {
        Node *temp = node;
        node = node->next;
        delete temp;
    }
}

//append
void CardList::append(string value) {
    if (first == 0) { // empty list
        first = new Node;
        first->card = value;
        first->next = 0;
    } else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->card = value;
        n->next->next = 0;
    }
}


//remove
ostream &operator<<(ostream &out, CardList list) {
    CardList::Node *n = list.first;
    while (n) {
        out << n->card;
        if (n->next)
            cout << endl;
        n = n->next;
    }

    return out;
}

bool CardList::contains(Card card) {
    Node *node = first;
    while (node != nullptr) {
        if (node->card == card)
            return true;
        node = node->next;
    }
    return false;
}


void CardList::remove(Card card) {
    Node *node = first;
    Node *prev = nullptr;
    while (node != nullptr) {
        if (node->card == card) {
            if (prev == nullptr) { // first node
                first = node->next;
            } else {
                prev->next = node->next;
            }
            delete node;
            return;
        }
        prev = node;
        node = node->next;
    }
}

CardList::CardList() {
    first = nullptr;
}

CardList &CardList::operator=(const CardList &source) {
    Node *node = first;
    while (node != nullptr) {
        Node *temp = node;
        node = node->next;
        delete temp;
    }
    first = nullptr;
    Node *prev = nullptr;
    for (Node *sourceNode = source.first; sourceNode != nullptr; sourceNode = sourceNode->next) {

        Node *copy = new Node;
        copy->card = sourceNode->card;
        copy->next = nullptr;

        if (first == nullptr) {
            first = copy;
        }
        if (prev != nullptr) {
            prev->next = copy;
        }
        prev = copy;
    }
    return *this;
}

player::player(string name, const CardList &cards) : name(name), cards(cards) {
    nextNode = cards.first;
}

Card player::nextCard() {
    Card card = nextNode->card;
    nextNode = nextNode->next;
    return card;
}

void player::remove(Card card) {
    if (card == nextNode->card) {
        nextNode = nextNode->next;
    }
    cards.remove(card);
}

bool player::contains(Card card) {
    return cards.contains(card);
}

bool player::isDone() {
    return nextNode == nullptr;
}

ostream &operator<<(ostream &out, player p) {
    out << p.name << "'s cards: " << endl;
    out << p.cards;
    return out;
}

Card::Card(const string &cardname) : cardname(cardname) {}

bool Card::operator==(const Card &rhs) const {
    return cardname == rhs.cardname;
}

ostream &operator<<(ostream &os, const Card &card) {
    os << card.cardname;
    return os;
}

Card::Card() {
}
