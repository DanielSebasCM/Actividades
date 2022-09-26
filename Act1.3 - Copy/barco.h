#ifndef BARCO_H
#define BARCO_H

#include <string>

class Barco{
	public:
		int minuto, hora, dia, mes, anio;
		char entrada;
		std::string UBI;
	
		Barco(int, int, int, int, int, char, std::string);
		Barco();
		Barco(const Barco&);
		
		bool isOlderThan(const Barco&);
};

Barco::Barco(int dia_, int mes_, int anio_, int hora_, int minuto_, char entrada_, std::string UBI_){
	dia = dia_;
	mes = mes_;
	anio = anio_;

	hora = hora_;
	minuto = minuto_;

	entrada = entrada_;
	UBI = UBI_;	
}

Barco::Barco(){
	dia = 0;
	mes = 0;
	anio = 0;
	hora = 0;
	minuto = 0;
	entrada = '0';
	UBI = "";
}

Barco::Barco(const Barco& right){
	dia = right.dia;
	mes = right.mes;
	anio = right.anio;
	hora = right.hora;
	minuto = right.minuto;
	entrada = right.entrada;
	UBI = right.UBI;
}

/* bool Barco::operator < (const Barco& right){
    return isOlderThan(right);
} */

bool Barco::isOlderThan(const Barco& right){

	if(anio != right.anio)
			return anio < right.anio;
	else{
		if(mes != right.mes)
			return mes < right.mes;
		else{
			if(dia != right.dia)
				return dia < right.dia;
			else{
				if(hora != right.hora)
					return hora < right.hora;
				else{
					if(minuto != right.minuto)
						return minuto < right.minuto;
				}
			}
		}
	}
    return false;
}


#endif