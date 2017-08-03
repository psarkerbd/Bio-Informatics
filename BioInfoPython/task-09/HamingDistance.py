# -*- coding: utf-8 -*-
"""
Created on Sun Jul 30 23:33:30 2017

@author: Pranta Sarker

Task: Haming Distance
"""

from __future__ import print_function;
from random import *;

DNA = {
    1:'A',
    2:'T',
    3:'C',
    4:'G',
}

RNA = {
    1:'A',
    2:'U',
    3:'C',
    4:'G',
}

print('Write "start" to start the console and "end" to end the console:');
#string = raw_input('>>>> ');
string = input('>>>> ');
if(string == "start"):
    print('>'*10, 'Console start' , '<'*10);
    size = input('Enter the size(0 to end the console): ');
    # in python 3 input() method takes string but python 2+ it takes integer
    size = int(size);
    while(string == 'start' and size > 0):
        dna = "";
        rna = "";
        mutation_dna = "";
        mutation_rna = "";
        for i in range(size):
            indx = randint(1 , 4);
            dna = dna + str(DNA[indx]);
            rna = rna + str(RNA[indx]);
        for i in range(size):
            indx = randint(1 , 4);
            mutation_dna = mutation_dna + str(DNA[indx]);
            mutation_rna = mutation_rna + str(RNA[indx]);
        print('DNA: (',dna , ') Mutated:(' , mutation_dna , end=')\n');
        print('RNA: (',rna , ') Mutated:(' , mutation_rna , end=')\n');
        dna_hamingDistance = 0;
        rna_hamingDistance = 0;
        mismathed_dna = [];
        mismathed_rna = [];
        for i in range(size):
            if(dna[i] != mutation_dna[i]):
                dna_hamingDistance+=1;
                mismathed_dna.append(str(dna[i])+ str(mutation_dna[i]))
            if(rna[i] != mutation_rna[i]):
                rna_hamingDistance+=1;
                mismathed_rna.append(str(rna[i]) + str(mutation_rna[i]));
        print("DNA Haming Distance: " , dna_hamingDistance);
        print(mismathed_dna);
        print("RNA Haming Distance: " , rna_hamingDistance);
        print(mismathed_rna);
        size = input('Enter the size(0 to end the console): ');
        size = int(size);
        if(size == 0):
            string = 'end';
print('<'*10, "End console" , '>'*10);