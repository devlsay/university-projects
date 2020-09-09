#include "CaesarCipher.h"

void
CaesarCipher::coder_menu()
{
  int command = 10;

  while (true) {
    system("cls");

    cout << "\n\t\t\t\t    S.P.Q.R"
         << "\n\t\t\t   Cipher Gaius Julius Caesar\n\n";

    cout << "\n\t1. String Cryption"
         << "\n\t2. Text File Cryption"
         << "\n\n\t9. About the program"
         << "\n\t0. Exit"
         << "\n\n\tChoose a command: ";

    cin >> command;

    if (command == 0)
      break;
    else
      switch (command) {
        case 1:
          string_menu();
          break;

        case 2:
          file_menu();
          break;

        case 9:
          about_the_program();
          break;

        default:
          cout << "\n\t\t\t   There is no such command!\n\n\n\t\t   ";
          system("pause");
          system("cls");
      }
  }
}

void
CaesarCipher::about_the_program()
{
  system("cls");

  cout << "\n\t\t\t\t    S.P.Q.R"
       << "\n\t\t\t   Cipher Gaius Julius Caesar\n\n";

  cout << "\t\t\t   © В. Д. Саяпин, МГУПИ 2019\n\n"
       << "\t\t\t   Курсовая работа по Практике\n\n\t\t";

  system("pause");
  system("cls");
}

string
CaesarCipher::Cipher(string inString, int key)
{
  string outString = "";

  for (auto c : inString) {
    int newkey = key;
    if ('a' <= c && c <= 'z') {
      if (key < 0)
        newkey = 26 + key % 26;

      for (int i = 0; i < 26; i++)
        if (c == char(i + 97))
          if (newkey + i > 25) {
            outString += char((newkey + i) % 26 + 97);
            break;
          } else {
            outString += char(newkey + i + 97);
            break;
          }
    } else if ('A' <= c && c <= 'Z') {
      if (key < 0)
        newkey = 26 + key % 26;

      for (int i = 0; i < 26; i++)
        if (c == char(i + 65))
          if (newkey + i > 25) {
            outString += char((newkey + i) % 26 + 65);
            break;
          } else {
            outString += char(newkey + i + 65);
            break;
          }
    } else if ('а' <= c && c <= 'я') {
      if (key < 0)
        newkey = 32 + key % 32;

      for (int i = 0; i < 32; i++)
        if (c == char(i - 32))
          if (newkey + i > 31) {
            outString += char((newkey + i) % 32 - 32);
            break;
          } else {
            outString += char(newkey + i - 32);
            break;
          }
    } else if ('А' <= c && c <= 'Я') {
      if (key < 0)
        newkey = 32 + key % 32;

      for (int i = 0; i < 32; i++)
        if (c == char(i - 64))
          if (newkey + i > 31) {
            outString += char((newkey + i) % 32 - 64);
            break;
          } else {
            outString += char(newkey + i - 64);
            break;
          }
    } else if ('0' <= c && c <= '9') {
      if (key < 0)
        newkey = 10 + key % 10;

      for (int i = 0; i < 10; i++)
        if (c == char(i + 48))
          if (newkey + i > 9) {
            outString += char((newkey + i) % 10 + 48);
            break;
          } else {
            outString += char(newkey + i + 48);
            break;
          }
    } else if (' ' <= c && c <= '/') {
      if (key < 0)
        newkey = 16 + key % 16;

      for (int i = 0; i < 16; i++)
        if (c == char(i + 32))
          if (newkey + i > 15) {
            outString += char((newkey + i) % 16 + 32);
            break;
          } else {
            outString += char(newkey + i + 32);
            break;
          }
    }
  }
  return string(outString);
}

void
CaesarCipher::string_menu()
{
  int command = 10;

  while (true) {
    system("cls");

    cout << "\n\t\t\t\t    S.P.Q.R"
         << "\n\t\t\t   Cipher Gaius Julius Caesar\n\n";

    cout << "\n\t1. Encryption"
         << "\n\t2. Decryption"
         << "\n\n\t0. Back\n\n"
         << "\tChoose a command: ";

    cin >> command;

    if (command == 0)
      break;
    else
      switch (command) {
        case 1:
          cryption_string(true);
          break;

        case 2:
          cryption_string();
          break;

        default:
          cout << "\n\t\t\t   There is no such command!\n\n\n\t\t   ";
          system("pause");
          system("cls");
      }
  }
}

void
CaesarCipher::cryption_string(bool typeCryption)
{
  system("cls");

  cout << "\n\t\t\t\t    S.P.Q.R"
       << "\n\t\t\t   Cipher Gaius Julius Caesar\n\n";

  if (typeCryption)
    cout << "\n\t\t\t\t  Encryption\n\n";
  else
    cout << "\n\t\t\t\t  Decryption\n\n";

  cout << " Enter the string:\n\n\t";
  string inString;
  cin.ignore();
  getline(cin, inString);

  cout << "\n Enter key: ";
  int key;
  cin >> key;

  if (typeCryption)
    cout << "\t\t\t      Encryption performed!\n\n"
         << " Encrypted string:\n\n\t" << Cipher(inString, key);
  else
    cout << "\t\t\t      Decryption performed!\n\n"
         << " Decrypted string:\n\n\t" << Cipher(inString, -1 * key);

  cout << "\n\n\n\t\t   ";
  system("pause");
  system("cls");
}

void
CaesarCipher::file_menu()
{
  int command = 10;

  while (true) {
    system("cls");

    cout << "\n\t\t\t\t    S.P.Q.R"
         << "\n\t\t\t   Cipher Gaius Julius Caesar\n\n";

    cout << "\n\t1. Encryption"
         << "\n\t2. Decryption"
         << "\n\n\t3. Create/Edit File"
         << "\n\t4. View File"
         << "\n\n\t0. Back\n\n"
         << "\tChoose a command: ";

    cin >> command;

    if (command == 0)
      break;
    else
      switch (command) {
        case 1:
          cryption_file(true);
          break;

        case 2:
          cryption_file();
          break;

        case 3:
          edit_file();
          break;

        case 4:
          view_file();
          break;

        default:
          cout << "\n\t\t\t   There is no such command!\n\n\n\t\t   ";
          system("pause");
          system("cls");
      }
  }
}

void
CaesarCipher::edit_file()
{
  system("cls");

  string nameInFile = "", outFileString;
  ofstream file;

  int command = 10;

  while (true) {
    system("cls");

    cout << "\n\t\t\t\t    S.P.Q.R"
         << "\n\t\t\t   Cipher Gaius Julius Caesar\n\n";

    if (nameInFile == "") {
      cout << "\tEnter file name: ";
      cin >> nameInFile;
      nameInFile += ".txt";

      file.open(nameInFile, ios::out);

      if (!file.is_open()) {
        cout << "\n\t\t\t     Error opening file!\n\n";

        cout << "\n\n\n\t\t   ";
        system("pause");
        system("cls");
        break;
      }
    } else {
      cout << "\n\t1. Clear " << nameInFile << "\n\t2. Add string to "
           << nameInFile << "\n\t3. View " << nameInFile << "\n\n\t0. Back"
           << "\n\n\tChoose a command: ";

      cin >> command;

      if (command == 0) {
        system("cls");
        break;
      } else
        switch (command) {
          case 1:
            file.close();
            file.open(nameInFile, ios::out | ios::trunc);

            cout << "\n\n\t\t\t\tFile is cleared!\n\n\t\t   ";
            system("pause");

            break;

          case 2:

            cout << "\n\tEnter the string:\n\t\t";
            cin >> outFileString;

            file.close();
            file.open(nameInFile, ios::out | ios::app);

            file << outFileString;
            file << endl;

            cout << "\n\n\t\t\tString added to file!\n\n\t\t   ";
            system("pause");

            break;

          case 3:
            view_file(nameInFile);
            break;

          default:
            cout << "\n\tThere is no such command!\n\n\n";
            system("pause");
            system("cls");
        }
    }
  }
  file.close();
}

void
CaesarCipher::view_file()
{
  system("cls");

  cout << "\n\t\t\t\t    S.P.Q.R"
       << "\n\t\t\t   Cipher Gaius Julius Caesar\n\n";

  cout << "\n\tEnter file name: ";

  string nameInFile;
  cin >> nameInFile;
  nameInFile += ".txt";

  view_file(nameInFile);
}

void
CaesarCipher::view_file(string nameInFile)
{
  ifstream file(nameInFile);

  if (!file.is_open()) {
    cout << "\n\t\t\t     Error opening file!\n\n";

    cout << "\n\n\n\t\t   ";
    system("pause");
    system("cls");
  } else {
    string inFileString, ptrFileString;
    cout << "\n\tFile content:\n";
    if (file.peek() == EOF)
      cout << "\t\tFail empty!\n";
    else
      while (!file.eof()) {
        ptrFileString = "";
        getline(file, ptrFileString);
        cout << '\t' << ptrFileString << endl;
      }
    file.close();
  }
  cout << "\n\n\n\t\t   ";
  system("pause");
  system("cls");
}

void
CaesarCipher::cryption_file(bool typeCryption)
{
  system("cls");

  cout << "\n\t\t\t\t    S.P.Q.R"
       << "\n\t\t\t   Cipher Gaius Julius Caesar\n\n";

  if (typeCryption)
    cout << "\n\t\t\t\t  Encryption\n\n";
  else
    cout << "\n\t\t\t\t  Decryption\n\n";

  cout << "\n Enter the name of the input file: ";
  string nameInFile, nameOutFile;
  cin.ignore();
  getline(cin, nameInFile);

  if (typeCryption)
    nameOutFile = "enCr" + nameInFile;
  else
    nameOutFile = "deCr" + nameInFile;

  cout << "\n Enter key: ";
  int key;
  cin >> key;

  fstream inFile, outFile;
  inFile.open(nameInFile);
  outFile.open(nameOutFile, fstream::trunc | fstream::out);

  if (!inFile.is_open() || !outFile.is_open()) {
    cout << "\n\t\t\t     Error opening file!\n\n";

    cout << "\n\n\n\t\t   ";
    system("pause");
    system("cls");
  } else {
    string inString;

    while (!inFile.eof()) {
      getline(inFile, inString);

      if (typeCryption)
        outFile << Cipher(inString, key) << endl;
      else
        outFile << Cipher(inString, -1 * key) << endl;
    }
    outFile.close();
    inFile.close();

    cryption_performed(nameOutFile, typeCryption, key);
  }
}

void
CaesarCipher::cryption_performed(string inFileName, bool ptr, int key)
{
  system("cls");

  cout << "\n\t\t\t\t    S.P.Q.R"
       << "\n\t\t\t   Cipher Gaius Julius Caesar\n\n";

  if (ptr)
    cout << "\t\t\t      Encryption performed!\n\n"
         << "\tFile name: " << inFileName << "\t\t Key: " << key << "\n\n";
  else
    cout << "\t\t\t      Decryption performed!\n\n"
         << "\tFile name: " << inFileName << "\t\t Key: " << key << "\n\n";

  view_file(inFileName);
}
