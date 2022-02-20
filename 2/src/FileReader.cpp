/** 
* @file         FileReader.cpp
* @description  1. Reads and parses text file in to appropriate data stream
                2. Creates the Dogrukuyrugu objects and finally the AVL tree
* @course       Data Structures 1B
* @assignment   2. Odev
* @date         23/12/2021
* @author       Bedru Umer Mohammed -> bedru.mohammed@ogr.sakarya.edu.tr
*/

#include "FileReader.hpp"
#include <fstream>
#include <string>

void FileReader::readFile(string filePath)
{
    //FILE NAME IS Noktalar.txt
    ifstream file(filePath);

    if(!file.is_open())
    {
        if(!file.is_open())
        {
            cout << "File not found!" << endl;
            cout << "Please make sure the " << filePath << " file is in the same directory as the makefile" << endl;
            return;
        }
    }

    int lineSize, arrayIterator = 0, queueIterator = 0;
    string line, strNum;

    //an array of LineQueue is created from file
    int queueSize = getFileSize(filePath);
    LineQueues = new LineQueue[queueSize];

    //Each line in the file is converted to array first then to LineQueue
    while(getline(file, line))
    {
        lineSize = getArraySize(line);
        lineArray = new int[lineSize];

        for(int i = 0; i < line.length(); i++)
        {
            strNum += line[i];
            if(line[i] == ' ' || line[i + 1] == '\0')
            {
                int intNum = stoi(strNum);
                lineArray[arrayIterator++] = intNum;
                strNum = "";
            }
        }
        arrayIterator = 0;  strNum = "";

        //LineQueue object is created using lineArray(int array)
        createQueue( LineQueues[queueIterator], lineArray, lineSize);
        
        queueIterator++;                //incremented for the next line
        delete[] lineArray;
    }

    //creates the tree from the array of LineQueue
    createTree(queueSize);

    file.close();
}
//This creates the LineQueue from the lineArray
void FileReader::createQueue(LineQueue &queue, int *lineArr, int lineSize)
{
    int X, Y, Z;

    //this loop breaks the lineArray in to 3 pieces each time
    //to create a point and add it to the LineQueue
    for(int i = 0; i < lineSize; i += 3)
    {
        X = lineArr[i];
        Y = lineArr[i + 1];    
        Z = lineArr[i + 2];
        
        queue.enqueueInOrder(Point(X, Y, Z));
    }
}
//This finds out the size of the lineArray to be created
int FileReader::getArraySize(string str)
{
    int size = 1;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ' && str[i + 1] != '\0')
            size++;
    }
    return size;
}
//This finds out the number of queues to be made from a file
int FileReader::getFileSize(string filePath)
{
    int fileSize = 0;
    ifstream file(filePath);

    string line;
    while(getline(file, line))
    {
        fileSize++;
    }
    return fileSize;
}
//This function inserts each LineQueue object to the AVL tree
void FileReader::createTree(int queueSize)
{
    tree = new AVL();
    
    for(int i = 0; i < queueSize; i++)
        tree->add(LineQueues[i]);
}
void FileReader::printPostOrder()
{
    //system("CLS");
    cout << "=====================      Postorder of the Tree      =====================" << endl;
    tree->postorder();
}
//All memory allocated in the heap is freed
FileReader::~FileReader()
{
    delete[] LineQueues;
    delete tree;
}