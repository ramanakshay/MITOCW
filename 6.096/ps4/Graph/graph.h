#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Graph {
    map<int, vector<int>> adjacency_list;
    
    public:
        Graph(const vector &starts, const vector &ends);
        int numOutgoing(const int nodeID);
        const vector<int> &adjacent(const int nodeID);
};