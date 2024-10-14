#include<iostream>
#include "inputvalidate.cpp"
#include "queue.cpp"

class Graph_Matrix{
    int **a;
    int size;

    public:
    Graph_Matrix(int n){
        size = n;
        *a = new int[size];
        for(int i = 0; i < size; i++){
            a[i] = new int[size];
            for(int j = 0; j < size; j++){
                a[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest){
        a[src][dest] = a[dest][src] = 1;
    }

    void BFS(int start){
        bool visited[size];
        for(int i = 0; i < size; i++)
            visited[i] = false;

        visited[start] = true;
        cout << "Visited: " << start << " ";

        Queue<int> Q1(size);
        Q1.enqueue(start);

        while(!Q1.isEmpty()){
            int node = Q1.queueFront();
            Q1.dequeue();
            for(int j = 0; j < size; j++){
                if(a[node][j] == 1 && visited[j] == 0){
                    cout << j << " ";
                    visited[j] = true;
                    Q1.enqueue(j);
                }
            }
        }
    }

    void DFS(int start, bool v[]){
        cout << start << " ";
        v[start] = true;

        for(int j = 0; j < size; j++){
            if(a[start][j] == 1 && v[j] == 0){
                DFS(j, v);
            }
        }
    }

    int getSize(){
        return size;
    }
};

int main(){
    cout << "Enter total number of nodes in a graph: ";
    int n = inputValidate_unsignInt(), src, dest, start; 
    Graph_Matrix g(n);
    bool *visited;
    
    while(1){
    cout << "Press 1 to enter Edge"  << endl;
    cout << "Press 2 to perform DFS" << endl;
    cout << "Press 3 to perform BFS" << endl;
    cout << "Press 4 to Exit" << endl;
    int opt = inputValidate_unsignInt();
    switch(opt)
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
        visited = new bool[g.getSize()];
        for(int i = 0; i < g.getSize(); i++)
            visited[i] = 0;
        cout << "DFS: ";
        g.DFS(start, visited);
        cout << endl;
        continue;

    case 3:
        cout << "Enter starting vertex: ";
        start = inputValidate_unsignInt();
        cout << "BFS: ";
        g.BFS(start);
        cout << endl;
        continue;

    case 4:
        cout << "Exiting Program" << endl;
        break;

    default:
        cout << "Invalid Input. " << endl;
        continue;
    }
    if(opt == 4)
    break;
  }
  return 0;
}