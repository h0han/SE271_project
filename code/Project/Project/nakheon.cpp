#include "SE271.h"

void open_csv(std::string filename) {
    std::string str_buf;
    std::fstream fs;

    fs.open(filename, std::ios::in);

    while (!fs.eof()) {
        getline(fs, str_buf, ',');
        std::cout << str_buf << std::endl;
    }
    fs.close();
}