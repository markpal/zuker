# -*- coding: utf-8 -*-

import subprocess
import numpy

methods = [1,2,3,4,9]
methodnam = ['oryg', 'pluto','tilecor','tstile','li']
threads = [1,2,4,8,12]
sizes = [1000]
vals = ['time','pkg', 'cores', 'ram']

'''
methods = [1,2,3,4,9]
methodnam = ['oryg', 'pluto','tilecor','tstile','li']
threads = [1,2,4,6,8,10,12]
sizes = [496, 620]
'''


lm = len(methods)
lt = len(threads)
ls = len(sizes)
lval = 4  #time, pkg, cores, ram

x = numpy.zeros((lm,ls,lt, lval))


time = 0.0

script = ' sudo  perf stat -o out.txt   -a -r 1     -e "power/energy-pkg/"     -e "power/energy-cores/"         -e "power/energy-ram/" ./a.out ' # 12 462 2'

lv = True
ns = True

#for m in trange(len(methods), desc='outer0 loop', leave=True):
#    for j in trange(len(sizes), desc='inner2 loop', leave=lv, position=2):
#        for t in trange(len(threads), desc='inner1 loop', leave=lv, position=1):
for m in range(0,len(methods)):
    print m
    for j in range(0,len(sizes)):
        for t in range(0,len(threads)):

            p = subprocess.Popen(script + str(threads[t]) + ' ' + str(sizes[j])+' ' + str(methods[m]) + "  > /dev/null ", shell=True)
            p.wait()


            with open('out.txt') as f:
                lines = f.readlines()

            for l in lines:
                if 'seconds' in l:
                    #parse time
                    #print l
                    item = l.replace('seconds time elapsed', '')
                    item = item.replace(' ', '')
                    item = item.replace(' ', '')
                    item = item.replace(',', '.')
                    time = round(float(item), 2)
                    x[m,j,t,0] = time
                    #print time

                if 'pkg' in l:

                    item = l.replace('Joules power/energy-pkg/', '')
                    item = item.replace(' ', '')
                    item = item.replace(' ', '')
                    item = item.replace(',', '.')
                    pkg = round(float(item), 1)
                    x[m,j,t,1] = pkg

                if 'cores' in l:

                    item = l.replace('Joules power/energy-cores/ ', '')
                    item = item.replace(' ', '')
                    item = item.replace(' ', '')
                    item = item.replace(',', '.')
                    cores = round(float(item), 1)
                    x[m, j,t, 2] = cores
                    #print cores

                if 'ram' in l:

                    item = l.replace('Joules power/energy-ram/', '')
                    item = item.replace(' ', '')
                    item = item.replace(' ', '')
                    item = item.replace(',', '.')
                    ram = round(float(item), 1)
                    x[m, j,t, 3] = ram
                    #print ram

            if(methods[m] == 1):
                break # only 1 thread


print("Finish!")

numpy.save("x", x)

# zapisz csv
all_lines = []

for s in range(0,4):

    lines = []

    lines.append('')
    lines.append('')
    lines.append('')
    lines.append(vals[s].upper())
    lines.append('')

    for m in range(0, lm):
        lines.append(methodnam[m].upper())
        tline = ',' + ','.join(map(str, threads))
        lines.append(tline)
        for j in range(0, ls):
            val = str(sizes[j]) + ','
            for t in range(0, lt):
                val += str(x[m,j,t,s]) +','
            lines.append(val[:-1])

    all_lines += lines

#for l in filelines:
#    print l

for j in range(0, len(all_lines)):
    all_lines[j] = all_lines[j] + '\n'

outF = open("wyniki.csv", "w")
outF.writelines(all_lines)
outF.close()
