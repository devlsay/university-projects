#pragma once
#include "Graph.h"

class GraphBuilder
{
  void add_vertex_by_vName(Graph& thisGraph);
  void remove_vertex_by_vNum(Graph& thisGraph);

  void add_edge_by_vNums(Graph& thisGraph);
  void remove_edge_by_vNum(Graph& thisGraph);

public:
  virtual ~GraphBuilder() {}

  virtual void select_function(Graph& thisGraph);
};
