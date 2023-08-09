#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
 
class Linkedlist{
	private:
		node* head;
	public:
		Linkedlist();
		void push(int val);
		void display()const;
		int pop();
		int top()const;
		bool isEmpty();
		void push_rear(int val);
		int pop_rear();
		void Delete(int val);
		};
 main(){
//	display();
//	push()
	Linkedlist  p;
	try{
	p.push(1);
	p.push(2);

	p.display();
	cout<<"Pop : "<<p.pop()<<endl;
	p.display();
	cout<<"Pop : "<<p.pop()<<endl;
//	p.pop();
	p.push(1);
	p.push(2);
	p.push(3);
	
	p.push_rear(0);
	p.display();
	cout<<"Pop rear : "<<p.pop_rear()<<endl;
	p.display();
	p.Delete(2);
	p.display();
	
	}
catch(...){
	cout<<"list underflow"
	<<endl;
	}
}
 
Linkedlist::Linkedlist(){
	head=NULL;
}
void Linkedlist::push(int val){
	node* temp=head;
		node* c=new node;
	if(temp==NULL){
		c->data=val;
		c->next=NULL;
		head=c;
	}
	else {
		while(temp->next!=NULL){
			temp=temp->next;
		}
		c->data=val;
		c->next=NULL;
		temp->next=c;
	}
}
 
void Linkedlist::display()const{
	node* temp=head;
	cout<<"[ ";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"]\n";
}
 
int Linkedlist::pop(){
	node* temp=head;
	if(temp==NULL) throw"list underflow";
	else if(temp->next==NULL){
		head=NULL;
		return temp->data;
	
	}
	else {
		node* prev=temp;
		temp=temp->next;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		prev->next=temp->next;
		delete temp;
//		return temp->data;
	}

}
void Linkedlist::push_rear(int val)
{
	node* rear=new node;
	rear->data=val;
	rear->next=head;
	head=rear;
}
int Linkedlist::pop_rear(){
	node * temp=head;
	head=head->next;
	return temp->data;
}
bool Linkedlist::isEmpty(){
	return head==NULL;
}
void Linkedlist::Delete(int val){
	node* temp=head;
	if(temp->data==val){
		delete temp;
		head=NULL;
// not needed necessarily
	}
	else {
		while(temp->next!=NULL){
			if(temp->next->data==val){
				node* t=temp->next;
				temp->next=t->next;
				delete t;
			}
			else temp=temp->next;
			
		}
		
	}
}
