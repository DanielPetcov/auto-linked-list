#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct automobil{
    char nume_companie[50];
    char model[50];
    char culoare[50];
    char stare[50];
    int an_productie;
    int pret;
} avto;

typedef struct Node{
    avto * data;
    struct Node * next;
} Node;

typedef struct List{
    Node * head;
} List;

Node * createNode(avto * data){
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

List * createList(){
    List * list = (List *)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void pushNode(avto * data, List * list){
    Node * node = createNode(data);
    if(list->head == NULL){
        list->head = node;
        return;
    }
    node->next = list->head;
    list->head = node;
}

void afisareList(List * list){
    if(list->head == NULL){
        printf("lista este goala.\n");
        return;
    }
    for(Node * currentNode = list->head; currentNode; currentNode = currentNode->next){
        avto * data = currentNode->data;
        printf("%s\n", data->nume_companie);
        printf("%s\n", data->model);
        printf("%s\n", data->culoare);
        printf("%s\n", data->stare);
        printf("%d\n", data->an_productie);
        printf("%d\n", data->pret);
        printf("\n");
    }
}

int main(){
    int n;
    printf("Introdu numarul de automobile: ");
    scanf("%d", &n);

    List * list = createList();
    for(int i = 0; i < n; i++){
        avto * automobil = (avto *)malloc(sizeof(avto));
        printf("Numele companiei: ");
        scanf(" %[^\n]s", automobil->nume_companie);
        printf("Model: ");
        scanf(" %[^\n]s", automobil->model);
        printf("Culoare: ");
        scanf(" %[^\n]s", automobil->culoare);
        printf("Stare: ");
        scanf(" %[^\n]s", automobil->stare);
        printf("Anul productiei: ");
        scanf(" %d", &automobil->an_productie);
        printf("Pret: ");
        scanf(" %d", &automobil->pret);
        pushNode(automobil, list);
    }

    afisareList(list);
    return 0;
}
