#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
class List {
private:
	node* head;
	int n;
public:
	List();
	void push(int val);
	int pop();
	bool isEmpty()const;
	void display()const;
	void swap_min_max();
};
int main() {
	List s;
/*
	s.push(5);
	//	cout<<s.pop()<<endl;
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	s.push(6);
	s.push(8);
	s.push(9);
	*/	
	s.push(4);
	s.push(1);
	s.push(5);
	s.push(3);

	s.display();
	s.swap_min_max();
	s.display();
}
List::List() {
	node* head = new node;
	head = NULL;
	n = 0;
}
void List::push(int val) {
	node* temp = head;
	if (temp == NULL) {
		node* t = new node;
		t->data = val;
		t->next = NULL;
		head = t;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		node* t = new node;
		t->data = val;
		t->next = NULL;
		temp->next = t;
	}
}
int List::pop() {
	node* temp = head;
	node* t = new node;
	int val;
	if (temp->next == NULL) {
		val = temp->data;
		delete temp;
		head = NULL;
	}
	else {
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		t = temp->next;
		val = t->data;
		delete t;
		temp->next = NULL;

	}
	return val;
}
bool List::isEmpty()const {
	return head == NULL;
}
void List::display()const {
	node *temp = head;
	cout << "[ ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "]\n";
}
void List::swap_min_max() {
	node* temp = head;
	if (temp->next == NULL) exit(0);
	node* min = temp;
	node* max = temp;
	node* temp_p = NULL;
	node* min_p = NULL;
	node* max_p = NULL;
	while (temp != NULL) {
		if (temp->data > max->data) {
			max = temp;
			max_p = temp_p;
		}
		if (temp->data < min->data) {
			min = temp;
			min_p = temp_p;
		}
		temp_p = temp;
		temp = temp->next;

	}
	/*
	node *t1;
	node* t2;
	t2 = max;
	t1 = min;
	min_p->next = max;
	max->next = t1->next;
	max_p->next = t1;
	t1->next = max->next;
	*/
	node* min_next = min->next;
	min->next = max->next;
	max->next = min_next;
	min_p->next = max;
	max_p->next = min;

}
