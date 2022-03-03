#include<iostream>
#include<sstream>
#include<string>

using namespace std;

class TicTacToe
{
	string matrix_1d[9];
	string matrix_2d[3][3];
	
	int row, column;

	string winner = "";

	bool win()
	{
		for(int i=0; i<3; i++)
		{
			// Row
			if(matrix_2d[i][0] == matrix_2d[i][1] and matrix_2d[i][1] == matrix_2d[i][2])
			{
				winner = matrix_2d[i][0];
				return true;
			}

			// Column
			if(matrix_2d[0][i] == matrix_2d[1][i] and matrix_2d[1][i] == matrix_2d[2][i])
			{
				winner = matrix_2d[0][i];
				return true;
			}
		}

		// Diagonal
		if(matrix_2d[0][0] == matrix_2d[1][1] and matrix_2d[1][1] == matrix_2d[2][2])
		{
			winner = matrix_2d[0][0];
			return true;
		}

		// Anti Diagonal
		if(matrix_2d[0][2] == matrix_2d[1][1] and matrix_2d[1][1] == matrix_2d[2][0])
		{
			winner = matrix_2d[0][2];
			return true;
		}

		return false;
	}

	void display()
	{
		for(int i=0; i<9; i++)
		{
			if(i%3==0)
			{
				cout<<endl;
			}
			cout<<"|"<<matrix_1d[i]<<"|";
		}
		cout<<endl<<endl;
	}

	void form_1d_to_2d(int value)
	{
		row = value/3;
		column = value%3;
	}

	void user_interface(int value)
	{
		if(value%2==0)
		{
			cout<<"X move: ";
		}

		else
		{
			cout<<"O move: ";
		}
	}

	void user_interface(int value, int move)
	{
		if(value%2==0)
		{
			matrix_1d[move]="X";
			matrix_2d[row][column]="X";
		}

		else
		{
			matrix_1d[move]="O";
			matrix_2d[row][column]="O";
		}
	}
	
	void set_move(int move, int index)
	{
		move-=1;

		form_1d_to_2d(move);

		user_interface(index, move);
	}

	public:

	TicTacToe()
	{
		for(int i=0; i<9; i++)
		{
			stringstream a;
			a<<i+1;
			matrix_1d[i] = a.str();
			form_1d_to_2d(i);
			matrix_2d[row][column] = a.str();
		}

		cout<<"***\tTic Tac Toe\t***\n";
		cout<<"\nPlay with X and O";
		cout<<"\nInput the board number to move!\n\n";
		cout<<"***\tTic Tac Toe\t***\n";
	}

	void start_game()
	{
		int index = 0;

		while(index<9)
		{
			if(win())
			{
				cout<<winner<<" won!";
				break;
			}

			display();

			int move;

			// User Interface			
			user_interface(index);

			cin>>move;

			// Set Move
			set_move(move, index);
			
			index++;
		}
		
		// Tie
		if(!win())
		{
			cout<<"It's a tie";
		}
	}

};

int main()
{
	TicTacToe t;

	t.start_game();
	
	return 0;
}