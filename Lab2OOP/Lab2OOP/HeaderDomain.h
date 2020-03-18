#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include<crtdbg.h>
#include <string.h>
#include <stdio.h>
#define INIT_CAPACITY 5
#define FACTOR_MUL 2

typedef struct {
	char* tip;
	int suprafata;
	char* adresa;
	int pret;
	int id;
}oferta;

typedef struct {
	oferta *of;
	int lg;
	int capacitate;
}VectorDinamic;

int validate(oferta x);
oferta creeaza_oferta(int id, char* tip, char* adresa, int pret, int suprafata);
void resizeVectorDinamic(VectorDinamic* v);
void distrugeVectorDinamic(VectorDinamic* v);
void distrugeOferta(oferta* x);
VectorDinamic creeazaVectorDinamic();
int validare_criteriu(char* criteriu);
oferta copyOferta(oferta* p);
VectorDinamic copyList(VectorDinamic* l);
oferta get(VectorDinamic* l, int poz);
oferta set(VectorDinamic* l, int poz, oferta p);