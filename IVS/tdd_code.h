 //======= Copyright (c) 2025, FIT VUT Brno, All rights reserved. ============//
 //
 // Purpose:     Test Driven Development - graph
 //
 // $NoKeywords: $ivs_project_1 $tdd_code.h
 // $Author:     Josef Pasek <xpasekj00@stud.fit.vutbr.cz>
 // $Date:       2025-02-19
 //============================================================================//
 #pragma once

 #ifndef TDD_CODE_H_
 #define TDD_CODE_H_

 #include <vector>
 #include <stdexcept>
 #include <iostream>

 // Místo pro Vaše případné includy, používejte pouze standardní knihovnu tak, aby nebylo nutno upravovat CMake.

 struct Node{
     size_t id;
     size_t color;
     // doplňte vhodné struktury, pokud potřebujete
 };

 class Edge{
 public:
     size_t a;
     size_t b;

     Edge(size_t a, size_t b) : a(a), b(b) { }

     bool operator==(const Edge& other) const{
         return (a == other.a && b == other.b) || (a == other.b && b == other.a);
     }

     bool operator!=(const Edge& other) const{
         return !(*this == other);
     }

     friend std::ostream& operator<<(std::ostream& os, const Edge& e) {
         return os << "{" << e.a << ", " << e.b << "}";
     }
 };

 class Graph{
 public:

     Graph();

     ~Graph();

     std::vector<Node*> nodes();

     std::vector<Edge> edges() const;

     Node* addNode(size_t nodeId);

     bool addEdge(const Edge& edge);

     void addMultipleEdges(const std::vector<Edge>& edges);

     Node* getNode(size_t nodeId);

     bool containsEdge(const Edge& edge) const;

     void removeNode(size_t nodeId);

     void removeEdge(const Edge& edge);

     size_t nodeCount() const;

     size_t edgeCount() const;

     size_t nodeDegree(size_t nodeId) const;

     size_t graphDegree() const;

     void coloring();

     void clear();

 protected:
     std::vector<Node*> l_nodes;
     std::vector<std::vector<size_t>> l_neighbour;

 };

 #endif // TDD_CODE_H_

 /*** Konec souboru tdd_code.h ***/
