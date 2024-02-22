#include <iostream>
#include <string>
#include <locale>

class figure {
protected:
    int a, b, c, d;
    int A, B, C, D;
    std::string name;

public:
    figure(int side1, int side2, int side3, int side4, int angle1, int angle2, int angle3, int angle4, std::string figName)
        : a(side1), b(side2), c(side3), d(side4), A(angle1), B(angle2), C(angle3), D(angle4), name(figName) {}

    virtual void printfigure() {
        std::cout << std::endl << name << ": " << std::endl
            << "Стороны: a=" << a << " b=" << b << " c=" << c;

        if (d != 0) {
            std::cout << " d=" << d;
        }

        std::cout << std::endl << "Углы: A=" << A << " B=" << B << " C=" << C;

        if (D != 0) {
            std::cout << " D=" << D;
        }

        std::cout << std::endl;
    }
};

void printfigure(figure* fig) {
    fig->printfigure();
}class triangle : public figure {
public:
    triangle(int side1, int side2, int side3, int angle1, int angle2, int angle3, std::string figName)
        : figure(side1, side2, side3, 0, angle1, angle2, angle3, 0, figName) {}
};

class right_triangle : public figure {
public:
    right_triangle(int side1, int side2, int angle1, int angle2, std::string figName)
        : figure(side1, side2, 0, 0, angle1, angle2, 90, 0, figName) {}
};

class isosceles_triangle : public figure {
public:
    isosceles_triangle(int side1, int side2, int side3, int angle1, int angle2, std::string figName)
        : figure(side1, side2, side3, 0, angle1, angle2, angle1, 0, figName) {}
};

class equilateral_triangle : public figure {
public:
    equilateral_triangle(int side, int angle1, std::string figName)
        : figure(side, side, side, 0, angle1, angle1, angle1, 0, figName) {}
};

class rectangle : public figure {
public:
    rectangle(int side1, int side2, std::string figName)
        : figure(side1, side2, side1, side2, 90, 90, 90, 90, figName) {}
};

class square : public figure {
public:
    square(int side, std::string figName)
        : figure(side, side, side, side, 90, 90, 90, 90, figName) {}
};

class parallelogram : public figure {
public:
    parallelogram(int side1, int side2, int angle1, int angle2, std::string figName)
        : figure(side1, side2, side1, side2, angle1, angle2, 180 - angle1, 180 - angle2, figName) {}
};

class rhombus : public figure {
public:
    rhombus(int side, int angle1, std::string figName)
        : figure(side, side, side, side, angle1, 180 - angle1, angle1, 180 - angle1, figName) {}
};
int main() {
    setlocale(LC_ALL, "ru");

    triangle tri(10, 20, 30, 50, 60, 70, "Треугольник");
    printfigure(&tri);

    right_triangle right_tri(10, 20, 50, 60, "Прямоугольный треугольник");
    printfigure(&right_tri);

    isosceles_triangle iso_tri(10, 15, 20, 60, 50, "Равнобедренный треугольник");
    printfigure(&iso_tri);

    equilateral_triangle eq_tri(30, 60, "Равносторонний треугольник");
    printfigure(&eq_tri);

    rectangle rect(10, 20, "Прямоугольник");
    printfigure(&rect);

    square sq(10, "Квадрат");
    printfigure(&sq);

    parallelogram para(10, 15, 60, 120, "Параллелограмм");
    printfigure(&para);

    rhombus rhomb(12, 60, "Ромб");
    printfigure(&rhomb);

    return 0;
}
