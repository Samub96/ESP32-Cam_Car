const char MAIN_page[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="es">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>Icesi Interactiva - ESP32-CAM</title>
  <style>
    body {
      margin: 0;
      font-family: Arial, sans-serif;
      background-color: #f4f4f4;
      color: #222;
      text-align: center;
    }

    header {
      display: flex;
      align-items: center;
      justify-content: space-between;
      background-color: #5c5dee;
      color: white;
      padding: 10px 30px;
      text-align: center;
    }

    .header-left, .header-center, .header-right {
      flex: 1;
    }

    .header-center h1 {
      margin: 0;
      font-size: 20px;
    }

    .header-left img.logo {
      height: 80px;
    }

    .header-right span {
      font-size: 16px;
      font-weight: bold;
    }

    main {
      padding: 20px;
    }

    .camera-view img {
      width: 90%;
      max-width: 640px;
      border: 4px solid #003366;
      border-radius: 10px;
      margin-bottom: 20px;
    }

    .remote-control {
      display: inline-block;
    }

    .row {
      margin: 10px 0;
    }

    button {
      font-size: 22px;
      padding: 15px 20px;
      margin: 0 10px;
      background-color: #005580;
      color: white;
      border: none;
      border-radius: 8px;
      cursor: pointer;
      width: 70px;
      height: 70px;
    }

    button:hover {
      background-color: #0077aa;
    }

    button.stop {
      background-color: #b30000;
    }

    button.stop:hover {
      background-color: #ff0000;
    }
  </style>
</head>
<body>
  <header>
    <div class="header-left">
      <img src="src/Icesi-logo.png" alt="Logo Universidad" class="logo"/>
    </div>
    <div class="header-center">
      <h1>Remote Controlled Car Camera Robot Web Server</h1>
    </div>
    <div class="header-right">
      <span>Ingeniería en Energía Inteligente</span>
    </div>
  </header>

  <main>
    <div class="camera-view">
      <img id="cameraStream" src="http://%IP%:81/stream" alt="Camera Stream" />
    </div>

    <div class="remote-control">
      <div class="row">
        <button id="btn-forward">↑</button>
      </div>
      <div class="row">
        <button id="btn-left">←</button>
        <button onclick="sendCommand('stop')" class="stop">■</button>
        <button id="btn-right">→</button>
      </div>
      <div class="row">
        <button id="btn-backward">↓</button>
      </div>
      <div class="row">
        <button onclick="toggleFlash()">🔦</button>
      </div>
    </div>
  </main>

  <script>
    document.getElementById('btn-forward').onclick = () => sendCommand('forward');
    document.getElementById('btn-backward').onclick = () => sendCommand('backward');
    document.getElementById('btn-left').onclick = () => sendCommand('left');
    document.getElementById('btn-right').onclick = () => sendCommand('right');

    function sendCommand(cmd) {
      fetch(`/move?action=${cmd}`).catch(err => console.error(err));
    }

    let flashState = false;
    function toggleFlash() {
      flashState = !flashState;
      const state = flashState ? "on" : "off";
      fetch(`/flash?state=${state}`).catch(err => console.error(err));
    }
  </script>
</body>
</html>
)rawliteral";
