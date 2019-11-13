#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
class Array {
public:
    virtual T get(int index) = 0;
    virtual void put(int index, T data) = 0;
    virtual int length() = 0;
};
#endif