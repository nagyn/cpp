#include <iostream>
#include <iomanip>
#include "Knihovna.h"
#define S 5
using namespace std;
using namespace knihovna;


//Definovani grafù

int graf1[S][S] = { {0,1,1,0,1}, {1,0,1,0,1}, {1,1,0,1,0}, {0,0,1,0,1}, {1,1,0,1,0} };
int graf2[S][S] = { {0,1,1,0,0}, {1,0,1,0,0}, {1,1,0,1,0}, {0,0,1,0,0}, {0,0,0,0,0} };
int graf3[S][S] = { {0,1,0,0,0}, {1,0,0,0,0}, {0,0,0,1,1}, {0,0,1,0,1}, {0,0,1,1,0} };
int graf[S][S];
bool navstiveno[S];

void graphchosen(int vgraf[S][S]) {
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			graf[i][j] = vgraf[i][j];
		}

	}
}

void printgraf(int graf[S][S]) {
	for (int i = 0; i < S; i++) {
		cout << "Vrchol " << i+1 << ":  ";
		for (int j = 0; j < S; j++) {
			cout << graf[i][j] << " ";
		}
		cout << endl;
	}
}

int getchoice() {
	int choice;

	cin >> setw(1) >> choice;

	while (!cin.good()) {


		cout << "Spatny vstup." << '\n';

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cin >> setw(1) >> choice;
		if (cin.eof()) {
			exit(1);
		}
	}

	cin.clear();
	cin.ignore(INT_MAX, '\n');
	return choice;

}

//DFS


bool findway(TList** top, int graphdfs[S][S], bool dfsvisited[S], int start, int finish) {
	if (start == finish) { return true; }
	for (int i = 0; i < S; i++) {
		dfsvisited[i] = false;
	}

	dfsvisited[start] = true;
	push(top, start);
	while (!sempty(*top)) {

		int v = pop(top);

		for (int i = 0; i < S; i++)
		{
			if (graphdfs[v][i] == 1 && !dfsvisited[i]) {
				if (i == finish) { return true; }
				push(top, i);
				dfsvisited[i] = true;
			}
		}

	}
	return false;
}

void bigpart(TList** head, TList** tail, TList** merena, TList** nejvetsi, bool visited[S], int graph[S][S]) {
	int vel = 0;
	int nvel = 0;

	for (int v = 0; v < S; v++) {
		if (!visited[v]) {
			visited[v] = true;
			enqueue(head,tail,v);
		}
		while (!qempty(*head)) {

			int v = dequeue(head,tail);
			push(merena,v);
			vel++;
			for (int i = 0; i < S; i++)
			{
				if (graph[v][i] == 1 && !visited[i]) {
					enqueue(head,tail,i);
					visited[i] = true;
				}
			}
		}
		if (vel >> nvel) {
			while (!sempty(*nejvetsi)) {
				pop(nejvetsi);
			}
			while (!sempty(*merena))
			{
				push(nejvetsi, pop(merena));
			}
			nvel = vel;
		}

	}
	cout << "Nejvetsi komponenta se sklada z vrcholu: ";

	while (!sempty(*nejvetsi)) {
		cout << pop(nejvetsi)+1 << " ";
	}
}

int main() {
	//Pointer na stack pro algoritmus
	TList* top = NULL;
	TList* head = NULL;
	TList* tail = NULL;
	TList* merena = NULL;
	TList* nejvetsi = NULL;
	int vybranygraf;
	int algoritmus;
	int start;
	int konec;
	cout << " Graf 1:" << endl;
	printgraf(graf1);
	cout << endl;
	cout << " Graf 2:" << endl;
	printgraf(graf2);
	cout << endl;
	cout << " Graf 3:" << endl;
	printgraf(graf3);
	cout << endl;

	cout << "Zvolte graf zadanim cisla." << '\n';


	vybranygraf = getchoice();

	bool vybrano = false;
	while (!vybrano) {
		switch (vybranygraf)
		{
		case 1:
			cout << "Vybran graf cislo 1." << '\n';
			graphchosen(graf1);
			vybrano = true;
			break;
		case 2:
			cout << "Vybran graf cislo 2." << '\n';
			graphchosen(graf2);
			vybrano = true;
			break;
		case 3:
			cout << "Vybran graf cislo 3." << '\n';
			graphchosen(graf3);
			vybrano = true;
			break;
		default:
			cout << "Graf s timto cislem neexistuje!" << '\n';
			vybranygraf = getchoice();
			break;
		}


	}

	cout << "Chcete: 1) najit komponentu s nejvetsim poctem vrcholu, nebo 2) zjistit existenci cesty mezi dvema vrcholy?" << '\n';
	// vyber algoritmus pres case
	vybrano = false;
	algoritmus = getchoice();
	while (!vybrano) {
		switch (algoritmus)
		{
		case 1:
			cout << "Vybrano najiti komponenty s nejvetsim poctem vrcholu." << '\n';

			vybrano = true;
			bigpart(&head,&tail,&merena,&nejvetsi,navstiveno,graf);
			break;
		case 2:
			cout << "Vybrano zjisteni cesty mezi dvema vrcholy." << '\n';
			vybrano = true;

			cout << "Zadejte vrchol pro zacatek cesty." << '\n';
			// vyber vrcholy pres case
			vybrano = false;
			start = getchoice();
			while (!vybrano) {
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
					start = getchoice();
					break;
				}


			}
			cout << "Zadejte vrchol pro konec cesty." << '\n';
			vybrano = false;
			konec = getchoice();
			while (!vybrano) {
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
					konec = getchoice();
					break;
				}


			}
			if (findway(&top, graf, navstiveno, start - 1, konec - 1)) {
				cout << "Cesta mezi vrcholy " << start << " a " << konec << " existuje.";
			}
			else {
				cout << "Cesta mezi vrcholy " << start << " a " << konec << " neexistuje.";
			}
			break;

		default:
			cout << "Moznost s timto cislem neexistuje!" << '\n';
			algoritmus = getchoice();
			break;
		}


	}




}