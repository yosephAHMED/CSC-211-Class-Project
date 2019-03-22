#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
enum input { ENTER, UP, DOWN, LEFT, RIGHT, BACK, NONE };
/// Variables & Constants
bool EXIT_PROGRAM = false; // Exit conditions
int MainMenu_OptionSelected = 1;
bool on_MainMenu = true;
input MainMenu_Input = NONE, LAST_MainMenu_Input = NONE;
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
	cout << "\t\t\t\t3. Set Variables (non functional)";
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
	cout << "\n\n\n\n";
	cout << "\t\t            ";
	if (LAST_MainMenu_Input == UP)
		SetConsoleTextAttribute(console, 242);
	cout << "^";
	cout << "        w                                                    " << endl;
	SetConsoleTextAttribute(console, 240);
	cout << "\t\tControls: ";
	if (LAST_MainMenu_Input == LEFT)
		SetConsoleTextAttribute(console, 242);
	cout << "< ";
	SetConsoleTextAttribute(console, 240);
	if (LAST_MainMenu_Input == DOWN)
		SetConsoleTextAttribute(console, 242);
	cout << "v";
	SetConsoleTextAttribute(console, 240);
	cout << " ";
	if (LAST_MainMenu_Input == RIGHT)
		SetConsoleTextAttribute(console, 242);
	cout << ">";
	SetConsoleTextAttribute(console, 240);
	cout << " or ";
	if (LAST_MainMenu_Input == LEFT)
		SetConsoleTextAttribute(console, 242);
	cout << "a ";
	SetConsoleTextAttribute(console, 240);
	if (LAST_MainMenu_Input == DOWN)
		SetConsoleTextAttribute(console, 242);
	cout << "s";
	SetConsoleTextAttribute(console, 240);
	if (LAST_MainMenu_Input == RIGHT)
		SetConsoleTextAttribute(console, 242);
	cout << " d";
	SetConsoleTextAttribute(console, 240);
	cout << " to move\n\t\t";
	if (LAST_MainMenu_Input == BACK)
		SetConsoleTextAttribute(console, 242);
	cout << "Backspace or Escape";
	SetConsoleTextAttribute(console, 240);
	cout << " to go back, and ";
	if (LAST_MainMenu_Input == ENTER)
		SetConsoleTextAttribute(console, 242);
	cout << "Enter." << endl;
	SetConsoleTextAttribute(console, 240);
}
void MainMenuInput() { // Gets inputs and sets related variables
	if (MainMenu_Input != NONE)
		LAST_MainMenu_Input = MainMenu_Input;
	ResetInputVariables();
	if (_kbhit()) {
		switch (_getch()) {
		case 13: // ENTER
			MainMenu_Input = ENTER;
			break;
		case 27: // ESC
		case 8: // Backspace
			MainMenu_Input = BACK;
			break;
		case 'w':
		case 72: // UP ARROW
			MainMenu_Input = UP;
			break;
		case 's':
		case 80: // DOWN ARROW
			MainMenu_Input = DOWN;
			break;
		case 'a':
		case 75: // LEFT ARROW
			MainMenu_Input = LEFT;
			break;
		case 'd':
		case 77: // RIGHT ARROW
			MainMenu_Input = RIGHT;
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