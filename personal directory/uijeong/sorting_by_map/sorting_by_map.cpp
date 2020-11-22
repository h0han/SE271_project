// sorting_by_map.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <functional>


class Collection {
private:
    int idx = 1;
    std::map<double, int /*나중에 인스턴스로 바꾸기*/, std::greater<double>> m;

    double data1[4]{ 1, 200, 30, 40 };
    double data2[4]{ 2, 10, 31, 41 };
    double data3[4]{ 3, 101, 33, 43 };
    double data4[4]{ 4, 20.7, 35, 45 };
    double data5[4]{ 5, 37.9, 37, 47 };
    double data6[4]{ 6, 37.5, 39, 49 };
    double* data_all[6]{ data1, data2, data3, data4, data5, data6 };
public:

    void Get(int idx = 1) {
        for (int i = 0; i < 6/*데이터 개수 맞춰서 숫자 바꾸기*/; ++i) {
                m[data_all[i][idx]] = i + 1;
        }
        std::map<double, int /*나중에 인스턴스로 바꾸기*/, std::greater<double>>::iterator iter;
        for (iter = m.begin(); iter != m.end(); ++iter) {
            std::cout << "<" << iter->first << ',' << iter->second << "> " << std::endl;
        }
    };

    void print_data() {
        std::map<double, int /*나중에 인스턴스로 바꾸기*/, std::greater<double>>::iterator iter1;
        for (iter1 = m.begin(); iter1 != m.end(); ++iter1) {
            int std_id=(iter1->second)-1; //std_id 바꾸기
            std::cout << "[ ";
            for (int j = 0; j < 4; ++j) {
                std::cout << data_all[std_id][j] << " ";
            }
            std::cout << "]" << std::endl;
        }
    }
};


void testcase(Collection* o) {
    o->Get();
    o->print_data();
}

int main()
{

    Collection TestList;
    testcase(&TestList);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
