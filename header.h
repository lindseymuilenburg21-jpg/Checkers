#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>				
#include <io.h>
#include <locale.h>				//Last three help with the Unicode somehow

// wind/air 💨
// rock 🗿
// fire 🔥 
// water 💧 
// wall 🧱 
// avatar 🌈 

//const wchar_t* name_1 = L"jessica"; data type example for strings of unicode
//wprintf(L"%ls") print for unicode characters
//Wscanf(L"") scan for unicode characters


void print_board(const wchar_t* board[8][9]);
void get_two_ints(int* a, int* b);
void set_up(const wchar_t* board[8][9]);
void show_rules(void);
void start_game(void);
void main_menu(void);
void get_peice_cords(int* a, int* b, int player_num, const wchar_t* board[8][9], const wchar_t* board_blank[8][9]);
void move_player1_piece(int* row, int* column, int original_row, int original_column, const wchar_t* board[8][9]);
void move_player2_piece(int* row, int* column, int original_row, int original_column, const wchar_t* board[8][9]);


//Example pointer function

//void get_two_ints(int* a, int* b) {
//	wprintf(L"Enter first number: ");
//	wscanf(L"%d", a);   // no & here, because a is already a pointer
//	wprintf(L"Enter second number: ");
//	wscanf(L"%d", b);
//}

//Example pointer main

	//int x = 0;
	//int y = 0;


	//get_two_ints(&x,&y);
	//
	//wprintf(L"\nYou entered %d and %d\n", x, y);
