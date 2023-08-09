#include<iostream>
using namespace std;
template<typename T>
class Stack{
	private:
		T *data;
		int TOP;
		int size;
	public:
		Stack(int n=10);
		void push(T val);
		T pop();
		T top()const;
		bool isEmpty()const;
		Stack(const Stack<T>& right);
		bool operator==(const Stack<T>& right);
		bool operator<(const Stack<T>& right);
		bool operator>(const Stack<T>& right);
		friend ostream& operator<<(ostream& c,const Stack& right);
};
int main(){
	Stack<int> s(10);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	Stack <int> p=s;
	if(s==p){
		cout<<"Both Stacks are equal \n";
	}
	else cout<<"Stacks are not equal \n";
	cout<<s.pop()<<endl;
//	if(s==p){
//		cout<<"Both Stacks are equal \n";
//	}
//	else cout<<"Stacks are not equal \n";
	if(s<p){
		cout<<"s is less than p\n";
	}
	else cout<<"s is equal to or greater then p\n";
	s.push(4);

	if(s>p){
		cout<<"s is greater than p\n";
	}
	else cout<<"s is less than or equal to p\n";
}
template<typename T>
Stack<T>::Stack(int n){
	this->size=n;
	this->TOP=-1;
	this->data=new T[size];
}
template<typename T>
void Stack<T>::push(T val){
	TOP++;
	data[TOP]=val;
}
template<typename T>
T Stack<T>::pop(){
	T val=data[TOP];
	TOP--;
	return val;
}
template<typename T>
T Stack<T>::top()const{
	return data[TOP]; 
}
template<typename T>
bool Stack<T>::isEmpty()const{
	return TOP+1==size;
}
template<typename T>
Stack<T>::Stack(const Stack<T>& right){
	this->size=right.size;
	this->TOP=right.TOP;
	if(this->data!=NULL){
		delete []data;
	}
	this->data=new T[size];
	int i=0;
	for(i=0;i<=TOP;i++){
		this->data[i]=right.data[i];
	}
	
}
template<typename T>
bool Stack<T>::operator==(const Stack<T>& right){
	int i=this->TOP;
	int j=right.TOP;
	while(i>=0&&j>=0){
		if(data[i]!=right.data[j]){
			return false;
		}		
		i--;
		j--;
	}
	return true;
}
template<typename T>
bool Stack<T>::operator<(const Stack<T>& right){
	int i=TOP;
	int j=right.TOP;
	while(i>=0&&j>=0){
		if(data[i]>=right.data[j]) return false;
		i--;
		j--;
	}
	return true;
}
template<typename T>
bool Stack<T>::operator>(const Stack<T>& right){
	int i=TOP;
	int j=right.TOP;
	while(i>=0&&j>=0){
		if(data[i]<=right.data[j]) return false;
		i--;
		j--;
	}
	return true;
}
template <typename T>
ostream& operator<<( ostream& c,const Stack<T>& right){
	int i=right.top();
	for(i;i>=0;i--){
		c<<right.data[i]<<" ";
	}cout<<"\n";		
	return c;
	}
