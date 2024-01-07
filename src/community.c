#include <stdio.h>

#include "social_graph.h"
#include "community.h"
#include "utils.h"

void detectCommunities(Graph *graph, int minCommunitySize)
{
    Community communities[MAX_NODES]; // Array to store detected communities
    float edgeBetweenness[MAX_NODES]; // Array to store edge betweenness values

    int i = 0;
    // Initialize communities
    for (; i < MAX_NODES; ++i)
    {
        communities[i].numMembers = 0;
    }

    // Detect communities until a stopping criterion is met
    int iteration = 0;
    int stopIteration = 0;

    while (!stopIteration)
    {
        // Calculate edge betweenness for all edges
        calculateEdgeBetweenness(graph, edgeBetweenness);

        // Find the edge with the highest betweenness
        Node maxBetweennessEdge = findMaxBetweennessEdge(graph, edgeBetweenness);

        // Remove the edge with the highest betweenness
        removeEdge(graph, maxBetweennessEdge);

        // Increment the iteration counter
        iteration++;

        // Check stopping criteria
        if (iteration > 1)
        {
            if (iteration % 2 == 0)
            {
                // Stopping criterion 3.a: If the number of communities remains the same for k consecutive iterations
                if (compareCommunities(communities, graph->numNodes))
                    stopIteration = 1;
            }
            else
            {
                // Stopping criterion 3.b: If the size of a community drops below the minimum specified size
                if (checkMinCommunitySize(communities, graph->numNodes, minCommunitySize))
                    stopIteration = 1;
            }
        }

        // Update communities
        updateCommunities(graph, communities);
    }

    // Print the detected communities
    printCommunities(communities, graph->numNodes);
}
