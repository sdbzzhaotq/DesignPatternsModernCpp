#include <iostream>

class Person {
public:
    //address
    std::string street_address, post_code, city;
    //employment
    std::string company_name, position;
    int annual_income = 0;

    Person(){}
};

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
protected:
    Person& person;
    explicit PersonBuilderBase(Person& person) :person{ person } {
    }
public:
    operator Person() {
        return std::move(person);
    }

    //builder facets
    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase {
    Person p;
public:
    PersonBuilder():PersonBuilderBase{p} {}
};

class PersonAddressBuilder :public PersonBuilderBase {
    typedef PersonAddressBuilder self;
public:
    explicit PersonAddressBuilder(Person& person):PersonBuilderBase{person}{}

    self& at(std::string street_address) {
        person.street_address = street_address;
        return *this;
    }
    self& with_postcode(std::string post_code) {

    }
    self& in(std::string city) {

    }
};

int main()
{
    std::cout << "Hello World!\n";
}
