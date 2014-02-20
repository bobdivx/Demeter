#include "demeter.h"
#include <Ethernet.h>
#include "lib/WebServer.h"

static uint8_t mac[] = { 0xAE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
static uint8_t ip[] = { 192, 168, 1, 50 };
WebServer webserver("", 80);

void helloCmd(WebServer &server, WebServer::ConnectionType type, char *, bool)
{
  printkn(F("# Hello world !"));
  server.httpSuccess();

    P(helloMsg) = "<h1>Hello, World!</h1>";
    server.printP(helloMsg);
}

/**
 * Configuration du système
 */
void setup()
{
    Serial.begin(9600);
    printkn(F("# Demeter #"));
    Ethernet.begin(mac, ip);
    Serial.print("server is at ");
      Serial.println(Ethernet.localIP());
    webserver.setDefaultCommand(&helloCmd);
    webserver.addCommand("index.html", &helloCmd);
    webserver.begin();
}

/**
 * Boucle infini
 */
void loop()
{
      char buff[64];
      int len = 64;

      webserver.processConnection(buff, &len);
}
