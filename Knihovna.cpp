#include "Knihovna.h"
#include <iostream>
#define S 5

using namespace std;

namespace knihovna {


	//Zjit�, jestli je z�sobn�k pr�zdn�
	bool sempty(List* top) {
		return top == NULL;
	}

	//Vlo�en� do z�sobn�ku
	void push(TList **top, int v)
	{
		List* temp = new List();
		temp->vertex = v;
		temp->next = *top;
		*top = temp;
	}


	//Vyta�en� ze z�sobn�ku
	int pop(TList **top)
	{
		int templ = (*top)->vertex;
		List* temp = *top;
		*top = (*top)->next;
		delete temp;
		return templ;
	}


	//Zjit�, jestli je fronta pr�zdn�
	bool qempty(List* head) {
		return head == NULL;
	}


	//Vlo�en� do fronty
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



	//Vyta�en� z fronty
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