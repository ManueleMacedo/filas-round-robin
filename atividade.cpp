#include <iostream>
using namespace std;

/*1 - Implementação de Fila Simples (Queue) */
#define MAX 15

class Queue {
    int items[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Fila cheia!\n";
            return;
        }
        if (front == -1) front = 0;
        items[++rear] = value;
        cout << value << " inserido na fila\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Fila vazia!\n";
            return -1;
        }
        cout << items[front] << " removido da fila\n";
        return items[front++];
    }
};

/* 2 - Fila de Prioridade (Priority Queue)*/
class PriorityQueue {
    int items[MAX];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void enqueue(int value) {
        if (size == MAX) {
            cout << "Fila cheia!\n";
            return;
        }
        items[size++] = value;
        cout << value << " inserido\n";
    }

    int dequeue() {
        if (size == 0) {
            cout << "Fila vazia!\n";
            return -1;
        }
        int highest = 0;
        for (int i = 1; i < size; i++) {
            if (items[i] > items[highest]) {
                highest = i;
            }
        }
        int value = items[highest];
        for (int i = highest; i < size - 1; i++) {
            items[i] = items[i + 1];
        }
        size--;
        cout << value << " removido (maior prioridade)\n";
        return value;
    }

    bool isEmpty() {
        return size == 0;
    }
};

/* 3 - Teste com Prioridades Alta, Média e Baixa */
void testePrioridades() {
    PriorityQueue pq;

    // Alta prioridade
    pq.enqueue(100);
    pq.enqueue(99);
    pq.enqueue(98);
    pq.enqueue(97);
    pq.enqueue(96);

    // Média
    pq.enqueue(50);
    pq.enqueue(49);
    pq.enqueue(48);
    pq.enqueue(47);
    pq.enqueue(46);

    // Baixa
    pq.enqueue(10);
    pq.enqueue(9);
    pq.enqueue(8);
    pq.enqueue(7);
    pq.enqueue(6);

    cout << "\nRemovendo em ordem de prioridade:\n";
    while (!pq.isEmpty()) {
        pq.dequeue();
    }
    cout << "\n";
}

/* 4 - Simulação Round Robin */
struct Processo {
    string id;
    int tempo;
};

class ProcessoQueue {
    Processo items[MAX];
    int front, rear;

public:
    ProcessoQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(Processo p) {
        if (rear == MAX - 1) return;
        if (front == -1) front = 0;
        items[++rear] = p;
    }

    Processo dequeue() {
        return items[front++];
    }
};

void roundRobin() {
    ProcessoQueue fila;
    int quantum = 2;

    Processo p1 = {"P1", 5};
    Processo p2 = {"P2", 7};
    Processo p3 = {"P3", 3};

    fila.enqueue(p1);
    fila.enqueue(p2);
    fila.enqueue(p3);

    cout << "\n=== Simulacao Round Robin ===\n";
    while (!fila.isEmpty()) {
        Processo atual = fila.dequeue();

        int exec = (atual.tempo > quantum) ? quantum : atual.tempo;
        atual.tempo -= exec;

        cout << atual.id << " executou " << exec
             << " unidades (restam " << atual.tempo << ")\n";

        if (atual.tempo > 0) {
            fila.enqueue(atual);
        }
    }

    cout << "Todos os processos foram concluidos!\n";
}

/* MAIN */

int main() {
    cout << "=== TESTE 1: FILA SIMPLES ===\n";
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << "\n=== TESTE 2: FILA DE PRIORIDADE ===\n";
    PriorityQueue pq;
    pq.enqueue(5);
    pq.enqueue(10);
    pq.enqueue(2);
    pq.enqueue(8);
    while (!pq.isEmpty()) pq.dequeue();

    cout << "\n=== TESTE 3: PRIORIDADES (ALTA, MEDIA, BAIXA) ===\n";
    testePrioridades();

    cout << "\n=== TESTE 4: ROUND ROBIN ===\n";
    roundRobin();

    return 0;
}
