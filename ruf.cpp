#include<iostream>
#include<list>
#include<queue>
using namespace std;
int main(){
list<int> q,r;
q.push_front(1);
q.push_front(2);
r.push_front(2);
r.push_front(3);
cout<<q.next + r.next;

}
