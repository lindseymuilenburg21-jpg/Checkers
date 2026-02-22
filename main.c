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

	//main_menu();

	show_rules();

	print_board(board);

	set_up(board);

	print_board(board);

	// start of game 

	get_peice_cords(&a, &b, 1, board, board_blank);
	
	print_board(board);




	return 0;
}