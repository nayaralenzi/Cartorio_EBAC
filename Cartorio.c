#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro () { // Funçao responsáel por cadastrazr os usuários no sistema
	setlocale(LC_ALL, "Portuguese");
		
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando a informação do usuário
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
		printf("Não foi possível abrir o arquivo, não localizado!. \n");
		
	}   
   
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas são as informações do usuário: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	system("pause");
   
}

int deletar() {


	char cpf [40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen (cpf,"r");


	if (file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
	else {
		printf("Usuário deletado com sucesso!\n");
		system("pause");	
	}
} 


int main () 
{	
	
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
	
		system("cls"); //limpar a tela, retorna o menu 
		
		setlocale(LC_ALL, "Portuguese");
		
		
		printf(" #### Cartório da EBAC #### \n\n"); //início do menu
		printf ("Escolha a opção desejada do menu: \n \n");
		printf ("\t 1 - Registrar nomes\n");
		printf("\t 2 - Consultar nomes\n");
		printf("\t 3 - Deletar nomes\n");
		printf("\t 4 - Sair do Sistema\n\n"); 
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao); //armazenamento e escolha do usuário
		
		system("cls");
		
		switch(opcao) { //inicio da seleção
			case 1: 
				registro(); // chamada de funções
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
				printf("Esta opção não está disponível \n");
				system("pause");
			break; 
		}  //fim da seleção
			
	} 
}
