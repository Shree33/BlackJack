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

Player::Player()
{
	chips = 500;
	bet = 0;
}

Player::~Player(){
	// intentionally left blank
}

void Player::bet(int amount){
	// Check if has player has enough
	chips = chips - amount;
	bet = amount;

}


void Player::look_at_player_hand(string player_id){

}

bool Player::split_hand(){

}

void Player::print_cards(string player_id){

}
