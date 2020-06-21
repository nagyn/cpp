#include <iostream>
#include <iomanip>
#include "Knihovna.h"
#define S 5
using namespace std;
using namespace knihovna;

int GRAF_1[S][S] = {{0, 1, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 1, 0, 1, 0}, {0, 0, 1, 0, 1}, {1, 1, 0, 1, 0}};
int GRAF_2[S][S] = {{0, 1, 1, 0, 0}, {1, 0, 1, 0, 0}, {1, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}};
int GRAF_3[S][S] = {{0, 1, 0, 0, 0}, {1, 0, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 1, 0, 1}, {0, 0, 1, 1, 0}};

void copy_graph(int result[S][S], int graf[S][S])
{
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			result[i][j] = graf[i][j];
}

void printgraf(const char *name, int graf[S][S])
{
	cout << name << ":" << endl;
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			if (graf[i][j])
				cout << " " << i << " -> " << j << endl;
}

int get_choice()
{
	int choice;

	cin >> setw(1) >> choice;

	while (!cin.good())
	{
		cout << "Spatny vstup." << '\n';
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> setw(1) >> choice;

		if (cin.eof())
			exit(1);
	}

	cin.clear();
	cin.ignore(INT_MAX, '\n');
	return choice;
}

int main()
{
	TList *top = NULL;
	TList *head = NULL;
	TList *tail = NULL;
	TList *merena = NULL;
	TList *nejvetsi = NULL;

	int graf[S][S];
	bool navstiveno[S];

	int vybranygraf;
	int algoritmus;
	int start;
	int konec;

	printgraf("Graf 1", GRAF_1);
	printgraf("Graf 2", GRAF_2);
	printgraf("Graf 3", GRAF_3);

	cout << "Zvolte graf zadanim cisla." << '\n';

	vybranygraf = get_choice();

	bool vybrano = false;
	while (!vybrano)
	{
		switch (vybranygraf)
		{
		case 1:
			cout << "Vybran graf cislo 1." << '\n';
			copy_graph(graf, GRAF_1);
			vybrano = true;
			break;
		case 2:
			cout << "Vybran graf cislo 2." << '\n';
			copy_graph(graf, GRAF_2);
			vybrano = true;
			break;
		case 3:
			cout << "Vybran graf cislo 3." << '\n';
			copy_graph(graf, GRAF_3);
			vybrano = true;
			break;
		default:
			cout << "Graf s timto cislem neexistuje!" << '\n';
			vybranygraf = get_choice();
			break;
		}
	}

	cout << "Chcete: 1) najit komponentu s nejvetsim poctem vrcholu, nebo 2) zjistit existenci cesty mezi dvema vrcholy?" << '\n';

	// vyber algoritmus pres case
	vybrano = false;
	algoritmus = get_choice();
	while (!vybrano)
	{
		switch (algoritmus)
		{
		case 1:
			cout << "Vybrano najiti komponenty s nejvetsim poctem vrcholu." << '\n';
			vybrano = true;
			//bigpart(graf);
			break;
		case 2:
			cout << "Vybrano zjisteni cesty mezi dvema vrcholy." << '\n';
			vybrano = true;

			cout << "Zadejte vrchol pro zacatek cesty." << '\n';
			// vyber vrcholy pres case
			vybrano = false;
			start = get_choice();
			while (!vybrano)
			{
				switch (start)
				{
				case 1:
					cout << "Vrchol 1 vybran jako start." << '\n';
					vybrano = true;
					break;
				case 2:
					cout << "Vrchol 2 vybran jako start." << '\n';
					vybrano = true;
					break;
				case 3:
					cout << "Vrchol 3 vybran jako start." << '\n';
					vybrano = true;
					break;
				case 4:
					cout << "Vrchol 4 vybran jako start." << '\n';
					vybrano = true;
					break;
				case 5:
					cout << "Vrchol 5 vybran jako start." << '\n';
					vybrano = true;
					break;

				default:
					cout << "Vrchol s timto cislem neexistuje!" << '\n';
					start = get_choice();
					break;
				}
			}
			cout << "Zadejte vrchol pro konec cesty." << '\n';
			vybrano = false;
			konec = get_choice();
			while (!vybrano)
			{
				switch (konec)
				{
				case 1:
					cout << "Vrchol 1 vybran jako konec." << '\n';
					vybrano = true;
					break;
				case 2:
					cout << "Vrchol 2 vybran jako konec." << '\n';
					vybrano = true;
					break;
				case 3:
					cout << "Vrchol 3 vybran jako konec." << '\n';
					vybrano = true;
					break;
				case 4:
					cout << "Vrchol 4 vybran jako konec." << '\n';
					vybrano = true;
					break;
				case 5:
					cout << "Vrchol 5 vybran jako konec." << '\n';
					vybrano = true;
					break;

				default:
					cout << "Vrchol s timto cislem neexistuje!" << '\n';
					konec = get_choice();
					break;
				}
			}
			if (findway(&top, graf, navstiveno, start - 1, konec - 1))
			{
				cout << "Cesta mezi vrcholy " << start << " a " << konec << " existuje.";
			}
			else
			{
				cout << "Cesta mezi vrcholy " << start << " a " << konec << " neexistuje.";
			}
			break;

		default:
			cout << "Moznost s timto cislem neexistuje!" << '\n';
			algoritmus = get_choice();
			break;
		}
	}
}
