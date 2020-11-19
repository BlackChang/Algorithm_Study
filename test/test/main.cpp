//
// Software Pattern Lab#2
// ID:
// Name:
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
struct Index{
   char word[100];
   int num = 0;
   int position[100];
};
// global variable
// idx_length indicate the length of the index array
int idx_length = 0;
//*******************************************************************************************************
// You can only modify inside the function.
// in: text - sample text
// out: index - created index table from sample text
void create_index(char* text, struct Index* index){
    int i = 0;
    int j = 0;
    int idx[100] = {0};
    int length = 0;
    int check = 1;
    char temp[100];
    while(i <= strlen(text)){
        if(text[i] == ' ' || text[i] == '\0'){
            char tmp[100] = "";
            for(int k = 0; k < j; k++){
                tmp[k] = temp[k];
            }
            for(int k = 0; k < idx_length; k++){
                if(strcmp(tmp, index[k].word) == 0){
                    check = 0;
                    index[k].num += 1;
                    index[k].position[idx[k]] = length;
                    idx[k] += 1;
                }
            }
            if(check == 1){
                strcpy(index[idx_length].word, tmp);
                index[idx_length].num += 1;
                index[idx_length].position[idx[idx_length]] = length;
                idx[idx_length] += 1;
                idx_length += 1;
            }
            length += 1;
            j = 0;
            check = 1;

        }
        else
            temp[j++] = text[i];
        i++;
    }
}

// in: index - index table created by create_index function
// in: str - string to find
void print_result(struct Index* index, char* str){
    int idx = 0;
    int check = 0;
    for(int i = 0; i < 100; i++){
        if(strcmp(str, index[i].word) == 0){
            idx = i;
            check = 1;
            break;
        }
    }
    if(check == 1){
        printf("\"%s\" (answer : %d", str, index[idx].num);
        for(int i = 0; i < index[idx].num; i++){
            char temp[100] = "";
            char temp2[100] = "";
            for(int j = 0; j < idx_length; j++){
                for(int k = 0; k < index[j].num; k++){
                    if(index[j].position[k] == index[idx].position[i] + 1)
                        strcpy(temp, index[j].word);
                    else if(index[j].position[k] == index[idx].position[i] + 2)
                        strcpy(temp2, index[j].word);
                }
            }
            printf(", \"%s %s\"", temp, temp2);
        }
        printf(")\n");
    }
    else
        printf("No Word\n");
}
//*******************************************************************************************************

// Do not modify this function
void print_index(struct Index* index){
   printf("word index\n");
   printf("----------------\n");
   for (int i = 0; i < idx_length; i++) {
      printf("%12s, %8d, (", index[i].word, index[i].num);
      for (int j = 0; j < index[i].num; j++) {
         if (j == 0) printf("%d", index[i].position[j]);
         else printf(", %d", index[i].position[j]);
      }
      printf(")\n");
   }
   printf("\n");
}
int main(){
   char sample_text[1024] = "it was the best of times it was the worst of times it was the age of wisdom it was the age of foolishness it was the epoch of belief";
   struct Index index_table[100];

   // create init
   create_index(sample_text, index_table);

   // print_index
   print_index(index_table);

   // get string and find the number of times it occurs and following words
   char str[1024];
   printf("input string: ");
   scanf("%s", str);

   // print result
   // 1. Print the number of occurence
   // 2. Print next two words
   print_result(index_table, str);

   return 1;
}
