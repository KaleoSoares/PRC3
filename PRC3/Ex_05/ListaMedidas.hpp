#ifndef _LISTA_MEDIDAS_HPP_
#define _LISTA_MEDIDAS_HPP_

#include <string>

using namespace std;

class NoMedida {
private:
    int _idGlobal;
    int _idLocal;
    double _valor;
    NoMedida* _prox;

    NoMedida(int idGlobal, int idLocal, double v);
    friend class ListaMedidas;
};

class ListaMedidas {
private:
    NoMedida* _inicio;
    NoMedida* _fim;
    int _tamanho;

public:
    ListaMedidas();
    ~ListaMedidas();

    int inserir(int idGlobal, double valor);
    int getTamanho() const;

    double minimo() const;
    double maximo() const;
    double media() const;
    double rms() const;
    double desvioPadrao() const;
    double mediaMovel(int janela) const;
    void imprimirHistorico(const string& unidade) const;
};

#endif
