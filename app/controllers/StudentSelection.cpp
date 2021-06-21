#include <string.h>
#include <iostream>

class StudentSelection
{
private:
    static StudentSelectionChainType chain;
    static StudentSelection object;
    int quota;
    void addChain(string testId, 
        string name, string originSchool, float testScore);
    void connectChain(StudentSelectionChainType *newChain);
    void initiate();
    void successMessage();

public:
    StudentSelection();
    ~StudentSelection();
    static StudentSelection& from(StudentSelectionChainType candidates);
    StudentSelection& useQuota(int quota_);
    static void help();
    StudentSelectionChainType add(string testId);
    static int count();
    void release();
};

StudentSelectionChainType StudentSelection::chain;
StudentSelection StudentSelection::object;

StudentSelection::StudentSelection() {
    StudentSelection::object = *this;
}

StudentSelection::~StudentSelection() {
}

void StudentSelection::initiate() {
    StudentSelection::object = *this;
}

StudentSelection& StudentSelection::from(StudentSelectionChainType candidates) {
    StudentSelection::object.initiate();
    StudentSelection::chain = candidates;
    return StudentSelection::object;
}

void StudentSelection::successMessage() {
    cout << "Data berhasil dimasukkan ke entri." 
        << endl << endl;
}

void StudentSelection::connectChain(StudentSelectionChainType *newChain) {
    StudentSelectionChainType *walkerChain = new StudentSelectionChainType;
    walkerChain = &this->chain;

    if (!walkerChain) {
        walkerChain = newChain;
        return;
    }

    while (!walkerChain) 
        walkerChain = walkerChain->next;
    
    walkerChain->next = newChain;
    return;
}

void StudentSelection::addChain(string testId, 
    string name, string originSchool, float testScore) {
    StudentSelectionChainType *candidate = new StudentSelectionChainType;
    candidate->testEntryId = testId;
    candidate->name = name;
    candidate->originSchool = originSchool;
    candidate->testScore = testScore;
    candidate->next = NULL;
    this->connectChain(candidate);
    this->successMessage();
}

StudentSelectionChainType StudentSelection::add(string testId) {
    string name, originSchool;
    float testScore;
        
    cout << "Nama Pendaftar : "; 
    cin.ignore();
    getline(cin, name); 
    
    cout << "Sekolah Asal   : ";
    getline(cin, originSchool); 

    cout << "Nilai Tes Masuk: "; 
    cin >> testScore;

    cout << endl;
    this->addChain(testId, name, originSchool, testScore);

    return this->chain;
}

void StudentSelection::release() {
    StudentSelectionChainType *candidate 
        = new StudentSelectionChainType;
    candidate = &StudentSelection::chain;
    int counter = 0;

    while (candidate) {
        cout 
            << candidate->name
            << candidate
            << candidate->testEntryId
            << endl;
        candidate = candidate->next;
    }
}
