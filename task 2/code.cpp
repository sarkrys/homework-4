#include <iostream>
#include <fstream>
#include <string>

class figure {
protected:
    int a;
    int b;
    int c;
    int d;
    int A;
    int B;
    int C;
    int D;

public:
    figure(int a,int b,int c,int d,int A,int B, int C, int D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}
    int get_figur() {
        return a , b, c, d, A, B, C, D;
    }
    void printfigure(std::string figurname) {
        std::cout << std::endl <<  figurname << ": " << std::endl << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << std::endl << "Углы: " << "A=" << A << " B=" << B<< " C=" << C;
    }
    void printfiguretwoword(std::string figurnamef, std::string figurnames) {
        std::cout << std::endl<< figurnamef << " " << figurnames << ": " << std::endl << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << std::endl << "Углы: " << "A=" <<A << " B="  << B<< " C=" << C;
    }
    void printfigurechetug(std::string figurname) {
        std::cout  << std::endl<< figurname << ": " << std::endl << "Стороны: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d <<  std::endl << "Углы: " << "A=" << A << " B="  << B<< " C=" << C << " D=" << D << std::endl << std::endl;
    }
};

class triangle : public figure {
public:
    triangle(int a, int b, int c, int d, int A, int B, int C, int D) : figure(a, b, c, d, A, B, C, D) {}
    void createtriangl() {
        a = 10;
        b = 20;
        c = 30;
        A = 50;
        B = 60;
        C = 70;
    }
};

class pramtriug : public figure {
public:
    pramtriug(int a, int b, int c, int d, int A, int B, int C, int D) : figure(a, b, c, d, A, B, C, D) {}
    void createpramtriug() {
        a = 10;
        b = 20;
        c = 30;
        A = 50;
        B = 60;
        C = 90;
    }
};
class ravnobedtriug : public figure {
public:
    ravnobedtriug(int a, int b, int c, int d, int A, int B, int C, int D) : figure(a, b, c, d, A, B, C, D) {}
    void createtriangl() {
        a = 10;
        b = 20;
        c = 30;
        A = 50;
        B = 60;
        C = 50;
    }
}; class ravnostrtriug : public figure {
public:
    ravnostrtriug(int a, int b, int c, int d, int A, int B, int C, int D) : figure(a, b, c, d, A, B, C, D) {}
    void createtriangl() {
        a = 30;
        b = 30;
        c = 30;
        A = 60;
        B = 60;
        C = 60;
    }
}; class chetirehug : public figure {
public:
    chetirehug(int a, int b, int c, int d, int A, int B, int C, int D) : figure(a, b, c, d, A, B, C, D) {}
    void createtriangl() {
        a = 10;
        b = 20;
        c = 30;
        d = 40;
        A = 50;
        B = 60;
        C = 70;
        D = 80;
    }
}; class priamoug : public figure {
public:
    priamoug(int a, int b, int c, int d, int A, int B, int C, int D) : figure(a, b, c, d, A, B, C, D) {}
    void createtriangl() {
        a = 10;
        b = 20;
        c = 10;
        d = 20;
        A = 90;
        B = 90;
        C = 90;
        D = 90;
    }
}; class kvadrat : public figure {
public:
    kvadrat(int a, int b, int c, int d, int A, int B, int C, int D) : figure(a, b, c, d, A, B, C, D) {}
    void createtriangl() {
        a = 20;
        b = 20;
        c = 20;
        d = 20;
        A = 90;
        B = 90;
        C = 90;
        D = 90;
    }
}; class paralerogram : public figure {
public:
    paralerogram(int a, int b, int c, int d, int A, int B, int C, int D) : figure(a, b, c, d, A, B, C, D) {}
    void createtriangl() {
        a = 20;
        b = 30;
        c = 20;
        d = 30;
        A = 30;
        B = 40;
        C = 30;
        D = 40;
    }
}; class romb : public figure {
public:
    romb(int a, int b, int c, int d, int A, int B, int C, int D) : figure(a, b, c, d, A, B, C, D) {}
    void createtriangl() {
        a = 30;
        b = 30;
        c = 30;
        d = 30;
        A = 30;
        B = 40;
        C = 30;
        D = 30;
    }
};

int main() {

    triangle mytri(0, 0, 0, 0, 0, 0, 0, 0);
    mytri.createtriangl();
    mytri.printfigure("треугольник");

    pramtriug mytripra(0, 0, 0, 0, 0, 0, 0, 0);
    mytri.createtriangl();
    mytri.printfiguretwoword("прямоугоьный", "треугольник");

    ravnobedtriug mytrirav(0, 0, 0, 0, 0, 0, 0, 0);
    mytri.createtriangl();
    mytri.printfiguretwoword("равнобедренный", "треугольник");

    ravnostrtriug mytriravstr(0, 0, 0, 0, 0, 0, 0, 0);
    mytri.createtriangl();
    mytri.printfiguretwoword("равносторонний", "треугольник");

    chetirehug mychet(0, 0, 0, 0, 0, 0, 0, 0);
    mytri.createtriangl();
    mytri.printfigure("четырёхугольник");

    priamoug mypramoug(0, 0, 0, 0, 0, 0, 0, 0);
    mytri.createtriangl();
    mytri.printfigure("прямоугольник");

    kvadrat mykvadr(0, 0, 0, 0, 0, 0, 0, 0);
    mytri.createtriangl();
    mytri.printfigure("квадрат");

    paralerogram myparal(0, 0, 0, 0, 0, 0, 0, 0);
    mytri.createtriangl();
    mytri.printfigure("паралерограмм");

    romb myromb(0, 0,0,0,0,0,0,0);
    mytri.createtriangl();
    mytri.printfigure("ромб");
    return 0;
}
