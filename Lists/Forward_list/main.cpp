#include<iostream>
#include"forward_list.h"
#include"definitions.cpp"
using namespace std;

void display(forward_list& r) {
	node* temp = r.FRONT;
	cout << "[ ";
	while (temp != NULL) {
		cout << temp->data<<" ";
		temp = temp->next;
	}
	cout << "]\n";
}

int main() {
	forward_list l1;
	display(l1);
	l1.push_front(4);
	l1.push_front(3);
	l1.push_front(2);
	l1.push_front(1);
	
	display(l1);
	forward_list l2;
	l2= l1;
	display(l2);
	l1.merge(l2);
	display(l1);
		return 0;
}