#include <string.h>
#include <iostream>
#include "../types/RegistrationQueueType.cpp"

class RegistrationQueue
{
private:
    static RegistrantQueueType queue;
    static RegistrantQueueChainType *chain;
    static RegistrationQueue object;

    void addChain(string testId);
    void addChainToQueue(string testId);
    void warnIfTestIdNull();
    void getQueueId();

    RegistrantQueueType callChain();
    void callMessage();
    void error(string message);
    void initiate();

public:
    RegistrationQueue();
    static RegistrationQueue& from(RegistrantQueueType registrantQueue);
    RegistrantQueueType add();
    RegistrantQueueType call();
    string getRearTestId();
    static void help();
    ~RegistrationQueue();
};

RegistrantQueueType RegistrationQueue::queue;
RegistrantQueueChainType *RegistrationQueue::chain;
RegistrationQueue RegistrationQueue::object;

RegistrationQueue::RegistrationQueue() {
    RegistrationQueue::object = *this;
}

RegistrationQueue::~RegistrationQueue() {}

void RegistrationQueue::initiate() {
    RegistrationQueue::object = *this;
}

RegistrationQueue& RegistrationQueue::from(RegistrantQueueType registrantQueue) {
    RegistrationQueue::object.initiate();
    RegistrationQueue::queue = registrantQueue;
    return RegistrationQueue::object;
}

/* 
 * --------------------------------
 * Tambah Antrean
 * --------------------------------
 */

void RegistrationQueue::addChain(string testId) {
    RegistrationQueue::chain = new RegistrantQueueChainType;
    RegistrationQueue::chain->testIdNumber = testId;
    cout << !RegistrationQueue::queue.rear << endl;
    if (RegistrationQueue::queue.rear) {
        RegistrationQueue::chain->queueId = RegistrationQueue::queue.rear->queueId + 1;
        return;
    }
    RegistrationQueue::chain->queueId = 1;
}

void RegistrationQueue::addChainToQueue(string testId) {
    this->addChain(testId);
    if (RegistrationQueue::queue.front == NULL)
        RegistrationQueue::queue.front = RegistrationQueue::chain;
    else 
        RegistrationQueue::queue.rear->next = RegistrationQueue::chain;
    
    RegistrationQueue::queue.rear = RegistrationQueue::chain;
    RegistrationQueue::queue.count += 1;
    this->getQueueId();
}

void RegistrationQueue::getQueueId() {
    cout << "No. antrean: " << RegistrationQueue::chain->queueId 
        << ", dengan nomor ujian " << RegistrationQueue::chain->testIdNumber
        << endl << endl;
}

void RegistrationQueue::warnIfTestIdNull() {
    cout << "Test ID tidak boleh kosong!" << endl;
}

RegistrantQueueType RegistrationQueue::add() {
    string testId;
    cout << "Masukkan Nomor Ujian Masuk : " ; 
    cin >> testId;

    if (testId.compare("") != 0) 
        this->addChainToQueue(testId);
    else this->warnIfTestIdNull();

    return RegistrationQueue::queue;
}

/* 
 * --------------------------------
 * Panggil Antrean
 * --------------------------------
 */

void RegistrationQueue::callMessage() {
    cout << "Memanggil no. antrean " << RegistrationQueue::chain->queueId 
        << " dengan nomor ujian " << RegistrationQueue::chain->testIdNumber
        << endl << endl;
}

RegistrantQueueType RegistrationQueue::callChain() {
    RegistrationQueue::chain = RegistrationQueue::queue.front;
    this->callMessage();
    RegistrationQueue::queue.front = RegistrationQueue::chain->next;
    delete RegistrationQueue::chain;
    RegistrationQueue::queue.count -= 1;
    return RegistrationQueue::queue;
}

RegistrantQueueType RegistrationQueue::call() {
    if (RegistrationQueue::queue.count != 0) 
        this->callChain();
    else 
        this->error("Antrean kosong");
    return RegistrationQueue::queue;
}

string RegistrationQueue::getRearTestId() {
    if (RegistrationQueue::queue.count != 0) 
        return this->queue.rear->testIdNumber;
    return "0";
}

/* 
 * --------------------------------
 * General Check
 * --------------------------------
 */

/* 
 * --------------------------------
 * Appendix
 * --------------------------------
 */

void RegistrationQueue::help() {}

void RegistrationQueue::error(string message) {
    cout << message << endl << endl;
}