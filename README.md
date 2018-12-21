

#include <stdio.h>
#include <string.h>
#include <time.h>


struct cliente
{
	char nome[100];
	char servico[100];
};

int dados()
{
	struct cliente x;
	char id, serv;
	printf("Nome do cliente:");
	scanf("%[^\t\n]s", &id);
	printf("Servico:");
	scanf("%s", &serv);
	//Passar id e serv para a estrutura acima (nome e servico, respetivamente)
}

int main()
{
	int tm_hour;
	 
	
	dados();
	
	switch()
	{
		case 'Reparação':
			{
			
				break;
			}
		case 'Entrega':
			{
			
				break;
			}
		default: a = 0;
	}
	
	
	
	
	if(tm_hour==22) //Caso a hora seja 22
		{
			printf("Não pode recolher mais nenhum ticket");
		}
	
		
}
