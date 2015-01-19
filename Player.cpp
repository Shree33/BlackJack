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
	player_name = "default";
}

Player::Player(string name)
{
	cards = new Card[INITIAL_CAPACITY];
	chips = 500;
	bet = 0;
	cards_held = 0;
	player_name = name;
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
	// Check if has player has enough and is within bet min/max
	if(amount > MINIMUM_BET && amount < MAXIMUM_BET){

		if(bet < chips){

			chips = chips - amount;
			bet = amount;
		}
	}
}


Card* Player::look_at_player_hand(string player_id){

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

void take_cards(Card given_card){

}