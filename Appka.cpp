#include <iostream>
#include <iomanip>
#include "Knihovna.h"
#define S 5
using namespace std;
using namespace knihovna;

int GRAPHS[][S][S] = {{{0, 1, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 1, 0, 1, 0}, {0, 0, 1, 0, 1}, {1, 1, 0, 1, 0}},
					  {{0, 1, 1, 0, 0}, {1, 0, 1, 0, 0}, {1, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}},
					  {{0, 1, 0, 0, 0}, {1, 0, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 1, 0, 1}, {0, 0, 1, 1, 0}}};

void copy_graph(int result[S][S], int graph[S][S])
{
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			result[i][j] = graph[i][j];
}

void print_graph(const char *name, int graph[S][S])
{
	cout << name << ":" << endl;
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			if (graph[i][j])
				cout << " " << i << " -> " << j << endl;
}

int get_choice()
{
	int choice;

	cin >> setw(1) >> choice;

	while (!cin.good())
	{
		cout << "Spatny vstup." << endl;
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

void select_graph(int result[S][S])
{
	print_graph("Graf 1", GRAPHS[0]);
	print_graph("Graf 2", GRAPHS[1]);
	print_graph("Graf 3", GRAPHS[2]);

	cout << "Zvolte graph zadanim cisla." << endl;

	int graph_index = get_choice();
	bool selected = false;

	while (!selected)
	{
		if (graph_index >= 1 && graph_index <= 3)
		{
			cout << "Vybran graph cislo " << graph_index << "." << endl;
			copy_graph(result, GRAPHS[graph_index]);
			selected = true;
		}
		else
		{
			cout << "Co takhle si vybrat z grafu 1-3?" << endl;
			graph_index = get_choice();
		}
	}
}

void perform_algorithm(int algorithm, int graph[S][S])
{
	TList *top = NULL, *head = NULL, *tail = NULL, *merena = NULL, *nejvetsi = NULL;

	bool navstiveno[S];
	for (int i = 0; i < S; ++i)
		navstiveno[i] = false;

	int start = 0, konec = 0;
	bool selected = false;

	while (!selected)
	{
		switch (algorithm)
		{
		case 1:
			cout << "Vybrano najiti komponenty s nejvetsim poctem vrcholu." << endl;
			selected = true;
			//bigpart(graph);
			break;
		case 2:
			cout << "Vybrano zjisteni cesty mezi dvema vrcholy." << endl;
			selected = true;

			cout << "Zadejte vrchol pro zacatek cesty." << endl;
			// vyber vrcholy pres case
			selected = false;
			start = get_choice();
			while (!selected)
			{
				switch (start)
				{
				case 1:
					cout << "Vrchol 1 vybran jako start." << endl;
					selected = true;
					break;
				case 2:
					cout << "Vrchol 2 vybran jako start." << endl;
					selected = true;
					break;
				case 3:
					cout << "Vrchol 3 vybran jako start." << endl;
					selected = true;
					break;
				case 4:
					cout << "Vrchol 4 vybran jako start." << endl;
					selected = true;
					break;
				case 5:
					cout << "Vrchol 5 vybran jako start." << endl;
					selected = true;
					break;

				default:
					cout << "Vrchol s timto cislem neexistuje!" << endl;
					start = get_choice();
					break;
				}
			}
			cout << "Zadejte vrchol pro konec cesty." << endl;
			selected = false;
			konec = get_choice();
			while (!selected)
			{
				switch (konec)
				{
				case 1:
					cout << "Vrchol 1 vybran jako konec." << endl;
					selected = true;
					break;
				case 2:
					cout << "Vrchol 2 vybran jako konec." << endl;
					selected = true;
					break;
				case 3:
					cout << "Vrchol 3 vybran jako konec." << endl;
					selected = true;
					break;
				case 4:
					cout << "Vrchol 4 vybran jako konec." << endl;
					selected = true;
					break;
				case 5:
					cout << "Vrchol 5 vybran jako konec." << endl;
					selected = true;
					break;

				default:
					cout << "Vrchol s timto cislem neexistuje!" << endl;
					konec = get_choice();
					break;
				}
			}
			if (findway(&top, graph, navstiveno, start - 1, konec - 1))
			{
				cout << "Cesta mezi vrcholy " << start << " a " << konec << " existuje.";
			}
			else
			{
				cout << "Cesta mezi vrcholy " << start << " a " << konec << " neexistuje.";
			}
			break;

		default:
			cout << "Moznost s timto cislem neexistuje!" << endl;
			algorithm = get_choice();
			break;
		}
	}
}

int select_algorithm()
{
	cout << "Chcete: 1) najit komponentu s nejvetsim poctem vrcholu, nebo 2) zjistit existenci cesty mezi dvema vrcholy?" << endl;
	return get_choice();
}

int main()
{
	int graph[S][S];
	select_graph(graph);
	int algorithm = select_algorithm();
	perform_algorithm(algorithm, graph);
}
