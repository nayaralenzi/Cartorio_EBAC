#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro () { // Fun�ao respons�el por cadastrazr os usu�rios no sistema
	setlocale(LC_ALL, "Portuguese");
		
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando a informa��o do usu�rio
	scanf("%s", cpf); //%s se refere a string

	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf);  //salvo o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}


int consulta () {
	
   	setlocale(LC_ALL, "Portuguese");
		
   	char cpf [40];
   	char conteudo[200];
   	
   	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
		
	}   
   
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	system("pause");
   
}

int deletar() {


	char cpf [40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf,"r");


	if (file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	else {
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");	
	}
} 


int main () 
{	
	
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
	
		system("cls"); //limpar a tela, retorna o menu 
		
		setlocale(LC_ALL, "Portuguese");
		
		
		printf(" #### Cart�rio da EBAC #### \n\n"); //in�cio do menu
		printf ("Escolha a op��o desejada do menu: \n \n");
		printf ("\t 1 - Registrar nomes\n");
		printf("\t 2 - Consultar nomes\n");
		printf("\t 3 - Deletar nomes\n");
		printf("\t 4 - Sair do Sistema\n\n"); 
		printf("Op��o: "); //fim do menu
		
		scanf("%d", &opcao); //armazenamento e escolha do usu�rio
		
		system("cls");
		
		switch(opcao) { //inicio da sele��o
			case 1: 
				registro(); // chamada de fun��es
			break; 
			
			case 2: 
				consulta();
			break; 
			
			case 3: 
				deletar();
			break; 
			
			case 4: 
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
			break; 
			
			
			default:
				printf("Esta op��o n�o est� dispon�vel \n");
				system("pause");
			break; 
		}  //fim da sele��o
			
	} 
}
