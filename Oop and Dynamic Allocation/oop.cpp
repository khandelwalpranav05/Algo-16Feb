#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    int price;
public:
    string name;

//    Car (){}
    Car(int price, string name) {
        this->price = price;
        this->name = name;
        cout << "Calling the Parameterized constructor" << endl;
    }

    Car(string name) {
        this->name = name;
        cout << "Calling the single parameter constructor" << endl;
    }

    Car(int price) {
        this->price = price;
    }

    Car() {
//        cout<<"A new object is being created"<<endl;
        cout << "Calling the empty Constructor" << endl;
    }

    Car(Car &X) {
        this->price = X.price;
        this->name = X.name;
        cout << "New Copy Constructor" << endl;
    }

    void start() {
        cout << "Ignition" << endl;
    }

    void display() {
        cout << "Name :" << name << endl;
        cout << "Price: " << price << endl;
        cout << "***********************" << endl;
    }

    void setPrice(int price) {
        if (price < 0) {
            this->price = 0;
            return;
        }
        this->price = price;
    }

    int getPrice() {
        return this->price;
//        return price;
    }

    //Destructor
    ~Car() {
        cout << "Destroying the car " << this->name << " and " << this->price << endl;
    }
};

int main() {

//    Car c;
//    c.name = "Creta";
////    c.price = -100; // Bad Habbit
////    c.price = 'v'; // Bad Habbit
//
////    cout<<c.price<<endl; // Error
//
//    c.setPrice(100);
//    cout<<c.getPrice()<<endl;
//    c.start();
//    c.display();

//    cout<<c.name<<"->"<<c.price<<endl;

//    Car d;
//    d.name = "Merc";
//    d.price = 1000;
//
//    cout<<d.name<<"->"<<d.price<<endl;


//    Car a;
//    Car b(12,"Jazz");
//
//    b.display();
//
//    a.display();
//
//    Car x("Honda City");
//    x.setPrice(-90);
//
//    x.display();
//
//    Car y(34);
//
////    Car p(56);
//
////    Car p("op",89,9.67);
//
//
////    cout<< sizeof(c)<<endl;
////    cout<< sizeof(Car)<<endl;
////
////    int a = 10;
////    cout<< sizeof(a)<<endl;
////    cout<< sizeof(int)<<endl;
//
////    int a;
////    float b;
////    bool c;
////    char d;
//
////    string s2 = "pranav";
////
////    string s1 = "khandelwal";
////
////    cout<< sizeof(s1)<<endl;

//    Car a(100,"Creta");
//
//    Car b(a);
//
//    a.display();
//
//    b.display();

    Car *c = new Car(32, "A");

//    Car p(32,"A");

//    cout<<p.name<<endl;

    cout << (*c).name << endl;
    cout << c->name << endl;

    delete c;

    return 0;
}