#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H
#define FOR_INI for (pto = ini.prox; i; i--, pto = pto->prox);
#define FOR_FIM for (pto = fim.ant; i; i--, pto = pto->ant);

#include <cstdlib>
#include "Enums.h"
#include "macros.h"
#include "cellarray.h"
#include <stack>
#include <queue>
#include <iostream>
#include <QString>

class Commands;

class Information {
private:
    int size, *info;
    std::string *info_name;
    int i;
public:
    Information(int size) : size(size), info(new int[size]), info_name(new std::string[size]), i(0) { }

    Information(Information & other) {
        size = other.size;
        info_name = new std::string[size];
        info = new int[size];

        for (int i = 0; i < size; i++) {
            info_name[i] = other.info_name[i];
            info[i] = other.info[i];
        }
        this->i = other.i;
    }

    Information(const Information & other) {
        size = other.size;
        info_name = new std::string[size];
        info = new int[size];

        for (int i = 0; i < size; i++) {
            info_name[i] = other.info_name[i];
            info[i] = other.info[i];
        }
        this->i = other.i;
    }

    ~Information() {
        if (info_name) delete [] info_name;
        if (info) delete [] info;
    }

    void addInfo(std::string info_name, int info) {
        if (i < size) {
            this->info_name[i] = info_name;
            this->info[i++] = info;
        } else throw "Information full!";
    }

    std::string getInfoName(int index) {
        if (index < size) {
            return info_name[index];
        } else throw "Out of range!";
    }

    int getInfo(int index) {
        if (index < size) {
            return info[index];
        } else throw "Out of range!";
    }

    int getSize() { return size; }
};

int random(int num_rand);

std::stack<Direction> shortPass(int begin_i, int begin_j, int end_i, int end_j);

bool isVertical(Direction direction);

//int randlevelitem();


#endif // GLOBALFUNCTIONS_H
