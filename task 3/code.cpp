#include <iostream>
#include <string>

class figure {
protected:
    int a, b, c, d, A, B, C, D;

public:
    figure() : a(0), b(0), c(0), d(0), A(0), B(0), C(0), D(0) {}

    virtual bool checkValidity() {
        return false;
    }

    void printFigureInfo(std::string figurname) {
        std::cout << figurname << ":\n";
        if (checkValidity()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << getSideCount() << std::endl;
        if (a != 0) {
            std::cout << "Стороны: a=" << a;
        }
        if (b != 0) {
            std::cout << " b=" << b;
        }
        if (c != 0) {
            std::cout << " c=" << c;
        }
        if (d != 0) {
            std::cout << " d=" << d;
        }
        std::cout << std::endl;
        if (A != 0) {
            std::cout << "Углы: A=" << A;
        }
        if (B != 0) {
            std::cout << " B=" << B;
        }
        if (C != 0) {
            std::cout << " C=" << C;
        }
        if (D != 0) {
            std::cout << " D=" << D;
        }
        std::cout << std::endl << std::endl;
    }

    virtual int getSideCount() {
        return 0;
    }
};

class triangle : public figure {
public:
    triangle() : figure() {
        a = 10;
        b = 20;
        c = 30;
        A = 50;
        B = 60;
        C = 70;
    }

    bool checkValidity() override {
        return (a + b > c && a + c > b && b + c > a && A + B + C == 180 && getSideCount() == 3);
    }

    int getSideCount() override {
        return 3;
    }
};

class right_triangle : public triangle {
public:
    right_triangle() : triangle() {
        C = 90;
    }

    bool checkValidity() override {
        return (A == 90 && B == 90 && C == 90);
    }
};

class isosceles_triangle : public triangle {
public:
    isosceles_triangle() : triangle() {
        a = 15;
        b = 15;
        c = 20;
    }

    bool checkValidity() override {
        return (a == b || a == c || b == c);
    }
};

class equilateral_triangle : public triangle {
public:
    equilateral_triangle() : triangle() {
        a = 10;
        b = 10;
        c = 10;
    }

    bool checkValidity() override {
        return (a == b && b == c);
    }
};

class quadrilateral : public figure {
public:
    quadrilateral() : figure() {
        a = 10;
        b = 20;
        c = 30;
        d = 40;
        A = 50;
        B = 60;
        C = 70;
        D = 80;
    }

    bool checkValidity() override {
        return (getSideCount() == 4 && A + B + C + D == 360);
    }

    int getSideCount() override {
        return 4;
    }
};

class rectangle : public quadrilateral {
public:
    rectangle() : quadrilateral() {
        C = 90;
        D = 90;
    }

    bool checkValidity() override {
        return (((a == c && b == d) || (a == b && c == d)) && (A == 90 && B == 90 && C == 90 && D == 90));
    }
};

class square : public rectangle {
public:
    square() : rectangle() {
        A = 90;
        B = 90;
        C = 90;
        D = 90;
    }

    bool checkValidity() override {
        return (a == b && b == c && c == d && A == B && B == C && C == D && A == 90);
    }
};

class parallelogram : public quadrilateral {
public:
    parallelogram() : quadrilateral() {}

    bool checkValidity() override {
        return ((a == c && b == d) || (a == b && c == d));
    }
};

class rhombus : public square {
public:
    rhombus() : square() {}
};

int main() {
    setlocale(LC_ALL, "ru");
    triangle tri;
    tri.printFigureInfo("Треугольник");

    right_triangle right_tri;
    right_tri.printFigureInfo("Прямоугольный треугольник");

    isosceles_triangle iso_tri;
    iso_tri.printFigureInfo("Равнобедренный треугольник");

    equilateral_triangle equi_tri;
    equi_tri.printFigureInfo("Равносторонний треугольник");

    quadrilateral quad;
    quad.printFigureInfo("Четырехугольник");

    rectangle rect;
    rect.printFigureInfo("Прямоугольник");

    square sq;
    sq.printFigureInfo("Квадрат");

    parallelogram para;
    para.printFigureInfo("Параллелограмм");

    rhombus rhom;
    rhom.printFigureInfo("Ромб");

    return 0;
}