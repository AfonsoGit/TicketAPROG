#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int i=0, j=0, natend_ent=1, natend_rep=1;

typedef struct reparacao
{
	char servico_rep;
	int numtick_rep;
	int dia_entrada_rep;
	int mes_entrada_rep;
	int ano_entrada_rep;
	int hora_entrada_rep;
	int min_entrada_rep;
	int hora_atend_rep;
	int min_atend_rep;
	int balcao_rep;
	char equip_rep;
	char obs[100];	
};
reparacao reparacao1[100];
typedef struct  entrega
{
	char servico_ent;
	int numtick_ent;
	int dia_entrada_ent;
	int mes_entrada_ent;
	int ano_entrada_ent;
	int hora_entrada_ent;
	int min_entrada_ent;
	int hora_atend_ent;
	int min_atend_ent;	
	int balcao_ent;
	char cond_ent[100];
	float valor_pagar;
};
entrega entrega1[100];

//Gerar tickets de entrega
int ticket_entrega()
{
	//entrega entrega1[100];
	int tm_mday, tm_mon, tm_year, tm_hour, tm_sec, tm_min;
	printf("\n\nTicket de Entrega\n");
	//Relogio
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	printf("%d-%d-%d %d:%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
	// verificar se o horário está entre as 8H e as 22H
	if(tm.tm_hour<8 || tm.tm_hour>=22) 
	{
		printf("\nNao pode recolher ticket. Horario: 8:00h-21:59h\n\n");
	}else
		{
		//Guardar dados no vetor
			printf("Ticket numero %d\n\n", natend_ent);
			entrega1[j].numtick_ent = natend_ent;
			entrega1[j].servico_ent = 'Entrega';
			entrega1[j].dia_entrada_ent = tm.tm_mday;
			entrega1[j].mes_entrada_ent = tm.tm_mon+1;
			entrega1[j].ano_entrada_ent = tm.tm_year + 1900;
			entrega1[j].hora_entrada_ent = tm.tm_hour;
			entrega1[j].min_entrada_ent = tm.tm_min;
			natend_ent++;
			j++;
  		}
}
//Gerar tickets de reparação
int ticket_reparacao()
{
	//reparacao reparacao1[100];
	int tm_mday, tm_mon, tm_year, tm_hour,  tm_min;
	printf("\n\nTicket de Reparacao\n");
	//Relogio
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	printf("%d-%d-%d %d:%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
	// verificar se o horário está entre as 8H e as 22H
	if(tm.tm_hour<8 || tm.tm_hour>=22) 
	{
		printf("\nNao pode recolher ticket. Horario: 8:00h-21:59h\n\n");
	}else
		{
			printf("Ticket numero %d\n\n", natend_rep);
			//Guardar dados no vetor
			reparacao1[i].numtick_rep = natend_rep;
			reparacao1[i].servico_rep = 'Reparacao';
			reparacao1[i].dia_entrada_rep = tm.tm_mday;
			reparacao1[i].mes_entrada_rep = tm.tm_mon+1;
			reparacao1[i].ano_entrada_rep = tm.tm_year + 1900;
			reparacao1[i].hora_entrada_rep = tm.tm_hour;
			reparacao1[i].min_entrada_rep = tm.tm_min;
			natend_rep++;
			i++;
   	 }
}

//Atendimento ticket reparação
int atend_reparacao()
{
	int numticket, k, balc;
	int tm_mday, tm_mon, tm_year, tm_hour, tm_sec, tm_min, verificar_ticket=0;
//	reparacao reparacao1[100];
	printf("Numero ticket reparacao: ");
	scanf("%d", &numticket);
	for(k=0;k<i;k++)
	{
		if(numticket==reparacao1[k].numtick_rep)
		{
			
			verificar_ticket=1;
			printf("%d-%d-%d %d:%d\n", reparacao1[k].dia_entrada_rep, reparacao1[k].mes_entrada_rep, reparacao1[k].ano_entrada_rep, reparacao1[k].hora_entrada_rep, reparacao1[k].min_entrada_rep);
			//Regista a hora de atendimento
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
			printf("%d-%d-%d %d:%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
			printf("Balcao: ");
			scanf("%d", &balc);
			if(balc == 4)
			{
				printf("Este balcao nao aceita tickets de reparacao\n");
			}
			if(balc == 1 || balc == 2 || balc == 3)
			{
				reparacao1[k].hora_atend_rep = tm.tm_hour;
		     	reparacao1[k].min_atend_rep = tm.tm_min;
				reparacao1[k].balcao_rep = balc;
				printf("Avaria do equipamento: ");
				scanf("%s", &reparacao1[k].equip_rep);
				printf("Observacoes:");
				scanf("%s", &reparacao1[k].obs);
		    }else 
			{
				printf("So pode escolher o balcao 1, 2 ou 3");
			}	
		}
	}
	if(verificar_ticket == 0)
	{
		printf("\nNumero de ticket nao existente\n");
	}
}

//Atendimento ticket entrega
int atend_entrega()
{
	int numticket, k, balc;
	int tm_mday, tm_mon, tm_year, tm_hour, tm_min, verificar_ticket=0;
//	entrega entrega1[100];
	printf("Numero ticket entrega: ");
	scanf("%d", &numticket);
	
	for(k=0;k<j;k++)
	{
		printf("%d",numticket);
		printf("%d",entrega1[k].numtick_ent);
		if(numticket==entrega1[k].numtick_ent)
		{
			verificar_ticket=1;
			//Relogio
			printf("%d-%d-%d %d:%d\n", entrega1[k].dia_entrada_ent, entrega1[k].mes_entrada_ent, entrega1[k].ano_entrada_ent, entrega1[k].hora_entrada_ent, entrega1[k].min_entrada_ent);
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
			printf("%d-%d-%d %d:%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
			printf("Balcao: ");
			// faz a validação do balcao
		
			scanf("%d", &balc);
		    
			if(balc == 1 || balc == 2 || balc == 3)
			{					
				printf("Valor a pagar:");
				scanf("%s", &entrega1[k].cond_ent);
				//Validar que o valor a pagar e superior a 0
				if(entrega1[k].cond_ent < 0)
				{
					printf("Valor invalido");
				}else
				{
					printf("Condições da mercadoria: ");
					scanf("%s", &entrega1[k].cond_ent);
					entrega1[k].hora_atend_ent = tm.tm_hour;
					entrega1[k].min_atend_ent = tm.tm_min;
					entrega1[k].balcao_ent = balc;	
				}
			}else 
			{
					
				printf("So pode escolher o balcao 1, 2 ou 3");
			}
	
		}   
	}
	if(verificar_ticket == 0)
	{
		printf("\nNumero de ticket nao existente\n");
	}	
}

//5. Listar todos os tickets por data
int listar_ticket()
{
	int l;
	printf("Servico de reparacao\n\n");
	l=0;
	do
	{
		printf("Ticket numero %d\n",reparacao1[l].numtick_rep);
		printf("Data/hora de entrada: %d-%d-%d %d:%d\n", reparacao1[l].dia_entrada_rep, reparacao1[l].mes_entrada_rep, reparacao1[l].ano_entrada_rep, reparacao1[l].hora_entrada_rep, reparacao1[l].min_entrada_rep);
		printf("Data/hora de atendimento: %d-&d-%d %d:%d\n", reparacao1[l].hora_atend_rep, reparacao1[l].min_atend_rep);
		printf("Balcao: %d\n", reparacao1[l].balcao_rep);
		printf("Tipo de avaria:%s\n", reparacao1[l].equip_rep);
		printf("Observacoes:%s\n\n\n", reparacao1[l].obs);
		getchar();
		l++;
	}while(l<i);

	printf("Servico de entrega\n\n");
	l=0;
	do
	{
		printf("Ticket numero %d\n",entrega1[l].numtick_ent);
		printf("Data/hora de entrada: %d-%d-%d %d:%d\n", entrega1[l].dia_entrada_ent, entrega1[l].mes_entrada_ent, entrega1[l].ano_entrada_ent, entrega1[l].hora_entrada_ent, entrega1[l].min_entrada_ent);
		printf("Data/hora de atendimento: %d-&d-%d %d:%d\n", entrega1[l].hora_atend_ent, entrega1[l].min_atend_ent);
		printf("Balcao: %d\n", entrega1[l].balcao_ent);
		printf("Condicoes da mercadoria:%s\n", entrega1[l].cond_ent);
		printf("Valor a pagar:%f\n\n\n", entrega1[l].valor_pagar);
		getchar();
		l++;
	}while(l<i);
}

int main()
{
	int opcao, tm_hour;
	/*struct reparacao x;
	struct entrega y;*/
;

	//Selecionar tipo de ticket
	printf("Software de Gestao de Tickets\n\n\n");
	printf("1-Ticket Reparacao\n2-Ticket Entrega\n3-Atendimento Reparacao\n4-Atendimento de entrega\n5-Listar todos os tickets\n6-Mapas de quantidades\n7-Mapas de medias\n8-Mapas de balcoes:\n9-Sair\n\nOpcao:");
	do
	{
		scanf("%d", &opcao);
		//Gerar tickets de reparacao
		if(opcao == 1)
		{
			ticket_reparacao();
		}
		//Gerar tickets de entrega
		if(opcao == 2)
		{
			ticket_entrega();
		}
		if(opcao == 3)
		{
			atend_reparacao();
		}
		if(opcao == 4)
		{
			atend_entrega();
		}
		if(opcao == 5)
		{
			listar_ticket();
		}
		if(opcao == 6)
		{
			
		}
		if(opcao == 7)
		{
			
		}
		if(opcao == 8)
		{
			
		}
		if(opcao == 9)
		{
			break;
		}
		system("pause");
		system("cls");
		printf("Software de Gestao de Tickets\n\n\n");
		printf("1-Ticket Reparacao\n2-Ticket Entrega\n3-Atendimento Reparacao\n4-Atendimento de entrega\n5-Listar todos os tickets\n6-Mapas de quantidades\n7-Mapas de medias\n8-Mapas de balcoes:\n9-Sair\n\nOpcao:");	
	}while(opcao!=3);
return 0;		
}
