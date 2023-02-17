# Declara uma matriz de 20x20 elementos com todos os elementos inicializados como -1
matriz_adj = [[-1 for j in range(20)] for i in range(20)]

# Declara variável num_vertices e solicita ao usuário que informe o número de cidades
num_vertices = int(input("Digite o numero de cidades do mapa (no maximo 20): "))

# Loop para ler as estradas que ligam as cidades informadas pelo usuário
for x in range(num_vertices):
  # Declara variável num_adj e solicita ao usuário que informe o número de estradas que saem da cidade atual
  num_adj = int(input(f"Digite o numero de estradas que saem da cidade {x + 1}: "))
  for y in range(num_adj):
    # Declara variáveis ver_adj e distancia e solicita ao usuário que informe a cidade adjacente e a distância em km
    ver_adj = int(input(f"Digite a {y + 1}a cidade que se pode chegar a partir da cidade {x + 1}: "))
    distancia = int(input(f"Digite a distancia em Km da estrada ({x + 1}-{ver_adj}): "))
    # Armazena a distância na matriz de adjacência, na posição correspondente à cidade atual e a cidade adjacente
    matriz_adj[x][ver_adj - 1] = distancia

# Imprime a matriz de adjacência resultante
print("\n\tMATRIZ DE ADJACENCIA: ")
for x in range(num_vertices):
  for y in range(num_vertices):
    # Verifica se o elemento da diagonal principal e atualiza para zero
    if x == y:
      matriz_adj[x][y] = 0
    # Verifica se o elemento da matriz é -1 e imprime '-' na tela
    if matriz_adj[x][y] == -1:
      print(" - ", end="")
    else:
      # Imprime a distância entre as cidades na tela
      print(f"{matriz_adj[x][y]}Km ", end="")
  # Pula linha depois de imprimir todas as colunas da linha atual
  print()
