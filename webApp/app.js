// 🔧 CAMBIA SOLO ESTA VARIABLE
const ESP32_IP = "http://10.246.212.243";

// Control de movimiento
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

// Control de flash
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

// Stream de la cámara (se inserta en el HTML)
window.onload = () => {
  document.getElementById("cameraStream").src = `${ESP32_IP}:81/stream`;
};
