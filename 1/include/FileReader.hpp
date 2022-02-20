#ifndef FILEPARESER_HPP
#define FILEPARESER_HPP

#include <fstream>
#include <string>

#include "DoublyLinkedList.hpp"
using namespace std;

class FileReader
{
    private:
        static string TrimStringByChar(string, char, char);
    public:
        static void readFile(string);
};

#endif