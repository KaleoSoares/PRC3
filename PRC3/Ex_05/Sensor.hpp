#ifndef _SENSOR_HPP_
#define _SENSOR_HPP_

#include <iostream>
#include <string>
#include <iomanip>
#include "ListaMedidas.hpp"

using namespace std;

class Sensor {
private:
    int _id;
    string _modelo;
    double _ganho;
    double _offset;
    double _limiarCritico;
    int _janela;
    ListaMedidas _historico; // Composição da lista dinâmica de medidas

public:
    Sensor(int id, string modelo, double ganho, double offset, double limiarCritico, int janela);
    virtual ~Sensor() {}

    int getId() const;
    string getModelo() const;
    double getGanho() const;
    double getOffset() const;
    double getLimiarCritico() const;
    int getJanela() const;

    double converterSinal(double leituraBruta) const;
    void registrarMedicao(int idGlobal, double leituraBruta);
    void imprimirRelatorio() const;
    void imprimirHistoricoDetalhado() const;

    virtual string getNomeTipo() const = 0;
    virtual string getUnidade() const = 0;
    virtual void avaliarAlarme(int idGlobal, int idLocal, double valorConvertido) = 0;
};

#endif
