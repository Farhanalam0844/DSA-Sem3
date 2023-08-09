#include "dnode.h"
#include<iostream>
using namespace std;

template<typename T>
class list {
private:
    dnode<T> *FRONT;
    dnode<T> *BACK;
    int n;
public:
    list() {
        FRONT = BACK = NULL;
        n = 0;        
    }

    list(const list &src) {
        FRONT = BACK = NULL;
        operator=(src);
    }

    ~list() {
        clear();
    }
//	void delete_val(T val){
//		dnode<T>* temp_f=FRONT;
//		dnode<T>* temp_b=BACK;
//		if(temp_f->data==val){
//			dnode<T>* t=temp_f;
//			temp_f=temp_f->next;
//			temp_f->prev=NULL;
//			delete t;
//		}
//		while(temp_f->next!=NULL){
//			if(temp_f->next->data==val){
//			dnode<T>* t=temp_f->next;
//			temp_f->next=t->next;
//			
//			temp_f->next->prev=temp_f;
//			delete t;
//			}
//		}
//	}
    void push_front(const T &val) {
        dnode<T> *temp;
        temp = new dnode<T>;

        if (temp == NULL) {
            throw("List Overflow!");
        }

        temp->data = val;
        temp->prev = NULL;

        if (FRONT == NULL) //list is empty
        {
            FRONT = BACK = temp;
            temp->next = NULL;
        } else {
            temp->next = FRONT;
            FRONT->prev = temp;
            FRONT = temp;
        }
        n++;
    }

    void push_back(const T &val) {
        dnode<T> *temp;
        temp = new dnode<T>;
        temp->data = val;
        temp->next = NULL;
        if (BACK == NULL) {
            FRONT = BACK = temp;
            temp->prev = NULL;
        } else {
            temp->prev = BACK;
            BACK->next = temp;
            BACK = temp;
        }
        n++;
    }

    T front() const {
        if (FRONT == NULL)
            throw("List Underflow!");
        return FRONT->data;
    }

    T back() const {
        if (FRONT == NULL)
            throw("List Underflow!");
        return BACK->data;
    }

    void pop_front()  {
        if (FRONT == NULL)
            throw("List Underflow!");

        dnode<T> *temp;

        temp = FRONT;

        FRONT = FRONT->next;

        delete temp;

        if (FRONT != NULL) {
            FRONT->prev = NULL;
        } else {
            BACK = NULL;
        }
        n--;
    }

    // void pop_front_no_temp()  {
    //     if (FRONT == NULL)
    //         throw("List Underflow!");

    //     if (FRONT == BACK) {
    //         delete FRONT;
    //         FRONT = BACK = NULL;
    //     } else {
    //         FRONT = FRONT->next;
    //         delete FRONT->prev;
    //         FRONT->prev = NULL;
    //     }
    
    // }

    void pop_back()  {
        if (FRONT == NULL)
            throw("List Underflow!");

        dnode<T> *temp;
        temp = BACK;

        BACK = BACK->prev;

        delete temp;

        if (BACK == NULL) {
            FRONT = NULL;
        } else {
            BACK->next = NULL;
        }
        n--;
    }

    bool empty() const {
        // return FRONT == NULL;
        if (FRONT == NULL)
            return true;
        else
            return false;
    }

    bool full() const {
        dnode<T> *temp;
        temp = new dnode<T>;
        if (temp == NULL) {
            return true;
        } else {
            delete temp;
            return false;
        }
    }

    void clear() {
        while(!empty()) {
            pop_front();
        }
        // n = 0;
    }

    bool find(T &val) const {
        dnode<T> *temp;
        temp = FRONT;
        while (temp != NULL) {
            if (temp->data == val) {
                val = temp->data; //copy satellite data. Only useful for stuctures and objects
                return true;
            } else {
                temp = temp->next;
            }
        }
        return false;
    }

    int size() const {
        return n;
    }
    void display() {
        dnode<T>* temp = this->FRONT;
        cout << "[ ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "]\n";
    }
	void unique() {
            dnode<T>* temp_f=FRONT->next;
            dnode<T>* temp_b=FRONT;
            if(temp_b->data==temp_b->next->data){
            	
            	FRONT=temp_b->next;
            	temp_b->prev=NULL;
            	delete temp_b;
            
			}
			
            while (temp_f != NULL) {
                if (temp_f->data == temp_b->data) {
                   // cout << 1;
                   dnode<T>* t=temp_b;
				    temp_f->prev=temp_b->prev;
                    temp_b->prev->next=temp_f;
                 //   cout << t->data;
                  //  temp_b->next = t->next;
                    //temp_b = temp;
                    //temp = temp->next;
                 //   temp->next = temp->next->next->next;
                  //  temp = temp->next->next;
      //              cout << temp->data;
//cout << temp_p->data;
                    delete t;
                }
                else {
      //              cout << "t " << temp->data;
                    temp_b = temp_f;
                    temp_f = temp_f->next;
                }
            }
         
        }
	void reverse(){
//		int val=2;
   		dnode<T>* temp_f=FRONT;
   		dnode<T>* t=FRONT;
   		dnode<T>* temp_b=BACK;
   		while(temp_f->next!=NULL){
   			T val=temp_f->next->data;
   			push_front(val);
   			  temp_f=temp_f->next;
//  			val++;
   		//	dnode<T>* t=new dnode<T>;
			  // t=temp_f->next;
		//	   temp_f->next=t->next;
		//	   t->next->prev=temp_f;
		//	   delete t;
   		//	delete_val(val);
   		//	temp_f=temp_f->next;
  // delete t;

		   }
		   temp_f=FRONT;
	while(temp_f!=t){
		pop_back();
		temp_f=temp_f->next;
	}	   
		   }	
//		void swap(dnode<T>* f,dnode<T>* b){
//			dnode<T>* temp;
//			temp=f;
//			f->next=b->next;
//			f->prev=b->prev;
//			b->next=temp->next;
//			b->prev=temp->prev;
//		}
dnode<T>* swap_min_max(dnode<T>* H,dnode<T>* B) {
	dnode<T>*  temp_f = H;
	if (temp_f->next == NULL) exit(0);
//	dnode<T>*  min = temp;
	dnode<T>*  max = temp_f;
//	dnode<T>*  temp_p = NULL;
//	dnode<T>*  min_p = NULL;
//	dnode<T>*  max_p = NULL;
	while (temp_f != B) {
		if (temp_f->data > max->data) {
			max = temp_f;
//			max_p = temp_p;
		}
//		if (temp->data < min->data) {
//			min = temp;
//			min_p = temp_p;
//		}
		temp_f = temp_f->next;
//		temp = temp->next;

	}
	/*
	node *t1;
	node* t2;
	t2 = max;
	t1 = min;
	min_p->next = max;
	max->next = t1->next;
	max_p->next = t1;
	t1->next = max->next;
	*/
//	dnode<T>*  min_next = min->next;
//	min->next = max->next;
//	min->prev=max->pre
//	max->next = min_next;
//	min_p->next = max;
//	max_p->next = min;
	return max;
}  
void merge(list * s){
	dnode<T>* temp=this->FRONT;
	dnode<T>* temp2=s->FRONT;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=temp2;
	this->sort();
} 
void sort() {
	cout<<"Sort is under construction \n";
       
        dnode<T>* temp_f = FRONT;
        dnode<T>* temp_b = BACK;

        while (temp_f->next != NULL) {
        dnode<T>* max=	swap_min_max(temp_f,temp_b);
        temp_f=temp_f->next;
        this->push_back(max->data);
        
		}
		}
//		while(temp_f!=NULL){
//			temp_b=temp_f;
//			while(temp_b!=NULL){
//				if(temp_b->data>temp_b->next->data){
//					swap(temp_b->next,temp_b);
//					temp_b=temp_b->next;
//				}
//				temp_f=temp_f->next;
//			}
//		}
//		
//	}	   
};


