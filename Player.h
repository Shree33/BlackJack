#ifndef __player_h__
#define __player_h__

#include <iostream>
#include "hand.h"

#define MININUM_BET 5
#define MAXIMUM_BET 10*MINIMUM_BET

using namespace std;

class Player {
public:
  	Player(); //constructor
  	~Player(); //destructor
	void bet(int amount); // allows player to bet chips
	Card* look_at_player_hand(string player_id); //displays ascii art of a
	                                             //requested player's cards
	bool split_hand(); //specific behavior for double card hands
	void sync_holdings(int winnings); //resets player for new turn, adds winnings
	void give_card(Card given_card); //
private:
	string player_name;
	int cards_held;
	int chips; // player's "money"
	int bet; // player's bet on a single hand
	Hand *cards[]; // player's cards
	void print_cards(string player_id); // ascii card printer
};


#endif __player_h__