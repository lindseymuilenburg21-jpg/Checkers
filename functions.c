
#include "header.h"

/*
Author: Lindsey Muilenburg
Function: takes in current board array, and prints it, no outputs
*/
void print_board(const wchar_t* board[8][9]) {
	wprintf(L"Player 2\n");
	wprintf(L"  0 1 2 3 4 5 6 7\n");
	for (int i = 0; i < 8; i++) {
		wprintf(L"%d ", i);
		for (int j = 0; j < 9; j++) {
			wprintf(L"%ls", board[i][j]);
		}
	}
	wprintf(L"Player 1");
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

void get_peice_cords(int*a, int*b, int player_num, const wchar_t* board[8][9], const wchar_t* board_blank[8][9]) {

	do  {
		wprintf(L"Player %d, it's your turn!\nWhich peice would you like to move? \nEnter: row (space) collumn\n", player_num);
		wscanf(L" %d %d", a, b);
		if (*a >= 0 && *b >= 0 && *a <= 7 && *b <= 7) {
			break;
		}
		wprintf(L"Sorry! Thats not a vaild placment, try again\n");
	} while (!(*a >= 0 && *b >= 0 && *a <= 7 && *b <= 7));
	board[*a][*b] = board_blank[*a][*b];
}

/*
Author: Lindsey Muilenburg
Function: Does one round of player 1 and player 2 movment
*/

int do_a_round(int *a, int *b, int*c, int*d, const wchar_t* board[8][9], const wchar_t* board_blank[8][9]) {
	int player_num = 1;

	if (check_for_loss(player_num, board) == 0) {
		return 0;
	}

	get_peice_cords(&a, &b, player_num, board, board_blank);

	move_player1_piece(&c, &d, a, b, board);

	print_board(board);

	player_num = 2;

	if (check_for_loss(player_num, board) == 0) {
		return 0;
	}

	get_peice_cords(&a, &b, player_num, board, board_blank);

	move_player2_piece(&c, &d, a, b, board);

	print_board(board);

	return 1;
}


int check_for_loss(int player_num, const wchar_t* board[8][9]) {
	int peices_left = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {

				if (player_num == 1) {
					if (board[i][j] == L"⚪") {
						peices_left = 1;
					}
				}
				if (player_num == 2) {
					if (board[i][j] == L"⚫"){
						peices_left = 1;
					}
				}

			}
		}
		if (peices_left == 0) {
			wprintf(L"\nGAME OVER\n");
		}
		return peices_left;
}



// Author : Patrick Tolentino
// Function : Gets the bender ability after kinging a piece

int get_bender_abilities(int kinged_piece)
{
	int option = 0;
	int result = 0;


	wprintf(L"Your powered! Pick your bending ability: \n");
	wprintf(L"----------------------------------------\n");
	wprintf(L"1. Water\n");
	wprintf(L"2. Earth\n");
	wprintf(L"3. Fire\n");
	wprintf(L"4. Air\n");
	wprintf(L"----------------------------------------\n");

	do
	{
		wprintf(L"What will you choose? (Pick 1-4): ");

		result = wscanf(L" %d", &option);

		if (result != 1)
		{
			wprintf(L"Invalid input type! Please enter numbers only!\n");

			while (getchar() != '\n');
		}

		else if (option < 1 || option > 4)
		{
			wprintf(L"Invalid option, try again!\n");
		}
	} while (option < 1 || option > 4);

	if (option == 1)
	{
		wprintf(L"Your piece is now a Water bender!\n");
	}

	else if (option == 2)
	{
		wprintf(L"Your piece is now an Earth bender!\n");
	}

	else if (option == 3)
	{
		wprintf(L"Your piece is now a Fire bender!\n");
	}

	else if (option == 4)
	{
		wprintf(L"Your piece is now an Air bender!\n");
	}

	return option;

}

// Author : Patrick
// Function : Moves a normal white piece (Player 1)

void move_player1_piece(int* row, int* column, int original_row, int original_column, const wchar_t* board[8][9])
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	do
	{
		wprintf(L"Where would you like to move this piece (Enter row then column from values 0-7): ");
		wscanf(L" %d %d", row, column);


		if (*row < 0 || *row > 7 || *column < 0 || *column > 7)
		{
			wprintf(L"Not a spot on the board, try again!\n");
		}

		if ((*row == (original_row - 1) && *column == (original_column - 1)) || (*row == (original_row - 1) && *column == (original_column + 1)))
		{
			break;
		}
		else
		{
			wprintf(L"Not a valid move for this piece! Try again!\n");
		}
	} while (!((*row == (original_row - 1) && *column == (original_column - 1)) || (*row == (original_row - 1) && *column == (original_column + 1))));

	board[*row][*column] = L"⚪";
}

// Author : Patrick
// Function : Moves a normal black piece (Player 2)

void move_player2_piece(int* row, int* column, int original_row, int original_column, const wchar_t* board[8][9])
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	do
	{
		wprintf(L"Where would you like to move this piece (Enter row then column from values 0-7): ");
		wscanf(L" %d %d", row, column);


		if (*row < 0 || *row > 7 || *column < 0 || *column > 7)
		{
			wprintf(L"Not a spot on the board, try again!\n");
		}

		if ((*row == (original_row + 1) && *column == (original_column - 1)) || (*row == (original_row + 1) && *column == (original_column + 1)))
		{
			break;
		}
		else
		{
			wprintf(L"Not a valid move for this piece! Try again!\n");
		}
	} while (!((*row == (original_row + 1) && *column == (original_column - 1)) || (*row == (original_row + 1) && *column == (original_column + 1))));
	board[*row][*column] = L"⚫";
}

// Name : P & A
// Function : Shows rules

void show_rules(void)
{
	wprintf(L"\n");
	wprintf(L"Airbender Checkers - Rules:\n");
	wprintf(L"1) Standard checkers movement: pieces move diagonally forward.\n");
	wprintf(L"2) Capture by jumping over opponent pieces. Multiple jumps allowed.\n");
	wprintf(L"3) When a piece reaches the far row it becomes a 'Master' (king) and may move diagonally both directions.\n");
	wprintf(L"4) Win by capturing all opponent pieces.\n");
	wprintf(L"\n");
	wprintf(L"--------------------\n");
	wprintf(L"Elemental abilities:\n");
	wprintf(L"\n");
	wprintf(L"Fire: When a Fire piece captures, it \"explodes\" and also destroys any pieces on adjacent squares (including diagonals).\n");
	wprintf(L"\n");
	wprintf(L"Air: Air pieces gain extra movement range and may capture along straight (orthogonal) lines, allowing them to take an enemy piece any number of squares away if the path is clear.\n");
	wprintf(L"\n");
	wprintf(L"Water: When a Water piece captures or uses its ability, it can push an adjacent enemy piece one square away into an empty square.\n");
	wprintf(L"\n");
	wprintf(L"Earth: Earth pieces create obstacles — squares immediately surrounding an Earth piece become blocked and cannot be entered by other pieces.\n");
	wprintf(L"\n");
	wprintf(L"Avatar: An Avatar piece combines all elemental abilities. To enable the Avatar option a player must have at least one Fire, Air, Water, and Earth piece on the board; once eligible, a chosen piece may transform into the Avatar (rules for transformation and timing are a selectable variant).\n");
	wprintf(L"\n");
	wprintf(L"\nPress ENTER to return: ");
	getwchar();
}

// Name : P & A
// Function : starts game

void start_game(void) {
	wprintf(L"\n[Game Started]\n");
	wprintf(L"Press ENTER to return: ");
	getwchar();
}

// Name : P & A
// Function : Prompts main menu and choices

int main_menu(void)
{
	int choice = 0;

	while (1) {
		wprintf(L"\n--- Airbender Checkers ---\n");
		wprintf(L"1) Play Game\n");
		wprintf(L"2) Game Rules\n");
		wprintf(L"3) Quit\n");
		wprintf(L"Select: ");
		wscanf(L" %d", &choice);
		getwchar();  /* consume newline */

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

	return 0;
}

