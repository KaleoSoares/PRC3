#include "ListaMedidas.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

NoMedida::NoMedida(int idGlobal, int idLocal, double v) :
    _idGlobal(idGlobal),
    _idLocal(idLocal),
    _valor(v),
    _prox(nullptr) {
}

ListaMedidas::ListaMedidas() :
    _inicio(nullptr),
    _fim(nullptr),
    _tamanho(0) {
}

ListaMedidas::~ListaMedidas() {
    NoMedida* atual = _inicio;
    while (atual != nullptr) {
        NoMedida* prox = atual->_prox;
        delete atual;
        atual = prox;
    }
}

int ListaMedidas::inserir(int idGlobal, double valor) {
    _tamanho++;
    NoMedida* novo = new NoMedida(idGlobal, _tamanho, valor);
    if (_inicio == nullptr) {
        _inicio = novo;
        _fim = novo;
    } else {
        _fim->_prox = novo;
        _fim = novo;
    }
    return _tamanho;
}

int ListaMedidas::getTamanho() const {
    return _tamanho;
}

double ListaMedidas::minimo() const {
    if (_tamanho == 0) return 0.0;
    double min = _inicio->_valor;
    NoMedida* atual = _inicio->_prox;
    while (atual != nullptr) {
        if (atual->_valor < min) {
            min = atual->_valor;
        }
        atual = atual->_prox;
    }
    return min;
}

double ListaMedidas::maximo() const {
    if (_tamanho == 0) return 0.0;
    double max = _inicio->_valor;
    NoMedida* atual = _inicio->_prox;
    while (atual != nullptr) {
        if (atual->_valor > max) {
            max = atual->_valor;
        }
        atual = atual->_prox;
    }
    return max;
}

double ListaMedidas::media() const {
    if (_tamanho == 0) return 0.0;
    double soma = 0.0;
    NoMedida* atual = _inicio;
    while (atual != nullptr) {
        soma += atual->_valor;
        atual = atual->_prox;
    }
    return soma / _tamanho;
}

double ListaMedidas::rms() const {
    if (_tamanho == 0) return 0.0;
    double soma = 0.0;
    NoMedida* atual = _inicio;
    while (atual != nullptr) {
        soma += atual->_valor * atual->_valor;
        atual = atual->_prox;
    }
    return sqrt(soma / _tamanho);
}

double ListaMedidas::desvioPadrao() const {
    if (_tamanho == 0) return 0.0;
    double m = media();
    double soma = 0.0;
    NoMedida* atual = _inicio;
    while (atual != nullptr) {
        soma += (atual->_valor - m) * (atual->_valor - m);
        atual = atual->_prox;
    }
    return sqrt(soma / _tamanho);
}

double ListaMedidas::mediaMovel(int janela) const {
    if (_tamanho == 0 || janela <= 0) return 0.0;
    int m = (_tamanho < janela) ? _tamanho : janela;
    int pular = _tamanho - m;

    NoMedida* atual = _inicio;
    for (int i = 0; i < pular && atual != nullptr; i++) {
        atual = atual->_prox;
    }

    double soma = 0.0;
    while (atual != nullptr) {
        soma += atual->_valor;
        atual = atual->_prox;
    }
    return soma / m;
}

void ListaMedidas::imprimirHistorico(const string& unidade) const {
    NoMedida* atual = _inicio;
    while (atual != nullptr) {
        cout << "[Amostra Local #" << atual->_idLocal
             << " | Global #" << atual->_idGlobal << "]: "
             << fixed << setprecision(2) << atual->_valor << " " << unidade << endl;
        atual = atual->_prox;
    }
}
