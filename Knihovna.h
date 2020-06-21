#pragma once
#define S 5
namespace knihovna
{
	struct Node
	{
		int value;
		Node *next;
	};
	typedef Node TNode;

	// Stack
	bool sempty(TNode *top);
	void push(TNode **top, int v);
	int pop(TNode **top);

	// Queue
	bool qempty(TNode *head);
	void enqueue(TNode **head, TNode **tail, int v);
	int dequeue(TNode **head, TNode **tail);
} // namespace knihovna
