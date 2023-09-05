#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

struct TrieNode;

struct TrieNode* createNode();
void insert(struct TrieNode* root, const char* word);
bool search(struct TrieNode* root, const char* word);
char** autocomplete(struct TrieNode* root, const char* prefix);
void freeAutocompleteResults(char** results);
void destroy(struct TrieNode* root);

#endif

