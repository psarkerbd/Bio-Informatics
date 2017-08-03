# -*- coding: utf-8 -*-
"""
Created on 01-Aug-17 at 3:35 AM

@author: Pranta Sarker

Task: Partial Digest Problem

python-3.6.2

"""         
from math import *;

currfq = {};
count = {};
L = [];

def formula(a , b , c):
    D = b**2 - (4 * a * c);
    n = (-b + sqrt(D)) / (2 * a);
    return int(n);

def init(len):
    global currfq;
    for i in range(0, len+2):
        currfq[i] = 0;
    #print(currfq , end='; ');

def PDP(size):

    global L , count , currfq, X , visited;

    n = formula(1 , -1, -(2 * size));
    # print('n = ' , n);
    # print('X = ' , X);
    # print('coount = ' ,  count);
    # print('L = ' , L);

    for i in range(1 , len(L)+1):

        element = L[i];

        takeminimum = 1e5;

        if(len(X) == n):
            return X;

        else:

            for item1 in X:
                point = abs(element - item1);

                if(point in visited):
                    #print('val1 = ', item1 , ', element = ' , element, ' , point = ', point);
                    cnt = 0;
                    init(L[0]);

                    for item2 in X:

                        diff2 = abs(item2 - point);

                        if(diff2 in visited):

                            #print('point = ' , point , ', item2 = ' , item2, ', diff2 = ', diff2);
                            currfq[diff2] = currfq[diff2] + 1;

                            if(count[diff2] >= currfq[diff2]):
                                cnt+=1;
                                #print('cnt = ' , cnt);
                            else:
                                continue;
                        else:
                            #print('point = ', point, ', item2 = ', item2, ', diff2 = ', diff2 , ' left');
                            continue;

                    if(cnt == len(X)):
                        takeminimum = min(takeminimum , point);
                        #print("cnt and len(X) are equal");
                        #print('temporary minimum = ' , takeminimum);
                else:
                    continue;
            if(takeminimum < 1e5):
                X.append(takeminimum);
                count[takeminimum] -= 1;
                #print('final minimum = ', takeminimum);


def Prove(X):
    global L , visited;

    for i in range(len(X)):
        for j in range(i+1 , len(X)):
            diff = abs(X[i] - X[j]);
            #print('diff = ' , diff);
            count[diff]-=1;

    fl = True;

    for element in visited:
        if(count[element] > 0):
            fl=False;
            break;
    if(fl == True):
        print("Partial Digest Points are: " , X);
    else:
        print("No Solution");



size = int(input('Enter the Size: '));

L = [int(n) for n in input().split()];

#L = list(map(int , input().split()));

L = L[:size];
#print(L);

L.sort(reverse=True);
# print(L);
visited = set(L);
for item in visited:
    count[item] = L.count(item);
# print(getUnique);
# print(L);
# print(count);

X = [0, L[0]];

PDP(size);
X.sort();
# print('X has = ' , X);
Prove(X);