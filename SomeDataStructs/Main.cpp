#include <iostream>
#include <fstream>
#include <vector>
#include "linkedlist_d.h"

using namespace std;

int main()
{

	vector<float> dataArr = {0.2f, 9.2f, -2.3f, 81.3f, 0.4f};

	linkedlist_d<float> *test = new linkedlist_d<float>(dataArr);
	cout << "\nOur linked list: " << test->toString() << endl;
	test->Sort();
	cout << "\nAfter sorting:   " << test->toString() << endl;
	int ind9 = test->getInd(9.2f);
	test->remove(ind9);
	cout << "\nAfter removing 9.2:   " << test->toString() << endl;
	test->insert(ind9 - 1, 8.0f);
	cout << "\nAfter inserting 8.0 in its place:   " << test->toString() << endl;

	while (true)
	{
	}
	return 0;
}