#include <stdio.h>

int main() {
    int num_vertices,num_adj, ver_adj,x,y;
    int matriz_adj[20][20];

    // Inicializa matriz de adjacência com -1 para representar falta de arestas
    for(x=0;x<20;x++){
        for(y=0;y<20;y++){
            matriz_adj[x][y]=-1;
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
   
    
    return 0;
}
