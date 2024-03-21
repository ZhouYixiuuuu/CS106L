/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 2/16/2024.
*/

// TODO: import anything from the STL that might be useful!
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <type_traits>
#include <vector>
#include <functional>


// TODO: write convert_f_to_c function here. Remember it must be a template function that always returns
// a double.
// [function definition here]
template <typename T>
concept numerical = std::is_arithmetic_v<T>;

template <numerical T>
double convert_f_to_c(T fah)
{
    double res = fah;
    res = (res - 32) * 5 / 9;
    return res;
}

template<typename Function, typename Container>
std::vector<double> get_forecast(Container readings, Function fn) {
    // TODO: write get_forecast here!
    std::vector<double> res;
    for (int i = 0; i < readings.size(); i ++ )
    {
        res.push_back(fn(readings[i].begin(), readings[i].end()));
    }
    return res;
}

int main() {
    std::vector<std::vector<int>> readings = {
        {70, 75, 80, 85, 90},
        {60, 65, 70, 75, 80},
        {50, 55, 60, 65, 70},
        {40, 45, 50, 55, 60},
        {30, 35, 40, 45, 50},
        {50, 55, 61, 65, 70},
        {40, 45, 50, 55, 60}
    };

    std::string path = "/workspace/CppProject/output.txt";
    std::ofstream ofs(path);


    // TODO: Convert temperatures to Celsius and output to output.txt
    std::vector<std::vector<double>> convert_celsius;
    for (int i = 0; i < readings.size(); i ++ )
    {
        std::vector<double> t;
        std::transform(readings[i].begin(), readings[i].end(), std::back_inserter(t),
        [](int c) -> double {return convert_f_to_c(c);});
        convert_celsius.push_back(t);
    }

    // TODO: Find the maximum temperature for each day and output to output.txt
    auto myMax = [](auto begin, auto end) -> double {
        auto it = std::max_element(begin, end);
        return (double)(*it);
    };

    std::vector<double> maxVec = get_forecast(convert_celsius, myMax);
    // TODO: Find the minimum temperature for each day and output to output.txt
    auto myMin = [](auto begin, auto end) -> double {
        auto it = std::min_element(begin, end);
        return (double)(*it);
    };

    std::vector<double> minVec = get_forecast(convert_celsius, myMin);
    // TODO: Find the average temperature for each day and output to output.txt
    auto myAve = [](auto begin, auto end) -> double {
        double sum = 0.0;
        int count = 0;
        for (auto it = begin; it != end; it ++ )
        {
            sum += *it;
            count ++;
        }
        return (double)(sum / count);
    };

    std::vector<double> aveVec = get_forecast(convert_celsius, myAve);

    for (int i = 0; i < convert_celsius.size(); i ++ )
    {
        for (int j = 0; j < convert_celsius[i].size(); j ++ )
        {
            //std::cout << convert_celsius[i][j] << ' ';
            ofs << convert_celsius[i][j] << ' ';
        }
    }
    ofs << '\n';
    for (int i = 0; i < maxVec.size(); i ++ ) ofs << maxVec[i] << ' ';
    ofs << '\n';
    for (int i = 0; i < minVec.size(); i ++ ) ofs << minVec[i] << ' ';
    ofs << '\n';
    for (int i = 0; i < aveVec.size(); i ++ ) ofs << aveVec[i] << ' ';
    return 0;
}
