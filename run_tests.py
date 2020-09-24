import subprocess
import os
import sys

exe = './' + sys.argv[1] + '.exe'
output = sys.argv[2]

unitPairs = [['luke.json', 'palpatine.json'],
             ['luke.json', 'vader.json'],
             ['palpatine.json', 'luke.json'],
             ['palpatine.json', 'vader.json'],
             ['vader.json', 'luke.json'],
             ['vader.json', 'palpatine.json']]


with open(output, 'w') as output_f:
    for pair in unitPairs:
        args = [exe, pair[0], pair[1]]
        subprocess.call(args,
                        stdout=output_f, stderr=output_f)
