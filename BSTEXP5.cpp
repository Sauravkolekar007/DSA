#include <iostream>
using namespace std;
struct Node {
 int data;
 Node* left;
 Node* right;
};
// Create a new node
Node* createNode(int value) {
 Node* newNode = new Node();
 newNode->data = value;
 newNode->left = newNode->right = nullptr;
 return newNode;
}
// Insert a node into the BST
Node* insert(Node* root, int value) {
 if (root == nullptr) {
 return createNode(value);
 }
 if (value < root->data) {
 root->left = insert(root->left, value);
 } else if (value > root->data) {
 root->right = insert(root->right, value);
 }
 return root;
}
// Search for a value in the BST
bool search(Node* root, int value) {
 if (root == nullptr) {
 return false;
 }
 if (root->data == value) {
 return true;
 } else if (value < root->data) {
 return search(root->left, value);
 } else {
 return search(root->right, value);
 }
}
// In-order traversal (Left, Root, Right)
void inOrderTraversal(Node* root) {
 if (root != nullptr) {
 inOrderTraversal(root->left);
 cout << root->data << " ";
 inOrderTraversal(root->right);
 }
}
// Calculate the depth of the tree
int depth(Node* root) {
 if (root == nullptr) {
 return 0;
 }
 int leftDepth = depth(root->left);
 int rightDepth = depth(root->right);
 return max(leftDepth, rightDepth) + 1;
}
// Display leaf nodes
void displayLeafNodes(Node* root) {
 if (root == nullptr) {
 return;
 }
 if (root->left == nullptr && root->right == nullptr) {
 cout << root->data << " ";
 }
 displayLeafNodes(root->left);
 displayLeafNodes(root->right);
}
int main() {
 Node* root = nullptr;
 int choice, value;
 do {
 cout << "\nMenu:\n";
 cout << "1. Insert\n";
 cout << "2. Search\n";
 cout << "3. Display (In-order Traversal)\n";
 cout << "4. Display Depth of Tree\n";
 cout << "5. Display Leaf Nodes\n";
 cout << "6. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Enter value to insert: ";
 cin >> value;
 root = insert(root, value);
 break;
 case 2:
 cout << "Enter value to search: ";
 cin >> value;
 if (search(root, value)) {
 cout << "Value found in the tree." << endl;
 } else {
 cout << "Value not found in the tree." << endl;
 }
 break;
 case 3:
 cout << "In-order Traversal: ";
 inOrderTraversal(root);
 cout << endl;
 break;
 case 4:
 cout << "Depth of the tree: " << depth(root) << endl;
 break;
 case 5:
 cout << "Leaf nodes: ";
 displayLeafNodes(root);
 cout << endl;
 break;
 case 6:
 cout << "Exiting..." << endl;
 break;
 default:
 cout << "Invalid choice! Please try again." << endl;
 }
 } while (choice != 6);
 return 0;
}
