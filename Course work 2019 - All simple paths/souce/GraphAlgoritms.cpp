#include "GraphAlgoritms.h"

void
GraphAlgoritms::search_for_ways(Graph& thisGraph)
{
  system("cls");

  cout << "\n\n\t\t����� ������� ����� ����� ����� ���������\n\n";

  cout << "\t���� \"" << thisGraph.nameGraph
       << "\"\n\n\t���������� ������: " << thisGraph.quantityVertex << "\n\n";

  unsigned int vNum1, vNum2;

  while (true) {
    cout << "\n\t������� ����� ������ �������: ";
    cin >> vNum1;

    if (!thisGraph.check_vertex_number(vNum1) || vNum1 <= 0)
      cout << "\n\t������� � ����� ������� ���! ��������� ����: ";
    else
      break;
  }
  while (true) {
    cout << "\n\t������� ����� ������ �������: ";
    cin >> vNum2;

    if (!thisGraph.check_vertex_number(vNum2) || vNum2 <= 0)
      cout << "\n\t������� � ����� ������� ���! ��������� ����: ";
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

  cout << "\n\t����� ������� ����� ����� ��������� "
       << thisGraph.vertices[vIndex1].label << " � "
       << thisGraph.vertices[vIndex2].label << "\n\n\t\t";

  dfs(thisGraph, vIndex1, vIndex2, 1, roadLength, visited, quantityRoads);

  if (quantityRoads == 0)
    cout << "\n\t������� ����� ����� ��������� "
         << thisGraph.vertices[vIndex1].label << " � "
         << thisGraph.vertices[vIndex2].label << " �� �������!\n\n\t\t";
  else
    cout << "\n\t����� ������� �����: " << quantityRoads << "\n\n\t\t";

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

    cout << "\n\t���� �" << quantityRoads << ": ";

    for (int i = 1; i <= depth; i++)
      for (int j = 0; j < thisGraph.quantityVertex; j++)
        if (visited[j] == i) {
          cout << thisGraph.vertices[j].GetLabel() << ' ';

          break;
        }
    cout << "\n\t\tL���� ���� lenghtRoad = " << roadLength << endl;
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

  cout << "\n\t�������, ������� � �������� \'" << vertex << "\':\n";

  for (int i = 0; i < thisGraph.quantityVertex; i++)
    if (thisGraph.matrixAdjacency[vIndex][i] == true)
      cout << "\n\t Index: " << i
           << "\t�����: " << thisGraph.vertices[i].number;

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

  cout << "\n\t\t\t\t������� FIRST"
       << "\n\n\t\t������� ���������� ������ ������ ������� � �����\n\n";

  cout << "\t���� \"" << thisGraph.nameGraph
       << "\"\n\n\t���������� ������: " << thisGraph.quantityVertex << "\n\n";

  cout << "\n\t������� � ����� � ������� \'1\':"
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

  cout << "\n\t\t\t\t������� NEXT"
       << "\n\n\t   ������� ���������� ������ �������, ������� � �������� "
          "v,\n\t\t\t   ��������� �� �������� i\n\n";

  cout << "\t���� \"" << thisGraph.nameGraph
       << "\"\n\n\t���������� ������: " << thisGraph.quantityVertex << "\n\n";

  unsigned int vNum, nextIndex;

  while (true) {
    cout << "\n\t������� ����� �������: ";
    cin >> vNum;

    if (!thisGraph.check_vertex_number(vNum) || vNum <= 0)
      cout << "\n\t������� � ����� ������� ���! ��������� ����: ";
    else
      break;
  }
  adjacent_vertices(thisGraph, vNum);

  while (true) {
    cout << "\n\t������� ������, �� ������� ������� ������ ������� �������: ";
    cin >> nextIndex;

    if (nextIndex >= thisGraph.quantityVertex || nextIndex < 0)
      cout << "\n\t������� � ����� �������� ���! ��������� ����: ";
    else
      break;
  }
  if (!NEXT(thisGraph, vNum, nextIndex)) {
    cout << "\n\t������ �������, ������� � �������� \'" << vNum
         << "\',\n\t\t ��������� �� �������� \'" << nextIndex
         << "\' �� ������!\n\n\t\t";
  } else
    cout << "\n\t������ �������, ������� � �������� \'" << vNum
         << "\',\n\t\t ��������� �� �������� \'" << nextIndex << "\':"
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

  cout << "\n\t\t\t\t������� NEXT"
       << "\n\n    ������� ���������� ������� � �������� i �� ��������� "
          "������, ������� � v\n\n";

  cout << "\t���� \"" << thisGraph.nameGraph
       << "\"\n\n\t���������� ������: " << thisGraph.quantityVertex << "\n\n";

  unsigned int vNum, nextIndex;

  while (true) {
    cout << "\n\t������� ����� ������� �������: ";
    cin >> vNum;

    if (thisGraph.check_vertex_number(vNum) && vNum <= 0)
      cout << "\n\t������� � ����� ������� ���! ��������� ����: ";
    else
      break;
  }
  adjacent_vertices(thisGraph, vNum);

  while (true) {
    cout << "\n\t������� ������ ������� �������: ";
    cin >> nextIndex;

    if (nextIndex >= thisGraph.quantityVertex || nextIndex < 0)
      cout << "\n\t������� � ����� �������� ���! ��������� ����: ";
    else
      break;
  }
  if (!VERTEX(thisGraph, vNum, nextIndex)) {
    cout << "\n\t�������, ������� � �������� \'" << vNum
         << "\',\n\t\t ��� �������� \'" << nextIndex
         << "\' �� �������!\n\n\t\t";
  } else
    cout << "\n\t�������, ������� � �������� \'" << vNum
         << "\',\n\t\t ��� �������� \'" << nextIndex << "\':"
         << "\n\n\t\t�����: " << VERTEX(thisGraph, vNum, nextIndex)
         << "\n\n\t\t";

  system("pause");
  system("cls");
}

void
GraphAlgoritms::select_function(Graph& thisGraph)
{
  while (true) {
    system("cls");

    cout << "\n\t\t\t\t������������ �����\n\n";

    cout << "\n\t1. �������� �����\n"
         << "\n\t2. ��� ������� ���� ����� ����� ���������\n"
         << "\n\t3. FIRST"
         << "\n\t4. NEXT"
         << "\n\t5. VERTEX\n"
         << "\n\t0. �����\n"
         << "\n\t������� �������: ";
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
          cout << "\n\n\t\t����� ������� ���!\n\n\t\t";
          system("pause");
          system("cls");
      }
  }
}
