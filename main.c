#define ecERR_FAULT                 -3
#define ecERR_CARD_NOT_VALID        -2
#define ecERR_CARD_ALREADY_EXIST    -1    
#define ecERR_OK                    0
#define ecERR_INIT_ERR              1
#define ecERR_NO_ARGUM              2
#include <stdlib.h>
#include <string.h>
// TODO: [Optional] Think about an appropriate division of the solution into files.
//                  e.g. Move data loading and validating to another .c file.

//#include "data_source.h" // TODO: Read the content of this file.
#include "data_source.c"
#include "stdio.h"
// const char *get_container_id(size_t line_index);
// const char *get_container_x(size_t line_index);
// const char *get_container_y(size_t line_index);
// const char *get_container_waste_type(size_t line_index);
// const char *get_container_capacity(size_t line_index);
// const char *get_container_name(size_t line_index);
// const char *get_container_street(size_t line_index);
// const char *get_container_number(size_t line_index);
// const char *get_container_public(size_t line_index);
// const char *get_path_a_id(size_t line_index);
// const char *get_path_b_id(size_t line_index);
// const char *get_path_distance(size_t line_index);


int main(int argc, char *argv[])
{
    // TODO: Read and validate options.
    //                                      argv[argc-2]                             argv[argc-1]
    if (argc>2){if (!init_data_source(".\\data\\Brno-BosonohyContainers.csv", ".\\data\\Brno-BosonohyPaths.csv")) return ecERR_INIT_ERR;} else return ecERR_NO_ARGUM;
    
  char m,m1,m2; 
  // int capas1,capas2;
  // char param_t[10],param_c1[10]

  for(int i=1;i<argc-2;i++){
    m=argv[i][0];
    m1=argv[i][1];
    m2=argv[i][2];
    if (strcmp(argv[i],"-t")==0) printf("%i '%c' '%c' '%c'\n",i,m,m1,m2);


  } ;
for(int i=1;i<argc-2;i++){
     m=argv[i][0];
    m1=argv[i][2];
    m2=argv[i][3];
    if (1==1) printf("%i--%c-%c-%c",i,m,m1,m2);


  } ;



printf("\n");
    
    // get_container_id(0);
    char ddd[150];
    int ll=0;
    while (get_container_id(ll))
    {
      strcpy(&ddd[0],get_container_id(ll));
      strncpy(&ddd[10],get_container_x(ll),9);ddd[17]='\0';
      strncpy(&ddd[20],get_container_y(ll),9);ddd[27]='\0';
      strcpy(&ddd[30],get_container_waste_type(ll));
      strcpy(&ddd[60],get_container_capacity(ll)); 
      strcpy(&ddd[70],get_container_name(ll));
      strcpy(&ddd[100],get_container_public(ll));



      // printf("_id= %s ", ddd );
      // printf("_x= %s ", &ddd[50]);
      // printf("_y= %s ", &ddd[75]);
      // printf("_cc= %s \n", &ddd[100]);

      printf("ID: %s, Type: %s, Capacity: %s, Address: %s, Neighbors: --\n", &ddd[0],&ddd[30],&ddd[60],&ddd[70]);
      ll++;

    }
        // A → Plastics and Aluminium
        // P → Paper
        // B → Biodegradable waste
        // G → Clear glass
        // C → Colored glass
        // T → Textile
    // for (int i=(int)'F', i<'H',i++)
    // ddd[0]=+'f';
    // ddd[1]=+'d';
    // ddd[2]=+'s';

    // ddd[3]=+'\0';
    // strcpy(&ddd[0],argv[1]);
    // size_t length = strlen(ddd);
    // ++length;
    //"23949,16.53049228900005,49.17545125700008,Plastics and Aluminium,1100,Bosonozske namesti 35,Bosonozske namesti,669,Y";
   
   // char cn20;
    //scanf("%c",ddd);
   // char cn=get_container_number(1);
    printf("argN=%i\n",argc);
    for (int i=0; i < argc;i++) {printf("arg%i=%s \n",i,argv[i]); }


    // printf("ParamN%i, arg1=%s- ",argv[1],argc, ddd );



    // TODO: Save data to your own structures.


    destroy_data_source(); // If you forget to do this, Valgrind will yell at you a lot.

    // TODO: Process the data as the user wishes and print them to the stdin.
     scanf("%c",ddd);
    return EXIT_SUCCESS; // May your program be as successful as this macro. Good luck!
}
