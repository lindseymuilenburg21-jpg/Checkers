/*
Authors: Lindsey Muilenburg, Patrick Tolentino, Lyd Thompson, 
Partial credit to Andrew Martinez who helped write the main menu functions
Date: 2/21/2026 from 11 pm to 4 am 2/22/2026
Last Updated: 2/23/2026
Description:	Hackathon prompt - Reinventing the Wheel, taking somthing that's been 
				done a million times and putting a twist on it.
				This project lets 2 players play a normal game of checkers, useing a 8x8 
				coordinate grid for user inputs. When peices are kinged however, they gain 
				additional abilities modeled after the elemental powers of the benders 
				in Avatar the last Airbender.
				All of the imagery in this code is enabled by the inclusion of Unicode 
				Characters and various emjois representing the different tiles and player peices
				*/

#include "header.h"

int main(void) {
	
	setlocale(LC_ALL, "");
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	

	const wchar_t* board_blank[8][9] = {
	{L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"\n" },
	{L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛",L"\n"},
	{L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"\n" },
	{L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛",L"\n"},
	{L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"\n" },
	{L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛",L"\n"},
	{L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"\n" },
	{L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛",L"\n"},
	};
	const wchar_t* board[8][9] = {
	{L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"\n" },
	{L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛",L"\n"},
	{L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"\n" },
	{L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛",L"\n"},
	{L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"\n" },
	{L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛",L"\n"},
	{L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"\n" },
	{L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛", L"⬜", L"⬛",L"\n"},
	};

	int a = 0, b = 0;	//coords of peice wanting to be moved, row and collumn
	int c = 0, d = 0;	//coords of new place peice is moving to, row and collumn
	int running = 1;	//tells game to keep playing

	running = main_menu();

	if (running == 1) {
	
		print_board(board);

		set_up(board);

		print_board(board);

		// start of game 
		do {
			running = do_a_round(&a, &b, &c, &d, board, board_blank);
		} while (running);
	
	}
	
	return 0;
}