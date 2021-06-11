#include <string.h>
#include <iostream>

using namespace std;

struct RegistrantQueueChainType
{
    int queueId;
    string testIdNumber;
    RegistrantQueueChainType *next;
};

typedef struct RegistrantQueueChainType RegistrantQueueChainType;

struct RegistrantQueueType
{
    int count;
    RegistrantQueueChainType *front;
    RegistrantQueueChainType *rear;
};

typedef struct RegistrantQueueType RegistrantQueueType;
