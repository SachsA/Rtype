rmdir /s build
mkdir build
cd build
conan install --build sfml .. --build=missing
cmake .. -G  "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=Release
msbuild CPP_rtype_2018.sln /p:OutDir="." /p:Configuration=Release /p:Platform="x64"

copy Sources\Server\GameEngine\Entities\Ships\ShipBlue\shipBlueServer.dll lib\
copy Sources\Server\GameEngine\Entities\Ships\ShipRed\shipRedServer.dll lib\
copy Sources\Server\GameEngine\Entities\Ships\ShipYellow\shipYellowServer.dll lib\
copy Sources\Server\GameEngine\Entities\Ships\ShipGreen\shipGreenServer.dll lib\

copy Sources\Server\GameEngine\Entities\BulletsShips\BulletsShipsSD\bulletsShipsSDServer.dll lib\

copy Sources\Server\GameEngine\Entities\Aliens\AlienAlpha\alienAlphaServer.dll lib\
copy Sources\Server\GameEngine\Entities\Aliens\AlienBeta\alienBetaServer.dll lib\
copy Sources\Server\GameEngine\Entities\Aliens\AlienDelta\alienDeltaServer.dll lib\

copy Sources\Client\Entities\Ships\ShipBlue\shipBlueClient.dll lib\
copy Sources\Client\Entities\Ships\ShipRed\shipRedClient.dll lib\
copy Sources\Client\Entities\Ships\ShipYellow\shipYellowClient.dll lib\
copy Sources\Client\Entities\Ships\ShipGreen\shipGreenClient.dll lib\

copy Sources\Client\Entities\Bullets\BulletsShips\BulletsShipsSD\bulletsShipsSDClient.dll lib\

copy Sources\Client\Entities\Aliens\AlienAlpha\alienAlphaClient.dll lib\
copy Sources\Client\Entities\Aliens\AlienBeta\alienBetaClient.dll lib\
copy Sources\Client\Entities\Aliens\AlienDelta\alienDeltaClient.dll lib\