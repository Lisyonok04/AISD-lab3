#pragma once
#include <ctime>
#include <vector>

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

