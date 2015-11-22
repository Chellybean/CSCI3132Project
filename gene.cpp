// Example program
#include "gene.h"

//no args, creates a random gene
void gene::initialize()
{
	phenotype = a;
	for(int i = 0; i < 2; i++)
	{
		allele randomA = allele(rand() % 2);
		genotype[i] = randomA;
		if(randomA == A)
			phenotype = A;
	}
}

//creates a homozygote of an allele of phenotype x
void gene::initialize(allele x)
{
	phenotype = x;
	if(x == A){genotype[0] = A; genotype[1] = A;}
	else{genotype[0] = a; genotype[1] = a;};
}

//creates a gene of with both alleles
void gene::initialize(allele x, allele y)
{
	if( x == A && y == A){ phenotype = A; genotype[0] = A; genotype[1] = A;}
	else if( x == a && y == a){ phenotype = a; genotype[0] = a; genotype[1] = a;}
	else { phenotype = A; genotype[0] = A; genotype[1] = a;}
}

//get and set methods
//note, you can retrieve the genotype and phenotype, can only change them through
//set gene
gene::allele * gene::getGenotype(){ return genotype; }
gene::allele gene::getPhenotype(){ return phenotype; }
//returns a random allele, this will be used for mating
//the allele will be passed on to the child
gene::allele gene::getRandomAllele(){ return genotype[rand()%2]; }


void gene::printGene()
{
	std::cout << "Genotype: ";
	for(int i = 0; i < 2; i++ )
	{
		if(genotype[i] == A){ std::cout << "A"; }
		else { std::cout << "a"; }
	}
	std::cout << " Phenotype: ";
	if(phenotype == A){ std::cout << "A\n"; }
	else{ std::cout << "a\n";}
}
	
int main()
{
    for(int i = 0; i < 10; i++)
    {
	    gene test;
	    test.initialize();
	    test.printGene();
    }
}
