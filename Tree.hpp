#pragma once

namespace ariel
{

	class TNode {
		int data;
		TNode* left;
		TNode* father;
		TNode*right;
	public:
		TNode(int num) {
			data = num;
			left = NULL;
			father = NULL;
			right = NULL;

		}
		~TNode()
		{
		}
		void setdata(int num1) {
			data = num1;
		}
		int getdata() {
			return data;
		}
		void setleft(TNode* t) {
			left = t;
		}
		TNode* getleft() {
			return left;
		}
		void setright(TNode* t) {
			right = t;
		}
		TNode* getright() {
			return right;
		}

		void setfather(TNode* t) {
			father = t;
		}

		TNode* getfather() {
			return father;
		}
	};


	//functions
	class Tree {

	private:
		TNode* head;
		int TreeSize;
	public:
		Tree();
		~Tree();
		void setHead(TNode* t);
		TNode* gethead();
		void insert(int i);
		void remove(int i);
		int size();
		bool contains(int i);
		int root();
		int parent(int i);
		int left(int i);
		int right(int i);
		void print();

		//add our function:
		TNode* search(int i);
	};
}
