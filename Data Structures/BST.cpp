#include <iostream>
using namespace std;

template <class T>
class Node {
    public: 
        T data;
        Node<T>* left;
        Node<T>* right;
        Node(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

template <class T>
class BST {
    private: 
        Node<T> *root;
        void Inorder(Node<T> *ptr);
        void Preorder(Node<T> *ptr);
        void Postorder(Node<T> *ptr);
        Node<T>* FindNode(T data);
        Node<T>* DeleteNode(Node<T>* node, T data);
    public:
        void Insert(T data);
        Node<T>* Min(Node<T> *from);
        Node<T>* Max(Node<T> *from);
        Node<T>* Delete(T data);
        void Print();
        BST() {
            root = NULL;
        }
};

template <class T>
Node<T>* BST<T> :: Min(Node<T>* from) {
    if(from == NULL) return from;
    if(from->left == NULL) return from;

    Min(from->left);
}

template <class T>
Node<T>* BST<T> :: Max(Node<T> *from) {
    if(from == NULL) return from;
    if(from->right == NULL) return from;

    Max(from->right);
}

template <class T>
Node<T>* BST<T> :: FindNode(T data) 
{
    Node<T> *prev = NULL;
    Node<T> *curr = root;

    if(root == NULL) return root;

    // Find the Node that contains its data part as requested data
    while(curr != NULL) {
        prev = curr;

        // if curr's data is requested data stop the loop
        if(curr->data == data) break;

        if(data > curr->data) curr = curr->right; 
        else curr = curr->left;
    }

    return curr;
}

template <class T>
Node<T>* BST<T> :: Delete(T data) {
    DeleteNode(root, data);
}

template <class T> 
Node<T>* BST<T> :: DeleteNode(Node<T>* node, T data) {
    if(node == NULL) return node;

    if(data < node->data) node->left = DeleteNode(node->left, data);
    else if(data > node->data) node->right = DeleteNode(node->right, data);
    else {
        if(node->left == NULL) {
            Node<T>* temp = node->right;
            delete node;
            return temp;
        } 
        else if(node->right == NULL) {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        }

        Node<T> *min = Min(node->right);
        node->data = min->data;
        node->right = DeleteNode(node->right, min->data);
    }

    return node;
}

template <class T>
void BST<T> :: Insert(T data) 
{
    Node<T> *curr = root;
    Node<T> *prev = NULL;
    Node<T> *ptr = new Node<T>(data);

    if(root == NULL) {
        root = ptr;
        return;
    }

    while(curr!=NULL) {
        if(data > curr->data) {
            prev = curr;
            curr = curr->right;
        } else {
            prev = curr;
            curr = curr->left;
        }
    }

    if(prev->data < data) prev->right = ptr;
    else prev->left = ptr;
}

template <class T>
void BST<T> :: Print() 
{
    int choice;

    cout << "1. Inorder Traversal\n";
    cout << "2. Preorder Traversal\n";
    cout << "3. PostOrder Traversal\n";

    cout << "Enter your choice\n";
    cin >> choice;

    switch(choice) {
        case 1: 
            Inorder(root); 
            break;
        case 2: 
            Preorder(root);
            break;
        case 3:
            Postorder(root);
            break;
        default: cout << "Invalid Choice\n";
    }
}

template <class T>
void BST<T> :: Inorder(Node<T> *ptr) {
    if(ptr == NULL) return;

    Inorder(ptr->left);
    cout << ptr->data << " ";
    Inorder(ptr->right);
}

template <class T>
void BST<T> :: Preorder(Node<T> *ptr) {
    if(ptr == NULL) return;

    Preorder(ptr->left);
    Preorder(ptr->right);
    cout << ptr->data << " ";
}

template <class T>
void BST<T> :: Postorder(Node<T> *ptr) {
    if(ptr == NULL) return;

    cout << ptr->data << " ";
    Postorder(ptr->left);
    Postorder(ptr->right);
}


int main()
{
    BST<int> tree; int choice; int data;

    cout << "Binary Search Tree\n";

    // Sample Data
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(6);
    tree.Insert(7);
    tree.Insert(8);
    tree.Insert(20);
    tree.Insert(15);
    tree.Insert(13);
    tree.Insert(16);
    tree.Insert(40);
    tree.Insert(35);
    tree.Insert(48);
    tree.Insert(31);
    tree.Insert(36);
    tree.Insert(33);
    tree.Insert(32);
    tree.Insert(34);

    while(true) {
        cout << "1. Insert A Node<T>\n";
        cout << "2. Delete A Node<T>\n";
        cout << "3. Print the tree\n";
        cout << "\n0. Exit\n";

        cout << "Enter your choice\n";
        cin >> choice;

        switch(choice) {
            case 1: 
                cout << "Enter the data for the Node<T>\n";
                cin >> data;
                tree.Insert(data);
                break;
            case 2:
                cout << "Enter the data of the node \n";
                cin >> data;
                tree.Delete(data); 
                break;
            case 3:
                tree.Print();
                cout << endl;
                break;

            default: return 0;
        }
    }
}