#include <stdio.h>
#include <stdlib.h>
void MatrizInicial();
int Cond_Vitoria (char mat[][3], int linha, int coluna, char peca);

int main(int argc, char const *argv[])
{   
    //declaração de variaveis
    char Matriz[3][3], piece;
    int fimjogo = 0, turno = 1, posicao,i,j, jogada = 0, validacao;
    //setar Matriz
    for (i = 0; i <= 3; i++)
    {   for (j = 0; j <= 3; j++)
        {
            Matriz[i][j] = ' ';
        }
    }
    // gerar matriz inicial e StarGame
    printf("  Jogo da Velha!\n");
    MatrizInicial();
    printf("\n");
    system("pause");
    system("cls");
    // Inicio do Jogo
    printf("\t  O JOGO COMECOU!\n");
    while(turno < 10 || fimjogo == 0)
    {   
        system("cls");
        //Checagem de Peça
        if (turno % 2 == 1)
        {
            piece = 'X';
        }
        else
        {
            piece = 'O';
        }
        // Atualizar Matriz
        printf("\t  Vez do Jogador %c\n", piece);
        posicao = 1;
        for (i=0; i < 3; i++)
        {   for (j = 0; j < 3; j++)
            {
                if (Matriz[i][j] == ' ')
                {
                    printf("\t|%d|", posicao);
                    posicao++;
                }
                else
                {
                    printf("\t|%c|", Matriz[i][j]);
                    posicao++;
                }
                
            }
            printf(" \n") ;
        }
        // Fazer Jogada
        printf("Onde deseja fazer a jogada: \n");
        scanf("%d", &jogada);
        //Validacao de Jogada
        validacao = 0;
        while (validacao == 0)
        {
            switch (jogada)
            {
                case 1:
                    if (Matriz[0][0] == ' ')
                    {
                        Matriz[0][0] = piece;
                        validacao = 1;
                    }
                    else
                    {   
                        validacao = 0;
                    }
                    break;
                case 2:
                    if (Matriz[0][1] == ' ')
                    {
                        Matriz[0][1] = piece;
                        validacao = 1;
                    }
                    else
                    {   
                        validacao = 0;
                    }
                    break;
                case 3:
                    if (Matriz[0][2] == ' ')
                    {
                        Matriz[0][2] = piece;
                        validacao = 1;
                    }
                    else
                    {   
                        validacao = 0;
                    }
                    break;
                case 4:
                    if (Matriz[1][0] == ' ')
                    {
                        Matriz[1][0] = piece;
                        validacao = 1;
                    }
                    else
                    {   
                        validacao = 0;
                    }
                    break;
                case 5:
                    if (Matriz[1][1] == ' ')
                    {
                        Matriz[1][1] = piece;
                        validacao = 1;
                    }
                    else
                    {   
                        validacao = 0;
                    }
                    break;
                case 6:
                    if (Matriz[1][2] == ' ')
                    {
                        Matriz[1][2] = piece;
                        validacao = 1;
                    }
                    else
                    {   
                        validacao = 0;
                    }
                    break;
                case 7:
                    if (Matriz[2][0] == ' ')
                    {
                        fflush(stdin);
                        Matriz[2][0] = piece;
                        validacao = 1;
                    }
                    else
                    {   
                        validacao = 0;
                    }
                    break;
                case 8:
                    if (Matriz[2][1] == ' ')
                    {
                        Matriz[2][1] = piece;
                        validacao = 1;
                    }
                    else
                    {   
                        validacao = 0;
                    }
                    break;
                case 9:
                    if (Matriz[2][2] == ' ')
                    {
                        Matriz[2][2] = piece;
                        validacao = 1;
                    }
                    else
                    {   
                        validacao = 0;
                    }
                    break;
                default:
                    printf("Jogada Invalida! A posicao escolhida nao existe, tente novamente!\n");
                    scanf("%d", &jogada);
                    break;
            }
            if (validacao == 0)
                {
                    fflush(stdin);
                    printf("Jogada Invalida! A posicao ja foi escolhida antes, tente novamente!\n");
                    scanf("%d", &jogada);
                }
        }
        // Condições de Vitoria
         fimjogo = Cond_Vitoria(Matriz, 3, 3, piece);
         //se fimjogo vale 1 forçar o turno valer mais que 9
         if(fimjogo == 1){
            turno = turno + 9;
         }
        //virada de turno
        turno++;
        
    }
    system("cls");
    //atualizar tabela final
    printf("\t  Vez do Jogador %c\n", piece);
        posicao = 1;
        for (i=0; i < 3; i++)
        {   for (j = 0; j < 3; j++)
            {
                if (Matriz[i][j] == ' ')
                {
                    printf("\t|%d|", posicao);
                    posicao++;
                }
                else
                {
                    printf("\t|%c|", Matriz[i][j]);
                    posicao++;
                }
                
            }
            printf(" \n") ;
        }
    if (turno == 10){
        printf("DEU VELHA!!\n");
    }
    if (fimjogo == 1){
        printf("Vitoria do jogador %c\n", piece);
    }
    system("pause");
    return 0;
    
}
void MatrizInicial()
{
    int i,j, posicao = 1;
    for (i=0; i < 3; i++)
    {   for (j = 0; j < 3; j++)
        {
            printf("  |%d|", posicao);
            posicao = posicao + 1;
        }
        printf(" \n") ;
    }
}

int Cond_Vitoria (char mat[][3],int linha, int coluna, char peca)
{

    int i,win;
    // chegagem de linhas
    for (i = 0; i < 3; i++){
        if (mat[0][i] == peca){
            win++;
        }   
    }
    if (win == 3){

        return 1;
    }
    else{
        win = 0;
    }
    for (i = 0; i < 3; i++){
        if (mat[1][i] == peca){
            win++;
        }   
    }
    if (win == 3){

        return 1;
    }
    else{
        win = 0;
    }
    for (i = 0; i < 3; i++){
        if (mat[2][i] == peca){
            win++;
        }   
    }
    if (win == 3){

        return 1;
    }
    else{
        win = 0;
    }
    // checagem de colunas
    for (i = 0; i < 3; i++){
        if (mat[i][0] == peca){
            win++;
        }   
    }
    if (win == 3){

        return 1;
    }
    else{
        win = 0;
    }
    for (i = 0; i < 3; i++){
        if (mat[i][1] == peca){
            win++;
        }   
    }
    if (win == 3){

        return 1;
    }
    else{
        win = 0;
    }
    for (i = 0; i < 3; i++){
        if (mat[i][2] == peca){
            win++;
        }   
    }
    if (win == 3){

        return 1;
    }
    else{
        win = 0;
    }
    //checagem de diagonais
    //principal
    for (i = 0; i < 3; i++){
        if(mat[i][i] == peca){
            win++;
        }
    }
    if (win == 3){

        return 1;
    }
    else{
        win = 0;
    }
    //secundaria
    for (i = 0; i < 3; i++){
        if(mat[i][2-i] == peca){
            win++;
        }
    }
    if (win == 3){

        return 1;
    }
    else{
        win = 0;
    }
}