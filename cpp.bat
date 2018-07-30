echo using VS2017 Community Version
echo [VS2017+Notepad++] simple npp + cpp dev env init (npp edit, commandline compile, link, build)
echo place this bat in %userprofile%, so run cmd will into here and can call cpp
echo after call cpp.bat, the directory will changed to %userprofile%\source
echo then you can enter %npp% hello.cpp to call Notepad++ starting coding..
echo save you source code (hello.cpp) and return cmd,
echo input cl /c /D "UNICODE" /EHsc hello.cpp (compile hello.cpp to hello.obj)
echo input link /subsystem:console user32.lib hello.obj (or link hello.obj to hello.exe)
echo input hello or hello.exe run the program


set npp="C:\Program Files\Notepad++\notepad++.exe"
set path=%path%;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.14.26428\bin\Hostx64\x64;
set include=%include%;C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\um;C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\ucrt;C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\shared;C:\Program Files (x86)\Windows Kits\10\Include\10.0.17134.0\winrt;
set lib=%lib%;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.17134.0\um\x64;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.17134.0\ucrt\x64;

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
echo init vc x64 compile env finished.

cd /d d:\git\cpp
echo enter [npp] hello.cpp start coding..
