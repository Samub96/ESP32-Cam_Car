
# Proyecto: Carro Controlado Remotamente con ESP32-CAM

## Descripción del Proyecto

Este proyecto consiste en un carro robótico controlado remotamente mediante una interfaz web, utilizando un ESP32-CAM como el dispositivo central para gestionar tanto la cámara como el control de los motores del carrito. Los usuarios pueden interactuar con el carro a través de una página web que se aloja en el propio ESP32.

### Características:
- **Transmisión en vivo**: El ESP32-CAM transmite video en tiempo real desde la cámara del carrito.
- **Control remoto**: Los usuarios pueden controlar el movimiento del carro (adelante, atrás, izquierda, derecha) y activar o desactivar el flash mediante botones en la interfaz web.
- **Web Server**: El ESP32-CAM sirve una página web sencilla con controles para interactuar con el carrito.
- **Conexión Wi-Fi**: El proyecto se conecta a una red Wi-Fi para permitir el control remoto desde cualquier dispositivo en la misma red.

## Componentes Utilizados

- **ESP32-CAM**: Utilizado para gestionar la cámara y la conexión a la red Wi-Fi.
- **Motores de corriente continua**: Para el movimiento del carrito.
- **LED de alta potencia**: Para iluminar el entorno en condiciones de poca luz.
- **Red Wi-Fi**: Para la comunicación remota entre el ESP32 y los dispositivos de control.

## Estructura del Proyecto

1. **Motor Control**: Funciones para controlar el movimiento de los motores.
2. **Flash Control**: Funciones para manejar el estado del LED de alta potencia.
3. **Camera Stream**: Transmisión en vivo de la cámara del ESP32-CAM.
4. **Web Server**: Configuración del servidor web embebido en el ESP32-CAM para recibir comandos.

## Instrucciones de Instalación

1. **Requisitos Previos**:
   - Tener el entorno de desarrollo **Arduino IDE** instalado.
   - Instalar la librería **ESP32** para Arduino desde el Gestor de Placas.
   - Tener acceso a una red Wi-Fi.

2. **Conectar el Hardware**:
   - Conectar el ESP32-CAM al ordenador mediante un adaptador FTDI para la programación.
   - Conectar los motores y el LED al ESP32 de acuerdo con el esquema de conexión.

3. **Subir el Código**:
   - Abrir el proyecto en Arduino IDE.
   - Seleccionar la placa **ESP32 Dev Module** y el puerto correcto.
   - Subir el código al ESP32.

4. **Acceder al Proyecto**:
   - Conectar el ESP32 a la red Wi-Fi.
   - Buscar la IP del ESP32 en el monitor serial.
   - Abrir un navegador y acceder a la IP del ESP32 para controlar el carrito.

## Capturas de Pantalla

¡Aquí podrías incluir algunas capturas de pantalla del proyecto en acción!

## Contribuciones

Este proyecto está abierto a contribuciones. Si deseas colaborar, por favor sigue estos pasos:

1. Haz un fork del proyecto.
2. Crea una rama para tu característica o corrección de error.
3. Haz un pull request detallando los cambios realizados.

## Contacto

- **Nombre**: [Tu Nombre]
- **Correo Electrónico**: [Tu Correo Electrónico]
- **Universidad**: Universidad Icesi
