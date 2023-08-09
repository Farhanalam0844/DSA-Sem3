#include<iostream>
using namespace std;

class Stack{
	private:
		int TOP;
		int SIZE;
	public:
		int* data;
		Stack(int);
		Stack(const Stack &right);
		int get_top()const;
		int get_size()const;
		void push(int val);
		void pop();
		bool isEmpty()const;
		int top()const;
		bool operator==(Stack& right);
		bool operator<(Stack& right);
		bool operator>(Stack& right);
		bool operator<=(Stack& right);
		bool operator>=(Stack& right);
		bool operator!=(Stack& right);
		friend ostream& operator<<(ostream& c,Stack& stack);
		~Stack();
};
int main(){
	int size=5;
	Stack s1(size);
	int i=0;
	for(i=0;i<size;i++){
		s1.push(i);
	}
	
	cout<<"Stack : 1\n"<<s1;
	Stack s2(size);
	for(i=size;i<size+size;i++){
		s2.push(i);
}
cout<<"Stack : 2\n"<<s2;
cout<<"Operations sequence --- \n1-Less than\n2-Less than or equal to\n"
<<"3-Equal to\n4-Not equal to\n5-Greater than\n6-Greater than or equal to\n\n";
// LESS THAN 

	cout<<"Operation Less than\n";
	if(s1<s2) cout<<"True! Stack 1 is less than Stack 2\n\n";
	else cout<<"False! Stack 1 is not less than Stack 2\n\n";
// LESS THAN OR EQUAL TO
	cout<<"Operation Less than or Equal to\n\n";
	if(s1<=s2) cout<<"True! Stack 1 is less than or equal to Stack 2\n\n";
	else cout<<"False! Stack 1 is not less than nor equal to Stack 2\n\n";
//COPY CONSTRUCTOR 
	Stack s3=s1;
	cout<<"Using copy constructor from s1 to s3\n"<<s3<<endl;
//EQUAL TO
	cout<<"Operation Equal to\n\n";
	if(s1==s3) cout<<"True! Stack 1 is equal to than Stack 3\n";
	else cout<<"False! Stack 1 is not equal to than Stack 3\n";
//NOT EQUAL TO
	cout<<"Operation Not Equal to\n\n";
	if(s1!=s3) cout<<"True! Stack 1 is not equal to than Stack 3\n\n";
	else cout<<"False! Stack 1 is equal to than Stack 3\n\n";
//GREATER THAN 
	cout<<"Operation Greater than\n";
	if(s1>s2) cout<<"True! Stack 1 is greater than Stack 2\n\n";
	else cout<<"False! Stack 1 is not greater than Stack 2\n\n";
//GREATER THAN OR EQUAL TO 
	cout<<"Operation Greater than or Equal to\n";
	if(s1>=s2) cout<<"True! Stack 1 is greater than or equal to Stack 2\n\n\n";
	else cout<<"False! Stack 1 is not greater than nor than Stack 2\n\n\n";
	

}
Stack::Stack(int size){
	this->SIZE=size;
	data=new int[this->SIZE];
	TOP=-1;
}
Stack::Stack(const Stack& right){
	this->SIZE=right.SIZE;
	this->TOP=right.TOP;
	this->data=new int[this->SIZE];
	for(int i=0;i<=right.TOP;i++){
		this->data[i]=right.data[i];
	}
}
int Stack::get_top()const{
	return this->TOP;
}
int Stack::get_size()const{
	return this->SIZE;
}
void Stack::push(int val){
	TOP++;
	data[TOP]=val;
}
void Stack::pop(){
	TOP--;
}
bool Stack::isEmpty()const{
	return (TOP<0)?true:false;
}
int Stack::top()const{
	return data[TOP];
}
bool Stack::operator==(Stack& right){

	int i;
	for(i=TOP;i>=0;i--){
		if(this->data[i]==right.data[i]){
		}
		else return 0;
	}
	return 1;
}
bool Stack::operator>(Stack& right){

	int i;
	for(i=this->TOP;i>=0;i--){
		if(this->data[i]>right.data[i]) {
		}
		else return 0;
	}
	return 1;
}
bool Stack::operator<(Stack& right){
	int i;
	for(i=this->TOP;i>=0;i--){
		if(this->data[i]<right.data[i]){
		}
		else return 0;
	}
	return 1;	
}
bool Stack::operator<=(Stack& right){
	int i;
	for(i=this->TOP;i>=0;i--){
		if(this->data[i]<=right.data[i]){
		} 
		else return 0;
	}
	return 1;
}
bool Stack::operator>=(Stack& right){
		int i;
	for(i=this->TOP;i>=0;i--){
		if(this->data[i]>=right.data[i]) {
		}
		else return 0;
	}
	return 1;
}
bool Stack::operator!=(Stack& right){
			int i;
	for(i=this->TOP;i>=0;i--){
		if(this->data[i]!=right.data[i]) {
		}
		else return 0;
	}
	return 1;
}
Stack::~Stack(){
	delete[]data;
}
ostream& operator<<(ostream& c,Stack& stack){
	for(int i=stack.get_top();i>=0;i--){
		c<<stack.data[i]<<endl;
	}
	return c;
}

//C:\Users\No\AppData\Local\Temp\ccANr13v.o	lab task 3.cpp:(.text+0x63): undefined reference to `operator<<(std::ostream&, Stack&)'
