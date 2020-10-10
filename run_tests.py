import subprocess
import os
import sys

exe = './' + sys.argv[1]
output = sys.argv[2]

unitPairs = [['luke.json', 'palpatine.json'],
             ['luke.json', 'vader.json'],
             ['luke.json', 'player.json'],
             ['palpatine.json', 'luke.json'],
             ['palpatine.json', 'vader.json'],
             ['palpatine.json', 'player.json'],
             ['vader.json', 'luke.json'],
             ['vader.json', 'palpatine.json'],
             ['vader.json', 'player.json'],
             ['player.json', 'luke.json'],
             ['player.json', 'palpatine.json'],
             ['player.json', 'vader.json']]


with open(output, 'w') as output_f:
    for pair in unitPairs:
        args = [exe, pair[0], pair[1]]
        subprocess.call(args,
                        stdout=output_f, stderr=output_f)
