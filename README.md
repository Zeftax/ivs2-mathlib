Math base library for the second IVS project for academic year 2022/2023
===

A collection of a select few math functions needed for our [calculator](https://github.com/Zeftax/ivs2-calculator) and
[profiler](https://github.com/Zeftax/ivs2-profiler) programs.

This library is most likely of no use to you. But it is a required part of our
uni project at BUT FIT.

Installing
---
#### Compiling from source
```sh
git clone https://github.com/Zeftax/ivs2-mathlib
cd ivs2-mathlib && make
```
The program will install to the repo directory. <br>
If you wish to install it elsewhere, set `-DCMAKE_INSTALL_PREFIX:PATH` to your 
desired destination.

Usage
---
Example usage as a git submodule:
```cmake
add_subdirectory("extern/ivs2-mathlib")
target_link_libraries(${PROJECT_NAME} PRIVATE ivs2-mathlib)
```
Library namespace: `ivsm` <br>
Example function usage: `ivsm::add(40, 2)` <br>
The full list of functions can be found in `inc/ivs-math.hpp`
<br>

#### Running tests
To run the library tests, use this command in the repo root:
```sh
make test
```

License
---
Copyright (C) <2023>  <xborov08, xkrejc84, xlozrt00, xmitre07>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
