#include<iostream>
#include"forward_list.h"
using namespace std;
int main() {
	forward_list <int>t;
	try{
	t.push_front(5);
	t.push_front(5);
	t.push_front(6);
	t.push_front(7);
	t.push_front(7);
	t.push_front(8);
	t.push_front(0);
	t.push_front(0);
	t.push_front(0);
	}
	catch(const char* s){
		cout<<s<<endl;
	}
	cout<<"List 1 : ";
	t.display();
	t.reverse();
	cout<<"After Reversing | List 1 : ";
	t.display();
	t.unique();
	cout<<"After Unique    | List 1 : ";
	t.display();
	t.sort();
	cout<<"After Sorting   | List 1 : ";
	t.display();
forward_list <int>s;
try{
s.push_front(-2);
s.push_front(0);
s.push_front(4);
s.push_front(5);
s.push_front(6);
}
catch(const char* s){
cout<<s<<endl;
}
cout<<"List 2 : ";
s.display();
t.merge(&s);
cout<<"After Merging : ";
t.display();

}
