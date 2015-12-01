#include "Population.h"
#include "stdafx.h"

//creates an empty population
void Population::initialize()
{
	pop.clear();
}
//creates a random population of size
void Population::initialize(int size)
{
	for(auto i = 0; i < size; i++)
	{
		Individual ind;
		ind.initialize();
		pop.push_back(ind);
	}
}
//creates population of size, with only homozygotes
void Population::initialize(int size, double freqAA)
{
	pop.clear();

	int numAA = (double)size/freqAA-(int)size/freqAA >= 0.5 ? (size/freqAA)+1 : (size/freqAA);

	for(auto i = 0; i < numAA; i++)
	{
		Individual ind;
		ind.initialize(gene::A, gene::A);
		pop.push_back(ind);
	}

	for(auto i = 0; i < size-numAA; i++)
	{
		Individual ind;
		ind.initialize(gene::A, gene::A);
		pop.push_back(ind);
	}
}
//creates a population with # of AA and # of aa
void Population::initialize(int sizeAA, int sizeaa)
{
	pop.clear();
	
	for(auto i = 0; i < sizeAA; i++)
	{
		Individual ind;
		ind.initialize(gene::A, gene::A);
		pop.push_back(ind);
	}

	for(auto i = 0; i < sizeaa; i++)
	{
		Individual ind;
		ind.initialize(gene::a, gene::a);
		pop.push_back(ind);
	}
}
//creates a population with # of AA, aa, and Aa
void Population::initialize(int sizeAA, int sizeaa, int sizeAa)
{
	pop.clear();
	for(auto i = 0; i < sizeAA; i++)
	{
		Individual ind;
		ind.initialize(gene::A, gene::A);
		pop.push_back(ind);
	}
	for(auto i = 0; i < sizeaa; i++)
	{
		Individual ind;
		ind.initialize(gene::a, gene::a);
		pop.push_back(ind);
	}
	for(auto i = 0; i < sizeAa; i++)
	{
		Individual ind;
		ind.initialize(gene::A, gene::a);
		pop.push_back(ind);
	}
}
//gets a random individual from the population
Individual Population::getRandomIndividual() { return pop.at( rand() % pop.size() ); }
//creates a new random generation
Population Population::newGeneration()
{
	Population newGen;
	newGen.initialize();
	//newGen.getPopulation().

	std::vector<Individual> nextGen;

	for(auto i = 0; i < pop.size(); i++)
	{
		Individual parentX = getRandomIndividual(), parentY = getRandomIndividual();
		nextGen.push_back(parentX.mate(parentY));
	}

	newGen.setPop(nextGen);

	return newGen;
}
//creates a new generation with specified fitnesses
Population Population::newGeneration(double fitAA, double fitAa, double fitaa)
{
	double fitAvg = (fitAA + fitaa + fitAa) / 3.0;

	//Calculation: (#Genotype * fitness of Genotype) / average fitness -> next generation num of Genotype

	int numAA = countAA() * fitAA;
	int numAa = countAa() * fitAa;
	int numaa = countaa() * fitaa;

	Population newGen;
	newGen.initialize();

	std::vector<Individual> nextGenSample;

	for(auto i = 0; i < numAA; i++)
	{
		Individual ind;
		ind.initialize(gene::A, gene::A);
		nextGenSample.push_back(ind);
	}
	for(auto i = 0; i < numaa; i++)
	{
		Individual ind;
		ind.initialize(gene::a, gene::a);
		nextGenSample.push_back(ind);
	}
	for(auto i = 0; i < numAa; i++)
	{
		Individual ind;
		ind.initialize(gene::A, gene::a);
		nextGenSample.push_back(ind);
	}

	std::vector<Individual> nextGen;

	for(auto i = 0; i < pop.size(); i++)
	{
		Individual ind;
		ind = nextGenSample.at(rand() % nextGenSample.size()).mate(nextGenSample.at(rand() % nextGenSample.size()));
		nextGen.push_back(ind);
	}

	newGen.setPop(nextGen);

	return newGen;
}
//counts # of AA, aa, Aa
int Population::countAA()
{
	int count = 0;

	for(auto i = 0; i < getPopulation().size(); i++)
	{
		Individual ind = getPopulation().at(i);
		gene::allele* geno = ind.getGene().getGenotype();

		if(geno[0] == gene::A && geno[1] == gene::A){ count++; }
	}

	return count;
}
int Population::countaa()
{
	int count = 0;

	for(auto i = 0; i < getPopulation().size(); i++)
	{
		Individual ind = getPopulation().at(i);
		gene::allele* geno = ind.getGene().getGenotype();

		if(geno[0] == gene::a && geno[1] == gene::a){ count++; }
	}

	return count;
}
int Population::countAa()
{
	int count = 0;

	for(auto i = 0; i < getPopulation().size(); i++)
	{
		Individual ind = getPopulation().at(i);
		gene::allele* geno = ind.getGene().getGenotype();

		if((geno[0] == gene::A && geno[1] == gene::a) || (geno[0] == gene::a && geno[1] == gene::A)){ count++; }
	}

	return count;
}
double Population::getFreqP()
{
	int AA = countAA(), aa = countAa(), popSize = getPopulation().size();
	return (double)((2 * AA) + aa) / (double)(2 * popSize);
}
void Population::setPop(std::vector<Individual> newPop)
{
	pop = newPop;
}
//checks if the population is in HW
bool Population::isHardyWeinbergEquil(double freqP, double freqQ)
{
	double expAA = (freqP * freqP) * getPopulation().size();
	double expAa = (2 * freqP * freqQ) * getPopulation().size();
	double expaa = (freqQ * freqQ) * getPopulation().size();

	double chiSq = ( ( (countAA() - expAA) * (countAA() - expAA) ) / 2 ) +
		( ( (countAa() - expAa) * (countAa() - expAa) ) / 2) +
		( ( (countaa() - expaa) * (countaa() - expaa) ) / 2);

	return chiSq < 3.84;
}
//prints out the populations statisics 
void Population::printStats(double freqP)
{
	double freqQ = 1 - freqP;
	std::cout << "Population Size: " << getPopulation().size() << "\n";
	std::cout << "Genotype AA: count " << countAA() << ", freq " << std::fixed << (double)countAA()/getPopulation().size() << "\n";
	std::cout << "Genotype Aa: count " << countAa() << ", freq " << std::fixed << (double)countAa()/getPopulation().size() << "\n";
	std::cout << "Genotype aa: count " << countaa() << ", freq " << std::fixed << (double)countaa()/getPopulation().size() << "\n";
	std::cout << "Gene A: freq " << std::fixed << (double)( (2 * countAA()) + (countAa()) ) / ( 2 * getPopulation().size() ) << "\n";
	std::cout << "Gene a: freq " << std::fixed << (double)( (2 * countaa()) + (countAa()) ) / ( 2 * getPopulation().size() ) << "\n";
	std::string HW = isHardyWeinbergEquil(freqP, freqQ) ? "true" : "false";
	std::cout << "Is in Hardy-Weinberg Equilibrium? " << HW << "\n";
}