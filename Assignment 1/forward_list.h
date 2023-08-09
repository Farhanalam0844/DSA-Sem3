#include "node.h"
#include <iostream>

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

    forward_list(const forward_list& src) {
        FRONT = NULL;
        operator=(src);
    }

    void operator=(const forward_list& src) {
        if (FRONT != NULL)
            clear();

        node<T>* temp_src, * nn, * temp;
        temp_src = src.FRONT;
        while (temp_src != NULL) {
            nn = new node<T>;
            nn->data = temp_src->data;
            nn->next = NULL;

            if (FRONT == NULL)
                FRONT = nn;
            else
                temp->next = nn;

            temp = nn;
            temp_src = temp_src->next;
        }
        n = src.n;
    }

    ~forward_list() {
        clear();
    }


    void push_front(const T& val) {
        node<T>* temp;
        temp = new node<T>;
        if (temp == NULL) {
            throw("List Overflow!");
        }
        temp->data = val;
        if (FRONT == NULL) //if list is empty
            temp->next = NULL;
        else                //if list is not empty
            temp->next = FRONT;
        FRONT = temp;
        n++;
    }

    T front() const {
        if (FRONT == NULL)
            throw("List Underflow!");
        return FRONT->data;
    }

    void pop_front() {
        if (FRONT == NULL) { //if (empty())
            throw("List Underflow!");
        }
        node<T>* temp;
        temp = FRONT;
        FRONT = FRONT->next;
        delete temp;
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
        node<T>* temp;
        temp = new node<T>;
        if (temp == NULL) {
            return true;
        }
        else {
            delete temp;
            return false;
        }
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
        // n = 0;
    }

    bool find(T& val) const {
        node<T>* temp;
        temp = FRONT;
        while (temp != NULL) {
            if (temp->data == val) {
                val = temp->data; //copy satellite data. Only useful in case of structures or objects.
                return true;
            }
            else {
                temp = temp->next;
            }
        }
        return false;
    }
    void display() {
        node<T>* temp = this->FRONT;
        std::cout << "[ ";
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "]\n";
    }
    int size() const {
        return n;
    }
        void reverse(){
        	node<T> *temp=this->FRONT;
            node<T>* temp_f = NULL;
            while (temp != NULL) {
                T val = temp->data;
                node<T>* temp2 =new node<T>;
                temp2->data = val;
                temp2->next = temp_f;
                temp_f = temp2;
                temp = temp->next;
                //pop_front();
                //       t.push_front(val);
                //       node<T>* t_node = temp;
                //       temp = temp->next;
                //       delete t_node;
            }
			this->FRONT = temp_f;
                       
   //     	node<T> *l_node=FRONT;
   //     	
   // 		l_node=temp;
   // 		temp=FRONT;
   // 		while(temp!=l_node){
   // 			T val=temp->data;
   //             node<T>* t = temp;
   //             temp = temp->next;
   //             delete t;
   //             push(val);
   // 		}
    	}
        void unique() {
            node<T>* temp=FRONT->next;
            node<T>* temp_p = FRONT;
            if(temp_p->data==temp->data){
            	node<T>* t=temp_p;
            	FRONT=temp;
            	delete t;
			}
            while (temp != NULL) {
                if (temp->data == temp_p->data) {
                   // std::cout << 1;
                    node<T>* t = new node<T>;
                    t=temp;
                 //   std::cout << t->data;
                    temp_p->next = t->next;
                    temp_p = temp;
                    temp = temp->next;
                 //   temp->next = temp->next->next->next;
                  //  temp = temp->next->next;
      //              cout << temp->data;
//cout << temp_p->data;
                    delete t;
                }
                else {
      //              cout << "t " << temp->data;
                    temp_p = temp;
                    temp = temp->next;
                }
            }
         
        }
void sort() {
    bool b = false;
    while (!b) {
        b = true;
        node<T>* temp_f = FRONT;
        node<T>* temp_p = NULL;

        while (temp_f->next != NULL) {
            if (temp_f->data > temp_f->next->data) {
                b = false;
                if (temp_p != NULL) {
                    temp_p->next = temp_f->next;
                }
                else {
                    FRONT = temp_f->next;
                }

                node<T>* temp = temp_f->next;
                temp_f->next = temp->next;
                temp->next = temp_f;

                temp_p = temp;
            }
            else {
                temp_p = temp_f;
                temp_f = temp_f->next;
            }
        }
    }
}
//    void sort() {
//    	node<T>* temp=FRONT;
//    	node<T>* temp2=FRONT;
//    	node<T>* swap_n=NULL;
//    	node<T>* swap_p=NULL;
//    	node<T>* pre=NULL;
//    	T val;
//    	while(temp!=NULL){
//    		swap_p=temp2;
//    		swap_n=temp2->next;
//    		temp2=temp->next;
//    		
//    		while(temp2!=NULL){
//    			if(temp2->data>temp->data){
//    			val=temp2->data;
//    			swap_p=temp2;
//    			swap_n=temp2->next;
//				temp2=temp2->next;
//				pre=swap_p;	
//				}
//				else
//			//	swap_p=swap_n;
//			//	swap_n=swap_n->next;
//				temp2=temp2->next;
//			}
//			
//			push_front(val);
//			//temp=temp->next;
//			pre->next=swap_n->next;
////			delete swap_n;
//		}
//    }
    
//            node<T>* temp = FRONT;
//            node<T>* temp_n=FRONT;
//            node<T>* min=NULL;
//            node<T>* temp_p=FRONT;
//            while(temp->next!=NULL){
//            		temp_n=temp->next;
//            	while(temp_n->next!=NULL){
//            		if(temp_n->data>temp_n->next->data){
//            			temp_p=temp_n;
//            			min=temp_n->next;
//					}
//					temp_n=temp_n->next;
//				}
//				cout<<min->data;
////				temp->next=min->next;
////				min->next=temp->next;
////				temp_p->next=temp;
//				temp=temp->next;
//				
//			}
//		}
    //        node<T>* temp_fp = FRONT;
    //        node<T>* temp_f = FRONT->next;
    //        node<T>* temp_p = FRONT;
    //        while (temp->next->next != NULL) {
    //            temp_fp = temp;
    //            temp_f = temp->next;
    //            while (temp_f->next != NULL) {
    //                if (temp_f->data < temp_p->data) {
    //                    cout << temp_p->data << temp_f->data << endl;
    //                    node<T>* t = temp_p;
    //                    t->next = temp_p->next;
    //                    temp_p->next = temp_f->next;
    //              //      t->next = temp_p->next;
    //                    temp_f->next = t->next;
    //                    temp_fp->next = temp_p;
    //              //      temp_p = temp_f;
    //                }
    //                else {
    //                    temp_f = temp_f->next;
    //                }
    //            }
    //            temp = temp->next;
    //        }
    //       
    //
//        node<T>* temp_last = FRONT;
//        while (temp_last->next != NULL) {
//             temp_last = temp_last->next;
//        }
//        T max = temp->data;
//        node<T>* tempp = NULL;
//        node<T>* tempf = NULL;
//        node<T>* temp2 = FRONT;
//        node<T>* temp_p = FRONT;
//        while (temp != NULL&&temp!=temp_last) {
//
//            temp2 = temp;
//            while (temp2->next != NULL) {
//                if (temp2->data > max) {
//                    max = temp2->data;
//                    cout << max;
//                    tempp = temp_p;
//                    tempf = temp2;
//                    temp_p = temp2;
//                    temp2 = temp2->next;
//                }
//                else {
//                    temp_p = temp2;
//                    temp2 = temp2->next;
//                }
//            }
//            tempp->next = tempf->next;
//          node<T>* t = tempf;
//         push_front(t->data);
//         delete t;
//            cout << "max " << max;
//            temp = temp->next;
        
        //}
	void merge( forward_list<T> *s) {
            node<T>* temp1=FRONT;
  //          this->sort();
//            s->sort();
//            node<T>* TEMP=new node<T>;
            node<T>* temp2=s->FRONT;
            while(temp1->next!=NULL){
            temp1=temp1->next;
		}
		temp1->next=temp2;
		this->sort();

//            T max;
//            while(temp1!=NULL){
//            	temp2=temp1->next;
//            	while(temp2!=NULL){
//            		if(temp2->data>temp1->data){
//            			max=temp2->data;
//					}
//					temp2=temp2->next;
//				}
//				t->push(a)
//            	t->next=temp1;
//            	t=t->next;
//            	t->next=temp2;
//            	t=t->next;
//            	temp1=temp1->next;
//            	temp2=temp2->next;
//			}
//            
//            while(temp1!=NULL&&temp2!=NULL){
//            	if(temp1->data<temp2->data){
//            		t->next=temp1;
//				}
//				else {
//				t->next=temp2;}
//				
//				temp1=temp1->next;
//				temp2=temp2->next;
//				t=t->next;
//			}
			
//			t=TEMP->next;
//			delete TEMP;
//			return t;
        }
};

