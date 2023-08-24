#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* lista = (List*) malloc(sizeof(List));
  lista->head = NULL;
  lista->tail = NULL;
  lista->current = NULL;
     return lista;
}

void * firstList(List * list) {
  if (list->head == NULL){
    return NULL;
  }
  list->current = list->head;
  return list->head->data;
}

void * nextList(List * list) {
  if (list->current == NULL){
    return NULL;
  }
  Node * proximoNodo = list->current->next;
  list->current = proximoNodo;

  if (proximoNodo == NULL){
    return NULL;
  }

    return proximoNodo->data;
}

void * lastList(List * list) {
    if (list->tail == NULL){
    return NULL;
  }
  list->current = list->tail;
  return list->tail->data;
}

void * prevList(List * list) {
    if (list->current == NULL){
    return NULL;
  }
  Node * nodoAnterior = list->current->prev;
  list->current = nodoAnterior;

  if (nodoAnterior == NULL){
    return NULL;
  }

    return nodoAnterior->data;
}

void pushFront(List * list, void * data) {
  Node * newNode = createNode(data); // Crea un nuevo nodo con el dato

    if (list->head == NULL) {
        // La lista está vacía, el nuevo nodo será el único nodo en la lista
        list->head = newNode;
        list->tail = newNode;
        list->current = newNode;
        return;
    }

    Node * nodo_b = list->head; 
    Node * nodo_a = NULL;       

    // Conecta el nuevo nodo con los nodos a y b
    newNode->next = nodo_b;
    newNode->prev = nodo_a;

    // Ajusta el puntero prev del nodo b actual para que apunte al nuevo nodo
    nodo_b->prev = newNode;

    // Actualiza el puntero head de la estructura List para que apunte al nuevo nodo
    list->head = newNode;

    // Actualiza el puntero current de la estructura List
    list->current = newNode;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  if (list->current == NULL){
    return;
  }
  Node * nuevoNodo = createNode(data);
  Node * nodo_b = list->current;
  Node * nodo_a = nodo_b->prev;

  nuevoNodo->next = nodo_b;
  nuevoNodo->prev = nodo_a;

  if (nodo_a != NULL){
    nodo_a->next = nuevoNodo;
    nuevoNodo->prev = nodo_a;
  }
  else{
    list->head = nuevoNodo;
    nuevoNodo->prev = NULL;
  }
  list->current = nuevoNodo;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}