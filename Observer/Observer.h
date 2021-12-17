#pragma once
#ifndef OBSERVER_H_H
#define OBSERVER_H_H
template <typename T> 

struct Observer {
    virtual void field_change(T& source, const std::string& field_name) = 0;
};
#endif