#include <iostream>
#include <vector>
#include <Sorting.h>

using namespace std;
using namespace sorting;

int main() {
	vector<int> mas{ 10,8,5,3,9,1,2,4,6,7 };
	cout << mas << endl;
	//cout << insert_sort(mas);
	cout << shaker_sort(mas);
	//cout << heap_sort(mas);
	cout << mas << endl;

	vector<size_t> size{1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,25000,50000,100000};
	int seed;
	cout << "Введите  seed: ";
	cin >> seed;

	for (size_t i = 0; i < size.size(); ++i) {
		Stats stats = average_stats(size[i], insert_sort, seed);
		Stats stats = average_stats(size[i], shaker_sort, seed);
		Stats stats = average_stats(size[i], heap_sort, seed);
		cout << stats;
	}

	for (size_t i = 0; i < size.size(); ++i) {
		vector<int> mas = sorted(size[i]);
		vector<int> mas = back_sorted(size[i]);
		Stats stats = insert_sort(mas);
		Stats stats = shaker_sort(mas);
		Stats stats = heap_sort(mas);
		cout << stats;
	}

	return 0;
}