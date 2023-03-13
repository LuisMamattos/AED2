#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 20

int minDistance(int dist[], int visited[], int num_vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < num_vertices; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int matriz_adj[MAX_VERTICES][MAX_VERTICES], int origem, int destino, int num_vertices) {
    int dist[num_vertices], visited[num_vertices];

    for (int i = 0; i < num_vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[origem] = 0;

    for (int count = 0; count < num_vertices - 1; count++) {
        int u = minDistance(dist, visited, num_vertices);
        visited[u] = 1;

        for (int v = 0; v < num_vertices; v++) {
            if (!visited[v] && matriz_adj[u][v] != -1 && dist[u] != INT_MAX && dist[u] + matriz_adj[u][v] < dist[v]) {
                dist[v] = dist[u] + matriz_adj[u][v];
            }
        }
    }

    if (dist[destino] != INT_MAX) {
        printf("A distancia minima entre os vertices %d e %d eh: %d km\n", origem + 1, destino + 1, dist[destino]);
    } else {
        printf("Nao ha caminho entre os vertices %d e %d\n", origem + 1, destino + 1);
    }
}
int main() {
int num_vertices, num_adj, ver_adj, x, y;
int matriz_adj[MAX_VERTICES][MAX_VERTICES];
// Inicializa matriz de adjacência com -1 para representar falta de arestas
for (x = 0; x < MAX_VERTICES; x++) {
    for (y = 0; y < MAX_VERTICES; y++) {
        matriz_adj[x][y] = -1;
    }        
}
// Pede ao usuário para digitar o número de cidades e as estradas entre elas
printf("Digite o numero de cidades do mapa (no maximo 20): "); 
scanf("%d", &num_vertices);
for(x=0;x<num_vertices;x++){
    printf("Digite o numero de estradas que saem da cidade %d: ",x+1);
    scanf("%d", &num_adj);
    for(y=0;y<num_adj;y++){
        printf("Digite a %da cidade que se pode chegar a partir da cidade %d: ",y+1,x+1);
        scanf("%d", &ver_adj);
        printf("Digite a distancia em Km da estrada (%d-%d): ",x+1,ver_adj);
        int distance;
        scanf("%d", &distance);
        matriz_adj[x][ver_adj-1] = distance;
        matriz_adj[ver_adj-1][x] = distance;
    }
}

// Imprime a matriz de adjacência resultante
printf("\n\tMATRIZ DE ADJACENCIA: \n");
for(x=0;x<num_vertices;x++){
    for(y=0;y<num_vertices;y++){
        if(x==y){
            matriz_adj[x][y] = 0;
        }
        if(matriz_adj[x][y] == -1){
            printf("%d  ",matriz_adj[x][y]);                
        }
        else{
            printf("%dKm  ",matriz_adj[x][y]);
        }            
    }
    printf("\n");
} 

// Pede ao usuário os vértices de origem e destino para calcular a menor distância entre eles
int origem, destino;
printf("Digite o vertice de origem (entre 1 e %d): ", num_vertices);
scanf("%d", &origem);
printf("Digite o vertice de destino (entre 1 e %d): ", num_vertices);
scanf("%d", &destino);

// Executa o algoritmo de Dijkstra
dijkstra(matriz_adj, origem - 1, destino - 1, num_vertices);

return 0;
}
