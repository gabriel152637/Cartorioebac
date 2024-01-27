#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca resposável por cuidar dos string

int registro() // função responsavel por cadastrar os usuários no sistema
{
	// inicio criação de vriaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da  criação de variaveis/string
	
	
	printf("digite o cpf a ser cadastrado: ");// coletar informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores dos string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); // cria o arquivo 
    fprintf(file,cpf); // salvar o valor da variavel 
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);

    file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);

	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);

    file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);

	
	printf("digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen (arquivo,"a");
    fprintf(file,cargo);
    fclose(file);

	system("pause");
	}

int consulta()
{
   setlocale(LC_ALL, "Portuguese"); 
   
   char cpf[40];
   char conteudo[40];
   
   printf("digite o cpf a ser consultado: ");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
   	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
   }
   
   while(fgets(conteudo, 200, file)!= NULL)
   {
   	printf("\nEssas são as informções do usuario: ");
   	printf("%s", conteudo);
   	printf("\n\n");
   }
   
   system("pause");
   
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o cpf do usuário a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usuário não se encontra no sistema!.\n");
    	system("pause");
	}
    
}


int main()  
    {
    int opcao=0; //definindo variaveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
    	
    	system("cls");
    
    
    
	setlocale(LC_ALL, "Portuguese");
	printf("### Cartório da EBAC ###\n\n");
	printf(" Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes:\n");
	printf("\t2 - Consultar nomes:\n");
	printf("\t3 - Deletar nomes:\n\n");
	printf("\t4 - Sair do sistema:\n\n");
	printf("opção:"); //fim do menu
	
	scanf("%d", &opcao); //armazenamento a escolha do usuário
	
	system("cls"); //responsavel pro limpar a tela 
	
	switch(opcao) //inicio da seleção
	{
		case 1:
		registro(); //chamda de funções
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
	    deletar();
	    break;
		
		case 4:
		printf("obrigado por utilizar esse sistema!\n");
		return 0;
		break;
		
		
		default:
		printf("essa opção não está disponivel!\n");
		system("pause");
		break;
			 
	} //fim de seleção
    }
}
	
	


