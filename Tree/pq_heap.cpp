#include<iostream>
using namespace std;

struct heap
{
	int *data;
	int size;
	void heapify_up(int first,int last){
		int parent=(last-1)/2;
		if(last>0){
			if(data[parent]<data[last]){
				swap(data[parent],data[last]);
				heapify_up(first,parent);
			}
		}
	}
	void heapify_down(int first,int last){
		int l=first*2+1;
		int max;
		int r=first*2+2;
		if(l<=last){
			if(l==last) max=l;
			else {
				data[l]>data[r]?max=l:max=r;
			}
		
		if(data[max]>data[first]){
			swap(data[max],data[first]);
			heapify_down(max,last);
		}
	}
}
};
class pq_heap{
	private:
		heap p;
		int n;
	public:
		pq_heap(const int& n=10){
			p.data=new int[n];
			p.size=n;
			this->n=0;
		}
		void push(int val){
			p.data[n]=val;
			p.heapify_up(0,n);
			n++;
		}
		void pop(){
			p.data[0]=p.data[n-1];
			n--;
			p.heapify_down(0,n-1);
			
		}
		void display(){
			int i=0;
			for(i=0;i<=n-1;i++){
				cout<<i<<" "<<p.data[i]<<endl;
			}
		}
};
int main(){
	pq_heap p;
	p.push(1);
	p.push(10);
p.push(18);
p.push(13);
p.push(11);
p.push(61);
p.push(78);
p.push(3);
p.display();
p.pop();
p.display();
// arr[2,4,,8,,2.3.23.3]

}
