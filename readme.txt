Blaga Ana-Maria-Andreea, 314CB

Functia "citire" citeste 4 numere,componentele unei adrese, pe care le shifteaza la stanga cu un anumit numar de biti si le "lipseste" facand | intre ele.

Functia "afisare" afiseaza o adresa de retea.Se afiseaza pe rand fiecare octet. Se creeaza o masca alcatuita numai din biti de 1 pentru octetul dorit, iar restul sunt setati pe 0 din shiftare. Octetul afisat este obtinut facand & intre masca si adresa primita ca parametru.

Functia "afisare_IP_MSK" afiseaza folosindu-se de functia "afisare" IP-ul si masca de retea in formatul IP/MSK.

Functia "MSK_zecimal" creeaza si afiseaza o masca in format zecimal. Functia primeste ca parametru numarul de biti de 1 ai mastii. Se creeaza o masca formata numai din biti de 1. Aceasta se shifteaza la stanga cu diferenta dintre 32(4 octeti a cate 8 biti) si numarul de biti de 1, respectiv numarul de biti de 0.

Functia "afisare_octa" functioneaza analog cu functia "afisare", insa aceasta afiseaza fiecare octet in format octal(baza 8).

Functia "afisare_hexa" functioneaza analog cu functia "afisare", insa aceasta afiseaza fiecare octet in format hexadecimal(baza 16).

Functia "adr_retea" primeste ca parametrii o adresa IP si o masca de retea si returneaza adresa de retea. Adresa de retea se obtine facand & intre adresa IP si masca de retea.

Functia "adr_brod" primeste ca parametrii o adresa IP si o masca de retea si returneaza adresa de retea. Adresa de retea se obtine facand | intre adresa IP si masca de retea negata.

Functia "afisare_binar" afiseaza fiecare octet al unei adrese IP in format binar. Prin shiftari repetate ale adresei IP este comparat ultimul bit al acesteia cu 1. In cazul in care sunt identici se afiseaza "1", altfel se afiseaza "0".

Functia "modificare_masca" afiseaza varianta corecta a unei masti de retea gresite pe care o primeste ca parametru. Acesta gaseste primul bit de 0 din adresa de masca parcurgand-o de la stanga la dreapta prin siftari repetate. Cand il gaseste genereaza varianta corecta a mastii de retea repective cu ajutorul functiei "MSK_zecimal" careia ii da ca parametru numarul de biti de 1 consecutivi pe care trebuie sa ii aiba masca de retea respectiva.

Functia "verificare_masca" verifica daca o masca de retea este corecta. Aceasta neaga masca primita ca parametru si o copiaza intr-o variabila auxiliara. Se adauga in variabila auxiliara valoarea 1. Verfifica daca masca obtinuta facand si pe biti intre masca initiala si variabila auxiliara este 0(MSK_1 & MSK ==0). In caz afirmativ functia returneaza valoarea 1, adica masca este intr-un format valid(bitii de 1 ai mastii nu sunt pe pozitii identice cu cei ai variabile auxiliare). In caz negativ functia retueneaza valoare 0, adica masca nu este intr-un format valid(cel putin un bit de 1 al mastii este pe pozitie identica cu un alt bit de 1 al variabilei auxiliare).

Functia "verificare_adresa" verifica daca o adresa IP ar putea face parte dintr-o anumita retea. Functia primeste ca parametrii adresa IP, masca de retea si adresa de retea. Sunt calculati 2 "parametri" intre care adresa IP trebuie sa se incadreze pentru a putea face parte din reteaua respectiva: start si end. Start se obtine facand si intre adresa de retea si masca de retea, iar end facand sau intre start si masca de retea negata. In cazul in care adresa IP se incadreaza intre start si end(start < = IP < = end) functia returneaza 1, altfel returneaza 0.

In "main":
Citesc numarul de seturi de retea, iar apoi pentru fiecare set citit realizez urmatoarele:
-citesc MSK_1 apland functia "citire";
-citesc MSK_2;
-citesc IP_1 si IP_2 apeland functia "citire";
-citesc numarul de adrese de retea;
-task 0: afisez IP_1/MSK_2 in formatul IP/MSK apeland functia "afisare_IP_MSK";
-task 1: afisez MSK_2 in format zecimal apeland functia "MSK_zecimal"
-task 2: afisez MSK_1 in bazele 8 si 16 apeland functiile "afisare_octa" si "afisare_hexa";
-task 3: afisez adresa de retea pentru IP_1 apeland functia "adr_retea";
-task 4: afisez adresa de broadcast pentru IP_1 apeland functia "adr_brod";
-task 5: afisez daca IP_1 este in aceeasi retea cu IP_2 apeland functia "adr_retea";
-task 6: verific corectitudinea mastii de retea MSK_1 apeland functia "verificare_masca";
-task 7: daca masca de la taskul anterior a fost corecta o afisez cu functia "afisare", altfel o corectez si afisez varianta corecta a acesteia cu functia "modificare_masca";
-task 8: afisez fiecare octet al adresei IP_1 in binar apeland functia "afisare_binar";
-task 9: citesc adrese de retea cu functia "citire", le caut pe cele din care ar putea face parte IP_2 si afisez indicii acestora cu functia "verificare_adresa". 