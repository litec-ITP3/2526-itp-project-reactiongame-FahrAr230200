# Installationsanleitung – Blink Rush

## Vorbereitung

Zuerst in den Ordner „src“ gehen und die Datei „BlinkRush.ino“ herunterladen.

## Arduino verbinden

Anschließend die Datei „BlinkRush.ino“ in der Arduino IDE öffnen und den Arduino über ein USB-Kabel mit dem Computer verbinden.

## Hardware anschließen

Nun müssen die Komponenten angeschlossen werden:

- Der blaue Button wird an Pin D5 angeschlossen
- Der rote Button wird an Pin D7 angeschlossen
- Die blaue LED wird an Pin D4 angeschlossen
- Die rote LED wird an Pin D6 angeschlossen
- Das OLED-Display wird über die I2C-Schnittstelle (SDA und SCL) angeschlossen

  <img width="384" height="512" alt="image" src="https://github.com/user-attachments/assets/76a00607-869c-40b4-b2a7-90ead3b64754" />
  <img width="384" height="512" alt="image" src="https://github.com/user-attachments/assets/e5645337-223c-4bde-8b3b-42738db19662" />



## Bibliotheken installieren

Im nächsten Schritt müssen die benötigten Bibliotheken installiert werden. Dazu in der Arduino IDE den Bibliotheksverwalter öffnen und folgende Bibliotheken installieren:

- Adafruit GFX
- Adafruit SSD1306

## Programm hochladen

Jetzt in der Arduino IDE das richtige Board (z. B. Arduino Uno) und den passenden COM-Port auswählen. Anschließend den Code auf den Arduino hochladen.

## Inbetriebnahme

Nach dem Hochladen startet das Spiel automatisch und auf dem Display erscheint „Bereit…“.

## Hinweise

Falls das Spiel nicht funktioniert, sollte überprüft werden, ob alle Kabel richtig angeschlossen sind und die Bibliotheken korrekt installiert wurden.
