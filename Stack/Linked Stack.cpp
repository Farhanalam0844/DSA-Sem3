#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
class Stack{
	private:
		node* top_ptr;
	public:
		Stack();
		void push(int val);
		int pop();
		int top()const;
		bool isEmpty() const;
		void makeEmpty();		
};
int main(){
	Stack s;
	try{
	s.push(1);
	s.push(2);
	cout<<s.top()<<endl;
	s.push(3);
	cout<<s.pop()<<endl;
	s.makeEmpty();
}
catch(...){
	cout<<"Underflow";
}
}
Stack::Stack(){
	top_ptr=NULL;
}
void Stack::push(int val){
	node* temp=new node;
	temp->data=val;
	temp->next=top_ptr;
	top_ptr=temp;
}
int Stack::pop(){
	if(top_ptr==NULL) throw"Stack underflow\n";
	else{
	node* temp=top_ptr;
	top_ptr=temp->next;
	int t=temp->data;
	delete temp;
	return t;
}
}
bool Stack::isEmpty()const{
	return top_ptr==NULL;
}
void Stack::makeEmpty(){
	node* temp;
	while(temp!=NULL) {	
		cout<<pop()<<"\n";
		temp=top_ptr;
	}
	cout<<endl;
}
int Stack::top()const{
	return top_ptr->data;
}
