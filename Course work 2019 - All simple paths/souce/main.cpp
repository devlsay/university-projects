#include <Windows.h>

#include "GraphAlgoritms.h"
#include "list.h"

dst::list<Graph> GraphList;

Graph* newGraph; // Очистится память и присвоится nullptr после первого же
                 // изменения графа

GraphAlgoritms GAObj;
GraphBuilder GBObj, *pGBObj;

bool
Load_Graph_From_File(Graph& thisGraph, const string& nameInFile);
bool
Save_Graph_To_File(Graph& thisGraph, const string& nameOutFile);

void
about_the_program()
{
  system("CLS");

  cout << "\n\t     © Российский технологический университет – МИРЭА, 2019"
       << "\n\t\t\t\t О программе\n";

  cout << "\n\t\t\t© Саяпин В.Д.\tБББО - 07 - 18\n\n";

  cout << "\n\t\t\t       Курсовая работа"
       << "\n\t\t\t        по дисциплине"
       << "\n\t\t\t  \"Языки программирования\"\n\n";

  cout << "\n\t\tВариант 57 (Шифр студенческого билета: 18Б1457)\n\n";

  cout << "\n    Задание:\n"
       << "\n\tНапишите программу,"
       << "\n\t    на входе которой вводится две его вершины (графа)."
       << "\n\tПрограмма должна распечатывать все простые пути,"
       << "\n\t    ведущие от одной вершины к другой.\n"
       << "\n\tГраф представлен в виде Матрицы Смежности.\n\n";

  cout
    << "\n    Инструкции к программе:\n"
    << "\n\t- Программа работает с неорентированными графами"
    << "\n\t      (любой загруженный граф в программу становится "
       "неорентированным);\n"
    << "\n\t- Граф с количеством вершин более 20 отображается некорректно;\n"
    << "\n\t- Программа поддерживает ввод названия файла Графа с пробелами;\n"
    << "\n\t- Если Граф был изменен в процессе работы программы был,"
    << "\n\t      то его можно сохранить вручную,"
    << "\n\t      если Граф не был сохранен пользователем,"
    << "\n\t\t  то при выходе программа предложит сохранить граф в новый "
       "файл;\n"
    << "\n\t- В программе можно открыть сразу несколько файлов с Графами,"
    << "\n\t      при этом можно выбирать, с каким графом работать,"
    << "\n\t      функция выбора графа отображается в главном меню,"
    << "\n\t\t  если количество загруженных графов больше или равно одному;\n";

  cout << "\n\n\t\t";
  system("Pause");
  system("CLS");
}

void
graph_menu(Graph& thisGraph)
{
  while (true) {
    system("CLS");

    cout << "\n\t     © Российский технологический университет – МИРЭА, 2019"
         << "\n\t\t\t\tГлавное Меню\n\n";

    cout << "\n\t1. Исследовать граф"
         << "\n\t2. Редактировать граф";

    if (!thisGraph.saved)
      cout << "\n\t3. Сохранить граф в файл...";

    cout << "\n\n\t0. Назад\n"
         << "\n\tВведите команду: ";

    int command;
    cin >> command;

    if (command == 0)
      break;
    else {
      string nameFile;

      switch (command) {
        case 1:
          pGBObj = &GAObj;
          pGBObj->select_function(thisGraph);
          break;

        case 2:
          pGBObj = &GBObj;
          pGBObj->select_function(thisGraph);
          break;

        case 3:
          if (!thisGraph.saved) {
            system("CLS");

            cout << "\n\t\t\t     Сохранить граф из файла...\n"
                 << "\n\tВведине название файла с графом:\n\n\t\t";
            cin.ignore();
            getline(cin, nameFile);

            Save_Graph_To_File(thisGraph, nameFile);

            break;
          }

        default:
          cout << "\n\n\t\tТакой команды нет!\n\n\t\t";
          system("Pause");
          system("CLS");
          break;
      }
    }
  }
}

void
main_menu()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  while (true) {
    system("CLS");

    cout << "\n\t     © Российский технологический университет – МИРЭА, 2019"
         << "\n\t\t\t\tГлавное Меню\n\n";

    if (GraphList.GetSize())
      cout << "\n\t1. Загрузить граф из файла..."
           << "\n\t2. Выбрать граф...\n";
    else
      cout << "\n\t1. Загрузить граф из файла...\n";

    cout << "\n\t9. О программе"
         << "\n\t0. Выйти\n"
         << "\n\tВведите команду: ";

    int command;
    cin >> command;

    if (command == 0) {
      if (GraphList.GetSize() != 0)
        for (int i = 0; i < GraphList.GetSize(); i++)
          if (!GraphList[i].saved) {
            system("CLS");

            cout << "\n\n\tГраф " << GraphList[i].GetGraphName()
                 << " не сохранен!"
                 << "\n\tСохранить (Yes/No)? -> ";
            string answer;
            cin >> answer;
            if (answer == "Yes" || answer == "Да" ||
                ("1" <= answer && answer <= "9")) {
              Save_Graph_To_File(
                GraphList[i], GraphList[i].GetGraphName() + " - fast save.tgf");
              GraphList[i].saved = true;
            }
          }
      break;
    } else if (command == 9)
      about_the_program();
    else {
      string nameFile;
      unsigned int numGraph, i;

      switch (command) {
        case 1:
          system("CLS");

          newGraph = new Graph;

          GraphList.push_back(*newGraph);

          cout << "\n\t\t\t     Загрузить граф из файла...\n"
               << "\n\tВведине название файла с графом:\n\n\t\t";
          cin.ignore();
          getline(cin, nameFile);

          if (Load_Graph_From_File(GraphList[GraphList.GetSize() - 1],
                                   nameFile))
            GraphList.pop_back();

          break;

        case 2:
          if (GraphList.GetSize()) {
            system("CLS");

            cout << "\n\t\t\t\tВыбрать граф...\n"
                 << "\n\tСуществующие графы:\n";
            for (i = 0; i < GraphList.GetSize(); i++)
              cout << "\n\t" << i + 1 << ". " << GraphList[i].GetGraphName();

            while (true) {
              cout << "\n\n\tВведите номер графа: ";
              cin >> numGraph;

              if (numGraph <= 0 || numGraph > GraphList.GetSize())
                cout << "\n\n\t\tНеверный номер!\n\n\t\t";
              else
                break;
            }
            graph_menu(GraphList[numGraph - 1]);
            break;
          }

        default:
          cout << "\n\n\t\tТакой команды нет!\n\n\t\t";

          system("Pause");
          system("CLS");
          break;
      }
    }
  }
}

int
main()
{
  main_menu();

  return 0;
}
