#include <string.h>
#include <iostream>

using namespace std;

struct ClassesType
{
  int className;
  ClassesType *next;
};

typedef struct ClassesType ClassesType;

struct EdgeType
{
  ClassesType *klaas;
  StudentSelectionChainType *student;
  EdgeType *next;
};

typedef struct EdgeType EdgeType;
