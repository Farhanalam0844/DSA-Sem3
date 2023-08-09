#include<iostream>
using namespace std;
template<typename T>
class queue{
	private:
		T *data;
		int FRONT;
		int BACK;
		int n;
		int size;
	public:
		queue(int s=10){
			FRONT=BACK=0;
			n=0;
			size=s+1;
			data=new T[size];
		}
		queue(const queue<T> &t){
			data=NULL;
//			operator=(t);
		}
		void push(T val){
		if(isFull())	throw "Queue overflow";	
			data[BACK]=val;
			BACK=(BACK+1)%size;
			n++;
		}
		void pop(){
			if(isEmpty()) throw "Queue underflow";
			FRONT=(FRONT+1)%size;
			n--;
		}
		bool isEmpty(){
			return n==0;
		}
		bool isFull(){
			return n==size-1;
		}
		T front(){
			return data[FRONT];
		}
		T back(){
			return data[BACK];
		}
		friend ostream& operator<<(ostream& c,const queue<T> q){
			int f=q.FRONT;
			int b=q.BACK;
			c<<"[ ";
			while(f!=b){
				c<<q.data[f]<<" ";
				f=(f+1)%q.size;
			}
			c<<"] \n";
		}
//		queue operator=(const queue<T> src){
//			if(data!=NULL){
//				data =NULL;
//			}
//			FRONT=src.FRONT;
//			BACK=src.BACK;
//			n=0;
//			size=src.size;
//			data=new T[size];
//			while(FRONT!=BACK){
//				push(src.FRONT);
//				
//			}
//		}
};
int main(){
	queue <int>q;
	try{
	q.push(4);
	q.push(3);
	q.push(2);
	//q.push(2);
	q.push(1);
	cout<<q;
//	q.push(2);
//	q.push(2);
//	q.push(2);
//	q.push(2);
//	q.push(2);
//	q.push(2);
	cout<<q;
	q.pop();
	cout<<q;
	q.pop();
	cout<<q;
//	q.pop();
}
catch(const char* s){
	cout<<s<<endl;
}
	queue<int> p;
	try{
	p.push(1);
	p.push(2);
	p.push(4);
	cout<<p;
//	q=p;
	cout<<q;
}
catch(const char* s){
	cout<<s<<endl;
}
}
