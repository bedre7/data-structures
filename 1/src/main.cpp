/** 
* @file         main.hpp
* @description  Contains the main function
* @course       Data Structures 1B
* @assignment   1. Odev
* @date         14/11/2021
* @author       Bedru Umer Mohammed -> bedru.mohammed@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "FileReader.hpp"

int main()
{
    FileReader::readFile("Veri.txt");
    return 0;
}