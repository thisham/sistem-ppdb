#include <string.h>
#include <iostream>

using namespace std;

struct StudentSelectionChainType
{
    string testEntryId;
    string name;
    string originSchool;
    float testScore;
    StudentSelectionChainType *next;
};

typedef struct StudentSelectionChainType StudentSelectionChainType;
