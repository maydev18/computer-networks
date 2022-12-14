#include <bits/stdc++.h>
using namespace std;
void bellman(int graph[][3] , int vertices , int edges , int source){
    int distance[vertices+1];
    for(int i = 1  ; i <= vertices ; i++){
        distance[i] = 100000;
    }
    distance[source] = 0;
    for(int i = 1 ; i<=vertices-1 ; i++){
        for(int j = 1 ; j<=edges ; j++){
            int u = graph[j][0];
            int v = graph[j][1];
            int w = graph[j][2];
            distance[v] = min(distance[u] + w , distance[v]);
        }
    }
    for(int j = 1; j<=edges ; j++){
        int u = graph[j][0];
        int v = graph[j][1];
        int w = graph[j][2];
        if(distance[u] + w < distance[v]){
            cout << "negative path cycle found in graph , hence cannot determine the correct shortest path lengths" << endl;
            exit(100);
        }
    }
    cout << endl;
    for(int i = 1 ; i<=vertices ;i++){
        cout << distance[i] << " ";
    }
    cout << endl;
}
int main(){
    int vertices , edges;
    cout << "enter the number of vertices: " ; cin >> vertices;
    cout << " enter the number of edges: "; cin >> edges;
    int graph[edges+1][3];
    cout << "enter the graph by three integers u,v,w where u represent the starting vertex , v represents the ending vertex and w represent the weight of the edge: " << endl;
    for(int i =1  ;  i<=edges ; i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[i][0] = u;
        graph[i][1] = v;
        graph[i][2] = w;
    }
    for(int i = 1  ; i <= vertices ; i++){
        cout << "source " << i <<"  :  " ;
        bellman(graph ,vertices ,edges , i);
    }
    return 0;
}