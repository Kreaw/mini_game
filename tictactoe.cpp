#include <iostream>
#include <string>
#include <cstddef>
#include <stdexcept>
using namespace std;

void exchangePlayer(char &Player);
int win(char pos[3][3],int n);
void playProcess();
void determineWhetherToWrite(int location_letter,int location_number,char (&pos)[3][3] );
void final_win();

char pos[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
char Player='X';
unsigned step_count = 0;//»ØºÏÊýa1

void exchangePlayer(char &Player)
{
	if(Player=='X')
		Player='O';
	else
		Player='X';
}
int win(char pos[3][3],int n)
{


	if (pos[0][0] == pos[0][1] && pos[0][1] == pos[0][2] && pos[0][0] == 'X') return 1; // X wins
	if (pos[1][0] == pos[1][1] && pos[1][1] == pos[1][2] && pos[1][0] == 'X') return 1; // X wins
	if (pos[2][0] == pos[2][1] && pos[2][1] == pos[2][2] && pos[2][0] == 'X') return 1; // X wins
	if (pos[0][0] == pos[1][0] && pos[1][0] == pos[2][0] && pos[0][0] == 'X') return 1; // X wins
	if (pos[0][1] == pos[1][1] && pos[1][1] == pos[2][1] && pos[0][1] == 'X') return 1; // X wins
	if (pos[0][2] == pos[1][2] && pos[1][2] == pos[2][2] && pos[0][2] == 'X') return 1; // X wins
	if (pos[0][0] == pos[1][1] && pos[1][1] == pos[2][2] && pos[1][1] == 'X') return 1; // X wins
	if (pos[0][2] == pos[1][1] && pos[1][1] == pos[2][0] && pos[1][1] == 'X') return 1; // X wins

	if (pos[0][0] == pos[0][1] && pos[0][1] == pos[0][2] && pos[0][0] == 'O') return 2; // 0 wins
	if (pos[1][0] == pos[1][1] && pos[1][1] == pos[1][2] && pos[1][0] == 'O') return 2; // 0 wins
	if (pos[2][0] == pos[2][1] && pos[2][1] == pos[2][2] && pos[2][0] == 'O') return 2; // 0 wins
	if (pos[0][0] == pos[1][0] && pos[1][0] == pos[2][0] && pos[0][0] == 'O') return 2; // 0 wins
	if (pos[0][1] == pos[1][1] && pos[1][1] == pos[2][1] && pos[0][1] == 'O') return 2; // 0 wins
	if (pos[0][2] == pos[1][2] && pos[1][2] == pos[2][2] && pos[0][2] == 'O') return 2; // 0 wins
	if (pos[0][0] == pos[1][1] && pos[1][1] == pos[2][2] && pos[1][1] == 'O') return 2; // 0 wins
	if (pos[0][2] == pos[1][1] && pos[1][1] == pos[2][0] && pos[1][1] == 'O') return 2; // 0 wins

	if (n == 9) return 3; // end up in a draw
	else return 0; // unfinished
}

void playProcess()
{    
	
	while (win(pos,step_count)==0)
	{
		string location;
		unsigned location_letter = 0; // A/B/C
		unsigned location_number = 0; // 1/2/3

		std::cout << "Player " << Player << ", make your move: ";
		cin >> location; // input the location (e.g. B2)
		std::cout << endl;
		switch (location[0])
		{
		case 'a': case 'A':
			location_letter = 0;
			break;
		case 'b': case 'B':
			location_letter = 1;
			break;
		case 'c': case 'C':
			location_letter = 2;
			break;
		default: // illegal input
			location_letter = 100; // indicate an error
			break;
		}

		switch (location[1])
		{
		case '1':
			location_number = 0;
			break;
		case '2':
			location_number = 1;
			break;
		case '3':
			location_number = 2;
			break;
		default: // illegal input
			location_number = 100; // indicate an error
			break;
		}
		determineWhetherToWrite(location_letter,location_number,pos);

		std::cout << "| |1|2|3|" << endl;
		std::cout << "|A|" << pos[0][0] << "|" << pos[0][1] << "|" << pos[0][2] << "|" << endl;
		std::cout << "|B|" << pos[1][0] << "|" << pos[1][1] << "|" << pos[1][2] << "|" << endl;
		std::cout << "|C|" << pos[2][0] << "|" << pos[2][1] << "|" << pos[2][2] << "|" << endl;

		exchangePlayer(Player); // change the player
		++step_count; // count one more time
		std::cout << endl;
	}

	final_win();

	

}
 
void determineWhetherToWrite(int location_letter,int location_number,char (&pos)[3][3] )
{
	try
	{
		if(location_letter !=100&&location_number!=100&&pos[location_letter][location_number]==' ')
			pos[location_letter][location_number]=Player;
		else throw runtime_error("Illegal input!");
	}
	catch(runtime_error err)
	{
		std::cout << err.what() << "\nTry Again? Rnter Y or N." << endl;
		char decision;
		cin >> decision;
		if (!cin || decision == 'n' || decision == 'N')
			cout<<"Game over";
		else
		{
			playProcess();
			cout << endl;
		}
	}
}

void final_win()
{
	int final_result = win(pos, step_count);
	switch (final_result)
	{
	case 1:
		std::cout << "Congratulations! The winner is X." << endl;
		break;
	case 2:
		std::cout << "Congratulations! The winner is O." << endl;
		break;
	case 3:
		std::cout << "The game ended in a draw." << endl;
		break;
	}

}

int main()
{ 
	std::cout << "This program is a simple tic-tac-toe game.\n";
	std::cout << "| |1|2|3|" << endl;
	std::cout << "|A| | | |" << endl;
	std::cout << "|B| | | |" << endl;
	std::cout << "|C| | | |\n" << endl;  
	playProcess();

}
