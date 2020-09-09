#include "GraphAlgoritms.h"

void
GraphAlgoritms::search_for_ways(Graph& thisGraph)
{
  system("cls");

  cout << "\n\n\t\tПоиск простых путей между двумя вершинами\n\n";

  cout << "\tГраф \"" << thisGraph.nameGraph
       << "\"\n\n\tКоличество вершин: " << thisGraph.quantityVertex << "\n\n";

  unsigned int vNum1, vNum2;

  while (true) {
    cout << "\n\tВведите номер первой вершины: ";
    cin >> vNum1;

    if (!thisGraph.check_vertex_number(vNum1) || vNum1 <= 0)
      cout << "\n\tВершины с таким номером нет! Повторите ввод: ";
    else
      break;
  }
  while (true) {
    cout << "\n\tВведите номер второй вершины: ";
    cin >> vNum2;

    if (!thisGraph.check_vertex_number(vNum2) || vNum2 <= 0)
      cout << "\n\tВершины с таким номером нет! Повторите ввод: ";
    else
      break;
  }
  depth_crawl(thisGraph, vNum1, vNum2);

  system("pause");
  system("cls");
}

void
GraphAlgoritms::depth_crawl(Graph& thisGraph,
                            unsigned int& vNum1,
                            unsigned int& vNum2)
{
  system("CLS");

  int vIndex1 = thisGraph.index_search(vNum1),
      vIndex2 = thisGraph.index_search(vNum2);

  int quantityRoads = 0, roadLength = 0,
      *visited = new int[thisGraph.quantityVertex];

  for (int i = 0; i < thisGraph.quantityVertex; i++)
    visited[i] = 0;

  cout << "\n\tПоиск простых путей между вершинами "
       << thisGraph.vertices[vIndex1].label << " и "
       << thisGraph.vertices[vIndex2].label << "\n\n\t\t";

  dfs(thisGraph, vIndex1, vIndex2, 1, roadLength, visited, quantityRoads);

  if (quantityRoads == 0)
    cout << "\n\tПростых путей между вершинами "
         << thisGraph.vertices[vIndex1].label << " и "
         << thisGraph.vertices[vIndex2].label << " не найдено!\n\n\t\t";
  else
    cout << "\n\tВсего простых путей: " << quantityRoads << "\n\n\t\t";

  delete[] visited;
}

void
GraphAlgoritms::dfs(Graph& thisGraph,
                    int vIndex1,
                    int vIndex2,
                    int depth,
                    int& roadLength,
                    int visited[],
                    int& quantityRoads)
{
  visited[vIndex1] = depth;

  if (vIndex1 == vIndex2) {
    quantityRoads++;

    cout << "\n\tПуть №" << quantityRoads << ": ";

    for (int i = 1; i <= depth; i++)
      for (int j = 0; j < thisGraph.quantityVertex; j++)
        if (visited[j] == i) {
          cout << thisGraph.vertices[j].GetLabel() << ' ';

          break;
        }
    cout << "\n\t\tLлина пути lenghtRoad = " << roadLength << endl;
  } else {
    for (unsigned int i = 0; i < thisGraph.quantityVertex; i++) {
      if (thisGraph.matrixAdjacency[vIndex1][i] && visited[i] == 0) {
        roadLength += thisGraph.matrixPowers[vIndex1][i];

        dfs(
          thisGraph, i, vIndex2, depth + 1, roadLength, visited, quantityRoads);

        roadLength -= thisGraph.matrixPowers[vIndex1][i];
      }
    }
  }
  visited[vIndex1] = 0;
}

void
GraphAlgoritms::adjacent_vertices(Graph& thisGraph, unsigned int& vertex)
{
  unsigned int vIndex = thisGraph.index_search(vertex);

  bool* adjacencyObtainedVertex = new bool[thisGraph.quantityVertex];

  cout << "\n\tВершины, смежные с вершиной \'" << vertex << "\':\n";

  for (int i = 0; i < thisGraph.quantityVertex; i++)
    if (thisGraph.matrixAdjacency[vIndex][i] == true)
      cout << "\n\t Index: " << i
           << "\tНомер: " << thisGraph.vertices[i].number;

  cout << endl;

  delete[] adjacencyObtainedVertex;
}

unsigned int
GraphAlgoritms::FIRST(const Graph& thisGraph)
{
  for (int i = 0; i < thisGraph.quantityVertex; i++)
    if (thisGraph.vertices[i].number == 1)
      return i;
}

void
GraphAlgoritms::realization_FIRST(const Graph& thisGraph)
{
  system("cls");

  cout << "\n\t\t\t\tФункция FIRST"
       << "\n\n\t\tФункция возвращает индекс первой вершины в графе\n\n";

  cout << "\tГраф \"" << thisGraph.nameGraph
       << "\"\n\n\tКоличество вершин: " << thisGraph.quantityVertex << "\n\n";

  cout << "\n\tВершина в графе с номером \'1\':"
       << "\n\n\t\tIndex: " << FIRST(thisGraph) << "\n\n\t\t";

  system("pause");
  system("cls");
}

unsigned int
GraphAlgoritms::NEXT(Graph& thisGraph,
                     unsigned int& vertex,
                     unsigned int& index)
{
  unsigned int vIndex = thisGraph.index_search(vertex), result = 0;

  bool* adjacencyObtainedVertex = new bool[thisGraph.quantityVertex];

  for (int i = 0; i < thisGraph.quantityVertex; i++)
    if (thisGraph.matrixAdjacency[vIndex][i] == true)
      adjacencyObtainedVertex[i] = true;
    else
      adjacencyObtainedVertex[i] = false;

  for (int i = index + 1; i < thisGraph.quantityVertex; i++)
    if (adjacencyObtainedVertex[i] == true) {
      result = i;
      break;
    }
  delete[] adjacencyObtainedVertex;

  return result;
}

void
GraphAlgoritms::realization_Next(Graph& thisGraph)
{
  system("cls");

  cout << "\n\t\t\t\tФункция NEXT"
       << "\n\n\t   Функция возвращает индекс вершины, смежной с вершиной "
          "v,\n\t\t\t   следующий за индексом i\n\n";

  cout << "\tГраф \"" << thisGraph.nameGraph
       << "\"\n\n\tКоличество вершин: " << thisGraph.quantityVertex << "\n\n";

  unsigned int vNum, nextIndex;

  while (true) {
    cout << "\n\tВведите номер вершины: ";
    cin >> vNum;

    if (!thisGraph.check_vertex_number(vNum) || vNum <= 0)
      cout << "\n\tВершины с таким номером нет! Повторите ввод: ";
    else
      break;
  }
  adjacent_vertices(thisGraph, vNum);

  while (true) {
    cout << "\n\tВведите индекс, за которым следует индекс искомой вершины: ";
    cin >> nextIndex;

    if (nextIndex >= thisGraph.quantityVertex || nextIndex < 0)
      cout << "\n\tВершины с таким индексом нет! Повторите ввод: ";
    else
      break;
  }
  if (!NEXT(thisGraph, vNum, nextIndex)) {
    cout << "\n\tИндекс вершины, смежной с вершиной \'" << vNum
         << "\',\n\t\t следующий за индексом \'" << nextIndex
         << "\' не найден!\n\n\t\t";
  } else
    cout << "\n\tИндекс вершины, смежной с вершиной \'" << vNum
         << "\',\n\t\t следующий за индексом \'" << nextIndex << "\':"
         << "\n\n\t\tIndex: " << NEXT(thisGraph, vNum, nextIndex) << "\n\n\t\t";

  system("pause");
  system("cls");
}

unsigned int
GraphAlgoritms::VERTEX(Graph& thisGraph,
                       unsigned int& vertex,
                       unsigned int& index)
{
  unsigned int vIndex = thisGraph.index_search(vertex), result = 0;

  bool* adjacencyObtainedVertex = new bool[thisGraph.quantityVertex];

  for (int i = 0; i < thisGraph.quantityVertex; i++)
    if (thisGraph.matrixAdjacency[vIndex][i] == true)
      adjacencyObtainedVertex[i] = true;
    else
      adjacencyObtainedVertex[i] = false;

  if (adjacencyObtainedVertex[index])
    result = thisGraph.vertices[index].number;

  delete[] adjacencyObtainedVertex;

  return result;
}

void
GraphAlgoritms::realization_VERTEX(Graph& thisGraph)
{
  system("cls");

  cout << "\n\t\t\t\tФункция NEXT"
       << "\n\n    Функция возвращает вершину с индексом i из множества "
          "вершин, смежных с v\n\n";

  cout << "\tГраф \"" << thisGraph.nameGraph
       << "\"\n\n\tКоличество вершин: " << thisGraph.quantityVertex << "\n\n";

  unsigned int vNum, nextIndex;

  while (true) {
    cout << "\n\tВведите номер смежной вершины: ";
    cin >> vNum;

    if (thisGraph.check_vertex_number(vNum) && vNum <= 0)
      cout << "\n\tВершины с таким номером нет! Повторите ввод: ";
    else
      break;
  }
  adjacent_vertices(thisGraph, vNum);

  while (true) {
    cout << "\n\tВведите индекс искомой вершины: ";
    cin >> nextIndex;

    if (nextIndex >= thisGraph.quantityVertex || nextIndex < 0)
      cout << "\n\tВершины с таким индексом нет! Повторите ввод: ";
    else
      break;
  }
  if (!VERTEX(thisGraph, vNum, nextIndex)) {
    cout << "\n\tВершина, смежная с вершиной \'" << vNum
         << "\',\n\t\t под индексом \'" << nextIndex
         << "\' не найдена!\n\n\t\t";
  } else
    cout << "\n\tВершина, смежная с вершиной \'" << vNum
         << "\',\n\t\t под индексом \'" << nextIndex << "\':"
         << "\n\n\t\tНомер: " << VERTEX(thisGraph, vNum, nextIndex)
         << "\n\n\t\t";

  system("pause");
  system("cls");
}

void
GraphAlgoritms::select_function(Graph& thisGraph)
{
  while (true) {
    system("cls");

    cout << "\n\t\t\t\tИсследование Графа\n\n";

    cout << "\n\t1. Просмотр графа\n"
         << "\n\t2. Все простые пути между двумя вершинами\n"
         << "\n\t3. FIRST"
         << "\n\t4. NEXT"
         << "\n\t5. VERTEX\n"
         << "\n\t0. Назад\n"
         << "\n\tВведите команду: ";
    int command;
    cin >> command;

    if (command == 0) {
      system("cls");
      break;
    } else
      switch (command) {
        case 1:
          view_graph(thisGraph);
          break;

        case 2:
          search_for_ways(thisGraph);
          break;

        case 3:
          realization_FIRST(thisGraph);
          break;

        case 4:
          realization_Next(thisGraph);
          break;

        case 5:
          realization_VERTEX(thisGraph);
          break;

        default:
          cout << "\n\n\t\tТакой команды нет!\n\n\t\t";
          system("pause");
          system("cls");
      }
  }
}
