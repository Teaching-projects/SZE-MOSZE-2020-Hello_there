import subprocess
import os
import sys

exe = './' + sys.argv[1]
output = sys.argv[2]

scenarios = ['scenario1.json', 'scenario2.json']


with open(output, 'w') as output_f:
    for scenario in scenarios:
        args = [exe, scenario]
        subprocess.call(args,
                        stdout=output_f, stderr=output_f)
