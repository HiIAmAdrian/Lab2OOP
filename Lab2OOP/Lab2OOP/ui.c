#include "HeaderService.h"
#include "HeaderDomain.h"
#include "HeaderTeste.h"

void print_menu()
{
	printf("1. Adauga o oferta noua.\n");
	printf("2. Modifica o oferta.\n");
	printf("3. Listeaza ofertele.\n");
	printf("4. Sterge o oferta.\n");
	printf("5. Ordoneaza lista.\n");
	printf("0. EXIT.\n");
}

void ui_add_optiune(VectorDinamic* v)
{
	int id, pret, suprafata;
	char adresa[100], tip[20];

	printf("\nIntroduceti id:");
	scanf("%d", &id);
	printf("\nIntrodceti tip:");
	scanf("%s", tip);
	printf("\nIntroduceti adresa:");
	scanf("%s", adresa);
	printf("\nIntroduceti pret:");
	scanf("%d", &pret);
	printf("\nIntroduceti suprafata:");
	scanf("%d", &suprafata);

	int error = adauga_oferta_sv(id, tip, adresa, pret, suprafata, v);
	if (error)
		printf("Oferta invalida!\n");
}

void ui_modifica_optiune(VectorDinamic* v)
{
	int id, pret;

	printf("Introdu id:");
	scanf("%d", &id);
	printf("Introdu noul pret:");
	scanf("%d", &pret);
	if (pret < 0)
	{
		printf("Pret invalid!\n");
		return;
	}
	if (!modifica_optiune_sv(v, id, pret))
		printf("Oferta nu exista in baza de date!\n");
}

void ui_sterge_oferta(VectorDinamic* v)
{
	int id;

	printf("Introdu id-ul ofertei de sters: ");
	scanf("%d", &id);
	if (sterge_optiune_sv(v, id))
		printf("Id invalid/nu este in baza de date!\n");
}

void ui_print_optiuni(VectorDinamic* v)
{
	int i = 0;

	while (i < v->lg)
	{
		printf("OPTIUNEA ID: %d\n", v->of[i].id);
		printf("Tip: %s\n", v->of[i].tip);
		printf("Suprafata: %d\n", v->of[i].suprafata);
		printf("Adresa: %s\n", v->of[i].adresa);
		printf("Pret: %d\n", v->of[i].pret);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		i++;
	}
}

void ui_ordoneaza(VectorDinamic* v)
{
	int ord;
	char criteriu[30];

	printf("Criteriu de filtrare?(tip, suprafata, pret):\n");
	scanf("%s", criteriu);
	if (validare_criteriu(criteriu))
	{
		printf("Criteriu invalid!\n");
		return;
	}
	printf("1.Crescator sau 2. Descrescator?");
	scanf("%d", &ord);
	if (ord != 1 && ord != 2)
	{
		printf("Criteriu invalid!\n");
		return;
	}
	VectorDinamic c = ordoneaza_sv(v, criteriu, ord);
	ui_print_optiuni(&c);
	distrugeVectorDinamic(&c);
}

void run()
{
	int optiune;
	VectorDinamic v = creeazaVectorDinamic();

	do
	{
		print_menu();
		scanf("%d", &optiune);
		switch (optiune)
		{
		case 0:
			break;
		case 1:
			ui_add_optiune(&v);
			break;
		case 2:
			ui_modifica_optiune(&v);
			break;
		case 3:
			ui_print_optiuni(&v);
			break;
		case 4:
			ui_sterge_oferta(&v);
			break;
		case 5:
			ui_ordoneaza(&v);
			break;
		default:
			printf("Comanda invalida!\n");
			break;
		}
	} while (optiune);
	distrugeVectorDinamic(&v);
}

int main()
{
	teste();
	//run();
	_CrtDumpMemoryLeaks();
	return 0;
}