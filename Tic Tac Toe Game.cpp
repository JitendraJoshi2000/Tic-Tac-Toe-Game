//============================================================================
// Name        : TTT.cpp
// Author      : Jitendra Joshi
// Description : Tic Tac Toe Game by C++
//============================================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

class Game
{
	int ch;
	bool flag;
	char chance;
	char a[3][3];
	void input();
public:
	void display();
	void chance_player();
	bool exit();
	Game()
	{
		flag=0;
		chance='X';
		ch=-1;
		for(int i=0;i<3;i++)
		{
			a[0][i]=i+1+48;
		}
		for(int i=0;i<3;i++)
		{
			a[1][i]=i+4+48;
		}
		for(int i=0;i<3;i++)
		{
			a[2][i]=i+7+48;
		}
	}
};

void Game::display()
{
    if(flag)
    system("CLS");
    cout<<"\t\tTic Tack Toe"<<endl<<endl;
	cout<<"Player 1 : X"<<endl;
	cout<<"Player 1 : O"<<endl;
	cout<<endl;
	cout<<"\t\t     |     |     "<<endl;
	cout<<"\t\t  "<<a[0][0]<<"  |  "<<a[0][1]<<"  |  "<<a[0][2]<<endl;
	cout<<"\t\t_____|_____|_____"<<endl;
	cout<<"\t\t     |     |     "<<endl;
	cout<<"\t\t  "<<a[1][0]<<"  |  "<<a[1][1]<<"  |  "<<a[1][2]<<endl;
	cout<<"\t\t_____|_____|_____"<<endl;
	cout<<"\t\t     |     |     "<<endl;
	cout<<"\t\t  "<<a[2][0]<<"  |  "<<a[2][1]<<"  |  "<<a[2][2]<<endl;
	cout<<"\t\t     |     |     "<<endl<<endl;
}

void Game::chance_player()
{
	if(chance=='X')
	{
		cout<<"Player 1 turn (X) : ";
		cin>>ch;
		input();
		if(flag)
		chance='O';
	}
	else
	{
		cout<<"Player 2 turn (O) : ";
		cin>>ch;
		input();
		if(flag)
		chance='X';
	}
}

void Game::input()
{
	int row,column;
	switch(ch)
	{
	case 1:
		row=column=0;
		break;
	case 2:
		row=0;
		column=1;
		break;
	case 3:
		row=0;
		column=2;
		break;
	case 4:
		row=1;
		column=0;
		break;
	case 5:
		row=column=1;
		break;
	case 6:
		row=1;
		column=2;
		break;
	case 7:
		row=2;
		column=0;
		break;
	case 8:
		row=2;
		column=1;
		break;
	case 9:
		row=column=2;
		break;
	default:
	    system("CLS");
		cout<<"\n\tEnter Valid Number..."<<endl<<endl;
		flag=0;
		return;
	}
	if(a[row][column]=='X'||a[row][column]=='O')
	{
	    system("CLS");
		cout<<"\n\tEnter Valid Number..."<<endl<<endl;
		flag=0;
	}
	else
	{
		a[row][column]=chance;
		flag=1;
	}
}

bool Game::exit()
{
	bool p1=0,p2=0,draw=1;
	for(int i=0;i<3;i++)
    {
        if(a[i][0]==a[i][1]&&a[i][0]==a[i][2])
        {
            if(a[i][0]=='X')
            p1=1;
            else p2=1;
        }
    }
    for(int i=0;i<3;i++)
    {
        if(a[0][i]==a[1][i]&&a[0][i]==a[2][i])
        {
            if(a[0][i]=='X')
            p1=1;
            else p2=1;
        }
    }
    if(a[0][0]==a[1][1]&&a[0][0]==a[2][2])
    {
        if(a[0][0]=='X')
        p1=1;
        else p2=1;
    }
    if(a[0][2]==a[1][1]&&a[0][2]==a[2][0])
    {
        if(a[1][1]=='X')
        p1=1;
        else p2=1;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]!='X'&&a[i][j]!='O')
            {
                draw=0;
                break;
            }

        }
        if(!draw)
            break;
    }
    if(p1)
    {
        display();
        cout<<"\n\nPlayer 1 (X) Wins..."<<endl;
        return 1;
    }
    else if(p2)
    {
        display();
        cout<<"\n\nPlayer 2 (O) Wins..."<<endl;
        return 1;
    }
    else if(draw)
    {
        display();
        cout<<"\n\nGame Draw..."<<endl;
        return 1;
    }
    else
        return 0;
}

int main()
{
    char ch;
    do
    {
        system("CLS");
        Game g;
        do
        {
            g.display();
            g.chance_player();
        }while(!g.exit());
        cout<<"\nWould You like to play another game(y/n) : ";
        cin>>ch;
    }while(ch!='n');
    return 0;
}
