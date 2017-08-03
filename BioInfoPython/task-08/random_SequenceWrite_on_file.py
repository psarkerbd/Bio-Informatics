# -*- coding: utf-8 -*-
"""
Created on Sun Jul 30 00:58:01 2017

@author: Pranta Sarker
"""

from __future__ import print_function;
from random import *;

file = open("randomDNAsequence.txt" , "w");

DNA = {
    1: 'A',
    2: 'T',
    3: 'C',
    4: 'G',
}

RNA = {
    1: 'A',
    2: 'U',
    3: 'C',
    4: 'G',
}

size = input("Enter the Size: ");

stringdna = "";
stringrna = "";

for i in range(size):
    indx = randint(1 , 4);
    stringdna = stringdna + str(DNA[indx]);
    stringrna = stringrna + str(RNA[indx]);

file.write(stringdna);
file.write('\n');
file.write(stringrna);

print('Done!');

file.close();