<img src=https://www.icesi.edu.co/buscar-personas/assets/img/ban-icesi.png width="250" height="100" align="center">

-------------------

# 🤖 Carro Controlado por ESP32-CAM - Universidad Icesi

Proyecto académico de Ingeniería Telemática y Energía Inteligente. Se trata de un **carro robótico con cámara en tiempo real**, controlado de forma remota desde una interfaz web en una ESP32-CAM.

## 📸 Descripción General

Este proyecto consiste en el desarrollo de un carrito eléctrico inteligente controlado mediante una interfaz web en una ESP32-CAM. Su principal objetivo es demostrar el impacto del estilo de conducción sobre el consumo energético, integrando monitoreo en tiempo real a través de medidores USB Bluetooth.

La solución permite:

- Transmisión de video en tiempo real.
- Control de movimiento: avanzar, retroceder, girar, detenerse.
- Encendido y apagado del flash.
- Interfaz visual limpia y profesional.

## 🧠 Tecnologías Utilizadas

- **Microcontrolador:** ESP32-CAM
- **Lenguaje:** C++ (Arduino)
- **Frontend:** HTML, CSS, JavaScript 
- **Comunicación:** HTTP sobre WiFi


## 🛠️ Estructura del Proyecto

```
📁 esp32_cam/
|   ├── main/
|   |  ├── motor_control.h
|   |  ├── flash_control.h
|   |  ├── camera_stream.h
|   |  ├── web_server.h  
|   |  └── main.ino   
|   ├── webApp / 
|   |  |      ├── src/
|   |  |      └── logo.png
|   |  ├── app.js
|   |  ├── index.html
|   |  └── Style.css

```

## 🚀 Cómo Usar el Proyecto

1. **Conectar ESP32-CAM:**
   - Configura la red WiFi (SSID y password) en `web_server.h`.

2. **Compilar y subir:**
   - Usa Arduino IDE para cargar el código.

3. **Conéctate al mismo WiFi que el ESP32-CAM.**

4. **Abre el navegador:**
   - Ingresa la dirección IP que aparece por el puerto serial al iniciar en `app.js`.
   - Verás la transmisión y los botones de control.

## 🧠 Aprendizajes Esperados
   - Comprender el impacto del estilo de conducción en el consumo energético.
   - Aplicar conceptos reales de eficiencia en vehículos eléctricos (como frenado regenerativo).
   - Fomentar la innovación en soluciones de movilidad sostenible.

## 📷 Vista de la Interfaz Web

//pendiente

## 🛠️ Requisitos Técnicos
   - ESP32-CAM con cámara OV2640.
   - Driver de motor L298N o similar.
   - Sensores de energía (USB Meter Bluetooth).
   - Navegador web moderno.
   - Fuente de energía portátil (batería recargable)

## 👨‍🔬 Créditos

- **Desarrollador:** Samuel — Estudiante de Ingeniería Telemática
- **Asesor Académico:** Carlos Andres Diaz
- **Universidad:** Universidad Icesi
- **Carrera:** Ingeniería en Energía Inteligente

---

**🔧 Versión presentada en el evento Icesi interactiva 2025.**
