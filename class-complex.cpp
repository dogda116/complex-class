#include <cmath>
#include <iostream>

class Complex {
private:
    double re, im;
public:
    Complex(double x = 0, double y = 0) {
        re = x;
        im = y;
    }

    double Re() const {
        return re;
    }

    double Im() const {
        return im;
    }

    bool operator == (const Complex& z2) const {
        return re == z2.re && im == z2.im;
    }

    bool operator != (const Complex& z2) const {
        return Re() != z2.Re() || Im() != z2.Im();
    }

    Complex& operator += (const Complex& z2) {
        this->re += z2.re;
        this->im += z2.im;
        return *this;
    }

    Complex& operator -= (const Complex& z2) {
        this->re -= z2.re;
        this->im -= z2.im;
        return *this;
    }

    Complex& operator *= (const Complex& z2) {
        auto curr_re = re;
        this->re = re * z2.re - im * z2.im;
        this->im = im * z2.re + curr_re * z2.im;
        return *this;
    }

    Complex& operator /= (const Complex& z2) {
        auto curr_re = re;
        this->re = (re * z2.re + im * z2.im) / (z2.re * z2.re + z2.im * z2.im);
        this->im = (im * z2.re - curr_re * z2.im) / (z2.re * z2.re + z2.im * z2.im);
        return *this;
    }

    Complex operator + () {
        return {re, im};
    }

    Complex operator - () {
        return {-re, -im};
    }
};

Complex operator + (const Complex& z1, const Complex& z2) {
    return {z1.Re() + z2.Re(), z1.Im() + z2.Im()};
}

Complex operator - (const Complex& z1, const Complex& z2) {
    return {z1.Re() - z2.Re(), z1.Im() - z2.Im()};
}

Complex operator * (const Complex& z1, const Complex& z2) {
    return {z1.Re() * z2.Re() - z1.Im() * z2.Im(), z1.Im() * z2.Re() + z1.Re() * z2.Im()};
}

Complex operator / (const Complex& z1, const Complex& z2) {
    return {
            (z1.Re() * z2.Re() + z1.Im() * z2.Im()) / (z2.Re() * z2.Re() + z2.Im() * z2.Im()),
            (z1.Im() * z2.Re() - z1.Re() * z2.Im()) / (z2.Re() * z2.Re() + z2.Im() * z2.Im())
    };
}

double abs(const Complex& z1) {
    return sqrt(z1.Re() * z1.Re() + z1.Im() * z1.Im());
}
