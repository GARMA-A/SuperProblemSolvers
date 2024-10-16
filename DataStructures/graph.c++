#include <iostream>

class Node {
       int data;
       Node* next;
       Node(){
              data = 0;
              next = NULL;
       }

};

class LinkedList {
private:
       Node* head;
       Node* tail;
       int size;
public:
       LinkedList(){
              head = NULL;
              length = 0;
       }


void addNode(int data){
       Node* newNode = new Node();
       newNode->data = data;
       if(head == NULL){
              head = newNode;
       }
       else{
              head->next = newNode;
       }
       length++;

};
}



class Graph {
private:
       int vertices;
       LinkedList* adjList;
public:
       Graph(int vertices){
              this->vertices = vertices;
              adjList = new LinkedList[vertices];
       }

void addEdge(int src, int dest){
       adjList[src].addNode(dest);
       adjList[dest].addNode(src);
}


void BFS(int startVertex){
       bool* visited = new bool[vertices];
       for(int i = 0; i < vertices; i++){
              visited[i] = false;
       }
       LinkedList queue;
       visited[startVertex] = true;
       queue.addNode(startVertex);
       while(queue.length != 0){
              int currentVertex = queue.head->data;
              cout << currentVertex << " ";
              Node* temp = adjList[currentVertex].head;
              while(temp != NULL){
                     int adjVertex = temp->data;
                     if(!visited[adjVertex]){
                            visited[adjVertex] = true;
                            queue.addNode(adjVertex);
                     }
                     temp = temp->next;
              }
              queue.head = queue.head->next;
              queue.length--;
       }

void DFS(int startVertex){
       bool* visited = new bool[vertices];
       for(int i = 0; i < vertices; i++){
              visited[i] = false;
       }
       DFSUtil(startVertex, visited);

};

void DFSUtil(int currentVertex, bool visited[]){
       visited[currentVertex] = true;
       cout << currentVertex << " ";
       Node* temp = adjList[currentVertex].head;
       while(temp != NULL){
              int adjVertex = temp->data;
              if(!visited[adjVertex]){
                     DFSUtil(adjVertex, visited);
              }
              temp = temp->next;
       }
};

signed main()
{
   Graph g(4);
       g.addEdge(0, 1);
       g.addEdge(0, 2);
       g.addEdge(1, 2);
       g.addEdge(2, 3);
       return 0;
       

}

