#include<iostream>
#include<list>
using namespace std;
template<typename T>
class hash_table {
private:
	list<T>* l;
	int size;
	int hash(int& key) {
		return key % size ;
	}
	bool Find(list<T>* l,int val) {
		typename<typename T>
		list<T>::iterator<T> it;
		it = l->begin();
		while (it!=l->end()) {
			if (it.ptr->data == val) return true;
			++it;
		}
		return false;
	}
public:
	hash_table(int &size=10) {
		l = new list<T>[size];
		this->size = size;
	}
	void insert(int val) {
		int ind = hash(val);
		l[ind]->push(val);
	}
	bool find(int val) {
		int ind = hash(val)
			return Find(l[ind],val)
	}
	void remove(int val) {
		int ind = hash(val);
		return l[ind]->remove(val);
	}
};
int main() {
	hash_table <int> h(10);
}