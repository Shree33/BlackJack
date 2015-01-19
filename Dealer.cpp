#include <iostream>
#include "Dealer.h"

using namespace std;

Dealer::Dealer() {
	deck = new Hand[52*4];
	create_superdeck(&deck);
	deck.shuffle();
}

Dealer::~Dealer() {
	delete [] deck;
}

void Dealer::deal_cards(Player player_name) {
	deck.deal_card_from_top(*(player_name.get_player_hand()));
}

void Dealer::give_chips(int winnings, Player player_name) {

}

Card* Dealer::look_at_player_hand(string player_id) {
	
}

void create_superdeck(Hand* deck) {
	for (int i = 0; i < 4; i++) {
		Hand temp_deck;
		temp_deck.create_deck();
		for (int i = 0; i < 52; i++)
			*deck.insert_at_tail(temp_deck[i]);
	}
}

