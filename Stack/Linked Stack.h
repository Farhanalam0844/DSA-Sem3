template<typename T>
struct node{
	T data;
	node* next;
};
template<typename T>
class Stack{
	private:
		node<T>* top_ptr;
	public:
		Stack();
		void push(T val);
		T pop();
		T top()const;
		bool isEmpty() const;
		void makeEmpty();
//		Stack(const Stack<T>& right);
//		bool operator==(const Stack<T>& right);
//		bool operator<(const Stack<T>& right);
//		bool operator>(const Stack<T>& right);
//		friend ostream& operator<<(ostream& c,const Stack& right);
		char* infinix_to_postfix(const char *c);		
};
