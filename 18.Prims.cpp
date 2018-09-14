#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<time.h>
using namespace std;
int minKey(int key[], bool mstSet[], int V){
	int min = INT_MAX, min_index;
	for(int v=0; v<V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}
void primMST(int graph[10][10], int V){
	int parent[V]; // Array to store constructed MST
    int key[V];   // Key values used to pick minimum weight edge in cut
    bool mstSet[V];  // To represent set of vertices not yet included in MST
    for(int i=0; i<V; i++)
    	key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST 
    for(int count=0; count<V-1; count++){
		int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        for(int v=0; v<V; v++)
        	if (graph[u][v] && mstSet[v] ==false && graph[u][v]<key[v])
        		parent[v] = u, key[v] = graph[u][v];
    }
    cout<<" Edge\tWeight\n";
	for(int i=1; i<V; i++)
		printf(" %d--%d\t  %d \n", parent[i], i, graph[i][parent[i]]);
}
int main(){
	int V;
	cout<<" Enter The Num Of Vetices :  ";
	cin>>V;
	int graph[10][10];
	cout<<" Enter Adjacency List In 2D Array Form >\n";
	for(int i=0; i<V; i++)
		for(int j=0; j<V; j++)
			cin>>graph[i][j];
//	int graph[V][V] = {{0, 2, 0, 6, 0},
//                      {2, 0, 3, 8, 5},
//                      {0, 3, 0, 0, 7},
//                      {6, 8, 0, 0, 9},
//                      {0, 5, 7, 9, 0},
//                     };
    clock_t start = clock();
    primMST(graph, V);
    clock_t end = clock();
    cout<<"\n Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	cout<<" Time : "<<(end - start)<<" Milliseconds\n";
    return 0;
}


	//prim(G,w r)
//		for each u in G.V
//			u.key = inf
//			u.pi = NIL
//		r.key = 0
//		Q = G.V
//		while Q != null
//		 	u = extractmin(Q)
//		 	for each v in G.Adj(u)
//		 		if v in Q & w(u,v) < v.key
//		 			v.pi = u
//		 			u.key = w(u,v)

//O(ElgV)
