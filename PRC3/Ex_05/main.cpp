#include <iostream>
#include <string>
#include "Sensor.hpp"
#include "SensoresConcretos.hpp"
#include "ModuloAquisicao.hpp"
#include "Supervisor.hpp"

using namespace std;

int main() {
    char hash;
    int idConsulta;
    cin >> hash >> idConsulta;

    string nomePlanta, nomeSupervisor;
    int qtdSensores;
    cin >> nomePlanta >> nomeSupervisor >> qtdSensores;

    Supervisor supervisor(nomeSupervisor);
    ModuloAquisicao modulo;

    for (int i = 0; i < qtdSensores; i++) {
        char tipo, h;
        int id, janela;
        string modelo;
        double ganho, offset, limiarCritico;

        cin >> tipo >> h >> id >> modelo >> ganho >> offset >> limiarCritico >> janela;

        if (tipo == 'T') {
            modulo.adicionarSensor(new SensorTemperatura(id, modelo, ganho, offset, limiarCritico, janela));
        } else if (tipo == 'P') {
            modulo.adicionarSensor(new SensorPressao(id, modelo, ganho, offset, limiarCritico, janela));
        } else if (tipo == 'V') {
            modulo.adicionarSensor(new SensorVibracao(id, modelo, ganho, offset, limiarCritico, janela));
        }
    }

    supervisor.iniciarSessao(nomePlanta);

    int idSensor;
    double leituraBruta;
    while (cin >> hash >> idSensor >> leituraBruta) {
        supervisor.processarDado(&modulo, idSensor, leituraBruta);
    }

    supervisor.emitirRelatorioConsolidado(nomePlanta, &modulo);
    supervisor.auditarSensor(&modulo, idConsulta);
    supervisor.finalizarSessao(nomePlanta);

    return 0;
}
