#include <iostream>
#include <iomanip>
#include "Knihovna.h"
#define S 5
using namespace std;
using namespace knihovna;

// ---------- Constants --------------------------------------------------

int GRAPHS[][S][S] = {{{0, 1, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 1, 0, 1, 0}, {0, 0, 1, 0, 1}, {1, 1, 0, 1, 0}},
					  {{0, 1, 1, 0, 0}, {1, 0, 1, 0, 0}, {1, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}},
					  {{0, 1, 0, 0, 0}, {1, 0, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 1, 0, 1}, {0, 0, 1, 1, 0}}};

// ---------- Algorithms --------------------------------------------------

bool check_path_existence(int graph[S][S], int start, int finish)
{
	TNode *top = NULL;

	bool visited[S];
	for (int i = 0; i < S; ++i)
		visited[i] = false;

	if (start == finish)
	{
		return true;
	}
	for (int i = 0; i < S; i++)
	{
		visited[i] = false;
	}

	visited[start] = true;
	push(&top, start);
	while (!sempty(top))
	{
		int v = pop(&top);
		for (int i = 0; i < S; i++)
		{
			if (graph[v][i] == 1 && !visited[i])
			{
				if (i == finish)
				{
					return true;
				}
				push(&top, i);
				visited[i] = true;
			}
		}
	}
	return false;
}

void find_biggest_partition(int graph[S][S], int *return_size, int *return_vertex)
{
	TNode *head = NULL, *tail = NULL;
	int max_vertex = 0, max_size = 0;

	bool visited[S];
	for (int i = 0; i < S; ++i)
		visited[i] = false;

	/*
			1. pro kazdy vrchol
			2. pokud jsem v nem jeste nebyl, oznac, ze uz jo a dej na konec fronty
			3. pokud neni fronta prazdna
			4. vytahni si index vrcholu z fronty
			5. pro kazdeho nenavstiveneho souseda inkrementuj velikost
			6. pokud velikost >= max_velikost tak uloz max velikost a max_vrchol
		*/

	for (int v = 0; v < S; v++)
	{
		int size = 1;

		if (!visited[v])
		{
			visited[v] = true;
			enqueue(&head, &tail, v);
		}

		while (!qempty(head))
		{
			int v = dequeue(&head, &tail);

			for (int i = 0; i < S; i++)
			{
				if (graph[v][i] == 1 && !visited[i])
				{
					enqueue(&head, &tail, i);
					visited[i] = true;
					size += 1;
				}
			}
		}

		if (size > max_size)
		{
			max_size = size;
			max_vertex = v;
		}
	}

	*return_size = max_size;
	*return_vertex = max_vertex;
}

// ---------- Utility methods --------------------------------------------------

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
	{
		for (int j = 0; j < S; j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}
}

void print_component(int graph[S][S], int vertex)
{
	bool visited[S];
	for (int i = 0; i < S; ++i)
		visited[i] = false;

	TNode *head = NULL, *tail = NULL;
	enqueue(&head, &tail, vertex);
	visited[vertex] = true;

	while (!qempty(head))
	{
		int v = dequeue(&head, &tail);

		for (int i = 0; i < S; i++)
		{
			if (graph[v][i] == 1 && !visited[i])
			{
				cout << " " << v << " -> " << i << endl;
				visited[i] = true;
				enqueue(&head, &tail, i);
			}
		}
	}
}

void pretty_print_graph(const char *name, int graph[S][S])
{
	cout << name << ":" << endl;
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			if (graph[i][j])
				cout << " " << i << " -> " << j << endl;
}

int read_int()
{
	int choice;

	cin >> setw(1) >> choice;

	while (!cin.good())
	{

		if (cin.eof())
		{
			cout << "Konec vstupu." << endl;
			exit(1);
		}
		else
		{
			cout << "Spatny vstup." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> setw(1) >> choice;
		}
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

	int graph_index = read_int();
	bool selected = false;

	while (!selected)
	{
		if (graph_index >= 1 && graph_index <= 3)
		{
			cout << "Vybran graph cislo " << graph_index << "." << endl;
			copy_graph(result, GRAPHS[graph_index - 1]);
			selected = true;
		}
		else
		{
			cout << "Co takhle si vybrat z grafu 1-3?" << endl;
			graph_index = read_int();
		}
	}
}

void execute_find_biggest_partition(int graph[S][S])
{
	cout << "Vybrano najiti komponenty s nejvetsim poctem vrcholu." << endl;
	int max_size = 0, max_vertex = 0;
	find_biggest_partition(graph, &max_size, &max_vertex);

	cout << "Nejvetsi komponenta ma velikost " << max_size << "." << endl;
	print_component(graph, max_vertex);
}

int read_vertex_index()
{
	cout << "Zadejte vrchol pro zacatek cesty." << endl;
	while (true)
	{
		int vertex_index = read_int();
		if (vertex_index >= 0 && vertex_index <= S)
		{
			cout << "Vrchol " << vertex_index << " vybran jako start." << endl;
			return vertex_index;
		}
		else
		{
			cout << "Vrchol s timto cislem neexistuje!" << endl;
		}
	}
}

void execute_check_path_existence(int graph[S][S])
{
	cout << "Vybrano zjisteni cesty mezi dvema vrcholy." << endl;

	int from = read_vertex_index();
	int to = read_vertex_index();

	if (check_path_existence(graph, from - 1, to - 1))
	{
		cout << "Cesta mezi vrcholy " << from << " a " << to << " existuje." << endl;
	}
	else
	{
		cout << "Cesta mezi vrcholy " << from << " a " << to << " neexistuje." << endl;
	}
}

int select_algorithm()
{
	cout << "Chcete: 1) najit komponentu s nejvetsim poctem vrcholu, nebo 2) zjistit existenci cesty mezi dvema vrcholy?" << endl;

	while (true)
	{
		int choosen = read_int();
		if (choosen >= 1 && choosen <= 2)
			return choosen;
		else
		{
			cout << "Moznost s timto cislem neexistuje!" << endl;
		}
	}
}

// ---------- Let the magic begin --------------------------------------------------

int main()
{
	int graph[S][S];
	select_graph(graph);

	switch (select_algorithm())
	{
	case 1:
		execute_find_biggest_partition(graph);
		break;
	case 2:
		execute_check_path_existence(graph);
		break;
	}
}
