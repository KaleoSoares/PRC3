#include <iostream>
#include <string>
#include "Nota.hpp"
#include "Musica.hpp"
#include "Cordas.hpp"
#include "Sopro.hpp"
#include "Percussao.hpp"
#include "Banda.hpp"
#include "Maestro.hpp"

using namespace std;

int main() {
    string nomeBanda, nomeMaestro, nomeMusica;
    cin >> nomeBanda >> nomeMaestro >> nomeMusica;

    Banda banda(nomeBanda);
    Maestro maestro(nomeMaestro);
    Musica musica(nomeMusica);

    int qtdMusicos;
    cin >> qtdMusicos;
    for (int i = 0; i < qtdMusicos; i++) {
        char tipo;
        string nome, instrumento;
        cin >> tipo >> nome >> instrumento;
        if (tipo == 'C') {
            banda.adicionarMusico(new Cordas(nome, instrumento));
        } else if (tipo == 'S') {
            banda.adicionarMusico(new Sopro(nome, instrumento));
        } else if (tipo == 'P') {
            banda.adicionarMusico(new Percussao(nome, instrumento));
        }
    }

    int qtdNotas;
    cin >> qtdNotas;
    for (int i = 0; i < qtdNotas; i++) {
        string tom;
        int duracao;
        string filtro;
        cin >> tom >> duracao >> filtro;
        musica.adicionarNota(tom, duracao, filtro);
    }

    maestro.reger(&banda, &musica);

    return 0;
}