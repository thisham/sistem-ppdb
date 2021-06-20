#include <string.h>
#include <iostream>

class StudentSelection
{
private:
    static StudentSelectionChainType *chain;
    static StudentSelection object;
    StudentSelectionChainType *addChain(string testId, 
        string name, string originSchool, float testScore);
    StudentSelectionChainType *connectChain(StudentSelectionChainType *newChain);
    void initiate();
    void successMessage();

public:
    StudentSelection();
    ~StudentSelection();
    static StudentSelection& from(StudentSelectionChainType *candidates);
    static void help();
    StudentSelectionChainType *add(string testId);
};

StudentSelectionChainType *StudentSelection::chain;
StudentSelection StudentSelection::object;

StudentSelection::StudentSelection() {
    StudentSelection::object = *this;
}

StudentSelection::~StudentSelection() {
}

void StudentSelection::initiate() {
    StudentSelection::object = *this;
}

StudentSelection& StudentSelection::from(StudentSelectionChainType *candidates) {
    StudentSelection::object.initiate();
    StudentSelection::chain = candidates;
    return StudentSelection::object;
}

void StudentSelection::successMessage() {
    cout << "Data berhasil dimasukkan ke entri." 
        << endl << endl;
}

StudentSelectionChainType *StudentSelection::connectChain(StudentSelectionChainType *newChain) {
    StudentSelectionChainType *walkerChain = new StudentSelectionChainType;
    walkerChain = StudentSelection::chain;

    if (walkerChain) {
        walkerChain = newChain; 
        StudentSelection::chain = walkerChain;
        return StudentSelection::chain;
    }
    
    while (!walkerChain) {
        if (walkerChain->testScore < newChain->testScore) 
            break;
        
        walkerChain = walkerChain->next;
    }; 

    newChain->next = walkerChain->next;
    walkerChain = newChain;
    return StudentSelection::chain;
}

StudentSelectionChainType *StudentSelection::addChain(string testId, 
    string name, string originSchool, float testScore) {
    StudentSelectionChainType *candidate = new StudentSelectionChainType;
    candidate->testEntryId = testId;
    candidate->name = name;
    candidate->originSchool = originSchool;
    candidate->testScore = testScore;
    candidate->next = NULL;
    this->connectChain(candidate);
    this->successMessage();

    return StudentSelection::chain;
}

StudentSelectionChainType *StudentSelection::add(string testId) {
    string name, originSchool;
    float testScore;

    cout << "Nama Pendaftar : "; 
    cin.ignore();
    getline(cin, name); 
    
    cout << "Sekolah Asal   : ";
    cin.ignore(); 
    getline(cin, originSchool); 

    cout << "Nilai Tes Masuk: "; 
    cin >> testScore;

    cout << endl;
    return this->addChain(testId, name, originSchool, testScore);
}
