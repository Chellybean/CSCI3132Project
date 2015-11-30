#ifndef __POPULATION_H_INCLUDED__
#define __POPULATION_H_INCLUDED__
#include "Individual.h"
#include <vector>

class Population
{
public:
	void initialize(); //empty population
	void initialize(int); //random population of a size
	void initialize(int, double); //population with only homozygo, freq = fre of AA
	void initialize(int, int); //# of AA and # of aa
	void initialize(int, int, int); //# of AA, # of aa, and # of Aa
	std::vector<Individual> getPopulation() { return pop; };
	Individual getRandomIndividual(); // gets a random individual from the pop
	Population newGeneration(); //random next gen, same pop size
	Population newGeneration(double, double, double); //fit of AA, aa, Aa
	int countAA(); //counts AA
	int countaa(); //counts aa
	int countAa(); //count Aa
	double getFreqP();
	void setPop(std::vector<Individual>);
	bool isHardyWeinbergEquil(double, double); //expected p and q
	void printStats(double);


private:
	std::vector<Individual> pop;
};
#endif