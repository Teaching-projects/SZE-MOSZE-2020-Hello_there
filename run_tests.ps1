Clear-Content "output.txt"

.\main.exe luke.json palpatine.json     >>output.txt
.\main.exe luke.json vader.json         >>output.txt
.\main.exe palpatine.json luke.json     >>output.txt
.\main.exe palpatine.json vader.json    >>output.txt
.\main.exe vader.json luke.json         >>output.txt
.\main.exe vader.json palpatine.json    >>output.txt
