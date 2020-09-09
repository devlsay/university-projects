#include "GraphBuilder.h"

void
GraphBuilder::add_vertex_by_vName(Graph& thisGraph)
{
  system("CLS");

  cout << "\n\t\t\t\tСоздать вершину\n\n";

  all_vertices(thisGraph);

  unsigned int vNum = thisGraph.quantityVertex + 1;
  cout << "\n\n\tВведите название новой вершины с номером \'" << vNum << "\': ";
  string vName;
  cin.ignore();
  getline(cin, vName);

  thisGraph.add_vertex(vNum, vName);

  cout << "\n\tВершина \"" << vName << "\" с номером \'" << vNum
       << "\' добавлена в граф!\n\n\t";

  system("Pause");
  system("CLS");
}

void
GraphBuilder::remove_vertex_by_vNum(Graph& thisGraph)
{
  unsigned int vNum;

  while (true) {
    system("CLS");

    cout << "\n\t\t\t\tУдалить вершину\n\n";

    all_vertices(thisGraph);

    cout << "\n\n\tВведите номер удаляемой вершины: ";
    cin >> vNum;

    if (!thisGraph.check_vertex_number(vNum) || vNum <= 0) {
      cout << "\n\n\t\tВершины с таким номером нет!\n\n\t\t";

      system("Pause");
      system("CLS");
    } else
      break;
  }
  thisGraph.remove_vertex(vNum);

  cout << "\n\tВершина с номером \'" << vNum << "\' удалена из графа!\n\n\t";
  system("Pause");
  system("CLS");
}

void
GraphBuilder::add_edge_by_vNums(Graph& thisGraph)
{
  system("CLS");

  cout << "\n\t\t\t\tСоздать ребро\n\n";

  all_vertices(thisGraph);

  unsigned int vNum1, vNum2;
  double ePower;

  cout << endl;

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
  while (true) {
    cout << "\n\tВведите вес ребра: ";
    cin >> ePower;
    break;
  }
  thisGraph.add_edge(vNum1, vNum2, ePower);

  cout << "\n\tРебро с весом \'" << ePower << "\'\n\t\t"
       << " из вершины \'" << vNum1 << "\' в вершину \'" << vNum2
       << "\' создано!\n\n\t";
  system("Pause");
  system("CLS");
}

void
GraphBuilder::remove_edge_by_vNum(Graph& thisGraph)
{
  system("CLS");

  cout << "\n\t\t\t\tУдалить ребро\n\n";

  all_vertices(thisGraph);

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
  thisGraph.remove_edge(vNum1, vNum2);

  cout << "\n\tРебро из вершины \'" << vNum1 << "\' в вершину \'" << vNum2
       << "\' удалено!\n\n\t";
  system("Pause");
  system("CLS");
}

void
GraphBuilder::select_function(Graph& thisGraph)
{
  while (true) {
    system("CLS");

    cout << "\n\t\t\t\tРедактор Графов\n\n";

    cout << "\n\t1. Просмотр графа\n"
         << "\n\t2. Создать вершину"
         << "\n\t3. Удалить вершину\n"
         << "\n\t4. Создать ребро"
         << "\n\t5. Удалить ребро\n"
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
          add_vertex_by_vName(thisGraph);
          break;

        case 3:
          remove_vertex_by_vNum(thisGraph);
          break;

        case 4:
          add_edge_by_vNums(thisGraph);
          break;

        case 5:
          remove_edge_by_vNum(thisGraph);
          break;

        default:
          cout << "\n\n\t\tТакой команды нет!\n\n\t\t";
          system("pause");
          system("cls");
      }
  }
}
