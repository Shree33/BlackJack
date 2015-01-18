#include "List_dynamic_array.h"

#include <iostream>
#include <cassert>

using namespace std;

List_dynamic_array::List_dynamic_array()
{
	hand_capacity = INITIAL_CAPACITY;
	cards = new Card[hand_capacity];
	make_empty();
}

List_dynamic_array::~List_dynamic_array()
{
	delete [] cards;
}

// copy constructor
List_dynamic_array::List_dynamic_array(const List_dynamic_array& source) {
	// explicit copy constructor necessary because of cards array
	cards_held = source.cards_held;
	hand_capacity = source.hand_capacity;

	cards = new Card[hand_capacity];
	for (int i=0;i<cards_held;i++) {
		cards[i] = source.cards[i];
	}
}

// operator= overload
List_dynamic_array List_dynamic_array::operator =(const List_dynamic_array&
		source) {
	// explicit operator= overload necessary because of cards array
	Card *new_cards;

	// check for self-assignment -- return without doing anything
	if (this == &source) {
		return *this;
	}

	hand_capacity = source.hand_capacity;
	cards_held = source.cards_held;
	new_cards = new Card[hand_capacity];
	for (int i=0;i<hand_capacity;i++) {
		new_cards[i]=source.cards[i];
	}
	delete [] cards;
	cards = new_cards;
	return *this;
}

void List_dynamic_array::print_list()
{
	for(int i = 0; i < cards_held; i++) {
		cards[i].print_card();
		if (i != cards_held-1) {
			cout << ", "; */
		} else {
			cout << "\n";
		}
	}
}

void List_dynamic_array::print_list_int()
{
	for(int i = 0; i < cards_held; i++) {
		cards[i].print_card_int();
		if (i != cards_held-1) {
			cout << ", ";
		} else {
			cout << "\n";
		}
	}
}

void List_dynamic_array::insert_at_head(Card c)
{
	// check if we need to expand, and expand if necessary
	if (cards_held == hand_capacity)
		expand();
	
	// move all items over one, starting from the last one
	for (int i = cards_held; i >= 0; i--)
		cards[i+1] = cards[i];

	cards[0] = c; //inserts new card
	cards_held++; //increments holdings
}

void List_dynamic_array::insert_at_tail(Card c)
{
	// check if we need to expand, and expand if necessary
	if (cards_held == hand_capacity)
		expand();

	cards[cards_held++] = c; // insert the new card at the end
}

void List_dynamic_array::insert_at_index(Card c,int index)
{
	// if index is greater than cards_held, then fail
	assert(index <= cards_held);

	// check if we need to expand, and expand if necessary
	if (cards_held == hand_capacity)
		expand();
	
	// move all elements past the insertion point up one
	for (int i = index; i < cards_held+1; i++)
		cards[i+1] = cards[i];
	
	cards[index] = c; // insert the card
	cards_held++; //update cards_held
}

void List_dynamic_array::replace_at_index(Card c, int index) {
	assert(index < cards_held);
	cards[index] = c; 	// replace the card at index with c
}

Card List_dynamic_array::card_at(int index)
{
	// if index is out of bounds, fail
	assert (index >= 0 && index < cards_held);
	
	return cards[index];
}

bool List_dynamic_array::has_card(Card c) {
    // loops through the list using same_card
	for (int i = 0; i < cards_held; i++) {
		if (cards[i].same_card(c))
			return true;
	}
	return false;
}

bool List_dynamic_array::remove(Card c)
{
	for (int i = 0; i < cards_held; i++) {
		if (cards[i].same_card(c)) { //looks for the card
			Card temp = remove_from_index(i); //removes if found
			cards_held--;
			return true;
		}
	}
	return false; // false if not found
}

Card List_dynamic_array::remove_from_head()
{
	assert(cards_held > 0);

	Card temp_card = cards[0]; // holds the deleted card
	for (int i = 1; i < cards_held; i++) // moves cards forward in array
		cards[i-1] = cards[i];
	cards_held--;
	
	return temp_card; 
}

Card List_dynamic_array::remove_from_tail()
{
	assert(cards_held > 0);
	return cards[cards_held--]; //decrements cards held; returns former last card

}

Card List_dynamic_array::remove_from_index(int index)
{
	// if the list is empty, fail
	assert(cards_held > 0);
	
	// if loc is outside of bounds, fail
	assert(index >= 0 && index < cards_held);

	Card temp_card = cards[index];
	for (int i = index+1; i < cards_held; i++)
		cards[i-1] = cards[i];
	// similar to remove_from_head(), but
	// we remove the card at index
	return temp_card;
	// Returns the card that was removed
	
}

void List_dynamic_array::expand()
{
	Card* new_list = new Card[hand_capacity*2];

	for (int i = 0; i < hand_capacity; i++) //copy all cards into new array
		new_list[i] = cards[i];
	delete [] cards; 	// delete the old list
	cards = new_list; // set cards variable to point to the new list
	hand_capacity *= 2; // update hand_capacity
}
