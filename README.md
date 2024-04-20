### dev

#### 1. add submodule git

Example:
```
git submodule add https://github.com/zeux/pugixml.git pugixml
```

other devlopers update submodule git
```
git submodule update --init --recursive
```

#### 2. add qt6 env

add `E:/Qt6/6.6.1/msvc2019_64` (replace with your own) to the system environment variable.

#### 3. copy openssl

Copy all files from the openssl/bin directory to the software debug or release root directory


### debug

Run the windeployqt.exe program to complete the missing dependencies
```
E:\Qt6\6.6.1\msvc2019_64\bin\windeployqt.exe H:\CPP\moyu\out\build\x64-Debug\moyu.exe
D:\Qt6\6.6.2\msvc2019_64\bin\windeployqt.exe D:\workspace\moyu\out\build\x64-debug\moyu.exe
```