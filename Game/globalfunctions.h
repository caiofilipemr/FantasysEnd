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

struct Cordenates {
    int i, j;
    Cordenates(int new_i, int new_j): i(new_i), j(new_j) {}
    Cordenates() { }
    Cordenates operator+ (Direction dir);
    Cordenates operator- (Direction dir);
    bool operator== (Cordenates cord);
};

template <typename T>

class Node
{
public:
    T x;
    Node *prox;
    Node *ant;
    Node(T n, Node *ptp = 0, Node *pta = 0) : x(n), prox(ptp), ant(pta) { }
};

template <typename T>
class myIterator {
    Node<T> *pt;
public:
    myIterator() { }
    virtual T next() = 0;
    virtual bool has_next() = 0;
};

template <typename T>
class Fila
{
private:
    Node<T> ini, *fim;
    int s;
public:
    //Métodos "padrão" da estrutura Fila!!!
    Fila() : ini(0), fim(&ini), s(0) { }

    void queue(T n) {
        fim->prox = new Node<T>(n, NULL, fim);
        fim = fim->prox;
        s++;
    }

    T dequeue() {
        if (is_empty()) throw "Fila vazia, impossível desinfileirar!";
        s--;
        T x = ini.prox->x;
        if (!ini.prox->prox) {
            delete ini.prox;
            ini.prox = NULL;
            fim = &ini;
            return x;
        }
        ini.prox = ini.prox->prox;
        delete ini.prox->ant;
        ini.prox->ant = &ini;
        return x;
    }

    T first() {
        if (is_empty()) throw "Fila vazia!";
        return ini.prox->x;
    }

    T last() {
        if (is_empty()) throw "Fila vazia!";
        return fim->x;
    }

    int size() { return s; }

    bool is_empty() { return !(bool)s; }

    void clear() {
        while (!is_empty()) dequeue();
    }

    ~Fila() { this->clear(); }
};

template <typename T>
class Lista
{
private:
    Node<T> ini, fim;
    int s;

    template <typename T1>
    class myIteratorLista : public myIterator<T1> {
        Node<T> *pt, *fim;
    public:
        myIteratorLista(Node<T> *it, Node<T> *fim) : pt(it), fim(fim) { }
        T1 next() {
            if (pt) {
                T1 x = pt->x;
                pt = pt->prox;
                return x;
            }
            throw "Não existe próximo!";
        }

        bool has_next() {
            if (pt != fim) return true;
            return false;
        }
    };

public:
    //Métodos "padrão" da estrutura lista!!!
    Lista(T n) : ini(n, &fim), fim(n, 0, &ini), s(0) { }

    void add(T n) {
        fim.ant->prox = new Node<T>(n, &fim, fim.ant);
        fim.ant = fim.ant->prox;
        s++;
    }

    T remove(int i) {
        if (i < 0 || i >= s || !s) throw "Lista vazia, impossível remover elemento!";
        T x;
        Node<T> *pto;
        if (i  < (s >> 1)) FOR_INI
        else {
            i = (s-1) - i;
            FOR_FIM
        }
        pto->ant->prox = pto->prox;
        pto->prox->ant = pto->ant;
        x = pto->x;
        delete pto;
        s--;
        return x;
    }

    T get(int i) {
        if (i < 0 || i >= s) throw "Indice inválido!";
        if (!s) throw "Lista vazia!";
        Node<T> *pto;
        if (i  < (s >> 1)) FOR_INI
        else {
            i = (s-1) - i;
            FOR_FIM
        }
        return pto->x;
    }

    int size() { return s; }

    bool is_empty() { return !(bool)s; }

    void clear() {
        Node<T> *pto;
        for (pto = ini.prox->prox; !is_empty(); pto = pto->prox, s--){
            delete pto->ant;
        }
    }

    myIterator<T> * getIterator() {
        return new myIteratorLista<T>(ini.prox, &fim);
    }

    ~Lista() { this->clear(); }
};

int random(int num_rand);

std::stack<Direction> shortPass(int begin_i, int begin_j, int end_i, int end_j);

//int randlevelitem();


#endif // GLOBALFUNCTIONS_H
