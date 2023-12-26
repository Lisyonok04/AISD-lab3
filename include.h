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

