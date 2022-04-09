#include "Matrix.h"
#include <pthread.h>
std::ifstream in("matrices.txt");
pthread_mutex_t mutex;

struct Params {
    const Matrix& a1;
    const Matrix& a2;
    Matrix& a3;

    int bSize;
    int i;
    int j;
    int k;
    pthread_mutex_t& _lock;

    Params(const Matrix& m1, const Matrix& m2, Matrix& m3,
           int blSize, int ii, int jj, int kk, pthread_mutex_t& lock) : a1(m1), a2(m2),
                                                              a3(m3), bSize(blSize), i(ii), j(jj), k(kk), _lock(lock) {}
};

void basicMult(const Matrix& a1, const Matrix& a2, Matrix& a3) {
    //standard multiplication algorithm
    //nothing to add here
    for (int i = 0; i < a3.getSize(); i++) {
        for (int j = 0; j < a3.getSize(); j++) {
            a3(i, j) = 0;
            for (int k = 0; k < a3.getSize(); k++) {
                a3(i, j) += a1(i, k) * a2(k, j);
            }
        }
    }

}


void* multiplyBlocks(void* parameters) {
auto* p = (Params*) parameters;
int ii = p->i,
        jj = p->j,
        kk = p->k,
        blSize = p->bSize;
for (int i = ii; i < ii + blSize; i++) {
for (int j = jj; j < jj + blSize; j++) {
double sum = 0;
for (int k = 0; k < blSize; k++) {
sum += p->a1(i, kk + k) * p->a2(kk + k, j);
}
pthread_mutex_lock(&p->_lock);
p->a3(i, j) += sum;
pthread_mutex_lock(&p->_lock);
}
}
pthread_exit(nullptr);
}


Matrix advancedMult(const Matrix& a1, const Matrix& a2, int blocksNum) {
    int blSize = a1.getSize() / blocksNum;

    Matrix a3 = Matrix(a1.getSize());
    std::vector<pthread_t> threads;
    std::vector<Params*> pVector;

    for (int ii = 0; ii < a3.getSize(); ii += blSize) {
        for (int jj = 0; jj < a3.getSize(); jj += blSize) {
            for (int kk = 0; kk < a3.getSize(); kk += blSize) {
                auto* p = new Params(a1, a2, a3, blSize, ii, jj, kk, mutex);
                pthread_t thr;
                pthread_create(&thr, nullptr,&multiplyBlocks,p);
                threads.push_back(thr);
                pVector.push_back(p);
            }
        }
    }
    std::cout << "Threads(total): " << threads.size() << std::endl;
    for(auto& thr:threads){
        pthread_join(thr,nullptr);
    }

    for(auto& p:pVector){
        delete p;
    }
    return a3;
}


void fillData(Matrix& a) {
    for (int i = 0; i < a.getSize(); i++) {
        for (int j = 0; j < a.getSize(); j++) {
            in >> a(i, j);
        }
    }
}

void generateRand(Matrix& a, int max) {
    for (int i = 0; i < a.getSize(); i++) {
        for (int j = 0; j < a.getSize(); j++) {
            a(i,j)= rand() % (int)max;
        }
    }
}

int main() {
    srand(time(NULL));
    int s=10;
    //in >> s;
    Matrix m1(s), m2(s), m3(s), m4(s);
    //fillData(m1);
    //fillData(m2);
    generateRand(m1, 10);
    generateRand(m2, 10);

    int start = clock();
    basicMult(m1, m2, m3);

    int end = clock();
    std::cout << "---Regular multiplication:---\n";
    //std::cout << m3;
    std::cout << "Time: " << end - start << std::endl;
    std::cout << "===========================================\n";

    std::cout << "---Block multiplication:---\n";
    for (int i = 1; i <= s; i++) {
        //here "i" is the number of blocks
        if (s % i == 0 ) {
            int _start = clock();
            m4 = advancedMult(m1, m2, i);
            int _end = clock();
            //std::cout << m4;
            std::cout << "Time(block mult): " << _end - _start << ", blocks: " << i << std::endl;
            std::cout << "===========================================\n";
        }
    }


    return 0;
}