#include <iostream>
#include <vector>
#define INT_MAX 9999999
using namespace std;
int findMinNonVisitedNode(int distance[], bool visited[] , int vertices)
{
    int mini = INT_MAX;
    int index;
    for(int i = 0  ;  i<vertices ; i++){
        if(distance[i] < mini && !visited[i]){
            mini = distance[i];
            index = i;
        }
    }
    return index;
}
void dijkstra(int graph[][5], int src , int vertices)
{
    int distance[vertices];
    bool visited[vertices];
    for(int i = 0 ; i < vertices ; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[src] = 0;
    for(int i= 0 ; i<vertices-1 ; i++){
        int u = findMinNonVisitedNode(distance , visited , vertices);
        visited[i] = true;
        for(int i = 0 ; i<vertices ; i++){
            if(graph[u][i] && !visited[i] && (distance[u] + graph[u][i] < distance[i])){
                distance[i] = distance[u] + graph[u][i];
            }
        }
    }
    for(int i = 0  ; i<vertices; i++) cout << distance[i] << " ";
    cout << endl;
}
int main()
{
    int graph[5][5] = {
        {0, 4, 0, 1, 2},
        {4, 0, 8, 0, 0},
        {0, 8, 0, 7, 0},
        {1, 0, 7, 0, 9},
        {2, 0, 0, 9, 0},
    };
    dijkstra(graph ,0 ,5);
}