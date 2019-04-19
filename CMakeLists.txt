set(CMAKE_CXX_STANDARD 17)

cmake_minimum_required(VERSION 3.11)
project(CPP_rtype_2018)

include(build/conanbuildinfo.cmake)
conan_basic_setup()

set(EXECUTABLE_CLIENT_NAME "r-type_client")
set(EXECUTABLE_SERVER_NAME "r-type_server")

include_directories(${CMAKE_INCLUDE_PATH})

if (UNIX)
    set(CMAKE_DL_LIBS pthread)
    set(CMAKE_DL_LIBS dl)
    set(CMAKE_DL_LIBS stdc++fs)
endif ()

add_executable(${EXECUTABLE_CLIENT_NAME}
        Sources/Client/Menus/Principal/ButtonsMenuPrincipal.hpp
        Sources/Client/Menus/Settings/ButtonsMenuSettings.hpp
        Sources/Client/Menus/Pause/ButtonsMenuPause.hpp
        Sources/Client/Menus/Right/ButtonsMenuRight.hpp
        Sources/Client/Menus/Rooms/ButtonsMenuRooms.hpp
        Sources/Client/Menus/Lobby/ButtonsMenuLobby.hpp
        Sources/Client/Menus/Login/ButtonsMenuLogin.hpp

        Sources/Client/Menus/Principal/ModelMenuPrincipal.hpp
        Sources/Client/Menus/Pause/ModelMenuPause.hpp
        Sources/Client/Menus/Right/ModelMenuRight.hpp
        Sources/Client/Menus/Rooms/ModelMenuRooms.hpp
        Sources/Client/Menus/Settings/ModelMenuSettings.hpp
        Sources/Client/Menus/Lobby/ModelMenuLobby.hpp
        Sources/Client/Menus/Login/ModelMenuLogin.hpp
        Sources/Client/Menus/GameInstance/ModelGameInstance.hpp

        Sources/Client/Main.cpp

        Sources/Client/Constants/Constants.hpp
        Sources/Client/Constants/Sounds.hpp

        Sources/Client/SFMLHandler/SFMLHandler.cpp
        Sources/Client/SFMLHandler/SFMLHandler.hpp

        Sources/Client/SFMLHandler/FontHandler/FontHandler.cpp
        Sources/Client/SFMLHandler/TextHandler/TextHandler.cpp

        Sources/Client/SFMLHandler/WindowHandler/WindowHandler.cpp
        Sources/Client/SFMLHandler/EventHandler/EventHandler.cpp

        Sources/Client/SFMLHandler/MusicHandler/MusicHandler.cpp
        Sources/Client/SFMLHandler/SpriteHandler/SpriteHandler.cpp
        Sources/Client/SFMLHandler/TextureHandler/TextureHandler.cpp

        Sources/Client/CoreClient/CoreClient.cpp
        Sources/Client/CoreClient/CoreClient.hpp

        Sources/Client/Menus/AMenu.hpp
        Sources/Client/Menus/AMenu.cpp

        Sources/Client/Menus/Pause/ErrorsMenuPause.cpp
        Sources/Client/Menus/Pause/ErrorsMenuPause.hpp
        Sources/Client/Menus/Principal/ErrorsMenuPrincipal.cpp
        Sources/Client/Menus/Principal/ErrorsMenuPrincipal.hpp
        Sources/Client/Menus/Settings/ErrorsMenuSettings.cpp
        Sources/Client/Menus/Settings/ErrorsMenuSettings.hpp
        Sources/Client/Menus/Right/ErrorsMenuRight.cpp
        Sources/Client/Menus/Right/ErrorsMenuRight.hpp
        Sources/Client/Menus/Rooms/ErrorsMenuRooms.cpp
        Sources/Client/Menus/Rooms/ErrorsMenuRooms.hpp
        Sources/Client/Menus/Lobby/ErrorsMenuLobby.hpp
        Sources/Client/Menus/Lobby/ErrorsMenuLobby.cpp
        Sources/Client/Menus/Login/ErrorsMenuLogin.hpp
        Sources/Client/Menus/Login/ErrorsMenuLogin.cpp
        Sources/Client/Menus/GameInstance/ErrorsGameInstance.cpp
        Sources/Client/Menus/GameInstance/ErrorsGameInstance.hpp
        Sources/Client/Entities/ErrorsEntityClient.hpp
        Sources/Client/Entities/ErrorsEntityClient.cpp

        Sources/Client/CoreClient/ErrorsCoreClient.cpp
        Sources/Client/CoreClient/ErrorsCoreClient.hpp

        Sources/Client/Components/Slots/SlotBlue/ErrorsSlotBlue.cpp
        Sources/Client/Components/Slots/SlotBlue/ErrorsSlotBlue.hpp
        Sources/Client/Components/Slots/SlotGreen/ErrorsSlotGreen.hpp
        Sources/Client/Components/Slots/SlotGreen/ErrorsSlotGreen.cpp
        Sources/Client/Components/Slots/SlotRed/ErrorsSlotRed.cpp
        Sources/Client/Components/Slots/SlotRed/ErrorsSlotRed.hpp
        Sources/Client/Components/Slots/SlotYellow/ErrorsSlotYellow.cpp
        Sources/Client/Components/Slots/SlotYellow/ErrorsSlotYellow.hpp

        Sources/Client/Menus/Principal/MenuPrincipal.hpp
        Sources/Client/Menus/Principal/MenuPrincipal.cpp
        Sources/Client/Menus/Pause/MenuPause.hpp
        Sources/Client/Menus/Pause/MenuPause.cpp
        Sources/Client/Menus/Settings/MenuSettings.cpp
        Sources/Client/Menus/Settings/MenuSettings.hpp
        Sources/Client/Menus/Right/MenuRight.cpp
        Sources/Client/Menus/Right/MenuRight.hpp
        Sources/Client/Menus/Rooms/MenuRooms.hpp
        Sources/Client/Menus/Rooms/MenuRooms.cpp
        Sources/Client/Menus/Lobby/MenuLobby.hpp
        Sources/Client/Menus/Lobby/MenuLobby.cpp
        Sources/Client/Menus/Login/MenuLogin.hpp
        Sources/Client/Menus/Login/MenuLogin.cpp
        Sources/Client/Menus/GameInstance/GameInstance.hpp
        Sources/Client/Menus/GameInstance/GameInstance.cpp

        Sources/Client/Components/Button/Button.cpp
        Sources/Client/Components/Button/Button.hpp
        Sources/Client/Components/Color/Color.cpp
        Sources/Client/Components/Color/Color.hpp

        Sources/Commands/CommandParser/CommandParser.cpp
        Sources/Commands/CommandParser/CommandParser.hpp

        Sources/Client/Components/Slots/ASlot.cpp
        Sources/Client/Components/Slots/ASlot.hpp

        Sources/Client/Components/Slots/SlotBlue/SlotBlue.cpp
        Sources/Client/Components/Slots/SlotBlue/SlotBlue.hpp

        Sources/Client/Components/Slots/SlotGreen/SlotGreen.cpp
        Sources/Client/Components/Slots/SlotGreen/SlotGreen.cpp

        Sources/Client/Components/Slots/SlotRed/SlotRed.cpp
        Sources/Client/Components/Slots/SlotRed/SlotRed.hpp

        Sources/Client/Components/Slots/SlotYellow/SlotYellow.cpp
        Sources/Client/Components/Slots/SlotYellow/SlotYellow.hpp

        Sources/Client/Entities/AEntity.cpp
        Sources/Client/Entities/AEntity.hpp

        Sources/Client/LibLoader/ErrorsLibLoader.cpp
        Sources/Client/LibLoader/ErrorsLibLoader.hpp
        Sources/Client/LibLoader/LibLoader.hpp

        Sources/Communication/CommunicationTCP/CommunicationTCPClient/CommunicationTCPClient.cpp
        Sources/Communication/CommunicationTCP/CommunicationTCPClient/CommunicationTCPClient.hpp

        Sources/Communication/CommunicationUDP/CommunicationUDPClient/CommunicationUDPClient.cpp
        Sources/Communication/CommunicationUDP/CommunicationUDPClient/CommunicationUDPClient.hpp

        Sources/Communication/Sockets/SocketUdp/Client/SocketUdpClient.cpp
        Sources/Communication/Sockets/SocketUdp/Client/SocketUdpClient.hpp

        Sources/Communication/Sockets/SocketTcp/Client/SocketTcpClient.cpp
        Sources/Communication/Sockets/SocketTcp/Client/SocketTcpClient.hpp

        Sources/Errors/Errors.cpp
        Sources/Errors/Errors.hpp

        Sources/Communication/Sockets/ErrorsSocket/ErrorsSocket.cpp
        Sources/Communication/Sockets/ErrorsSocket/ErrorsSocket.hpp)
target_link_libraries(${EXECUTABLE_CLIENT_NAME} ${CONAN_LIBS})

add_executable(${EXECUTABLE_SERVER_NAME}
        Sources/Server/Main.cpp

        Sources/Server/CoreServer/CoreServer.cpp
        Sources/Server/CoreServer/CoreServer.hpp

        Sources/Server/GameEngine/GameEngine.cpp
        Sources/Server/GameEngine/GameEngine.hpp

        Sources/Server/GameInstance/GameInstanceStatus.hpp

        Sources/Server/GameEngine/Entities/HitBox.hpp
        Sources/Server/GameEngine/Entities/AEntity.cpp
        Sources/Server/GameEngine/Entities/AEntity.hpp

        Sources/Server/GameEngine/Game/Game.cpp
        Sources/Server/GameEngine/Game/Game.hpp

        Sources/Server/GameEngine/LibLoader/LibLoader.hpp

        Sources/Server/GameEngine/Lobby/Lobby.cpp
        Sources/Server/GameEngine/Lobby/Lobby.hpp

        Sources/Server/GameEngine/Lobby/Slots/Slot.cpp
        Sources/Server/GameEngine/Lobby/Slots/Slot.hpp

        Sources/Server/GameInstance/GameInstance.cpp
        Sources/Server/GameInstance/GameInstance.hpp

        Sources/Server/User/User.cpp
        Sources/Server/User/User.hpp

        Sources/Template/Vector2D/Vector2D.hpp

        Sources/ThreadPool/ThreadPool.cpp
        Sources/ThreadPool/ThreadPool.hpp

        Sources/ParsingConf/AParser.cpp
        Sources/ParsingConf/AParser.hpp
        Sources/ParsingConf/Asset/AssetParser.cpp
        Sources/ParsingConf/Asset/AssetParser.hpp
        Sources/ParsingConf/Level/LevelParser.cpp
        Sources/ParsingConf/Level/LevelParser.hpp
        Sources/ParsingConf/Server/ServerConfParsing.cpp
        Sources/ParsingConf/Server/ServerConfParsing.hpp

        Sources/Communication/Sockets/SocketUdp/Server/SocketUdpServer.cpp
        Sources/Communication/Sockets/SocketUdp/Server/SocketUdpServer.hpp

        Sources/Communication/Sockets/SocketTcp/Server/SocketTcpServer.cpp
        Sources/Communication/Sockets/SocketTcp/Server/SocketTcpServer.hpp

        Sources/Communication/CommunicationTCP/CommunicationTCPServer/CommunicationTCPServer.cpp
        Sources/Communication/CommunicationTCP/CommunicationTCPServer/CommunicationTCPServer.hpp

        Sources/Communication/CommunicationUDP/CommunicationUDPServer/CommunicationUDPServer.cpp
        Sources/Communication/CommunicationUDP/CommunicationUDPServer/CommunicationUDPServer.hpp

        Sources/Commands/CommandParser/CommandParser.cpp
        Sources/Commands/CommandParser/CommandParser.hpp

        Sources/Errors/Errors.cpp
        Sources/Errors/Errors.hpp

        Sources/Communication/Sockets/ErrorsSocket/ErrorsSocket.cpp
        Sources/Communication/Sockets/ErrorsSocket/ErrorsSocket.hpp

        Sources/Server/GameEngine/LibLoader/ErrorsLibLoader.cpp
        Sources/Server/GameEngine/LibLoader/ErrorsLibLoader.hpp

        Sources/ParsingConf/ErrorAParser.cpp
        Sources/ParsingConf/ErrorAParser.hpp
        Sources/ParsingConf/Asset/ErrorAssetParser.cpp
        Sources/ParsingConf/Asset/ErrorAssetParser.hpp
        Sources/ParsingConf/Level/ErrorLevelParser.cpp
        Sources/ParsingConf/Level/ErrorLevelParser.hpp
        Sources/ParsingConf/Server/ErrorServerParser.cpp
        Sources/ParsingConf/Server/ErrorServerParser.hpp)


target_link_libraries(${EXECUTABLE_SERVER_NAME} ${CONAN_LIBS} ${CMAKE_DL_LIBS})

add_subdirectory(Sources/Server/GameEngine/Entities)

add_subdirectory(Sources/Client/Entities)
