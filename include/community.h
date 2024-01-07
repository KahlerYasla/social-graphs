#ifndef COMMUNITY_H
#define COMMUNITY_H

#include "social_graph.h"

// Structure to represent a community
typedef struct
{
    int members[MAX_NODES]; // Array to store community members
    int numMembers;         // Number of members in the community
} Community;

// Function to detect communities in a graph
void detectCommunities(Graph *graph, int minCommunitySize);

#endif // COMMUNITY_H
