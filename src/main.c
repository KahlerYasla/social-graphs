#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "social_graph.h"
#include "community.h"
#include "utils.h"
#include "colored_output.h"

#define MAX_LINE_LENGTH 100

int main()
{
    LogCyan("SOCIAL NETWORK COMMUNITY DETECTION\n");
    printf("========================================\n");

    FILE *inputFile = fopen("data/input.txt", "r");
    if (inputFile == NULL)
    {
        perror("Error opening input.txt");
        return 1;
    }
    else
    {
        LogGreen("Opened input.txt successfully\n");
    }

    Graph graph;
    initializeGraph(&graph);

    printf("========================================\n");
    LogYellow("Reading input.txt and building graph...\n");

    char *line = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    char *nodeMain = (char *)malloc(sizeof("LONGESTNODENAMEALLOWED"));
    char **connectedNodes = (char **)malloc(MAX_NODES * sizeof("LONGESTNODENAMEALLOWED"));

    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL)
    {
        // Parse the line to extract nodeMain and connectedNodes
        if (parseLine(line, nodeMain, connectedNodes))
        {
            // Add the main node and connected nodes to the graph
            addNode(&graph, nodeMain, connectedNodes);
        }
    }

    fclose(inputFile);

    printf("========================================\n");

    LogGreen("Successfully built graph\n");
    printf("========================================\n");

    LogYellow("Printing graph...\n");
    printGraph(&graph);
    printf("========================================\n");

    LogYellow("Detecting communities...\n");

    // // Assuming you have a variable `t` representing the minimum community size
    // int t = 4;

    // // Detect communities in the social network
    // detectCommunities(&graph, t);

    // Free allocated memory
    free(line);
    free(nodeMain);

    for (int i = 0; connectedNodes[i] != NULL; ++i)
    {
        free(connectedNodes[i]);
    }
    free(connectedNodes);

    printf("\n========================================\n");

    return 0;
}
