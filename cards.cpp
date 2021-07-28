//cards.cpp
//Authors: Dingfan Zheng
//Implementation of the classes defined in cards.h
void AddCard(string x) {
    node *tmp = new node;
    tmp->number = x;
    tmp->next = NULL;
}
