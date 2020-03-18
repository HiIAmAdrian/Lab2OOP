#include "HeaderDomain.h"

/*
parametrii: const char* s1
face o copie in memorie a stringu-ului s1
intoarce copia lui s1
*/

char* ft_strdup(const char* s1)
{
	char* copy;
	int		i;

	i = 0;
	if ((copy = (char*)malloc(sizeof(char) * (strlen(s1) + 1))) != 0)
	{
		while (s1[i])
		{
			copy[i] = s1[i];
			i++;
		}
		copy[i] = 0;
		return (copy);
	}
}

/*
parametrii: const void* a, const void* b
compara doua elemente de tip oferta->tip
intoarce rezultatul comparatiei
*/

int compareTip(const void* a, const void* b)
{
	oferta* ia = (oferta*)a;
	oferta* ib = (oferta*)b;

	return (strcmp(ia->tip, ib->tip));
}

/*
parametrii: const void* a, const void* b
compara doua elemente de tip oferta->tip
intoarce rezultatul comparatiei
*/

int compareTip2(const void* a, const void* b)
{
	oferta* ia = (oferta*)a;
	oferta* ib = (oferta*)b;

	return (strcmp(ib->tip, ia->tip));
}


/*
parametrii: const void* a, const void* b
compara doua elemente de tip oferta->pret
intoarce rezultatul comparatiei
*/

int comparePret(const void* a, const void* b)
{
	oferta* ia = (oferta*)a;
	oferta* ib = (oferta*)b;
	return (ia->pret - ib->pret);
}

/*
parametrii: const void* a, const void* b
compara doua elemente de tip oferta->pret
intoarce rezultatul comparatiei
*/

int comparePret2(const void* a, const void* b)
{
	oferta* ia = (oferta*)a;
	oferta* ib = (oferta*)b;
	return (ib->pret - ia->pret);
}

/*
parametrii: const void* a, const void* b
compara doua elemente de tip oferta->suprafata
intoarce rezultatul comparatiei
*/

int compareSuprafata(const void* a, const void* b)
{
	oferta* ia = (oferta*)a;
	oferta* ib = (oferta*)b;
	return (ia->suprafata - ib->suprafata);
}

/*
parametrii: const void* a, const void* b
compara doua elemente de tip oferta->suprafata
intoarce rezultatul comparatiei
*/

int compareSuprafata2(const void* a, const void* b)
{
	oferta* ia = (oferta*)a;
	oferta* ib = (oferta*)b;
	return (ib->suprafata - ia->suprafata);
}

/*
parametrii: VectorDinamic* v, int left, int right, int (*comp)(void*, void*)
ordoneaza vectorul dinamic v in functie de functia comp
*/

void qsor(VectorDinamic* v, int left, int right, int (*comp)(void*, void*))
{
	int i = left, j = right;

	for(i = 0;i < v->lg;i++)
		for (j = i + 1; j < v->lg; j++) {
			oferta p1 = get(v, i);
			oferta p2 = get(v, j);
			if (comp(&p1, &p2) > 0)
			{
				set(v, i, p2);
				set(v, j, p1);
			}
		}
}