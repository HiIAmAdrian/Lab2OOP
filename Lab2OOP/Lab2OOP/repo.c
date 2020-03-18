#include "HeaderDomain.h"

/*
parametrii:oferta x, VectorDinamic* v
adauga oferta x in lista de oferte din v
*/

void adauga_oferta_rp(oferta x, VectorDinamic* v)
{
	if (v->lg == v->capacitate)
		resizeVectorDinamic(v);
	v->of[v->lg] = x;
	v->lg++;
}

/*
parametrii: VectorDinamic* v, int id > 0, int pret > 0
modifica pretul ofertei cu id-ul id cu pret
intoarce un numar pozitiv daca a gasit oferta id
intoarce 0 daca nu a gasit oferta id
*/

int modifica_optiune_rp(VectorDinamic* v, int id, int pret)
{
	int i = 0;

	while (i < v->lg) 
	{
		if (v->of[i].id == id)
		{
			v->of[i].pret = pret;
			break;
		}
		i++;
	}
	if (i == v->lg)
		return 0;
	return 1;
}

/*
parametrii: VectorDinamic* v, int id > 0
cauta oferta cu id - ul id si o sterge din v
intoarce 1 daca oferta cu id - ul id nu este in v
intoarce 0 daca oferta cu id - ul id este in v si a fost stearsa
*/

int sterge_optiune_rp(VectorDinamic* v, int id)
{
	int i = 0;

	while (i < v->lg && v->of[i].id != id)
		i++;
	if (i == v->lg)
		return 1;
	distrugeOferta(&v->of[i]);
	v->of[i].adresa = NULL;
	v->of[i].tip = NULL;
	while (i < v->lg - 1)
	{
		v->of[i] = v->of[i + 1];
		i++;
	}
	v->lg--;

	return 0;
}