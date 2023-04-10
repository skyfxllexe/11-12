// Файловый ввод-вывод с итераторами: Используйте стандартные итераторы для чтения и записи файлов. 
// Напишите программу, которая демонстрирует работу с текстовым файлом с помощью итераторов.

#include <iostream>
#include <fstream>
#include <iterator>
#include <string>

int main() 
{
    std::string text = "hello world";
    std::ofstream fileout("file.txt");

    for (std::string::iterator i = text.begin(); i != text.end(); ++i) 
    {
        fileout << *i;
    }

    fileout.close();

    std::ifstream filein("file.txt");

    std::istream_iterator<std::string> iter(filein);
    std::istream_iterator<std::string> end;
    while (iter != end) 
    {
        std::cout << *iter << std::endl;
        ++iter;
    }
    std::cout << std::endl;

    filein.close();

    return 0;
}
