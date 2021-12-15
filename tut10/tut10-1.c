/* 
------------------------------------------------------------------------------
ALGORITHMEN & DATENSTRUKTUREN
Eric Kunze 
Website: https://oakoneric.github.io/aud21
------------------------------------------------------------------------------
Aufgabe 1
------------------------------------------------------------------------------
*/

#include <stdio.h>

struct Edge
{
    int from, to;
};

void topsort(int n,
             int e,
             struct Edge edges[],
             int ord[])
{
    int j = 1, node, edge, ok;
    while (j <= n)
    {
        // printf("Sortierungsnummer: %d \n", j);
        for (node = 0; node < n; ++node)
        {
            if (ord[node] == -1)
            {
                ok = 1;
                for (edge = 0; edge < e; ++edge)
                    if (edges[edge].to == node && ord[edges[edge].from] == -1)
                        ok = 0;
                if (ok)
                {
                    printf("Knoten %d bekommt Nummer %d. \n", node, j);
                    ord[node] = j;
                    j++;
                    break;
                }
            }
        }
    }
}

void bsp1()
{
    // Graph von Uebungsblatt 9 mit vorgeschalteter 0
    struct Edge edges[] =
        {
            {0, 1},
            {1, 5},
            {2, 5},
            {3, 5},
            {4, 5},
            {5, 6},
            {6, 7},
            {6, 8},
            {6, 9}};

    int lenEdges = sizeof(edges) / sizeof(edges[0]); // alternativ: int lenEdges = *(&edges + 1) - edges;
    printf("length: %d \n", lenEdges);

    int ord[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    topsort(10, lenEdges, edges, ord);

    for (int i = 0; i < 10; i++)
        printf("%d, ", ord[i]);
}

void bsp2()
{
    struct Edge edges[] =
        {
            {6, 5},
            {6, 3},
            {5, 2},
            {3, 2},
            {2, 4},
            {2, 1},
            {1, 4},
            {4, 0}};

    int lenEdges = sizeof(edges) / sizeof(edges[0]); // alternativ: int lenOne = *(&edges + 1) - edges;
    printf("\nlength: %d \n", lenEdges);

    int ord[] = {-1, -1, -1, -1, -1, -1, -1};
    topsort(7, lenEdges, edges, ord);

    printf("\n");
    for (int i = 0; i < 7; i++)
        printf("%d, ", ord[i]);
}

int main()
{
    // bsp1();
    bsp2();
}