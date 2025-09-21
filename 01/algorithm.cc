#include "algorithm.h"

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
  if (str.size() >= 4)
  {
    return str.substr(0, 4);
  }
  else
  {
    return str + std::string(4 - str.size(), '0');
  }
}

bool isEqual(std::string text1, std::string text2)
{
  std::string res1 = convertTextToSound(text1);
  std::string res2 = convertTextToSound(text2);

  if (res1.compare(res2) == 0)
    return true;
  else
    return false;
}

std::string convertTextToSound(std::string text)
{
  if (text == "")
  {
    std::string result = trim(text);
    return result;
  }

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
      char symbol = buf[i];

      if (strchr("bfpv", buf[i]) != nullptr)
      {
        symbol = '1';
      }
      if (strchr("cgjkqsxz", buf[i]) != nullptr)
      {
        symbol = '2';
      }
      if (strchr("dt", buf[i]) != nullptr)
      {
        symbol = '3';
      }
      if (strchr("l", buf[i]) != nullptr)
      {
        symbol = '4';
      }
      if (strchr("mn", buf[i]) != nullptr)
      {
        symbol = '5';
      }
      if (strchr("r", buf[i]) != nullptr)
      {
        symbol = '6';
      }
      buf1.push_back(symbol);
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
  assert(convertTextToSound("Ashcraft") == std::string{"A261"});

  /* Регистр */
  assert(convertTextToSound("ASHCRAFT") == std::string{"A261"});

  /* Удаление h и w */
  assert(convertTextToSound("Hwhw") == std::string{"H000"});

  /* Удаление гласных */
  assert(convertTextToSound("Erie") == std::string{"E600"});

  /* Числа идут подряд */
  assert(convertTextToSound("Bfpv") == std::string{"B100"});
  assert(convertTextToSound("BFPV") == std::string{"B100"});

  assert(convertTextToSound("Robert") == std::string{"R163"});
  assert(convertTextToSound("Rupert") == std::string{"R163"});
  assert(isEqual("Robert", "Rupert"));

  /* Пустая строка */
  assert(convertTextToSound("") == std::string{"0000"});

  /* Дополнение пробелами */
  assert(convertTextToSound("A") == std::string{"A000"});

  /* Разные коды */
  assert(!isEqual("Tymczak", "Pfister"));

  std::cout << "Все блоки assert пройдены";

  return 0;
}