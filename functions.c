
#include "header.h"

/*
Author: Lindsey Muilenburg
Function: takes in current board array, and prints it, no outputs
*/
void print_board(const wchar_t* board[8][9]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			wprintf(L"%ls", board[i][j]);
		}
	}
	wprintf(L"\n\n\n");
}


/*
Author: Lindsey Muilenburg
Function: takes in cureent board, prints peices to all the starting 
positions of checkers, outputs nothing
*/
void set_up(const wchar_t*board[8][9]) {

	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

for (int j = 0; j < 3; j += 2) {
	for (int i = 0; i < 8; i += 2) {
		board[j][i] = L"⚫";
	}
}
for (int j = 1; j < 3; j += 2) {
	for (int i = 1; i < 8; i += 2) {
		board[j][i] = L"⚫";
	}
}
for (int j = 6; j < 8; j += 2) {
	for (int i = 0; i < 8; i += 2) {
		board[j][i] = L"⚪";
	}
}
for (int j = 5; j < 8; j += 2) {
	for (int i = 1; i < 8; i += 2) {
		board[j][i] = L"⚪";
	}
}
}

/*
Author: Andrew Martinez
Function: Prints rules, no inputs or outputs
*/
void show_rules(void) {
	wprintf(L"\n");
	wprintf(L"Airbender Checkers - Rules:\n");
	wprintf(L"1) Standard checkers movement: pieces move diagonally forward.\n");
	wprintf(L"2) Capture by jumping over opponent pieces. Multiple jumps allowed.\n");
	wprintf(L"3) When a piece reaches the far row it becomes a 'Master' (king) and may move diagonally both directions.\n");
	wprintf(L"4) Win by capturing all opponent pieces.\n");
	wprintf(L"Elemental abilities:\n");
	wprintf(L"- Fire: When a Fire piece captures, it \"explodes\" and also destroys any pieces on adjacent squares (including diagonals).\n");
	wprintf(L"- Air: Air pieces gain extra movement range and may capture along straight (orthogonal) lines, allowing them to take an enemy piece any number of squares away if the path is clear.\n");
	wprintf(L"- Water: When a Water piece captures or uses its ability, it can push an adjacent enemy piece one square away into an empty square.\n");
	wprintf(L"- Earth: Earth pieces create obstacles — squares immediately surrounding an Earth piece become blocked and cannot be entered by other pieces.\n");
	wprintf(L"Avatar: An Avatar piece combines all elemental abilities. To enable the Avatar option a player must have at least one Fire, Air, Water, and Earth piece on the board; once eligible, a chosen piece may transform into the Avatar (rules for transformation and timing are a selectable variant).\n");
	wprintf(L"\nPress ENTER to return: ");
	getchar();
}

/*
Author: Andrew Martinez
Function: Starts the game upon user prompting
*/
void start_game(void) {
	wprintf(L"\n[Game Started]\n");
	wprintf(L"Press ENTER to return: ");
	getchar();
}

/*
Author: Andrew Martinez
Function:
*/
void main_menu(void) {
	int choice;

	while (1) {
		wprintf(L"\n--- Airbender Checkers ---\n");
		wprintf(L"1) Play Game\n");
		wprintf(L"2) Game Rules\n");
		wprintf(L"3) Quit\n");
		wprintf(L"Select: ");
		wscanf(L"%d", &choice);
		getchar();  /* consume newline */

		if (choice == 1) {
			start_game();
		}
		else if (choice == 2) {
			show_rules();
		}
		else if (choice == 3) {
			wprintf(L"Goodbye!\n");
			break;
		}
		else {
			wprintf(L"Invalid choice. Try again.\n");
		}
	}
}


/*
Author: Andrew Martinez
Function:
*/