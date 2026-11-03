#ifndef _MODULO_AQUISICAO_HPP_
#define _MODULO_AQUISICAO_HPP_

#include "ListaSensores.hpp"

class ModuloAquisicao {
private:
    ListaSensores _sensores; // Composição da lista dinâmica de sensores

public:
    ModuloAquisicao();
    ~ModuloAquisicao();

    void adicionarSensor(Sensor* s);
    bool registrarMedicao(int idGlobal, int idSensor, double leituraBruta);
    bool auditarSensor(int idSensor) const;
    void imprimirTodosRelatorios() const;
};

#endif
