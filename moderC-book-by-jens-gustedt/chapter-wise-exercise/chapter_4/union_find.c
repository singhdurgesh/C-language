#include <stdlib.h>
#include <stdio.h>

#define MAX 100

int parent[MAX];

// Find the parent of a node
int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return find(parent[x]);
}

// Can you implement a FindCompress function that changes all parent entries to the root that has been found?
// Find the parent of a node and compress the path
int find_compress(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find_compress(parent[x]);
}

// Can you implement a FindReplace function that changes all parent entries on a path to the root (including) to a specific value?
// Find the parent of a node and replace it with other value
int find_replace(int x, int y) {
    if (parent[x] == x) {
      parent[x] = y;
      return y;
    }
    return parent[x] = find_replace(parent[x], y);
}

// Union two nodes
// Basic Implementation
void union_basic(int x, int y){
    int x_root = find(x);
    int y_root = find(y);
    parent[x_root] = y_root;
}

// Can you implement a Union function that, for two given elements,
// combines their trees into one? Use FindCompress for one side and FindReplace for the other.
void union_efficient(int x, int y){
    int x_root = find_compress(x);
    int y_root = find_replace(y, x_root);
}

int main() {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < MAX; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        union_efficient(x, y);
    }

    for (int i = 0; i < MAX; i++) {
        printf("%d: %d\n",i, parent[i]);
    }
    return EXIT_SUCCESS;
}
