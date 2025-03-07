#include "tdd_code.h"
#include <cstddef>
#include <sys/types.h>
Graph::Graph()
    : l_nodes(), l_neighbour()
{
}
Graph::~Graph(){
    std::cout << "Destructor" << std::endl;
    for(Node *node: l_nodes){
        delete node;
    }
}
Node * Graph::addNode(size_t id){
    Node *newNode = new Node{id,0};
    l_nodes.push_back(newNode);
    l_neighbour.push_back(std::vector<size_t>());
    return newNode;
}
bool Graph::addEdge(const Edge& edge){
    Node *sourceNode = getNode(edge.a);
    Node *destNode = getNode(edge.b);
    if(!sourceNode || !destNode ){
        return false;
    }
    if(containsEdge(edge)){
        return false;
       }
    l_neighbour[edge.a].push_back(edge.b);
    l_neighbour[edge.b].push_back(edge.a);
    return true;
}
void Graph::addMultipleEdges(const std::vector<Edge>& edges){
    for(const Edge& edge:edges){
        bool correct = addEdge(edge);
        if(!correct){

        }

    }
}
Node *Graph::getNode(size_t nodeId){
    for(Node *node:l_nodes){
        if(node->id == nodeId){
           return node;
        }
    }
    return nullptr;
}
bool Graph::containsEdge(const Edge& edge){


}
