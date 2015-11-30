#ifndef __INDIVIDUAL_H_INCLUDED__
#define __INDIVIDUAL_H_INCLUDED__
#include <iostream>
#include <string>
#include <cstdlib>
#include "gene.h"

class Individual
{
    public:
        void initialize(); //default, creates a random gene
        void initialize(gene::allele); //creates a homozygote of a phenotype
        void initialize(gene::allele, gene::allele); //creates a gene with alleles
		gene getGene(){return g;}; //gets the genotype
        Individual mate(Individual);
        
        
    private:
        gene g;
         
};

#endif