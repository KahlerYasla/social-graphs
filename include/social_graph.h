#ifndef SOCIAL_GRAPH
#define SOCIAL_GRAPH

#define MAX_NODES 100

// Structure to represent an edge in the graph
typedef struct
{
    char *nodeMain;
    char **connectedNodes;
    int numConnectedNodes;
} Node;

// Structure to represent a graph
typedef struct
{
    Node nodes[MAX_NODES]; // Array to store edges
    int numNodes;          // Number of nodes in the graph
} Graph;

// Function to initialize a graph
void initializeGraph(Graph *graph);

// Function to add an edge to the graph
void addNode(Graph *graph, char *nodeMain, char **connectedNodes);

// Function to print the graph
void printGraph(Graph *graph);

#endif // SOCIAL_GRAPH
