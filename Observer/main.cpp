// Observer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <vector>
#include <iostream>
#include "Observer.h"
#include "Observable.h"

struct Person : Observable <Person> {
    Person(int value) { age = value; }
    int get_age() const { return age; }
    void set_age(const int age) {
        if (age == this->age) return;
        this->age = age;
        notify(*this, "age");
    }
private:
    int age;
};

struct ConsolePersonObserver : Observer<Person> {
    void field_change(Person& source, const std::string& field_name) override {
        std::cout << "Person's " << field_name << " has changed to "
            <<source.get_age() << std::endl;
    }
};

int main() {
    std::cout << "Hello Observer!\n";
    Person p{ 20 };
    ConsolePersonObserver cpo;
    p.subscribe(&cpo);
    p.set_age(21);
    p.set_age(22);
}
