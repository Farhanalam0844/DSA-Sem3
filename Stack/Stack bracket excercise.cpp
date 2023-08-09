#include<iostream>
#include<cstring>
using namespace std;

class Stack{
	private:
		char* data;
		int size;
		int top;
	public:
		Stack(int n=10);
		void push(char );
		void pop();
		bool empty();
		char Top();
};
class Bracket{
	public:
		char s_brack;
		char m_brack;
		char l_brack;
	Bracket();
};
int main(){
	string c;
	cout<<"Enter equation to check if brackets are balanced : ";
	getline(cin,c);
	int size=c.length()+1;
	char* ch=new char[size+1];
	strcpy(ch,c.c_str());
	Stack s(size);
	Bracket b;
//	char ch[size];
//	string c;
//	cin.ignore();
//	getline(cin,c);
//	ch=new char[c.length()];
//	cin.getline(ch,size);
	int i;
	for(i=0;i<size&&ch[i]!='\n';i++){
		switch(ch[i]){
		case '{':
		case '[':
		case '(':
		{
		if(ch[i]=='(') s.push(b.s_brack);
		else if(ch[i]=='{') s.push(b.m_brack);// (({})))
		else s.push(b.l_brack);
		break;
		}
		case ')':
		case '}':
		case ']':
		{
			if(s.empty()||ch[i]!=s.Top())
			{
				cout<<"Unbalanced \n";
				exit(0);
			}
			else s.pop();
		break;
				}		
		default: continue;
	}
}
if(!s.empty()){
	cout<<"Unbalanced";
}
else cout<<"balanced";
}
Stack::Stack(int n){
	this->data=new char[n];
	this->size=n;
	top=-1;
}
void Stack::push(char c){
	top++;
	data[top]=c;
}
void Stack::pop(){
	top--;
}
bool Stack::empty(){
	return top==-1;
}
char Stack::Top(){
	return data[top];
}
Bracket::Bracket(){
	s_brack=')';
	m_brack='}';
	l_brack=']';
}
