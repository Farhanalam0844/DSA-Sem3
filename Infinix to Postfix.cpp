#include<iostream>
#include<stack>
using namespace std;
int prec(char s){
	if(s=='+'||s=='-') return 0;
	else if(s=='*'||s=='/') return 1;
//	return -1;
	
}
bool not_ch(char ch){
	if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/') return true;
	return false;
}
string infinix_to_outfix(string s,int len){
	string output=" ";
	stack <char>t;
		int i=0;
		for(i=0;i<len;i++){
			
			if(not_ch(s[i])) {
				output+=s[i];
			}
			else if(t.empty()||(prec(s[i])>prec(t.top()))) t.push(s[i]);
			
//			else if{
//				if(prec(s[i])>prec(t.top())){
//					t.push(s[i]);
//				}
//				else{
//			 if((s[i]=='+'&&t.top()=='-')||(s[i]=='-'&&t.top()=='+')){
//					
//				}}
			//}
			else if(prec(s[i])<=prec(t.top())){
			while(prec(s[i])<=prec(t.top())&&(!t.empty())){
				output+=t.top();
				t.pop();
			}
			t.push(s[i]);
		}
}
	//	cout<<output<<"\t"<<t.top()<<endl;
		while(!t.empty()){
			output+=t.top();
			t.pop();
		}
		return output;
	}
int main(){
	string s;
	cout<<"Enter equation : ";
	getline(cin,s);
	int len=s.length();
	string t;
	t=infinix_to_outfix(s,len);
	cout<<t;
}
