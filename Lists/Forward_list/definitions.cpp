#include"forward_list.h"
#include"iterator.h"

forward_list::forward_list() {
	this->n = 0;
	this->FRONT = NULL;
}
forward_list::forward_list(const forward_list& right) {
	if (!empty()) clear();
	this->operator=(right);
}
//const iterator forward_list::cbegin() {
//	iterator it;
//	it.ptr = FRONT;
//	return it;
//}
//iterator forward_list::end() {
//	iterator it;
//	it.ptr = NULL;
//	return it;
//}
//const iterator forward_list::cend() {
//	return NULL;
//}
bool forward_list::empty()const {
	return n == 0;
}
int forward_list::max_size()const {
	return n;
}
void forward_list::clear() {
	node* temp = FRONT;
	while (temp!=NULL)
	{
		this->pop_front();
	}
	n = 0;
}
void forward_list::push_front(int val) {
	node* temp;
	temp = new node;
	if (temp == NULL) throw "forward list overflow \n";
	temp->data = val;
	temp->next = FRONT;
	FRONT = temp;
	n++;
}
int forward_list::pop_front() {
	if (FRONT == NULL) throw "list underflow\n";
	node* temp = FRONT->next;
	FRONT = FRONT->next;
	int val = temp->data;
	delete temp;
	n--;
	return val;
}
bool forward_list::operator==(const forward_list& right){
	node* temp1 = FRONT;
	node* temp2 = right.FRONT;
	while (!empty()) {
		if (temp1->data != temp2->data) return 0;
		temp1 = temp1->next;
		temp2 = temp2->next;
		if (temp2 == NULL) return 1;
	}
	return 1;
}
bool forward_list::operator!=(const forward_list& right){
	node* temp1 = FRONT;
	node* temp2 = right.FRONT;
	while (!empty()) {
		if (temp1->data == temp2->data) return 0;
		temp1 = temp1->next;
		temp2 = temp2->next;
		if (temp2 == NULL) return 1;
	}
	return 1;
}
bool forward_list::operator<=(const forward_list& right){
	node* temp1 = FRONT;
	node* temp2 = right.FRONT;
	while (!empty()) {
		if (temp1->data > temp2->data) return 0;
		temp1 = temp1->next;
		temp2 = temp2->next;
		if (temp2 == NULL) return 1;
	}
	return 1;
}
bool forward_list::operator>=(const forward_list& right){
	node* temp1 = FRONT;
	node* temp2 = right.FRONT;
	while (!empty()) {
		if (temp1->data < temp2->data) return 0;
		temp1 = temp1->next;
		temp2 = temp2->next;
		if (temp2 == NULL) return 1;
	}
	return 1;

}
bool forward_list::operator>(const forward_list& right){
	node* temp1 = FRONT;
	node* temp2 = right.FRONT;
	while (!empty()) {
		if (temp1->data <= temp2->data) return 0;
		temp1 = temp1->next;
		temp2 = temp2->next;
		if (temp2 == NULL) return 1;
	}
	return 1;
	}
bool forward_list::operator<(const forward_list& right) {
	node* temp1 = FRONT;
	node* temp2 = right.FRONT;
	while (!empty()) {
		if (temp1->data >= temp2->data) return 0;
		temp1 = temp1->next;
		temp2 = temp2->next;
		if (temp2 == NULL) return 1;
	}
	return 1;
}
void forward_list::operator=(const forward_list& right) {
	node* temp1 = FRONT;
	node* temp2 = right.FRONT;
	clear();
//	forward_list t;
	//t.FRONT= temp1;
	while (temp2!=NULL) {
		push_front(temp2->data);
		temp2 = temp2->next;
	}
//	operator=(t);
}
void forward_list::remove(const int& val) {
	node* temp = this->FRONT;
	if (temp->data == val) {
		pop_front();
	}
	else {
		while (temp->next!=NULL)
		{
			if (temp->next->data == val) {
				node* t = temp->next;
				temp->next = t->next;
				delete t;
			}
			temp = temp->next;

		}
	}
}
void forward_list::reverse(){

	}
void forward_list::unique(){
	}
void forward_list::sort(){
	}
void forward_list::merge(const forward_list& right){
	
	}
void forward_list::insert_after(const iterator* it, int val){
	}
void forward_list::erase_after(const iterator* it){
	}
void forward_list::swap(const forward_list* right) {
}
forward_list::~forward_list() {
	clear();
}