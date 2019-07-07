#!/usr/bin/env python3
# -*- coding: utf-8 -*-
N = int(input())
count = 0
while N > 0:
    N -= 1;
    s = input();
    a, b, c = [int(x) for x in s.split(' ')]
    count += 1
    print("Case #" + str(count) + ": ", end = "")
    if(int(a) + int(b) > int(c)):
        print("true" if(N) else "true")
    else:
        print("false" if(N) else "false")