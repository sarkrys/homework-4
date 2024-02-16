#include <iostream>
#include <string>
class figure {
protected:
    int a, b, c, d, A, B, C, D;
public:
    figure(int side1, int side2, int side3, int side4, int angle1, int angle2, int angle3, int angle4)
        : a(side1), b(side2), c(side3), d(side4), A(angle1), B(angle2), C(angle3), D(angle4) {}
    figure(int side1, int side2, int side3, int angle1, int angle2, int angle3)
        : a(side1), b(side2), c(side3), d(0), A(angle1), B(angle2), C(angle3), D(0) {}
    figure(int side)
        : a(side), b(side), c(side), d(0), A(60), B(60), C(60), D(0) {}
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
    triangle(int side1, int side2, int side3, int angle1, int angle2, int angle3)
        : figure(side1, side2, side3, 0, angle1, angle2, angle3, 0) {}
    bool checkValidity() override {
        return (a + b > c && a + c > b && b + c > a && A + B + C == 180 && getSideCount() == 3);
    }
    int getSideCount() override {
        return 3;
    }
};
class right_triangle : public triangle {
public:
    right_triangle(int side1, int side2, int angle1, int angle2)
        : triangle(side1, side2, 0, angle1, angle2, 90) {}
    bool checkValidity() override {
        return (A == 90 && B == 90 && C == 90);
    }
};
class equilateral_triangle : public triangle {
public:
    equilateral_triangle(int side)
        : triangle(side, side, side, 60, 60, 60) {}
    bool checkValidity() override {
        return (a == b && b == c);
    }
};
class ravnobed_triangle : public triangle {
public:
    ravnobed_triangle(int side1, int side2, int side3, int angle1, int angle2, int angle3)
        : triangle(side1, side2, side3, angle1, angle2, angle3) {}

    bool checkValidity() override {
        return (a == c && A == C && getSideCount() == 3);
    }
};

class rectangle : public figure {
public:
    rectangle(int side1, int side2) : figure(side1, side2, side1, side2, 90, 90, 90, 90) {}
    bool checkValidity() override {
        return (a == c && b == d) && (A == B && B == C && C == D && A == 90);
    }
    int getSideCount() override {
        return 4;
    }
};
class square : public rectangle {
public:
    square(int side) : rectangle(side, side) {}
    bool checkValidity() override {
        return (a == b && b == c && c == d && A == B && B == C && C == D && A == 90);
    }
};
class parallelogram : public figure {
public:
    parallelogram(int side1, int side2, int angle)
        : figure(side1, side2, side1, side2, angle, 180 - angle, angle, 180 - angle) {}
    bool checkValidity() override {
        return (a == c && b == d) && (A == B && B == C && C == D);
    }
    int getSideCount() override {
        return 4;
    }
};
class rhombus : public square {
public:
    rhombus(int side) : square(side) {}

    bool checkValidity() override {
        return (a == b && b == c && c == d) && (A == C && B == D && A == 60);
    }
};
int main() {
    setlocale(LC_ALL, "ru");
    triangle tri(10, 20, 30, 50, 60, 70);
    tri.printFigureInfo("Треугольник");
    right_triangle right_tri(10, 20, 50, 60);
    right_tri.printFigureInfo("Прямоугольный треугольник");
    equilateral_triangle eq_tri(30);
    eq_tri.printFigureInfo("Равносторонний треугольник");
    ravnobed_triangle ra_tri(10, 20, 10, 50, 60, 50);
    eq_tri.printFigureInfo("Равнобедренный треугольник");
    rectangle rect(10, 20);
    rect.printFigureInfo("Прямоугольник");
    square sq(30);
    sq.printFigureInfo("Квадрат");
    parallelogram para(20, 30, 40);
    para.printFigureInfo("Параллелограмм");
    rhombus rhom(30);
    rhom.printFigureInfo("Ромб");
    return 0;
}
