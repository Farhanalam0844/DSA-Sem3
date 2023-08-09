#include<iostream>
using namespace std;

//STACK WITH SIMPLE ARRAY
class Stack{
	private:
		int arr[10];
		int size;
		int top;
	public:
		Stack();
		void push(int);
		void pop();
		bool Is_Empty()const;
		int Top()const;
		int getSize()const;
};
int main(){
	Stack s;
	int i=0;
	for(i=0;i<s.getSize();i++){
		s.push(i);
	}
	int num;
	while(!s.Is_Empty()){
		num=s.Top();
		s.pop();
		cout<<num<<endl;
	}
}
Stack::Stack(){
	size=10;
	top=-1;
}
void Stack::push(int n){
	top++;
	arr[top]=n;
}
void Stack::pop(){
	top--;
}
bool Stack::Is_Empty()const{
	return top==-1;
}
int Stack::Top()const{
	return arr[top];
}
int Stack::getSize()const{
	return this->size;
}
