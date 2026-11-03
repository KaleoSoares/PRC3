#include "SensoresConcretos.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

SensorTemperatura::SensorTemperatura(int id, string modelo, double ganho, double offset, double limiarCritico, int janela) :
    Sensor(id, modelo, ganho, offset, limiarCritico, janela) {
}

string SensorTemperatura::getNomeTipo() const {
    return "Temperatura";
}

string SensorTemperatura::getUnidade() const {
    return "C";
}

void SensorTemperatura::avaliarAlarme(int idGlobal, int idLocal, double valorConvertido) {
    cout << fixed << setprecision(2);
    cout << "[Temperatura] Sensor #" << getId() << " (" << getModelo() << ") [Global: #" << idGlobal
         << " | Local: #" << idLocal << "]: " << valorConvertido << " C | ";
    if (valorConvertido > getLimiarCritico()) {
        cout << "ALERTA: SOBRETEMPERATURA CRÍTICA" << endl;
    } else {
        cout << "STATUS: OPERAÇÃO NOMINAL" << endl;
    }
}

SensorPressao::SensorPressao(int id, string modelo, double ganho, double offset, double limiarCritico, int janela) :
    Sensor(id, modelo, ganho, offset, limiarCritico, janela) {
}

string SensorPressao::getNomeTipo() const {
    return "Pressão";
}

string SensorPressao::getUnidade() const {
    return "bar";
}

void SensorPressao::avaliarAlarme(int idGlobal, int idLocal, double valorConvertido) {
    cout << fixed << setprecision(2);
    cout << "[Pressão] Sensor #" << getId() << " (" << getModelo() << ") [Global: #" << idGlobal
         << " | Local: #" << idLocal << "]: " << valorConvertido << " bar | ";
    if (valorConvertido > getLimiarCritico()) {
        cout << "ALERTA: SOBREPRESSÃO DETECTADA" << endl;
    } else {
        cout << "STATUS: OPERAÇÃO NOMINAL" << endl;
    }
}

SensorVibracao::SensorVibracao(int id, string modelo, double ganho, double offset, double limiarCritico, int janela) :
    Sensor(id, modelo, ganho, offset, limiarCritico, janela) {
}

string SensorVibracao::getNomeTipo() const {
    return "Vibração";
}

string SensorVibracao::getUnidade() const {
    return "mm/s";
}

void SensorVibracao::avaliarAlarme(int idGlobal, int idLocal, double valorConvertido) {
    cout << fixed << setprecision(2);
    cout << "[Vibração] Sensor #" << getId() << " (" << getModelo() << ") [Global: #" << idGlobal
         << " | Local: #" << idLocal << "]: " << valorConvertido << " mm/s | ";
    if (valorConvertido > getLimiarCritico()) {
        cout << "ALERTA: FALHA DE BALANCEAMENTO ESTRUTURAL" << endl;
    } else {
        cout << "STATUS: OPERAÇÃO NOMINAL" << endl;
    }
}
