#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class minheap
{
private:
	int* data;
	int height;
	int no_of_elements;
public:
	minheap(int h)
	{
		height = h;
		no_of_elements = 0;
		data = new int[pow(2, height) - 1];
	}
	void insert(int v)
	{
		if (no_of_elements < pow(2, height) - 1)
		{
			data[no_of_elements] = v;
			no_of_elements++;
		}

		int i = no_of_elements - 1;
		while (i != 0 && data[i] < data[(i - 1 )/ 2]) //heapify up...
		{
			swap(data[i], data[(i - 1) / 2]);
			i = i - 1 / 2;
		}
	}

	void heapifydown(  int i, int n)
	{
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int min = i;
		if (left < n  && data[left] < data[min])
		{
			min = left;
		}
		if (right < n  && data[right] < data[min])
		{
			min = right;
		}
		if (min != i)
		{
			swap(data[i], data[min]);
			heapifydown( min, n);
		}
	}
	void print()
	{
		for (int i = 0; i < no_of_elements; i++)
			cout << data[i] << " ";
		cout << endl;
	}

	void heapsort( int n)
	{
		for (int i = n - 1;i > 0;i--)
		{
			swap(data[0],data[i]);
			heapifydown(0, i);
		}
	}
	int deleteMin()
	{
		if (no_of_elements == 0)
			return -1;    

		int root = data[0];            

		data[0] = data[no_of_elements - 1];   
		no_of_elements--;

		heapifydown(0, no_of_elements);      

		return root;
	}

	 
};

 int main()
{
	minheap t(3);
	t.insert(2);
	t.insert(8);
	t.insert(7);
	t.insert(0);
	t.insert(1);
	t.insert(3);
	t.heapifydown( 0, 6);
	t.print();
	t.deleteMin();
	t.print();
	t.heapsort(6);
	t.print();
	return 0;
}