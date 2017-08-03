# -*- coding: utf-8 -*-
"""
Created on Sun Jul 30 00:39:04 2017

@author: Pranta Sarker
"""

from __future__ import print_function;
from random import *;
RNA = {
    1:'A',
    2:'U',
    3:'C',
    4:'G',
}
string = raw_input('Write "start"(except quota) to start the console\n or\nWrite "end"(except quota) to end the console\n>>> ');
if(string == 'start'):
    print('>'*20 ,'Start console' , '<'*20);
    size = input('Enter the length of RNA(length 0 will consider to terminate the console): ');
    if(size == 0):
        string = 'end';
while(string == 'start'):
    seq = "";
    visited = [];
    s = "";
    tmp = "";
    for i in range(size):
        indx = randint(1 , 4);
        seq = str(seq) + str(RNA[indx]);
    print(seq , end=' ');
    lmar = input('Enter l-mar: ');
    print("");
    for i in range(size-lmar+1):
        for j in range(i , i+lmar):
            tmp = str(tmp) + str(seq[j]);
        s = tmp;
        tmp = "";
        visited.append(s);
        if(visited.count(s) == 1):
            print(s , end=' ');
    size = input('\nEnter the length of RNA(length 0 will consider to terminate the console): ');
    if(size == 0):
        string = 'end';
print('<'*20, 'End console', '>'*20);