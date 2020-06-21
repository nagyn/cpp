#include "Knihovna.h"
#include <iostream>
#define S 5

using namespace std;

namespace knihovna
{
	//Zjit�, jestli je z�sobn�k pr�zdn�
	bool sempty(TNode *top)
	{
		return top == NULL;
	}

	//Vlo�en� do z�sobn�ku
	void push(TNode **top, int v)
	{
		TNode *temp = new TNode();
		temp->value = v;
		temp->next = *top;
		*top = temp;
	}

	//Vyta�en� ze z�sobn�ku
	int pop(TNode **top)
	{
		int templ = (*top)->value;
		TNode *temp = *top;
		*top = (*top)->next;
		delete temp;
		return templ;
	}

	//Zjit�, jestli je fronta pr�zdn�
	bool qempty(TNode *head)
	{
		return head == NULL;
	}

	//Vlo�en� do fronty
	void enqueue(TNode **head, TNode **tail, int v)
	{
		TNode *temp = new TNode();
		temp->value = v;
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
	int dequeue(TNode **head, TNode **tail)
	{
		int help = (*head)->value;
		TNode *temp = *head;
		*head = (*head)->next;
		if (qempty(*head))
		{
			*tail = NULL;
		}
		delete temp;
		return help;
	}
} // namespace knihovna
