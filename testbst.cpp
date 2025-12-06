#include <iostream>
#include<string>
using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<class T>
class BST {
private:
    Node<T>* root;
    Node<T>* findMin(Node<T>* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }



    Node<T>* deleteNode(Node<T>* node, T value) {
        if (node == nullptr)
            return node;

        if (value < node->data)
            node->left = deleteNode(node->left, value);

        else if (value > node->data)
            node->right = deleteNode(node->right, value);

        else {
            if (node->left == nullptr) {
                Node<T>* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node<T>* temp = node->left;
                delete node;
                return temp;
            }

            Node<T>* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    void inOrder(Node<T>* p) {
        if (p != nullptr) {
            inOrder(p->left);
            cout << p->data << " ";
            inOrder(p->right);
        }
    }

    void preOrder(Node<T>* p) {
        if (p != nullptr) {
            cout << p->data << " ";
            preOrder(p->left);
            preOrder(p->right);
        }
    }


    void postOrder(Node<T>* p) {
        if (p != nullptr) {
            postOrder(p->left);
            postOrder(p->right);
            cout << p->data << " ";
        }
    }


    bool recSearch(Node<T>* node, T key) {
        if (node == nullptr)
            return false;
        if (node->data == key)
            return true;
        if (key < node->data)
            return recSearch(node->left, key);
        return recSearch(node->right, key);
    }

    int countNodes(Node<T>* node) {
        if (node == nullptr)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }


    int getHeight(Node<T>* node) {
        if (node == nullptr)
            return -1;
        int lh = getHeight(node->left);
        int rh = getHeight(node->right);
        return 1 + max(lh, rh);
    }


    void doubleTree(Node<T>* node) {
        if (node == nullptr)
            return;

        doubleTree(node->left);
        doubleTree(node->right);

        Node<T>* oldLeft = node->left;
        node->left = new Node<T>(node->data);
        node->left->left = oldLeft;
    }

    void printAllPaths(Node<T>* node, T path[], int len) {

        if (node == nullptr)
            return;

        path[len] = node->data;
        len++;

        if (node->left == nullptr && node->right == nullptr) {
            for (int i = 0; i < len; i++) {
                cout << path[i];
                if (i < len - 1) cout << " -> ";
            }
            cout << endl;
        }
        else {
            printAllPaths(node->left, path, len);
            printAllPaths(node->right, path, len);
        }
    }



public:

    BST() : root(nullptr) {}


    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node<T>* current = root;
        Node<T>* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }


    bool search(T value) {
        Node<T>* current = root;

        while (current != nullptr) {
            if (current->data == value)
                return true;
            else if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }


    void deleteMethod(T value) {
        root = deleteNode(root, value);
    }



    void inOrder() {
        inOrder(root);
        cout << endl;
    }



    void preOrder() {
        preOrder(root);
        cout << endl;
    }



    void postOrder() {
        postOrder(root);
        cout << endl;
    }



    bool recSearch(T key) {
        return recSearch(root, key);
    }


    int countNodes() {
        return countNodes(root);
    }



    int getHeight() {
        return getHeight(root);
    }


    void doubleTree()
    {
        doubleTree(root);
    }



    void printAllPaths() {
        T path[100];
        printAllPaths(root, path, 0);
    }



    /*  void construct_from_traversals(int in_order[], int pre_order[])
     {
         int size=6;

         this->root = pre_order[0];
         for (int j = 0;j < size;j++)
         {
             if (in_order[j] == pre_order[0])
             {
                 root->left = in_order[j - 1];
                 root->right = in_order[j + 1];
            }
         }
     }*/

    
};



int main() {
    BST<int> obj;
    obj.insert(5);
    obj.insert(3);
    obj.insert(7);
    obj.insert(2);
    obj.insert(4);
    obj.insert(6);
    obj.insert(8);

    cout << "InOrder: ";
    obj.inOrder();

    cout << "Height: " << obj.getHeight() << endl;
    cout << "Node Count: " << obj.countNodes() << endl;

    cout << "\nAll Paths:\n";
    obj.printAllPaths();

    return 0;
}