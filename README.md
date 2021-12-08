# microbit-tinyshell
A tiny shell for Microbit written in C++ that is designed to be integrated into other projects. It includes an extremely small amount of commands by default, but is designed to be easily extensible with new commands. 

# Microbit Version Support
As of right now, I only have a Microbit v2 to test on, so I can only gurantee functionality with that version.

# Building from source
To build from source, first prepare the Microbit C++ runtime maintained by Lancaster University. To do this on the Microbit v2, follow the instructions at https://github.com/lancaster-university/microbit-v2-samples. Please note that I have only gotten the build tools to work on an Ubuntu 18.04 LTS environment.

Next, clone this repository and copy all the source files (.cpp and .hpp files) except main.cpp to the source directory of the microbit-v2-samples repository.

Third, create a .cpp source file that imports shell.hpp and has a main() function that calls uBit.init() and shell(). For an test version, a basic main.cpp is included. To use it, copy it to the source directory of the microbit-v2-samples repository.

Finally, build the project using the build.py script included with microbit-v2-samples.

# Installing the shell
To install a test version of the shell, download the latest release and copy it to the Microbit, or use a hex binary you built from source. To interact with the shell, simply open a serial connection to the Microbit. For instructions on opening a serial connection, check out this page: https://support.microbit.org/support/solutions/articles/19000022103-outputing-serial-data-from-the-micro-bit-to-a-computer.

If the shell boot messages do not show up, simply hit the reset button on the Micro bit. 

If the text output from commands looks incomplete, unplug the Microbit, plug in the Microbit, reopen the serial connection, and hit the reset button on the Microbit. I don't know what causes this, it only seems to happen on first connection. 

# Extending the shell
To extend the shell, simply create a new function in shell.cpp that corresponds to the command you want to implement, then add a case for your command in shell().

# Contributing
Any contributions are welcome! Please make your code formatting similar to the rest of the project, and make sure the Unlicense is commented at the top of any source files, as well as this notice:

"This software uses microbit-v2-samples - see microbit-v2-samples-license.txt".
