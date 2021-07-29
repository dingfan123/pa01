// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    runAll();
    return 0;
}

void runAll() {
    test_append();
    test_list();
    test_card();
}

void test_append() {
    START_TEST("test_append");
    test_append_empty_list();
    test_append_single_element_list();
    END_TEST("test_append");

}

void test_list() {
    START_TEST("test_list");
    test_remove();
    test_contains();
    END_TEST("test_list");
}

void test_contains(){
    CardList l1;
    l1.append("card1");
    l1.append("card2");
    l1.append("card3");
    assertEquals(l1.contains(Card("card2")), true, "list contains card2");
    assertEquals(l1.contains(Card("card3")), true, "list contains card3");
}
void test_remove(){
    CardList l1;
    l1.append("card2");
    l1.append("card1");
    l1.remove(Card ("card1"));
    assertEquals(l1.contains(Card("card1")), false, "list does not contain card1");
}

void test_card() {
    START_TEST("test_card");
    test_card_operator_double_equal();
    END_TEST("test_card");
}


void test_append_empty_list() {
    CardList l1;
    l1.append("card1");
    assertEquals(l1.first->card, Card("card1"), "card1");
}

void test_append_single_element_list() {
    // Tests cases should be independent,
    CardList l1;
    l1.append("card1");
    l1.append("card2");
    assertEquals(l1.first->card, Card("card1"), "first card");
    assertEquals(l1.first->next->card, Card("card2"), "second card");
}


void test_card_operator_double_equal() {
    Card card1("somecard");
    Card card2("somecard");
    assertEquals(card1 == card2, true, "cards are equal");
}




