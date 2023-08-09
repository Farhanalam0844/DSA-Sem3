#pragma once
#include<iostream>
#include"dnode.h"
using namespace std;
template<typename T>
class list {
private:
	dnode<T>* FRONT;
	dnode<T>* BACK;
	int n;
public:
	list() {
		FRONT = BACK = NULL;
		n = 0;
	}
	void push(const T& val) {
		dnode<T>* temp;
		temp = new dnode<T>;
		if (temp == NULL) throw "List overflow\n";
		temp->data = val;
		temp->next = NULL;
		temp->prev = BACK;
		if (BACK == NULL) FRONT = temp;
		if (BACK != NULL) 	BACK->next = temp;
		BACK = temp;
		n++;
	}
	T pop() {
		if (BACK == NULL) throw "List underflow\n";
		dnode<T>* temp = BACK;
		BACK = BACK->prev;
		BACK->next = NULL;
		T val = temp->data;
		delete temp;
		n--;
		return val;
	}
	void push_front(const T& val) {
		dnode<T>* temp = new dnode<T>;
		if (temp == NULL) throw "List overflow \n";
		temp->data = val;
		temp->next = FRONT;
		temp->prev = NULL;
		if (FRONT == NULL) BACK = temp;
		else FRONT->prev = temp;
		FRONT = temp;
		n++;
	}
	T pop_front() {
		if (FRONT == NULL) throw "List underflow\n";
		dnode<T>* temp = FRONT;
		FRONT = FRONT->next;
		FRONT->prev = NULL;
		delete temp;
		n--;
	}
	int max_size()const {
		return n;
	}
	void clear() {
		dnode<T>* temp = FRONT;
		while (temp != NULL) {
			pop();
		}
	}
	bool empty()const {
		return n == 0;
	}
		
	 friend void display(const list<T>& t) {
		dnode<T>* temp = t.FRONT;
		cout << "[ ";
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "]" << endl;
	}
	void merge(list<T>& right)
	{
		dnode<T>* temp1_f = FRONT;
		dnode<T>* temp2_f = right.FRONT;
		dnode<T>* temp1_b = BACK;
		dnode<T>* temp2_b = right.BACK;
		if (temp1_f == NULL && temp2_f == NULL) throw "Both lists are empty\n";
		if (temp2_f == NULL) return;
		else if (temp1_f == NULL) {
			FRONT = temp2_f;
			BACK = temp2_b;
			temp2_f = NULL;
			temp2_b = NULL;
		}
		else {
		dnode<T>* temp1_f_p = NULL;
			while (temp1_f != NULL && temp2_f != NULL) {
				if (temp1_f->data >= temp2_f->data) {
					dnode<T>* t = temp2_f;
					temp2_f = temp2_f->next;
					if (temp1_f->prev == NULL) {
						t->next = temp1_f;
						temp1_f->prev = t;
						t->prev = NULL;
						FRONT = t;
						//	temp1_f = FRONT;
					}
					else {
						temp1_f->prev->next = t;
						t->prev = temp1_f->prev;
						t->next = temp1_f;
						temp1_f->prev = t;
					}
				}
				else {
					temp1_f_p = temp1_f;
					temp1_f = temp1_f->next;
				}
			}
			if (temp2_f == NULL) return;
			else if (temp1_f == NULL) {
				
				temp1_f_p->next = temp2_f;
				
			}
		}
	}
};