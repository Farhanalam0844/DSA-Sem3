#include<iostream>
using namespace std;

template<typename T>
struct tnode {
	T data;
	tnode<T>* left;
	tnode<T>* right;
};

template<typename T>
void insert(tnode<T>*& root,T val) {
	
	if (root == NULL) {
		root = new tnode<T>;
		root->data = val;
		root->left = root->right = NULL;
	}
	else if (root->data<val)
		insert(root->right, val);
	else insert(root->left, val);
}

template<typename T>
void display(tnode<T>*& root) {
	if (root == NULL) return;
	cout << root->data << endl;
//	if (root->left == NULL)
		display(root->left);
//	else 
	display(root->right);
}
template<typename T>
bool empty(tnode<T>*& root)
{
	return root == NULL;
}
template<typename T>
bool find(tnode<T>*& root,T val) {
//	cout << "find\n";
	if (root == NULL) return false;
	if (val ==root->data) return true;
	else if (val > root->data)		//1
		find(root->right,val);	//-5		2
										//0		9
	else find(root->left,val);
	
//	cout << "@";
//	return false;
}
template<typename T>
int leafs(tnode<T>*& root,int n) {
	if (root == NULL) return 0;
	else if (root->left == NULL && root->right == NULL) {  return n++; }
	n= leafs(root->left,n);
	n= leafs(root->right,n);
	return n;
}
int main() {
	tnode<int> *t=NULL;
	//int i,j;
	cout << empty(t)<<endl;
//	for (i = 0, j = 5; i < 10; i++, j = j + 2) {
		insert<int>(t, 1);
		insert<int>(t, 5);
		insert<int>(t, 2);
		insert<int>(t, 11);
		insert<int>(t, 56);
		insert<int>(t, -5);
		insert<int>(t, 3);
		insert<int>(t, 10);
	//}
		cout << empty(t)<<endl;
	display(t);

	bool b=find(t, 10);
	if (b) cout << "Value "<<10<<" is present \n";
	else cout << "Value " << 10 << " not present \n";
	b= find(t, 1000);
	if (b) cout << "Value " << 1000 << " is present \n";
	else cout << "Value " << 1000 << " not present \n";

cout<<leafs(t,0);
	return 0;
}
