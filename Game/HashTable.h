#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstdlib>
#include <initializer_list>
#include <utility>

namespace hash {
    template <typename VALUE, typename KEY>
    struct container {
        KEY key;
        VALUE value;
        container(KEY key, VALUE value) : key(key), value(value) { }
        container() { }
    };
}

template <typename VALUE, typename KEY>
class HashTable {
protected:
    size_t (*hash)(KEY);
    size_t table_size;
    size_t _size;
    bool redimensionable;
public:
    HashTable(size_t (* hashFunction)(KEY),
              size_t table_size,
              bool isRedimensionable) : hash(hashFunction),
                                                  table_size(table_size),
                                                  _size(0),
                                                  redimensionable(isRedimensionable) { }
    virtual void put(KEY key, VALUE value) = 0;


    virtual VALUE get(KEY key) = 0;
    virtual VALUE remove(KEY key) = 0;
    bool isEmpty() { return !_size; }
    size_t size() { return _size; }
    virtual VALUE * values() = 0;
    virtual KEY * keys() = 0;
    virtual bool hasKey(KEY key) = 0;
    virtual int getC() = 0;
    virtual void clear() = 0;
};

using namespace hash;

template <typename VALUE, typename KEY>
class HashTableDH : public HashTable<VALUE, KEY> {
private:
    container<VALUE, KEY> ** hash_table;
    size_t (*hash2)(KEY);
    int colisions;

    template <typename T>
    class iterator {
    private:
        container<VALUE, KEY> ** begin;
        container<VALUE, KEY> ** end;
    public:
        iterator(container<VALUE, KEY> ** hash_table, size_t table_size) : begin(hash_table), end(hash_table + table_size) {
            while (!(*begin) && begin++ < end);
        }

        iterator(iterator & it) {
            begin = it.begin;
            end = it.end;
        }

        T next() {
            if (begin < end) {
                T v = (*begin)->value;
                ++begin;
                while (!(*begin) && begin++ < end);
                return v;
            }
            throw "Don't has next!!";
        }

        bool has_next() {
            return (begin < end);
        }
    };

public:
    HashTableDH(size_t (* hashFunction)(KEY),
                size_t (* hashFunction2)(KEY),
                size_t table_size,
                bool isRedimensionable) : HashTable<VALUE, KEY>(hashFunction, table_size, isRedimensionable), hash2(hashFunction2), colisions(0)
    {
        hash_table = new container<VALUE, KEY>*[this->table_size];
        for (size_t i = 0; i < table_size; hash_table[i] = NULL, i++); //Faz todos os ponteiros do vetor apontar para NULL
    }

    void put(KEY key, VALUE value) {
        size_t index = 0;
        size_t i = 0;
        do {
            index = ((this->hash)(key) + i * (*hash2)(key)) % this->table_size;
            ++i;
        } while (hash_table[index] && hash_table[index]->key != key);
        if (hash_table[index]) { //Se já existir está KEY ele substitui!
            hash_table[index]->value = value;
            return;
        }
        hash_table[index] = new container<VALUE, KEY>(key, value);
        ++(this->_size);
        colisions += (i-1);
    }

    void put(std::initializer_list<std::pair<KEY, VALUE> > l) {
        for (std::pair<KEY, VALUE> p : l) {
            put(p.first, p.second);
        }
    }

    VALUE get(KEY key) {
        size_t index = 0;
        size_t i = 0;
        do {
            index = ((this->hash)(key) + i * (*hash2)(key)) % this->table_size;
            ++i;
        } while (hash_table[index] && hash_table[index]->key != key);
        if (!hash_table[index])
            throw "HashTable doesn't has this key!!!";
        return hash_table[index]->value;
    }

    VALUE remove(KEY key) {
        size_t index = 0;
        size_t i = 0;
        do {
            index = ((this->hash)(key) + i * (*hash2)(key)) % this->table_size;
            ++i;
        } while (hash_table[index] && hash_table[index]->key == key);
        if (!hash_table[index]) throw "HashTable doesn't has this key!!!";
        VALUE v = hash_table[index]->value;
        delete hash_table[index];
        (this->_size)--;
        return v;
    }

    VALUE * values() {
        VALUE * v = new VALUE[(this->_size)];
        for (size_t i = 0, s = 0; i < this->table_size && s < (this->_size); ++i) {
            if (hash_table[i]) {
                v[s] = hash_table[i]->value;
                ++s;
            }
        }
        return v;
    }

    KEY * keys() {
        KEY * k = new KEY[(this->_size)];
        for (size_t i = 0, s = 0; i < this->table_size && s < (this->_size); ++i) {
            if (hash_table[i]) {
                k[s] = hash_table[i]->key;
                ++s;
            }
        }
        return k;
    }

    iterator<VALUE> getIterator() {
        return iterator<VALUE>(hash_table, this->size());
    }

    bool hasKey(KEY key) {
        size_t index = 0;
        size_t i = 0;
        do {
            size_t h1 = (this->hash)(key), h2 = (*hash2)(key);
            index = (h1 + i * h2) % this->table_size;
            i++;
        } while (hash_table[index] && hash_table[index]->key != key);
        return hash_table[index];
    }

    int getC() {
        return colisions;
    }

    void clear() {
        for (size_t i = 0; i < this->table_size; ++i) {
            delete hash_table[i];
            hash_table[i] = NULL;
        }
        this->_size = 0;
    }
};

#endif // HASHTABLE_H
