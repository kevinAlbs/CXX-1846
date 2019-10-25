Open VS2015 x64 Native Tools Command Prompt.

Build C driver
```
> cd C:/source
> git clone --branch 1.15.1 https://github.com/mongodb/mongo-c-driver.git
> cd mongo-c-driver
> mkdir cmake-build
> cd cmake-build
> cmake.exe -G "Visual Studio 14 2015 Win64" -DCMAKE_BUILD_TYPE=Release -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF -DCMAKE_INSTALL_PREFIX=C:\mongo-c-driver ..
> msbuild.exe /m INSTALL.vcxproj
```

Build C++ driver
```
> cd C:/source
> git clone --branch r3.4.0 https://github.com/mongodb/mongo-cxx-driver.git
> cd mongo-cxx-driver
> mkdir cmake-build
> cd cmake-build
> cmake -G "Visual Studio 14 2015 Win64" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=C:\mongo-cxx-driver -DCMAKE_PREFIX_PATH=C:\mongo-c-driver -DBOOST_ROOT=C:\boost_1_60_0 ..
> msbuild.exe /m INSTALL.vcxproj
```

Build the repro
```
> cd C:/source
> git clone https://github.com/kevinAlbs/CXX-1846.git
> mkdir cmake-build
> cd cmake-build
> cmake -G "Visual Studio 14 2015 Win64" -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=C:\mongo-cxx-driver ..
```

Add C:\mongo-c-driver\bin and C:\mongo-cxx-driver\bin to PATH. Then run.
```
> .\Debug\repro.exe
mongodb://my_server/?ssl=true
```
