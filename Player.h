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
	void hit(); // requests another card from the dealer
	void look_at_player_hand(string player_id); //displays ascii art of a
	                                             //requested player's cards
	bool split_hand(); //specific behavior for double card hands
	void sync_holdings(int winnings); //resets player for new turn, adds winnings
private:
	int chips; // player's "money"
	int bet; // player's bet on a single hand
	Hand *cards[]; // player's cards
	void print_cards(string player_id); // ascii card printer
};
