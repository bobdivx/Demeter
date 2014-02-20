set(ARDUINO_DEFAULT_BOARD mega2560)
#set(ARDUINO_DEFAULT_BOARD leonardo)
set(ARDUINO_DEFAULT_PORT /dev/ttyACM0)

#add_subdirectory(lib)
#add_subdirectory(trigger)
#add_subdirectory(sensors)

generate_arduino_firmware(demeter
    SRCS  demeter.cpp
    SERIAL picocom @SERIAL_PORT@ -b 9600 -l)

