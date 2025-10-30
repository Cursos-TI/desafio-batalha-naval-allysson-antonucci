#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


    // ---------- Início do desafio Tema 5: Aventureiro ---------- //
    
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Letras para as colunas do tabuleiro
    int tabuleiro[10][10];
    
    // Variável para verificar se é possível adicionar os navios no tabuleiro:
    
    int podePosicionar = 0; // (0: Não ; 1 = Sim)
    
    // Variáveis para dizer se o navio está no tabuleiro (0: Não ; 1 = Sim):
    
    int navioHorizontalPosicionado = 0; 
    int navioVerticalPosicionado = 0;
    int navioDiagonalPosicionado = 0;
    
    // Iniciando o tabuleiro (valores iniciais = 0)
    
    void inicioTabuleiro() {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++) {            
                tabuleiro[i + 1][j + 1] = 0;  
            }
        }
    }
    
    // Função que posiciona o navio na horizontal:
    
    void posicionarNavioHorizontal(int linha, int coluna) {
        podePosicionar = 1; // Começamos atribuindo verdadeiro e vamos testar para ver se o navio pode realmente ser posicionado
        
        for(int i = 0; i < 3; i++) {
            if(coluna >= 8 || tabuleiro[linha][coluna + i] == 3) { // Verifica se o navio pode ser colocado na horizontal (Se coluna >= 8 então não terá espaço) e se o navio não sobrepõe outro navio já posto no tabuleiro
                podePosicionar = 0; 
                break; // interrompe imediatamente a execução do loop
            }
        }
        
        if(podePosicionar == 1) {
            for(int i = 0; i < 3; i++) {
                tabuleiro[linha][coluna + i] = 3; // Substitui o valor do elemento do tabuleiro por 3 para marcar como posição ocupada pelo navio (coluna + i pois muda na horizontal)
            }
            
            navioHorizontalPosicionado = 1;
        } else {
            navioHorizontalPosicionado = 0; // Garante que se não poder posicionar o próximo navio, a variável volte a ser 0, caso contrário, se o primeiro navio for posicionado e o segundo não puder, a variável continua sendo 1, ao invés de 0;
        }
    }
    
    // Função que posiciona o navio na vertical:
    
    void posicionarNavioVertical(int linha, int coluna) {
        podePosicionar = 1; // Começamos atribuindo verdadeiro e vamos testar para ver se o navio pode realmente ser posicionado
        
        for(int i = 0; i < 3; i++) {
            if(linha >= 8 || tabuleiro[linha + i][coluna] == 3) { // Verifica se o navio pode ser colocado na vertical (Se linha >= 8 então não terá espaço) e se o navio não sobrepõe outro navio já posto no tabuleiro
                podePosicionar = 0; 
                break; // interrompe imediatamente a execução do loop
            }
        }
        
        if(podePosicionar == 1) {
            for(int i = 0; i < 3; i++) {
                tabuleiro[linha + i][coluna] = 3; // Substitui o valor do elemento do tabuleiro por 3 para marcar como posição ocupada pelo navio (linha + i pois muda na vertical)
            }
            
            navioVerticalPosicionado = 1;
        } else {
            navioVerticalPosicionado = 0; // Garante que se não poder posicionar o próximo navio, a variável volte a ser 0, caso contrário, se o primeiro navio for posicionado e o segundo não puder, a variável continua sendo 1, ao invés de 0;
        }
    }
    
    // Função que posiciona o navio na diagonal:
    
    void posicionarNavioDiagonal(int linha, int coluna) {
        podePosicionar = 1; // Começamos atribuindo verdadeiro e vamos testar para ver se o navio pode realmente ser posicionado
        
        for(int i = 0; i < 3; i++) {
            if(linha + i >= 10 || coluna + i >= 10 || tabuleiro[linha + i][coluna + i] == 3) { // Verifica se o navio pode ser colocado na diagonal (Se linha >= 8 e coluna >= 8 então não terá espaço) e se o navio não sobrepõe outro navio já posto no tabuleiro
                podePosicionar = 0;
                break; // interrompe imediatamente a execução do loop
            } 
        }
        
        if(podePosicionar == 1) {
            for(int i = 0; i < 3; i++) {
                tabuleiro[linha + i][coluna + i] = 3; // Substitui o valor do elemento do tabuleiro por 3 para marcar como posição ocupada pelo navio (linha + i, coluna + i pois muda na diagonal)
            }
            
            navioDiagonalPosicionado = 1;
        } else {
            navioDiagonalPosicionado = 0; // Garante que se não poder posicionar o próximo navio, a variável volte a ser 0, caso contrário, se o primeiro navio for posicionado e o segundo não puder, a variável continua sendo 1, ao invés de 0;
        }
        
    }
    
    // Exibir tabuleiro atualizado
    
    void exibirTabuleiroFinal() {
        printf ("----- TABULEIRO BATALHA NAVAL -----\n\n");
        printf("    "); 
        
        for (int i = 0; i < 10; i++)
        {            
            printf("%c ", linha[i]); // Imprime as letras das colunas
        }  
        
        printf("\n");  
        
        for (int i = 0; i < 10; i++)
        {   
            printf("\n");
            printf(" %2d ", i + 1); // Imprime a coluna 0 da tabela contendo os números de 1 a 10
            
            // Imprime o tabuleiro:
            
            for (int j = 0; j < 10; j++)
            {
                printf("%d ", tabuleiro[i][j]); 
            }
            
        }
    } 
    
    
    

int main()
{
    inicioTabuleiro();
    
    // Posiciona os navios no tabuleiro:
    
    posicionarNavioHorizontal(0,7);
    posicionarNavioVertical(7,4);
    posicionarNavioDiagonal(1,2);
    posicionarNavioDiagonal(7,7);
    
    
    // Exibir tabuleiro se as posições dos navios estiverem corretas:
    
    if(navioHorizontalPosicionado == 1 && navioVerticalPosicionado == 1 && navioDiagonalPosicionado == 1) {
        exibirTabuleiroFinal();
    } else {
        printf("Não é possível adicionar os navios no tabuleiro. Verifique suas coordenadas!");
    }
    
    return 0;
}
