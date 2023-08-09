#pragma once
#include"node.h"
#include"iterator.h"

class forward_list {
private:
	node* FRONT;
	int n;
public:
	class iterator;
	forward_list();
	forward_list(const forward_list& right);
	iterator begin();
	const iterator cbegin();
	iterator end();
	const iterator cend();
	void remove(const int& val);
	void reverse();
	void unique();
	void sort();
	void merge(const forward_list& right);
	bool empty()const;
	int max_size()const;
	void clear();
	void push_front(int val);
	void insert_after(const iterator* it, int val);
	void erase_after(const iterator* it);//int val 5
	void swap(const forward_list* right);
	int pop_front();
	bool operator==(const forward_list & right);
	bool operator!=(const forward_list& right);
	bool operator<=(const forward_list& right);
	bool operator>=(const forward_list& right);
	bool operator>(const forward_list& right);
	bool operator<(const forward_list& right);
	void operator=(const forward_list& right);
	friend void display(forward_list& r);
	~forward_list();

};