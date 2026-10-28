#ifndef _CLASS_PROFESSOR_
#define _CLASS_PROFESSOR_

#include <iostream>
#include "Pessoa.hpp"

using namespace std;

class Professor: public Pessoa {
    private:
        string _prontuario;
        string _senha;
        float salario;
    public:
        Professor(string nome, int idade, string prontuario, string senha, float salario);
        void estudar(string materia);
        void fazerProva(void);
        string getSenha(void);
        void setSenha(string senha);
        string getProntuario(void);
        float getSalario(void);
        void setSalario(float salario);
        void apresentar(string cumprimento) override;
};

#endif