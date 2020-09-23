import subprocess
import os


unitPairs = ['luke.json palpatine.json',
             'luke.json vader.json',
             'palpatine.json luke.json',
             'palpatine.json vader.json',
             'vader.json luke.json',
             'vader.json palpatine.json']


with open('output.txt', 'w+') as output_f:
    for pair in unitPairs:
        p = subprocess.Popen('./main.exe ' + pair,
                             stdout=output_f, stderr=output_f)
