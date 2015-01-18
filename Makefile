#
# Makefile for List_dynamic_array
#
CXX = clang++
FLAGS =  -g -Wall 

blackjack: List_dynamic_array.cpp List_dynamic_array.h \
     	card.h card.cpp hand.h hand.cpp blackjack.cpp \
	Player.h Player.cpp 
	${CXX} ${FLAGS} -o bjgame List_dynamic_array.cpp main.cpp \
	 	hand.cpp card.cpp
clean:
	rm -f bjgame
