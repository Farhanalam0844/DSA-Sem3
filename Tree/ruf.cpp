#include<iostream>
//#include<list>
//#include<stack>
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
	forward_list() {
		FRONT = NULL;
		n = 0;
	}
//	forward_list(const forward_list &r) {
//		clear();
//		node* temp = r.FRONT;
//		node* temp2 = temp;
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
	void push_front(int val) {
		node* temp = FRONT;
		node* temp1 = new node;
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
		node* temp = FRONT;
		FRONT = FRONT->next;
		delete temp;
		n--;
	}
	void clear() {
		node* temp = FRONT;
		while (temp != NULL) {
			pop_front();
		}
		n = 0;
	}
	bool full() {
		node* temp = new node;
		if (temp == NULL) {
			return true;
		}
		return false;
	}
	int size() {
		return n;
	}
	void insert_after(int ind, int val) {
		int i = 0;
		node* temp = FRONT;
		while (temp->next != NULL && i <= val){
			temp = temp->next;
		i++;
	}
		//temp = FRONT;
	node* t = new node;
	t->data = val;
	t->next = temp->next;
	temp->next = t;
	n++;
}
//	void operator=(const forward_list& r) {
//		if (!isempty()) clear();
//		clear();
//		node* temp = r->FRONT;
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
	friend ostream& operator<<(ostream& c, const forward_list s) {
		node* temp = s.FRONT;
		c << "[ ";
		while (temp != NULL) {
			c << temp->data << " ";
			temp = temp->next;
		}
		cout << "]\n";
		return c;
	}
	node* Front(){
		return FRONT;
	}
};
class hash_table {
private:
	forward_list* l;
	int size;
	int hash(int& key) {
		return key % size ;
	}
	bool Find(forward_list &t,int val){
		node* temp=t.Front();
		while(temp!=NULL){
			if(temp->data==val) return true;
			temp=temp->next;
		}
		return false;	
	}
		void Remove(forward_list& t,int val) {
		node* temp = t.Front();
		if (temp->data == val) t.pop_front();
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
	hash_table(int size=13) {
		l = new forward_list[size];
		this->size = size;
	}
	void insert(int val) {
		int ind = hash(val);
		l[ind].push_front(val);
	}
	bool find(int val) {
		int ind = hash(val);
			return Find(l[ind],val);
	}
	void remove(int val) {
		int ind = hash(val);
		Remove(l[ind],val);
	}
	void display(){
		int i=0;
		for(i=0;i<size;i++){
			cout<<l[i];
		}
	}
};
int main() {
	hash_table h;
	h.insert(5);
	h.insert(15);
	h.insert(27);
	h.insert(97);
	h.insert(44);
	h.insert(13);
	h.insert(590);
	h.display();
	if(h.find(44)){
		cout<<"Found 44"<<endl;
	}
	else cout<<"Not found \n";
		if(h.find(100)){
		cout<<"Found 100\n";
	}
	else cout<<"Not found 100\n";
	h.remove(44);
	h.display();
}
