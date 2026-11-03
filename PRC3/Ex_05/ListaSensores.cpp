#include "ListaSensores.hpp"
#include <iostream>

using namespace std;

NoSensor::NoSensor(Sensor* s) :
    _sensor(s),
    _prox(nullptr) {
}

ListaSensores::ListaSensores() :
    _inicio(nullptr),
    _fim(nullptr),
    _tamanho(0) {
}

ListaSensores::~ListaSensores() {
    NoSensor* atual = _inicio;
    while (atual != nullptr) {
        NoSensor* prox = atual->_prox;
        delete atual->_sensor;
        delete atual;
        atual = prox;
    }
}

void ListaSensores::inserir(Sensor* s) {
    NoSensor* novo = new NoSensor(s);
    if (_inicio == nullptr) {
        _inicio = novo;
        _fim = novo;
    } else {
        _fim->_prox = novo;
        _fim = novo;
    }
    _tamanho++;
}

Sensor* ListaSensores::buscarPorId(int id) const {
    NoSensor* atual = _inicio;
    while (atual != nullptr) {
        if (atual->_sensor->getId() == id) {
            return atual->_sensor;
        }
        atual = atual->_prox;
    }
    return nullptr;
}

int ListaSensores::getTamanho() const {
    return _tamanho;
}

void ListaSensores::imprimirRelatorios() const {
    NoSensor* atual = _inicio;
    while (atual != nullptr) {
        atual->_sensor->imprimirRelatorio();
        atual = atual->_prox;
    }
}
