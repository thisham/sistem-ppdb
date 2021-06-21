#include <string.h>
#include <iostream>

using namespace std;

struct SouvenirChainType {
  string goods;
  SouvenirChainType *next;
};

typedef struct SouvenirChainType SouvenirChainType;

struct SouvenirStackType {
  int count;
  SouvenirChainType *top;
};

typedef struct SouvenirStackType SouvenirStackType;
