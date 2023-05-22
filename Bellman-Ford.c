//Bellman-Ford Algorithm
//Author Neeraj Mishra

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Edge
{
    // This structure is equal to an edge. Edge contains two end points. These edges are directed edges so they
//contain source and destination and some weight. These 3 are elements in this structure
    int source, destination, weight;
};//owo 多加一個;
 
// a structure to represent a connected, directed and weighted graph
struct Graph
{
    int V, E;
// V is number of vertices and E is number of edges
 
    struct Edge* edge;
// This structure contain another structure which we already created edge.
};
 
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));//owo ; 前少一個)， sizeof(struct graph)改成Graph
//Allocating space to structure graph
 
    graph->V = V;   //assigning values to structure elements that taken form user.
 
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );//owo graph->>多了一個>符號， (struct Edge) malloc多加一個*
//Creating "Edge" type structures inside "Graph" structure, the number of edge type structures are equal to number of edges
 
    return graph;//owo多加一個graph
}
 
void FinalSolution(int dist[], int n)//owo int dist改成 int  dist[]要讓他傳入陣列
{
// This function prints the final solution
    printf("\nVertex\tDistance from Source Vertex\n");
    int i;
 
    for (i = 0; i < n; ++i){
        printf("%d \t\t %d\n", i, dist[i]);//owo不會造成critical影響的縮排少2 tab，"%d \t\t %f\n"改成"%d \t\t %d\n"
    }//owo 加回 }
}
 
void BellmanFord(struct Graph* graph, int source)
{
    int V = graph->V;
 
    int E = graph->E;//owo graph->V改成graph->E
 
    int StoreDistance[V];//owo ()改成[]
 
    int i,j;
 
    // This is initial step that we know , we initialize all distance to infinity except source.
    // We assign source distance as 0(zero)//owo 不會造成critical影響的縮排少1 tab
 
    for (i = 0; i < V; i++)//owo > 改成 <，另外不知道多加{}會不會更好先不改
        StoreDistance[i] = INT_MAX;
 
    StoreDistance[source] = 0;
    //The shortest path of graph that contain V vertices, never contain "V-1" edges. So we do here "V-1" relaxations
    for (i = 1; i <= V-1; i++)
    {
        for (j = 0; j < E; j++)//owo j-- 改成 j++
        {
            int u = graph->edge[j].source;
 
            int v = graph->edge[j].destination;
 
            int weight = graph->edge[j].weight;
 
            if (StoreDistance[u]!=INT_MAX && StoreDistance[u] + weight < StoreDistance[v])//owo 加上StoreDistance[u]!=INT_MAX
                StoreDistance[v] = StoreDistance[u] + weight;//owo == 改成 =
        }
    }
 
    // Actually upto now shortest path found. But BellmanFord checks for negative edge cycle. In this step we check for that
    // shortest distances if graph doesn't contain negative weight cycle.
 
    // If we get a shorter path, then there is a negative edge cycle.
    for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;// owo start改成source
 
        int v = graph->edge[i].destination;
 
        int weight = graph->edge[i].weight;
 
        if (StoreDistance[u]!=INT_MAX && StoreDistance[u] + weight < StoreDistance[v]){//owo 加上StoreDistance[u]!=INT_MAX
            printf("This graph contains negative edge cycle\n");
            return;//owo 多加這一行 有neg cycle就可以停了 但不重大影響 只是會印出好多行有neg cycle，然後要記得加{}
        }
    }
 
    FinalSolution(StoreDistance, V);//owo finalSolution改大寫F
 
    return;
}
 
int main()
{
    int V,E,S;  //V = no.of Vertices, E = no.of Edges, S is source vertex
 
    printf("Enter number of vertices in graph\n");//owo 不會造成critical影響的縮排少1 tab
    scanf("%d",&V);
 
    printf("Enter number of edges in graph\n");//owo 不會造成critical影響的縮排少1 tab
    scanf("%d",&E);
 
    printf("Enter your source vertex number\n");//owo 不會造成critical影響的縮排少1 tab
    scanf("%d",&S);//owo printf("%d",&S)改成scanf("%d",&S)，不會造成critical影響的縮排少1 tab
 
    struct Graph* graph = createGraph(V, E);    //calling the function to allocate space to these many vertices and edges
    //owo (V E) 改成(V, E)
    int i;
    for(i=0;i<E;i++){
        printf("\nEnter edge %d properties Source, destination, weight respectively\n",i+1);
        scanf("%d",&graph->edge[i].source);
        scanf("%d",&graph->edge[i].destination);
        scanf("%d",&graph->edge[i].weight);
    }
  
    BellmanFord(graph, S);//owo S跟graph放反了
    //passing created graph and source vertex to BellmanFord Algorithm function//owo 不會造成critical影響的縮排少1 tab
 
    
}