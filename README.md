## About this branch: ymesh_dev
This branch uses  [ymesh](https://github.com/ymesh) forked modules for [pota](https://github.com/ymesh/pota) (Polynomial optics to Arnold) with fix for Arnold 7.3 and [CryptomatteArnold](https://github.com/ymesh/CryptomatteArnold.git) v1.2.3.


#### Clone this repository with submodules
```
git clone --recurse-submodules https://github.com/ymesh/lentil.git
```

#### Build (Windows)
Run [build.cmd](build.cmd) in terminal. This will build and install __Lentil__ and __Cryptomatte__ Arnold plugins
to directory specified in variable *deploy_dir* inside [build.cmd](build.cmd).

Edit *ARNOLD_VERSION* and *ARNOLD_ROOT* in [build.cmd](build.cmd) according to your Arnold SDK locations.
```
set ARNOLD_VERSION=7.3.3.1
set ARNOLD_ROOT=<ARNOLD_SDK_PATH>/Arnold-%ARNOLD_VERSION%-windows
```

#### Build (Linux)
Install static libraries for the GNU standard C++ library.
```
sudo dnf install libstdc++-static.x86_64
```
Run [build.sh](build.sh) in terminal. This will build and install __Lentil__ and __Cryptomatte__ Arnold plugins
to directory specified in variable *deploy_dir* inside [build.sh](build.sh).

Edit *ARNOLD_VERSION* and *ARNOLD_ROOT* in [build.sh](build.sh) according to your Arnold SDK locations.
```
ARNOLD_VERSION=7.3.3.1
export ARNOLD_ROOT=<ARNOLD_SDK_PATH>/Arnold-${ARNOLD_VERSION}-linux
```

#### Usage in Maya/Houdini
Set environment variable ARNOLD_PLUGIN_PATH to __bin__ folder in __Lentil__ install directory.
```
# Windows
set LENTIL_PATH=<YOUR_INSTALL_PATH>/lentil-v2.5.1-windows-7.3.3.1
set ARNOLD_PLUGIN_PATH=%LENTIL_PATH%/bin
# Linux
LENTIL_PATH=<YOUR_INSTALL_PATH>/lentil-v2.5.1-linux-7.3.3.1
export ARNOLD_PLUGIN_PATH=${LENTIL_PATH}/bin
```
-----

### There are two components to this project. The first of one is "pota" - short for "Polynomial optics to Arnold". The second one is "polynomial-optics", which is a fork of "Sparse high-degree polynomials for wide-angle lenses" (https://jo.dreggn.org/home/2016_optics.pdf)

  

To get started compiling the Arnold plugin - which I will assume most of the people here are interested in, you don't need to touch the "polynomial-optics" folder. The files have been pre-generated for compilation. However, if new lenses need to be added, this can be done with the code inside of "polynomial-optics".


In the case cryptomatte will be used, it is important that a custom cryptomatte version is compiled. This can be done with the forked CryptomatteArnold repository.

-----
  

### Arnold plug-in compile instructions:

  
Download the Arnold SDK from: https://arnoldrenderer.com/download/archive/ (under Arnold SDK). On my own machine, the environment variables look like this. Please modify for your needs/arnold version. Changing the Arnold Root version will change which Arnold version the plugin is compiled against.

#### Build (Linux/OSX)

The project uses cmake for compilation. The build setup is a forked version from the Cryptomatte project.

```bash
    export LENTIL_ARNOLD_SDKS="/home/cactus/"
    export LENTIL_PATH="/home/cactus/lentil/polynomial-optics"
    export ARNOLD_ROOT="/home/cactus/Arnold-7.1.1.0-linux"
    export ARNOLD_VERSION="7.1.1.0"
    export PATH=$PATH:$LENTIL_PATH"/../Eigen/"
    export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$ARNOLD_ROOT/bin"
```


```bash
    cd lentil
    cd pota
    mkdir build
    cd build
    make install ..
```

This will build the project to the `/dist` folder.

----- 

#### Build (Windows)

On Windows use CMakeGUI.

1. Set the source directory to where you unpacked the source files
2. Set the build directory to be the same but with "\build" on the end.
3. Use "Add Entry" to add ARNOLD_ROOT, set to point to the root directory of the Arnold API.
4. Use "Add Entry" to add ARNOLD_VERSION, e.g `7.1.1.0`.
5. Click "Configure", Select "Yes" when it asks if you want to create the build directory, and choose a Win64 compiller option, e.g. Visual Studio 14 2015 Win64.
6. Click "Generate". This will create a Visual Studio project files in the build directory
7. Open a "Developer Command Prompt for VS2015"
8. cd to the top-level CryptomatteArnold directory
9. `> msbuild build\INSTALL.vcxproj /p:Configuration=Release`



-------

  

### (POLYNOMIAL OPTICS) compile instructions:

  

TODO.


-----


MIT License

Copyright (c) [2023] [Zeno Pelgrims]

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
