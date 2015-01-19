//
//
//
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
	chips = 500;
	bet = 0;
	cards_held = 0;
}

Player::~Player(){
	delete [] cards;
}

void Player::bet(int amount){
	// Check if has player has enough
	chips = chips - amount;
	bet = amount;

}


Card* Player::look_at_player_hand(string player_id){

}

bool Player::split_hand(){
	// possibly create a new player, both players share a chips, and winnings 
	// are transferred back to player one
}

void Player::print_cards(string player_id){

}

void sync_holdings(){

}