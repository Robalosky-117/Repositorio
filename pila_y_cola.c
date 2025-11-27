#include <stdio.h>
#include <stdlib.h>

#define MAX 5

//PILA
typedef struct {
    int datos[MAX];
    int tope;
} Pila;

void inicializarPila(Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacía\n");
}

int pilaLlena(Pila *p) {
    return p->tope == MAX - 1;
}

int pilaVacia(Pila *p) {
    return p->tope == -1;
}

void push(Pila *p, int valor) {
    if (pilaLlena(p)) {
        printf("Error: La pila está llena\n");
        return;
    }
    p->datos[++p->tope] = valor;
    printf("Elemento %d apilado\n", valor);
}

int pop(Pila *p) {
    if (pilaVacia(p)) {
        printf("Error: La pila está vacía\n");
        return -1;
    }
    return p->datos[p->tope--];
}

void mostrarPila(Pila *p) {
    if (pilaVacia(p)) {
        printf("Pila vacía\n");
        return;
    }
    printf("Estado de la pila: ");
    for (int i = 0; i <= p->tope; i++) {
        printf("%d ", p->datos[i]);
    }
    printf("\n");
}

//COLA
typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;

void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf("Cola inicializada vacía\n");
}

int colaLlena(Cola *c) {
    return c->final == MAX - 1;
}

int colaVacia(Cola *c) {
    return c->frente > c->final;
}

void enqueue(Cola *c, int valor) {
    if (colaLlena(c)) {
        printf("Error: La cola está llena\n");
        return;
    }
    c->datos[++c->final] = valor;
    printf("Elemento %d encolado\n", valor);
}

int dequeue(Cola *c) {
    if (colaVacia(c)) {
        printf("Error: La cola está vacía\n");
        return -1;
    }
    return c->datos[c->frente++];
}

void mostrarCola(Cola *c) {
    if (colaVacia(c)) {
        printf("Cola vacía\n");
        return;
    }
    printf("Estado de la cola: ");
    for (int i = c->frente; i <= c->final; i++) {
        printf("%d ", c->datos[i]);
    }
    printf("\n");
}

// MAIN
int main() {
    Pila pila;
    Cola cola;
    int n, valor;

    // Paso 1: Inicializar pila
    inicializarPila(&pila);

    // Paso 2: Insertar elementos en pila
    printf("\n¿Cuántos elementos quiere apilar (máximo 5)? ");
    scanf("%d", &n);
    if (n > MAX) n = MAX;
    for (int i = 0; i < n; i++) {
        printf("Ingrese elemento %d: ", i + 1);
        scanf("%d", &valor);
        push(&pila, valor);
        mostrarPila(&pila);
    }

    // Paso 3: Extraer elementos de la pila
    printf("\n¿Cuántos elementos quiere desapilar? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int elem = pop(&pila);
        if (elem != -1)
            printf("Elemento desapilado: %d\n", elem);
        mostrarPila(&pila);
    }

    // Paso 4: Inicializar cola
    inicializarCola(&cola);

    // Paso 5: Insertar elementos en cola
    printf("\n¿Cuántos elementos quiere encolar (máximo 5)? ");
    scanf("%d", &n);
    if (n > MAX) n = MAX;
    for (int i = 0; i < n; i++) {
        printf("Ingrese elemento %d: ", i + 1);
        scanf("%d", &valor);
        enqueue(&cola, valor);
        mostrarCola(&cola);
    }

    // Paso 6: Extraer elementos de la cola
    printf("\n¿Cuántos elementos quiere desencolar? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int elem = dequeue(&cola);
        if (elem != -1)
            printf("Elemento desencolado: %d\n", elem);
        mostrarCola(&cola);
    }

    // Paso 7: Comparación
    printf("\n--- Comparación ---\n");
    printf("Pila → LIFO (último en entrar, primero en salir)\n");
    printf("Cola → FIFO (primero en entrar, primero en salir)\n");

    return 0;
}
