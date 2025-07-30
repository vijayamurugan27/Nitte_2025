// problem number 49 Group Anagrams

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Helper function to sort characters in a string
void sortString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// Node to store each word in a group
typedef struct WordNode {
    char* word;
    struct WordNode* next;
} WordNode;

// Hash table node
typedef struct HashNode {
    char* key;           // Sorted version of the word
    WordNode* words;     // Linked list of original words
    struct HashNode* next;
} HashNode;

// Hash table
typedef struct HashTable {
    HashNode** buckets;
    int size;
} HashTable;

int hash(char* key, int size) {
    int h = 0;
    for (int i = 0; key[i]; i++) {
        h = (h * 31 + key[i]) % size;
    }
    return h;
}

HashTable* createHashTable(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = size;
    ht->buckets = (HashNode**)calloc(size, sizeof(HashNode*));
    return ht;
}

void insert(HashTable* ht, char* originalWord) {
    char sorted[100];
    strcpy(sorted, originalWord);
    sortString(sorted);

    int index = hash(sorted, ht->size);
    HashNode* node = ht->buckets[index];

    while (node) {
        if (strcmp(node->key, sorted) == 0) {
            WordNode* newWord = (WordNode*)malloc(sizeof(WordNode));
            newWord->word = strdup(originalWord);
            newWord->next = node->words;
            node->words = newWord;
            return;
        }
        node = node->next;
    }

    // New key
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = strdup(sorted);
    newNode->words = NULL;

    WordNode* newWord = (WordNode*)malloc(sizeof(WordNode));
    newWord->word = strdup(originalWord);
    newWord->next = NULL;

    newNode->words = newWord;
    newNode->next = ht->buckets[index];
    ht->buckets[index] = newNode;
}

void printGroups(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        HashNode* node = ht->buckets[i];
        while (node) {
            WordNode* w = node->words;
            printf("[ ");
            while (w) {
                printf("%s ", w->word);
                w = w->next;
            }
            printf("]\n");
            node = node->next;
        }
    }
}

void freeHashTable(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        HashNode* node = ht->buckets[i];
        while (node) {
            HashNode* temp = node;
            WordNode* w = node->words;
            while (w) {
                WordNode* tempW = w;
                free(w->word);
                w = w->next;
                free(tempW);
            }
            free(node->key);
            node = node->next;
            free(temp);
        }
    }
    free(ht->buckets);
    free(ht);
}

int main() {
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    char** strs = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        strs[i] = (char*)malloc(100 * sizeof(char));
        scanf("%s", strs[i]);
    }

    HashTable* ht = createHashTable(101); // A prime number size
    for (int i = 0; i < n; i++) {
        insert(ht, strs[i]);
    }

    printf("\nGrouped Anagrams:\n");
    printGroups(ht);

    freeHashTable(ht);
    for (int i = 0; i < n; i++) {
        free(strs[i]);
    }
    free(strs);

    return 0;
}
