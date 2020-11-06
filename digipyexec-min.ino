/*============================================================================
MIT License
Copyright (c) 2020 github.com/whyire
                   ___       _                                
              ____/ (_)___ _(_)___  __  _____  _  _____  _____
             / __  / / __ `/ / __ \/ / / / _ \| |/_/ _ \/ ___/
            / /_/ / / /_/ / / /_/ / /_/ /  __/>  </  __/ /__  
            \__,_/_/\__, /_/ .___/\__, /\___/_/|_|\___/\___/  
                   /____/ /_/    /____/
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
============================================================================*/

#include "DigiKeyboard.h"

/* ACTUAL SCRIPT TO EXEC */
// Swap this line with your own script or one from scripts/*
#define PY_SCRIPT "import time;time.sleep(2);f=open('test.txt','x');f.close()"

// use US_KEYBOARD if the computer is setup with a US keyboard layout
#define UK_KEYBOARD

/* DIFFERENT DELAYS */
#define START_DELAY 500
#define START_MENU_DELAY 1200
#define START_MENU_SEARCH_DELAY 300
#define PYTHON_WINDOW_OPEN_DELAY 600


void setup() {
  /*   Open python prompt   */
  DigiKeyboard.delay(START_DELAY);
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
  DigiKeyboard.delay(START_MENU_DELAY);
  DigiKeyboard.print("python.exe");
  DigiKeyboard.delay(START_MENU_SEARCH_DELAY);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(PYTHON_WINDOW_OPEN_DELAY);

  /*   Python script   */
  #ifdef UK_KEYBOARD //swap tilde with pipe as its printed as tilde on uk layout
  DigiKeyboard.print("import os,subprocess as s;os.chdir(os.path.expanduser('|'));f=open('pythonscr.py','w');f.write('''import os;os.chdir(os.path.expanduser('|'));");
  #elif US_KEYBOARD
  DigiKeyboard.print("import os,subprocess as s;os.chdir(os.path.expanduser('~'));f=open('pythonscr.py','w');f.write('''import os;os.chdir(os.path.expanduser('~'));");
  #endif
  DigiKeyboard.print(PY_SCRIPT);
  DigiKeyboard.print("''');f.close();s.Popen('pythonw.exe pythonscr.py',creationflags=8,close_fds=1);exit();");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}
