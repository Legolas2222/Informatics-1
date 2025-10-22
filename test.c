#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

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

void appendtoLL(LinkedList *list, int value)
{
    if (!list)
        return;

    LLItem *item = (LLItem *)malloc(sizeof(LLItem));
    if (!item)
        return; /* allocation failed */
    item->value = value;
    item->next = NULL;

    if (list->start == NULL)
    {
        list->start = item;
    }
    else
    {
        LLItem *current = list->start;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = item;
    }
    list->length++;
}

void printLL(LinkedList *list)
{
    if (!list)
        return;
    for (LLItem *current = list->start; current != NULL; current = current->next)
    {
        printf("%d\n", current->value);
    }
}

/* compute primes <= maxNumber using Sieve of Eratosthenes */
LinkedList *computePrime(int maxNumber)
{
    if (maxNumber < 2)
    {
        LinkedList *empty = (LinkedList *)malloc(sizeof(LinkedList));
        if (!empty)
            return NULL;
        empty->length = 0;
        empty->start = NULL;
        return empty;
    }

    char *isPrime = (char *)malloc((maxNumber + 1) * sizeof(char));
    if (!isPrime)
        return NULL;
    memset(isPrime, 1, (maxNumber + 1) * sizeof(char));
    isPrime[0] = 0;
    if (maxNumber >= 1)
        isPrime[1] = 0;

    int limit = (int)sqrt((double)maxNumber);
    for (int p = 2; p <= limit; ++p)
    {
        if (isPrime[p])
        {
            for (int m = p * p; m <= maxNumber; m += p)
                isPrime[m] = 0;
        }
    }

    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (!list)
    {
        free(isPrime);
        return NULL;
    }
    list->length = 0;
    list->start = NULL;

    for (int i = 2; i <= maxNumber; ++i)
    {
        if (isPrime[i])
            appendtoLL(list, i);
    }

    free(isPrime);
    return list;
}

int main(void)
{
    const int MAX_N = 1000000; /* compute primes up to 1,000,000 */

    LinkedList *primes = computePrime(MAX_N);
    if (!primes)
    {
        fprintf(stderr, "Failed to compute primes (allocation error)\n");
        return 1;
    }

    printLL(primes);

    /* cleanup linked list nodes */
    LLItem *cur = primes->start;
    while (cur)
    {
        LLItem *tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    free(primes);

    return 0;
}
