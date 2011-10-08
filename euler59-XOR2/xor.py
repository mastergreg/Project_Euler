#!/usr/bin/python
encoded = open("cipher1.txt", "r")
list = encoded.read()
list = list.split(",")
possibles = []
enc = ""
for i in range (97, 123):
    print i
    for j in range (97, 123):
        for k in range (97, 123):
            for l in range(0, len(list) - 2):
                a = int(list[l]) ^ i
                b = int(list[l + 1]) ^ j
                c = int(list[l + 2]) ^ k
                print "%c" %a ,"%c" %b, "%c"  %c
		
