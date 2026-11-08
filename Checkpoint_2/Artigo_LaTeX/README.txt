TEMPLATE OFICIAL DO PROJETO - ARTIGO DE COMPUTAÇÃO GRÁFICA
IFNMG - Bacharelado em Ciência da Computação - 2026/2

FORMATO
-------
O modelo adota uma diagramação compacta em duas colunas, corpo em 9 pt e
espaçamentos reduzidos, inspirada em características comuns de conferências de
Computação Gráfica como SIGGRAPH/SIGGRAPH Asia e Eurographics.

Este NÃO é o template oficial de um evento específico. Em uma futura submissão,
o artigo deverá ser migrado para o modelo oficial do evento escolhido.

EXTENSÃO
--------
8 a 12 páginas, incluindo referências.

ARQUIVOS
--------
artigo_cg_conferencia.tex  - arquivo principal
referencias.bib            - base BibTeX
figures/                   - figuras da simulação (.png)

ORIENTAÇÕES
-----------
Durante a redação, as caixas "Orientação aos autores" podem permanecer visíveis.
Antes da entrega, altere:
    \mostrarorientacoestrue
para:
    \mostrarorientacoesfalse

OVERLEAF
--------
Crie um projeto a partir do zip (Artigo_LaTeX_Overleaf.zip) ou envie
artigo_cg_conferencia.tex, referencias.bib e a pasta figures/.

COMPILAÇÃO LOCAL
----------------
pdflatex artigo_cg_conferencia.tex
biber artigo_cg_conferencia
pdflatex artigo_cg_conferencia.tex
pdflatex artigo_cg_conferencia.tex
