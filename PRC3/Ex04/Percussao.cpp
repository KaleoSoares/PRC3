#include "Percussao.hpp"

Percussao::Percussao(string nome, string instrumento) :
    Musico(nome, instrumento) {
}

char Musico::getTipo() const {
    return 'P';
}

void Musico::tocar(const Nota& n) {
    cout << "[Percussao] " << getNome() << " bateu no(a) " << getInstrumento() << " mantendo o ritmo de " << n.getTom() << "(" << n.getDuracao() << " tempos)." << endl;
}