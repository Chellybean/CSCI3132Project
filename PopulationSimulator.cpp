// PopulationSimulator.cpp : Defines the entry point for the console application.
<<<<<<< HEAD
//

#include "stdafx.h"

Graph graph;
int iterations;

Population menu1(){// what population?
	int input, popSize, numD, numR, numH;
	double  genoDFreq;
	Population newPop;
	//newPop.initialize();

	std::cout << "How would you like to define your population: \n\n";
	std::cout <<	"	[1] Random population of given size \n\n";
	std::cout <<	"	[2] Homozygous population with given frequencies\n\n";
	std::cout <<	"	[3] Homozygous population with given numbers of\n";
	std::cout <<    "		dominant and recessive genotypes \n\n";
	std::cout <<	"	[4] Population with given numbers of \n";
	std::cout <<    "		heterozygous and homozygous genotypes\n\n";
invalid:
	//std::cin.clear();
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
		std::cout<< "Invalid input. Press c to continue.\n";
		std::cin.clear();
		std::cin.ignore(80, 'c');


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
=======
//AHHHHHH THIS IS A TEST!

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
>>>>>>> origin/master
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
	/*
	for(int i = 0; i < 10; i++)
    {
	    gene test;
	    test.initialize();
	    test.printGene(); 
    }
	
	
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
	*/


	Population population = menu1();
	double initFreqP = population.getFreqP();
	int input, iterations;
	std::cout << "How would you like to iterate the generation?: \n\n";
	std::cout <<	"	[1] Fitness \n\n";
	std::cout <<	"	[2] Random mating \n\n";
	
invalid2:
	std::cin >> input;

	//int graph[80][50];

	switch(input){
	case 1:
		double fitAA, fitAa, fitaa;
		//sometimes i feel reaaaaally weird
		std::cout << "Enter the fitness for genotype AA: ";
		std::cin >> fitAA;
		std::cout << "Enter the fitness for genotype Aa: ";
		std::cin >> fitAa;
		std::cout << "Enter the fitness for genotype aa: ";
		std::cin >> fitaa;
		
		iterations = menuGetIterations();		

		graph = Graph::Graph(iterations > 80 ? 80 : iterations);
	

		std::cout << "\n========================== GENERATION: " << 0 << " ==========================\n";
		population.printStats(initFreqP);
		graph.addFreq(initFreqP);
		for(int i = 1; i <= iterations; i++){
			std::cout << "\n========================== GENERATION: " << i << " ==========================\n";
			population = population.newGeneration(fitAA, fitAa, fitaa);
			population.printStats(initFreqP);
			if(i < 80) graph.addFreq(population.getFreqP());
		}
		break;
		//return 1;
	case 2:
		//My names Dave Fuck
		iterations = menuGetIterations();
		


		graph = Graph::Graph(iterations > 80 ? 80 : iterations);

		std::cout << "\n========================== GENERATION: " << 0 << " ==========================\n";
		
		population.printStats(initFreqP);
		graph.addFreq(initFreqP);
		for(int i = 1; i <= iterations; i++){
			std::cout << "\n========================== GENERATION: " << i << " ==========================\n";
			population = population.newGeneration();
			population.printStats(initFreqP);
			if(i < 80) graph.addFreq(population.getFreqP());
		}
		break;
		//return 2;
	default:
		//and I'm a Backer.
		std::cout<< "Invalid input. Press c to continue.\n";
		std::cin.clear();
		std::cin.ignore(80, 'c');

		goto invalid2;
		//return -1;
	}	
	//input = menu2();
	//while(input == -1){input = menu2();}

	
	//population.printStats(.5);

	

	//for(int i = 0; i < 15; i++){graph.addFreq((double)(i)/15);}
	std::cout<< "\nWould you like a graph of the first 80 generations? (y/n): ";
	char cinput;
invalid3:
	std::cin >> cinput;

	switch(cinput){
	case 'y':
		graph.drawGraph();
	case 'n':
		break;
	default:

		std::cout<< "Invalid input. Press c to continue.\n";
		//std::cin.ignore(80, 'c');
		std::cin.clear();
		std::cin.ignore(80, 'c');
		goto invalid3;
	}

	//int input;
	std::cin >> input;
	return 0;
	
}








