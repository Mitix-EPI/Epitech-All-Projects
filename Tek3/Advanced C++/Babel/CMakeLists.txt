cmake_minimum_required(VERSION 3.14)
project(babel)

if (WIN32)
    set (CMAKE_PREFIX_PATH "C:\\Qt\\5.15.1\\msvc2019_64")
endif()

set(CMAKE_CXX_STANDARD 17)
add_definitions("-fPIC -g3")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_SUPPRESS_REGENERATION true)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(Portaudio REQUIRED)
find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

file(GLOB_RECURSE SOURCE_FILES_CLIENT
    ${CMAKE_SOURCE_DIR}/include/client/*.cpp
    ${CMAKE_SOURCE_DIR}/src/client/*.cpp
    ${CMAKE_SOURCE_DIR}/src/commons/*.cpp
)

file(GLOB_RECURSE HEADER_FILES_CLIENT
    ${CMAKE_SOURCE_DIR}/include/client/*.h
    ${CMAKE_SOURCE_DIR}/include/client/*.hpp
    ${CMAKE_SOURCE_DIR}/include/commons/*.h
    ${CMAKE_SOURCE_DIR}/include/commons/*.hpp
)

file(GLOB_RECURSE SOURCE_FILES_SERVER
    ${CMAKE_SOURCE_DIR}/include/server/*.cpp
    ${CMAKE_SOURCE_DIR}/src/server/*.cpp
    ${CMAKE_SOURCE_DIR}/src/commons/*.cpp
)

file(GLOB_RECURSE HEADER_FILES_SERVER
    ${CMAKE_SOURCE_DIR}/include/server/*.h
    ${CMAKE_SOURCE_DIR}/include/server/*.hpp
	${CMAKE_SOURCE_DIR}/include/commons/*.h
    ${CMAKE_SOURCE_DIR}/include/commons/*.hpp
)

# include_directories("${PROJECT_SOURCE_DIR}/include/client/")
# include_directories("${PROJECT_SOURCE_DIR}/include/server/")

include_directories(${CMAKE_INCLUDE_PATH})
include_directories(
    ${CONAN_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
)

add_definitions(${QT_DEFINITIONS})

if (WIN32)
    add_definitions(-D_WIN32_WINNT=0x0A00)
endif()

set(STANDARD_UNIX_CXX_FLAGS "-W -Wall -Wextra -std=c++17 -g3 -I./include -fsanitize=address")
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${STANDARD_UNIX_CXX_FLAGS}")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# file(GLOB_RECURSE CLIENT "include/client/*.hpp")
# file(GLOB_RECURSE SERVER "include/server/*.hpp")

include_directories("${CMAKE_MODULE_PATH}/Portaudio/include" include)
link_libraries(${PORTAUDIO_LIBRARIES})

add_executable(babel_client ${HEADER_FILES_CLIENT} ${SOURCE_FILES_CLIENT})
add_executable(babel_server ${HEADER_FILES_SERVER} ${SOURCE_FILES_SERVER})
qt5_use_modules(babel_client Core Network)
target_link_libraries(babel_client ${CONAN_LIBS} -lrt -lm -lasound -ljack -pthread -lpthread -lportaudio Qt5::Widgets Qt5::Network)
target_link_libraries(babel_server ${CONAN_LIBS})

if(MSVC)
    target_link_options(${PROJECT_NAME} PUBLIC /DEBUG)
endif()

# generate proper GUI program on specified platform
if(WIN32) # Check if we are on Windows
	if(MSVC) # Check if we are using the Visual Studio compiler
		set_target_properties(${PROJECT_NAME} PROPERTIES
			WIN32_EXECUTABLE YES
			LINK_FLAGS "/ENTRY:mainCRTStartup"
		)
	elseif(CMAKE_COMPILER_IS_GNUCXX)
			# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows") # Not tested
	else()
		message(SEND_ERROR "You are using an unsupported Windows compiler! (Not MSVC or GCC)")
	endif(MSVC)
elseif(APPLE)
	set_target_properties(${PROJECT_NAME} PROPERTIES
			MACOSX_BUNDLE YES
	)
elseif(UNIX)
	# Nothing special required
else()
	message(SEND_ERROR "You are on an unsupported platform! (Not Win32, Mac OS X or Unix)")
endif(WIN32)
