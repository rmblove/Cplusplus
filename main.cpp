//
//  main.cpp
//  stanford_test
//
//  Created by Lex.Luther on 16/6/5.
//  Copyright © 2016年 Lex.Luther. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "heaque.hpp"
#include "Heap.hpp"
#include "PQueue.hpp"
#include "assignment_3.hpp"
#include "sort.hpp"
#include "strlib.h"
#include "random.h"


/*
 * CS 106B Section 07 Problems
 */

#include "console.h"
#include "basicgraph.h"
using namespace std;

void testKthLevelFriends(); // section problem 5
void testIsReachable(); // section problem 6
void testIsConnected(); // section problem 7
void testFindMinimumVertexCover(); // section problem 8

Set<Vertex*> kthLevelFriends(BasicGraph& graph, Vertex* v, int k);
bool isReachable(BasicGraph& graph, Vertex* v1, Vertex* v2);
bool isConnected(BasicGraph& graph);
Set<Vertex*> findMinimumVertexCover(BasicGraph& graph);

int main() {
    setConsoleSize(750, 500);
    setConsoleFont("Monospaced-Bold-14");
    setConsoleEcho(true);
    
    // run tests
    testKthLevelFriends();
    testIsReachable();
    testIsConnected();
    testFindMinimumVertexCover();
    
    return 0;
}


void testKthLevelFriends() {
    BasicGraph graph;
    graph.addVertex("Marty");
    graph.addVertex("Mehran");
    graph.addVertex("Cynthia");
    graph.addVertex("Eric");
    graph.addVertex("Keith");
    graph.addVertex("Patrick");
    graph.addEdge("Marty", "Cynthia");
    graph.addEdge("Marty", "Mehran");
    graph.addEdge("Eric", "Mehran");
    graph.addEdge("Cynthia", "Keith");
    
    cout << "kthLevelFriends:" << endl;
    Set<Vertex*> friends = kthLevelFriends(graph, graph.getVertex("Marty"), 1);
    Set<Vertex*> friendsOfFriends = kthLevelFriends(graph, graph.getVertex("Marty"), 2);
    for(Vertex* v : friends) {
        cout << "k = 1 friend: " << v->name << endl;
    }
    cout << "k = 1 friends above should be {Mehran, Cynthia}" << endl;
    for(Vertex* v : friendsOfFriends) {
        cout << "k = 2 friend: " << v->name << endl;
    }
    cout << "k = 2 friends above should be {Keith}" << endl;
}


void testIsReachable() {
    BasicGraph graph;
    graph.addVertex("a");
    graph.addVertex("b");
    graph.addVertex("c");
    graph.addVertex("d");
    graph.addEdge("a", "b");
    graph.addEdge("b", "d");
    graph.addEdge("d", "c");
    cout << "isReachable:" << endl;
    cout << boolalpha << isReachable(graph, graph.getVertex("a"), graph.getVertex("d")) << " should be true" << endl;
    cout << boolalpha << isReachable(graph, graph.getVertex("c"), graph.getVertex("a")) << " should be false" << endl;
    cout << boolalpha << isReachable(graph, graph.getVertex("a"), graph.getVertex("a")) << " should be true" << endl;
}


void testIsConnected() {
    BasicGraph graph;
    cout << "isConnected:" << endl;
    cout << boolalpha << isConnected(graph) << " should be true" << endl;
    graph.addVertex("a");
    graph.addVertex("b");
    graph.addVertex("c");
    graph.addEdge("a", "b");
    graph.addEdge("b", "c");
    cout << boolalpha << isConnected(graph) << " should be false" << endl;
    graph.addEdge("c", "a");
    cout << boolalpha << isConnected(graph) << " should be true" << endl;
}


void testFindMinimumVertexCover() {
    BasicGraph graph;
    graph.addVertex("a");
    graph.addVertex("b");
    graph.addVertex("c");
    graph.addVertex("d");
    graph.addVertex("e");
    graph.addEdge("a", "b");
    graph.addEdge("b", "a");
    graph.addEdge("a", "c");
    graph.addEdge("c", "a");
    graph.addEdge("a", "d");
    graph.addEdge("d", "a");
    graph.addEdge("a", "e");
    graph.addEdge("e", "a");
    
    cout << "findMinimumVertexCover:" << endl;
    Set<Vertex*> cover1 = findMinimumVertexCover(graph);
    graph.addEdge("d", "e");
    graph.addEdge("e", "d");
    Set<Vertex*> cover2 = findMinimumVertexCover(graph);
    for (Vertex* v : cover1) {
        cout << v->name << endl;
    }
    cout << "vertices above should be {a}" << endl;
    for (Vertex* v : cover2) {
        cout << v->name << endl;
    }
    cout << "vertices above should be {a, e} or {a, d}" << endl;
}


Set<Vertex*> kthLevelFriends(BasicGraph& graph, Vertex* v, int k) {
    // TODO: finish me!
    return {};
}


bool isReachable(BasicGraph& graph, Vertex* v1, Vertex* v2) {
    // TODO: finish me!
    return false;
}


bool isConnected(BasicGraph& graph) {
    // TODO: finish me!
    return false;
}


Set<Vertex*> findMinimumVertexCover(BasicGraph& graph) {
    // TODO: finish me!
    return {};
}


