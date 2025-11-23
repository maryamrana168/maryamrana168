 
#include <iostream>
#include<string>
using namespace std;
template <class T>
class Node
{
public:
	T info;
	Node<T>* next;
	Node()
	{
		next = 0;
	}
	Node(T val)
	{
		info = val;
		next = 0;
	}
	Node(T val, Node* p)
	{
		info = val;
		next = p;
	}
};
template <class T>
class LSLL
{
private:
	Node<T>* head;
public:
	LSLL()
	{
		head = 0;
	}

	// Insertion functions
	void insertAtHead(T val)
	{
		Node<T>* t = new Node<T>(val);
		t->next = head;
		head = t;
	}

	void insertAtTail(T val)
	{
		Node<T>* t = new Node<T>(val);
		if (!head)
		{
			head = t;
			return;
		}
		Node<T>* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = t;
	}

	void insertBefore(T key, T val)
	{
		//if head is nullptr
		if (!head)
		{
			return;
		}

		//if value match in first node
		if (head->info == key)
		{
			Node<T>* t = new Node<T>(val);
			t->next = head;
			head = t;
			return;
		}

		Node<T>* temp = head;
		Node<T>* prev = head;
		while (temp != nullptr)
		{
			if (temp->info == key)
			{
				Node<T>* t = new Node<T>(val);
				t->next = temp;
				prev->next = t;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
	}

	void insertAfter(T key, T val)
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			if (temp->info == key)
			{
				Node<T>* t = new Node<T>(val);
				t->next = temp->next;
				temp->next = t;
				return;
			}
			temp = temp->next;
		}
	}

	// Deletion functions
	void removeAtHead()
	{
		if (!head) return;

		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}

	void removeAtTail()
	{
		if (!head) return;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		Node<T>* temp = head;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = nullptr;

	}

	void remove(T val)
	{
		if (!head)
		{
			return;
		}
		if (head->info == val)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node<T>* temp = head;
		Node<T>* prev = head;
		while (temp != nullptr)
		{
			if (temp->info == val)
			{
				prev->next = temp->next;
				delete temp;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
	}
	void removeBefore(T val)
	{
		if (!head) return;
		if (head->info == val) return;

		Node<T>* temp = head;
		Node<T>* prev = nullptr;
		Node<T>* prev_p = nullptr;

		while (temp != nullptr)
		{
			if (temp->info == val)
			{
				if (prev_p == nullptr) {

					head = temp;
					delete prev;
					return;
				}
				else {
					prev_p->next = temp;
					delete prev;
					return;
				}
			}

			prev_p = prev;
			prev = temp;
			temp = temp->next;
		}

	}
	void removeAfter(T val)
	{
		if (!head)
		{
			return;
		}

		Node<T>* temp = head;

		while (temp != nullptr)
		{
			if (temp->info == val && temp->next != nullptr)
			{
				Node<T>* t = temp->next;
				temp->next = t->next;
				delete t;
				return;
			}
			temp = temp->next;
		}
	}

	// Utility functions
	bool search(T key)
	{
		if (!head) return false;

		Node<T>* temp = head;
		while (temp != nullptr)
		{
			if (temp->info == key)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	void update(T key, T val)
	{
		if (!head) return;

		Node<T>* temp = head;
		while (temp != nullptr)
		{
			if (temp->info == key)
			{
				temp->info = val;
				return;
			}
			temp = temp->next;
		}
	}

	int countNodes()
	{
		if (!head) return 0;

		int count = 0;
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}

	void removeKthNode(int k)
	{
		if (head == 0) return;
		if (k == 1)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		int count = 2;
		Node<T>* temp = head->next;
		Node<T>* prev = head;
		while (temp != 0)
		{
			if (count == k)
			{
				prev->next = temp->next;
				delete temp;
				return;
			}
			prev = temp;
			temp = temp->next;
			count++;
		}
	}
	void display()
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->info << " ";
			temp = temp->next;
		}
	}

	~LSLL() // Destructor
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			Node<T>* next_Node = temp->next;
			delete temp;
			temp = next_Node;
		}
		head = nullptr;
	}
};



class HashTable {
    LSLL<int>* table;  // array of linked lists
    int size;

public:
    HashTable(int s) {
        size = s;
        table = new LSLL<int>[size];   // dynamically allocate array
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].insertAtTail(key);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
			table[i].display();
            cout << "NULL" << endl;
        }
    }

    ~HashTable() {
		table = nullptr;
        delete[] table;  // free memory
    }
};

int main() {
    HashTable ht(7);

    ht.insert(15);
    ht.insert(11);
    ht.insert(27);
    ht.insert(8);
    ht.insert(12);

    ht.display();

    return 0;
}