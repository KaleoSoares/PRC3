#include "Sensor.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Sensor::Sensor(int id, string modelo, double ganho, double offset, double limiarCritico, int janela) :
    _id(id),
    _modelo(modelo),
    _ganho(ganho),
    _offset(offset),
    _limiarCritico(limiarCritico),
    _janela(janela) {
}

int Sensor::getId() const {
    return _id;
}

string Sensor::getModelo() const {
    return _modelo;
}

double Sensor::getGanho() const {
    return _ganho;
}

double Sensor::getOffset() const {
    return _offset;
}

double Sensor::getLimiarCritico() const {
    return _limiarCritico;
}

int Sensor::getJanela() const {
    return _janela;
}

double Sensor::converterSinal(double leituraBruta) const {
    return _ganho * leituraBruta + _offset;
}

void Sensor::registrarMedicao(int idGlobal, double leituraBruta) {
    double valorConvertido = converterSinal(leituraBruta);
    int idLocal = _historico.inserir(idGlobal, valorConvertido);
    avaliarAlarme(idGlobal, idLocal, valorConvertido);
}

void Sensor::imprimirRelatorio() const {
    cout << "[" << getNomeTipo() << "] Sensor: #" << _id << " (" << _modelo << ")" << endl;
    cout << "Total de Amostras: " << _historico.getTamanho() << endl;
    cout << fixed << setprecision(2);
    cout << "Mínimo: " << _historico.minimo() << " " << getUnidade() << endl;
    cout << "Máximo: " << _historico.maximo() << " " << getUnidade() << endl;
    cout << "Média: " << _historico.media() << " " << getUnidade() << endl;
    cout << "RMS: " << _historico.rms() << " " << getUnidade() << endl;
    cout << "Desvio Padrão: " << _historico.desvioPadrao() << " " << getUnidade() << endl;
    cout << "Média Móvel (#" << _janela << "): " << _historico.mediaMovel(_janela) << " " << getUnidade() << endl;
    cout << "----------------------------------------" << endl;
}

void Sensor::imprimirHistoricoDetalhado() const {
    if (_historico.getTamanho() == 0) {
        cout << "Nenhuma medida registrada para este sensor." << endl;
    } else {
        _historico.imprimirHistorico(getUnidade());
    }
}
