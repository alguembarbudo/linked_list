	/*Atividade Supervisionada			*
	 *Gabriel Dias Alonso - 841			*
	 *Estrutura de Dados - Soraia Alves	*
 	 *Dev-C++ 5.11 						*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Definição de estrutura ******************************************
typedef struct no{
 	int dado;
 	struct no *prox;} no; 

 //Inicio de lista ************************************************
no* inicio = NULL;

//Definição de lista vazia ****************************************
cria_lista(){
		inicio = NULL;}

//Cria nó *********************************************************
no* cria_no(int dado){
	no *aux;
	aux = (no *) malloc(sizeof(no));
	if (aux == NULL){
		printf ("\nSem memória disponivel.\n");
		return NULL;}
	aux -> dado = dado;
	aux -> prox = NULL;
	return aux;}

//Insere no início ************************************************
insere_inicio(int dado){
	no *aux;
	aux = cria_no(dado);
	if (inicio == NULL)
		inicio = aux;
	else{
		aux -> prox = inicio;
		inicio = aux;}}

//Insere no fim ***************************************************
insere_fim(int dado){
	no *aux, *p;
	aux = cria_no(dado);
	p = inicio;
	while (p -> prox != NULL)
           p = p -> prox;
    p -> prox = aux;}

//Exibe a lista ***************************************************
exibe_lista() {
	no *aux;
	aux = inicio;
 	while (aux != NULL) {
		printf ("%3d",aux -> dado);
		aux = aux -> prox;}}

//Remove do início ************************************************
no *remove_inicio(){
		no *aux;
		aux = inicio;
		inicio = inicio -> prox;
		return aux;
		free (aux);}
	
		
//Remove do fim ***************************************************
no *remove_fim(no *inicio){
	no *aux = inicio -> prox, *p = inicio;
	while (aux -> prox != NULL){
		p = aux;
		aux = aux -> prox;}
p -> prox = NULL;
return aux;
free (aux);}

//Verifica se lista está vazia ************************************
lista_vazia(){
	if (inicio == NULL)
		printf ("Lista vazia!");}

//Corpo do programa ***********************************************
main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int resp=1, num=0;
	
	no *aux;
	
	cria_lista();
	
	while (resp){
		
		system ("cls");
		
		printf ("Atividade Supervisionada\n");
		printf ("Gabriel Dias Alonso - 841\n");
		printf ("Estrutura de Dados - Soraia Alves\n\n");
		
		if (lista_vazia())
			exibe_lista();
		
		printf ("\n\n[1] Inserir elemento no Início.");
		printf ("\n[2] Inserir elemento no Fim.");
		printf ("\n[3] Retirar elemento no Início.");
		printf ("\n[4] Retirar elemento no Fim.");
		printf ("\n[5] Inserir números aleatórios.");
		printf ("\n[6] Limpar lista.");
		printf ("\n[7] Sair\n");
		
		printf ("\nOpção:  ");
       	scanf ("%d",&resp);
       	       	
       	switch (resp){
       		
			case 1:
				printf ("\nNúmero a ser inserido no início: ");
				scanf ("%d",&num);
    			insere_inicio(num);
    			printf ("\nNúmero %d inserido com sucesso.\n\n",num);
    			system ("pause");
				break;
				
			case 2:
				printf ("\nNúmero a ser inserido no fim: ");
				scanf ("%d",&num);
    			insere_fim(num);
    			printf ("\nNúmero %d inserido com sucesso.\n\n",num);
    			system ("pause");
				break;
    		
			case 3:
				if (lista_vazia()){
					printf ("\n");
					system ("pause");
					break;}
				else{
					aux = remove_inicio();
					printf ("\nNúmero %d removido do inicio.\n\n",aux -> dado);
					system ("pause");
					break;}
			
			case 4: 
				if (lista_vazia()){
					printf ("\n");
					system ("pause");
					break;}
				else{
					aux = remove_fim(inicio);
					printf ("\nNúmero %d removido do fim.\n\n",aux -> dado);
					system ("pause");
					break;}
					
			case 5:
				for (int i=1; i<=10; i++)
      				insere_inicio(i*2);
				break;
			
			case 6:
				cria_lista();
				break;;
			
			case 7:
				exit(0);
			
			default:
				printf ("\nComando inválido.\n\n");
				system ("pause");
				break;}}}
