---
author:
   name1: Hartings, Rrobert, 1164453
   name2: Niersmann, Alexander, 1164424
title:
   main: Software EngineeringWS 2019/2020
   sub1: Praktikum Gruppe D
   sub2: Systementwurf
revision:
   doc: hartings_niersmann.p2.000.md
   level: 0
   date: 11.12.2019
lang: de
cssextra: doc1.css
---

# Allgemeine Beschreibung

_Geben Sie kurz an, welche grundsätzliche Systemarchitektur verwendet wird._

# Systemstruktur

## Komponentendiagramm

_Geben Sie hier das Komponentendiagramm an und erläutern Sie die Zusammenhänge._

### Übersicht

![[1] Übersicht UML-Komponenten-Diagramm für Absolventenfeiersystem](übersicht-komponenten.png "Übersicht über die Komponenten")



### Applikationslogik verfeinert

![[2] Applikationslogik UML-Komponenten-Diagramm für Absolventenfeiersystem](app-komponenten.png "Übersicht über die Applikationslogik")

## Komponenten

### Benutzungsschnittstelle

#### Webbrowser

Der Webbrowser wird genutzt, damit die Nutzer die Applikation verwenden können. Der Browser muss HTML und CSS anzeigen können.
Je nach Use-Case und Benutzerrolle werden verschiedene HTML-Seiten angezeigt, welche von der Applikation gerendert worden sind.
Der Webbrowser muss Formulardaten an den Server senden können.

##### Import-Schittstelle

### Applikationslogik

#### Registierung / Login

Diese Komponente ermöglicht die Registierung und Anmeldung am AFS, um so Absolventen und Mitarbeitern des Prüfungsausschuss
die Möglichkeit zu geben, Daten innerhalb der Anwendung zu verwalten und zu ändern.

##### Export-Schnittstelle

Die Komponente Registierung / Login bietet die folgenden Exportschnittstellen an:
* Registierung am AFS
* Login am AFS
* Passwort setzen

###### Registierung am AFS

Registierung am AFS bietet einem Mitarbeiter des Fachbreiches(Prüfungsausschus) die Möglichkeit Zugangsdaten am AFS zu
hinterlegen, um so im Zugriff auf das Backend des AFS zu erhalten. Dies Funktion darf nur von Berechtigten, also
Mitgliedern des Prüfungsauschuss genutzt werden.  

**Datenstruktur:**

new_login ::= #email + passwort;  
email ::= string;  
passwort ::= string;

###### Login am AFS

Der Login am AFS ermöglicht den Absolventen und den Mitarbeitern des Prüfungsausschusses sich am AFS an zu melden,
um so Funktionen der Rolle wahr zunehmen.

**Datenstruktur:** 

login ::= #email + passwort;  
email ::= string;  
passwort ::= string;

###### Passwort setzen

Absolventen ohne Nutzeraccount müssen vor Nutzung des AFS ein Passwort festlegen, damit diese Möglich ist, exportiert 
die Registierung/Login Komponente die Möglichkeit ein Passwort zu vergeben. Nach dem ein Passwort vergeben worden ist,
kann der Absolvent das AFS nutzen.

**Datenstruktur:**

new_login ::= #email + passwort;  
email ::= string;  
passwort ::= string;

##### Import-Schnittstelle

###### Nutzerdaten festschreiben

Das Festschreiben der Nutzerdaten wird aus der Peristenzsicht importiert, um das Abspeichern von Daten zu ermöglichen.
Die Daten umfassen die Nutzereingaben, welche durch die Export-Schnittstellen an die Komponente gesandet werden können.
Die Aktionen auf der Datenbank ist entweder eine Abfrage oder ein Einfügen.
 
**Datenstruktur:**

login ::= #email + passwort;  
email ::= string;  
passwort ::= string;  

#### Teilnahmebekundung

Diese Komponente ermöglicht den Benutzern eine Anmeldung für die Absolventenfeier auszusprechen. Desweitern
ermöglicht die Komponente Absolventen die Anzahl der Begleitpersonen sowie ihre Zusage zu ändern.

##### Export-Schnittstelle
Die Komponente Teilnahmebekundung bietet die folgenden Exportschnittstellen an:
* Teilnahmebekunden
* Status ändern
* Anzahl Begleitpersonen ändern

###### Teilnahmebekunden

Diese Export-Schnittstelle bitet den Mitarbeitern des Fachbereichs die Möglichekeit ihr kommen zur Absolventenfeier
anzumelden.

**Datenstruktur:**

login ::= #email + name + vorname;

email ::= string;  
name ::= string;  
vorname ::= string;  

###### Status ändern

Durch diese Export-Schnittstelle, ist es dem Absolventen möglich, sein kommen anzumelden bzw. zu wiederrufen.

**Datenstruktur:**

login ::= #email + name + teilnahmestatus;
  
teilnahmestatus ::= boolean;

###### Anzahl Begleitpersonen ändern

Diese Export-Schnittstelle ermöglicht es den Absolventen, die Anzahl an Begleitpersonen, welche diesen zur Absolventefeier
begleiten zu ändern.

**Datenstruktur:**

login ::= #email + name + anzahl;

anzahl ::= number;

##### Import-Schnittstelle

###### Daten festschreiben

Das Festschreiben der Daten wird aus der Peristenzsicht importiert, um das Abspeichern von Daten zu ermöglichen.
Die Daten umfassen die Nutzereingaben, welche durch die Export-Schnittstellen an die Komponente gesandet werden können.
Die Aktionen auf der Datenbank ist entweder ein Einfügen oder ein Update auf bestehende Datenbestände.
 
**Datenstruktur:**

teilnahmebekunden ::= #email + name + vorname;  
status_ändern ::= #email + teilnahmestatus;
anzahl_begleitpersonen ::= #email + anzahl;

email ::= string;  
name ::= string;
vorname ::= string;  
teilnahmestatus ::= boolean;
anzahl ::= number;

#### Absolventenfeierverwaltung

Die Komponente Absolventenfeierverwaltung ermöglicht es eine Absolventenfeier anzulegen bzw. diese zu bearbeiten.

##### Export-Schnittstelle

###### Anlegen

Durch diese Exportschittstelle haben die Mitglieder des Prüfungsausschusses die Möglichkeit eine Absolventenfeier im AFS 
zu hinterlegen. Sollte bereits eine andere Feier angelegt sein, wird diese überschrieben.

**Datenstruktur:**

neue_feier ::= name + #datum + uhrzeit + ort;

name ::= string;  
datum ::= date;  
uhrzeit ::= time;  
ort ::= string;  

###### Bearbeiten

Durch die Exportschnittstelle "Bearbeiten" hat der Prüfungssausschuss die Möglichkeit die Daten der Absolventenfeier im
AFS zu ändern.

**Datenstruktur:**

feier ::= name + #datum + uhrzeit + ort;

name ::= string;  
datum ::= date;  
uhrzeit ::= time;  
ort ::= string;  

##### Import-Schittstelle

Die Import-Schnittstelle ermöglicht, das eine Erstellung einer Absolventenfeier sowie die Änderungen an einer
Absolventenfeier in die Datenbank geschrieben werden und somit persistent sind.

**Datenstruktur:**

feier ::= name + #datum + uhrzeit + ort;

name ::= string;  
datum ::= date;  
uhrzeit ::= time;  
ort ::= string;  

#### UI Rendering

Diese Komponete umfasst ein server seitiges rendern der Ansicht, sowie eine Auslieferung an den Client.

##### Export-Schnittstelle

Die Export-Schnittstelle liefert dem Browser/Client eine gerenderte HTML-Seite mit Informationen aus der Datenbank,
sofern diese benötigt werden.

**Datenstruktur:**_Auslieferung einer HTML/CSS-Seite_

##### Import-Schittstelle

Die Import-Schnittstelle wird benötigt, damit HTML-Seiten mit unter anderem Datenbank inhalt gerendert werden können.

**Datenstruktur:** Abhängig von der angeforderten Seite

### Persistenzschicht

Die Persistenzsicht hat die folgenden Aufgaben: Sie kümmert sich um das Transofmieren der Daten in eines für die Datenbank
nutzbares Format. Desweitern ermöglicht diese, SQL Abfragen auf vorhandene Daten. Neben diesem stellt die Persitenźsicht
auch eine Möglichtkeit bereit mit Hilfe eines Adapters auf die benötigten Daten des Prüfungsamtes zuzugreifen 

#### Query-Manager

Der Query-Manager ermöglicht es SQL Datenbank abfragen auszuführen.

#### Object-Pool

Der Object-Pool verwaltet die Objekte welche in der Datenbank vorhanden sind bzw. welche in die Datenbank geschrieben werden sollen.

#### Object2BSON

Diese Komponente wandelt die von der Applikation übergebenden Daten in das von der MongoDB genutzte Datenformat BSON um.

#### Adapter (technisch)

Der Adapter ermöglicht es die umgewandelten Daten in der MongoDB Datenbank abzuspeichern.

### Weiters

#### Datenbank - MongoDB

#### Adapter - Daten ders Prüfungsamts

## Benutzungsschnittstelle

_Geben Sie die Elemente der Benutzungsschnittstelle an; verwenden Sie Wireframes zur Visualisierung. Beschreiben Sie einheitliche Bedienabläufe._

## Systemverhalten

_Geben Sie hier UML-Sequenz- und/oder UML-Zustands- und/oder UML-Aktivitätsdiagramme_ an.

## Datenbasis

### Klassenmodell

_Geben Sie hier UML-Klassendiagramme an und erläutern Sie diese._

### Nutzung MongoDB

_Geben Sie hier an, wie das Klassenmodell auf Container und Referenzen zwischen den Containern abgebildet wird._

## Verwendung von Entwufsmustern

_Beschreiben Sie hier die verwendeten Entwurfsmuster._