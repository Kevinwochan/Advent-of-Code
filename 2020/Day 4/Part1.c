#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Passport {
  int birthYear;
  int issueYear;
  int expirationYear;
  char height[7];
  char eyeColor[5];
  char passportId[11];
} typedef Passport;

Passport *initPassport() {

  Passport *ps = malloc(sizeof(struct Passport));
  ps->birthYear = -1;
  ps->issueYear = -1;
  ps->expirationYear = -1;
  strcpy(ps->height, "None");
  strcpy(ps->eyeColor, "None");
  strcpy(ps->passportId, "None");
  return ps;
}

void destroyPassport(Passport *ps) { free(ps); }

void printPassport(Passport ps) {
  printf("== Passport ==\n");
  printf("ID: %s\nbirth year %d\nissue year %d\nexpiration year %d\nheight "
         "%s\neye color %s\n",
         ps.passportId, ps.birthYear, ps.issueYear, ps.expirationYear,
         ps.height, ps.eyeColor);
}

Passport *parsePassportEntry(char *string) {
  Passport *ps = NULL;
  // Passport *ps = initPassport();
  char key[3];
  char value[11];
  while (sscanf(string, "%s:%s ", key, value) > 0) {
    printf("Found key: %s\n", key);
    printf("Found val: %s\n", value);
  }
  return ps;
}

int main(void) {
  FILE *fp = fopen("sample.txt", "r");
  if (fp == NULL)
    printf("File could not be opened");

  char buffer[255];
  int i = 0;
  while (fscanf(fp, "%[^\n\n]", buffer) > 0) {
    // Passport *ps = parsePassportEntry(buffer);
    printf("%d: %s\n", ++i, buffer);
    // parsePassportEntry(buffer);
    // printPassport(*ps);
    // destroyPassport(ps);
  }
  fclose(fp);
}
