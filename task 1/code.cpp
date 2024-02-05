#include <iostream>
#include <fstream>
#include <string>

class figure {
protected:
    int num;
public:
    figure(int n) : num(n) {}
    int get_figur() {
        return num;
    }
    void printfigure(std::string figurname) {
        std::cout << figurname << ": " << num << std::endl;
    }
};

class triangle : public figure {
public:
    triangle(int n) : figure(n) {}
    void createtriangl() {
        num = 3;
    }
};

class quadrilateral : public figure {
public:
    quadrilateral(int n) : figure(n) {}
    void createtriangl() {
        num = 4;
    }
};

int main() {
    figure myfig(0);
    myfig.printfigure("фигура");

    triangle mytri(0);
    mytri.createtriangl();
    mytri.printfigure("треугольник");

    quadrilateral myquad(0);
    mytri.createtriangl();
    mytri.printfigure("квадрат");
    return 0;
}
