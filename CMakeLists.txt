# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

cmake_minimum_required(VERSION 3.13)
set(CMAKE_C_STANDARD 11)

# Inicializa o SDK do Raspberry Pi Pico
include(pico_sdk_import.cmake)
project(Semaforo C CXX ASM)
pico_sdk_init()

# Adiciona o executável principal
add_executable(Semaforo main.c)

# Define o nome e a versão do programa
pico_set_program_name(Semaforo "Semaforo")
pico_set_program_version(Semaforo "1.0")

# Habilita a saída via UART e USB
pico_enable_stdio_uart(Semaforo 1)
pico_enable_stdio_usb(Semaforo 1)

# Linka as bibliotecas necessárias
target_link_libraries(Semaforo pico_stdlib hardware_timer)

# Adiciona saídas adicionais (.uf2 e .elf)
pico_add_extra_outputs(Semaforo)