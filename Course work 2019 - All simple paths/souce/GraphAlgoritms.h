#pragma once
#include "GraphBuilder.h"

class GraphAlgoritms : public GraphBuilder
{
  /*
   *	Функция поиска всех простых путей между двумя вершинами в графе:
   *		- search_for_ways: выбор вершин пользователем
   *		- depth_crawl: подготовка к поиску
   *				(создание переменных "длина текущего пути" и "количество
   *         путей"массива посещенных вершин)
   *		- dfs: обход графа в глубину
   */
  void search_for_ways(Graph& thisGraph);
  void depth_crawl(Graph& thisGraph, unsigned int& vNum1, unsigned int& vNum2);
  void dfs(Graph& thisGraph,
           int vIndex1,
           int vIndex2,
           int depth,
           int& roadLength,
           int visited[],
           int& quantityRoads);

  void adjacent_vertices(Graph& thisGraph, unsigned int& vertex);

  //  Функция FIRST(v), которая возвращает индекс первой вершины в графе.
  void realization_FIRST(const Graph& thisGraph);
  unsigned int FIRST(const Graph& thisGraph);

  //  Функция NEXT(v, i), которая возвращает индекс вершины, смежной с вершиной
  //  v, следующий за индексом i.
  void realization_Next(Graph& thisGraph);
  unsigned int NEXT(Graph& thisGraph,
                    unsigned int& vertex,
                    unsigned int& index);

  //  Функция VERTEX(v, i), которая возвращает вершину с индексом i из множества
  //  вершин, смежных с v.
  void realization_VERTEX(Graph& thisGraph);
  unsigned int VERTEX(Graph& thisGraph,
                      unsigned int& vertex,
                      unsigned int& index);

public:
  void select_function(Graph& thisGraph) override;
};
