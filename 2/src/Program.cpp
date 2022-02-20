/** 
* @file         Program.cpp
* @description  Creates an instance of FileReader and initiates the whole Operation
* @course       Data Structures 1B
* @assignment   2. Odev
* @date         23/12/2021
* @author       Bedru Umer Mohammed -> bedru.mohammed@ogr.sakarya.edu.tr
*/
#include "FileReader.hpp"

FileReader filereader;
int main()
{
    filereader.readFile("Noktalar.txt");
    filereader.printPostOrder();
    return 0;
}