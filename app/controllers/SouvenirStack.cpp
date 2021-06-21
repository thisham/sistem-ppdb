#include <string.h>
#include <iostream>
#include "../types/SouvenirType.cpp"

class SouvenirStack
{
private:
  static SouvenirStackType souvenir;
  static SouvenirStack object;
  void initiate();
  void setSuccess(SouvenirChainType souvenir_);

public:
  SouvenirStack();
  ~SouvenirStack();
  static SouvenirStack& from(SouvenirStackType souvenir_);
  SouvenirStackType add();
  SouvenirStackType pop();
  void count();
};

SouvenirStackType SouvenirStack::souvenir;
SouvenirStack SouvenirStack::object;

SouvenirStack::SouvenirStack() {
  SouvenirStack::object = *this;
}

SouvenirStack::~SouvenirStack() {
}

void SouvenirStack::initiate() {
  SouvenirStack::object = *this;
}

SouvenirStack& SouvenirStack::from(SouvenirStackType souvenir_) {
  SouvenirStack::souvenir = souvenir_;
  return SouvenirStack::object;
}

void SouvenirStack::count() {
  cout
    << "Total semua seragam tersisa : "
    << this->souvenir.count
    << " unit"
    << endl << endl;
}

void SouvenirStack::setSuccess(SouvenirChainType souvenir_) {
  cout
    << "Mendapatkan "
    << souvenir_.goods
    << " sebanyak 1 unit"
    << endl << endl;
}

SouvenirStackType SouvenirStack::add() {
  string goods;
  int unit;
  cout << "Nama Barang   : ";
  cin >> goods;
  cout << "Banyak Barang : ";
  cin >> unit;

  for (int i = 0; i < unit; i++) {
    SouvenirChainType *newChain = new SouvenirChainType;
    newChain->goods = goods;
    
    newChain->next = this->souvenir.top;
    this->souvenir.top = newChain;
    this->souvenir.count += 1;
  }

  return this->souvenir;
}

SouvenirStackType SouvenirStack::pop() {
  SouvenirChainType *tempChain = new SouvenirChainType;
  if (this->souvenir.top) {
    tempChain = this->souvenir.top->next;
    this->souvenir.count -= 1;
    this->setSuccess(*this->souvenir.top);
    delete this->souvenir.top;
    this->souvenir.top = tempChain;
  }
  return this->souvenir;
}
