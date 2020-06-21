#pragma once
#define S 5
namespace knihovna {

	//Struktura zásobníku a fronty
	struct List {
		int vertex;
		List* next;
	};
	typedef List TList;

	bool sempty(List* top);
	void push(TList** top, int v);
	int pop(TList** top);
	bool qempty(List* head);
	void enqueue(TList** head, TList** tail, int v);
	int dequeue(TList** head, TList** tail);



	
}