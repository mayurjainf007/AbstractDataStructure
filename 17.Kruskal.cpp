#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
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
struct subset{
    int parent;
    int rank;
};
int find(struct subset subsets[], int i){
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(struct subset subsets[], int x, int y){
	int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int myComp(const void* a, const void* b){
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
void KruskalMST(struct Graph* graph){
    int V = graph->V;
    struct Edge result[V];  // Tnis will store the resultant MST
    int e = 0;  // An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    struct subset *subsets = (struct subset*) malloc( V * sizeof(struct subset) );
    for(int v=0; v<V; ++v){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while(e < V-1){
    	struct Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if(x != y){
        	result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    cout<<" Following Are The Edges In The Constructed MST >\n";
    cout<<" Source\tDestination\tWeight\n";
    for(i=0; i<e; ++i)
    	printf("    %d \t     %d\t      >\t%d\n", result[i].src, result[i].dest,result[i].weight);
    return;
}
int main(){
	int V,E;
	cin>>V>>E;	// V=3 E=3
    struct Graph* graph = createGraph(V, E);
    cout<<"\tSrc\tDest\tWt\n";
    for(int i=0; i<E; i++){
    	// 1 2 5
    	// 2 3 7
    	// 1 3 8
    	cin>>graph->edge[i].src;
    	cin>>graph->edge[i].dest;
    	cin>>graph->edge[i].weight;
	}
	clock_t start = clock();
    KruskalMST(graph);
    clock_t end = clock();
    cout<<"\n Starting Time : "<<start<<"\n";
	cout<<" Ending Time   : "<<end<<"\n";
	cout<<" Time : "<<(end - start)<<" Milliseconds\n";
    return 0;
}
//
//KRUSKAL(G):
//1 A = Ø
//2 foreach v ? G.V:
//3    MAKE-SET(v)
//4 foreach (u, v) in G.E ordered by weight(u, v), increasing:
//5    if FIND-SET(u) ? FIND-SET(v):
//6       A = A ? {(u, v)}
//7       UNION(u, v)
//8 return A

//O(ElgV)
