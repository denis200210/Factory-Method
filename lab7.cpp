// лаба 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <vector>
using namespace std;

class Toyota
{
public:
    virtual void info() = 0;
    virtual ~Toyota() {}
};

class Crown : public Toyota
{
public:
    void info() {
        cout << "Crown" << endl;
    };
};

class Rav4 : public Toyota
{
public:
    void info() {
        cout << "Rav4" << endl;
    };
};

class GT86 : public Toyota
{
public:
    void info() {
        cout << "GT86" << endl;
    };
};



class Factory
{
public:
    virtual Toyota* createToyota() = 0;
    virtual ~Factory() {}
};

class CrownFactory : public Factory
{
public:
    Toyota* createToyota() {
        return new Crown;
    }
};

class Rav4Factory : public Factory
{
public:
    Toyota* createToyota() {
        return new Rav4;
    }
};

class GT86Factory : public Factory
{
public:
    Toyota* createToyota() {
        return new GT86;
    }
};



int main()
{
    
    CrownFactory* Crown_factory = new CrownFactory;
    Rav4Factory* Rav4_factory = new Rav4Factory;
    GT86Factory* GT86_factory = new GT86Factory;

    vector<Toyota*> v;
    v.push_back(Crown_factory->createToyota());
    v.push_back(Rav4_factory->createToyota());
    v.push_back(GT86_factory->createToyota());

    for (int i = 0; i < v.size(); i++)
        v[i]->info();
    
}