#include <iostream>
#include<string>
#include "Tree.hpp"
using namespace std;
using namespace ariel;

Tree::Tree()
{
	head = NULL;
	TreeSize = 0;
}

void recursive_Delete_TRee(TNode* head) {
	
	TNode* current = head;
	if(current != NULL)
	{
		if (current->getleft() != NULL)
			recursive_Delete_TRee(current->getleft());
		if (current->getright() != NULL)
			recursive_Delete_TRee(current->getright());
		delete current;
	}
}


Tree::~Tree()
{
	recursive_Delete_TRee(head);
}

void Tree::setHead(TNode* t) {
	head = t;
}

TNode* Tree::gethead() {
	return head;
}

void Tree::insert(int i) {

	cout << "function insert was called on " << i << " " << endl;
	if (contains(i))
	{
		throw string(to_string(i) + " is allready in the tree!");
		return;
	}
	TreeSize++;
	TNode* temp = new TNode(i);

	if (head == NULL) {

		head = temp;
	}

	else {
		TNode* current = head;
		bool exit = false;
		while (!exit) {
			if (i < current->getdata()) {
				if (current->getleft() == NULL) {
					current->setleft(temp);
					temp->setfather(current);
					exit = true;
				}

				else {
					current = current->getleft();
				}
			}
			else {
				if (current->getright() == NULL) {
					current->setright(temp);
					temp->setfather(current);
					exit = true;
				}
				else {
					current = current->getright();
				}
			}
		}

	}

}

bool Tree::contains(int i) {
	cout << "function contains was called on " << i << " " << endl;
	TNode* current = head;
	while (current != NULL) {
		if (current->getdata() == i) {
			return true;
		}
		else if (i < current->getdata()) {
			current = current->getleft();
		}
		else {
			current = current->getright();
		}
	}
	return false;
}


TNode* Tree::search(int i) {
	cout << "function search was called on " << i << " " << endl;
	TNode* current = head;
	while (current != NULL) {
		if (current->getdata() == i) {
			return current;
		}
		else if (i < current->getdata()) {
			current = current->getleft();
		}
		else {
			current = current->getright();
		}
	}
	return NULL;

}



void Tree::remove(int i) {

	cout << "function remove was called on " << i << " " << endl;

	if (!contains(i))
	{
		throw string(to_string(i) + " is not in the tree!");
		return;
		//return 2147483647;
	}
	TreeSize--;
	TNode* current = head;
	while (current->getdata() != i)
	{
		if (i < current->getdata())
			current = current->getleft();
		else {
			current = current->getright();
		}

	}


	TNode* father = current->getfather();

	//case 1:leaf

	if (current->getleft() == NULL && current->getright() == NULL) {
		if (father == NULL) {

			head = NULL;

		}

		else if (i < father->getdata()) {
			father->setleft(NULL);

		}
		else {
			father->setright(NULL);

		}

	}
	//case 2:current has only child
	else if (current->getleft() == NULL) {
		if (father == NULL) {
			head = current->getright();
			head->setfather(NULL);
		}
		else if (i < father->getdata()) {
			father->setleft(current->getright());
			current->getright()->setfather(father);
		}
		else {
			father->setright(current->getright());
			current->getright()->setfather(father);
		}
	}
	else if (current->getright() == NULL) {
		if (father == NULL) {
			head = current->getleft();
			head->setfather(NULL);

		}
		else if (i < father->getdata()) {
			father->setleft(current->getleft());
			current->getleft()->setfather(father);
		}
		else {
			father->setright(current->getleft());
			current->getleft()->setfather(father);
		}
	}

	// case 3: two children
	else
	{
		TNode* replace = current->getright();
		while (replace->getleft() != NULL)
			replace = replace->getleft();
                int number=replace->getdata();
		remove(replace->getdata());
		current->setdata(number);
                //return i;
		return;
	}
	delete current;
	//return i;
}

int Tree::size() {
	cout << "function size was called" << endl;
	return TreeSize;
}

int Tree::root() {
	cout << "function root was called" << endl;
	if (head == NULL)
	{
		throw string("root is null!");
	}
	return head->getdata();
}

int Tree::parent(int i) {
	cout << "function parent was called on " << i << " " << endl;
	TNode* temp = search(i);
	if (temp == NULL)
		throw string(to_string(i) + " is not in the tree");
	if (temp->getfather() == NULL)
		throw string(to_string(i) + " does not have a parent");
	return temp->getfather()->getdata();
}

int Tree::left(int i) {
	cout << "function left was called on " << i << " " << endl;
	TNode* temp = search(i);
	if (temp == NULL)
		throw string(to_string(i) + " is not in the tree");
	if (temp->getleft() == NULL)
		throw string(to_string(i) + " does not have a left child");
	return temp->getleft()->getdata();
}

int Tree::right(int i) {
	cout << "function right was called on " << i << " " << endl;
	TNode* temp = search(i);
	if (temp == NULL)
		throw string(to_string(i) + " is not in the tree");
	if (temp->getright() == NULL)
		throw string(to_string(i) + " does not have a right child");
	return temp->getright()->getdata();
}



void functionvisit(TNode* node) {

	if (node->getleft() != NULL) {
		functionvisit(node->getleft());
	}
	cout << " ";
	cout << node->getdata();

	if (node->getright() != NULL) {
		functionvisit(node->getright());
	}

}


void Tree::print() {


	functionvisit(head);

}
