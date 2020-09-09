#pragma once
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class CaesarCipher
{
  string Cipher(string inString, int key);

  void string_menu();
  void cryption_string(bool typeCryption = false);

  void file_menu();
  void edit_file();
  void view_file();
  void view_file(string nameInFile);
  void cryption_file(bool typeCryption = false);

  void cryption_performed(string inFileName, bool ptr, int key);

public:
  void coder_menu();
  void about_the_program();
};
