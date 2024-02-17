#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//////////////////  STRUCTURI  ////////////////////////////
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

//////////////////  LINKED-LIST  ////////////////////////////
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

void afisareList(List * list);
void introducereDate(List * list, int * n);
void citireDate(avto * automobil);
void lucruCuDate(List * list, int * n);
void Cautare(List * list);
void Sortare(List * list);

//functii pentru cautare
void NumeCompanie(List * list);
void Model(List * list);
void Culoare(List * list);
void Stare(List * list);
void An_productie(List * list);
void Pret(List * list);

//functii pentru sortare
void NumeCompanieSort(List * list);
void ModelSort(List * list);
void CuloareSort(List * list);
void StareSort(List * list);
void An_productieSort(List * list);
void Pret_Sort(List * list);

// functii de inserare
void PushFront(List * list);
void PushBack(List * list);
void PushIndex(List * list);

// functie de stergere
void DeleteIndex(List * list);

// functie de inversare a listei
void InversList(List * list);

// functie pentru eliberarea memoriei
void freeMemory(List * list);

//////////////////////////////
int main(){
    int n;
    printf("Introdu numarul de automobile: ");
    scanf("%d", &n);

    List * list = createList();
    introducereDate(list, &n);
    afisareList(list);

    lucruCuDate(list, &n);
    freeMemory(list);
    return 0;
}
/////////////////////////////

int SizeList(List * list){
    int count = 0;
    for(Node * currentNode = list->head; currentNode; currentNode = currentNode->next){
        count++;
    }
    return count;
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
void introducereDate(List * list, int * n){
    for(int i = 0; i < *n; i++){
        PushFront(list);
        printf("\n");
    }
}
void citireDate(avto * automobil){
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
}

void lucruCuDate(List * list, int * n){
    int option;
    do{
        printf("Selecteaza una din optiuni:\n");
        printf("(1) Cautare\n");
        printf("(2) Sortare\n");
        printf("(3) Inserare la capat\n");
        printf("(4) Inserare la inceput\n");
        printf("(5) Inserare la X\n");
        printf("(6) Stergere la X\n");
        printf("(7) Inversare\n");
        printf("(8) Printeaza lista\n");
        printf("(9) Exit\n");
        printf("Enter: ");
        scanf("%d", &option);

        switch(option){
        case 1:
            Cautare(list);
            break;
        case 2:
            Sortare(list);
            break;
        case 3:
            PushBack(list);
            break;
        case 4:
            PushFront(list);
            break;
        case 5:
            PushIndex(list);
            break;
        case 6:
            DeleteIndex(list);
            break;
        case 7:
            InversList(list);
            break;
        case 8:
            afisareList(list);
            break;
        case 9:
            option = -1;
            break;
        default:
            printf("You entered something wrong\n\n");
        }
    } while(option != -1);
    printf("Sfarsit.\n");
}


// Cautare menu si functii pentru cautare
void Cautare(List * list){
    int camp;
    printf("Care camp:\n");
    printf("(1) Nume companie.\n");
    printf("(2) Model.\n");
    printf("(3) Culoare.\n");
    printf("(4) Stare.\n");
    printf("(5) An productie.\n");
    printf("(6) Pret.\n");
    printf("Enter: ");
    scanf(" %d", &camp);

    switch(camp){
    case 1:
        NumeCompanie(list);
        break;
    case 2:
        Model(list);
        break;
    case 3:
        Culoare(list);
        break;
    case 4:
        Stare(list);
        break;
    case 5:
        An_productie(list);
        break;
    case 6:
        Pret(list);
        break;
    default:
        printf("Wrong value.\n\n");
        break;
    }
}
void NumeCompanie(List * list){
    int count = 0;
    char name[50];
    printf("Numele companiei: ");
    scanf(" %[^\n]s", name);

    for(Node * currentNode = list->head; currentNode; currentNode = currentNode->next){
        count++;
        if(strcmp(currentNode->data->nume_companie, name) == 0){
            printf("Pozitia %d\n\n", count);
            return;
        }
    }
    printf("Nu a fost gasit niciun element.\n\n");
}
void Model(List * list){
    int count = 0;
    char model[50];
    printf("Numele companiei: ");
    scanf(" %[^\n]s", model);

    for(Node * currentNode = list->head; currentNode; currentNode = currentNode->next){
        count++;
        if(strcmp(currentNode->data->nume_companie, model) == 0){
            printf("Pozitia %d\n\n", count);
            return;
        }
    }
    printf("Nu a fost gasit niciun element.\n\n");
}
void Culoare(List * list){
    int count = 0;
    char culoare[50];
    printf("Numele companiei: ");
    scanf(" %[^\n]s", culoare);

    for(Node * currentNode = list->head; currentNode; currentNode = currentNode->next){
        count++;
        if(strcmp(currentNode->data->nume_companie, culoare) == 0){
            printf("Pozitia %d\n\n", count);
            return;
        }
    }
    printf("Nu a fost gasit niciun element.\n\n");
}
void Stare(List * list){
    int count = 0;
    char stare[50];
    printf("Numele companiei: ");
    scanf(" %[^\n]s", stare);

    for(Node * currentNode = list->head; currentNode; currentNode = currentNode->next){
        count++;
        if(strcmp(currentNode->data->nume_companie, stare) == 0){
            printf("Pozitia %d\n\n", count);
            return;
        }
    }
    printf("Nu a fost gasit niciun element.\n\n");
}
void An_productie(List * list){
    int count = 0;
    int an;
    printf("Numele companiei: ");
    scanf(" %d", &an);

    for(Node * currentNode = list->head; currentNode; currentNode = currentNode->next){
        count++;
        if(currentNode->data->an_productie == an){
            printf("Pozitia %d\n\n", count);
            return;
        }
    }
    printf("Nu a fost gasit niciun element.\n\n");
}
void Pret(List * list){
    int count = 0;
    int pret;
    printf("Numele companiei: ");
    scanf(" %d", &pret);

    for(Node * currentNode = list->head; currentNode; currentNode = currentNode->next){
        count++;
        if(currentNode->data->pret == pret){
            printf("Pozitia %d\n\n", count);
            return;
        }
    }
    printf("Nu a fost gasit niciun element.\n\n");
}



// Sortare menu si functii pentru sortare
void Sortare(List * list){
    int camp;
    printf("Introdu una din optiuni:\n");
    printf("(1) Nume companie.\n");
    printf("(2) Model.\n");
    printf("(3) Culoare.\n");
    printf("(4) Stare.\n");
    printf("(5) An productie.\n");
    printf("(6) Pret.\n");
    printf("Enter: ");
    scanf(" %d", &camp);

    switch(camp){
    case 1:
        NumeCompanieSort(list);
        break;
    case 2:
        ModelSort(list);
        break;
    case 3:
        CuloareSort(list);
        break;
    case 4:
        StareSort(list);
        break;
    case 5:
        An_productieSort(list);
        break;
    case 6:
        Pret_Sort(list);
        break;
    default:
        printf("Wrong value.\n\n");
    }
}
void NumeCompanieSort(List * list){
    int length = SizeList(list);
    if(length == 1){
        printf("Exista doar un element.\n");
        return;
    }

    Node * headNode = list->head;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - i - 1; j++){
            Node * p1 = headNode;
            Node * p2 = headNode->next;

            if(strcmp(p1->data->nume_companie, p2->data->nume_companie) > 0){
                avto * temp = p2->data;
                p2->data = p1->data;
                p1->data = temp;
            }
            p2 = p2->next;
        }
        headNode = headNode->next;
    }
}
void ModelSort(List * list){
    int length = SizeList(list);
    if(length == 1){
        printf("Exista doar un element.\n");
        return;
    }

    Node * headNode = list->head;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - i - 1; j++){
            Node * p1 = headNode;
            Node * p2 = headNode->next;

            if(strcmp(p1->data->model, p2->data->model) > 0){
                avto * temp = p2->data;
                p2->data = p1->data;
                p1->data = temp;
            }
            p2 = p2->next;
        }
        headNode = headNode->next;
    }
    afisareList(list);
}
void CuloareSort(List * list){
    int length = SizeList(list);
    if(length == 1){
        printf("Exista doar un element.\n");
        return;
    }

    Node * headNode = list->head;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - i - 1; j++){
            Node * p1 = headNode;
            Node * p2 = headNode->next;

            if(strcmp(p1->data->culoare, p2->data->culoare) > 0){
                avto * temp = p2->data;
                p2->data = p1->data;
                p1->data = temp;
            }
            p2 = p2->next;
        }
        headNode = headNode->next;
    }
}
void StareSort(List * list){
    int length = SizeList(list);
    if(length == 1){
        printf("Exista doar un element.\n");
        return;
    }

    Node * headNode = list->head;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - i - 1; j++){
            Node * p1 = headNode;
            Node * p2 = headNode->next;

            if(strcmp(p1->data->stare, p2->data->stare) > 0){
                avto * temp = p2->data;
                p2->data = p1->data;
                p1->data = temp;
            }
            p2 = p2->next;
        }
        headNode = headNode->next;
    }
}
void An_productieSort(List * list){
    int length = SizeList(list);
    if(length == 1){
        printf("Exista doar un element.\n");
        return;
    }

    Node * headNode = list->head;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - i - 1; j++){
            Node * p1 = headNode;
            Node * p2 = headNode->next;

            if(p1->data->an_productie > p2->data->an_productie){
                avto * temp = p2->data;
                p2->data = p1->data;
                p1->data = temp;
            }
            p2 = p2->next;
        }
        headNode = headNode->next;
    }
}
void Pret_Sort(List * list){
    int length = SizeList(list);
    if(length == 1){
        printf("Exista doar un element.\n");
        return;
    }

    Node * headNode = list->head;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - i - 1; j++){
            Node * p1 = headNode;
            Node * p2 = headNode->next;

            if(p1->data->pret > p2->data->pret){
                avto * temp = p2->data;
                p2->data = p1->data;
                p1->data = temp;
            }
            p2 = p2->next;
        }
        headNode = headNode->next;
    }
}


// Inserare fata
void PushFront(List * list){
    avto * automobil = (avto *)malloc(sizeof(avto));
    citireDate(automobil);

    Node * node = createNode(automobil);
    if(list->head == NULL){
        list->head = node;
        return;
    }
    node->next = list->head;
    list->head = node;
}

//Inserare spate
void PushBack(List * list){
        avto * automobil = (avto *)malloc(sizeof(avto));
        citireDate(automobil);

        Node * newNode = createNode(automobil);
        Node * currentNode = list->head;

        while(currentNode->next != NULL){
            currentNode = currentNode->next;
        }

        newNode->next = currentNode->next;
        currentNode->next = newNode;
}

// Inserare dupa index
void PushIndex(List * list){
    int index;
    printf("Introdu pozitia: ");
    scanf("%d", &index);
    int length = SizeList(list);

    if(index < 1 || index > length){
        printf("Pozitia trebuie sa fie in limitele listei.\n\n");
        return;
    }

    index--;
    if(index == 0){
        PushFront(list);
        return;
    }

    avto * automobil = (avto *)malloc(sizeof(avto));
    citireDate(automobil);

    Node * newNode = createNode(automobil);
    Node * currentNode = list->head;

    for(int i = 0; i < index - 1; i++){
        currentNode = currentNode->next;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

// Stergere dupa index
void DeleteIndex(List * list){
    int index;
    printf("Introdu pozitia: ");
    scanf("%d", &index);
    int length = SizeList(list);
    if(index < 1 || index > length){
        printf("Pozitia trebuie sa fie in limitele listei.\n\n");
        return;
    }
    index--;
    //in caz ca lista are doar un singur node
    if(index == 0){
        free(list->head);
        list->head = NULL;
        return;
    }

    Node * currentNode = list->head;
    for(int i = 0; i < index - 1; i++){
        currentNode = currentNode->next;
    }

    currentNode->next = currentNode->next->next;
    free(currentNode->next);
}

// Inversarea listei
void InversList(List * list){
    int length = SizeList(list);
    if(length == 1){
        return;
    }

    Node * prev = NULL;
    Node * next = NULL;
    Node * currentNode = list->head;

    while(currentNode != NULL){
        next = currentNode->next;
        currentNode->next = prev;
        prev = currentNode;
        currentNode = next;
    }
    list->head = prev;
}

// Eliberare memorie
void freeMemory(List * list){
    Node * prev = NULL;
    Node * currentNode = list->head;
    while(currentNode != NULL){
        prev = currentNode;
        currentNode = currentNode->next;
        free(prev);
    }
    free(list);
}
