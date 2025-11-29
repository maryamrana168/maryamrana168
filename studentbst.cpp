#include <iostream>
#include<string>
using namespace std;

class StudentNode {
public:
	int rollNo;  

	string name;  
	double cgpa;  
	StudentNode* left;  
	StudentNode* right;

	StudentNode(int roll,string str,double value)  {
        name = str;
        cgpa=value;
        rollNo = roll;
        left=nullptr;
        right=nullptr;
    
    }

    StudentNode(int roll) {
         
        rollNo = roll;
        left = nullptr;
        right = nullptr;

    }

};


class StudentBST {
private:
	StudentNode* root;

    void inOrderHelper(StudentNode* p)
    {
        if (p != nullptr) {
            inOrderHelper(p->left);
            cout << p->name << " ";
            cout << p->cgpa << " ";
            cout << p->rollNo << " ";
            inOrderHelper(p->right);
        }
    }





    StudentNode findMin(StudentNode  node)
    {
        {
            while (node->left != nullptr) {
                node = node->left;
            }
            return node;
        }

    }


    void destroy(StudentNode* root )
    {
        if (root == nullptr) 
        {
            return root;
        }

        if (this->rollNo < root->rollNo) {
            root->left = destroy(root->left);
        }
        else if (this->rollNo > root->rollNo) {
            root->right = destroy(root->right);
        }
        else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                StudentNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                StudentNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            StudentNode* temp = findMin(root->right);
            root->data = temp->data;

            // Delete the inorder successor
            root->right = destroy(root->right, temp->data);
        }
        return root;

    }


public:

	StudentBST()
	{
		root = nullptr;
	}

    bool insert( int roll,string str,double cgpa)
    {
        StudentNode* cur = root;
        while (cur != nullptr) {
            if (cur->rollNo == roll) {
                return false;
            }
            else if (roll < cur->rollNo) {
                cur  = cur->left;
            }
            else {
                cur = cur ->right;
            }
        } 
        StudentNode* newNode = new StudentNode(roll);

        if (root == nullptr) {
            root = newNode;
        }
        else {
            StudentNode* current = root;
            StudentNode* parent = nullptr;

            while (current != nullptr) {
                parent = current;
                if (roll < current->rollNo) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }

            if (roll < parent->rollNo) {
                parent->left = newNode;
            }
            else {
                parent->right = newNode;
            }
        }
        return true;
    }

    bool search(int roll)
    {
        StudentNode* current = root;
        while (current != nullptr) 
        {
            if (current->rollNo == roll) {
                cout << current->name << endl;
                cout << current->rollNo << endl;
                cout << current->cgpa << endl;
                return true;
            }
            else if (roll < current->rollNo) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        cout << "student not found" << endl;
        return false;
    }

    ~StudentBST() {
         destroy(root);
       
    }


    void inOrder()
    {
        inOrderHelper(root);
        cout << endl;
    }

    bool remove(int rn)
    {
        StudentNode* current = root;
        while (current != nullptr)
        {
            if (current->rollNo == roll) {
                destroy(current);
                return true;
            }
            else if (roll < current->rollNo) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        cout << "student not found" << endl;
        return false;
    }
    
    void displayInRange(double cgpastrat,double cgpaend)
    {
        StudentNode* temp = root;
        while(temp!=NULL)
        if (temp->cgpa > cgpastart && temp->cgpa < cgpaend)
        {
            this->inOrder();
        }
        else if (temp->cgpa > cgpaend)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
        return;
     }



};


int main()
{   
    StudentBST obj;
    obj.insert(3, "maryam", 2.7);
        obj.insert(4, "ali", 3.4);
        obj.insert(5, "sadia", 3.7);


    return 0;
}