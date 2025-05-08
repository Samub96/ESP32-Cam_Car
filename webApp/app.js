const ESP32_IP = "http://172.20.250.243";

// Enviar comandos de movimiento
async function sendCommand(action) {
  try {
    const res = await fetch(`${ESP32_IP}/move?action=${action}`);
    if (res.ok) {
      console.log("Comando enviado:", action);
    } else {
      console.error("Error al enviar comando:", res.status);
    }
  } catch (err) {
    console.error("Error de red:", err);
  }
}

// Encendido/apagado del flash
let flash = false;
async function toggleFlash() {
  flash = !flash;
  try {
    const res = await fetch(`${ESP32_IP}/flash?state=${flash ? "on" : "off"}`);
    if (!res.ok) {
      console.error("Error al cambiar el estado del flash:", res.status);
    }
  } catch (err) {
    console.error("Error de red:", err);
  }
}

// Soporte para mantener presionado
function setupHoldButton(buttonId, command) {
  const btn = document.getElementById(buttonId);

  btn.addEventListener("mousedown", () => sendCommand(command));
  btn.addEventListener("touchstart", () => sendCommand(command));

  const stop = () => sendCommand("stop");
  btn.addEventListener("mouseup", stop);
  btn.addEventListener("mouseleave", stop);
  btn.addEventListener("touchend", stop);
}

// Inicialización general
window.onload = () => {
  document.getElementById("cameraStream").src = `${ESP32_IP}:81/stream`;

  setupHoldButton("btn-forward", "forward");
  setupHoldButton("btn-backward", "backward");
  setupHoldButton("btn-left", "left");
  setupHoldButton("btn-right", "right");
};
