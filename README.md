# digipyexec
<p align="center">
    <a href="http://digistump.com/products/1"><img src="https://img.shields.io/badge/Arduino-DigiSpark-blue.svg" alt="dspark badge"></a>
    <a href="https://www.pjrc.com/teensy/"><img src="https://img.shields.io/badge/Arduino-Teensy-blue.svg" alt="teensy badge"></a>
    <img src="https://img.shields.io/badge/Finished-Actively Maintained-green.svg" alt="finished badge">
    <a href="LICENSE"><img src="https://img.shields.io/badge/License-MIT-blue.svg" alt="mit license"></a>
</p>

### :warning: I am not responsible for anything malicious done with this as it is for educational purposes only. :warning:

Make a digispark/teensy run a python script in the background on any "victim" windows computer you plug it into with python3+. The main use is in Cybersecurity/penetration testing where the background script could do something like install some kind of reverse shell or keylogger, but it could be used for loads of other things like running a script to download and install a list of programs after a factory reset.

#
### Features
- Made to work on 99% of machines with python installed, even if things like run menu are blocked, it runs python via start menu instead.
- Stealthy as it runs the *actual* payload script in the background after the ~5 secs of setup.
- Runs in ~5 secs (digispark) and less than a second (teensy)
- Runs on teensy and digispark

#
### :page_facing_up: Usage
1. Setup digispark with arduino IDE https://digistump.com/wiki/digispark/tutorials/connecting and make sure "victim" has python3+ installed.
2. Put a link to you python script in the PY_SCRIPT_URL macro (line 28). If it's a teensy define TEENSY (line 31)
3. Upload to Digispark/teensy.
4. Profit?!?!

#
### How to speed it up
- (digispark) Reflash bootloader so you don't have to wait 5 secs at the start each time
- (digispark) Use teensy rather than digispark
- (teensy) Dont do anything it's speedy af
