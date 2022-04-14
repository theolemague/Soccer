# Soccer
This project is a soccer game in C++. This project was realized in the optional course of computer science of my DUT GEII. This course was given by [Philippe Lucidarme](https://www.lucidarme.me/1345-2/) following his [tutorial](https://www.lucidarme.me/programmer-un-jeu-video-de-foot/). The game is written in C++ using SFML. It was normally developed with Qt Creator but I change the structure to use the Make file. (The game is not finished yet !) 
# Development
## Project
```other
- Makefile
- build/
    - objects/
    - app/
- images/
- include/
- src/
```
`src/` is a folder that contains all the .cpp files including the `main.cpp` file which is the starting point of the project. `include/` contains all the .hpp files and the SFML library used. `image/` contains all the .png images used. `build/` (this folder is not in the Github, it is created after the build, see the build section) contains the .o and .d files in the `objects/` folder and the executable in the `app/` folder. `Makefile` is the Makefile the project that shortcut all the command (uselly the project was made on Qt creator but so I created it). The Makefile uses the `c++` compiler (my version: Apple clang version 12.0.5 (clang-1205.0.22.9)) but if you use another one the `CXX` variable can be modified.
## Install
```zsh
$ git clone https://github.com/theolemague/Soccer.git
...
$ cd Soccer
```
## Build
To build the project, use the command `make`
```zsh
$ make
c++ -Wall -Iinclude/ -c src/ball.cpp -MMD -o build/objects/src/ball.o
...
```
The `build/` directory should appear
## Run
To start the project, use the command `make run`. Note that if you run the executable by writing the command (`.exe_file_name`), you must have the `images/` in the same folder where you run the command.
```zsh
% make run
./build/app/main
(window should open)
```
![Result](/images/result.png?raw=true "Employee Data title")
## Clean
To clean the project (remove executable and objects files), use the command `make clean`
```zsh
$ make clean
rm -rf ./build
```