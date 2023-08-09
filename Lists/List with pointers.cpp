#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};
node* create_node(node* c,int val){
	node* n=new node;
	n->data=val;
	n->next=NULL;
	c->next=n;
	return n;
}
void display_list(node* h){
	node* c=h;
	cout<<"[ ";
	while(c!=NULL){
		cout<<c->data<<" ";
		c=c->next;
	}
	cout<<"] \n";
}
void delete_node(node* c){
	node* temp;
	temp=c->next;
	c->next=temp->next;
	delete temp;
}
int main(){
	node* head;
	head=new node;
	head->data=1;
	head->next=NULL;
	node* current=head;
	int i;
	for(i=2;i<=10;i++){
		current =create_node(current,i);
	}
	cout<<"List :";
	display_list(head);
	cout<<"Deleteing : "<<head->next->data<<" : ";
	delete_node(head);
	display_list(head);
	cout<<"Deleteing : "<<head->next->next->next->data<<" : ";
	delete_node(head->next->next);
	display_list(head);
}
