# -*- coding: utf-8 -*-
"""
Created on 02-Aug-17 at 10:35 PM

@author: Pranta Sarker

Task: Motif Finding

python-3.6.2

"""         

from __future__ import print_function;
from random import *;

DNA = {
    1: 'A',
2: 'T',
3: 'C',
4: 'G'
}

motif = {};

def takeDNASequence(row, col):
    global motif;
    for i in range(row):
        for j in range(col):
            indx = randint(1 , 4);
            motif.setdefault(i, []).append(DNA[indx]);
    print("\nDNA Sequence:");
    for i in range(row):
        for j in range(len(motif[i])):
            print(motif[i][j] , end=' ');
        print("");


def Motif_Finding(lmar , row):
    lst = [];
    for i in range(row+5):
        lst.append(0);
    for i in range(len(motif[0]) - lmar + 1):
        string = "";
        sol = "";
        for j in range(i , lmar+i):
            string = string + str(motif[0][j]);
        print(string);
        instring = "";
        for k in range(1 , row):
            for l in range(0, len(motif[k]) - lmar + 1):
                instring = "";
                for p in range(l , lmar + l):
                    instring = instring + str(motif[k][p]);
                print('string = ' , string , ' ' , 'instring = ' , instring);
                if(string == instring):
                    sol = string;
                    lst[k] = 1;
        fl = True;
        for x in range(1 , row):
            if(lst[x] == 0):
                fl=False;
                break;
        if(fl == True):
            break;
        else:
            for a in range(row+5):
                lst[a] = 0;
            sol = "nai";
    #print(sol);
    if(sol == 'nai'):
        print("\nMotif did not find for this Sequences\n");
    else:
        print("\nMotif: " , sol);

print('<'*4, 'Console Start', '>' * 4);
sample = int(input('Enter number of Sample(0 to end console): '));
length = int(input('Enter DNA Sequence length: '));

while(sample > 0):
    motif = {};
    takeDNASequence(sample , length);
    lmar = int(input('\nEnter l-mar(size of motif): '));
    Motif_Finding(lmar , sample);
    sample = int(input('\nEnter number of Sample(0 to end console): '));
    if(sample == 0):
        break;
    length = int(input('\nEnter DNA Sequence length: '));
print(">"*4 , 'End console' , '<'*4);