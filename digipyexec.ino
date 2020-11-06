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
// Default script waits 20 secs then makes a file named test.txt in home dir
// Swap this line with your own script or one from scripts/*
#define PY_SCRIPT "import time;time.sleep(20);f=open('test.txt', 'x');f.close()"

/* DIFFERENT DELAYS */
#define START_DELAY 500
#define START_MENU_DELAY 1200
#define START_MENU_SEARCH_DELAY 300
#define PYTHON_WINDOW_OPEN_DELAY 1000


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
  // All is in one line but split into multiple prints for readability

  // py imports
  DigiKeyboard.print("import subprocess;");
  DigiKeyboard.print("import os;");
  
  // Change directory to home as we may not have permission to edit in the python folder
  DigiKeyboard.print("os.chdir(os.path.expanduser('~'));");
  
  // Create the file named pythonscr.py which will run in the background in future (change dir to home
  // to reduce confusion when creating scripts as you may not have perms to write in python folder)
  DigiKeyboard.print("f=open('pythonscr.py', 'w');");
  DigiKeyboard.print("f.write('''import os;os.chdir(os.path.expanduser('~'));");
  DigiKeyboard.print(PY_SCRIPT);
  DigiKeyboard.print("''');");
  DigiKeyboard.print("f.close();");

  // Open the script we just made with pythonw (so it runs in background)
  DigiKeyboard.print("subprocess.Popen('pythonw.exe pythonscr.py', creationflags=8, close_fds=True);");
  
  // Close python prompt when done
  DigiKeyboard.print("exit();");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}
