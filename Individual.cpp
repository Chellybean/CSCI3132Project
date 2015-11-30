#include "Individual.h"
#include "stdafx.h"
     //Initializes the individual with a random gene
     void Individual::initialize() {
         g.initialize();
     }
     //Initialize individual with a given allele
     void Individual::initialize(gene::allele a) {
         g.initialize(a);
     }
     //Initialize individual with two given alleles
     void Individual::initialize(gene::allele a, gene::allele b) {
         g.initialize(a, b);
     }
     //mates given individual w/ this given new random alleles
     Individual Individual::mate(Individual a) {
         gene::allele x = getGene().getRandomAllele();
         gene::allele y = a.getGene().getRandomAllele();
         Individual i;
         i.initialize(x, y);
         return i;
     }