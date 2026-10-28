#include "Complexo.hpp"
#include <cmath>
#include <iomanip>

// =============================================================================
// FUNÇÕES PRIVADAS (AUXILIARES)
// =============================================================================

double Complexo::normalizarAngulo(double theta) {
    while (theta <= -M_PI) theta += 2.0 * M_PI;
    while (theta > M_PI)  theta -= 2.0 * M_PI;
    if (std::abs(theta) < EPSILON) theta = 0.0;
    return theta;
}

bool Complexo::quaseIgual(double a, double b) {
    return std::abs(a - b) < EPSILON;
}

// =============================================================================
// 1. FORMA CANÔNICA ORTODOXA
// =============================================================================

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

// =============================================================================
// 2. CONSTRUTORES DE CONVERSÃO E TIPOS PRIMITIVOS
// =============================================================================

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

// =============================================================================
// 3. OPERADORES DE CONVERSÃO EXPLÍCITA (CASTS)
// =============================================================================

Complexo::operator double() const {
    //--------
    return 0.0;
}

Complexo::operator float() const {
    //--------
    return 0.0f;
}

Complexo::operator int() const {
    //--------
    return 0;
}

Complexo::operator bool() const {
    //--------
    return false;
}

// =============================================================================
// 4. MÉTODOS DE ACESSO (GETTERS) E CONVERSÃO DE FORMATO
// =============================================================================

double Complexo::real() const {
    //--------
    return 0.0;
}

double Complexo::imag() const {
    //--------
    return 0.0;
}

double Complexo::modulo() const {
    //--------
    return 0.0;
}

double Complexo::arg() const {
    //--------
    return 0.0;
}

Formato Complexo::formato() const {
    //--------
    return formatoAtual;
}

Complexo Complexo::converterPara(Formato novoFormato) const {
    //--------
    return *this;
}

// =============================================================================
// 5. OPERADORES ARITMÉTICOS BINÁRIOS
// =============================================================================

Complexo Complexo::operator+(const Complexo& b) const {
    //--------
    return *this;
}

Complexo Complexo::operator-(const Complexo& b) const {
    //--------
    return *this;
}

Complexo Complexo::operator*(const Complexo& b) const {
    //--------
    return *this;
}

Complexo Complexo::operator/(const Complexo& b) const {
    //--------
    return *this;
}

Complexo Complexo::operator+(double r) const {
    //--------
    return *this;
}

Complexo Complexo::operator-(double r) const {
    //--------
    return *this;
}

Complexo Complexo::operator*(double r) const {
    //--------
    return *this;
}

Complexo Complexo::operator/(double r) const {
    //--------
    return *this;
}

Complexo operator+(double r, const Complexo& c) {
    //--------
    return c;
}

Complexo operator-(double r, const Complexo& c) {
    //--------
    return c;
}

Complexo operator*(double r, const Complexo& c) {
    //--------
    return c;
}

Complexo operator/(double r, const Complexo& c) {
    //--------
    return c;
}

// =============================================================================
// 6. OPERADORES DE ATRIBUIÇÃO COMPOSTA
// =============================================================================

Complexo& Complexo::operator+=(const Complexo& b) {
    //--------
    return *this;
}

Complexo& Complexo::operator-=(const Complexo& b) {
    //--------
    return *this;
}

Complexo& Complexo::operator*=(const Complexo& b) {
    //--------
    return *this;
}

Complexo& Complexo::operator/=(const Complexo& b) {
    //--------
    return *this;
}

Complexo& Complexo::operator+=(double r) {
    //--------
    return *this;
}

Complexo& Complexo::operator-=(double r) {
    //--------
    return *this;
}

Complexo& Complexo::operator*=(double r) {
    //--------
    return *this;
}

Complexo& Complexo::operator/=(double r) {
    //--------
    return *this;
}

Complexo& Complexo::operator^=(double expoente) {
    //--------
    return *this;
}

Complexo& Complexo::operator^=(const Complexo& expoente) {
    //--------
    return *this;
}

// =============================================================================
// 7. OPERADORES UNÁRIOS E INCREMENTOS
// =============================================================================

Complexo Complexo::operator-() const {
    //--------
    return *this;
}

Complexo& Complexo::operator++() {
    //--------
    return *this;
}

Complexo Complexo::operator++(int) {
    //--------
    return *this;
}

Complexo& Complexo::operator--() {
    //--------
    return *this;
}

Complexo Complexo::operator--(int) {
    //--------
    return *this;
}

// =============================================================================
// 8. OPERADORES DE COMPARAÇÃO
// =============================================================================

bool Complexo::operator==(const Complexo& outro) const {
    //--------
    return false;
}

bool Complexo::operator!=(const Complexo& outro) const {
    //--------
    return false;
}

bool Complexo::operator==(double r) const {
    //--------
    return false;
}

bool Complexo::operator!=(double r) const {
    //--------
    return false;
}

bool operator==(double r, const Complexo& c) {
    //--------
    return false;
}

bool operator!=(double r, const Complexo& c) {
    //--------
    return false;
}

// =============================================================================
// 9. OPERADORES DE POTENCIAÇÃO
// =============================================================================

Complexo Complexo::operator^(double expoente) const {
    //--------
    return *this;
}

Complexo Complexo::operator^(int expoente) const {
    //--------
    return *this;
}

Complexo Complexo::operator^(const Complexo& expoente) const {
    //--------
    return *this;
}

Complexo operator^(double base, const Complexo& expoente) {
    //--------
    return Complexo();
}

// =============================================================================
// 10. FUNÇÕES MATEMÁTICAS AVANÇADAS
// =============================================================================

Complexo Complexo::conjugado() const {
    //--------
    return *this;
}

Complexo Complexo::potencia(double n) const {
    //--------
    return *this;
}

Complexo Complexo::exponencial() const {
    //--------
    return *this;
}

Complexo Complexo::log() const {
    //--------
    return *this;
}

void Complexo::raizes(int n, Complexo resultados[]) const {
    //--------
}

// =============================================================================
// 11. FUNÇÕES TRIGONOMÉTRICAS COMPLEXAS
// =============================================================================

Complexo Complexo::sin() const {
    //--------
    return *this;
}

Complexo Complexo::cos() const {
    //--------
    return *this;
}

Complexo Complexo::tan() const {
    //--------
    return *this;
}

Complexo sin(const Complexo& z) {
    //--------
    return z;
}

Complexo cos(const Complexo& z) {
    //--------
    return z;
}

Complexo tan(const Complexo& z) {
    //--------
    return z;
}

// =============================================================================
// 12. FUNÇÕES HIPERBÓLICAS COMPLEXAS
// =============================================================================

Complexo Complexo::sinh() const {
    //--------
    return *this;
}

Complexo Complexo::cosh() const {
    //--------
    return *this;
}

Complexo Complexo::tanh() const {
    //--------
    return *this;
}

Complexo sinh(const Complexo& z) {
    //--------
    return z;
}

Complexo cosh(const Complexo& z) {
    //--------
    return z;
}

Complexo tanh(const Complexo& z) {
    //--------
    return z;
}

// =============================================================================
// 13. FUNÇÕES AMIGAS AUXILIARES (COMPATIBILIDADE STL / ADL)
// =============================================================================

double real(const Complexo& c) {
    //--------
    return 0.0;
}

double imag(const Complexo& c) {
    //--------
    return 0.0;
}

double abs(const Complexo& c) {
    //--------
    return 0.0;
}

double arg(const Complexo& c) {
    //--------
    return 0.0;
}

Complexo exp(const Complexo& z) {
    //--------
    return z;
}

Complexo log(const Complexo& z) {
    //--------
    return z;
}

// =============================================================================
// 14. OPERADORES DE FLUXO (I/O STREAMS)
// =============================================================================

std::ostream& operator<<(std::ostream& os, const Complexo& c) {
    //--------
    return os;
}

std::istream& operator>>(std::istream& is, Complexo& c) {
    //--------
    return is;
}

// =============================================================================
// 15. LITERAIS DEFINIDOS PELO USUÁRIO
// =============================================================================

Complexo operator""_i(long double imag) {
    //--------
    return Complexo();
}

Complexo operator""_j(long double imag) {
    //--------
    return Complexo();
}

Complexo operator""_i(unsigned long long int imag) {
    //--------
    return Complexo();
}

Complexo operator""_j(unsigned long long int imag) {
    //--------
    return Complexo();
}

double operator""_deg(long double graus) {
    //--------
    return 0.0;
}

double operator""_deg(unsigned long long int graus) {
    //--------
    return 0.0;
}

double operator""_rad(long double rad) {
    //--------
    return 0.0;
}

double operator""_rad(unsigned long long int rad) {
    //--------
    return 0.0;
}