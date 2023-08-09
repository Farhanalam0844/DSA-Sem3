#include<iostream>
using namespace std;

struct node {
	node* next;
	int data;
};
class forward_list {
private:
	node* FRONT;
	int n;
public:
	forward_list() {
		FRONT = NULL;
		n = 0;
	}
	void push_front(int val) {
		node* temp;
		temp = new node;
		if (temp == NULL) {
			throw "forward list overflow\n";
		}
		temp->data = val;
		temp->next = FRONT;
		FRONT = temp;
		n++;
	}
	int pop_front() {
		node* temp = FRONT;
		FRONT = FRONT->next;
		int v = temp->data;
		delete temp;
		n--;
		return v;
	}
	bool empty() {
		return FRONT == NULL;
	}
	void clear() {
		while (FRONT != NULL) {
			cout << pop_front() << " ";
		}cout << "\n";
	
	}
	class iterator {
	private:
		node* ptr;
		friend forward_list;
	public:
		bool operator!=(const iterator& right) {
			return ptr != right.ptr;
		}
		bool operator==(const iterator& right) {
			return ptr == right.ptr;
		}
	//	iterator operator=(const iterator& right) {
	//		iterator it;
	//		it.ptr = right.ptr;
	//		return it;
		//}
		int operator*() {
			return ptr->data;
		}
		node* operator->() {
			return this->ptr;
		}
		void operator++() {
			this->ptr = ptr->next;
		}
		iterator operator++(int) {
			iterator it;
			it.ptr = ptr;
			this->ptr = ptr->next;
			return it;
		}
		
	};

	iterator begin() {
		iterator it;
		it.ptr = this->FRONT;
		return it;
	}
	iterator end() {
		iterator it;
		it.ptr = NULL;
		return it;
	}
};
int main() {

	forward_list l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(5);
	forward_list::iterator it;
	it = l.begin();
	for (it = l.begin(); it != l.end(); it++) {
		cout << *it<<" ";
	}
	return 0;
}