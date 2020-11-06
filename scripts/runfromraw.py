# A script that downloads another python script from the internet and runs it,
# allows you to have extremely large scripts with slower typing times

#   Cleaner formatted version:
# import urllib.request as r, os
# f=open('pscript.py', 'wb')
# f.write(r.urlopen('https://raw.githubusercontent.com/whyire/digipyexec/main/scripts/testscript.py').read())
# f.close()
# os.system("python.exe pscript.py")

#   One line ver (use this):
import urllib.request as r, os;f=open('pscript.py', 'wb');f.write(r.urlopen('https://raw.githubusercontent.com/whyire/digipyexec/main/scripts/testscript.py').read());f.close();os.system("python.exe pscript.py")
