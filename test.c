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

  //g_hash_table_destroy(binCodes);
}

int isType(char type_name[], char codes[] ) {

  // printf("There are %d bin types\n", g_hash_table_size(binCodes));
  char* binCode = g_hash_table_lookup(binCodes,type_name);

  // printf("The code is %s\n", (char *)binCode); 

  return (strchr( codes, binCode[0]) != NULL);

}


int main() {

   init();
   printf("Is type code: %d\n", isType("Clear glass", "ABGCP"));

   return 0;
}
