import subprocess
import os


unitPairs = [['luke.json', 'palpatine.json'],
             ['luke.json', 'vader.json'],
             ['palpatine.json', 'luke.json'],
             ['palpatine.json', 'vader.json'],
             ['vader.json', 'luke.json'],
             ['vader.json', 'palpatine.json']]

f = open('output.txt', 'w')
f.close()

with open('output.txt', 'w') as output_f:
    for pair in unitPairs:
        args = ["./main.out", pair[0], pair[1]]
        subprocess.call(args,
                        stdout=output_f, stderr=output_f)
