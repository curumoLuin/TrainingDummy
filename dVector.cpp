#include <iostream>

class DVector{
    int size,maxSize;
    int* array;
    void allocateItDummy(); //alocate new memory space

public:
    DVector();                  //def ctor
    DVector(int);               //ctor param=maxSize
    DVector(const DVector&);    //copy ctor
    ~DVector();                 //dtor
    void pushItBackDummy(int);  //push_back
    int sizeV();                 //return size
    int operator[](int);        //array sub operator - what to return
    int at(int i);              //check element
};

DVector::DVector() {
    maxSize=6;
    array=new int[maxSize];
    size = 0;
}

DVector::DVector(int i) {
    maxSize=i;
    array=new int[maxSize];
    size = 0;
}

DVector::DVector(const DVector& v) {}

DVector::~DVector() {
    delete[] array;
}

void DVector::pushItBackDummy(int i) {
    if(size+1 > maxSize) allocateItDummy();
    array[size]=i;
    size++;
}

int DVector::sizeV() {
    return size;
}

int DVector::operator[](int i) {
    return array[i];
}

int DVector::at(int i) {
    if(i < size)
        return array[i];
    throw 10;
}

void DVector::allocateItDummy() {
    maxSize=size*2;
    int* tmp=new int[maxSize];
    for (int i = 0; i < size; ++i)
        tmp[i]=array[i];
    delete[] array;
    array=tmp;
    std::cout << "New memory was allocated!" << std::endl;
}

/////////
int main() {
    std::cout << "Dummy Dev presents: The Vector!" << std::endl;

    DVector v(6);
    int tmp,tmp2;

    std::cout << "How long, how long?" << std::endl;
    std::cin >> tmp;

    std::cout << "Will what slide? (input data)" << std::endl;
    for (int i = 0; i < tmp; ++i) {
        std::cin >> tmp2;
        v.pushItBackDummy(tmp2);
        if (tmp2==(-1))
            break;
    };

    std::cout << "And the sliders (all " << v.sizeV() << " of them) are:" << std::endl;
    for (int j = 0; j < tmp; ++j) {
      std::cout << v[j] << " ";
    };

    std::cout << std::endl;

    return 0;
}