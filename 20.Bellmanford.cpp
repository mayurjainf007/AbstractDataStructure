#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int src, dest, weight;
};
struct Graph{
    int V, E;
    struct Edge* edge;
};
struct Graph* createGraph(int V, int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}
void BellmanFord(struct Graph* graph){
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    for(int i=0; i<V; i++)
        dist[i] = INT_MAX;
    dist[0] = 0;
    for(int i=1; i<=V-1; i++){
    	for(int j=0; j<E; j++){
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            	dist[v] = dist[u] + weight;
        }
    }
    for(int i=0; i<E; i++){
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
    return;
}
int main(){
	int V,E;
	cin>>V>>E;
    struct Graph* graph = createGraph(V, E);
    cout<<"\tSrc\tDest\tWt\n";
//    int V = 5; E = 8;
//    edge 0-1 weight = -1;
//    edge 0-2 weight = 4;
//    edge 1-2 weight = 3;
//    edge 1-3 weight = 2;
//    edge 1-4 weight = 2;
//    edge 3-2 weight = 5;
//    edge 3-1 weight = 1;
//    edge 4-3 weight = -3;
    for(int i=0; i<E; i++){
    	cin>>graph->edge[i].src;
    	cin>>graph->edge[i].dest;
    	cin>>graph->edge[i].weight;
	}
	clock_t start = clock();
    BellmanFord(graph);
    clock_t end = clock();
    cout<<"\n Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	cout<<" Time : "<<(end - start)<<" Milliseconds\n";
    return 0;
}

//	function BellmanFord(list vertices, list edges, vertex source)
//	   ::distance[],predecessor[]
//	   // This implementation takes in a graph, represented as
//	   // lists of vertices and edges, and fills two arrays
//	   // (distance and predecessor) with shortest-path
//	   // (less cost/distance/metric) information
//	   // Step 1: initialize graph
//	   for each vertex v in vertices:
//	       distance[v] := inf             // At the beginning , all vertices have a weight of infinity
//	       predecessor[v] := null         // And a null predecessor
//	   distance[source] := 0              // Except for the Source, where the Weight is zero
//	
//	   // Step 2: relax edges repeatedly
//	   for i from 1 to size(vertices)-1:
//	       for each edge (u, v) with weight w in edges:
//	           if distance[u] + w < distance[v]:
//	               distance[v] := distance[u] + w
//	               predecessor[v] := u
//	   // Step 3: check for negative-weight cycles
//	   for each edge (u, v) with weight w in edges:
//	       if distance[u] + w < distance[v]:
//	           error "Graph contains a negative-weight cycle"
//	   return distance[], predecessor[]

//O(EV)
