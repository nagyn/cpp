#include "Knihovna.h"
#include <iostream>
#define S 5

using namespace std;

namespace knihovna {


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
	
}