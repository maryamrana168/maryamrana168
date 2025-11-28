#include <iostream>
#include <cmath>
#include<string>
template<class T>
class Node
{
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};
template<class T>
class BST
{
private:
    Node<T>* root;

    int height(Node<T> root) {
        if (root == NULL)
            return -1;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return  max (leftHeight, rightHeight) + 1;
    }


    int countNodes(Node<T> root)
    {
        if (root == NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
     
    void inOrderHelper(Node<T>* p)
    {
        if (p != nullptr) {
            inOrderHelper(p->left);
            std::cout << p->data << " ";
            inOrderHelper(p->right);
        }
    }

    void preOrderHelper(Node<T>* p)
    {
        if (p != nullptr) {
            std::cout << p->data << " ";
            preOrderHelper(p->left);
            preOrderHelper(p->right);
        }
    }


    void postOrderHelper(Node<T>* p)
    {
        if (p != nullptr) {
            postOrderHelper(p->left);
            postOrderHelper(p->right);
            std::cout << p->data << " ";
        }
    }

    Node<T>* findMin(Node<T>* node)
    {
        {
            while (node->left != nullptr) {
                node = node->left;
            }
            return node;
        }

    }

    Node<T>* findMax(Node<T>* node)
    {
        {
            while (node->right != nullptr) {
                node = node->right;
            }
            return node;
        }

    }

    Node<T>* deleteNode(Node<T>* root, T node)
    {
        if (root == nullptr) {
            return root;
        }

        if (node < root->data) {
            root->left = deleteNode(root->left, node);
        }
        else if (node > root->data) {
            root->right = deleteNode(root->right, node);
        }
        else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node<T>* temp = findMin(root->right);
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
        return root;

    }
//bool recsearch (Node* b,int key)
public:
    BST()  
    {
        root = nullptr;
    }

    void insert(T node)
    {
        Node<T>* newNode = new Node<T>(node);

        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node<T>* current = root;
            Node<T>* parent = nullptr;

            while (current != nullptr) {
                parent = current;
                if (node < current->data) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }

            if (node < parent->data) {
                parent->left = newNode;
            }
            else {
                parent->right = newNode;
            }
        }
    }

    bool search(T node)
    {
        Node<T>* current = root;
        while (current != nullptr) {
            if (current->data == node) {
                return true;
            }
            else if (node < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }

    void inOrder()
    {
        inOrderHelper(root);
        std::cout << std::endl;
    }


    void preOrder()
    {
        preOrderHelper(root);
        std::cout << std::endl;
    }

    int getheight()
    {
        return height(this->root);
    }

    int countnodes()
    {
        return countNodes(this->root);
    }


    void postOrder()
    {
        postOrderHelper(root);
        std::cout << std::endl;
    }

    void deleteMethod(T p) 
    {
        root = deleteNode(root, p);
    }
};
 
 
 
int main()
{
    BST<int> obj;
    obj.insert(5);
    obj.insert(3);
    obj.insert(7);
    obj.insert(2);
    obj.insert(4);
    obj.insert(6);
    obj.insert(8);

    obj.inOrder();
    obj.preOrder();
    obj.postOrder();
    obj.getheight();
    obj.countnodes();
    obj.deleteMethod(2);

    obj.inOrder();

    return 0;
}