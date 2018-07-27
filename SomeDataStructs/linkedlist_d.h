#pragma once

#include <string>
#include <vector>

using namespace std;

template <class G>
struct dLL_node
{

	G data;
	dLL_node<G> *prev;
	dLL_node<G> *next;

	dLL_node<G>();

	dLL_node<G>(G d);

	dLL_node<G>(dLL_node *p, dLL_node *n);

	dLL_node<G>(dLL_node *p, dLL_node *n, G d);
};

template <class G>
dLL_node<G>::dLL_node()
{
	prev = nullptr;
	next = nullptr;
	data = 0.0;
}

template <class G>
dLL_node<G>::dLL_node(G d)
{
	prev = nullptr;
	next = nullptr;
	data = d;
}

template <class G>
dLL_node<G>::dLL_node(dLL_node *p, dLL_node *n)
{
	prev = p;
	next = n;
	data = 0.0;
}

template <class G>
dLL_node<G>::dLL_node(dLL_node *p, dLL_node *n, G d)
{
	prev = p;
	next = n;
	data = d;
}

template <class G>
struct linkedlist_d
{

  protected:
	dLL_node<G> *head;
	int len;

  public:
	linkedlist_d<G>();

	linkedlist_d<G>(int l);

	linkedlist_d<G>(vector<G> Arr);

	string toString();

	G get(int ind);

	void setNode(int ind, G d);

	dLL_node<G> *getnode(int ind);

	int getInd(G data, int start = 0);

	void push(G d);

	void append(G d = 0.0);

	void remove(int ind);

	void insert(int ind, G data);

	dLL_node<G> *lastNode();

	void Sort();

  private:
	/// credit to https://www.geeksforgeeks.org/quicksort-for-linked-list/
	void swap(G *a, G *b);

	dLL_node<G> *partition(dLL_node<G> *l, dLL_node<G> *h);

	/* A recursive implementation of quicksort for linked list */
	void _quickSort(dLL_node<G> *l, dLL_node<G> *h);

	// The main function to sort a linked list. It mainly calls _quickSort()
	void quickSort();
};

template <class G>
linkedlist_d<G>::linkedlist_d()
{
	this->head = new dLL_node<G>();
	this->len = 1;
}

template <class G>
linkedlist_d<G>::linkedlist_d(int l)
{
	this->head = new dLL_node<G>();
	this->len = 1;
	for (int i = 0; i < l; i++)
	{
		this->append();
	}
}

template <class G>
linkedlist_d<G>::linkedlist_d(vector<G> Arr)
{
	this->head = new dLL_node<G>(Arr[0]);
	this->len = 1;
	for (int i = 0; i < (int)Arr.size() - 1; i++)
	{
		this->append(Arr[i + 1]);
	}
}

template <class G>
string linkedlist_d<G>::toString()
{
	string s = "{";
	dLL_node<G> *currnode = head;
	for (int i = 0; i < this->len; i++)
	{
		s += "[";
		s += std::to_string(currnode->data);
		s += "]";
		if (currnode->next != nullptr)
		{
			s += " -> ";
			currnode = currnode->next;
		}
	}
	s += "}";
	return s;
}

template <class G>
G linkedlist_d<G>::get(int ind)
{
	dLL_node<G> currnode = *head;
	for (int i = 0; i < ind; i++)
	{
		currnode = *currnode.next;
	}
	return currnode.data;
}

template <class G>
void linkedlist_d<G>::setNode(int ind, G d)
{
	dLL_node<G> *currnode = head;
	for (int i = 0; i < ind; i++)
	{
		currnode = currnode->next;
	}
	currnode->data = d;
}

template <class G>
dLL_node<G> *linkedlist_d<G>::getnode(int ind)
{
	dLL_node<T> *currnode = head;
	for (int i = 0; i < ind; i++)
	{
		currnode = currnode->next;
	}
	return currnode;
}

template <class G>
int linkedlist_d<G>::getInd(G d, int start)
{
	dLL_node<G> *currnode = head;
	for (int i = 0; i < start; i++)
	{
		currnode = currnode->next;
	}
	int c = start;
	while (currnode->data != d && currnode->next != nullptr)
	{
		currnode = currnode->next;
		c += 1;
	}
	return c;
}

template <class G>
void linkedlist_d<G>::push(G d)
{
	dLL_node<G> *newNode = new dLL_node<G>(head, head->next, d);
	head->next->prev = newNode;
	head->next = newNode;
}

template <class G>
void linkedlist_d<G>::append(G d)
{
	dLL_node<G> *currnode = head;
	while (currnode->next != nullptr)
	{
		currnode = currnode->next;
	}
	dLL_node<G> *newNode = new dLL_node<G>();
	newNode->next = nullptr;
	newNode->prev = currnode;
	newNode->data = d;
	currnode->next = newNode;
	len++;
}

template <class G>
void linkedlist_d<G>::remove(int ind)
{
	dLL_node<G> *currnode = head;
	for (int i = 0; i < ind; i++)
	{
		currnode = currnode->next;
	}
	currnode->prev->next = currnode->next;
	currnode->next->prev = currnode->prev;
	free(currnode);
	len--;
}

template <class G>
void linkedlist_d<G>::insert(int ind, G data)
{
	dLL_node<G> *currnode = head;
	for (int i = 0; i < ind; i++)
	{
		currnode = currnode->next;
	}
	dLL_node<G> *newNode = new dLL_node<G>(currnode, currnode->next, data);
	if (currnode->next != nullptr)
		currnode->next->prev = newNode;
	currnode->next = newNode;
	len++;
}

template <class G>
dLL_node<G> *linkedlist_d<G>::lastNode()
{
	dLL_node<G> *currnode = head;
	while (currnode->next != nullptr)
	{
		currnode = currnode->next;
	}
	return currnode;
}

template <class G>
void linkedlist_d<G>::Sort()
{
	this->quickSort();
}

/// credit to https://www.geeksforgeeks.org/quicksort-for-linked-list/:
template <class G>
void linkedlist_d<G>::swap(G *a, G *b)
{
	G t = *a;
	*a = *b;
	*b = t;
}

template <class G>
dLL_node<G> *linkedlist_d<G>::partition(dLL_node<G> *l, dLL_node<G> *h)
{
	// set pivot as h element
	G x = h->data;

	// similar to i = l-1 for array implementation
	dLL_node<G> *i = l->prev;

	// Similar to "for (int j = l; j <= h- 1; j++)"
	for (dLL_node<G> *j = l; j != h; j = j->next)
	{
		if (j->data <= x)
		{
			// Similar to i++ for array
			i = (i == NULL) ? l : i->next;

			this->swap(&(i->data), &(j->data));
		}
	}
	i = (i == NULL) ? l : i->next; // Similar to i++
	this->swap(&(i->data), &(h->data));
	return i;
}

/* A recursive implementation of quicksort for linked list */
template <class G>
void linkedlist_d<G>::_quickSort(dLL_node<G> *l, dLL_node<G> *h)
{
	if (h != NULL && l != h && l != h->next)
	{
		struct dLL_node<G> *p = this->partition(l, h);
		this->_quickSort(l, p->prev);
		this->_quickSort(p->next, h);
	}
}

// The main function to sort a linked list. It mainly calls _quickSort()
template <class G>
void linkedlist_d<G>::quickSort()
{
	// Find last node
	struct dLL_node<G> *h = this->lastNode();

	// Call the recursive QuickSort
	this->_quickSort(head, h);
}
