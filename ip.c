//Blaga Ana-Maria-Andreea, 314CB

#include <stdio.h>

// Functie pentru citirea adreselor

unsigned int citire() {
  unsigned int adr, oct1, oct2, oct3, oct4;
  scanf("%u.%u.%u.%u", &oct1, &oct2, &oct3, &oct4);
  oct1 = oct1 << 24;
  oct2 = oct2 << 16;
  oct3 = oct3 << 8;
  adr = oct1 | oct2 | oct3 | oct4;
  return adr;
}

// Functie pentru afisarea adreselor

void afisare(unsigned int adr) {
  unsigned char m = 0;
  unsigned int mask, nr, p = 24, i;
  m = ~m;
  for (i = 0; i < 4; i++) {
    mask = m << p;
    nr = adr & mask;
    nr = nr >> p;
    p = p - 8;
    if (i != 3)
      printf("%u.", nr);
    else
      printf("%u", nr);
  }
}

// Functie pentru afisarea adreselor in formatul IP/MSK

void afisare_IP_MSK(unsigned int IP_1, unsigned int MSK_2) {
  printf("-0 ");
  afisare(IP_1);
  printf("/%u\n", MSK_2);
}

// Functie pentru afisarea mastii in format zecimal

unsigned int MSK_zecimal(unsigned int MSK_2) {
  unsigned int oct1 = 0, oct2 = 0, oct3 = 0, oct4 = 0, n, msk;
  n = MSK_2;
  oct1 = oct4 = ~oct1;
  oct2 = oct1 << 16;
  oct3 = oct1 << 8;
  oct1 = oct1 << 24;
  msk = oct1 | oct2 | oct3 | oct4;
  n = 32 - n;
  msk = msk << n;
  return msk;
}

// Functie pentru afisarea mastii in baza 8

void afisare_octa(unsigned int MSK_1) {
  unsigned char m = 0;
  unsigned int mask, nr;
  int i, p = 24;
  m = ~m;
  printf("-2 ");
  for (i = 0; i < 4; i++) {
    mask = m << p;
    nr = MSK_1 & mask;
    nr = nr >> p;
    p = p - 8;
    if (i != 3)
      printf("%o.", nr);
    else
      printf("%o ", nr);
  }
}

// Functie pentru afisarea mastii in baza 16

void afisare_hexa(unsigned int MSK_1) {
  unsigned char m = 0;
  unsigned int mask, nr;
  m = ~m;
  int i, p = 24;
  for (i = 0; i < 4; i++) {
    mask = m << p;
    nr = MSK_1 & mask;
    nr = nr >> p;
    p = p - 8;
    if (i != 3)
      printf("%X.", nr);
    else
      printf("%X\n", nr);
  }
}

// Functie pentru obtinerea adresei de retea

unsigned int adr_retea(unsigned int IP, unsigned int MSK) {
  unsigned int adr;
  adr = IP & MSK;
  return adr;
}

// Functie pentru obtinerea adresei de broadcast

unsigned int adr_brod(unsigned int IP, unsigned int MSK) {
  unsigned int adr;
  MSK = ~MSK;
  adr = IP | MSK;
  return adr;
}

// Functie pentru verificarea corectitudinii unei masti de retea

unsigned int verificare_masca(unsigned int MSK) {
  unsigned int MSK_1;
  MSK = ~MSK;
  MSK_1 = MSK + 1;
  if ((MSK & MSK_1) == 0)
    return 1;
  return 0;
}

// Functie pentru afisarea in format binar a fiecarui octet dintr-o adresa IP

void afisare_binar(unsigned int adr) {
  unsigned int p = 31, i, j;
  printf("-8 ");
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 8; j++) {
      if ((adr >> p) & 1)
        printf("1");
      else
        printf("0");
      p--;
    }
    if (i != 3)
      printf(".");
  }
  printf("\n");
}

// Functie pentru corectarea unei masti de retea

void modificare_masca(unsigned int adr) {
  unsigned int p = 31;
  while (((adr >> p) & 1) && p)
    p--;
  adr = MSK_zecimal(32 - p - 1);
  afisare(adr);
}

// Functie pentru a verifica daca o adresa IP se afla intr-o retea precizata

unsigned int verificare_adresa(unsigned int IP, unsigned int NET,
                               unsigned int MSK) {
  unsigned int start, end;
  start = NET & MSK;
  end = start | ~MSK;
  if ((IP >= start) && (IP <= end))
    return 1;
  return 0;
}

int main() {
  unsigned int i, MSK_d, adr, MSK_1, MSK_2, IP_1, MSK_2d, IP_2,
      o = 0, ok, n, k;

   // Citire numar seturi de date
  scanf("%u", &k);
  for (i = 0; i < k; i++) {

  	// Citire un set de date
    printf("%u\n", i + 1);

    //	Citire MSK_1
    MSK_1 = citire();

    //Citire MSK_2
    scanf("%u", &MSK_2);

    //	Citire IP_1, IP_2
    IP_1 = citire();
    IP_2 = citire();

    //	Citire numar adrese de retea
    scanf("%u", &n);

    //	Afisare IP_1/MSK_2
    afisare_IP_MSK(IP_1, MSK_2);

    //  Afisare MSK_2 in format zecimal
    printf("-1 ");
    MSK_2d = MSK_zecimal(MSK_2);
    afisare(MSK_2d);
    printf("\n");

    // Afisare MSK_1 in baza 8
    afisare_octa(MSK_1);

    // Afisare MSK_2 in baza 16
    afisare_hexa(MSK_1);

    // Afisare adresa de retea pentru IP_1
    adr = adr_retea(IP_1, MSK_2d);
    printf("-3 ");
    afisare(adr);

    // Afisare adresa de broadcast pt IP_1
    printf("\n-4 ");
    adr = adr_brod(IP_1, MSK_2d);
    afisare(adr);
    printf("\n");

    // Verificare daca IP_1 si IP_2 sunt in aceeasi retea
    if (adr_retea(IP_1, MSK_2d) == adr_retea(IP_2, MSK_2d))
      printf("-5 DA\n");
    else
      printf("-5 NU\n");

  	// Verficare corectitudine MSK_1 si afisare/corectare si afisare
    o = verificare_masca(MSK_1);
    if (o == 1)
      printf("-6 DA\n");
    else
      printf("-6 NU\n");
    if (o == 1) {
      printf("-7 ");
      afisare(MSK_1);
      printf("\n");
    } else {
      printf("-7 ");
      modificare_masca(MSK_1);
      printf("\n");
    }

    // Afisare IP_1 in format binar
    afisare_binar(IP_1);

    // Afisare indici de retele din care IP_2 ar putea face parte 
    printf("-9 ");
    for (o = 0; o < n; o++) {
      unsigned int MSK;
      adr = citire();
      scanf("/%u", &MSK);
      MSK_d = MSK_zecimal(MSK);
      adr = adr & MSK_d;
      ok = verificare_adresa(IP_2, adr, MSK_d);
      if (ok)
        printf("%u ", o);
    }
    printf("\n");
  }
  return 0;
}