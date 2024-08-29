#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "CBST.h"
#include "CPersonInfo.h"

const int MAX_ITEMS = 30;

void Visit(const CPersonInfo& item);  // Add a semicolon at the end of the function declaration

int main()
{
    CBST<CPersonInfo> treeList;
    CPersonInfo people[MAX_ITEMS];
    ifstream inFile("PersonBankInfo.txt");
    char header[256];
    int index;

    if (inFile.fail())
    {
        cerr << "Error";
        exit(EXIT_FAILURE);
    }

    inFile.getline(header, 256);  // Correct the function name from "getLine" to "getline"

    for (index = 0; index < MAX_ITEMS; ++index)
    {
        inFile >> people[index];
    }

    for (index = 0; index < 20; ++index)
    {
        treeList.Add(people[index]);
    }

    cout << "Displaying preorder Treelist \n";
    treeList.PreorderTraverse(Visit);
    cout << endl;

    cout << "Displaying postorder Treelist \n";
    treeList.PostorderTraverse(Visit);
    cout << endl;

    cout << "Displaying Inorder Treelist \n";
    treeList.InorderTraverse(Visit);
    cout << endl;

    cout << "Displaying Levelorder Treelist \n";
    treeList.LevelorderTraverse(Visit);
    cout << endl;

    for (index = 0; index < 10; ++index)
    {
        treeList.Remove(people[index]);
    }

    for (index = 20; index < MAX_ITEMS; ++index)
    {
        treeList.Add(people[index]);
    }

    CBST<CPersonInfo> treeList2(treeList);
    CBST<CPersonInfo> treeList3(people[0]);

    treeList2 = treeList2;
    treeList3 = treeList2;

    cout << "Displaying preorder Treelist3 \n";
    treeList3.PreorderTraverse(Visit);
    cout << endl;

    cout << "Displaying postorder Treelist3 \n";
    treeList3.PostorderTraverse(Visit);
    cout << endl;

    cout << "Displaying inorder Treelist3 \n";
    treeList3.InorderTraverse(Visit);
    cout << endl;

    cout << "Displaying preorder Treelist3 \n";
   treeList3.LevelorderTraverse(Visit);
    cout << endl;

    return 0;
}

void Visit(const CPersonInfo& item)
{
    cout << item << endl;
}
