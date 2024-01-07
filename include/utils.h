#ifndef UTILS_H
#define UTILS_H

#include "social_graph.h"
#include "community.h"

// Function to calculate edge betweenness for all edges in the graph
void calculateEdgeBetweenness(Graph *graph, float *edgeBetweenness);

// Function to find the edge with the highest betweenness
Node findMaxBetweennessEdge(Graph *graph, float *edgeBetweenness);

// Function to remove an edge from the graph
void removeEdge(Graph *graph, Node edge);

// Function to compare communities
int compareCommunities(Community *communities, int numNodes);

// Function to check if the size of a community drops below the minimum specified size
int checkMinCommunitySize(Community *communities, int numNodes, int minCommunitySize);

// Function to update communities
void updateCommunities(Graph *graph, Community *communities);

// Function to print the detected communities
void printCommunities(Community *communities, int numCommunities);

// Function to parse a line from the input file
int parseLine(char *line, char *nodeMain, char **connectedNodes);

#endif // UTILS_H
