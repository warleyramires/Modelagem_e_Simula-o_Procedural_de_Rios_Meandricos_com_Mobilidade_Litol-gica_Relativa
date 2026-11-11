# Resumo Técnico de Andamento — Checkpoint 2

**Projeto:** Modelagem e Simulação Procedural de Rios Meândricos com Modulação Espacial por Mobilidade Litológica Relativa  
**Artigo-base:** *Authoring and Simulating Meandering Rivers* (Paris et al., ACM TOG / SIGGRAPH Asia 2023)  
**Equipe:** Alberto Henrique, Pedro Henrique Braga e Warley Ramires  
**Orientador:** Prof. Dr. Wagner Ferreira de Barros  

---

## 1. Síntese do Estado Atual (O que já foi concluído)

- **Baseline reproduzida e isolada:** Código original importado no commit `c86c93a`, mantendo os cenários originais (`meander_simple`, `meander_terrain`, `avulsion_before` e `avulsion_after`) e preservando o comportamento inalterado quando o campo litológico está desativado.
- **Implementação da extensão litológica:** Adição de um campo escalar 2D independente $E(x,y)$ (`ScalarField2D`), amostrado por interpolação bilinear na margem externa do canal ($\mathbf{p}_i \pm \frac{w}{2}\mathbf{n}_i$ conforme o sinal da curvatura local), normalizado pela média espacial $\bar{E}$ e limitado ao intervalo $[0{,}25,\, 2{,}0]$.
- **Teste de regressão e validação numérica:** Implementado em `Meandering-rivers/Tests/lithology_regression.cpp`, comprovando paridade com a baseline para campo uniforme $E=1{,}0$ (erro máximo $L_\infty \le 10^{-9}$) e ausência de `NaN` em campos heterogêneos.
- **Benchmark comparativo automatizado:** Suite em `Meandering-rivers/Benchmarks/` com $1.200$ execuções ($3$ variantes $\times$ $4$ cenários $\times$ $100$ repetições com sementes `1234`, `4321` e `9999`), separando o custo estrutural (`modificado_neutro`) do custo da modulação litológica (`modificado_litologico`).
- **Artigo em $\text{\LaTeX}$ no template oficial:** Estrutura completa criada em `Checkpoint_2/Artigo_LaTeX/artigo_cg_conferencia.tex`, com a Seção 2 (*Trabalho de Referência e Trabalhos Relacionados*) finalizada e a Tabela 1 de resultados preliminares preenchida com os dados do benchmark.

---

## 2. Principais Dificuldades Técnicas Encontradas

1. **Convenção de eixos e indexação em `ScalarField2D`:**
   - Na implementação original dos autores (`Include/basics.h`), o método `GetValueBilinear()` associa o primeiro índice `i` da grade à coordenada vertical $Y$ (`v`) e o segundo índice `j` à coordenada horizontal $X$ (`u`), enquanto `Vertex(i, j)` retorna as coordenadas na ordem `(z, y, x)`.
   - Nos primeiros testes do benchmark (`plano_500` e `litologia_500`), essa convenção posicionou as faixas de contraste litológico em $|y| > 3000\,\text{m}$, fora da amplitude lateral atingida pelo canal horizontal em $500$ passos, mantendo o rio na zona central neutra ($E = 1{,}0$). Já no cenário `terreno_1200`, em que o canal percorre o eixo $Y$ de $-8500\,\text{m}$ a $+8500\,\text{m}$, o canal atravessou diretamente as faixas de resistência e reduziu a sinuosidade média de $3{,}401$ (original) para $2{,}929$ (litológico).
2. **Transição de margem externa em pontos de inflexão:**
   - Em trechos quase retilíneos onde a curvatura discreta se aproxima de zero ($|C(i)| \le 10^{-12}$), o lado externo da curva alterna entre vértices consecutivos. Para evitar descontinuidades antes da etapa de reamostragem por splines cúbicas, implementou-se a consulta bilateral nas duas margens com média aritmética das amostras válidas.
3. **Estabilidade da reamostragem cúbica sob contrastes abruptos:**
   - Valores muito elevados do fator de mobilidade podem deslocar vértices vizinhos de forma excessivamente desigual em um único passo ($\Delta t = 106$ dias). A normalização por $\bar{E}$ combinada ao intervalo `clamp(0.25, 2.0)` eliminou instabilidades geométricas, resultando em zero ocorrências de `NaN` nas $1.200$ execuções do benchmark.
4. **Representação visual do substrato nas imagens de saída (`.ppm`):**
   - A rotina original `OutputImage()` renderiza apenas o mapa de elevação ($h$) como fundo em escala de cinza. Em cenários de planície horizontal ($h = 0$), as barreiras litológicas $E(x,y)$ não ficam visíveis na imagem gerada, exigindo uma adaptação na exportação visual para sobrepor o mapa litológico ao traçado do rio nas figuras do artigo.

---

## 3. Plano Objetivo para Conclusão (Cronograma até a Apresentação Final)

| Período / Semana | Marco de Referência | Atividades Previstas | Entregáveis Principais |
| :--- | :--- | :--- | :--- |
| **Semana 1**<br>*(12/11 a 18/11)* | Pós-Checkpoint 2:<br>Ajustes Visuais e Seções Técnicas | • Ajustar a orientação das barreiras litológicas nos cenários horizontais para cruzar transversalmente o eixo $X$ do canal.<br>• Gerar imagens `.ppm`/`.png` exibindo as faixas de litologia no fundo junto à trajetória do rio.<br>• Concluir a redação definitiva das Seções 3 (*Proposta*) e 4 (*Implementação*) no $\text{\LaTeX}$. | • Novas figuras comparativas em `figures/`.<br>• Seções 3 e 4 concluídas no `artigo_cg_conferencia.tex`. |
| **Semana 2**<br>*(19/11 a 25/11)* | Consolidação Experimental e Discussão | • Extrair a contagem explícita de *cutoffs* e o comprimento de onda $\lambda$ entre pontos de inflexão por zona litológica.<br>• Atualizar os CSVs e tabelas finais com os novos cenários transversais.<br>• Redigir as Seções 5 (*Metodologia Experimental*), 6 (*Resultados*) e 7 (*Discussão*). | • Tabelas e gráficos definitivos no artigo.<br>• Seções 5, 6 e 7 concluídas. |
| **Semana 3**<br>*(26/11 a 29/11)* | **Entrega do Artigo Final (29/11/2026)** | • Redigir a Seção 1 (*Introdução*), Seção 8 (*Conclusão*) e revisar *Resumo/Abstract*.<br>• Desativar as caixas de orientação (`\mostrarorientacoesfalse`) e ajustar paginação (8 a 12 páginas).<br>• Documentar o uso de ferramentas de IA no `README.md` e sincronizar fontes `.tex`/`.bib` no GitHub. | • Submissão do PDF final do artigo.<br>• Fontes $\text{\LaTeX}$ finais no GitHub. |
| **Semana 4**<br>*(30/11 a 03/12)* | **Apresentação Final (03/12/2026)** | • Montar os slides finais com o comparativo visual e quantitativo contra a baseline.<br>• Revisar o repositório para reprodutibilidade completa e preparar a demonstração prática. | • Defesa final do projeto e demonstração executável. |
