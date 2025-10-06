# 💻 Implementação de Estruturas de Fila e Simulação de Round Robin em C++

Este projeto em C++ implementa diferentes tipos de estruturas de fila e simula um algoritmo de escalonamento de processos (Round Robin).

## 📄 Atividade

A atividade consiste em desenvolver, utilizando a linguagem C++, as seguintes estruturas de dados e simulações, baseadas no conceito de filas:

1.  **Fila Simples (Queue):** Estrutura FIFO (First-In, First-Out).
2.  **Fila de Prioridade (Priority Queue):** Estrutura onde o elemento removido é sempre o de maior prioridade (neste caso, o maior valor).
3.  **Teste de Prioridades:** Demonstração da Fila de Prioridade com grupos de valores (Alta, Média e Baixa).
4.  **Simulação Round Robin:** Implementação do algoritmo de escalonamento de processos usando uma fila simples para gerenciar a execução em *quantum* de tempo.

---

## 1. Fila Simples (Queue)

Implementação de uma fila tradicional que segue a regra **FIFO** (Primeiro a Entrar, Primeiro a Sair).

### **Execução:**

<img width="638" height="184" alt="Captura de tela 2025-10-06 124754" src="https://github.com/user-attachments/assets/152a15b1-a787-4ab7-bfcc-51a4a7af9fa0" />

---

## 2. Fila de Prioridade (Priority Queue)

Implementação de uma fila onde a remoção (dequeue) sempre seleciona o elemento com a **maior prioridade** (o maior valor numérico) da fila.

### **Execução:**

<img width="644" height="235" alt="Captura de tela 2025-10-06 124759" src="https://github.com/user-attachments/assets/9b62ffe1-3f38-4624-865d-fcb035142ac0" />

---

## 3. Teste de Prioridades (Alta, Média, Baixa)

Teste que demonstra a funcionalidade da Fila de Prioridade ao enfileirar valores de três faixas distintas (100-96, 50-46, 10-6) e garantir que a remoção ocorra do maior para o menor.

### **Execução:**

<img width="649" height="801" alt="Captura de tela 2025-10-06 124815" src="https://github.com/user-attachments/assets/2faa076e-2051-4f7d-9a37-f16e03254f09" />

---

## 4. Simulação Round Robin

Implementação do algoritmo de escalonamento de processos **Round Robin** utilizando uma fila circular implícita (aqui, uma fila simples) e um **quantum** de tempo (`quantum = 2`).

O processo é:
1.  Um processo é retirado da fila.
2.  É executado por um tempo igual ao *quantum* (ou o tempo restante, se for menor).
3.  Se o processo ainda não terminou, ele é **re-enfileirado** no final da fila para aguardar sua próxima vez.

### **Execução:**

<img width="573" height="340" alt="Captura de tela 2025-10-06 124823" src="https://github.com/user-attachments/assets/5105d249-403d-4226-895a-d77d20b1ae04" />
