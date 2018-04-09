# homework_1

Cristian Filippini
VR397728
id598ult@studenti.univr.it
07/04/2018


per lanciare il programma è possibile utilizzare il comando rolaunch in quanto presente un launcher.

Homework 1

La soluzione che ho previsto per questo homework parte da un messaggio che arbitrariamente contiene tre campi divisi ognuno dal carattere ":".
Può essere lanciata tramite apposito launcher, dove i messaggi inviati dal talker non saranno visibili, saranno presenti due finestre di terminale, rispettivamente per selector e listener

---TALKER---
Il nodo talker (talker.cpp) invia ogni secondo il messaggio con il proprio publisher sul topic "chatter".


---SELECTOR---
Il nodo selector (selector.cpp) è provvisto di un subscriber che sfrutta il topic "chatter" creato dal talker, e tramite la funzione callback è in grado di intercettarne i messaggi.
La funzione callback si occupa anche dell'elaborazione del messaggio intercettato. 
Ne viene estratto il campo data e sulla stringa che lo compone viene fatto un parsing tramite la funzione split.
	
	**SPLIT
	Prende come parametri due stringhe, una che sarà quella su cui fare il parsing e una che definisce il delimitatore.
	Ho deciso di far ritornare alla funzione un vettore di stringhe composte dalle sottostringhe ricavate. 
	Ho utilizzato un vettore di stringhe e due riferimenti per posizione di partenza e posizione del delimitatore, in quanto il parsing implementato si appoggia alla funzione find()(restituisce la posizione della prima occorrenza della stringa data in analisi).
	Tramite un ciclo sono state mano a mano estratte le sottostringhe e sono state inserite nel vettore.

Sempre nella funzione di callback si richiede in input uno dei caratteri richiesti e tramite uno switch si va a creare ed a inviare correttamente un nuovo messaggio. 
Questo si appoggia al publisher creato globale e inizializzato nel main che utilizza "selector" come topic.


---LISTENER---
Il listener ha a sua volta un subscriber che utilizza il topic "selector" e quindi riceve i messaggi del selector. 
Nella sua funzione di callback viene stampato a video il testo del messaggio ricevuto.





	
