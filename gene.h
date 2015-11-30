#ifndef __GENE_H_INCLUDED__
#define __GENE_H_INCLUDED__
#include <iostream>
#include <string>
#include <cstdlib>

class gene
{
    public:
        enum allele { A = 0, a = 1 };
        void initialize(); //default, creates a random gene
        void initialize(allele); //creates a homozygote of a phenotype
        void initialize(allele, allele); //creates a gene with alleles
        allele* getGenotype(); //gets the genotype
        allele getPhenotype(); //gets the phenotype
        void setGene(allele x, allele y) { initialize(x, y); }
        allele getRandomAllele(); //gets a random allele, used for mating
        void printGene();
        
        
    private:
        allele genotype[2];
        allele phenotype;
        

};

#endif