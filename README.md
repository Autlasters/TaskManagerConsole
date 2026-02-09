This application is a console-based application used for managing tasks. With its help, users can create, edit, delete, and monitor tasks.
Each task has a name, description, priority, and status associated with it. In addition, tasks can be saved to a file and loaded from a file.

To build and run the project pleas copy all the files to any folder on your computer, open the command console in the same folder with the file, and input the commands below one by one
Command with the description:
md build (to create an empty build folder)
cd build (to navigate to the newly created folder via the console)
cmake ../ (by this command, CMake will create all needed files and connect them to each other)
cmake --build . --config Debug (by this command, CMake will build the debug version of the project)
cmake --build . --config Release (by this command, CMake will build the release version of the project)
!Remark! When you open the final application in VS, do not forget to set the "source" as a Startup Project

!Important notes!
To build and run my application, you need to have CMake version 4.1.2 or later


