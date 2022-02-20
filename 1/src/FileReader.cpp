/** 
* @file         FileReader.cpp
* @description  1. Read and parse text file in appropriate data stream
                2. Create the linkedlist and print it
* @course       Data Structures 1B
* @assignment   1. Odev
* @date         14/11/2021
* @author       Bedru Umer Mohammed -> bedru.mohammed@ogr.sakarya.edu.tr
*/

#include "FileReader.hpp"

//This function trims the provided string with it's last and first characters
string FileReader::TrimStringByChar(string line, char start, char end)
{
    int first = line.find(start) + 1;
    int last = line.find(end);
    return line.substr(first, last - first);
}

//This function parses the text file to create the linkedlist
void FileReader::readFile(string filePath)
{
    //to read the file
    ifstream file;
    file.open(filePath);
    string line;

    if(!file.is_open())
    {
        cout << "File was not found" << endl;
        cout << "Please make sure the " << filePath << " file is in the same directory as the makefile" << endl;
        return;
    }

    //local variables to create the linkedlist
    char operation;
    int index;
    string data;

    DoublyLinkedList *names = new DoublyLinkedList();

    //this reads one line at a time and executes EACH command present until the end
    while(getline(file, line))
    {   
        if(line.empty()) continue;      //incase empty line was found it will jump to the next line
        
        operation = toupper(line.at(0));

        if(operation == 'E')
        {    
            index =  stoi(TrimStringByChar(line, '(', '#'));
            data = TrimStringByChar(line, '#', ')');
            names->insert(data, index);
        }
        else if(operation == 'S' && !names->isEmpty())
        {
            index =  stoi(TrimStringByChar(line, '(', ')'));
            names->removeAt(index);
        }
    }
    
    //system("CLS");
    cout << "===================\t Final state of the linkedlist\t ==================="<<endl;
    cout << *names << endl;

    //the file is closed and the linkedlist is deleted at the end
    file.close();
    delete names;
}