# Mentacy 🛏🎁

**[Mentacy](https://imd.mediencampus.h-da.de/projekt/mentacy/) by The Forbidden Fruit | Internet der Dinge | 4. Semester | [Interactive Media Design](https://imd.mediencampus.h-da.de/) | SoSe 2019**

# Projektbeschreibung

Das IoT-Produkt Mentacy besteht aus zwei Holzboxen, in der das Paar füreinander Liebeswürdigkeiten (z.B. einen Brief oder ein Parfum) verstecken kann. Schiebt man diese zusammen, verschließt sich die Box automatisch. Nun liegt es an dem Paar, diese wieder spielerisch auf zu bekommen. Dies geschieht nur, wenn sich die zwei Liebenden genügend Aufmerksamkeit schenken und miteinander intime Momente sammeln.

# Bestandteile des Prototypes

## Die linke Holzbox
Der Prototype besteht aus zwei Holzboxen. Die **linke Holzbox** *(Ansicht: vorne Memento und hinten Scharniere)* beinhaltet …

- aus 0,8mm Pappelholz & Magneten
- 1 x Arduino Uno
- 1 x Servo Motor (DSSERVO DS3218MG) + Gegenpart
- 1 x RFID-Chip (MFRC522)
- 1 x Memento á 3 LED´s 
- 1 x Memento á 3 LED´s mit RFID Tag
    - eine LED als Status-LED für Memento

*Datei: ./Mentacy-Box/LinkeBox/LinkeBox.ino*

## Die rechte Holzbox
Die **rechte Holzbox** *(Ansicht: vorne Memento und hinten Scharniere)* besteht aus …

- aus 0,8mm Pappelholz & Magneten
- 1 x Arduino Uno
- 2 x Mementos á 3 LED´s 

*Datei: ./Mentacy-Box/RechteBox/RechteBox.ino*

# Skizzen
**Holzbox**
![lTFF_Memento_box_T](https://user-images.githubusercontent.com/33021996/61014017-9bb7c280-a385-11e9-9897-1b72276e9f59.png)
![lTFF_Memento_box](https://user-images.githubusercontent.com/33021996/61012465-f6015500-a37e-11e9-9aa3-1bbe51485d1e.png)
**Memento**

**Auflegematratze**
![TFF-Matratze-T 2](https://user-images.githubusercontent.com/33021996/61014004-90649700-a385-11e9-846b-58c5fe9880f0.png)


# DONE
- [x] Holzboxen 

# Vision
weiteres Vorgehen:
- [ ] Arduino an Holzbox durch ESP´s ersetzen
- [ ] Matratzen-Prototype bauen & testen 
- [ ] ESP - Kommunikation zwischen Mementos, linker und rechter Holzbox und der Auflegematratze *Ordner: Demo-Memento*
- [ ] Fritzing
 
