#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

#include "Alias.h"

#include "StandardPSO.h"

int main(void){
	PSO::StandardPSO pso = PSO::StandardPSO(
		CostFunction([](dvec& x)->double
	{
		double sum = 0;
		for (auto v : x) { sum += v*v; }
		return sum;
	}, CostFunction::zero_cost, 2, -100., 100.),
		1000, 20);
	pso.Start();
}