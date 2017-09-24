# QtCMake
This is an example of running Qt project using CMake file. You can either use IDEs (CLion, Visual Studio 2017) to open this project, or compile directly through command line tool.

## CLion
Add the following line
```sh
QTDIR:PATH="*YOUR_QT_INSTALL_LOCATION*"
```
to
```sh
"*CLion Build Directory*"/cmake-build-debug/CMakeCache.txt
or
"*CLion Build Directory*"/cmake-build-release/CMakeCache.txt
```
based on your configuration type. You can add this line at anywhere, CLion will automatically configure it for you.

## Visual Studio 2017
Visual Studio 2017 comes with CMake support. You can take advantage of the features of Visual Studio to open and compile CMake projects.

Open the project by `File->Open->Folder...` or simply `Right Click` in the folder space. Find menu `CMake->Change CMake Settings-> YOUR_CMAKE_FILE` in VS2017 to open `CMakeSettings.json` for editing.
Add the following variable
```json
"variables": [ { "name": "QTDIR", "value": "*YOUR_QT_INSTALL_LOCATION*" } ]
```
to `CMakeSettings.json`.

An example of `CMakeSettings.json` will look like this:
```json
{
  "configurations": [ {
      "name": "x64-Release",
      "generator": "Visual Studio 15 2017 Win64",
      "configurationType": "Release",
      "inheritEnvironments": [ "msvc_x64" ],
      "buildRoot": "${workspaceRoot}/${name}",
      "variables": [ {
          "name": "QTDIR",
          "value": "C:/Qt/Qt5.9.0/5.9/msvc2017_64/"
        } ]
    } ]
}
```
where the Qt location is `C:/Qt/Qt5.9.0/5.9/msvc2017_64/`.

## Command Line
To run CMake directly in command line, add the following CMake option to your command line.
```sh
-DQTDIR="*YOUR_QT_INSTALL_LOCATION*"
```
