#ifndef _SENSORES_CONCRETOS_HPP_
#define _SENSORES_CONCRETOS_HPP_

#include "Sensor.hpp"

class SensorTemperatura : public Sensor {
public:
    SensorTemperatura(int id, string modelo, double ganho, double offset, double limiarCritico, int janela);
    string getNomeTipo() const override;
    string getUnidade() const override;
    void avaliarAlarme(int idGlobal, int idLocal, double valorConvertido) override;
};

class SensorPressao : public Sensor {
public:
    SensorPressao(int id, string modelo, double ganho, double offset, double limiarCritico, int janela);
    string getNomeTipo() const override;
    string getUnidade() const override;
    void avaliarAlarme(int idGlobal, int idLocal, double valorConvertido) override;
};

class SensorVibracao : public Sensor {
public:
    SensorVibracao(int id, string modelo, double ganho, double offset, double limiarCritico, int janela);
    string getNomeTipo() const override;
    string getUnidade() const override;
    void avaliarAlarme(int idGlobal, int idLocal, double valorConvertido) override;
};

#endif
