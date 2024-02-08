#include <iostream>
#include <string>

class figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    figure(int a = 0, int b = 0, int c = 0, int d = 0, int A = 0, int B = 0, int C = 0, int D = 0)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    void printfigure(std::string figurname) {
        std::cout << std::endl << figurname << ": " << std::endl
            << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl
            << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
};

class triangle : public figure {
public:
    triangle() : figure(10, 20, 30, 0, 50, 60, 70, 0) {}
};

class right_triangle : public figure {
public:
    right_triangle() : figure(10, 20, 30, 0, 50, 60, 90, 0) {}
};

class isosceles_triangle : public figure {
public:
    isosceles_triangle() : figure(10, 20, 10, 0, 50, 60, 50, 0) {}
};

class equilateral_triangle : public figure {
public:
    equilateral_triangle() : figure(30, 30, 30, 0, 60, 60, 60, 0) {}
};

class quadrilateral : public figure {
public:
    quadrilateral() : figure(10, 20, 30, 40, 50, 60, 70, 80) {}
};

class rectangle : public figure {
public:
    rectangle() : figure(10, 20, 10, 20, 90, 90, 90, 90) {}
};

class square : public figure {
public:
    square() : figure(20, 20, 20, 20, 90, 90, 90, 90) {}
};

class parallelogram : public figure {
public:
    parallelogram() : figure(20, 30, 20, 30, 30, 40, 30, 40) {}
};

class rhombus : public figure {
public:
    rhombus() : figure(30, 30, 30, 30, 30, 40, 30, 40) {}
};

int main() {
    setlocale(LC_ALL, "ru");

    triangle tri;
    tri.printfigure("Треугольник");

    right_triangle right_tri;
    right_tri.printfigure("Прямоугольный треугольник");

    isosceles_triangle iso_tri;
    iso_tri.printfigure("Равнобедренный треугольник");

    equilateral_triangle eq_tri;
    eq_tri.printfigure("Равносторонний треугольник");

    quadrilateral quad;
    quad.printfigure("Четырёхугольник");

    rectangle rect;
    rect.printfigure("Прямоугольник");

    square sq;
    sq.printfigure("Квадрат");

    parallelogram para;
    para.printfigure("Параллелограмм");

    rhombus rhom;
    rhom.printfigure("Ромб");

    return 0;
}
