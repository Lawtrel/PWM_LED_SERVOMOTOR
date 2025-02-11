# Projeto PicoW ServoMotor

Este projeto utiliza um Raspberry Pi Pico W para controlar um servo motor. O objetivo é demonstrar como controlar a posição de um servo motor utilizando o microcontrolador Pico W e a linguagem de programação MicroPython.

## Requisitos

- Raspberry Pi Pico W
- Servo motor
- Fonte de alimentação adequada para o servo motor
- Jumpers e cabos de conexão
- Ambiente de desenvolvimento MicroPython (Thonny ou similar)

## Video

## Instalação

1. Conecte o Raspberry Pi Pico W ao seu computador.
2. Abra o Thonny ou outro ambiente de desenvolvimento MicroPython.
3. Carregue o firmware MicroPython no Pico W, se ainda não estiver instalado.
4. Conecte o servo motor ao Pico W conforme o esquema de ligação abaixo:
    - Sinal do servo motor ao pino GPIO 22 do Pico W
    - VCC do servo motor ao pino 3V3 do Pico W
    - GND do servo motor ao pino GND do Pico W

## Diagrama de Conexões

    O diagrama de conexões para este projeto está disponível no arquivo `diagram.json`. Este arquivo pode ser aberto com o editor Wokwi para visualizar as conexões entre o Raspberry Pi Pico W e o servo motor.

## Compilação e Execução

    Para compilar e executar o código, siga os passos abaixo:

    1. Certifique-se de ter o CMake instalado em seu sistema.
    2. Navegue até o diretório do projeto.
    3. Execute os seguintes comandos:

    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

    4. Carregue o binário gerado no Raspberry Pi Pico W.

    ## Licença

    Este projeto está licenciado sob a licença MIT. Veja o arquivo `LICENSE` para mais detalhes.