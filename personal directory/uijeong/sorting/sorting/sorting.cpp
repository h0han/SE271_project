// sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>
/*bool desc(int a, int b) {
    return a < b;
}
template<class T>
void sorting(T& st) {
    //index 저장해놓는 ary를 만들어서(std_info) 같이 움직이게-> 이 어레이 활용해서 std 정보 자체 받을 수 있게
    int* sort_lst;
    int* std_info;
    for (int i = 0; i</*class 안에 저장되어있는 학생수; ++i) {
        int my_sub_score = st[i].sub_score;
        for (int j = 0; j </*class 안에 저장되어있는 학생수; ++j) {
            if (i == j) continue;
            else {
                sort_lst.add(st[j]->sub_score);
            }
        }
    }
    sort(sort_lst, sort_lst+n, desc)
}
void get_info() {
//   std_info 함수를 받아서 그 객체에 접근 for(int i=0, i<std_info 끝날때 까지, ++i) std[ㅑ]의 정보 배출
}
//my_Sub_score=5000 점으로 설정 한 후 
//st[i]->sub_score
*/


int data1[4]{ 10, 20, 30, 40 };
int data2[4]{ 11, 21, 31, 41 };
int data3[4]{ 13, 23, 33, 43 };
int data4[4]{ 15, 25, 35, 45 };
int data5[4]{ 17, 27, 37, 47 };
int data6[4]{ 19, 29, 39, 49 };
int* data_all[5]{ data1, data2, data3, data4, data5 };


class Collection {
private:
    int idx=1;
    int m_size = 0;
public:
    int* data;
    int* number;

    void Get(int* arr,int idx=1) {
        if (m_size == 0) {
            data = new int[1]{ *(arr+idx) };
           number = new int[1]{ 1 };

            ++m_size;
        }
        else {
            int* new_data = new int[m_size + 1];
            int* new_number = new int[m_size + 1];


            for (int i = 0; i < m_size; ++i) {
                new_data[i] = data [i];
                new_number[i] = number[i];
            }
            new_data[m_size] = *(arr+idx);
            new_number[m_size] = m_size+1;

            delete[] data;
            delete[] number;

            data = new_data;
            number = new_number;

            ++m_size;
        }
    };
    void print() {
        std::cout << "[ ";
        for (int i = 0; i < 5; i++) {
            std::cout << *(data + i) << " ";
        }
        std::cout << "]" << std::endl;

        std::cout << "[ ";
        for (int i = 0; i < 5; i++) {
            std::cout << *(number + i) << " ";
        }
        std::cout << "]" << std::endl;
    }
    
    void optimize() {
        int i, j, temp1, temp2;
        for (i = 0; i < m_size - 1; ++i) {
            for (j = i + 1; j < m_size; ++j) {
                if (data[i] > data[j]) {
                    temp1 = data[i];
                    temp2 = number[i];
                    data[i] = data[j];
                    number[i] = number[j];
                    data[j] = temp1;
                    number[j] = temp2;

                }
            };
        }
    }
    void print_data() {
  
        for (int i = 0; i < 5; ++i) {
            int idx = *(number + i);
            std::cout << "[ ";
            for (int j = 0; j < 4; ++j) {
                std::cout << *(*(data_all + (idx - 1)) + j) << " ";
            }
            std::cout << "]" << std::endl;
        }
}
};


void testcase(Collection* o) {
    o->Get(data1);
    o->Get(data3);
    o->Get(data2);
    o->Get(data5);
    o->Get(data4);
    o->print();

    o->optimize();
    o->print();
    
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
