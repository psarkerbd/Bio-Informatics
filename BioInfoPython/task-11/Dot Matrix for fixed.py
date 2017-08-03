# -*- coding: utf-8 -*-
"""
Created on 01-Aug-17 at 5:38 AM

@author: Pranta Sarker

Task: Dot Matrix for fixed

python-3.6.2

"""         

first_dna = "CTATGTC";
second_dna = "ATGGT";

DotMatrix = {};

for i in range(len(first_dna)):
    DotMatrix.setdefault(0, []).append(first_dna[i]);
#print(DotMatrix);

# for i in range(len(first_dna)):
#     print(DotMatrix[0][i] , end=' ');

for i in range(1 , len(second_dna)+1):
    DotMatrix.setdefault(i , []).append(second_dna[i-1]);

# for i in range(1 , len(second_dna)+1):
#     print(DotMatrix[i][0]);

for i in range(1 , len(second_dna) + 1):
    for j in range(1 , len(first_dna)+1):
        DotMatrix.setdefault(i , [j]).append('D');

#print(DotMatrix[1][6]);
#DotMatrix[1][6] = '.';
#print(DotMatrix[4][4])

for i in range(1 , len(second_dna)+1):
    for j in range(len(first_dna)):
        if(DotMatrix[i][0] == DotMatrix[0][j]):
            DotMatrix[i][j+1] = '.';

for i in range(len(first_dna)):
    print(' '*2 , DotMatrix[0][i] , end=' ');

print("");

for i in range(1 , len(second_dna)+1):
    print(DotMatrix[i][0] , end = ' ' *2);
    for j in range(1, len(DotMatrix[i])):
        print(DotMatrix[i][j], end=' '*4);
    print("");
