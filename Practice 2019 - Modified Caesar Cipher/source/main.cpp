#include "CaesarCipher.h"

int
main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  CaesarCipher* Cipher = new CaesarCipher;

  Cipher->coder_menu();

  delete Cipher;

  return 0;
}
