#include "ModuloAquisicao.hpp"

ModuloAquisicao::ModuloAquisicao() {
}

ModuloAquisicao::~ModuloAquisicao() {
}

void ModuloAquisicao::adicionarSensor(Sensor* s) {
    _sensores.inserir(s);
}

bool ModuloAquisicao::registrarMedicao(int idGlobal, int idSensor, double leituraBruta) {
    Sensor* s = _sensores.buscarPorId(idSensor);
    if (s != nullptr) {
        s->registrarMedicao(idGlobal, leituraBruta);
        return true;
    }
    return false;
}

bool ModuloAquisicao::auditarSensor(int idSensor) const {
    Sensor* s = _sensores.buscarPorId(idSensor);
    if (s != nullptr) {
        s->imprimirHistoricoDetalhado();
        return true;
    }
    return false;
}

void ModuloAquisicao::imprimirTodosRelatorios() const {
    _sensores.imprimirRelatorios();
}
