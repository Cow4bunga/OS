#include "Matrix.h"
std::ifstream in("matrices.txt");
std::mutex mutex;

void basicMult(const Matrix& a1, const Matrix& a2, Matrix& a3) {
	//standard multiplication algorithm
	for (int i = 0; i < a3.getSize(); i++) {
		for (int j = 0; j < a3.getSize(); j++) {
			a3(i, j) = 0;
			for (int k = 0; k < a3.getSize(); k++) {
				a3(i, j) += a1(i, k) * a2(k, j);
			}
		}
	}

}

void multiplyBlocks(const Matrix& a1, const Matrix& a2, Matrix& a3, int ii, int kk,
	int jj, int bSize) {
	for (int i = ii; i < ii + bSize; i++) {
		for (int j = jj; j < jj + bSize; j++) {
			double sum = 0;
			for (int k = 0; k < bSize; k++) {
				sum += a1(i, kk + k) * a2(kk + k, j);
			}
			mutex.lock();
			a3(i, j) += sum;
			mutex.unlock();
		}
	}
}


Matrix advancedMult(const Matrix& a1, const Matrix& a2, int blocksNum) {
	int blSize = a1.getSize() / blocksNum;
	/*calculate size of block(dimension) to
	easily make a step from one block to another*/
	Matrix a3 = Matrix(a1.getSize());
	std::vector<std::thread> threads;

	for (int ii = 0; ii < a3.getSize(); ii += blSize) {
		for (int jj = 0; jj < a3.getSize(); jj += blSize) {
			for (int kk = 0; kk < a3.getSize(); kk += blSize) {
				std::thread thread(multiplyBlocks, std::ref(a1), std::ref(a2), std::ref(a3), ii, kk, jj, blSize);
				threads.push_back(std::move(thread));
			}
		}
	}

	for (std::thread& thread : threads) {
		thread.join();
	}
	//the total amount of threads is blocksNum^3
	std::cout << "Threads(total): " << threads.size() << std::endl;

	return a3;
}

void fillData(Matrix& a) {
	for (int i = 0; i < a.getSize(); i++) {
		for (int j = 0; j < a.getSize(); j++) {
			in >> a(i, j);
		}
	}
}

int main() {
	srand(time(NULL));
	int s;
	in >> s;
	Matrix m1(s), m2(s), m3(s), m4(s);
	fillData(m1);
	fillData(m2);

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
		if (s % i==0) {
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