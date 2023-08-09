#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
bool is_palindrome(string str) {
	stack <int>s;
	queue <int>q;
	int i = 0;
	for (i = 0; i < str.length(); i++)
	{
		s.push(str[i]);
		q.push(str[i]);
	}
	while (!s.empty())
	{
		if (s.top() != q.front()) {
			return false;
		}
		s.pop();
		q.pop();
	}
	return true;
}
int main() {
	string s;
	cout << "Enter the word : ";
	getline(cin, s);
	if (is_palindrome(s)) {
		cout << "Word is Palindrome\n";
	}
	else cout << "Word is not a Palindrome\n";

}