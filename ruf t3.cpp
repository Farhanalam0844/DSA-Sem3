#include<iostream>
using namespace std;

class Stack{
	private:
		int* data;
		int TOP;
		int SIZE;
	public:
		Stack(int);
		void push(int val);
		void pop();
		bool isEmpty();
		int top();
		bool operator==(Stack& right);
		bool operator<(Stack& right);
		~Stack();
};
int main(){
	int size=5;
	Stack s1(size);
	int i=0;
	for(i=0;i<size;i++){
		s1.push(i);
	}
	while(!s1.isEmpty()){
		cout<<s1.top()<<endl;
		s1.pop();
	}
	for(i=0;i<size;i++){
		s1.push(i);
	}
	Stack s2(size);
	for(i=size;i>0;i--){
		s2.push(i);
}
	while(!s2.isEmpty()){
		cout<<s2.top()<<endl;
		s2.pop();
	}


//EQUAL TO
//	bool b=s1==s2;
//	if(b<0) cout<<"false";
//	else cout<<"true";
//	cout<<b<<endl;

// LESS THAN 
	if(s1<s2) cout<<"false";
	
	else cout<<"true";
}
Stack::Stack(int size){
	this->SIZE=size;
	data=new int[this->SIZE];
	TOP=-1;
}
void Stack::push(int val){
	TOP++;
	data[TOP]=val;
}
void Stack::pop(){
	TOP--;
}
bool Stack::isEmpty(){
	return (TOP<0)?true:false;
}
int Stack::top(){
	return data[TOP];
}
bool Stack::operator==(Stack& right){

	int i;
	for(i=TOP;i>=0;i++){
		if(this->data[i]==right.data[i]);
		else return -1;
	}
	return 1;
}
bool Stack::operator<(Stack& right){
	int i;
	for(i=this->TOP;i>=0;i++){
		if(this->data[i]<right.data[i]) return 1;
	}
	return -1;
}
Stack::~Stack(){
	delete[]data;
}
