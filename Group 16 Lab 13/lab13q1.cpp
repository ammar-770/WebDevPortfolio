// DFS algorithm in C++

#include <iostream>
#include <list>
#include "inputvalidate.cpp"
using namespace std;

class Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

   public:
  Graph(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex);
};

// Initialize graph
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
}

// DFS algorithm
void Graph::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];

  cout << "Visited " << vertex << " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
cout << endl;
}

int main() {
    cout << "Enter total number of nodes in a graph: ";
    int n = inputValidate_unsignInt(), src, dest, start; 
  Graph g(n);
  while(1){
    cout << "Press 1 to enter Edge"  << endl;
    cout << "Press 2 to perform DFS" << endl;
    cout << "Press 3 to Exit" << endl;
    int opt = inputValidate_unsignInt();
    switch (opt)
    {
    case 1:
        cout << "Enter Source Node: ";
        src = inputValidate_unsignInt();
        cout << "Enter Destiantion Node: ";
        dest = inputValidate_unsignInt();
        g.addEdge(src, dest);
        continue;

    case 2:
        cout << "Enter starting vertex: ";
        start = inputValidate_unsignInt();
        g.DFS(start);
        continue;

    case 3:
        cout << "Exiting Program" << endl;
        break;

    default:
        cout << "Invalid Input. " << endl;
        continue;
    }
    if(opt == 3)
    break;
  }
  return 0;
}