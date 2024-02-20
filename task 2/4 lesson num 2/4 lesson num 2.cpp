#include <iostream>
#include <string>

class figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    figure(int side1, int side2, int side3, int side4, int angle1, int angle2, int angle3, int angle4)
        : a(side1), b(side2), c(side3), d(side4), A(angle1), B(angle2), C(angle3), D(angle4) {}

    void printfigure(std::string figurname) {
        std::cout << std::endl << figurname << ": " << std::endl
            << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl
            << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
};

class triangle : public figure {
public:
    triangle(int side1, int side2, int side3, int angle1, int angle2, int angle3)
        : figure(side1, side2, side3, 0, angle1, angle2, angle3, 0) {}
};

class right_triangle : public figure {
public:
    right_triangle(int side1, int side2, int angle1, int angle2)
        : figure(side1, side2, 0, 0, angle1, angle2, 90, 0) {}
};

class isosceles_triangle : public figure {
public:
    isosceles_triangle(int side1, int side2, int angle1, int angle2)
        : figure(side1, side2, side1, 0, angle1, angle2, angle1, 0) {}
};

class equilateral_triangle : public figure {
public:
    equilateral_triangle(int side)
        : figure(side, side, side, 0, 60, 60, 60, 0) {}
};
class rectangle : public figure {
public:
    rectangle(int side1, int side2)
        : figure(side1, side2, side1, side2, 90, 90, 90, 90) {}
};

class square : public figure {
public:
    square(int side)
        : figure(side, side, side, side, 90, 90, 90, 90) {}
};

class parallelogram : public figure {
public:
    parallelogram(int side1, int side2, int angle)
        : figure(side1, side2, side1, side2, angle, 180 - angle, angle, 180 - angle) {}
};

class rhombus : public figure {
public:
    rhombus(int side, int angle)
        : figure(side, side, side, side, angle, 180 - angle, angle, 180 - angle) {}
};

int main() {
    setlocale(LC_ALL, "ru");

    triangle tri(10, 20, 30, 50, 60, 70);
    tri.printfigure("Треугольник");

    right_triangle right_tri(10, 20, 50, 60);
    right_tri.printfigure("Прямоугольный треугольник");

    isosceles_triangle iso_tri(10, 20, 50, 60);
    iso_tri.printfigure("Равнобедренный треугольник");

    equilateral_triangle eq_tri(30);
    eq_tri.printfigure("Равносторонний треугольник");

    rectangle rect(10, 20);
    rect.printfigure("Прямоугольник");

    square sq(30);
    sq.printfigure("Квадрат");

    parallelogram para(20, 30, 40);
    para.printfigure("Параллелограмм");

    rhombus rhom(30, 60);
    rhom.printfigure("Ромб");
    return 0;
}
