# RTYPE

###### The Rtype is a project where we had to remake a Rtype playable in multiplayer.
[R-Type](https://en.wikipedia.org/wiki/R-Type) is a well known game, where you control a ship that have to kill some aliens coming on the right of your screen. You can play solo or in multiplayer.

The main feature of this version of the Rtype is that it's in multiplayer. You can play up to four players on the same server.
The second thing to notice is that it's playable both on Linux and Windows AND it's support cross platform !

The **Rtype** is composed with two main parts : the back developped in **C++** manage all the menus, the game engine and the sockets for the multiplayer; and the front developped with the **SFML (in C++ too)** display the game.
 
### Program compilation:
  ##### Linux:
  ```sh
        ./launch.sh
```
  > Will compile the Rtype.

   ##### Windows:
  ```sh
        launchWin.bat
```
  >  Will compile the Rtype.

### Launching:
  ##### Go in the build folder:
  ```sh
        cd build
```
 > Here you have all the compiled files and binaries.
  ##### Linux Server:
  ```sh
	./bin/r-type_server
```
  > Will run the Server.

  ##### Linux Client:
  ```sh
	./bin/r-type_client
```
  > Will run the Client.

   ##### Windows:

  ##### Windows Server:
  ```sh
	r-type_server.exe
```
  > Will run the Server.

##### Windows Client:
  ```sh
	r-type_client.exe
```
  > Will run the Client.

### Rtype Usage

Please don't forget to change the IP address in the code so you can play on your server.

 #### Project realised by:
- **Alexandre Sachs : [alexandre.sachs@epitech.eu](https://github.com/SachsA)**
- **Antoine Pelletant : [antoine.pelletant@epitech.eu](https://github.com/yabou)**
- **Kellian Cipierre : [kellian.cipierre@cipierre.eu](https://github.com/K6PIR)**
- **Thomas Bleneau : [thomas.bleneau@epitech.eu](https://github.com/TBlenoX)**
