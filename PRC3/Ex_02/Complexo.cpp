#include "Complexo.hpp"
#include <cmath>
#include <iomanip>

double Complexo::normalizarAngulo(double theta) {
    while (theta <= -M_PI) theta += 2.0 * M_PI;
    while (theta > M_PI)  theta -= 2.0 * M_PI;
    if (std::abs(theta) < EPSILON) theta = 0.0;
    return theta;
}

bool Complexo::quaseIgual(double a, double b) {
    return std::abs(a - b) < EPSILON;
}

/* =============================================================================
 * 1. FORMA CANONICA ORTODOXA
 * ============================================================================= */

Complexo::Complexo() {
    formatoAtual = RETANGULAR;
    rec.real = 0.0;
    rec.imag = 0.0;
}

Complexo::Complexo(const Complexo& outro) {
    formatoAtual = outro.formatoAtual;
    if(formatoAtual == RETANGULAR) {
        rec.real = outro.rec.real;
        rec.imag = outro.rec.imag;
    } else {
        pol.modulo = outro.pol.modulo;
        pol.arg = outro.pol.arg;
    }
}

Complexo& Complexo::operator=(const Complexo& outro) {
    if(this != &outro) {
        formatoAtual = outro.formatoAtual;
        if(formatoAtual == RETANGULAR) {
            rec.real = outro.rec.real;
            rec.imag = outro.rec.imag;
        } else {
            pol.modulo = outro.pol.modulo;
            pol.arg = outro.pol.arg;
        }
    }
    return *this;
}

Complexo::~Complexo() {
}

/* =============================================================================
 * 2. CONSTRUTORES DE CONVERSAO E TIPOS PRIMITIVOS
 * ============================================================================= */

Complexo::Complexo(double real, double imag, Formato f) {
    formatoAtual = f;
    if(f == RETANGULAR) {
        rec.real = real;
        rec.imag = imag;
    } else {
        pol.modulo = real;
        pol.arg = normalizarAngulo(imag);
    }
}

Complexo::Complexo(float real, float imag, Formato f)
    : Complexo(static_cast<double>(real), static_cast<double>(imag), f) {
}

Complexo::Complexo(int real, int imag, Formato f)
    : Complexo(static_cast<double>(real), static_cast<double>(imag), f) {
}

Complexo::Complexo(long long real, long long imag, Formato f)
    : Complexo(static_cast<double>(real), static_cast<double>(imag), f) {
}

Complexo& Complexo::operator=(double r) {
    formatoAtual = RETANGULAR;
    rec.real = r;
    rec.imag = 0.0;
    return *this;
}

Complexo& Complexo::operator=(int r) {
    return *this = static_cast<double>(r);
}

/* =============================================================================
 * 3. OPERADORES DE CONVERSAO EXPLICITA (CASTS)
 * ============================================================================= */

Complexo::operator double() const {
    return real();
}

Complexo::operator float() const {
    return static_cast<float>(real());
}

Complexo::operator int() const {
    return static_cast<int>(real());
}

Complexo::operator bool() const {
    return modulo() > EPSILON;
}

/* =============================================================================
 * 4. METODOS DE ACESSO (GETTERS) E CONVERSAO DE FORMATO
 * ============================================================================= */

double Complexo::real() const {
    if(formatoAtual == RETANGULAR) {
        return rec.real;
    }
    return pol.modulo * std::cos(pol.arg);
}

double Complexo::imag() const {
    if(formatoAtual == RETANGULAR) {
        return rec.imag;
    }
    return pol.modulo * std::sin(pol.arg);
}

double Complexo::modulo() const {
    if(formatoAtual == POLAR) {
        return pol.modulo;
    }
    return std::hypot(rec.real, rec.imag);
}

double Complexo::arg() const {
    if(formatoAtual == POLAR) {
        return pol.arg;
    }
    return std::atan2(rec.imag, rec.real);
}

Formato Complexo::formato() const {
    return formatoAtual;
}

Complexo Complexo::converterPara(Formato novoFormato) const {
    if(formatoAtual == novoFormato) {
        return *this;
    }
    if(novoFormato == POLAR) {
        return Complexo(modulo(), arg(), POLAR);
    }
    return Complexo(real(), imag(), RETANGULAR);
}

/* =============================================================================
 * 5. OPERADORES ARITMETICOS BINARIOS
 * ============================================================================= */

Complexo Complexo::operator+(const Complexo& b) const {
    Complexo res(real() + b.real(), imag() + b.imag(), RETANGULAR);
    return res.converterPara(formatoAtual);
}

Complexo Complexo::operator-(const Complexo& b) const {
    Complexo res(real() - b.real(), imag() - b.imag(), RETANGULAR);
    return res.converterPara(formatoAtual);
}

Complexo Complexo::operator*(const Complexo& b) const {
    if(formatoAtual == POLAR && b.formatoAtual == POLAR) {
        return Complexo(pol.modulo * b.pol.modulo, normalizarAngulo(pol.arg + b.pol.arg), POLAR);
    }
    double r = real() * b.real() - imag() * b.imag();
    double i = real() * b.imag() + imag() * b.real();
    Complexo res(r, i, RETANGULAR);
    return res.converterPara(formatoAtual);
}

Complexo Complexo::operator/(const Complexo& b) const {
    if(formatoAtual == POLAR && b.formatoAtual == POLAR) {
        return Complexo(pol.modulo / b.pol.modulo, normalizarAngulo(pol.arg - b.pol.arg), POLAR);
    }
    double den = b.real() * b.real() + b.imag() * b.imag();
    double r = (real() * b.real() + imag() * b.imag()) / den;
    double i = (imag() * b.real() - real() * b.imag()) / den;
    Complexo res(r, i, RETANGULAR);
    return res.converterPara(formatoAtual);
}

Complexo Complexo::operator+(double r) const {
    return *this + Complexo(r, 0.0, RETANGULAR);
}

Complexo Complexo::operator-(double r) const {
    return *this - Complexo(r, 0.0, RETANGULAR);
}

Complexo Complexo::operator*(double r) const {
    return *this * Complexo(r, 0.0, RETANGULAR);
}

Complexo Complexo::operator/(double r) const {
    return *this / Complexo(r, 0.0, RETANGULAR);
}

Complexo operator+(double r, const Complexo& c) {
    return Complexo(r, 0.0, c.formato()) + c;
}

Complexo operator-(double r, const Complexo& c) {
    return Complexo(r, 0.0, c.formato()) - c;
}

Complexo operator*(double r, const Complexo& c) {
    return Complexo(r, 0.0, c.formato()) * c;
}

Complexo operator/(double r, const Complexo& c) {
    return Complexo(r, 0.0, c.formato()) / c;
}

/* =============================================================================
 * 6. OPERADORES DE ATRIBUICAO COMPOSTA
 * ============================================================================= */

Complexo& Complexo::operator+=(const Complexo& b) {
    *this = *this + b;
    return *this;
}

Complexo& Complexo::operator-=(const Complexo& b) {
    *this = *this - b;
    return *this;
}

Complexo& Complexo::operator*=(const Complexo& b) {
    *this = *this * b;
    return *this;
}

Complexo& Complexo::operator/=(const Complexo& b) {
    *this = *this / b;
    return *this;
}

Complexo& Complexo::operator+=(double r) {
    *this = *this + r;
    return *this;
}

Complexo& Complexo::operator-=(double r) {
    *this = *this - r;
    return *this;
}

Complexo& Complexo::operator*=(double r) {
    *this = *this * r;
    return *this;
}

Complexo& Complexo::operator/=(double r) {
    *this = *this / r;
    return *this;
}

Complexo& Complexo::operator^=(double expoente) {
    *this = *this ^ expoente;
    return *this;
}

Complexo& Complexo::operator^=(const Complexo& expoente) {
    *this = *this ^ expoente;
    return *this;
}

/* =============================================================================
 * 7. OPERADORES UNARIOS E INCREMENTOS
 * ============================================================================= */

Complexo Complexo::operator-() const {
    if(formatoAtual == RETANGULAR) {
        return Complexo(-rec.real, -rec.imag, RETANGULAR);
    }
    return Complexo(pol.modulo, normalizarAngulo(pol.arg + M_PI), POLAR);
}

Complexo& Complexo::operator++() {
    *this = *this + 1.0;
    return *this;
}

Complexo Complexo::operator++(int) {
    Complexo temp = *this;
    *this = *this + 1.0;
    return temp;
}

Complexo& Complexo::operator--() {
    *this = *this - 1.0;
    return *this;
}

Complexo Complexo::operator--(int) {
    Complexo temp = *this;
    *this = *this - 1.0;
    return temp;
}

/* =============================================================================
 * 8. OPERADORES DE COMPARACAO
 * ============================================================================= */

bool Complexo::operator==(const Complexo& outro) const {
    return quaseIgual(real(), outro.real()) && quaseIgual(imag(), outro.imag());
}

bool Complexo::operator!=(const Complexo& outro) const {
    return !(*this == outro);
}

bool Complexo::operator==(double r) const {
    return quaseIgual(real(), r) && quaseIgual(imag(), 0.0);
}

bool Complexo::operator!=(double r) const {
    return !(*this == r);
}

bool operator==(double r, const Complexo& c) {
    return c == r;
}

bool operator!=(double r, const Complexo& c) {
    return c != r;
}

/* =============================================================================
 * 9. OPERADORES DE POTENCIACAO
 * ============================================================================= */

Complexo Complexo::operator^(double expoente) const {
    return potencia(expoente);
}

Complexo Complexo::operator^(int expoente) const {
    return potencia(static_cast<double>(expoente));
}

Complexo Complexo::operator^(const Complexo& expoente) const {
    if(modulo() < EPSILON) {
        return Complexo(0.0, 0.0, formatoAtual);
    }
    return (expoente * log()).exponencial().converterPara(formatoAtual);
}

Complexo operator^(double base, const Complexo& expoente) {
    if(base <= 0.0) {
        return Complexo(0.0, 0.0);
    }
    return (expoente * std::log(base)).exponencial();
}

/* =============================================================================
 * 10. FUNCOES MATEMATICAS AVANCADAS
 * ============================================================================= */

Complexo Complexo::conjugado() const {
    if(formatoAtual == POLAR) {
        return Complexo(pol.modulo, normalizarAngulo(-pol.arg), POLAR);
    }
    return Complexo(rec.real, -rec.imag, RETANGULAR);
}

Complexo Complexo::potencia(double n) const {
    double r = std::pow(modulo(), n);
    double theta = normalizarAngulo(arg() * n);
    Complexo res(r, theta, POLAR);
    return res.converterPara(formatoAtual);
}

Complexo Complexo::exponencial() const {
    double ex = std::exp(real());
    double y = imag();
    Complexo res(ex * std::cos(y), ex * std::sin(y), RETANGULAR);
    return res.converterPara(formatoAtual);
}

Complexo Complexo::log() const {
    double m = modulo();
    if(m < EPSILON) {
        return Complexo(-1e9, 0.0, formatoAtual);
    }
    Complexo res(std::log(m), arg(), RETANGULAR);
    return res.converterPara(formatoAtual);
}

void Complexo::raizes(int n, Complexo resultados[]) const {
    if(n <= 0) return;
    double r = std::pow(modulo(), 1.0 / n);
    double theta = arg();
    for(int k = 0; k < n; k++) {
        double ang_k = normalizarAngulo((theta + 2.0 * M_PI * k) / n);
        Complexo rk(r, ang_k, POLAR);
        resultados[k] = rk.converterPara(formatoAtual);
    }
}

/* =============================================================================
 * 11. FUNCOES TRIGONOMETRICAS COMPLEXAS
 * ============================================================================= */

Complexo Complexo::sin() const {
    double x = real();
    double y = imag();
    Complexo res(std::sin(x) * std::cosh(y), std::cos(x) * std::sinh(y), RETANGULAR);
    return res.converterPara(formatoAtual);
}

Complexo Complexo::cos() const {
    double x = real();
    double y = imag();
    Complexo res(std::cos(x) * std::cosh(y), -std::sin(x) * std::sinh(y), RETANGULAR);
    return res.converterPara(formatoAtual);
}

Complexo Complexo::tan() const {
    return sin() / cos();
}

Complexo sin(const Complexo& z) {
    return z.sin();
}

Complexo cos(const Complexo& z) {
    return z.cos();
}

Complexo tan(const Complexo& z) {
    return z.tan();
}

/* =============================================================================
 * 12. FUNCOES HIPERBOLICAS COMPLEXAS
 * ============================================================================= */

Complexo Complexo::sinh() const {
    double x = real();
    double y = imag();
    Complexo res(std::sinh(x) * std::cos(y), std::cosh(x) * std::sin(y), RETANGULAR);
    return res.converterPara(formatoAtual);
}

Complexo Complexo::cosh() const {
    double x = real();
    double y = imag();
    Complexo res(std::cosh(x) * std::cos(y), std::sinh(x) * std::sin(y), RETANGULAR);
    return res.converterPara(formatoAtual);
}

Complexo Complexo::tanh() const {
    return sinh() / cosh();
}

Complexo sinh(const Complexo& z) {
    return z.sinh();
}

Complexo cosh(const Complexo& z) {
    return z.cosh();
}

Complexo tanh(const Complexo& z) {
    return z.tanh();
}

/* =============================================================================
 * 13. FUNCOES AMIGAS AUXILIARES (COMPATIBILIDADE STL / ADL)
 * ============================================================================= */

double real(const Complexo& c) {
    return c.real();
}

double imag(const Complexo& c) {
    return c.imag();
}

double abs(const Complexo& c) {
    return c.modulo();
}

double arg(const Complexo& c) {
    return c.arg();
}

Complexo exp(const Complexo& z) {
    return z.exponencial();
}

Complexo log(const Complexo& z) {
    return z.log();
}

/* =============================================================================
 * 14. OPERADORES DE FLUXO (I/O STREAMS)
 * ============================================================================= */

std::ostream& operator<<(std::ostream& os, const Complexo& c) {
    os << std::fixed << std::setprecision(2);
    if(c.formato() == RETANGULAR) {
        double r = c.real();
        double i = c.imag();
        if(std::abs(r) < 1e-9) r = 0.0;
        if(std::abs(i) < 1e-9) i = 0.0;
        if(i >= 0.0) {
            os << r << " + " << i << "i";
        } else {
            os << r << " - " << std::abs(i) << "i";
        }
    } else {
        double m = c.modulo();
        double a = c.arg();
        if(std::abs(m) < 1e-9) m = 0.0;
        if(std::abs(a) < 1e-9) a = 0.0;
        os << m << " < " << a << " rad";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Complexo& c) {
    double r, i;
    if(is >> r >> i) {
        c = Complexo(r, i, RETANGULAR);
    }
    return is;
}

/* =============================================================================
 * 15. LITERAIS DEFINIDOS PELO USUARIO
 * ============================================================================= */

Complexo operator""_i(long double imag) {
    return Complexo(0.0, static_cast<double>(imag), RETANGULAR);
}

Complexo operator""_j(long double imag) {
    return Complexo(0.0, static_cast<double>(imag), RETANGULAR);
}

Complexo operator""_i(unsigned long long int imag) {
    return Complexo(0.0, static_cast<double>(imag), RETANGULAR);
}

Complexo operator""_j(unsigned long long int imag) {
    return Complexo(0.0, static_cast<double>(imag), RETANGULAR);
}

double operator""_deg(long double graus) {
    return static_cast<double>(graus * (M_PI / 180.0));
}

double operator""_deg(unsigned long long int graus) {
    return static_cast<double>(graus * (M_PI / 180.0));
}

double operator""_rad(long double rad) {
    return static_cast<double>(rad);
}

double operator""_rad(unsigned long long int rad) {
    return static_cast<double>(rad);
}