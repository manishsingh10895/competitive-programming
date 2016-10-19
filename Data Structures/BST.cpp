#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
#include <string>
#include <limits>
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
        void TraverseLeft(Node<T>*);
        void TraverseRight(Node<T>*);
        void Postorder(Node<T> *ptr);
        int Height(Node<T>* from);
        bool IsSubtree(Node<T> *subRoot, Node<T>* root);
        void LevelOrderTraversalMethod1();
        void PrintGivenLevel(Node<T>* node, int level);
        void LevelOrderTraversalMethod2(); //With queue
        Node<T>* FindNode(T data);
        Node<T>* DeleteNode(Node<T>* node, T data);
        bool IsReallyBST(Node<T>* node, int min, int max);
    public:
        Node<T>* GetRoot() {
            return root;
        }
        void UnswapNodes();
        void Insert(T data);
        Node<T>* Min(Node<T> *from);
        Node<T>* Max(Node<T> *from);
        Node<T>* Delete(T data);
        int FullHeight() {
            return Height(root);
        }
        bool CheckIfSubtree(BST<T> subtree, Node<T> *   );
        void PrintTopViewRecursive(Node<T>* node);
        void PrintTopView();
        Node<T>* FindKthSmallestElement(int k);
        Node<T>* FindLCA(Node<T> *node, T, T);
        bool IsBST() {
            return IsReallyBST(root, 0, numeric_limits<int>::max());
        }
        void FindPredecessorAndSuccessor(Node<T>* node, Node<T>* &pred, Node<T>* &succ, T data);
        void LevelOrderTraversal();
        void Print();
        BST() {
            root = NULL;
        }
};

template <class T>
bool BST<T> :: IsSubtree(Node<T>* subRoot, Node<T>* root) 
{
    if(subRoot == NULL && root == NULL) return true;

    if(subRoot == NULL || root == NULL) return false;

    return ((subRoot->data == root->data) && IsSubtree(subRoot->left, root->left) && IsSubtree(subRoot->right, root->right));
}

template <class T>
bool BST<T> :: CheckIfSubtree(BST<T> subtree, Node<T>* root)
{
    Node<T>* subRoot = subtree.GetRoot();

    if(subRoot == NULL) return true; //Empty tree is a subtree of any tree

    if(root == NULL) return false; //Nothing is subtree of empty tree

    if(IsSubtree(subRoot, root)) return true;

    return CheckIfSubtree(subtree, root->left) || CheckIfSubtree(subtree, root->right); //Traverse down the original tree
}

template <class T>
void BST<T> :: UnswapNodes()
{
    Node<T>* ptr = root;
    stack<Node<T>*> stack;

    while(ptr != NULL)
    {
        stack.push(ptr);
        ptr = ptr->left;
    }

    while(!stack.empty())
    {
        ptr = stack.top();
        stack.pop();

        if(ptr->right != NULL){
            ptr = ptr->right;

            while(ptr != NULL) {
                stack.push(ptr);
                ptr = ptr->left;
            }
        }
    }
}

template <class T>
void BST<T> :: LevelOrderTraversalMethod2() 
{
    cout << "Using Queue\n";

    queue<Node<T>*> q;

    q.push(root);

    while(!q.empty())
    {
        Node<T>* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if(temp->left != NULL) q.push(temp->left);
        if(temp->right!= NULL) q.push(temp->right);
    }
}

template <class T>
void BST<T> :: LevelOrderTraversalMethod1() 
{
    // Using Only recursive Function
    cout << "Not Using Queue\n";

    for(int i = 1; i < FullHeight(); i++) {
        PrintGivenLevel(root, i);
        cout << endl;
    }
}

template <class T>
void BST<T> :: PrintGivenLevel(Node<T>* node, int level)
{
    if(node == NULL) return;

    if(level == 1)      
        cout << node->data << " ";
    else if(level > 1) {
        PrintGivenLevel(node->left, level-1);
        PrintGivenLevel(node->right, level -1);
    }      
}

template <class T>
void BST<T> :: LevelOrderTraversal()
{
    int x = rand() % 1;

    if(x)   return LevelOrderTraversalMethod1();
    else    return LevelOrderTraversalMethod2();
}

template <class T>
void BST<T> :: TraverseLeft(Node<T> *from)
{
    if(from == NULL) return;

    cout << from->data << " ";

    TraverseLeft(from->left);
}

template <class T>
void BST<T> :: TraverseRight(Node<T> *from) {
    if(from == NULL) return;
    
    cout << from->data << " ";

    TraverseRight(from->right);
}

template <class T>
void BST<T> :: PrintTopViewRecursive(Node<T> *node)
{
    TraverseLeft(node->left);

    cout << node->data << " ";

    TraverseRight(node->right); 
} 

template <class T>
void BST<T> :: PrintTopView() 
{
    stack<T> stack;
    Node<T>* ptr = root;
    while(ptr != NULL) {
        stack.push(ptr->data);
        ptr = ptr->left;
    }

    while(!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }

    ptr = root->right;
    while(ptr!=NULL) {
        cout << ptr->data << " ";
        ptr = ptr->right;
    }
}

template <class T>
int BST<T> :: Height(Node<T>* from) 
{
    if(from == NULL) return 0;

    int leftHeight = Height(from->left);
    int rightHeight = Height(from->right);

    if(leftHeight > rightHeight) return leftHeight + 1;
    else return rightHeight + 1;
}

template <class T>
Node<T>* BST<T> :: FindKthSmallestElement(int k)
{
    Node<T> *ptr = root;
    stack<Node<T>*> stack;

    // Traverse to the extreme left from root i.e. the smallest node
    while(ptr != NULL) {
        stack.push(ptr);
        ptr = ptr->left;
    }

    int i = 0;
    while(!stack.empty()) {
        ptr = stack.top();
        stack.pop();

        i++;
        if(i == k) break;

        if(ptr->right != NULL) {
            ptr = ptr->right;

            while(ptr != NULL) {
                stack.push(ptr);
                ptr = ptr->left;
            }
        }
    }

    cout << ptr->data;
    return ptr;
}

template <class T>
Node<T>* BST<T> :: FindLCA(Node<T> *node, T data1, T data2) {
    if (node == NULL) return node;

    if(node->data < data1 && node->data < data2) {
        return FindLCA(node->right, data1, data2);
    }

    if(node->data > data1 && node->data > data2) {
        return FindLCA(node->left, data1, data2);  
    }
     
    // This will be executed only if node is between data1 and data2
    return node;
}

template <class T>
bool BST<T> :: IsReallyBST(Node<T>* node, int min, int max)
{
    if(node == NULL) return true;

    // Node's data is out of the specified range then it is not a BST
    if(node->data < min || node->data > max) return 0;

    return IsReallyBST(node->left, min, node->data - 1) && IsReallyBST(node->right, node->data + 1, max);
} 

template <class T>
void BST<T> :: FindPredecessorAndSuccessor(Node<T>* node, Node<T>* &pred, Node<T>* &succ, T data) 
{
    if(node == NULL) return;

    if(node->data == data) {
        if(node->left != NULL) pred = Max(node->left);
        if(node->right != NULL) succ = Min(node->right);

        return;
    }

    if(node->data > data) {
        succ = node;
        FindPredecessorAndSuccessor(node->left, pred, succ, data);
    } else {
        pred = node;
        FindPredecessorAndSuccessor(node->right, pred, succ, data);
    }
}

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
        prev = curr;

        if(data > curr->data) curr = curr->right;
        else curr = curr->left;
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
    BST<int> tree; int choice; int data; int secondaryData; 
    string printStatement;

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
        cout << "4. Find Inorder Predecessor and Successor of a node\n";
        cout << "5. Check is the current tree is Binary Search Tree\n";
        cout << "6. Find Lowest Common Ancestor of two nodes\n";
        cout << "7. Find the height of the tree\n";
        cout << "8. Print Top view\n";
        cout << "9. Find Kth last node in the tree\n";
        cout << "10. Level Order Traversal\n";
        cout << "11. Check if subtree\n";
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
            case 4:
                cout << "Enter the data of the node\n";
                cin >> data;
                Node<int> *pred, *succ;
                tree.FindPredecessorAndSuccessor(tree.GetRoot(), pred, succ, data);
                cout << "\nInorder Predecessor \t" << pred->data;
                cout << "\nInorder Successor \t" << succ->data << endl;
                break;
            case 5:
                printStatement = tree.IsBST() ? "Tree is Binary Search Tree" : "Tree is not Binary Search Tree";                
                cout << printStatement << endl;
                break;
            case 6:
            {
                cout << "Enter the two datas for finding the LCA separated by space\n";
                cin >> data >> secondaryData;
                Node<int> *node = tree.FindLCA(tree.GetRoot(), data, secondaryData);

                if(node == NULL) cout << "No LCA found\n";
                else cout << "LCA is " << node->data << endl;
                break;
            }
            case 7:
                cout << "Height of the tree is " << tree.FullHeight() << endl;
                break;
            case 8:
                cout << "Here the top view for you \n";
                tree.PrintTopViewRecursive(tree.GetRoot());
                cout << "\n";
                break;
            case 9:
                cout << "Enter the value for k\n";
                cin >> data;
                tree.FindKthSmallestElement(data);
                cout << endl;
                break;
            case 10:
                tree.LevelOrderTraversal();
                cout << "\n";
                break;
            case 11:
            {
                BST<int> subtree;
                subtree.Insert(20);
                subtree.Insert(15);
                subtree.Insert(13);
                subtree.Insert(16);
                subtree.Insert(40);

                cout << tree.CheckIfSubtree(subtree, tree.GetRoot());
            }
            case 12: 
            {
                BST<int> 
            }
            default: return 0;
        }
    }
}