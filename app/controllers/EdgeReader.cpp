#include <string.h>
#include <iostream>

class EdgeReader
{
  private:
    static EdgeType *edges;
    static EdgeReader object;
    void initiate();

  public:
    EdgeReader();
    ~EdgeReader();
    static EdgeReader& useEdges(EdgeType *edges_);
    void print();
};

EdgeType *EdgeReader::edges;
EdgeReader EdgeReader::object;

EdgeReader::EdgeReader() {
  EdgeReader::object = *this;
}

EdgeReader::~EdgeReader() {
}

void EdgeReader::initiate() {
  EdgeReader::object = *this;
}

EdgeReader& EdgeReader::useEdges(EdgeType *edges_) {
  EdgeReader::object.edges = edges_;
  return EdgeReader::object;
}

void EdgeReader::print() {
  EdgeType *walkerEdge = new EdgeType;
  walkerEdge = this->edges;

  cout
    << "No. Kelas | Nama Siswa \t"
    << endl
    << "-------------------------------------------------------"
    << endl;
  
  while (!walkerEdge) {
    cout
      << walkerEdge->klaas->className
      << "\t"
      << walkerEdge->student->name
      << "\t"
      << endl;
    walkerEdge = walkerEdge->next;
  }
}
