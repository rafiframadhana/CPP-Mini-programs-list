#include <iostream>  
using namespace std; 
 
class Node {
 public:
  int data;
  Node *left;
  Node *right;
  Node(int data) {
    this->data = data;
    left = right = nullptr;
  }
};

class BST {
 public:
  Node *root;

  BST() { root = nullptr; }

  void insert(int data) { root = insertNode(root, data); }

  Node *insertNode(Node *node, int data) {
    if (node == nullptr) {
      return new Node(data);
    }
    if (data < node->data) {
      node->left = insertNode(node->left, data);
    } else if (data > node->data) {
      node->right = insertNode(node->right, data);
    }
    return node;
  }

  bool find(int data) { return findNode(root, data); }

  bool findNode(Node *node, int data) {
    if (node == nullptr) {
      return false;
    }
    if (data == node->data) {
      return true;
    }
    if (data < node->data) {
      return findNode(node->left, data);
    } else {
      return findNode(node->right, data);
    }
  }
};

int main() {
  BST bst;
  bst.insert(5);
  bst.insert(3);
  bst.insert(2);
  bst.insert(4);
  bst.insert(7);
  bst.insert(6);
  bst.insert(8);

  int num = 2;
  if (bst.find(num)) {
    cout << num << " is found in the tree." << endl;
  } else {
    cout << num << " is not found in the tree." << endl;
  }

  return 0;
}