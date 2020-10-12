#include <iostream>

class Base
{
public:
    Base() {};
    void non_virtual_method()
    {
        std::cout << "Metoda z klasy bazowej\n";
    }
    virtual void virtual_method()
    {
        std::cout << "Metoda z klasy bazowej\n";
    }
};

class BasePlus : public Base
{
public:
    BasePlus() : Base() {};
    void non_virtual_method()
    {
        std::cout << "Metoda z klasy pochodnej\n";
    }
    virtual void virtual_method()
    {
        std::cout << "Metoda z klasy pochodnej\n";
    }
};


int main()
{
    Base object_1;
    BasePlus object_2;

    Base &obj1_ref = object_1;
    Base &obj2_ref = object_2;

    obj1_ref.non_virtual_method(); //normalne użycie Base::non_virtual_method()
    obj2_ref.non_virtual_method(); //wywołanie metody Base::non_virtual_method() zamiast BasePlus::non_virtual_method()

    obj1_ref.virtual_method(); //użycie Base::virtual_method();
    obj2_ref.virtual_method(); //użycie poprawnie BasePlus :: virtial_method();
}