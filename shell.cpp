/*
 * This is free and unencumbered software released into the public domain.
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <https://unlicense.org>
 * 
 * This project uses microbit-v2-samples - see microbit-v2-samples.txt
 */
 
#include "uBit.hpp"
#include "shell.hpp"

/*
 * Both \r and \n are required to move serial output to the next line aligned to the left.
 */

ManagedString command("$ "); /* Creates the command variable. */
bool shellExit = false; /* Prevents shell from terminating */

void resetShell() /* Resets the shell to "$ " on a new line */
{
  uBit.serial.send("\r\n$ ");
  command = "$ ";
}

void bootMessages() /* Boot messages */
{
  uBit.serial.send("\r\nHello World!");
  uBit.serial.send("\r\nPress the enter key to execute a command.");
  uBit.serial.send("\r\nExecute 'help' for a list of commands and their attributes.");
}

/* Shell functions */
void shellHelp()
{
  uBit.serial.send("\r\n'help' gets help");
  uBit.serial.send("\r\n'info' gets program information");
  uBit.serial.send("\r\n'reset' resets the Microbit");
  uBit.serial.send("\r\n'exit' terminates the shell");
  resetShell();
}

void shellInfo()
{
  uBit.serial.send("\r\n Tinyshell for Microbit");
  resetShell();
}

void exitShell()
{
  uBit.serial.send("\r\nExiting shell...");
  shellExit = true;
}

void shell() /* Actual shell code */
{
  bootMessages();
  resetShell();
  while (shellExit == false)
  {
    if (command == "$ ") /* Checks for command input until enter is hit */
    {
      command = command + uBit.serial.readUntil("\r");
    }
    else if (command == "$ help") /* Case for "help" command */
    {
      shellHelp();
    }
    else if (command == "$ info") /* Case for "info" command */
    {
      shellInfo();
    }
    else if (command == "$ reset") /* Case for "reset" command */
    {
      uBit.reset();
    }
    else if (command == "$ exit") /* Case for "exit" command */
    {
      exitShell();
    }
    else /* Case for nonexistent command */
    {
      uBit.serial.send("\r\nCommand does not exist");
      resetShell();
    }
  }
}
