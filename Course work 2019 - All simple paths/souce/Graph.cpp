#include "Graph.h"

Graph::Graph()
{
  this->nameGraph = "No name";
  this->quantityVertex = NULL;
  this->vertices = nullptr;
  this->matrixAdjacency = nullptr;
  this->matrixPowers = nullptr;

  this->saved = false;
}

Graph::Graph(const int& kolVersh, const string& nameInGraph)
{
  this->nameGraph = nameInGraph;
  this->quantityVertex = kolVersh;
  this->vertices = new Vertex[quantityVertex];
  this->matrixAdjacency = new bool*[quantityVertex];
  this->matrixPowers = new double*[quantityVertex];

  for (int i = 0; i < quantityVertex; i++) {
    vertices[i].label = "v" + to_string(i + 1);
    vertices[i].number = i + 1;
    this->matrixAdjacency[i] = new bool[quantityVertex];
    this->matrixPowers[i] = new double[quantityVertex];

    for (int j = 0; j < quantityVertex; j++)
      this->matrixAdjacency[i][j] = this->matrixPowers[i][j] = NULL;
  }

  this->saved = false;
}

Graph::~Graph()
{
  for (int i = 0; i < quantityVertex; i++)
    delete[] matrixAdjacency[i], matrixPowers[i], matrixAdjacency[i] = nullptr,
                                                  matrixPowers[i] = nullptr;

  delete[] vertices, matrixAdjacency, matrixPowers;

  vertices = nullptr;
  matrixAdjacency = nullptr;
  matrixPowers = nullptr;
}

bool
Graph::check_vertex_number(unsigned int& vNum)
{
  bool result = false;

  for (unsigned int i = 0; i < quantityVertex; i++)
    if (vertices[i].number == vNum)
      result = true;

  return result;
}

unsigned int
Graph::index_search(unsigned int& vNum)
{
  for (unsigned int i = 0; i < quantityVertex; i++)
    if (vertices[i].GetNumber() == vNum)
      return i;
}

void
Graph::add_vertex(unsigned int& vNum, string& vName)
{
  Vertex* tempVertices = new Vertex[quantityVertex + 1];
  bool** tempAdjacency = new bool*[quantityVertex + 1];
  double** tempPowers = new double*[quantityVertex + 1];

  for (int i = 0; i < quantityVertex + 1; i++) {
    tempVertices[i].label = "v" + to_string(i + 1);
    tempVertices[i].number = i + 1;
    tempAdjacency[i] = new bool[quantityVertex + 1];
    tempPowers[i] = new double[quantityVertex + 1];

    for (int j = 0; j < quantityVertex + 1; j++) {
      tempAdjacency[i][j] = NULL;
      tempPowers[i][j] = NULL;
    }
  }
  for (int i = 0; i < quantityVertex; i++) {
    tempVertices[i].label = vertices[i].label;
    tempVertices[i].number = vertices[i].number;

    for (int j = 0; j < quantityVertex; j++) {
      tempAdjacency[i][j] = matrixAdjacency[i][j];
      tempPowers[i][j] = matrixPowers[i][j];
    }
  }
  tempVertices[quantityVertex].label = vName;
  tempVertices[quantityVertex].number = vNum;

  for (int i = 0; i < quantityVertex; i++)
    delete[] matrixAdjacency[i], matrixPowers[i];

  delete[] vertices, matrixAdjacency, matrixPowers;

  vertices = tempVertices;
  matrixAdjacency = tempAdjacency;
  matrixPowers = tempPowers;

  quantityVertex++;

  this->saved = false;
}

void
Graph::remove_vertex(unsigned int& vNum)
{
  Vertex* tempVertices = new Vertex[quantityVertex - 1];
  bool** tempAdjacency = new bool*[quantityVertex - 1];
  double** tempPowers = new double*[quantityVertex - 1];

  for (int i = 0; i < quantityVertex - 1; i++) {
    tempVertices[i].label = "v" + to_string(i + 1);
    tempVertices[i].number = i + 1;
    tempAdjacency[i] = new bool[quantityVertex - 1];
    tempPowers[i] = new double[quantityVertex - 1];

    for (int j = 0; j < quantityVertex - 1; j++) {
      tempAdjacency[i][j] = NULL;
      tempPowers[i][j] = NULL;
    }
  }

  unsigned int index = index_search(vNum);

  if (index == 0) {
    for (int i = 1; i < quantityVertex; i++) {
      tempVertices[i - 1].label = vertices[i].label;

      if (vertices[i].number > vNum)
        tempVertices[i - 1].number = vertices[i].number - 1;
      else
        tempVertices[i - 1].number = vertices[i].number;

      for (int j = 1; j < quantityVertex; j++) {
        tempAdjacency[i - 1][j - 1] = matrixAdjacency[i][j];
        tempPowers[i - 1][j - 1] = matrixPowers[i][j];
      }
    }
  } else if (index == quantityVertex) {
    for (int i = 0; i < quantityVertex - 1; i++) {
      tempVertices[i].label = vertices[i].label;
      tempVertices[i].number = vertices[i].number;

      for (int j = 0; j < quantityVertex - 1; j++) {
        tempAdjacency[i][j] = matrixAdjacency[i][j];
        tempPowers[i][j] = matrixPowers[i][j];
      }
    }
  } else {
    for (int i = 0; i < index; i++) {
      tempVertices[i].label = vertices[i].label;
      if (vertices[i].number > vNum)
        tempVertices[i].number = vertices[i].number - 1;
      else
        tempVertices[i].number = vertices[i].number;

      for (int j = 0; j < index; j++) {
        tempAdjacency[i][j] = matrixAdjacency[i][j];
        tempPowers[i][j] = matrixPowers[i][j];
      }
      for (int j = index + 1; j < quantityVertex; j++) {
        tempAdjacency[i][j - 1] = matrixAdjacency[i][j];
        tempPowers[i][j - 1] = matrixPowers[i][j];
      }
    }
    for (int i = index + 1; i < quantityVertex; i++) {
      tempVertices[i - 1].label = vertices[i].label;

      if (vertices[i].number > vNum)
        tempVertices[i - 1].number = vertices[i].number - 1;
      else
        tempVertices[i - 1].number = vertices[i].number;

      for (int j = 0; j < index; j++) {
        tempAdjacency[i - 1][j] = matrixAdjacency[i][j];
        tempPowers[i - 1][j] = matrixPowers[i][j];
      }
      for (int j = index + 1; j < quantityVertex; j++) {
        tempAdjacency[i - 1][j - 1] = matrixAdjacency[i][j];
        tempPowers[i - 1][j - 1] = matrixPowers[i][j];
      }
    }
  }
  for (int i = 0; i < quantityVertex; i++)
    delete[] matrixAdjacency[i], matrixPowers[i];

  delete[] vertices, matrixAdjacency, matrixPowers;

  vertices = tempVertices;
  matrixAdjacency = tempAdjacency;
  matrixPowers = tempPowers;

  quantityVertex--;

  this->saved = false;
}

void
Graph::add_edge(unsigned int& vNum1, unsigned int& vNum2, double& ePower)
{
  unsigned int i1 = index_search(vNum1), i2 = index_search(vNum2);

  matrixAdjacency[i1][i2] = matrixAdjacency[i2][i1] = true;
  matrixPowers[i1][i2] = matrixPowers[i2][i1] = ePower;

  this->saved = false;
}

void
Graph::remove_edge(unsigned int& vNum1, unsigned int& vNum2)
{
  unsigned int i1 = index_search(vNum1), i2 = index_search(vNum2);

  matrixAdjacency[i1][i2] = matrixAdjacency[i2][i1] = false;
  matrixPowers[i1][i2] = matrixPowers[i2][i1] = NULL;

  this->saved = false;
}

void
all_vertices(const Graph& thisGraph)
{
  cout << "\n\tВершины графа:\n"
       << "\n\t\tИндекс\t|\tНомер\t|\tНазвание\n";

  for (int i = 0; i < thisGraph.quantityVertex; i++)
    cout << "\n\t\t" << i << "\t|\t" << thisGraph.vertices[i].number << "\t|\t"
         << thisGraph.vertices[i].label;

  cout << endl;
}

void
view_graph(const Graph& thisGraph)
{
  system("cls");

  cout
    << "\n\t     © Российский технологический университет – МИРЭА, 2019\n\t\t"
    << "\t     Неопределенные Графы\n\n";

  cout << "\tГраф \"" << thisGraph.nameGraph
       << "\"\n\n\tКоличество вершин: " << thisGraph.quantityVertex << "\n\n";

  all_vertices(thisGraph);

  cout << "\n\n\t   Матрица Смежности:\n\n  ";

  cout << "ind  ";
  for (int i = 0; i < thisGraph.quantityVertex; i++)
    cout << i << "  ";

  for (int i = 0; i < thisGraph.quantityVertex; i++) {
    if (i < 10)
      cout << "\n   " << i << ' ';
    else
      cout << "\n   " << i;

    for (int j = 0; j < thisGraph.quantityVertex; j++)
      if (j > 10)
        cout << "   " << thisGraph.matrixAdjacency[i][j];
      else
        cout << "  " << thisGraph.matrixAdjacency[i][j];
  }

  cout << "\n\n\n\t   Матрица Весов Дуг:\n\n  ";

  cout << "ind  ";
  for (int i = 0; i < thisGraph.quantityVertex; i++)
    cout << i << "  ";

  for (int i = 0; i < thisGraph.quantityVertex; i++) {
    if (i < 10)
      cout << "\n   " << i << ' ';
    else
      cout << "\n   " << i;

    for (int j = 0; j < thisGraph.quantityVertex; j++)
      if (j > 10)
        cout << "   " << thisGraph.matrixPowers[i][j];
      else
        cout << "  " << thisGraph.matrixPowers[i][j];
  }
  cout << "\n\n\n\n\t\t";
  system("Pause");
  system("cls");
}

void
graph_menu(Graph& thisGraph);

bool
Load_Graph_From_File(Graph& thisGraph, const string& nameInFile)
{
  thisGraph.nameGraph = nameInFile;

  string inString, temp;
  int state = 0, lineIndex = 0;

  unsigned int vNum;
  string vLabel;

  unsigned int vNum1 = 0, vNum2 = 0;
  double ePower;

  ifstream inFile;

  inFile.open(nameInFile, ios::in);

  if (inFile.is_open()) {
    state = 1;

    while (!inFile.eof()) {
      getline(inFile, inString);
      lineIndex++;

      if (!empty(inString)) {
        if (state == 1) {
          if (inString == "#")
            state = 2;
          else {
            temp = "";
            int i = 0;

            for (auto c : inString + " ") {
              if (c != ' ')
                temp += c;
              else if (i == 0)
                vNum = stoi(temp), i++, temp = "";
              else if (i == 1)
                vLabel = temp;
            }
            thisGraph.add_vertex(vNum, vLabel);
          }
        } else if (state == 2) {
          temp = "";
          int i = 0;
          ePower = 1;

          for (auto c : inString + " ") {
            if (c != ' ')
              temp += c;
            else if (i == 0)
              vNum1 = stoi(temp), i++, temp = "";
            else if (i == 1)
              vNum2 = stoi(temp), i++, temp = "";
            else if (i == 2)
              ePower = atof(temp.c_str());
          }
          thisGraph.add_edge(vNum1, vNum2, ePower);
        }
      }
    }
    inFile.close();
    thisGraph.saved = true;

    graph_menu(thisGraph);
    return 0;
  } else {
    cout << "\n\tОшибка открытия файла: " + nameInFile << "\n\n\t\t";
    system("Pause");
    return 1;
  }
}

bool
Save_Graph_To_File(Graph& thisGraph, const string& nameOutFile)
{
  ofstream outFile;
  outFile.open(nameOutFile, ios::out);
  if (outFile.is_open()) {
    for (int i = 0; i < thisGraph.quantityVertex; i++) {
      outFile << thisGraph.vertices[i].number;
      if (thisGraph.vertices[i].label != "")
        outFile << " " << thisGraph.vertices[i].label;
      outFile << endl;
    }
    outFile << "#" << endl;

    for (int i = 0; i < thisGraph.quantityVertex; i++)
      for (int j = i; j < thisGraph.quantityVertex; j++)
        if (thisGraph.matrixPowers[i][j] != 0)
          outFile << thisGraph.vertices[i].number << ' '
                  << thisGraph.vertices[j].number << ' '
                  << thisGraph.matrixPowers[i][j] << endl;
    outFile.close();
    thisGraph.saved = true;

    cout << "\n\tГраф сохранен в файл: " << nameOutFile << "\n\n\t\t";

    system("Pause");
    return 0;
  } else {
    cout << "\n\tОшибка создания файла: " + nameOutFile << "\n\n\t\t";
    return 1;
  }
}
