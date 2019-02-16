Filbert
=======

A game engine created by following the tutorials from [TheChernoProject](https://www.youtube.com/thechernoproject)'s [Game Engine](https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT) series.  
This game engine will have a lot in common with [TheCherno/Hazel](https://github.com/TheCherno/Hazel) and that's why the project is called Filbert (see on [Wikipedia](https://en.wikipedia.org/wiki/Corylus_maxima)).

How to set up:
--------------
This project is developed using the latest version of Visual Studio, but is distriuted without the VS project files. In order to generate the project files you have to run premake. There are two scripts provided to help you with that:  
- [GenerateProjects.bat](GenerateProjects.bat) - Windows  
- [GenerateProjects](GenerateProjects) - MacOSX and Linux  

Both scripts behave mostly the same. After the user starts the script he is asked for the type of the project that he wants to generate. If the user doesn't provide that information a default value is used instead. The only significant difference between the scripts is the default project type, which defers depending on the OS. The default action for each OS is as follows:  
- Windows - vs2017
- Linux - gmake
- MacOSX - xcode4

After generating the project files you can build the engine using the selected platform's toolset


Note:
-----
This project provides modified version of [premake for windows](vendor/premake/windows/premake5.exe), whose source can be found in [inferno16/premake-core](https://github.com/inferno16/premake-core).

License:
--------
Copyright © 2019 Ivan Angelov  
Licensed under the [Apache 2.0 License](LICENSE) 