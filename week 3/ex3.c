#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>

struct ListItem {
    int key;
    struct ListItem *next;

};

bool hasNext(struct ListItem *item) {
    return item->next != NULL;
}

struct List {
    struct ListItem *head;

};

void insert_node(struct List *list, int value);

void delete_node(struct List *list, int key);

void create(struct List *list);

void destruct(struct List *list);

void print_list(struct List *list);

int main() {
    struct List list;
    create(&list);
    insert_node(&list, 1);
    insert_node(&list, 2);
    insert_node(&list, 3);
    insert_node(&list, 4);
    insert_node(&list, 5);
    insert_node(&list, 6);
    insert_node(&list, 7);
    print_list(&list);
    delete_node(&list, 4);
    print_list(&list);
    destruct(&list);
    return 0;
}

void create(struct List *list) {
    list->head = (struct ListItem *) malloc(sizeof(struct ListItem));
    list->head->next = NULL;
}

void insert_node(struct List *list, int value) {
    struct ListItem *tmp = (struct ListItem *) malloc(sizeof(struct ListItem));
    tmp->key = value;
    tmp->next = NULL;
    struct ListItem *current = list->head;
    while (hasNext(current)) {
        current = current->next;
    }
    current->next = tmp;
}

void delete_node(struct List *list, int key) {
    struct ListItem *current = list->head;
    struct ListItem *tmp;
    while (hasNext(current)) {
        if (current->next->key == key) {
            tmp = current->next->next;
            free(current->next);
            current->next = tmp;
            break;
        }
        current = current->next;
    }
}

void destruct(struct List *list) {
    struct ListItem *tmp = list->head;
    while (hasNext(tmp)) {
        struct ListItem *copyOfAdress = tmp->next;
        free(tmp);
        tmp = copyOfAdress;

    }
}

void print_list(struct List *list) {
    struct ListItem *tmp = list->head;
    while (hasNext(tmp)) {
        tmp = tmp->next;
        printf("%d ", tmp->key);
    }
}

