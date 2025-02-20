# Sonos ESP
This Project is all about developing a remote controll for my Sonos System. I hope in the future I will work this out.

## Setup
I. A RPI runs a http [api](https://github.com/jishi/node-sonos-http-api) and acts as a bridge due to sonos not having a local http api.

II. A ESP 32 running this project sending commands to the RPI

### Rudis Reste Rampe 

RPI IP and Port : 192.168.0.132:5005

Imortant routes: rpiip:5005/Sonos/state