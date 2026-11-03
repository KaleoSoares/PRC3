#include "Supervisor.hpp"
#include <iostream>

using namespace std;

Supervisor::Supervisor(string nome) :
    _nome(nome),
    _contadorGlobal(0) {
}

string Supervisor::getNome() const {
    return _nome;
}

int Supervisor::getContadorGlobal() const {
    return _contadorGlobal;
}

void Supervisor::iniciarSessao(const string& nomePlanta) {
    cout << "Supervisor " << _nome << " inicia monitoramento da planta " << nomePlanta << "!" << endl;
}

void Supervisor::processarDado(ModuloAquisicao* modulo, int idSensor, double leituraBruta) {
    _contadorGlobal++;
    modulo->registrarMedicao(_contadorGlobal, idSensor, leituraBruta);
}

void Supervisor::emitirRelatorioConsolidado(const string& nomePlanta, const ModuloAquisicao* modulo) {
    cout << "========================================" << endl;
    cout << "RELATÓRIO ESTATÍSTICO CONSOLIDADO" << endl;
    cout << "Planta: " << nomePlanta << " | Supervisor: " << _nome << endl;
    cout << "========================================" << endl;
    modulo->imprimirTodosRelatorios();
}

void Supervisor::auditarSensor(const ModuloAquisicao* modulo, int idConsulta) {
    cout << "========================================" << endl;
    cout << "HISTÓRICO DE MEDIDAS DO SENSOR #" << idConsulta << endl;
    cout << "========================================" << endl;
    if (!modulo->auditarSensor(idConsulta)) {
        cout << "Sensor #" << idConsulta << " não encontrado no sistema." << endl;
    }
    cout << "========================================" << endl;
}

void Supervisor::finalizarSessao(const string& nomePlanta) {
    cout << "Encerramento do monitoramento da planta " << nomePlanta << "." << endl;
}
