#include<iostream>
#include<queue>
#include<iomanip>
#include"tnode.h"
using namespace std;

class BST {
private:
	tnode* root;
	int n;
public:
	BST() {
		root = NULL;
		n = 0;
	}
	void insert(int val) {
		insert(root, val);
	}
private:
	void insert(tnode*& root, int val) {
		if (root == NULL) {
			root = new tnode;
			root->data = val;
			root->left = root->right = NULL;
			n++;
		}
		else if (val < root->data) return insert(root->left, val);
		else  return insert(root->right, val);
	}
	void Display(tnode*& root) {
		if (root == NULL)	return ;
		cout << root->data << endl;
		 Display(root->left);
		 Display(root->right);
	}
public:
	void display() {
		Display(root);
	}
	
	int node() {
		find_nodes(root);
		return n;

	}
	int find_nodes(tnode*& root) {
	//	if(root=)
		return 0;
	}
	bool find(int val) {
	return find_node(root, val);
	}
private:
	bool find_node(tnode*& root, int val) {
		if (root == NULL) return false;
		if (root->data == val) {
			return true;
		}

		else if (val > root->data) return find_node(root->right, val);
		else return find_node(root->left, val);
		return false;
	}
public:
	void delete_node(int val) {
		Delete(root, val);
	}
	private:

	void Delete(tnode*& root, int val) {
		if (root == NULL) return;
		else if (root->data == val) {
			if (root->left == NULL && root->right == NULL) {
				delete root;
				root = NULL;
				return;
			}
			else if (root->left == NULL) {
				tnode* t = root;
				root = root->right;
				delete t;
				t = NULL;
				return;
			}
			else if (root->right == NULL) {
				tnode* t = root;
				root = root->left;
				delete t;
				t = NULL;
				return;
			}
			else {
				int val = find_min(root->right);
				root->data = val;
				Delete(root, val);
			}

		}
		else if (root->data > val) return Delete(root->left, val);
		else return Delete(root->right, val);
	}

	int find_min(tnode*& root) {
		if (root->left == NULL) return root->data;
		else return find_min(root->left);
	}
	int Leafs(tnode*& root) {
	if (root == NULL) return 0;
	else if (root->left == NULL && root->right == NULL) { return 1; }
	return Leafs(root->left)+Leafs(root->right);
}
	int Nodes(tnode*& root) {
		if (root == NULL) return 0;
	//	else if (root->left == NULL && root->right == NULL) { return 1; }
		else return{ 1 + Nodes(root->left) + Nodes(root->right) };
	}
	int Height(tnode* root) {
		if (root == NULL) return 0;
		int l = Height(root->left);
		int r = Height(root->right);
		return (l > r ? l : r)+1;
	}
public:
	int leafs(){
		return Leafs(root);
	}
	int nodes() {
		return Nodes(root);
	}
	int height() {
		return Height(root);
	}
};
int main() {
	BST t;
	t.insert(1);
	t.insert(2);
	t.insert(0);
	t.insert(10);
	t.insert(7);
	cout << t.nodes();


	int val = 10;
	bool b = t.find(val);
	if (b) cout << "Node present with value : " << val << "\n ";
	else cout << "Node not present with value : " << val << "\n ";
	
	val = 100;
	b = t.find(val);
	if (b) cout << "Node present with value : " << val << "\n ";
	else cout << "Node not present with value : " << val << "\n ";
	val = 10;
	t.delete_node(val);
	t.insert(-5);
	t.insert(-2);
	t.insert(20);
	t.insert(13);
	t.insert(6);
	t.insert(12);
	t.display();
//	val = -2;
//	t.delete_node(val);
//	cout << "After deleting "<<val<<endl;
//	t.display();
//	val = 13;
//	t.delete_node(val);
//	cout << "After deleting "<<val<<endl;
//	t.display();
//	val = 7;
//	t.delete_node(val);
//	cout << "After deleting "<<val<<endl;
//	t.display();
	cout << "No of leafs are " << t.leafs() << endl;
	cout << "No of nodes are " << t.nodes() << endl;
	cout << "Height of BST is " << t.height() << endl;
}
