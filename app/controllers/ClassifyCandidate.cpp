#include <string.h>
#include <iostream>

class ClassifyCandidate
{
  private:
    static StudentSelectionChainType chain;
    static ClassifyCandidate object;
    ClassesType classes;
    int summ;
    int capacity;
    EdgeType edges;
    int maxClasses;
    void connectClass(ClassesType *newClass);
    void connectEdge(EdgeType *newEdge);
    void divide();
    void initiate();
    void initiateClasses();
    void setClassCapacity();
    void successMessage();

  public:
    ClassifyCandidate();
    ~ClassifyCandidate();
    static ClassesType classInit();
    static ClassifyCandidate& from(
      StudentSelectionChainType candidates
    );
    ClassifyCandidate& useClasses(
      ClassesType classes_
    );
    ClassifyCandidate& useSumm(int summ_);
    EdgeType classify();
    void classRelease();
    void help();
};

StudentSelectionChainType ClassifyCandidate::chain;
ClassifyCandidate ClassifyCandidate::object;

ClassifyCandidate::ClassifyCandidate() {
  ClassifyCandidate::object = *this;
}

ClassifyCandidate::~ClassifyCandidate() {
}

void ClassifyCandidate::initiate() {
  ClassifyCandidate::object = *this;
}

ClassifyCandidate& ClassifyCandidate::from(
  StudentSelectionChainType candidates) {
  ClassifyCandidate::object.initiate();
  ClassifyCandidate::chain = candidates;
  return ClassifyCandidate::object;
}

ClassifyCandidate& ClassifyCandidate::useClasses(
  ClassesType classes_) {
  ClassifyCandidate::object.classes = classes_;
  return ClassifyCandidate::object;
}

ClassifyCandidate& ClassifyCandidate::useSumm(int summ_) {
  this->summ = summ_;
  return *this;
}

void ClassifyCandidate::setClassCapacity() {
  int classNum, maxCapacity;
  cout << "Jumlah Kelas Tersedia : ";
  cin >> classNum;
  cout << "Kapasitas Kelas Tersedia : ";
  cin >> maxCapacity;
  cout << endl;

  this->maxClasses = classNum;
  this->capacity = maxCapacity;

  if ((maxCapacity * classNum) < this->summ) {
    cout
      << "Kapasitas kelas angkatan kurang dari jumlah peserta didik yang diterima."
      << endl << endl;
    this->setClassCapacity();
  }
}

void ClassifyCandidate::connectClass(ClassesType *newClass) {
  ClassesType *walkerClass = new ClassesType;
  walkerClass = &this->classes;

  if (walkerClass) {
    walkerClass = newClass;
    ClassifyCandidate::classes = *walkerClass;
    return;
  }

  while (!walkerClass->next)
    walkerClass = walkerClass->next;

  walkerClass->next = newClass;
  return;
}

void ClassifyCandidate::initiateClasses() {
  for (int i = 0; i < this->maxClasses; i++) {
    ClassesType *klaas = new ClassesType;
    klaas->className = i + 1;
    klaas->next = NULL;

    this->connectClass(klaas);
  }
}

ClassesType ClassifyCandidate::classInit() {
  ClassifyCandidate::object.setClassCapacity();
  ClassifyCandidate::object.initiateClasses();
  return ClassifyCandidate::object.classes;
}

void ClassifyCandidate::connectEdge(EdgeType *newEdge) {
  EdgeType *walkerEdge = new EdgeType;
  walkerEdge = &this->edges;

  if (walkerEdge) {
    walkerEdge = newEdge;
    this->edges = *walkerEdge;
    return;
  }

  while (!walkerEdge->next) 
    walkerEdge = walkerEdge->next;
  
  walkerEdge->next = newEdge;
  return;
}

void ClassifyCandidate::divide() {
  int counter; 
  int klaas = 0;
  ClassesType *walkerClass = new ClassesType;
  walkerClass = &this->classes;

  StudentSelectionChainType *walkerStudent 
    = new StudentSelectionChainType;
  walkerStudent = &this->chain;

  while (!walkerClass && klaas < this->maxClasses) {
    counter = 0;
    // saben kelas kudu duwe sambungan karo murid, maks. sak kapasitas kelas
    // kelas 1 kudu duwe sambungan nang arek 1, 2, .., 36.
    while (!walkerStudent && counter < this->capacity) {
      EdgeType *newEdge = new EdgeType;
      newEdge->klaas = walkerClass;
      newEdge->student = walkerStudent;
      newEdge->next = NULL;
      this->connectEdge(newEdge);
      counter++;
    }
    walkerClass = walkerClass->next;
  }
}

void ClassifyCandidate::successMessage() {
  cout 
    << "Data peserta didik lolos telah dibagi ke kelas-kelas." 
    << endl << endl;
}

EdgeType ClassifyCandidate::classify() {
  this->divide();
  this->successMessage();
  return this->edges;
}
