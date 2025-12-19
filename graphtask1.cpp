

#include<iostream>
#include<string>
#include"QUEUE"

using namespace std;


class Graph {
private:
	int** adjMatrix; // Adjacency matrix of the graph
	int maxVertices; // Max number of vertices which can be present in the graph
	int n; // Current number of vertices present in the graph
	bool* visited; // Array to keep track of visited/unvisited vertices

	void DFS(int v) // private member function
	{
		visited[v] = true;
		for (int i = 0;i < maxVertices;i++)
		{
			if (adjMatrix[s][i] == 1 && visited[i] == false)
			{
				DFS(i);
			}
		}
	}



public:
	Graph(int maxV, int currV)
	{
		maxVertices = maxV;
		n = currV;
		adjMatrix = new int* [maxV];
		for (int i = 0;i < maxV;i++)
		{
			adjMatrix[i] = new int[maxV];
		}
	}

	~Graph() // Destructor
	{
		maxVertices = 0;
		n = 0;
		delete adjMatrix;
		adjMatrix = nullptr;
	}


	bool addVertex(int& v);
	{
		if (n == maxVertices)
		{
			return false;
		}

		v = n;
		for (int i = 0;i < n;i++)
		{
			adjMatrix[v][i] = 0;
			adjMatrix[i][v] = 0;
		}
		n++;
		return true;
	}
	 
	bool addEdge(int u, int v) // Adds the edge <u,v> to the graph
	{
		if (u >= 0 && v >= 0 && u < maxVertices && v < maxVertices)
		{
			adjMatrix[u][v] = 1;
			adjMatrix[v][u] = 1;
		}
		return true;
	}

	bool removeEdge(int u, int v) // Removes the edge <u,v> from the graph
	{
		if (u >= 0 && v >= 0 && u < maxVertices && v < maxVertices)
		{
			adjMatrix[u][v] = 0;
			adjMatrix[v][u] = 0;
		}
		return true;
	}

	bool isempty()
	{
		for (int i = 0; i <n; i++)
		{
			for (int j = 0;j < n;j++)
			{
				if (adjMatrix[i][j] == 1) return false;
		    }
		}
		return true;
	}

	bool iscomplete()
	{
		if (n <= 1) return false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0;j < n;j++)
			{
				if (i!=j && adjMatrix[i][j] == 0) return false;
			}
		}
		return true;
	}

	void clear()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0;j < n;j++)
			{
				adjMatrix[i][j] == 0;
			}
		}
	}

	void display()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0;j < n;j++)
			{
				cout<<adjMatrix[i][j]<<" ";
				cout << endl;
			}
		}
	}

	int Degree(int v)
	{
		if (v < 0 || v >= n)
			return -1;

		int degree = 0;
		for (int i = 0; i < n; i++)
			degree += adjMatrix[v][i];

		return degree;
	}

	void DFS()
	{
		for (int i = 0;maxVertices;i++)
		{
			if (visit[i] == false) DFS(i);
		}
	}

	Graph(const Graph& g)
	{
		maxVertices = g.maxVertices;
		n = g.n;
		 
		for (int i = 0; i < maxVertices; i++)
			for (int j = 0; j < maxVertices; j++)
				adjMatrix[i][j] = g.adjMatrix[i][j];

		visited = new bool[maxVertices];
		for (int i = 0; i < maxVertices; i++)
			visited[i] = g.visited[i];
	}

	void BFS()
	{
		for (int i = 0;i < maxVertices;i++)
		{
			visited[i] = false;
		}
		int index;
		cout << "enter the particular index:";
		cin >> index;
		QUEUE q;
		q.enqueue(index);
		visited[index] = true;
		while (!q.empty())
		{
			int node = q.dequeue();
			cout << node;
		}
		for (int i = 0; i < n; i++)
		{
			if (adjMatrix[node][i] == 1 && !visited[i])
			{
				visited[i] = true;
				q.enqueue(i);
			}
		}
	}

};
