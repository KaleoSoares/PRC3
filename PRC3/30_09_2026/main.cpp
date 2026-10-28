#include <iostream>
#include "Pessoa.hpp"
#include "Aluno.hpp"

int main() {
    cout << "p1" << endl;
    Pessoa p1("William", 40);
    p1.apresentar("Oi ");
    
    cout << "p2" << endl;
    Pessoa p2("Vinicius", 10);
    p2.apresentar("Hello ");

    cout << "p3" << endl;
    Pessoa p3 = p1;
    p3.apresentar("Konichiwa ");

    cout << "p4" << endl;
    Pessoa p4 = p2;
    p4.apresentar("Bonjour ");

    cout << "p_p1" << endl;
    Pessoa* p_p1 = &p1;
    p_p1->apresentar("Hola ");

    cout << "p_p2" << endl;
    Pessoa* p_p2 = &p2;
    p_p2->apresentar("Hallo ");

    cout << "p_new1" << endl;
    Pessoa* p_new1 = new Pessoa("Miguelito1", 6);
    p_new1->apresentar("Bom ");

    cout << "p_new2" << endl;
    Pessoa* p_new2 = p_new1;
    p_new2->apresentar("Opa ");

    cout << "p_new1 (after reassignment)" << endl;
    p_new1 = new Pessoa("Miguelito2", 6);
    p_new1->apresentar("Iai ");

    delete p_new2;
    delete p_new1;

    //p_new1->apresentar("Oi de novo ");
    //p_new2->apresentar("Hello de novo ");

    Aluno* aluno1 = new Aluno("Kaleo", 22, "HT666999", "USUHAQUI01", 999);
    aluno1->apresentar("Oi ");
    /* aluno1->estudar("Programacao");
    aluno1->fazerProva();
    string s = aluno1->getSenha() + "naodurmo";
    cout << aluno1->getSenha() << endl;
    cout << "Prontuario: " << aluno1->getProntuario() << endl;
    cout << "IRA: " << aluno1->getIra() << endl;
    aluno1->setIra(666);
    cout << "IRA novo: " << aluno1->getIra() << endl; */

    Pessoa vpessoa = *aluno1;
    vpessoa.apresentar("Oi de novo ");

    Pessoa* ppessoa = aluno1;
    ppessoa->apresentar("Hello de novo ");

    return 0;
}