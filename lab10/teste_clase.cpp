#include "teste_clase.h"
#include <iostream>
#include <assert.h>
#include <string.h>
void TesteClase::teste_magazin()
{
	Magazin m(1, "Caine", 20, "19/03/2020", 4);
	assert((m.getCod() == 1) && (m.getNume() == "Caine") && (m.getPret() == 20) && (m.getDataIntroducerii() == "19/03/2020") && (m.getNrExemplareDisponibile() == 4));
	m.setCod(2);
	m.setNume("Pisica");
	assert((m.getCod() == 2) && (m.getNume() == "Pisica") && (m.getPret() == 20) && (m.getDataIntroducerii() == "19/03/2020") && (m.getNrExemplareDisponibile() == 4));
}
void TesteClase::teste_produse()
{
	Produs m(1, "Caine", 20, "19/03/2020", 4, "05/08/2023");
	assert((m.getCod() == 1) && (m.getNume() == "Caine") && (m.getPret() == 20) && (m.getDataIntroducerii() == "19/03/2020") && (m.getNrExemplareDisponibile() == 4) && (m.getDataExpirarii() == "05/08/2023"));
	m.setCod(2);
	m.setNume("Pisica");
	m.setDataExpirarii("25/09/2023");
	assert((m.getCod() == 2) && (m.getNume() == "Pisica") && (m.getPret() == 20) && (m.getDataIntroducerii() == "19/03/2020") && (m.getNrExemplareDisponibile() == 4) && (m.getDataExpirarii() == "25/09/2023"));
}
void TesteClase::teste_animal()
{
	Animal m(1, "Caine", 20, "19/03/2020", 4, 2);
	assert((m.getCod() == 1) && (m.getNume() == "Caine") && (m.getPret() == 20) && (m.getDataIntroducerii() == "19/03/2020") && (m.getNrExemplareDisponibile() == 4) && (m.getVarsta() == 2));
	m.setCod(2);
	m.setNume("Pisica");
	m.setVarsta(3);
	assert((m.getCod() == 2) && (m.getNume() == "Pisica") && (m.getPret() == 20) && (m.getDataIntroducerii() == "19/03/2020") && (m.getNrExemplareDisponibile() == 4) && (m.getVarsta() == 3));
}
void TesteClase::testClase()
{
	teste_animal();
	teste_magazin();
	teste_produse();
}
