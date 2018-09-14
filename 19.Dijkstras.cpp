#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <time.h>
using namespace std;
static int V;
int minDistance(int dist[], bool sptSet[]){
	int min = INT_MAX, min_index;
	for (int v=0; v<V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
	return min_index;
}
void dijkstra(int graph[10][10]){
	int dist[V];
    bool sptSet[V];
    for(int i=0; i<V; i++)
   		dist[i] = INT_MAX, sptSet[i] = false;
    dist[0] = 0;
    for (int count = 0; count < V-1; count++){
    	int u = minDistance(dist, sptSet);
    	sptSet[u] = true;
    	for(int v=0; v<V; v++)
    		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
    			dist[v] = dist[u] + graph[u][v];
    }
    cout<<"\n Vertex Distance from Source is >\n";
	cout<<" Node \t      Distance\n";
	for (int i = 0; i < V; i++)
		printf("  %d \t>>\t %d\n", i, dist[i]);
}
int main(){
	int graph[10][10];
	double time;
	cin>>V;
	for(int i=0; i<V; i++)
		for(int j=0; j<V; j++)
			cin>>graph[i][j];
	/*As Input Sample 
	graph = 
	   {{0, 4, 0, 8, 0},
        {4, 0, 8, 11, 0},
        {0, 8, 0, 0, 2},
        {0, 2, 0, 0, 6},
        {8, 11, 1, 0, 0},
    };*/
    clock_t start;
	start = clock();
    dijkstra(graph);
	clock_t end;
	end = clock();
	cout<<endl;
	cout<<" Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	time = (end - start);
	cout<<" Time : "<<time<<" Milliseconds\n";
    return 0;
}

//	initialise_single_source( Graph g, Node s )
//	   for each vertex v in Vertices( g )
//	       g.d[v] := infinity
//	       g.pi[v] := nil
//	   g.d[s] := 0;
//	   
//	relax( Node u, Node v, double w[][] )
//	    if d[v] > d[u] + w[u,v] then
//	       d[v] := d[u] + w[u,v]
//	       pi[v] := u
//	
//	shortest_paths( Graph g, Node s )
//	    initialise_single_source( g, s )
//	    S := { 0 }        /* Make S empty */
//	    Q := Vertices( g ) /* Put the vertices in a PQ */
//	    while not Empty(Q) 
//	        u := ExtractCheapest( Q );
//	        AddNode( S, u ); /* Add u to S */
//	        for each vertex v in Adjacent( u )
//	            relax( u, v, w )

//O(ElgV)
