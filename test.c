#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cc `pkg-config --cflags glib-2.0` test.c -o test `pkg-config --libs glib-2.0` && ./test


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

int isCodes


int main() {

   init();

   // TEST isCodeInCodesByName()
   printf("Is type code: %d\n", isCodeInCodesByName("Clear glass", "ABGCP")); // 1
   printf("Is type code: %d\n", isCodeInCodesByName("Clear glass", "ABCP")); // 0
   printf("Is type code: %d\n", isCodeInCodesByName("Biodegradable waste", "BCP")); // 1
   printf("Is type code: %d\n", isCodeInCodesByName("Blah Blah Blah", "APBGCT")); // 0
						


   // TEST isCodeInCodes()
   printf("Is type code: %d\n", isCodeInCodes("G", "APBGCT")); // 1
   printf("Is type code: %d\n", isCodeInCodes("L", "APBGCT")); // 0
   printf("Is type code: %d\n", isCodeInCodes("J", "APBGCT")); // 0

   return 0;
}
