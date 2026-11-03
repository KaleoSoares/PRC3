#ifndef _SUPERVISOR_HPP_
#define _SUPERVISOR_HPP_

#include <string>
#include "ModuloAquisicao.hpp"

using namespace std;

class Supervisor {
private:
    string _nome;
    int _contadorGlobal; // Contador global de medições encapsulado

public:
    Supervisor(string nome);
    string getNome() const;
    int getContadorGlobal() const;
    void iniciarSessao(const string& nomePlanta);
    void processarDado(ModuloAquisicao* modulo, int idSensor, double leituraBruta);
    void emitirRelatorioConsolidado(const string& nomePlanta, const ModuloAquisicao* modulo);
    void auditarSensor(const ModuloAquisicao* modulo, int idConsulta);
    void finalizarSessao(const string& nomePlanta);
};

#endif
