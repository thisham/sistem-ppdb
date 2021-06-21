#include <string.h>
#include <iostream>

class EliminateCandidate
{
  private:
    static StudentSelectionChainType chain;
    static EliminateCandidate object;
    int quota;
    StudentSelectionChainType *addChain(string testId, 
      string name, string originSchool, float testScore);
    StudentSelectionChainType *connectChain(
      StudentSelectionChainType *newChain);
    void purgeEliminated(StudentSelectionChainType *candidates);
    void initiate();
    void setQuota();
    void successMessage();

  public:
    EliminateCandidate();
    ~EliminateCandidate();
    static EliminateCandidate& from(
      StudentSelectionChainType candidates);
    static void help();
    StudentSelectionChainType eliminate();
    void listRelease();
};

StudentSelectionChainType EliminateCandidate::chain;
EliminateCandidate EliminateCandidate::object;

EliminateCandidate::EliminateCandidate() {
  EliminateCandidate::object = *this;
}

EliminateCandidate::~EliminateCandidate() {
}

void EliminateCandidate::initiate() {
  EliminateCandidate::object = *this;
}

EliminateCandidate& EliminateCandidate::from(
  StudentSelectionChainType candidates) {
  EliminateCandidate::object.initiate();
  EliminateCandidate::chain = candidates;
  return EliminateCandidate::object;
}

// void EliminateCandidate::setQuota() {
//   cout << "Masukkan kuota maksimal : ";
//   cin >> this->quota;
//   cout << endl << endl;
// }

// void EliminateCandidate::purgeEliminated(
//   StudentSelectionChainType *candidates) {
//   StudentSelectionChainType *walkerChain = new StudentSelectionChainType;
//   walkerChain = &EliminateCandidate::chain;
//   int counter = 0;

//   while (!walkerChain) {
//     cout << walkerChain << endl;
//     StudentSelectionChainType *tempChain 
//       = new StudentSelectionChainType;
//     tempChain = walkerChain;
//     walkerChain = walkerChain->next;
//     delete tempChain;
//     counter++;
//   }

//   cout << "Calon Peserta Didik Tereliminasi : " << counter 
//     << endl;
// }

// StudentSelectionChainType EliminateCandidate::eliminate() {
//   StudentSelectionChainType *walkerChain = new StudentSelectionChainType;
//   walkerChain = &EliminateCandidate::chain;
//   int counter = 0;
//   this->setQuota();

//   while (counter < this->quota 
//     && !walkerChain) {
//       cout << walkerChain << endl;
//     walkerChain = walkerChain->next;
//     counter++;
//   }

//   if (!walkerChain->next) {
//     // this->purgeEliminated(walkerChain->next);
//     walkerChain->next = NULL;
//   }

//   cout << "Calon Peserta Didik Diterima : " << counter 
//     << endl;

//   this->successMessage();
//   return EliminateCandidate::chain;
// }

void EliminateCandidate::successMessage() {
    cout << "Peserta didik berhasil diseleksi." 
        << endl << endl;
}

void EliminateCandidate::listRelease() {
  cout 
    << "No.\tNo. Ujian\tNama\t\tNilai Ujian" << endl
    << "--------------------------------------------" << endl;
  
  StudentSelectionChainType *walkerChain = new StudentSelectionChainType;
  walkerChain = &EliminateCandidate::chain;
  int counter = 1;

  while (!walkerChain) {
    cout
      << counter++ << "\t" 
      << walkerChain->testEntryId << "\t"
      << walkerChain->name << "\t"
      << walkerChain->testScore << endl;
    walkerChain = walkerChain->next;
  }
}
