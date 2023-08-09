#include<iostream>
using namespace std;

template<typename T>
struct tnode{
	T data;
	tnode<T>* left;
	tnode<T>* right;
};
template<typename T>
//RECURSIVE CALL
void insert(tnode<T> *&ptr,const T &val){
	if(ptr==NULL){
		ptr=new tnode<T>;
		ptr->data=val;
		ptr->left=ptr->right=NULL;
	}
	else if(val>ptr->data)  insert(ptr->right,val);
	else  (ptr->left,val);
}
//template<typename T>
//void display(tnode<T>* ptr){
//	if(ptr==NULL) return;
//	else
//	{ cout<<ptr->data<<end;
//	
//}
//}
int main(){
	tnode<int>* t=NULL;
	insert(t,5);
	display(t);
}
