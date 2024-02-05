#include <iostream>
#include <string>

class figure {
protected:
    int a, b, c, d, A, B, C, D;

public:
    figure(int a, int b, int c, int d, int A, int B, int C, int D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

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
    triangle(int a, int b, int c, int A, int B, int C) : figure(a, b, c, 0, A, B, C, 0) {}

    bool checkValidity() override {
        if (a + b > c && a + c > b && b + c > a && A + B + C == 180 && getSideCount() == 3) {
            return true;
        }
        else {
            return false;
        }
    }

    int getSideCount() override {
        return 3;
    }
};

class right_triangle : public triangle {
public:
    right_triangle(int a, int b, int c, int A, int B, int C) : triangle(a, b, c, A, B, C) {}

    bool checkValidity() override {
        if (A == 90 || B == 90 || C == 90) {
            return true;
        }
        else {
            return false;
        }
    }
};

class quadrilateral : public figure {
public:
    quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : figure(a, b, c, d, A, B, C, D) {}

    bool checkValidity() override {
        if (getSideCount() == 4 && A + B + C + D == 360) {
            return true;
        }
        else {
            return false;
        }
    }

    int getSideCount() override {
        return 4;
    }
};

class rectangle : public quadrilateral {
public:
    rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : quadrilateral(a, b, c, d, A, B, C, D) {}

    bool checkValidity() override {
        if (((a == c && b == d) || (a == b && c == d)) && (A == 90 && B == 90 && C == 90 && D == 90)) {
            return true;
        }
        else {
            return false;
        }
    }
};

class square : public rectangle {
public:
    square(int a, int A) : rectangle(a, a, a, a, A, A, A, A) {}

    bool checkValidity() override {
        if (a == b && b == c && c == d && A == B && B == C && C == D && A == 90) {
            return true;
        }
        else {
            return false;
        }
    }
};

class parallelogram : public quadrilateral {
public:
    parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : quadrilateral(a, b, c, d, A, B, C, D) {}

    bool checkValidity() override {
        if ((a == c && b == d) || (a == b && c == d)) {
            return true;
        }
        else {
            return false;
        }
    }
};

class rhombus : public square {
public:
    rhombus(int a, int A) : square(a, A) {}

    bool checkValidity() override {
        if (a == b && b == c && c == d && A == B && B == C && C == D) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    // создаем фигуры
    triangle myTriangle(10, 20, 30, 50, 60, 70);
    right_triangle myRightTriangle(10, 20, 30, 50, 60, 90);
    right_triangle myAnotherRightTriangle(10, 20, 30, 50, 40, 90);
    triangle myIsoscelesTriangle(10, 20, 10, 50, 60, 50);
    triangle myEquilateralTriangle(30, 30, 30, 60, 60, 60);

    quadrilateral myQuadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    rectangle myRectangle(10, 20, 10, 20, 90, 90, 90, 90);
    square mySquare(20, 90);
    parallelogram myParallelogram(20, 30, 20, 30, 30, 40, 30, 40);
    rhombus myRhombus(30, 30);

    // выводим информацию о фигурах
    myTriangle.printFigureInfo("Треугольник");
    myRightTriangle.printFigureInfo("Прямоугольный треугольник");
    myAnotherRightTriangle.printFigureInfo("Прямоугольный треугольник");
    myIsoscelesTriangle.printFigureInfo("Равнобедренный треугольник");
    myEquilateralTriangle.printFigureInfo("Равносторонний треугольник");
    myQuadrilateral.printFigureInfo("Четырёхугольник");
    myRectangle.printFigureInfo("Прямоугольник");
    mySquare.printFigureInfo("Квадрат");
    myParallelogram.printFigureInfo("Параллелограмм");
    myRhombus.printFigureInfo("Ромб");

    return 0;
}