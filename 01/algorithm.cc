#include "algorithm.h"

#include <cassert>
#include <cctype>
#include <cstring>
#include <iostream>

std::string clear_number(const std::string& str)
{
  std::string result = {};
  char last_numb = 0;
  bool numb_seq_flag = false;

  for (char c : str)
  {
    if (std::isdigit(static_cast<unsigned char>(c)))
    {
      if (!numb_seq_flag || c != last_numb) result.push_back(c);

      numb_seq_flag = true;
      last_numb = c;
    }
    else
    {
      result.push_back(c);
      numb_seq_flag = false;
    }
  }
  return result;
}

std::string trim(const std::string& str)
{
  return (str.size() >= 4) ? str.substr(0, 4)
                           : (str + std::string(4 - str.size(), '0'));
}

bool isEqual(std::string text1, std::string text2)
{
  return convertTextToSound(text1) == convertTextToSound(text2);
}

char table(char chr)
{
  char symbol = ' ';

  if (strchr("bfpv", chr) != nullptr)
  {
    symbol = '1';
  }
  if (strchr("cgjkqsxz", chr) != nullptr)
  {
    symbol = '2';
  }
  if (strchr("dt", chr) != nullptr)
  {
    symbol = '3';
  }
  if (strchr("l", chr) != nullptr)
  {
    symbol = '4';
  }
  if (strchr("mn", chr) != nullptr)
  {
    symbol = '5';
  }
  if (strchr("r", chr) != nullptr)
  {
    symbol = '6';
  }
  return symbol;
}

std::string convertTextToSound(std::string text)
{
  if (text == "") return trim(text);

  std::string buf = {};

  for (char c : text)
  {
    buf += std::tolower(static_cast<unsigned char>(c));
  }

  char upper = std::toupper(text[0]);

  std::string buf1 = {};
  buf1.push_back(upper);

  for (size_t i = 1; i < buf.length(); ++i)
  {
    if (strchr("hwaeiouy", buf[i]) == nullptr)
    {
      buf1.push_back(table(buf[i]));
    }
  }

  std::string result = clear_number(buf1);
  result = trim(result);

  return result;
}

int main(void)
{
  std::string text1{"Ashcraft"};
  std::string text2{"Ashcroft"};

  assert(isEqual(text1, text2));
  assert(convertTextToSound("Ashcraft") == "A261");

  /* Регистр */
  assert(convertTextToSound("ASHCRAFT") == "A261");

  /* Удаление h и w */
  assert(convertTextToSound("Hwhw") == "H000");

  /* Удаление гласных */
  assert(convertTextToSound("Erie") == "E600");

  /* Числа идут подряд */
  assert(convertTextToSound("Bfpv") == "B100");
  assert(convertTextToSound("BFPV") == "B100");

  assert(convertTextToSound("Robert") == "R163");
  assert(convertTextToSound("Rupert") == "R163");
  assert(isEqual("Robert", "Rupert"));

  /* Пустая строка */
  assert(convertTextToSound("") == "0000");

  /* Дополнение пробелами */
  assert(convertTextToSound("A") == "A000");

  /* Разные коды */
  assert(!isEqual("Tymczak", "Pfister"));

  /* Доп. тесты */
  assert(convertTextToSound("Tymczak") == "T520");

  std::cout << "Все блоки assert пройдены";

  return 0;
}