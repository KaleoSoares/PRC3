# Ex05 - Sistema de Monitoramento, Diagnóstico e Auditoria por Sensores Industriais

## 1. Descrição Geral

Em instalações industriais automatizadas, uma **Unidade de Aquisição de Dados (DAQ)** recebe medições elétricas contínuas provenientes de sensores conectados a um barramento de telemetria. Cada medição é composta pelo identificador numérico do sensor (precedido por `#`) e pelo valor elétrico bruto de tensão.

O sistema deve:
- Processar o fluxo de leituras até o final do arquivo (`EOF`);
- Atualizar históricos encadeados de cada sensor;
- Emitir alertas imediatos de segurança conforme limiares críticos;
- Consolidar relatórios estatísticos ao final da execução;
- Realizar a auditoria sob demanda de um sensor selecionado.

---

## 2. Requisitos de Implementação

### 2.1. Precisão Numérica e Saída
- Todas as grandezas em ponto flutuante devem ser manipuladas utilizando o tipo `double`.
- As saídas numéricas devem ser formatadas com exatamente **duas casas decimais**, utilizando:
  ```cpp
  std::fixed << std::setprecision(2)
  ```

### 2.2. Unidades Físicas
Para evitar incompatibilidades de codificação, utilize estritamente caracteres ASCII padrão:
- **Temperatura:** `C`
- **Pressão:** `bar`
- **Vibração:** `mm/s`

### 2.3. Encapsulamento Estrito e Gestão de Memória
- **Proibido o uso da STL:** Não utilize contêineres padrão (como `std::vector`, `std::list`, etc.) para armazenar sensores ou medições.
- **Estruturas Dinâmicas Próprias:**
  - A coleção de sensores deve ser gerenciada exclusivamente pela lista encadeada dinâmica `ListaSensores` (composta internamente pelo `ModuloAquisicao`).
  - As medições de cada sensor devem ser mantidas pela sua respectiva lista encadeada `ListaMedidas`.
- **Contador Global Cronológico:** Deve ser encapsulado dentro da classe `Supervisor` (sem variáveis globais soltas na função `main`).
- **Ciclo de Vida / Desalocação:** Toda liberação de memória dinâmica (`delete`) deve ocorrer nos destrutores das classes proprietárias (`RAII`). Nenhuma desalocação manual deve ser realizada na função `main`.

### 2.4. Polimorfismo e Busca Encadeada
- **Hierarquia:** Classe base abstrata `Sensor` contendo métodos virtuais puros implementados em subclasses especializadas:
  - `SensorTemperatura`
  - `SensorPressao`
  - `SensorVibracao`
- **Busca:** A classe `ListaSensores` deve implementar o método `buscarPorId(int id)` para localizar o sensor cadastrado pelo seu identificador inteiro.

---

## 3. Modelagem Matemática

### 3.1. Calibração (Conversão Linear)
Conversão do sinal elétrico bruto para a grandeza física correspondente:

$$y = a \cdot x + b$$

Onde:
- $x$: leitura bruta de tensão.
- $a$: ganho (fator de calibração).
- $b$: deslocamento (*offset*).

---

### 3.2. Estatística Descritiva (Cálculo Manual sobre Listas)

Para um conjunto de $N$ amostras registradas:

* **Mínimo e Máximo:**
  $$\min(x_1, \dots, x_N) \quad \text{e} \quad \max(x_1, \dots, x_N)$$

* **Média Aritmética Simples:**
  $$\mu = \frac{1}{N} \sum_{i=1}^{N} x_i$$

* **Valor Médio Quadrático (*Root Mean Square* - RMS):**
  $$X_{\text{RMS}} = \sqrt{\frac{1}{N} \sum_{i=1}^{N} x_i^2}$$

* **Desvio Padrão Populacional:**
  $$\sigma = \sqrt{\frac{1}{N} \sum_{i=1}^{N} (x_i - \mu)^2}$$

* **Média Móvel ($MM_k$) das últimas $k$ amostras:**
  $$MM_k = \frac{1}{m} \sum_{i=N-m+1}^{N} x_i \quad \text{onde } m = \min(N, k)$$

---

## 4. Formato de Entrada

1. **Consulta de Auditoria:**
   - `idConsulta` (`char '#'` seguido de `int`): Identificador do sensor a ser auditado ao final (ex.: `#2`).
2. **Dados da Planta:**
   - `nomePlanta` (`string`): Nome da unidade industrial.
   - `nomeSupervisor` (`string`): Nome do engenheiro supervisor.
   - `qtdSensores` (`int`): Quantidade $N \ge 1$ de sensores cadastrados.
3. **Cadastro dos Sensores ($N$ linhas):**
   - `tipo` (`char`): `'T'` (Temperatura), `'P'` (Pressão) ou `'V'` (Vibração).
   - `id` (`char '#'` seguido de `int`): Identificador do sensor (armazenado internamente como `int`).
   - `modelo` (`string`): Código comercial do modelo.
   - `ganho` (`double`): Constante $a$.
   - `offset` (`double`): Constante $b$.
   - `limiarCritico` (`double`): Limite de disparo de alarme.
   - `janela` (`int`): Tamanho da janela da média móvel ($k \ge 1$).
4. **Fluxo Contínuo de Medições (até `EOF`):**
   - Linhas compostas por: `idSensor` (formato `#{id}`) e `leituraBruta` (`double`).

---

## 5. Regras de Auditoria sob Demanda

Ao término do processamento:
- **Sensor encontrado com medições:**
  Imprime a lista cronológica das medições:
  ```text
  [Amostra Local #X | Global #Y]: <valor> <unidade>
  ```
- **Sensor encontrado, sem medições:**
  Imprime:
  ```text
  Nenhuma medida registrada para este sensor.
  ```
  *(Nota: no relatório consolidado, todos os parâmetros estatísticos deste sensor devem assumir `0.00`).*
- **Sensor não encontrado:**
  Caso `idConsulta` não exista na lista:
  ```text
  Sensor #<id> não encontrado no sistema.
  ```

---

## 6. Exemplo de Entrada e Saída

### 6.1. Entrada
```text
#2
RefinariaABC EngWilliam 3
T #1 PT100 10.0 0.0 80.0 2
T #2 NTC10k 5.0 10.0 50.0 2
P #3 MPX 2.0 0.0 10.0 3
#1 7.5
#3 4.0
#2 9.0
#1 8.5
#3 6.0
#2 4.0
```

### 6.2. Saída Esperada
```text
Supervisor EngWilliam inicia monitoramento da planta RefinariaABC!
[Temperatura] Sensor #1 (PT100) [Global: #1 | Local: #1]: 75.00 C | STATUS: OPERAÇÃO NOMINAL
[Pressão] Sensor #3 (MPX) [Global: #2 | Local: #1]: 8.00 bar | STATUS: OPERAÇÃO NOMINAL
[Temperatura] Sensor #2 (NTC10k) [Global: #3 | Local: #1]: 55.00 C | ALERTA: SOBRETEMPERATURA CRÍTICA
[Temperatura] Sensor #1 (PT100) [Global: #4 | Local: #2]: 85.00 C | ALERTA: SOBRETEMPERATURA CRÍTICA
[Pressão] Sensor #3 (MPX) [Global: #5 | Local: #2]: 12.00 bar | ALERTA: SOBREPRESSÃO DETECTADA
[Temperatura] Sensor #2 (NTC10k) [Global: #6 | Local: #2]: 30.00 C | STATUS: OPERAÇÃO NOMINAL
========================================
RELATÓRIO ESTATÍSTICO CONSOLIDADO
Planta: RefinariaABC | Supervisor: EngWilliam
========================================
[Temperatura] Sensor: #1 (PT100)
Total de Amostras: 2
Mínimo: 75.00 C
Máximo: 85.00 C
Média: 80.00 C
RMS: 80.16 C
Desvio Padrão: 5.00 C
Média Móvel (#2): 80.00 C
----------------------------------------
[Temperatura] Sensor: #2 (NTC10k)
Total de Amostras: 2
Mínimo: 30.00 C
Máximo: 55.00 C
Média: 42.50 C
RMS: 44.30 C
Desvio Padrão: 12.50 C
Média Móvel (#2): 42.50 C
----------------------------------------
[Pressão] Sensor: #3 (MPX)
Total de Amostras: 2
Mínimo: 8.00 bar
Máximo: 12.00 bar
Média: 10.00 bar
RMS: 10.20 bar
Desvio Padrão: 2.00 bar
Média Móvel (#3): 10.00 bar
----------------------------------------
========================================
HISTÓRICO DE MEDIDAS DO SENSOR #2
========================================
[Amostra Local #1 | Global #3]: 55.00 C
[Amostra Local #2 | Global #6]: 30.00 C
========================================
Encerramento do monitoramento da planta RefinariaABC.
```