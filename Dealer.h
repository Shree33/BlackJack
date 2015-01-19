#ifndef __dealer_h__
#define __dealer_h__

#include "Player.h"
#include <iostream>

class Dealer: public Player
{
public:
	Dealer();
	~Dealer();
	void deal_cards(Card c, Player player_name);
	void give_chips(int winnings, Player player_name);
	Card* look_at_player_hand(string player_id);
private:
	Hand* deck[];
	void create_superdeck(Hand* deck);
};