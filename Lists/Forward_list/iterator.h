
#pragma once
#include"node.h"
#include"forward_list.h"

class iterator {
private:
	node* ptr;
	friend class forward_list;
public:
	iterator();
	
};