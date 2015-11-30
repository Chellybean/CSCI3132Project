// PopulationSimulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

Population menu1(){// what population?
	int input, popSize, numD, numR, numH;
	double  genoDFreq;
	Population newPop;
	//newPop.initialize();

	std::cout << "What kinda population do you want, idiot?: \n";
	std::cout <<	"	[1] Random population of given size \n";
	std::cout <<	"	[2] Homozygous population with given frequencies\n";
	std::cout <<	"	[3] Homozygous population with given numbers of dominant and recessive genotypes \n";
	std::cout <<	"	[4] Population with given numbers of heterozygous and homozygous genotypes\n";

invalid:

	std::cin >> input;

	switch(input){

	case 1: // population of given size

		std::cout << "Enter population size: \n";
		std::cin >> popSize;
		newPop.initialize(popSize);
		return newPop;

	case 2:
		//aaaaaaaaaaahhhhhhhh
		
		std::cout << "Enter population size: ";	
		std::cin >> popSize;
		
		std::cout << "Enter Dominant genotype frequency (recessive frequency = (1 - freq_D)): "; 
		std::cin >> genoDFreq;

		newPop.initialize(popSize, genoDFreq);
		return newPop;
		//break;
	case 3:

		std::cout << "Enter number of dominant genotypes: ";	
		std::cin >> numD;

		std::cout << "Enter number of recessive genotypes: ";	
		std::cin >> numR;

		newPop.initialize(numD, numR);
		return newPop;
		//break;

	case 4:	

		std::cout << "Enter number of dominant homogeneous genotypes: ";	
		std::cin >> numD;

		std::cout << "Enter number of recessive homogeneous genotypes: ";	
		std::cin >> numR;

		std::cout << "Enter number of heterogeneous genotypes: ";	
		std::cin >> numH;

		newPop.initialize(numD, numR, numH);
		return newPop;

	default:
		//AAHHHH

		std::cout<< "wrong input type retard!\n expected an integer. \n";
		goto invalid;
	}
}

/*
int menu2(){
	int input, iterations;
	std::cout << "Whattya wanna do with that population loser?: \n";
	std::cout <<	"	[1] Fitness \n";
	std::cout <<	"	[2] Random mating (giggity)\n";


	std::cin >> input;
	
	switch(input){
	case 1:
		//sometimes i feel reaaaaally weird
		return 1;
	case 2:
		//My names Dave Fuck
		iterations = menuGetIterations();
		for(int i = 0; i<iterations; i++){
			population
		}

		return 2;
	default:
		//and I'm a Backer.

		std::cout<< "Wrong input type. Expected an integer. \n";
		return -1;
	}	
}
*/
int menuGetIterations(){
	int i;
	std::cout<< "How many generations: ";
	std::cin >> i;
	return i;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	/*for(int i = 0; i < 10; i++)
    {
	    gene test;
	    test.initialize();
	    test.printGene(); 
    }
	*/

	//Population population = menu1();
	Population pop;
	pop.initialize(20);
	double p = pop.getFreqP();
	std::cout << std::fixed << p;
	pop.printStats(p);
	pop = pop.newGeneration();
	pop.printStats(p);
	std::cout << "butts";
	//double initFreqP = population.getFreqP();
	

//	int input;
	
	/*int input, iterations;
	std::cout << "Whattya wanna do with that population loser?: \n";
	std::cout <<	"	[1] Fitness \n";
	std::cout <<	"	[2] Random mating (giggity)\n";
	
	std::cin >> input;
	
	switch(input){
	case 1:
		//sometimes i feel reaaaaally weird
		return 1;
	case 2:
		//My names Dave Fuck
		iterations = menuGetIterations();
		
		for(int i = 0; i<iterations; i++){
			population = population.newGeneration();
			population.printStats(initFreqP);
		}

		return 2;
	default:
		//and I'm a Backer.

		std::cout<< "Wrong input type. Expected an integer. \n";
		return -1;
	}	
	//input = menu2();
	//while(input == -1){input = menu2();}


	population.printStats(.5);*/
	
	
}








