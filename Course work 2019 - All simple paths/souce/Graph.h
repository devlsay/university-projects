#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Vertex
{
public:
  string label;
  unsigned int number;

  string GetLabel() { return label; }
  unsigned int GetNumber() { return number; }
};

class Graph
{
  string nameGraph;
  unsigned int quantityVertex;
  Vertex* vertices;
  bool** matrixAdjacency;
  double** matrixPowers;

public:
  Graph();
  Graph(const int& kolVersh, const string& nameInGraph);
  ~Graph();

  bool saved;

  bool check_vertex_number(unsigned int& vNum);
  unsigned int index_search(unsigned int& vNum);

  void add_vertex(unsigned int& vNum, string& vName);
  void remove_vertex(unsigned int& vNum);
  void add_edge(unsigned int& vNum1, unsigned int& vNum2, double& ePower);
  void remove_edge(unsigned int& vNum1, unsigned int& vNum2);

  string GetGraphName() { return nameGraph; }
  unsigned int GetQuantityVertex() { return quantityVertex; }

  friend void all_vertices(const Graph& thisGraph);
  friend void view_graph(const Graph& thisGraph);

  friend bool Load_Graph_From_File(Graph& thisGraph, const string& nameInFile);
  friend bool Save_Graph_To_File(Graph& thisGraph, const string& nameOutFile);

  friend class GraphBuilder;
  friend class GraphAlgoritms;
};
