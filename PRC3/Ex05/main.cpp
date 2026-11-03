#include <iostream>
#include <string>
#include "Sensor.hpp"
#include "SensoresConcretos.hpp"
#include "ModuloAquisicao.hpp"
#include "Supervisor.hpp"

using namespace std;

int main() {
    // =========================================================================
    // ROTEIRO DE IMPLEMENTAÇÃO DO FLUXO PRINCIPAL:
    // =========================================================================
    // Passo 1: Realizar a leitura do identificador do sensor de consulta (#idConsulta).
    //
    // Passo 2: Ler os dados cadastrais da planta:
    //          - nomePlanta (string)
    //          - nomeSupervisor (string)
    //          - qtdSensores (int)
    //
    // Passo 3: Instanciar o Supervisor e o ModuloAquisicao.
    //
    // Passo 4: Realizar o cadastro dos N sensores em um laço:
    //          - Ler: tipo, '#', id, modelo, ganho, offset, limiarCritico, janela.
    //          - Instanciar dinamicamente o sensor correspondente (Temperatura, Pressão ou Vibração).
    //          - Adicionar o ponteiro diretamente no ModuloAquisicao (NÃO utilizar vetores/arrays).
    //
    // Passo 5: Iniciar a sessão de monitoramento através do Supervisor.
    //
    // Passo 6: Executar a leitura contínua das medições até o final do arquivo (EOF):
    //          - Ler cada amostra ('#', idSensor, leituraBruta).
    //          - Repassar a leitura diretamente ao Supervisor, que gerencia o contador
    //            global incrementalmente de forma encapsulada (sem variável solta na main).
    //
    // Passo 7: Finalizado o fluxo de medições (EOF):
    //          - Comandar a emissão do Relatório Estatístico Consolidado via Supervisor.
    //          - Comandar a Auditoria do sensor de consulta (#idConsulta) via Supervisor.
    //          - Comandar o Encerramento da Sessão pelo Supervisor.
    //
    // Passo 8: Finalizar o programa. Toda a memória dinâmica alocada para os sensores
    //          é liberada automaticamente pelo destrutor do ModuloAquisicao / ListaSensores.
    // =========================================================================

    return 0;
}
