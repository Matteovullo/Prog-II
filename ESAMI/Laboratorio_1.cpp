#include<iostream>
using namespace std;

template<typename T>
class BSTNode {
	protected:
	
	T key;
	BSTNode<T>* left;
	BSTNode<T>* right;
	BSTNode<T>* parent;
	bool verbose = false;
	
	template<typename U>
	friend class BST;
	
	public: 
	
	BSTNode(T key, bool verbose=true) : key(key), verbose(verbose) {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	
	void setLeft(BSTNode<T>* left) {
		this->left = left;
	}
	
	void setRight(BSTNode<T>* right) {
		this->right = right;
	}
	
	void setParent(BSTNode<T>* parent) {
		this->parent = parent;
	}
	
	BSTNode<T>* getLeft() {
		return this->left;
	}
	
	BSTNode<T>* getRight() {
		return this->right;
	}
	
	BSTNode<T>* getParent() {
		return this->parent;
	}
	
	void setKey(T key) {
		this->key = key;
	}
	
	T getKey() {
		return this->key;
	}
	
	friend std::ostream& operator<<(std::ostream& out, BSTNode<T>& node) {
		if(node.verbose)
			out << "BSTNode@" << &node << " key=" << node.key << " - left=" << node.left << " right=" << node.right << " parent=" << node.parent;
		else
			out << "BSTNode key=" << node.key;
		return out;
	}
};

template<typename T>
class BST {
	BSTNode<T>* root;
	
	public:
	
	BST() {
		root = nullptr;
	}
	
	bool isEmpty() {
		return root == nullptr;
	}
	
	BSTNode<T>* getRoot() {
		return this->root;
	}
	
	void insert(T key) {
		if(this->isEmpty()) {
			root = new BSTNode<T>(key);
			return;
		}
		insert(root, key);
	}
	
	//la mia procedura ricorsiva deve avere due parametri:
	//il valore da inserire e la radice del sottoalbero 
	
	void insert(BSTNode<T>* ptr, T key) {
		if(ptr->left == nullptr && key <= ptr->key) {
			ptr->left = new BSTNode<T>(key);
			ptr->left->setParent(ptr);
			return;
		}
		if(ptr->right == nullptr && key > ptr->key) {
			ptr->right = new BSTNode<T>(key);
			ptr->right->parent = ptr;
			return;
		}
		else if(key <= ptr->key)
			insert(ptr->left, key);
		else
			insert(ptr->right, key);
	}

    	void visit(BSTNode<T>* node) {
		std::cout << *node << std::endl;
	}
	
	void inorder(BSTNode<T>* ptr) {
		if(ptr == nullptr)
			return;
		
		inorder(ptr->left);
		visit(ptr);
		inorder(ptr->right);
	}
	
	void inorder() {
		inorder(root);
	}

	BSTNode<T>* min() {
		return min(root);
	}
	
	int min(BSTNode<T>* from) {
		if(isEmpty()) {
			return -1;
		}
		int c=0;
		BSTNode<T>* ptr = from;
		while(ptr->left) {
			ptr = ptr->left;
            c++;
		}
        return c;
	}

    	BSTNode<T>* search(T key) {
		return search(root, key);
	}
	
	BSTNode<T>* search(BSTNode<T>* ptr, T key) {
		if(ptr == nullptr) 
			return nullptr;
		if(ptr->key == key)
			return ptr;
		
		if(key <= ptr->key)
			return search(ptr->left, key);
		else
			return search(ptr->right, key);
		
		return nullptr;
	}

	int distanza_successor(T val) {
		if(this->isEmpty()) {
			return -1;
		}
        BSTNode<T>* x=search(val);
		if(x->right) 
			return this->min(x->right);

        int c=0;
		BSTNode<T>* y = x->parent;
		while(x != nullptr && x == y->right) {
			x = y;
			y = y->parent;
            c++;
		}
        return c;
	}        
};

int main(){
    BST<int> b1;
    BST<char> b2;

    b1.insert(1);
    b1.insert(5);
    b1.insert(4);
    b1.insert(145);
    b1.insert(2);

    b2.insert('a');
    b2.insert('b');
    b2.insert('d');
    b2.insert('f');

    b1.inorder();
    b2.inorder();

    cout << b1.distanza_successor(145) << endl;
    cout << b2.distanza_successor('a') << endl; 

}