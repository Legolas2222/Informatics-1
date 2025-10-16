#include <stdio.h>
#include <math.h>


typedef struct LLItem
{
    int value;
    struct LLItem *next;
} LLItem;


typedef struct LinkedList
{
    int length;
    struct LLItem *start;
    
} LinkedList;


void appendItemtoLL(LinkedList* list, LLItem* item) {
    if (!list || !item) {return; }
    item->next = NULL;
    if (list->start == NULL)
    {
        list->start = item;
    }
    else {
        LLItem* current = list->start;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = item;
    }
    list->length++;
}


void printLL(LinkedList* list) {
    if (!list) return;
    for (LLItem* current = list->start; current != NULL; current = current->next) {
        printf("%d\n", current->value);   // correct printf usage
    }
}



int main(void) {
    printf("Hello, World!\n");

    LinkedList l = {0, NULL};
    LLItem item2 = {46, NULL};
    LLItem item1 = {23, NULL};

    appendItemtoLL(&l, &item1);
    appendItemtoLL(&l, &item2);
    printLL(&l);

    return 0;

}
