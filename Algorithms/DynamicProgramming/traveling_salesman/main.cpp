/**
 * @brief Encontra o ciclo hamiltoniano de menor custo
 * @param ans contem as cidades visitadas em ordem
 * @param visited eh a mascara com as cidades visitadas ate o momento
 * @param k eh a quantidade de cidades visitadas
 * @param d eh a distancia percorrida ate agora
 * Essa solucao usa um sistema de coordenadas, mas pode 
 * ser modificada para usar uma matriz
 * Caso o grafo nao seja completo, defina a dist entre duas cidades como infinito
 * @return a dist percorrida do menor ciclo (negativo) e as cidades que fazem parte em ordem
 */

pair<double, string> solve(string ans, int visited, int k, double d) {
    int last_visited = 0;
    int sede = 0;
    if(!ans.empty()) {
        // mp2 eh um map<char, int>
        last_visited = mp2[ans[k-1]];
        sede = mp2[ans[0]];
    }

    // m eh a qtd de cidades que farao parte do tour
    if(k==m) {
        double res = d + dist(graph[last_visited], graph[sede]);
        return dp[last_visited][visited] = {-res, ans};
    }
    
    pair<double, string> temp_ans = {double(-INT_MAX), ""};
    for(int i=0; i<n; i++) {
        if(!(visited & (1 << i))) {
            // marca a cidade i como visitada
            int n_visited = visited | (1 << i);

            // mp1 eh um map<int, char>
            ans += mp1[i];

            double distance = d;
            if(k>0)
                distance += dist(graph[last_visited], graph[i+1]);

            // comp eh a funcao de comparacao que define a melhor solucao      
            pair<double, string> temp = solve(ans, n_visited, k+1, distance);
            bool compared = (!comp(temp_ans, temp));
            
            if(compared) temp_ans = temp;

            // marca a cidade i como nao visitada
            ans.pop_back();
        }
    }

    // armazena o melhor trajeto
    return dp[last_visited][visited] = temp_ans;
}