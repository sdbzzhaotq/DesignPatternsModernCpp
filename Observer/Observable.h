#pragma once
#ifndef OBSERVABLE_H_H
#define OBSERVABLE_H_H
#include "Observer.h"

template <typename T> 

struct Observable {
    void subscribe(Observer<T>* f) { observers.push_back(f); }
    void notify(T& source, const std::string& name) {
        for (auto obs : observers) {
            obs->field_change(source, name);
        }
    }
private:
    std::vector<Observer<T>*> observers;
};

#endif