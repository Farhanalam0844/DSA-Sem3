#include"list.h"
#include <iostream>
using namespace std;

int main() {
	
	list <int>t;
	try{
	t.push_back(1);
	t.push_back(3);
	t.push_back(5);
	t.push_back(5);
	t.push_back(6);
	t.push_back(6);
//	t.push_back(8);
	
//	t.push_back(6);
	t.push_front(0);
	t.push_front(0);
//		t.push_front(0);
//	t.push_front(-1);
}
catch(const char* s){
	cout<<s<<endl;
}
cout<<"List : 1 ";
	t.display();
	t.unique();
cout<<"After Unique  | List 1 : ";
	t.display();
	t.reverse();
cout<<"After Reverse | List 1 : ";
	t.display();
	list <int>s;
	s.push_front(4);
	s.push_front(6);
	s.push_front(5);
	cout<<"List 2 : ";
	s.display();
	cout<<"Sort is unfinished : ";
//t.sort();
t.display();
	cout<<"Merge is unfinished : ";
t.merge(&s);
//t.display();
	
}
