#pragma once
#include "HeaderDomain.h"

int adauga_oferta_sv(int id, char* tip, char* adresa, int pret, int suprafata, VectorDinamic* v);
int modifica_optiune_sv(VectorDinamic* v, int id, int pret);
VectorDinamic ordoneaza_sv(VectorDinamic* v, char* criteriu, int ord);
int sterge_optiune_sv(VectorDinamic* v, int id);
