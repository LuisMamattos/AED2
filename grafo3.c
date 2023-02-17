#include <stdio.h>

int main() {
    int num_vertices, num_bidir, cidade1, cidade2, distancia, x, y;
    int matriz_adj[20][20];

    // Inicializa matriz de adjacência com -1 para representar falta de arestas
    for(x=0;x<20;x++){
        for(y=0;y<20;y++){
            matriz_adj[x][y] = -1;
        }        
    }
    
    // Pede ao usuário para digitar o número de cidades e as estradas entre elas
    printf("Digite o numero de cidades do mapa (no maximo 20): "); 
    scanf("%d", &num_vertices);
    
    printf("Digite o numero de estradas bidirecionais do mapa: ");
    scanf("%d", &num_bidir);
    
    for(x=0;x<num_bidir;x++){
        printf("Digite as cidades ligadas pela %da estrada bidirecional: ", x+1);
        scanf("%d %d", &cidade1, &cidade2);
        
        printf("Digite a distancia em Km da estrada (%d-%d): ", cidade1, cidade2);
        scanf("%d", &distancia);
        
        matriz_adj[cidade1-1][cidade2-1] = distancia;
        matriz_adj[cidade2-1][cidade1-1] = distancia;
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
    
    return 0;
}
