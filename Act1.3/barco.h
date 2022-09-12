#ifndef BARCO_H
#define BARCO_H

#include <iomanip>
#include <iostream>
#include <string>

class Barco{
	public:
		int minuto;
		int hora;
		int dia;
		int mes;
		int anio;
		char entrada;
		std::string UBI;
	
		Barco(std::string, std::string, char, std::string);
		Barco();
		Barco(const Barco&);
		bool isOlderThan(const Barco&);

		void set_time(std::string);
		void set_date(std::string);
		void set_entrada(char);
		void set_UBI(std::string);

        bool operator < (const Barco&);

};

Barco::Barco(std::string date, std::string time, char entrada_, std::string UBI_){
	dia = (date[0]-'0')*10 + (date[1]-'0');
	mes = (date[3]-'0')*10 + (date[4]-'0');
	anio = (date[6]-'0')*10 + (date[7]-'0');

	hora = (time[0]-'0')*10 + time[1]-'0';
	minuto = (time[3]-'0')*10 + time[4]-'0';

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

bool Barco::operator < (const Barco& right){
    return isOlderThan(right);
}

bool Barco::isOlderThan(const Barco& right){
	if(anio < right.anio)
		return true;
	else if(anio > right.anio)
		return false;
    
	if(mes < right.mes)
		return true;
	else if(mes > right.mes)
		return false;

	if(dia < right.dia)
		return true;
	else if(dia > right.dia)
		return false;

  	if(hora < right.hora)
		return true;
	else if(hora > right.hora)
		return false;

	if(minuto < right.minuto)
		return true;
	else if(minuto > right.minuto)
		return false;  

	return true;
}

void Barco::set_time(std::string time){
	hora = (time[0]-'0')*10 + time[1]-'0';
	minuto = (time[3]-'0')*10 + time[4]-'0';
}

void Barco::set_date(std::string date){
	dia = (date[0]-'0')*10 + date[1]-'0';
	mes = (date[3]-'0')*10 + date[4]-'0';
	anio = (date[6]-'0')*10 + date[7]-'0';
}

std::ostream& operator << (std::ostream &out, const Barco &barco)
{
    out << std::setfill('0');
    out << std::setw(2) << barco.dia << "-";
    out << std::setw(2) << barco.mes << "-";
    out << std::setw(2) << barco.anio << " ";
    out << std::setw(2) << barco.hora << ":";
    out << std::setw(2) << barco.minuto << " ";
    out << barco.entrada << " " << barco.UBI;
    return out;
}

#endif