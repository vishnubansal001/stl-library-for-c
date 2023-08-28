#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>

typedef struct TrieNode TrieNode;
typedef struct Trie Trie;

Trie *trie_create();
void trie_insert(Trie *trie, const char *key, void *value);
bool trie_search(Trie *trie, const char *key, void **value);
bool trie_remove(Trie *trie, const char *key);
void trie_destroy(Trie *trie);

#endif // TRIE_H
