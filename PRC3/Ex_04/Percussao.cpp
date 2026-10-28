#include "Percussao.hpp"

Percussao::Percussao(string nome, string instrumento) :
    Musico(nome, instrumento) {
}

char Percussao::getTipo() const {
    return 'P';
}

void Percussao::tocar(const Nota& n) {
    cout << "[Percussao] " << getNome() << " bateu no(a) " << getInstrumento() << " mantendo o ritmo de " << n.getTom() << " (" << n.getDuracao() << " tempos)." << endl;
}