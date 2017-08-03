# -*- coding: utf-8 -*-
"""
Created on Sun Jul 30 01:36:40 2017

@author: Pranta Sarker
"""

from __future__ import print_function;

def forboth(size , dna , rna):
    lmar = input('Enter l-mar(0 to end console): ');
    if(lmar > 0):
        print('>'*20 ,'Start console' , '<'*20);
        string = 'start';
    while(string == 'start'):
        print('*'*5 , 'DNA' , '*'*5);
        # DNA
        visiteddna = set();
        visitedrna = set();
        store = [];
        tmp = "";
        s = "";
        for i in range(size-lmar+1):
            for j in range(i , i+lmar):
                tmp = str(tmp) + str(dna[j]);
            s = tmp;
            tmp = "";
            visiteddna.add(s);
            store.append(s);
        for i in visiteddna:
            print(i , '-'*10 , store.count(i));
        print("");
        print('*'*5 , 'RNA' , '*'*5);
        # RNA
        store = [];
        tmp = "";
        s = "";
        for i in range(size - lmar+1):
            for j in range(i , i+lmar):
                tmp = str(tmp) + str(rna[j]);
            s = tmp;
            tmp = "";
            visitedrna.add(s);
            store.append(s);
        for i in visitedrna:
            print(i, '-'*10 , store.count(i));
        lmar = input('Enter l-mar(0 to end console): ');
        if(lmar == 0):
            string = 'end';
    
    print('<'*20, 'End console', '>'*20);


file = open("randomDNAsequence.txt" , "r");

#string = file.read();

dna = file.readline();
print('DNA: ' , dna);
#print(len(dna)-1);

rna = file.readline();
print('RNA: ' , rna);

forboth(len(dna)-1 , dna , rna);

file.close();
