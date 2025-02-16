#include <iostream>
#include <cmath>

struct Ponto {
    double x, y;
    
    Ponto(double x = 0, double y = 0) : x(x), y(y) {}
    
    void exibir() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

double distancia(const Ponto& p1, const Ponto& p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

struct Reta {
    double a, b, c; 
    
    Reta(double a, double b, double c) : a(a), b(b), c(c) {}
    
    double distancia(const Ponto& p) const {
        return std::fabs(a * p.x + b * p.y + c) / std::sqrt(a * a + b * b);
    }
};

double areaTriangulo(const Ponto& p1, const Ponto& p2, const Ponto& p3) {
    return std::fabs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
}

