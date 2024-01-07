#include <stdio.h>

#include "social_graph.h"

void initializeGraph(Graph *graph)
{
    graph->numNodes = 0;
}

void addNode(Graph *graph, char *nodeMain, char **connectedNodes)
{
    Node node;

    node.nodeMain = nodeMain;
    node.connectedNodes = connectedNodes;

    graph->numNodes++;

    int i = 0;
    int i = 0;
    while (connectedNodes[i] != NULL)
    {
        if (connectedNodes[i] != NULL) // add connected node to the graph
        {
            graph->nodes[graph->numNodes].numConnectedNodes++;
        }
        i++;
    }

    printf("Added node %s with %d many connected nodes\n", nodeMain, graph->nodes[graph->numNodes].numConnectedNodes);
}

void printGraph(Graph *graph)
{

    int i = 0;
    for (; i < graph->numNodes; ++i)
    {
        printf("Node %d: %s\n", i, graph->nodes[i].nodeMain);
        printf("Connected nodes: ");

        int j = 0;
        for (; j < graph->nodes[i].numConnectedNodes; ++j)
        {
            printf("%s ", graph->nodes[i].connectedNodes[j]);
        }
        printf("\n");
    }
}
