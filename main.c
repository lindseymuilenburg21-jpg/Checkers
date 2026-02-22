/*
Author: Lindsey Muilenburg



*/

#include "header.h"

int main(void) {

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

	int a = 0, b = 0; //coords of peice wanting to be moved, row and collumn
	int c = 0, d = 0; //coords of new place peice is moving to, row and collumn

	//main_menu();

	print_board(board);

	set_up(board);

	print_board(board);

	// start of game 
	int running = 1;
	do {
		running = do_a_round(&a, &b, &c, &d, board, board_blank);
		wprintf(L"%d", running);
	} while (running);
	

	



	return 0;
}