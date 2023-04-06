#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)

#include <glib.h> // https://libsoup.org/glib/glib-Hash-Tables.html#g-hash-table-foreach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cc `pkg-config --cflags glib-2.0` test.c -o test `pkg-config --libs glib-2.0` && ./test
//gcc -o test test.c `pkg-config --libs --cflags glib-2.0` && ./test

static GHashTable* binCodes; 

void init(){
  binCodes = g_hash_table_new(g_str_hash, g_str_equal);
  g_hash_table_insert(binCodes,"Plastics and Aluminium","A");
  g_hash_table_insert(binCodes,"Paper","P");
  g_hash_table_insert(binCodes,"Biodegradable waste","B");
  g_hash_table_insert(binCodes,"Clear glass","G");
  g_hash_table_insert(binCodes,"Colored glass","C");
  g_hash_table_insert(binCodes,"Textile","T");
  //printf("There are %d bin types\n", g_hash_table_size(binCodes));
  //g_hash_table_destroy(binCodes);
}

int isCodeInCodesByName(char type_name[], char codes[] ) {

  //Find the code by name
  char* binCode = g_hash_table_lookup(binCodes,type_name);

  //printf("The code is %s\n", (char *)binCode); 

  return (binCode != NULL && strchr(codes, binCode[0]) != NULL);

}

int isCodeInCodes(char code, char codes[]) {
  
  return (strchr(codes, code) != NULL);
}

int areCodesIncluded(char codes1[], char codes2[]){

   int i;

   for (i = 0; i < strlen(codes1); i++) {
        //printf("value: %d\n", isCodeInCodes(codes1[i], codes2));
	if(!isCodeInCodes(codes1[i], codes2)) return 0;
   }

  return 1;  
}

int main() {

   init();

   // TEST isCodeInCodesByName()
   printf("isCodeInCodesByName 1: %d\n", isCodeInCodesByName("Clear glass", "ABGCP"));       // 1
   printf("isCodeInCodesByName 2: %d\n", isCodeInCodesByName("Clear glass", "ABCP"));        // 0
   printf("isCodeInCodesByName 3: %d\n", isCodeInCodesByName("Biodegradable waste", "BCP")); // 1
   printf("isCodeInCodesByName 4: %d\n", isCodeInCodesByName("Blah Blah Blah", "APBGCT"));   // 0
						
   printf("\n\n");

   // TEST isCodeInCodes()
   printf("isCodeInCodes 1: %d\n", isCodeInCodes('G', "APBGCT")); // 1
   printf("isCodeInCodes 2: %d\n", isCodeInCodes('L', "APBGCT")); // 0
   printf("isCodeInCodes 3: %d\n", isCodeInCodes('Y', "APBGCT")); // 0

   printf("\n\n");

   // TEST areCodesIncluded()
   printf("areCodesIncluded 1: %d\n", areCodesIncluded("GAT", "APBGCT")); // 1
   printf("areCodesIncluded 2: %d\n", areCodesIncluded("LLL", "APBGCT")); // 0
   printf("areCodesIncluded 3: %d\n", areCodesIncluded("JAB", "APBGCT")); // 0

   return 0;
}
