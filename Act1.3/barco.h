#ifndef BARCO_H
#define BARCO_H

#include <iomanip>
#include <iostream>
#include <string>

class Barco{
	private:
		int minuto, hora, dia, mes, anio;
		char entrada;
		std::string UBI;
	
	public:
		Barco(std::string, std::string, char, std::string);
		Barco();
		Barco(const Barco&);

		// Accessor methods
		int get_minuto() const;
		int get_hora() const;
		int get_dia() const;
		int get_mes() const;
		int get_anio() const;
		char get_entrada() const;
		std::string get_UBI() const;

		void set_time(std::string);
		void set_date(std::string);
		void set_entrada(char);
		void set_UBI(std::string);


		// Operator override
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

int Barco::get_minuto() const{
	return minuto;
}

int Barco::get_hora() const{
	return hora;
}

int Barco::get_dia() const{
	return dia;
}

int Barco::get_mes() const{
	return mes;
}

int Barco::get_anio() const{
	return anio;
}

char Barco::get_entrada() const{
	return entrada;
}

std::string Barco::get_UBI() const{
	return UBI;
}

bool Barco::operator < (const Barco& right){
    if(anio != right.anio)
		return anio < right.get_anio();
    
	if(mes != right.mes)
		return mes < right.get_mes();

	if(dia != right.dia)
		return dia < right.get_dia();

	if(hora != right.hora)
		return hora < right.get_hora();

	if(minuto != right.minuto)
		return minuto < right.get_minuto();
    
    return false;
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
    out << std::setw(2) << barco.get_dia() << "-";
    out << std::setw(2) << barco.get_mes() << "-";
    out << std::setw(2) << barco.get_anio() << " ";
    out << std::setw(2) << barco.get_hora() << ":";
    out << std::setw(2) << barco.get_minuto() << " ";
    out << barco.get_entrada() << " " << barco.get_UBI();
    return out;
}

#endif