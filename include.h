#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

namespace sorting {

    template<typename T>
    ostream& operator<<(std::ostream& stream, const vector<T>& mas) {
        for (int i = 0; i < mas.size(); i++)
            stream << mas[i] << " ";
        return stream;
    }

    struct Stats {
        size_t comparison_count = 0;
        size_t copy_count = 0;

        Stats& operator+=(const Stats& stats) {
            comparison_count += stats.comparison_count;
            copy_count += stats.copy_count;
            return *this;
        }
    };

    ostream& operator<<(std::ostream& stream, const Stats& stats) {
        stream << "(" << stats.comparison_count << ", " << stats.copy_count << ")" << endl;
        return stream;
    }

    Stats insert_sort(vector<int>& mas) {
        Stats stats;
        for (int i = 1; i < mas.size(); i++) {
            for (int j = i; j > 0; j--) {
                stats.comparison_count++;
                if (mas[j - 1] > mas[j]) {
                    swap(mas[j - 1], mas[j]);
                    stats.copy_count += 2;
                }
            }
        }
        return stats;
    }

    Stats shaker_sort(vector<int>& mas) {
        Stats stats;
        int left = 1, right = mas.size() - 1;
        while (left <= right) {
            for (int i = right; i >= left; i--) {
                stats.comparison_count++;
                if (mas[i - 1] > mas[i]) {
                    swap(mas[i - 1], mas[i]);
                    stats.copy_count += 2;
                    cout << mas << endl;
                }
            }
            left++;
            for (int i = left; i <= right; i++) {
                stats.comparison_count++;
                if (mas[i - 1] > mas[i]) {
                    swap(mas[i - 1], mas[i]);
                    stats.copy_count += 2;
                    cout << mas << endl;
                }
            }
            right--;
        }
        return stats;
    }

    void heapify(vector<int>& mas, int size, int i, Stats& stats) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        stats.comparison_count++;
        if (left < size && mas[left] > mas[largest]) {
            largest = left;
            stats.copy_count++;
        }

        stats.comparison_count++;
        if (right < size && mas[right] > mas[largest]) {
            largest = right;
            stats.copy_count++;
        }

        stats.comparison_count++;
        if (largest != i) {
            swap(mas[i], mas[largest]);
            stats.copy_count += 2;
            heapify(mas, size, largest, stats);
        }
    }

    Stats heap_sort(vector<int>& mas) {
        Stats stats;
        int size = mas.size();
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(mas, size, i, stats);
        }

        for (int i = size - 1; i > 0; i--) {
            swap(mas[0], mas[i]);
            stats.copy_count += 2;
            heapify(mas, i, 0, stats);
        }
        return stats;
    }

   
    vector<int> sorted(size_t size) {
        vector<int> mas;
        for (int i = 0; i < size; i++)
            mas.push_back(i);
        return mas;
    }

    vector<int> back_sorted(size_t size) {
        vector<int> mas;
        for (int i = size; i > 0; i--)
            mas.push_back(i);
        return mas;
    }

    vector<int> random_mas(size_t size, int min, int max, int seed) {
        vector<int> mas;
        mt19937 gen(seed);
        uniform_real_distribution<> segment(min, max);
        for (int i = 0; i < size; ++i) {
            int value = segment(gen);
            mas.push_back(value);
        }
        return mas;
    }