#include<iostream>
#include<stack>
using namespace std;
template<typename T>
struct node {
	T data;
	node<T>* next;
};
template<typename T>
class forward_list {
private:
	node<T>* FRONT;
	int n;
public:
	forward_list() {
		FRONT = NULL;
		n = 0;
	}
//	forward_list(const forward_list &r) {
//		clear();
//		node<T>* temp = r.FRONT;
//		node<T>* temp2 = temp;
//		while (temp!=NULL)
//		{
//			temp2 = temp;
//			while (temp2->next!=NULL)
//			{
//				temp2 = temp2->next;
//			}
//			push_front(temp->data);
//		//	temp = temp->next;
//		}
//	}
	void push_front(T val) {
		node<T>* temp = FRONT;
		node<T>* temp1 = new node<T>;
		if (temp1 == NULL) throw "List overflow ";
		temp1->data = val;
		temp1->next = temp;
		FRONT = temp1;
		n++;
	}
	bool isempty() const{
		return FRONT == NULL;
	}
	void pop_front() {
		node<T>* temp = FRONT;
		FRONT = FRONT->next;
		delete temp;
		n--;
	}
	void clear() {
		node<T>* temp = FRONT;
		while (temp != NULL) {
			pop_front();
		}
		n = 0;
	}
	bool full() {
		node<T>* temp = new node;
		if (temp == NULL) {
			return true;
		}
		return false;
	}
	int size() {
		return n;
	}
	void insert_after(int ind, T val) {
		int i = 0;
		node<T>* temp = FRONT;
		while (temp->next != NULL && i <= val){
			temp = temp->next;
		i++;
	}
		//temp = FRONT;
	node<T>* t = new node<T>;
	t->data = val;
	t->next = temp->next;
	temp->next = t;
	n++;
}
//	void operator=(const forward_list& r) {
//		if (!isempty()) clear();
//		clear();
//		node<T>* temp = r->FRONT;
//		stack<int> s;
//		while (temp != NULL) {
//			s.push(temp->data);
//			temp = temp->next;
//		}
//		while (!s.empty()) {
//			push_front(s.top());
//			s.pop();
//
//		}
//	}
	friend ostream& operator<<(ostream& c, const forward_list<T> s) {
		node<T>* temp = s.FRONT;
		c << "[ ";
		while (temp != NULL) {
			c << temp->data << " ";
			temp = temp->next;
		}
		cout << "]\n";
		return c;
	}
};
int main() {
	forward_list <int>l;
	l.push_front(4);
	l.push_front(3);
	l.push_front(2);
	l.push_front(1);
	cout << l;
//	forward_list <int>l2 = l;
//	cout << l2;
	l.insert_after(2, 0);
	cout << l;
}