#include "Musica.hpp"

Musica::Musica(string titulo) :
    _titulo(titulo) {
}

void Musica::adicionarNota(string tom, int duracao, string filtro) {
    _partitura.inserir(Nota(tom, duracao, filtro));
}

string Musica::getTitulo() const {
    return _titulo;
}

void Musica::reiniciarPartitura() {
    _partitura.reiniciar();
}

bool Musica::temProximaNota() const {
    return _partitura.temProxima();
}

Nota Musica::proximaNota() {
    return _partitura.proxima();
}
