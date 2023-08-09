#include<iostream>
using namespace std;
 template<class T>
class Stack{
	private:
		T *arr;
		int top;
		int size;
	public:
		Stack(int n=10);
		T Top()const;
		void push(T n);
		void pop();
		bool isFull()const;
		bool  isEmpty()const;
		int SIZE()const;
		void Empty();	
};
int main(){
	Stack <int>s(4);
	s.push(5);
	s.push(10);
	s.push(15);
	s.push(20);
//	s.push(25);   //Stack Overflow
	s.Empty();
//	s.pop();		//Stack Underflow
}
template<class T>
Stack<T>::Stack(int n){
	arr=new T[n];
	size=n;
	top=-1;
}
template<class T>
T Stack<T>::Top()const{
	return arr[top];
}
template<class T>
void Stack<T>::push(T n){
	if(!this->isFull()){
	top++;
	arr[top]=n;
	}
	else {
		cout<<"Stack Overflow"<<endl;
		top++;
		arr[top]=n;
	}
}
template<class T>
void Stack<T>::pop(){
	if(!this->isEmpty())
	this->top--;
	else{
	 cout<<"Stack Underflow"<<endl;
	this->top--;
	}
}
template<class T>
int Stack<T>::SIZE()const{
	return this.size;
}
template<class T>
bool Stack<T>::isEmpty()const{
	return top==-1;
}
template<class T>
void Stack<T>::Empty(){
	T n;
	while(!this->isEmpty()){
		n=this->Top();
		cout<<n<<endl;
		this->pop();
	}
}
template<class T>
bool Stack<T>::isFull()const{
	return top==size-1;
}
