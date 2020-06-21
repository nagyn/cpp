#include "Knihovna.h"
#include <iostream>
#define S 5

using namespace std;

namespace knihovna {



	//Struktura zásobníku a fronty
	
	struct List {
		int vertex;
		List* next;
	};
	typedef List TList;

	//Zjití, jestli je zásobník prázdný
	bool sempty(List* top) {
		return top == NULL;
	}

	//Vložení do zásobníku
	void push(TList **top, int v)
	{
		List* temp = new List();
		temp->vertex = v;
		temp->next = *top;
		*top = temp;
	}


	//Vytažení ze zásobníku
	int pop(TList **top)
	{
		int templ = (*top)->vertex;
		List* temp = *top;
		*top = (*top)->next;
		delete temp;
		return templ;
	}


	//Zjití, jestli je fronta prázdná
	bool qempty(List* head) {
		return head == NULL;
	}


	//Vložení do fronty
	void enqueue(TList **head, TList **tail, int v)
	{
		List* temp = new List();
		temp->vertex = v;
		temp->next = NULL;

		if (qempty(*head))
		{
			*head = temp;
			*tail = temp;
		}
		else
		{
			(*tail)->next = temp;
			(*tail) = temp;
		};
	}



	//Vytažení z fronty
	int dequeue(TList **head, TList **tail)
	{
		int help = (*head)->vertex;
		List* temp = *head;
		*head = (*head)->next;
		if (qempty(*head))
		{
			*tail = NULL;
		}
		delete temp;
		return help;
	}
	
	
	//DFS


	bool findway(TList *top,int graphdfs[S][S], bool dfsvisited[S], int start, int finish) {
		if (start == finish) { return true; }
		for (int i = 0; i < S; i++) {
			dfsvisited[i] = false;
		}

		dfsvisited[start] = true;
		push(&top,start);
		while (!sempty(top)) {
			
			int v = pop(&top);
			
			for (int i = 0; i < S; i++)
			{
				if (graphdfs[v][i] == 1 && !dfsvisited[i]) {
					if (i == finish) { return true; }
					push(&top,i);
					dfsvisited[i] = true;
				}
			}

		}
		return false;
	}

	//BFS

	//graph definition

/*	void bigpart(bool bfsvisited[S], int graphbfs[S][S]) {
		int velikost=0;

		for (int v = 0; v < S; v++) {
			if (!bfsvisited[v]) {
				bfsvisited[v] = true;
				enqueue(v);
		//dodelat		push(v);
			}
		while (!qempty(head)) {

			int v = dequeue();

			for (int i = 0; i < S; i++)
			{
				if (graphbfs[v][i] == 1 && !bfsvisited[i]) {
					enqueue(i);
					bfsvisited[i] = true;
				}
			}
		}
		}


	}

	*/
}