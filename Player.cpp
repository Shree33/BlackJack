//
//
//
//
//


#include <iostream>
#include "player.h"

using namespace std;

Player::Player()
{
	cards = new Card[INITIAL_CAPACITY];
	chips = 500;
	bet = 0;
	cards_held = 0;
}

Player::~Player(){
	delete [] cards;
}

void Player::bet(int amount){
	// Check if has player has enough
	chips -= amount;
	bet = amount;
}


Card* Player::look_at_player_hand(string player_id) {
	return &cards;
}

bool Player::split_hand(){
	// possibly create a new player, both players share a chips, and winnings 
	// are transferred back to player one
}

void Player::print_cards(string player_id){
	//print ascii art of cards to player; call look at player hand, convert
	//that into appropriate art
}

void sync_holdings(int winnings){
	bet += winnings;
	chips += bet; //bet+winnings added to holdings
}