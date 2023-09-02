#include <stdlib.h>
#include <string.h>
#include "trie.h"

#define ALPHABET_SIZE 26

struct TrieNode {
    void *value;
    TrieNode *children[ALPHABET_SIZE];
};

struct Trie {
    TrieNode *root;
};

TrieNode *trie_node_create() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    if (node) {
        node->value = NULL;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            node->children[i] = NULL;
        }
    }
    return node;
}

Trie *trie_create() {
    Trie *trie = (Trie *)malloc(sizeof(Trie));
    if (trie) {
        trie->root = trie_node_create();
    }
    return trie;
}

void trie_insert(Trie *trie, const char *key, void *value) {
    if (!trie || !key) return;

    TrieNode *current = trie->root;
    for (int i = 0; key[i]; ++i) {
        int index = key[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = trie_node_create();
        }
        current = current->children[index];
    }
    current->value = value;
}

bool trie_search(Trie *trie, const char *key, void **value) {
    if (!trie || !key) return false;

    TrieNode *current = trie->root;
    for (int i = 0; key[i]; ++i) {
        int index = key[i] - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    if (current->value) {
        *value = current->value;
        return true;
    }
    return false;
}

static bool _trie_node_is_empty(TrieNode *node) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->children[i]) {
            return false;
        }
    }
    return true;
}

static void _trie_node_destroy(TrieNode *node) {
    if (!node) return;

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->children[i]) {
            _trie_node_destroy(node->children[i]);
        }
    }
    free(node);
}

static bool _trie_remove_helper(TrieNode *node, const char *key, int level) {
    if (!node) return false;

    if (!key[level]) {
        if (node->value) {
            node->value = NULL;
            return _trie_node_is_empty(node);
        }
        return false;
    }

    int index = key[level] - 'a';
    if (_trie_remove_helper(node->children[index], key, level + 1)) {
        // Remove the child node if it's empty and not associated with a value
        if (_trie_node_is_empty(node->children[index]) && !node->children[index]->value) {
            free(node->children[index]);
            node->children[index] = NULL;
        }
        return !_trie_node_is_empty(node);
    }
    return false;
}

bool trie_remove(Trie *trie, const char *key) {
    if (!trie || !key) return false;
    return _trie_remove_helper(trie->root, key, 0);
}

void _trie_destroy(TrieNode *node) {
    if (!node) return;

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->children[i]) {
            _trie_node_destroy(node->children[i]);
        }
    }
    free(node);
}

void trie_destroy(Trie *trie) {
    if (trie) {
        _trie_destroy(trie->root);
        free(trie);
    }
}
