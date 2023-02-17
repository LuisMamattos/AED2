// Declara uma matriz de 20x20 elementos com todos os elementos inicializados como -1
const matriz_adj = new Array(20).fill(null).map(() => new Array(20).fill(-1));

// Declara variável num_vertices e solicita ao usuário que informe o número de cidades
let num_vertices = +prompt("Digite o numero de cidades do mapa (no maximo 20): ");

// Loop para ler as estradas que ligam as cidades informadas pelo usuário
for (let x = 0; x < num_vertices; x++) {
  // Declara variável num_adj e solicita ao usuário que informe o número de estradas que saem da cidade atual
  let num_adj = +prompt(`Digite o numero de estradas que saem da cidade ${x + 1}: `);
  for (let y = 0; y < num_adj; y++) {
    // Declara variáveis ver_adj e distancia e solicita ao usuário que informe a cidade adjacente e a distância em km
    let ver_adj = +prompt(`Digite a ${y + 1}a cidade que se pode chegar a partir da cidade ${x + 1}: `);
    let distancia = +prompt(`Digite a distancia em Km da estrada (${x + 1}-${ver_adj}): `);
    // Armazena a distância na matriz de adjacência, na posição correspondente à cidade atual e a cidade adjacente
    matriz_adj[x][ver_adj - 1] = distancia;
  }
}

// Imprime a matriz de adjacência resultante
console.log("\n\tMATRIZ DE ADJACENCIA: ");
for (let x = 0; x < num_vertices; x++) {
  for (let y = 0; y < num_vertices; y++) {
    // Verifica se o elemento da diagonal principal e atualiza para zero
    if (x === y) {
      matriz_adj[x][y] = 0;
    }
    // Verifica se o elemento da matriz é -1 e imprime '-' na tela
    if (matriz_adj[x][y] === -1) {
      process.stdout.write(" -  ");
    } else {
      // Imprime a distância entre as cidades na tela
      process.stdout.write(`${matriz_adj[x][y]}Km  `);
    }
  }
  // Pula linha depois de imprimir todas as colunas da linha atual
  console.log("");
}
