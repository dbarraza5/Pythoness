#pragma once

#ifndef __SISMTEMAFAM_H__
#define __SISMTEMAFAM_H__

#include <string>
#include <vector>
#include <map>
#include "FAM.h"
#include "VariableLinguistica.h"

using namespace RedNeuronal;
using namespace LogicaDifusa;
using namespace std;

namespace SFAM
{
	class SistemaFAM
	{
	public:
		SistemaFAM();

		~SistemaFAM();

		void agregarVariable(VariableLinguistica*& variable);

		void agregarValoresVariable(string variable, double comienzo, double espacio, int num_vals);

		void agregarRegla(string regla);

		void fuzzificacion(string variable, double*& vals_var);

		void inferenciaDescomposicional(double**& salidas, int num_salidas, int num_vals, string operador, double*& salida);

		void evaluacionRegla(map<string, string>& vars, string& consecuente, string& val_consc, string& operador, map<string, double>& entrada, double*& salida);

		void getCapaSuma(double**& salidas, int num_salidas, int num_vals, double*& suma);

		double getCentroide(double*& suma, double*& vals_consc, int num_vals);

		void getElementosRegla(const string& regla, map<string, string>& vars, string& var_consc, string& val_consc, string& operador);

		void getBitVector(string variable, double valor_entrada, double*& bit_vector);

		// s = salida.
		double getSalida(map<string, double>& entrada);

	protected:
		map<string, VariableLinguistica*> variables;
		map<string, double*> valores_variables;
		map<string, map<string, double*>> grados_vals_vars;
		map<string, int> num_vals_vars;
		vector<string> reglas;
	};
}

#endif