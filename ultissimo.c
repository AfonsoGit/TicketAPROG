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
struct reparacao reparacao1[100];
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
struct entrega entrega1[100];

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
  		return j;
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
return i;
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
		    
			if(balc == 1 || balc == 2 || balc == 3 || balc == 4)
			{					
				printf("Valor a pagar:");
				scanf("%f", &entrega1[k].valor_pagar);
				//Validar que o valor a pagar e superior a 0
				if(entrega1[k].valor_pagar < 0)
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
	int l,m;
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
	m=0;
	do
	{
		printf("Ticket numero %d\n",entrega1[m].numtick_ent);
		printf("Data/hora de entrada: %d-%d-%d %d:%d\n", entrega1[m].dia_entrada_ent, entrega1[m].mes_entrada_ent, entrega1[m].ano_entrada_ent, entrega1[m].hora_entrada_ent, entrega1[m].min_entrada_ent);
		printf("Data/hora de atendimento: %d-&d-%d %d:%d\n", entrega1[m].hora_atend_ent, entrega1[m].min_atend_ent);
		printf("Balcao: %d\n", entrega1[m].balcao_ent);
		printf("Tipo de avaria:%s\n", entrega1[m].valor_pagar);
		printf("Observacoes:%s\n\n\n", entrega1[m].cond_ent);
		getchar();
		m++;
	}while(m<j);
}

int mapa_quantidades()
{
	int quant;
	quant = i + j;
	printf("Foram criados no dia de hoje %d tickets\n",quant);
return quant;
}
int mapa_medias()
{
	int minutos,minutosr, horas,horasr, minutose, horase, y, media_rep,media_ent,tempoespera_ent, tempoespera_rep, w, total, totalmedia;
	y = 0;
	horasr = 0;
	minutosr = 0;
	tempoespera_rep = 0;
	do{
	horas = reparacao1[y].hora_atend_rep - reparacao1[y].hora_entrada_rep;
	horasr = (horas * 60);
	tempoespera_rep = tempoespera_rep + (horasr + reparacao1[y].min_atend_rep) - reparacao1[y].min_entrada_rep;
	y++;
}while(y<i);
minutose = 0;
w = 0;
horas = 0;
horase = 0;
tempoespera_ent = 0;
do{
	horas = entrega1[w].hora_atend_ent - entrega1[w].hora_entrada_ent;
	horase = (horas * 60);
	tempoespera_ent = tempoespera_ent + (horase + entrega1[w].min_atend_ent) - entrega1[w].min_entrada_ent;
	w++;
}while(w<j);
media_rep = tempoespera_rep / y;
media_ent = tempoespera_ent / w;
total = tempoespera_rep + tempoespera_ent;
totalmedia = (media_rep + media_ent) / 2;
printf("O total de minutos de espera dos tickets de reparacao foi de %d minutos\n",tempoespera_rep);
printf("O total de minutos de espera dos tickets de entrega foi de %d minutos\n",tempoespera_ent);
printf("O total de minutos de espera da loja foi de %d\n",total);
printf("A média de minutos de espera dos tickets de reparacao foi de %d minutos\n",media_rep);
printf("A média de minutos de espera dos tickets de entrega foi de %d minutos\n",media_ent);
printf("A média de minutos de espera da loja foi de %d\n",totalmedia);
}

int mapa_balcoes()
{

    int n, balcao1, balcao2, balcao3, balcao4;
    n=0;
    balcao1 = 0;
    balcao2 = 0;
    balcao3 = 0;
    balcao4 = 0;
  do {
	if (entrega1[n].balcao_ent == 1)
	{balcao1++;
	n++;
	}else
	{if (entrega1[n].balcao_ent == 2){
	balcao2++;
	n++;
	}else
	{if (entrega1[n].balcao_ent == 3)
	{balcao3++;
	n++;
	}
	else{
	if (entrega1[n].balcao_ent == 4){
	balcao4++;
	n++;}
	}
	}
	}
}while (n<j);
n = 0;
do {
	if (reparacao1[n].balcao_rep == 1)
	{balcao1++;
	n++;
	}else
	{if (reparacao1[n].balcao_rep == 2){
	balcao2++;
	n++;
	}else
	{if (reparacao1[n].balcao_rep == 3)
	{balcao3++;
	n++;
	}
	else{
	if (reparacao1[n].balcao_rep == 4){
	balcao4++;
	n++;}
	}
	}
	}
}while (n<i);
printf("Balcao 1 : %d\nBalcao 2 : %d\nBalcao 3 :%d\nBalcao 4 : %d\n",balcao1, balcao2, balcao3,balcao4);
	
	
}
int receitas(){
	float receitas, media;
	int t;
	receitas = 0;
	t=0;
	for(t=0;t<j;t++){
		receitas = receitas + entrega1[t].valor_pagar;
	}
	media = receitas / j;
printf("O total de receitas foi de %f euros.\n e a media foi de %f",receitas, media);
}
int main()
{
	int opcao, tm_hour;
	/*struct reparacao x;
	struct entrega y;*/
;

	//Selecionar tipo de ticket
	printf("Software de Gestao de Tickets\n\n\n");
	printf("1-Ticket Reparacao\n2-Ticket Entrega\n3-Atendimento Reparacao\n4-Atendimento de entrega\n5-Listar todos os tickets\n6-Mapas de quantidades\n7-Mapas de medias\n8-Mapas de balcoes\n9-Receitas\n10-Sair\n\nOpcao:");
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
			mapa_quantidades();
		}
		if(opcao == 7)
		{
			mapa_medias();
		}
		if(opcao == 8)
		{
			mapa_balcoes();
		}
		if(opcao == 9)
		{
			receitas();
		}
		if(opcao == 10)
		{
			break;
		}
		system("pause");
		system("cls");
		printf("Software de Gestao de Tickets\n\n\n");
		printf("1-Ticket Reparacao\n2-Ticket Entrega\n3-Atendimento Reparacao\n4-Atendimento de entrega\n5-Listar todos os tickets\n6-Mapas de quantidades\n7-Mapas de medias de espera\n8-Mapas de balcoes\n9-Receitas\n10-Sair\n\nOpcao:");	
	}while(opcao!=9);
return 0;		
}

