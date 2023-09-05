#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define MAX_WORD_LENGTH 100

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    if (node) {
        node->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}

void insert(struct TrieNode* root, const char* word) {
    struct TrieNode* current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool search(struct TrieNode* root, const char* word) {
    struct TrieNode* current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return current && current->isEndOfWord;
}

void autocompleteHelper(struct TrieNode* node, char* prefix, int depth, char** results, int* count) {
    if (node == NULL) {
        return;
    }

    if (node->isEndOfWord) {
        prefix[depth] = '\0';
        results[*count] = (char*)malloc((strlen(prefix) + 1) * sizeof(char));
        strcpy(results[*count], prefix);
        (*count)++;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            prefix[depth] = 'a' + i;
            autocompleteHelper(node->children[i], prefix, depth + 1, results, count);
        }
    }
}

char** autocomplete(struct TrieNode* root, const char* prefix) {
    struct TrieNode* current = root;
    char** results = (char**)malloc(ALPHABET_SIZE * sizeof(char*));
    int count = 0;

    char* buffer = (char*)malloc((strlen(prefix) + 1) * sizeof(char));
    strcpy(buffer, prefix);

    for (int i = 0; buffer[i] != '\0'; i++) {
        int index = buffer[i] - 'a';
        if (!current->children[index]) {
            // No words with the given prefix
            free(buffer);
            return NULL;
        }
        current = current->children[index];
    }

    autocompleteHelper(current, buffer, strlen(prefix), results, &count);

    free(buffer);

    // Add a NULL pointer to mark the end of the results
    results[count] = NULL;

    return results;
}

void freeAutocompleteResults(char** results) {
    if (results == NULL) {
        return;
    }

    for (int i = 0; results[i] != NULL; i++) {
        free(results[i]);
    }

    free(results);
}

void destroyTrie(struct TrieNode* node) {
    if (node) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i]) {
                destroyTrie(node->children[i]);
            }
        }
        free(node);
    }
}

// Function to destroy the entire Trie
void destroy(struct TrieNode* root) {
    destroyTrie(root);
}

int main() {
    struct TrieNode* root = createNode();

    insert(root, "apple");
    insert(root, "app");
    insert(root, "banana");
    insert(root, "bat");
    insert(root, "cat");

    const char* searchWord = "app";
    if (search(root, searchWord)) {
        printf("%s found in the Trie.\n", searchWord);
    } else {
        printf("%s not found in the Trie.\n", searchWord);
    }

    char prefix[] = "ba";
    char** autocompleteResults = autocomplete(root, prefix);

    if (autocompleteResults) {
        printf("Words starting with '%s':\n", prefix);
        for (int i = 0; autocompleteResults[i] != NULL; i++) {
            printf("%s\n", autocompleteResults[i]);
        }
        freeAutocompleteResults(autocompleteResults);
    } else {
        printf("No words found with prefix '%s'.\n", prefix);
    }

    // Destroy the Trie when done
    destroy(root);

    return 0;
}

