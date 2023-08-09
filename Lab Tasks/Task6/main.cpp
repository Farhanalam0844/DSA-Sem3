#include<iostream>
#include"list.h"
using namespace std;

int main() {
	list<int> l;
	try {
	//	l.push(1);
		//l.push(2);
		l.push_front(10);
		l.push_front(6);
		l.push_front(4);
		l.push_front(2);
		l.push_front(1);
		cout << "List 1 :";
		display(l);
	//	l.display();
	}
	catch (const char* s) {
		cout << s;
	}
	list<int> l2;
	try {
		l2.push_front(20);
		l2.push_front(13);
		l2.push_front(10);
		l2.push_front(8);
		l2.push_front(7);
		l2.push_front(4);
		l2.push_front(0);
		cout << "List 2 : ";
		display(l2);
		l.merge(l2);
		cout << "After merging List 1 : ";
		display(l);
		
	}
	catch (const char* s) {
		cout << s;
	}
}