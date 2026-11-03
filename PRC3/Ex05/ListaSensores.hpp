#ifndef _LISTA_SENSORES_HPP_
#define _LISTA_SENSORES_HPP_

#include "Sensor.hpp"

class NoSensor {
private:
    Sensor* _sensor;
    NoSensor* _prox;

    NoSensor(Sensor* s);
    friend class ListaSensores;
};

class ListaSensores {
private:
    NoSensor* _inicio;
    NoSensor* _fim;
    int _tamanho;

public:
    ListaSensores();
    ~ListaSensores();

    void inserir(Sensor* s);
    Sensor* buscarPorId(int id) const;
    int getTamanho() const;
    void imprimirRelatorios() const;
};

#endif
