#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};
class list {
private:
	node* FRONT;
	node* BACK;
	int n;
public:
	list() {
		FRONT = BACK = NULL;
		n = 0;
	}
	void push_front(int val) {
		node* temp;
		temp = new node;
		if (temp == NULL) {
			throw "forward list overflow\n";
		}
		temp->data = val;
		temp->prev = NULL;
		temp->next = FRONT;
		if (FRONT == NULL)  BACK = temp;
		else FRONT->prev = temp;
		FRONT = temp;
		n++;
	}
	int pop_front() {
		node* temp = FRONT;
		FRONT = FRONT->next;
		FRONT->prev = NULL;
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

	void push_back(int val) {
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		temp->prev = BACK;
		if (BACK == NULL) FRONT = temp;
		else BACK->next = temp;
		
		BACK = temp;
		n++;
	}
	void pop_back() {
		node* temp = BACK;
		BACK = BACK->prev;
		BACK->next = NULL;
		delete temp;
		n--;
	}
	
	class reverse_iterator {
	private:
		node* ptr;
		friend class list;
	public:
		reverse_iterator() {
			ptr = NULL;
		}
		bool operator!=(const reverse_iterator& right) {
			return ptr != right.ptr;
		}
		bool operator==(const reverse_iterator& right) {
			return ptr == right.ptr;
		}
		//	reverse_iterator operator=(const reverse_iterator& right) {
		//		reverse_iterator it;
		//		it.ptr = right.ptr;
		//		return it;
		//	}
		int operator*() {
			return this->ptr->data;
		}
	//	node* operator->() {
	//		return this->ptr;
	//	}
		void operator++() {
			this->ptr = ptr->prev;
		}
		void operator--() {
			this->ptr = ptr->next;
		}
		reverse_iterator operator++(int) {
			reverse_iterator it;
			it.ptr = ptr;
			this->ptr = ptr->prev;
			return it;
		}
	};

	reverse_iterator rbegin() {
		reverse_iterator it;
		it.ptr = BACK;
		return it;
	}
	reverse_iterator rend() {
		reverse_iterator it;
		it.ptr = NULL;
		return it;
	}
	void display() {
		node* temp = FRONT;
		cout << "Forward : [ ";
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "]\n";
	}
	void insert_before(const reverse_iterator& it, int val) {
		if (it.ptr == FRONT) push_front(val);
		node* temp = new node;
		temp->data = val;
		it.ptr->prev->next = temp;
		temp->prev = it.ptr->prev;
		temp->next = it.ptr;
		it.ptr->prev = temp;
		n++;
	}
	void erase(const reverse_iterator& it) {
		if (it.ptr == FRONT) pop_front();
		else if (it.ptr == BACK) pop_back();
		else
		{
			node* temp = it.ptr;
			it.ptr->prev->next = it.ptr->next;
			it.ptr->next->prev = it.ptr->prev;
			delete temp;
			n--;
		}
	}
	void remove(int val) {
		node* temp = FRONT->next;
		if (val == FRONT->data) pop_front();
		else if (val == BACK->data) pop_front();
		else {
			
			while (temp->next != NULL) {
				if (temp->data == val) {
					node* t = temp;
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					delete t;
					n--;
					return;
				}
				else
				temp = temp->next;
			}
		}
	}
};

int main() {
	list l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(6);
	l.push_front(10);
	l.push_front(15);
	l.push_back(22);
	l.push_back(42);
	l.push_back(50);
	l.push_back(89);
	l.display();
	list::reverse_iterator it;
	cout << "Reverse : [ ";
	for (it = l.rbegin(); it != l.rend(); ++it) {
		cout << *it << " ";
	}
	cout << "]\n";
	it = l.rbegin();
	for (int i = 1; i < 3; i++) {
		++it;
	}
	cout << "Entering 0 before last 3rd index \n";
	l.insert_before(it, 0);
	l.display();
	cout << "Reverse : [ ";
	for (it = l.rbegin(); it != l.rend(); ++it) {
		cout << *it << " ";
	}
	cout << "]\n";
	cout << "After deleting 2nd last index \n";
	it = l.rbegin();
	++it; 
	l.erase(it);
	l.display();
	cout << "Reverse : [ ";
	for (it = l.rbegin(); it != l.rend(); ++it) {
		cout << *it << " ";
	}
	cout << "]\n";
	cout << "After deleting 0 value \n";
	l.remove(0);
	l.display();
	cout << "Reverse : [ ";
	for (it = l.rbegin(); it != l.rend(); ++it) {
		cout << *it << " ";
	}
	cout << "]\n";
}