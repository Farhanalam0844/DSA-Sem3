#include<iostream>
#include"Linked Stack.h"
template<typename T>
Stack<T>::Stack(){
	top_ptr=NULL;
}
template<typename T>
void Stack<T>::push(T val){
	node<T>* temp=new node<T>;
	temp->data=val;
	temp->next=top_ptr;
	top_ptr=temp;
}
template<typename T>
T Stack<T>::pop(){
	if(top_ptr==NULL) throw"Stack underflow\n";
	else{
	node<T>* temp=top_ptr;
	top_ptr=temp->next;
	T t=temp->data;
	delete temp;
	return t;
}
}
template<typename T>
bool Stack<T>::isEmpty()const{
	return top_ptr==NULL;
}
template<typename T>
void Stack<T>::makeEmpty(){
	node<T>* temp;
	while(temp!=NULL) {	
//		cout<<pop()<<"\n";
		temp=top_ptr;
	}
//	cout<<endl;
}
template<typename T>
T Stack<T>::top()const{
	return top_ptr->data;
}
