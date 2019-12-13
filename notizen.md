# Notizen

## Entwurfsmuster

BITTE BEDENKEN
* Singelton
* Adapter

## Komponenten

* MongoDB 
    * bietet *?* zur Persistenzlayer

* Persistenzlayer
    * Dateneingabe
    * Datenausgabe (Bereitstellung, nicht Empfang)
    * Zugang zu externenr Datenbank
    * Abfrage
    * Pooling
    * Übersetzung
        -> Vorlage siedersleben
    
* Applikationlayer
    * *wird verfeinert in Teilkomponente*
    * Login
    * Registrierung
    * Teilnahmebekundung
    * Absolventenfeierverwaltung
    * UI Rending (auf dem Server)
    
* Darstellungslayer
    * Browser