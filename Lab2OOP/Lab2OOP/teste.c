#include <assert.h>
#include "HeaderService.h"
#include "HeaderUi.h"
#include "HeaderRepo.h"
#include "HeaderUtils.h"

void testare_adaugare_modificare()
{
	VectorDinamic lst = creeazaVectorDinamic();
	assert(adauga_oferta_sv(1, "apartament", "aleea", 999, 40, &lst) == 0);
	assert(lst.of[0].id == 1);
	assert(strcmp(lst.of[0].adresa, "aleea") == 0);
	assert(lst.of[0].pret == 999);
	assert(lst.of[0].suprafata == 40);
	assert(strcmp(lst.of[0].tip, "apartament") == 0);


	oferta x = creeaza_oferta (1, "apartament", "aleea", 999, 40);
	assert(x.id == 1);
	assert(strcmp(x.adresa, "aleea") == 0);
	assert(strcmp(x.tip, "apartament") == 0);
	assert(x.pret == 999);
	assert(x.suprafata == 40);
	assert(modifica_optiune_sv(&lst, 1, 600) == 1);
	assert(modifica_optiune_rp(&lst, 432, 899) == 0);
	assert(lst.of[0].pret == 600);
	assert(adauga_oferta_sv(1, "apartament", "aleea", -999, 40, &lst) != 0);

	distrugeVectorDinamic(&lst);
	distrugeOferta(&x);
	
}

void testare_stergeri()
{
	VectorDinamic v = creeazaVectorDinamic();
	adauga_oferta_sv(2, "casa", "aleea", 99, 40, &v);
	adauga_oferta_sv(3, "casa", "aleea", 992, 240, &v);
	adauga_oferta_sv(4, "apartament", "aleea", 992, 240, &v);

	assert(sterge_optiune_sv(&v, 3) == 0);
	assert(sterge_optiune_sv(&v, 293) == 1);
	distrugeVectorDinamic(&v);

	oferta x = creeaza_oferta(1, "apartament", "aleea", 999, 40);
	distrugeOferta(&x);
	assert(x.adresa == NULL);
}

void testare_copyList()
{
	VectorDinamic v = creeazaVectorDinamic();
	adauga_oferta_sv(2, "casa", "aleea", 99, 40, &v);
	VectorDinamic c = copyList(&v);
	assert(c.of[0].id == 2);
	assert(!strcmp(c.of[0].adresa, "aleea"));
	distrugeVectorDinamic(&v);
	distrugeVectorDinamic(&c);
}

void testare_resize()
{
	VectorDinamic v = creeazaVectorDinamic();
	for (int i = 0;i < 10;i++)
		adauga_oferta_sv(2, "casa", "aleea", 99, 40, &v);
	assert(v.capacitate == 10);
	assert(v.of[7].adresa);
	distrugeVectorDinamic(&v);
}

void testare_validarari()
{
	assert(validare_criteriu("pret") == 0);
	assert(validare_criteriu("dsafd") == 1);

	oferta x = creeaza_oferta(1, "apartament", "aleea", 999, 40);
	assert(validate(x) == 0);
	oferta y = creeaza_oferta(-1, "apartament", "aleea", 999, 40);
	assert(validate(y) == 3);
	oferta z = creeaza_oferta(1, "artament", "aleea", 999, 40);
	assert(validate(z) == 2);
	oferta a = creeaza_oferta(1, "apartament", "", 999, 40);
	assert(validate(a) == 1);
	oferta b = creeaza_oferta(11, "apartament", "aleea", -999, 40);
	assert(validate(b) == 5);
	oferta c = creeaza_oferta(1, "apartament", "aleea", 999, -40);
	assert(validate(c) == 4);
	distrugeOferta(&x);
	distrugeOferta(&y);
	distrugeOferta(&z);
	distrugeOferta(&a);
	distrugeOferta(&b);
	distrugeOferta(&c);
}

void testare_copyOferta()
{
	oferta y = creeaza_oferta(1, "apartament", "aleea", 999, 40);
	oferta z = copyOferta(&y);
	assert(y.pret == 999);
	distrugeOferta(&z);
	distrugeOferta(&y);
}

void testare_ordonari_filtrari()
{
	VectorDinamic v = creeazaVectorDinamic();
	adauga_oferta_sv(2, "casa", "aleea", 100, 41, &v);
	adauga_oferta_sv(3, "apartament", "aleea", 99, 40, &v);
	adauga_oferta_sv(4, "teren", "aleea", 101, 39, &v);
	adauga_oferta_sv(5, "casa", "aleea", 97, 45, &v);

	VectorDinamic a = ordoneaza_sv(&v, "tip", 1);
	VectorDinamic b = ordoneaza_sv(&v, "tip", 2);
	VectorDinamic c = ordoneaza_sv(&v, "pret", 1);
	VectorDinamic d = ordoneaza_sv(&v, "pret", 2);
	VectorDinamic e = ordoneaza_sv(&v, "suprafata", 1);
	VectorDinamic f = ordoneaza_sv(&v, "suprafata", 2);
	
	assert(a.of[0].id == 3);
	assert(a.of[1].id == 5);
	assert(a.of[2].id == 2);
	assert(a.of[3].id == 4);

	assert(b.of[0].id == 4);
	assert(b.of[1].id == 5);
	assert(b.of[2].id == 2);
	assert(b.of[3].id == 3);

	assert(c.of[0].id == 5);
	assert(c.of[1].id == 3);
	assert(c.of[2].id == 2);
	assert(c.of[3].id == 4);

	assert(d.of[0].id == 4);
	assert(d.of[1].id == 2);
	assert(d.of[2].id == 3);
	assert(d.of[3].id == 5);

	assert(e.of[0].id == 4);
	assert(e.of[1].id == 3);
	assert(e.of[2].id == 2);
	assert(e.of[3].id == 5);

	assert(f.of[0].id == 5);
	assert(f.of[1].id == 2);
	assert(f.of[2].id == 3);
	assert(f.of[3].id == 4);

	qsor(&v, 0, 2, comparePret);
	distrugeVectorDinamic(&v);
	distrugeVectorDinamic(&a);
	distrugeVectorDinamic(&b);
	distrugeVectorDinamic(&c);
	distrugeVectorDinamic(&d);
	distrugeVectorDinamic(&e);
	distrugeVectorDinamic(&f);
	distrugeVectorDinamic(&v);

}

void teste()
{
	testare_adaugare_modificare();
	testare_copyList();
	testare_copyOferta();
	testare_ordonari_filtrari();
	testare_resize();
	testare_stergeri();
	testare_validarari();

}