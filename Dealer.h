#ifndef __dealer_h__
#define __dealer_h__

#include "Player.h"
#include <iostream>

class Dealer: public Player
{
public:
	void deal_cards(Card c, Player player_name);
	void give_chips(int winnings, Player player_name);
	
private:
	Hand* deck[];
};