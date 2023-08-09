#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
class forward_list {
private:
	node* FRONT;
	int n;
	
public:
	class iterator {
	private:
		node* ptr;
		friend class forward_list;
	public:
		iterator() {
			ptr = NULL;
		}
		bool operator==(const iterator& right) {
			return ptr->data == right.ptr->data;
		}
		bool operator!=(const iterator& right) {
			return ptr != right.ptr;
		}
		bool operator>(const iterator& right) {
			return ptr->data > right.ptr->data;
		}
		bool operator<(const iterator& right) {
			return ptr->data < right.ptr->data;
		}
		void operator++() {
			ptr=ptr->next;
		}
		int operator*() {
			return this->ptr->data;
		}
		iterator operator++(int) {
			iterator it;
			it.ptr = ptr;
			ptr=ptr->next;
			return it;
		}

	};
	forward_list() {
		FRONT = NULL;
		n = 0;
	}
	void push_front(int val) {
		node* temp = new node;
		temp->data = val;
		temp->next = FRONT;
		FRONT = temp;
		n++;
	}
	int pop_front() {
		if (FRONT == NULL) throw"List underflow \n";
		node* t = FRONT;
		int val = FRONT->data;
		FRONT = FRONT->next;
		delete t;
		n--;
		return val;
	}
	bool empty() {
		return FRONT == NULL;
	}
	iterator begin() {
		iterator it;
		it.ptr = FRONT;
		return it;
	}
	iterator end() {
		iterator it;
	
		it.ptr = NULL;
		return it;
	}
	void insert_after(iterator* it, int val) {
		if (it->ptr == FRONT) push_front(val);
		else {
			node* temp = new node;
			temp->data = val;
			temp->next = it->ptr->next;
			it->ptr->next = temp;
		}
	}
	void remove(int val) {
		node* temp = FRONT;
		if (temp->data == val) pop_front();
		else {
			while (temp->next != NULL) {
				if (temp->next->data == val) {
					node* t = temp->next;
					temp->next = t->next;
					delete t;
					return;
				}
			}
		}
	}
	void erase(iterator& it) {
		if (it.ptr == FRONT) pop_front();
		else {
			node* t = it.ptr->next;
			it.ptr->next = t->next;
			delete t;
		}
	}
	void display() {
		node* temp = FRONT;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main() {
	forward_list f;
	forward_list::iterator it;
	f.push_front(19);
	f.push_front(29);
	f.push_front(15);
	f.push_front(59);
	f.push_front(90);
	f.push_front(190);
	f.push_front(9);
	f.push_front(9);
	f.display();
	cout << "[ ";

	for (it = f.begin(); it != f.end(); ++it) {
		cout << *it << " ";
	}
	cout << "]" << endl;
	int i;
	it = f.begin();
	for (i = 1; i < 4; i++) ++it;
	cout << "After adding 200 after 4th index : \n";
	f.insert_after(&it, 200);
	cout << "[ ";

	for (it = f.begin(); it != f.end(); ++it) {
		cout << *it << " ";
	}
	cout << "]" << endl;
	it = f.begin();
	cout << "After deleting first index : ";
	f.erase(it);
	cout << "[ ";
	for (it = f.begin(); it != f.end(); ++it) {
		cout << *it << " ";
	}
	cout <<"]"<<endl;

	cout << "After removing 190 ";
	f.remove(190);
	cout << "[ ";
	for (it = f.begin(); it != f.end(); ++it) {
		cout << *it << " ";
	}
	cout << "]" << endl;
}