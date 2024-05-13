#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca respons�vel por cuidar das string's

int registrar(){
	//inicio de criacao de variaveis/string's
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informacao do usuario
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);//respons�vel por copiar os valores das string's
	
	FILE *file;
	file = fopen(arquivo, "w");//cria o arquivo / "w" significa escrever
	fprintf(file, cpf);// salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//adiciona no final do arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	system("cls");
	
	printf("\tUsu�rio registrado com sucesso!\n");
	
	system("pause");
}

int consultar(){
	
	setlocale(LC_ALL, "Portuguese");//definindo linguagem
	
	char cpf[40];
	char conteudo[400];
	char *token;
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	system("cls");
	
	if(file == NULL){
		printf("N�o foi poss�vel localizar o arquivo!\n");
	}
	
	while(fgets(conteudo, 400, file) != NULL){
		printf("Essas s�o as informa��es do usu�rio:\n\n");
		
		token = strtok(conteudo, ",");//define a string de entrada e o delimitador
		printf("CPF: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Nome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Sobrenome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Cargo: %s\n", token);
		
	}
	file = fclose(file);
	system("pause");
	
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
 if (file == NULL){
		system("cls");
		printf("\tUsu�rio deletado com sucesso!\n");
	}else{
		system("cls");
		printf("\tN�o foi poss�vel deletar o usu�rio.\n");
	}
	fclose(file);
	system("pause");

}

int main(){
	int opcao=0; //definindo vari�veis
	
	int x=1;
	
	for(x=1;x=1;){//definindo repeti��o do menu
		
		system("cls");//limpando tela do programa
		
    	setlocale(LC_ALL, "Portuguese");//definindo linguagem
    	
    	printf("###Cart�rio da EBAC###\n\n");//in�cio do menu
    	printf("Escolha a op��o desejada no menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n");
    	printf("\t4 - Sair\n\n");
		printf("Op��o:");//fim do menu
    	
    	scanf("%d", &opcao);//armazenando a escolha do usu�rio
    	
    	system("cls");//limpando tela do programa
    	
    	switch(opcao){//in�cio da sele��o
    		case 1:
    			registrar();
    			break;
    		
    		case 2:
    			consultar();
				break;
			
			case 3:
				deletar();
				break;
				
			case 4:
				printf("\t Obrigado por utilizar o programa!");
				return 0;
				break;
			
			default:
				printf("\tEssa op��o n�o est� dispon�vel\n\n");
				system("pause");
    		
		}//fim da sele��o
	}
}
