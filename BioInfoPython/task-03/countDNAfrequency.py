# -*- coding: utf-8 -*-
"""

@author: Pranta Sarker

"""

from __future__ import print_function;

from random import *;

DNA = {
1: 'A',
2: 'T',
3: 'C',
4: 'G'
}

fl = False;

while True:
    k = input('Enter the length to see the DNA sequence (Press 0 to end) : ');
    
    DNAseq = ();
    
    if k == 0:
        if fl == True:
            print("Checking finish! End console", end="\n");
        else:
            print("Not checked, End console", end="\n");
        break; 
    
    for i in range(0 , k):
        fl =True;
        n = randint(1 , 4);
        DNAseq += (DNA[n], );
        print(DNA[n] , end = " ");
    
    print("\n")    
    # print(DNAseq);
    print('A occured: ', DNAseq.count('A'), ' times', end='\n');
    print('T occured: ', DNAseq.count('T'), ' times', end='\n');
    print('C occured: ', DNAseq.count('C'), ' times', end='\n');
    print('G occured: ', DNAseq.count('G'), ' times', end='\n');
