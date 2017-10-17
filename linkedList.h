// Raul Martinez
// raul.martinez01@utrgv.edu

#include <iostream>
using namespace std;

template <class T>
class linkedList
{
private:
	class node
	{
	public:
		T data;
		node * next;
		node * prev;

		node(T x)
		{
			data = x;
			next = NULL;
			prev = NULL;
		}
	};

	node * head;
	node * tail;

	int numItems;

	void split(node * &h, node * &t, node *& t1, node *& h2)
	{
		int j = 0;
		node* n = h;

		while (n != t)
		{
			j++;
			n = n->next;
		}

		n = h;

		for (int i = 0; i <= j / 2; i++)
		{
			n = n->next;
		}

		t1 = n->prev;
		h2 = n;

		t1->next = t->next = NULL;
	}

	void merge(node* &h, node*& t1, node*&h2, node*&t)
	{
		node* newH = NULL;
		node* newT = NULL;

		if (h->data < h2->data)
		{
			newH = newT = h;
			h = h->next;
		}

		else
		{
			newT = newH = h2;
			h2 = h2->next;
		}

		while (h != NULL)
		{
			newT->next = h;
			newT->next->prev = newT;
			newT = newT->next;
			h = h->next;
		}

		while (h2 != NULL)
		{
			newT->next = h2;
			newT->next->prev = newT;
			newT = newT->next;
			h2 = h2->next;
		}

		while ((h != NULL) && (h2 != NULL))
		{
			if (h->data < h2->data)
			{
				newT->next = h;
				newT->next->prev = newT;
				newT = newT->next;
				h = h->next;
			}
			else if (h->data > h2->data)
			{
				newT->next = h2;
				newT->next->prev = newT;
				newT = newT->next;
				h2 = h2->next;
			}
		}

		h = newH;
		t = newT;
	}


	//merge sort the list from node h to t
	void mergeSort(node * &h, node * &t)
	{
		if (h != NULL && h != t) //2 or more items, otherwise base case of nothing
		{
			//step 1: split list into 2
			//point t1 and h2 to nodes such that: 
			//the left half of the list is from node h to t1, right half from node h2 to t
			node * t1;
			node * h2;
			split(h, t, t1, h2);

			//step 2: sort 2 halves
			mergeSort(h, t1);
			mergeSort(h2, t);

			//step 3: merge sorted halves back together
			//into a single sorted list
			merge(h, t1, h2, t);
		}
	}

public:
	linkedList()
	{
		head = NULL;
		tail = NULL;
		numItems = 0;
	}

	//frees all dynamically allocated memory (the nodes in the list)
	~linkedList()
	{
		while (!empty())
		{
			pop_front();
		}
	}

	int size()
	{
		return numItems;
	}

	//add item x to back of list
	void push_back(T x)
	{
		numItems++;
		if (head == NULL)
		{
			head = new node(x);
			tail = head;
		}
		else
		{
			tail->next = new node(x);
			tail->next->prev = tail;
			tail = tail->next;
		}
	}

	//remove and return the first item in the list
	T pop_front()
	{
		numItems--;
		T output = head->data;
		if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		}
		return output;
	}

	void display()
	{
		node * c = head;
		while (c != NULL)
		{
			cout << c->data << ",";
			c = c->next;
		}
		cout << endl;
	}

	bool empty()
	{
		return (numItems == 0);
	}

	void mergeSort()
	{
		mergeSort(head,tail);
	}
};