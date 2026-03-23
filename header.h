#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>				
#include <io.h>
#include <locale.h>	//Last three help with the Unicode somehow
#include <wchar.h>

// wall 🧱 

//L"♒︎ (water)
//L"⛰️ (earth)
//L"♨ (fire)
//L"☁️ (air)
//L"☯ (avatar)
//L"⌬(wall)" // make sure to have a space after the emjoi


//const wchar_t* name_1 = L"jessica"; data type example for strings of unicode
//wprintf(L"%ls") print for unicode characters
//Wscanf(L"") scan for unicode characters
//wcscmp(board[*a][*b], correct_peice)   returns 0 if their are matching characters, returns 1 if they are different 


void print_board(const wchar_t* board[8][9]);
void get_two_ints(int* a, int* b);
void set_up(const wchar_t* board[8][9]);
void show_rules(void);
void start_game(void);
int main_menu(void);
void get_peice_cords(int* a, int* b, int player_num, const wchar_t* board[8][9], const wchar_t* board_blank[8][9]);
void move_player1_piece(int* row, int* column, int original_row, int original_column, const wchar_t* board[8][9], const wchar_t* blank[8][9]);
void move_player2_piece(int* row, int* column, int original_row, int original_column, const wchar_t* board[8][9], const wchar_t* blank[8][9]);
int do_a_round(int* a, int* b, int* c, int* d, const wchar_t* board[8][9], const wchar_t* board_blank[8][9]);
int check_for_loss(int player_num, const wchar_t* board[8][9]);
void player1_kinged(const wchar_t* board[8][9], int row, int column);
void player2_kinged(const wchar_t* board[8][9], int row, int column);
int get_bender_abilities(void);
int get_kill_info(const wchar_t* board[8][9], const wchar_t* blank[8][9], int* victim_row, int* victim_collumn, int killer_row, int killer_collumn, int* new_row, int* new_collumn);
int alternate_kill(wchar_t* board[8][9], const wchar_t* blank[8][9], int killer_row, int killer_collumn);



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

void activate_ability(int* player, int* row, int* column, const wchar_t* board[8][9], const wchar_t* blank[8][9], const wchar_t* emoji);
 
void kill(int* row, int* column, int* player, const wchar_t* board[8][9], const wchar_t* blank[8][9], const wchar_t* emoji);
