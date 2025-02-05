# Semaforo

## Descrição
Este projeto implementa um semáforo com três LEDs conectados ao Raspberry Pi Pico:
- **LED Vermelho:** GP11
- **LED Amarelo:** GP12
- **LED Verde:** GP13

O semáforo alterna automaticamente entre as cores **vermelho**, **amarelo** e **verde** a cada 3 segundos.

---

## Requisitos

### Hardware
- **Raspberry Pi Pico** ou placa compatível.
- **LEDs:** 3 LEDs (vermelho, amarelo, verde) conectados aos GPIOs 11, 12 e 13.
- **Resistores:** 3 resistores de 330Ω para os LEDs.

### Software
- **CMake** (versão 3.13 ou superior).
- **Pico SDK** (versão 2.1.0 ou superior).
- **Toolchain GCC** para ARM Cortex-M0+.
- **Ninja** (opcional, mas recomendado para compilação rápida).

---

## Estrutura do Projeto
