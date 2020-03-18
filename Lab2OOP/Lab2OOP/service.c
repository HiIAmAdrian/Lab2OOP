#include "HeaderDomain.h"
#include "HeaderRepo.h"
#include "HeaderUtils.h"

/*
parametrii: v de tip VectorDinamic*, char* criteriu("tip", "pret", "suprafata"), int ord(1 sau 2)
face o copie a lui v in care: in functie de ord si criteriu, ordoneaza lista crescator sau descrescator si dupa tip/suprafata/pret
intoarce copia ordonata in functie de parametrii
*/

VectorDinamic ordoneaza_sv(VectorDinamic* v, char* criteriu, int ord)
{
	VectorDinamic c = copyList(v);

	if (!strcmp(criteriu, "tip") && ord == 1)
		qsort(c.of, c.lg, sizeof(oferta), compareTip);
	else if (!strcmp(criteriu, "tip") && ord == 2)
		qsort(c.of, c.lg, sizeof(oferta), compareTip2);
	else if (!strcmp(criteriu, "pret") && ord == 1)
		qsort(c.of, c.lg, sizeof(oferta), comparePret);
	else if (!strcmp(criteriu, "pret") && ord == 2)
		qsort(c.of, c.lg, sizeof(oferta), comparePret2);
	else if (!strcmp(criteriu, "suprafata") && ord == 1)
		qsort(c.of, c.lg, sizeof(oferta), compareSuprafata);
	else if (!strcmp(criteriu, "suprafata") && ord == 2)
		qsort(c.of, c.lg, sizeof(oferta), compareSuprafata2);

	return c;
}

/*
parametrii: int id > 0, char* tip, char* adresa, int pret > 0, int suprafata > 0, VectorDinamic* v
creeaza o oferta din toti parametrii de mai sus si o adauga in lista de oferte
intoarce un numar pozitiv daca oferta creata nu este valida
intoarce 0 daca e valida
*/

int adauga_oferta_sv(int id, char* tip, char* adresa, int pret, int suprafata, VectorDinamic* v)
{
	oferta x = creeaza_oferta(id, tip, adresa, pret, suprafata);
	int errorCode = validate(x);
	if (errorCode)
	{
		distrugeOferta(&x);
		return errorCode;
	}
	adauga_oferta_rp(x, v);
	return 0;
}

/*
parametrii: VectorDinamic* v, int id > 0, int pret > 0
modifica pretul ofertei cu id-ul id cu pret
intoarce un numar pozitiv daca a gasit oferta id
intoarce 0 daca nu a gasit oferta id
*/

int modifica_optiune_sv(VectorDinamic* v, int id, int pret)
{
	return modifica_optiune_rp(v, id, pret);
		
}

/*
parametrii: VectorDinamic* v, int id > 0
cauta oferta cu id-ul id si o sterge din v
intoarce 1 daca oferta cu id-ul id nu este in v
intoarce 0 daca oferta cu id-ul id este in v si a fost stearsa
*/

int sterge_optiune_sv(VectorDinamic* v, int id)
{
	return sterge_optiune_rp(v, id);
}