#include "HeaderDomain.h"
#include "HeaderUtils.h"
#include "HeaderRepo.h"

/*
parametrii: int id > 0, char* tip != NULL, char* adresa != NULL, int pret > 0, int suprafata > 0
Creeaza o oferta din toti parametrii
intoarce structura oferta creata
*/
oferta creeaza_oferta(int id, char* tip, char* adresa, int pret, int suprafata)
{
	oferta x;

	
	x.id = id;
	x.pret = pret;
	x.suprafata = suprafata;

	x.adresa = ft_strdup(adresa);
	x.tip = ft_strdup(tip);
	return x;
}

/*
parametrii: VectorDinamic* l
face o copie a lui l
intoarce copia
*/

VectorDinamic copyList(VectorDinamic* l) {
	VectorDinamic rez = creeazaVectorDinamic();
	for (int i = 0; i < l->lg; i++) {
		oferta p = l->of[i];
		adauga_oferta_rp(copyOferta(&p), &rez);
	}
	rez.lg = l->lg;
	rez.capacitate = l->capacitate;
	return rez;
}

/*
parametrii: structura de tip oferta x
valideaza campurile ofertei
intoarce un numar pozitiv daca cel putin una din conditii e indeplinita:
-x.adresa = 0
-x.tip = 0 sau nu este casa, apartament sau teren
-x.id < 0
-x.pret < 0
-x.suprafata < 0
intoarce 0 daca nu s-a indeplinit nicio conditie
*/

int validate(oferta x)
{
	if (strlen(x.adresa) == 0)
		return 1;
	if (strlen(x.tip) == 0 || (strcmp(x.tip, "casa") && strcmp(x.tip, "apartament") && strcmp(x.tip, "teren")))
		return 2;
	if (x.id < 0)
		return 3;
	if (x.suprafata < 0)
		return 4;
	if (x.pret < 0)
		return 5;
	return 0;
}

/*
creeaza o structura de tip VectorDinamic
intoarce structura creata
*/

VectorDinamic creeazaVectorDinamic()
{
	VectorDinamic v;
	v.of = malloc(INIT_CAPACITY * sizeof(oferta));
	v.capacitate = INIT_CAPACITY;
	v.lg = 0;

	return v;
}

/*
parametrii: x care este de tip oferta*
elibereaza memoria ocupata de x si campurile sale
*/

void distrugeOferta(oferta *x)
{
	free(x->adresa);
	free(x->tip);
	x->adresa = NULL;
	x->tip = NULL;
	x->pret = -1;
	x->suprafata = -1;
	x->id = -1;
}

/*
parametrii: v de tip VectorDinamic*
elibereaza memoria ocupata de v si campurile sale
*/

void distrugeVectorDinamic(VectorDinamic* v)
{
	int i;

	for (i = 0; i < v->lg; i++)
		distrugeOferta(&v->of[i]);
	free(v->of);
	v->of = NULL;
	v->lg = 0;
}

/*
parametrii: v de tip VectorDinamic*
redimensioneaza campul vector v->of din v astfel incat sa incapa noi elemente
*/

void resizeVectorDinamic(VectorDinamic* v)
{
	int nCap = FACTOR_MUL * v->capacitate, i;
	oferta* nX = malloc(nCap * sizeof(oferta));

	for (i = 0; i < v->lg; i++)
		nX[i] = v->of[i];
	free(v->of);
	v->of = nX;
	v->capacitate = nCap;
}

/*
parametrii: char* criteriu
intoarce 1 daca  criteriul nu este "pret", "tip" sau "suprafata"
intoarce 0 daca este cel putin una
*/

int validare_criteriu(char* criteriu)
{
	if (strcmp(criteriu, "pret") && strcmp(criteriu, "tip") && strcmp(criteriu, "suprafata"))
		return 1;
	return 0;
}

/*
parametrii: VectorDinamic* l, int poz
intoarce oferta de pe pozitia poz din l
*/

oferta get(VectorDinamic* l, int poz) 
{
	return l->of[poz];
}

/*
parametrii: VectorDinamic* l, int poz, oferta p
pune oferta p in pozitia poz in vectorul l
intoarce oferta
*/

oferta set(VectorDinamic* l, int poz, oferta p) 
{
	oferta rez = l->of[poz];
	l->of[poz] = p;
	return rez;
}

/*
parametrii: p de tip oferta*
face o copie a lui p
intoarce copia lui p
*/

oferta copyOferta(oferta* p)
{
	return creeaza_oferta(p->id, p->tip, p->adresa, p->pret, p->suprafata);
}