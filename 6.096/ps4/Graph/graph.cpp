#include "graph.h"
#include <stdexcept>

Graph::Graph(const vector &starts, const vector &ends) {
    if (starts.size() != ends.size())
        throw invalid_argument("Vectors are not equal.");
    
    for (int i=0; i<starts.size(); i++) {
        int start = starts[i], end = ends[i];
        adjacency_list[start].push_back(end);
        adjacency_list[end];
    }
}

int Graph::numOutGoing(const int nodeID) const {
    map<int,vector<int>>::const_iterator iter = outgoing.find(nodeID);
    if (iter == outgoing.end())
        throw invalid_argument ("Invalid Node ID");
    return adjacency_list[nodeID].size();
}

const vector<int> &Graph::adjacent(const int nodeID) {
    map<int,vector<int>>::const_iterator iter = outgoing.find(nodeID);
    if (iter == outgoing.end())
        throw invalid_argument ("Invalid Node ID");
    return iter->second;
}

