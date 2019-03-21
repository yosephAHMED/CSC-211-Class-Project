#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
enum input { ENTER, UP, DOWN, LEFT, RIGHT, BACK, NONE };
/// Variables & Constants
bool EXIT_PROGRAM = false; // Exit conditions
int MainMenu_OptionSelected = 1;
bool on_MainMenu = true;
input MainMenu_Input = NONE;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); COORD coordinates; // Console variables
/// Prototypes
void MainMenuDraw(), MainMenuInput(), MainMenuLogic();
void ResetInputVariables(), drawTitle(), hideCursor();
int main() {
	hideCursor();
	system("color F0");
	do {
		MainMenuDraw();
		MainMenuInput();
		MainMenuLogic();
		SetConsoleCursorPosition(console, coordinates);
	} while (!EXIT_PROGRAM);
	return 0;
}
/// Routines
void MainMenuDraw() { // Draws screen
	drawTitle();
	cout << "\n\n";
	cout << "\t\t\t\t1. Calculate! (non functional)";
	if (MainMenu_OptionSelected == 1)
		cout << " <--";
	else
		cout << "    ";
	cout << endl;
	cout << "\t\t\t\t2. Set Information (non functional)";
	if (MainMenu_OptionSelected == 2)
		cout << " <--";
	else
		cout << "    ";
	cout << endl;
	cout << "\t\t\t\t3. Set Variables";
	if (MainMenu_OptionSelected == 3)
		cout << " <--";
	else
		cout << "    ";
	cout << endl;
	cout << "\t\t\t\t4. Exit";
	if (MainMenu_OptionSelected == 4)
		cout << " <--";
	else
		cout << "    ";
	cout << endl;
}
void MainMenuInput() { // Gets inputs and sets related variables
	ResetInputVariables();
	if (_kbhit()) {
		switch (_getch()) {
		case 13: // ENTER
			MainMenu_Input = ENTER;
			break;
		case 'w':
			MainMenu_Input = UP;
			break;
		case 's':
			MainMenu_Input = DOWN;
			break;
		}
	}
}
void MainMenuLogic() { // Applies logic to input and other
	if (on_MainMenu) {
		if (MainMenu_Input == UP)
			MainMenu_OptionSelected--;
		if (MainMenu_Input == DOWN)
			MainMenu_OptionSelected++;
		if (MainMenu_Input == ENTER) {
			if (MainMenu_OptionSelected == 4)
				EXIT_PROGRAM = true;
		}
	}
	if (MainMenu_OptionSelected > 4)
		MainMenu_OptionSelected = 4;
	if (MainMenu_OptionSelected < 1)
		MainMenu_OptionSelected = 1;
}
void ResetInputVariables() {
	MainMenu_Input = NONE;
}
void drawTitle() {
	SetConsoleTextAttribute(console, 249);
	cout << "\n\n";
	cout << "\t\t\t  _     _          __        __         _    " << endl;
	cout << "\t\t\t | |   (_)_ __   __\\ \\      / /__  _ __| | __" << endl;
	cout << "\t\t\t | |   | | '_ \\ / _ \\ \\ /\\ / / _ \\| '__| |/ /" << endl;
	cout << "\t\t\t | |___| | | | |  __/\\ V  V / (_) | |  |   < " << endl;
	cout << "\t\t\t |_____|_|_| |_|\\___| \\_/\\_/ \\___/|_|  |_|\\_\\" << endl;
	SetConsoleTextAttribute(console, 240);
}
/// Functions
void hideCursor() {
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(console, &info);
}