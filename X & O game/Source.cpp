#include <iostream>
#include <math.h>
using namespace std;

/*create X-O game using C++*/
char Matrix[3][3] = { '1','2','3','4','5','6','7','8','9' };
char player = 'X';

void printMatrix()
{
	system("cls");   //clear screen
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << Matrix[i][j] << "  ";
		}
		cout << endl;
	}
}
void play()
{
	char pos;
	cout << "Choose Your Position - player <" << player << "> : ";
	cin >> pos;
	while (pos < '0' && pos > '10')
	{
		cout << "please enter a number from 1 to 9" << endl;
		cout << "Choose Your Position - player <" << player << "> : ";
		cin >> pos;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Matrix[i][j] == pos)
				Matrix[i][j] = player;
		}
	}
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}
char WhoWin()
{
	int Xcount = 0, Ocount = 0;
	bool isFill = true;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (Matrix[i][j] != 'X' && Matrix[i][j] != 'O')
				isFill = false;
			if (Matrix[i][j] == 'X')
				Xcount++;
			else if (Matrix[i][j] == 'O')
				Ocount++;
			if (Xcount == 3 || Ocount == 3)
				return Xcount > Ocount ? 'X' : 'O';
		}
		Xcount = 0;
		Ocount = 0;
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (Matrix[j][i] == 'X')
				Xcount++;
			else if (Matrix[j][i] == 'O')
				Ocount++;
			if (Xcount == 3 || Ocount == 3)
				return Xcount > Ocount ? 'X' : 'O';
		}
		Xcount = 0;
		Ocount = 0;
	}
	if (Matrix[0][0] == 'X' && Matrix[1][1] == 'X' && Matrix[2][2] == 'X')
		return 'X';
	else if (Matrix[0][0] == 'O' && Matrix[1][1] == 'O' && Matrix[2][2] == 'O')
		return 'O';
	else if (Matrix[0][2] == 'X' && Matrix[1][1] == 'X' && Matrix[2][0] == 'X')
		return 'X';
	else if (Matrix[0][2] == 'O' && Matrix[1][1] == 'O' && Matrix[2][0] == 'O')
		return 'O';
	if (isFill)
		return 'Z';
	return '.'; //mean the game is playing till now
}



int main(void)
{
	while (WhoWin() == '.')
	{
		printMatrix();
		play();
	}
	printMatrix();
	if (WhoWin() == 'Z')
		cout << "no one win" << endl;
	else
		cout << "congratulations : " << WhoWin() << " you win" << endl;
	system("pause");
	return 0;
}