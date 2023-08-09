#include<iostream>
#include<queue>
using namespace std;
struct tnode {
	int data;
	tnode* left;
	tnode* right;
};
class BST {
private:
	tnode* root;
	int n;
public:
	BST() {
		root = NULL;
		n = 0;
	}
	void insert(int val) {
		tnode* temp = root;
        tnode* parent = NULL;
        tnode* t = new tnode;
        t->data = val;
        t->left = t->right = NULL;
        if (root == NULL) { root = t; n++; return; }
		while (temp!=NULL) {
            parent = temp;
			if (temp->data > val) temp = temp->left;
			else if (temp->data < val) temp = temp->right;
			else return;
		}
		

  //     if (temp->left == NULL && temp->right == NULL) {
  //          if (val > temp->data) temp->right = t;
  //          else if (val < temp->data) temp->left = t;
  //  }
    if (parent->data>val) parent->left = t;
    else if (parent->data<val) parent->right = t;
       n++;
	}
   
    void visualize() {
        if (root == nullptr) {
            std::cout << "Tree is empty!" << std::endl;
            return;
        }

        // Perform level-order traversal using a queue
        std::queue<tnode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            // Print nodes at the current level with appropriate spacing
            for (int i = 0; i < levelSize; i++) {
                tnode* currNode = q.front();
                q.pop();

                if (i == 0)
                    std::cout << currNode->data;
                else
                    std::cout << " " << currNode->data;

                // Enqueue left and right children, if they exist
                if (currNode->left)
                    q.push(currNode->left);
                if (currNode->right)
                    q.push(currNode->right);
            }

            std::cout << std::endl;
        }
    }
    bool find(int val) {
        tnode* temp = root;
        while (temp != NULL) {
            if (temp->data == val) return true;
            else if (temp->data > val) temp = temp->left;
            else temp = temp->right;
        }
        return false;
    }
    bool empty() const{
        return root == NULL;
    }
    int height() {
        tnode* temp = root;
        int l,r;
        l = r = 0;
        while (temp != NULL) {
            if (temp->left == NULL && temp->right != NULL) temp = temp->right;
            else   temp = temp->left;
            l++;
        }
        temp = root;
        while (temp != NULL) {
            if (temp->left != NULL && temp->right == NULL) temp = temp->left;
            else
            temp = temp->right;
            r++;
        }
        return l > r ? l: r;
    }
    int leafs() {
        tnode* temp = root;
        return 0;
    }
};
int main() {
    BST t;
    t.insert(1);
    t.insert(8);
    t.insert(4);
    t.insert(0);
    t.insert(-10);
    t.insert(-5);
    t.visualize();
    if (t.find(8)) {
        cout << "value found \n";
    }
    else cout << "value couldn't found \n";
    if (t.empty()) {
        cout << "BST is empty \n";
    }
    else cout << "BST is not empty \n";
    cout <<"Height is : "<< t.height() << endl;
    cout <<"Leafs are : "<< t.leafs() << endl;
}