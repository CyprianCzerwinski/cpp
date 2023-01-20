//---------------------------------------//
            //Program rysuj¹cy figurê M znakiem ASCII//
//---------------------------------------//

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <string.h>

//--------------------------------------------------------------------------------------

void idz_do_xy(int x, int y);
int gdzieJestX();
int gdzieJestY();
void myjuMyju();
void ukryj();
void menu();
void wybierz_rozmiar(int &);
void wybierz_znak(char &);
void rysuj(char ,int ,int ,int &);
void zmien_pozycje( int &, int &, int &);

//--------------------------------------------------------------------------------------

using namespace std;

//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
																//----------------------
int main()														//----------------------
{																//----------------------
	char znak;													//----------------------
	int x=0, y=0, bok=15;										//----------------------
																//----------------------
	menu();                                                     //----------------------
    wybierz_rozmiar(bok);										//----------------------
	wybierz_znak(znak);											//----------------------
	rysuj(znak,x,y,bok);										//----------------------
	do {														//----------------------
																//----------------------
		zmien_pozycje(x, y,bok);							    //----------------------
		rysuj(znak, x, y, bok);									//----------------------
		//cout << x << " " << y;								----------------------
	} while (_getch() != 27);									//----------------------
																//----------------------
																//----------------------
}																//----------------------
																//----------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------

void wybierz_znak(char &znak) // Funkcja wybieraj¹ca znak do rysowania
{
	system("cls");
	cout << "Wybierz znak, ktorym chcesz narysowac litere : ";
	cin >> znak;

}

//--------------------------------------------------------------------------------------
void wybierz_rozmiar(int &bok) // Funkcja wybieraj¹ca rozmiar
{
	system("cls");
	cout << "Wybierz rozmiar, ktorym chcesz narysowac litere : ";
	cin >> bok;


}

//--------------------------------------------------------------------------------------



	void rysuj(char znak, int x, int y, int &bok) // Funkcja rysuj¹ca literê
{
    int x1=0, y1=0, counter=0;
    int x2=0, y2=0;


    system("cls");

    idz_do_xy(x, y);

    for(int x1=0; x1<bok; x1++){ // lewo
                cout<<znak;
                for (x2 = 0; x2 <= bok; x2++) {
            if (x2 == bok)
                cout <<znak;
            else if (x2 == counter
                    || x2 == bok - counter - 1)
                cout <<znak;
            else
                cout <<" ";
        }
        if (counter == bok / 2) {
            counter = -99999;
        }
        else
            counter++;
        cout <<"\n";
    }

    }





//---------------------------------------------------------------------------------------

void zmien_pozycje(int &x, int &y,int &bok) // Funkcja zmieniaj¹ca pozycjê litery
{
	ukryj();

		char znak = _getch();
		switch (znak)
		{
            znak = _getch();
			case 72: {y--;
				break; }

			case 80: {y++;
				break; }

			case 75: {x--;
				break; }

			case 77: {x++;
				break; }

            case '-': {bok--;
				break; }

			case '+': {bok++;
				break; }
 		}
 }

//---------------------------------------------------------------------------------------






void idz_do_xy(int x, int y)               //przenosi kursor do okreœlonej pozycji (x, y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//---------------------------------------------------------------------------------------

int gdzieJestX()            //zwraca pozycjê kursora w osi x
{

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}

//--------------------------------------------------------------------------------------

int gdzieJestY()                //zwraca pozycjê kursora w osi y
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}

//--------------------------------------------------------------------------------------

void ukryj()                       //ukrywa kursor konsoli
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}

//--------------------------------------------------------------------------------------

void myjuMyju()     //usowa zawartoœci linii, na której znajduje siê kursor
{
	int x, y;
	x = gdzieJestX();
	y = gdzieJestY();
	idz_do_xy(x, y);
	for (int i = x; i <= 79; i++)
		cout << " ";
	idz_do_xy(x, y);
}

//--------------------------------------------------------------------------------------

void menu() // menu g³ówne
{

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hOut, 0x004);

	idz_do_xy(31, 12);
	cout << "-------------------------------------------------------------" << endl;
	idz_do_xy(31, 13);
	cout << "--- " << "Witaj w programie rysujacym litere M znakiem ASCII!" << " ---" << endl;
	idz_do_xy(31, 14);
	cout << "-------------------------------------------------------------" << endl;
	idz_do_xy(38, 15);
	cout << "Aby kontunuowac, wcisnij dowolny przycisk : ";
	_getch();
}
