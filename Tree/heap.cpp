#include<iostream>
using namespace std;

struct heap {
	int* data;
	int size;
	void heapify_up( int first,int last) {
		int parent = (last - 1) / 2;
		if (last >0) {
			if (data[last] > data[parent]) {
				swap(data[last], data[parent]);
			}
			heapify_up(first, parent);
		}
		return;
	}
	void heapify_down(int first, int last) {
		int l, r, max;
		l = first * 2 + 1;
		r = first * 2 + 2;
		if (l <= last) {
			if (l == last) max = l;
			else {
				data[l] > data[r] ? max = l : max = r;
			}
		}
		if (data[first] < data[max]) {
			swap(data[first], data[max]);
			heapify_down(max, last);
		}
	}
};
//class tree {
//private:
//	heap h;
//	int n;
//public:
//	tree(const int n = 30) {
//		h.size = n;
//		this->n = 0;
//		h.data = new int[h.size];
//	}
//	void insert(const int& val) {
//		h.data[n] = val;
//		h.heapify(0, n);
//		n++;
//	}
//	void display() {
//		int i = 0;
//		for (i = 0; i < h.size; i++) {
//			cout << h.data[i]<<" ";
//		}
//		cout << endl;
//	}
//};
class pq_heap {
private:
	heap h;
	int n;
public:
	pq_heap(const int& n = 30) {
		h.size = n;
		h.data = new int[h.size];
		this->n = 0;
	}
	void push(int val) {
		h.data[n] = val;
		h.heapify_up(0, n);
		n++;
	}
	int pop() {
		int val = h.data[n-1];
		h.data[0] = h.data[n-1];
		n--;
		h.heapify_down(0, n-1);
		return val;
	}
	bool empty() {
		return n == 0;
	}
};
int main() {
//	tree s(8);
//	s.insert(1);
//	s.insert(61);
//	s.insert(12);
//	s.insert(19);
//	s.insert(21);
//	s.insert(14);
//	s.insert(100);
//	s.insert(0);
//	s.display();
//	cout << "Enter size : ";
//	cin >> size;
//	for (int i = 0; i < size; i++) {
		//cout << "Enter value : ";
	//	cin >> s.data[i];
	//	s.data[i] = i * i;
	//}
	
	
//	int last=floor(size/2);
//	int parent = (last - 1) / 2;
	pq_heap h(5);
	h.push(5);
	h.push(0);
	h.push(35);
	h.push(54);
	h.push(15);
		while (!h.empty()) {
			cout << h.pop() << " ";
		}
}