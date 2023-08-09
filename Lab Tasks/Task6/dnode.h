#pragma once
template<typename T>
struct dnode {
	T data;
	dnode<T>* next;
	dnode<T>* prev;
};