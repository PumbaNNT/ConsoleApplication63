
#include <iostream>
#include <string>
using namespace std;

class Engine {
private:
    string type;
    int power;

public:
    Engine(string t, int p) : type(t), power(p) {}

    void Show() {
        cout << "Двигун: " << type << ", " << power << " к.с." << endl;
    }
};

class Body {
private:
    string type;
    string color;

public:
    Body(string t, string c) : type(t), color(c) {}

    void Show() {
        cout << "Кузов: " << type << ", колір: " << color << endl;
    }
};

class Wheels {
private:
    int count;
    int diameter;

public:
    Wheels(int c, int d) : count(c), diameter(d) {}

    void Show() {
        cout << "Колеса: " << count << ", діаметр: " << diameter << " дюймів" << endl;
    }
};

class Doors {
private:
    int count;

public:
    Doors(int c) : count(c) {}

    void Show() {
        cout << "Кількість дверей: " << count << endl;
    }
};

class Gearbox {
private:
    string type;
    int gears;

public:
    Gearbox(string t, int g) : type(t), gears(g) {}

    void Show() {
        cout << "Коробка передач: " << type << ", передач: " << gears << endl;
    }
};

class Lights {
private:
    string type;

public:
    Lights(string t) : type(t) {}

    void Show() {
        cout << "Фари: " << type << endl;
    }
};

class Driver {
private:
    string name;
    string surname;
    int age;
    int experience;

public:
    Driver(string n, string s, int a, int e)
        : name(n), surname(s), age(a), experience(e) {
    }

    void Show() {
        cout << "\nІнформація про водія:" << endl;
        cout << "Ім'я: " << name << endl;
        cout << "Прізвище: " << surname << endl;
        cout << "Вік: " << age << endl;
        cout << "Стаж водіння: " << experience << " років" << endl;
    }
};

class Car {
private:
    string brand;
    string model;
    int year;

    Engine engine;
    Body body;
    Wheels wheels;
    Doors doors;
    Gearbox gearbox;
    Lights lights;

    Driver* driver;

public:
    Car(string b, string m, int y,
        Engine e, Body bo, Wheels w,
        Doors d, Gearbox g, Lights l)
        : brand(b), model(m), year(y),
        engine(e), body(bo), wheels(w),
        doors(d), gearbox(g), lights(l),
        driver(nullptr) {
    }

    Car(string b, string m, int y,
        Engine e, Body bo, Wheels w,
        Doors d, Gearbox g, Lights l, Driver* dr)
        : brand(b), model(m), year(y),
        engine(e), body(bo), wheels(w),
        doors(d), gearbox(g), lights(l),
        driver(dr) {
    }

    void AddDriver(Driver* dr) {
        driver = dr;
    }

    void Show() {
        cout << "\n========== АВТОМОБІЛЬ ==========" << endl;
        cout << "Марка: " << brand << endl;
        cout << "Модель: " << model << endl;
        cout << "Рік випуску: " << year << endl;

        engine.Show();
        body.Show();
        wheels.Show();
        doors.Show();
        gearbox.Show();
        lights.Show();

        if (driver != nullptr)
            driver->Show();
        else
            cout << "\nВодій відсутній!" << endl;

        cout << "================================" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ukr");

    Driver driver("Сергій", "Переходько", 20, 3);

    Engine engine("Бензиновий", 200);
    Body body("Седан", "Чорний");
    Wheels wheels(4, 18);
    Doors doors(4);
    Gearbox gearbox("Механічна", 6);
    Lights lights("LED");

    Car car("BMW", "320i", 2022,
        engine, body, wheels,
        doors, gearbox, lights);

    car.AddDriver(&driver);

    car.Show();

    return 0;
}

