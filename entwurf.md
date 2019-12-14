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
cssextra: assets/doc1.css
---

# Allgemeine Beschreibung

Das Absolventenfeiersystem kurz AFS nutzt eine Server-Client-Architektur. Bei dem Client handelt es sich um ein Thin-Client,
da das Rendering der Darstellungen auf dem Server durchgeführt wird. Da es sich um eine Webapplikation handelt, ist der 
genutze Client ein Webbrowser. Über diesen werden die Nutzerinteraktionen an den Server gesendet. Die Peristierung wird 
von einer Persistierungsschnitstelle im Zusammenspiel mit mongoDB durchgeführt. Die Absolventendaten werden über einen
Adapter von Prüfungsamt bezogen.

# Systemstruktur

## Komponentendiagramm

### Übersicht

![[1] Übersicht UML-Komponenten-Diagramm für Absolventenfeiersystem](images/uml/übersicht-komponenten.png "Übersicht über die Komponenten")

Die Benutzungsschnittstelle greift auf Funktionen der Applikationslogik zu um Daten an die Applikation zu senden.
Desweitern erfolgt das Rendern der HTML-Seite auf dem Server, sodass der Client/Web-Browser auch auf diese Funktionalität
zugreift.

Die Applikationslogik wiederrum, benötigt für das Speichern sowie für das Abrufen von Informationen/Daten die Persistenzschicht.
Die Persistenzsicht dient als Mediator zwischen Applikationslogik und Datenbank (MongoDB).

### Applikationslogik verfeinert

![[2] Applikationslogik UML-Komponenten-Diagramm für Absolventenfeiersystem](images/uml/app-komponenten.png "Übersicht über die Applikationslogik")

Die Applikationslogik ist im oberen Bild verfeinert, da diese in der Übersicht nur grob eingezeicht ist. Die vier verschiedenen
Komponenten bieten verschiedene Export- und Import-Schittstellen an, welche im folgenden genauer erklärt werden.

## Komponenten

### Benutzungsschnittstelle

In den folgenen Frames steht "Benutzername" als Platzhalter für den für den Namen des angemeldeten Nutzers, "Absolventenfeier" steht für den Namen der aktuellen Feier.

![[3] Login-Maske für alle Benutzer/Teilnehmer](images/wireframes/login_step_1.png "Login-Maske")

Diese Maske wird als globaler Login genutzt, jenachdem welche Email-Adresse eingegeben wird, wird die nächste Eingabe Maske angezeigt.
Dort wird unterschieden zwischen Mitarbeiter und Absolventen.

![[4] Maske zum Setzen eines Passwortes für Absolventen](images/wireframes/login_step_2_password_not_set_student.png "Passwort-Maske")

Wenn der Absolvent noch kein Password für seine Email gesetzt hat, muss er das in dieser Maske tun.

![[5] Maske zur Eingabe des Passwortes für Absolventen](images/wireframes/login_step_2_password_already_set_student.png "Passwort-Maske")

Wenn ein Passwort für den Absolventen hinterlegt ist, kann dieser sich damit in dieser Maske anzumelden.

![[6] Maske zur Bekundung der Teilnahme für Absolventen](images/wireframes/participate_not_participating.png "Maske zur Teilnahmebekundung - Absolventen")

Nach dem erfolgreichen Login besteht die Möglichkeit die Teilnahme an der Absolventenfeier zu bekunden und die Anzahl der Begleitpersonen anzugeben.

![[7] Maske zur Stornierung der Teilnahme für Absolventen und Änderungen der Anzahl der Begleitpersonen](images/wireframes/participate_participating.png "Maske zur Teilnahmebekundung - Absolventen")

Nach Bekundung der Teilnahme steht Absolventen nach dem Login die Möglichkeit zur Verfügung die Anzahl der Begleitpersonen zu ändern oder die Teilnahme zu stornieren.

![[8] Maske zur Bekundung der Teilnahme für Mitarbeiter, sowie Registrierung für Mitarbeiter am AFS](images/wireframes/login_step_2_account_not_set_not_participating_worker.png "Maske zur Teilnahmebekundung/Registrierung am AFS - Mitarbeiter")

Wenn ein Mitarbeiter sich weder am AFS angemeldet hat, noch seine Teilnahme zur Absolventenfeier bekundet hat kann er diese Vorgänge in dieser Maske vollenden.

![[9] Status zur Teilnahme, sowie Registrierung für Mitarbeiter am AFS](images/wireframes/login_step_2_account_not_set_participating_worker.png "Maske zur Teilnahmebekundung/Registrierung am AFS - Mitarbeiter")

Falls noch kein AFS-Account besteht aber die Teilnahme bereits bekundet wurde, wird die Maske zur Bekundung durch einen Statustext ersetzt.

![[10] Maske zur Bekundung der Teilnahme für Mitarbeiter und Login zum AFS](images/wireframes/login_step_2_account_set_not_participating_worker.png "Maske zur Teilnahmebekundung sowie Login - Mitarbeiter")

Besteht bereits ein Account, wird die Registrierung mit einem Login getauscht, bei Nicht-Teilnahme wird zusätzlich die Maske zur Teilnahmebekundung angezeigt.

![[11] Status zur Teilnahme, sowie Login zum AFS](images/wireframes/login_step_2_account_set_participating_worker.png "Status zur Teilnahmebekundung sowie Login - Mitarbeiter")

Bei bestehen Account und bekundeter Teilnahme wird die Loginmaske angezeigt und der Status der Teilnahme.

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

**Datenstruktur:** Auslieferung einer HTML/CSS-Seite

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

#### Object2JSON

Diese Komponente wandelt die von der Applikation übergebenden Objekte in das JSON Format aus.

#### Adapter (technisch)

Der Adapter ermöglicht es die umgewandelten Daten in der MongoDB Datenbank abzuspeichern.

### Weiters

#### Datenbank - MongoDB

Die Datenbank erhält von der Persistenzsicht Daten, welche abgespeichert werden sollen. Desweitern gibt die Datenbank
Daten auf Anforderung Daten an die Persistenzsicht.

#### Adapter - Daten ders Prüfungsamts

Diese Komponente stellt einen Adapter für die benötigten Daten des Prüfungsamtes dar, sodass nur benötigte Daten an die
Persistenzschicht weiter gegeben werden.

## Benutzungsschnittstelle



## Systemverhalten

### UML Zustandsdiagramme

#### Übersicht

![[3] Übersicht UML-Zustandsdiagramm-Diagramm für Absolventenfeiersystem](images/uml/übersicht-state.png "Übersicht Zustandsdiagramm")

#### Absolventenfeiersystem (ASF)

![[4] ASF UML-Zustandsdiagramm-Diagramm für Absolventenfeiersystem](images/uml/app-state.png "ASF-Zustandsdiagramm")

#### ASF Backend

![[4] ASF-Backend UML-Zustandsdiagramm-Diagramm für Absolventenfeiersystem](images/uml/asf-state.png "ASF-Backend-Zustandsdiagramm")

## Datenbasis

### Klassenmodell

_Geben Sie hier UML-Klassendiagramme an und erläutern Sie diese._

### Nutzung MongoDB

_Geben Sie hier an, wie das Klassenmodell auf Container und Referenzen zwischen den Containern abgebildet wird._

## Verwendung von Entwufsmustern

### Singelton

Die Applikationslogik soll nur über einen Pool von Verbindungen zur Datenbank verfügen.
Hierzu wird das Entwurfsmuster Singelton genutzt.

### Adapter
