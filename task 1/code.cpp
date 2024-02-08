#include <iostream>
#include <fstream>
#include <string>

class figure {
protected:
    int num;
public:
    figure() : num(0) {}
    int get_figur() {
        return num;
    }
    void printfigure(std::string figurname) {
        std::cout << figurname << ": " << num << std::endl;
    }
};

class triangle : public figure {
public:
    triangle() {
        num = 3;
    }
};

class quadrilateral : public figure {
public:
    quadrilateral() {
        num = 4;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    figure myfig;
    myfig.printfigure("фигура");

    triangle mytri;
    mytri.printfigure("треугольник");

    quadrilateral myquad;
    myquad.printfigure("четырехугольник");
    return 0;
}