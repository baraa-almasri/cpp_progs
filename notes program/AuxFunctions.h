#ifndef AUXFUNCTIONS_H
#define AUXFUNCTIONS_H
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
// red color output
#define RED "\033[31m"
// reset color output
#define RESET "\033[0m"
typedef void (*function)(void);
// list files in current directory
void listDir(char *directoryName){
    puts("Available files:");
    struct dirent *directoryEntry;  // Pointer for directory entry 
    // opendir() returns a pointer of DIR type.  
    DIR *directoryPtr = opendir(directoryName); 
    // opendir returns NULL if couldn't open directory
    if (directoryPtr == NULL){ 
        printf("Could not open current directory" ); 
        return; 
    } 
    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html 
    // for readdir() 
    while ((directoryEntry = readdir(directoryPtr)) != NULL)
        if( directoryEntry->d_name[0] != '.' ) 
            printf("%s\n", directoryEntry->d_name); 
    // close directory after being done with it
    closedir(directoryPtr); 
}

// create new note
void addNote(){
    printf("\nenter note name:  ");
    char noteName[99];
    scanf("%s", &noteName);
    FILE *noteFile;
    noteFile = fopen(noteName, "w");
    puts("enter your note type 'qq' when you are done");
    char note[99];
    while(1){
        scanf("%s", &note);
        if(note[0] == 'q' && note[1] == 'q')
            break;
        // append a space to the string for better formatting in the file
        strcat(note, " ");
        fputs(note, noteFile);
    }
}

// add to existing note
void addToNote(){
    printf("\nenter note name:  ");
    char noteName[99];
    scanf("%s", &noteName);
    FILE *noteFile;
    
    // open file in read mode to see the current note
    noteFile = fopen(noteName, "r");
    puts("\ncurrent file content:");    
    while(!feof(noteFile)){
        printf("%c", fgetc(noteFile));
    }

    fclose(noteFile);
    // reopen file in append mode
    noteFile = fopen(noteName, "a");
    puts("\nenter your note type 'qq' when you are done");
    char note[99];
    while(1){
        scanf("%s", &note);
        if(note[0] == 'q' && note[1] == 'q')
            break;
        // append a space to the string for better formatting in the file
        strcat(note, " ");
        fputs(note, noteFile);
    }

    fclose(noteFile);
}

// delete a note
void deleteNote(){
    printf("\nenter note name:  ");
    char noteName[99];
    scanf("%s", &noteName);
    remove(noteName);
}


// necessary for some reason :)
void hold(){
    puts("\n\tpress enter to continue....");
    // getchar is used to input a character
    while(getchar() != '\n');
}

// cross platform clear screen
void clear(){
    int counter = 0;
    while(counter < 100){
        puts("\n");
        counter++;
    }
}

// welcome screen
void welcome(){
    clear();
    puts("\n\tTerminal notes taking program!!\n");
    puts("\tBy Baraa Al-Masri . version 0.001");
    hold();
    clear();
}

// menu
int menu(){
    clear();
    listDir(".");
    puts("\n----------------------");
    puts("Available actions:");
    puts("1. Add a new note");
    puts("2. Add to existing note");
    puts("3. Delete note");
    puts("4. Exit");
    printf("\nenter a choice:  ");
    int choice;
    scanf("%d", &choice);

    return choice;
}
// 
void quit(){
    puts(RED);
    puts("have a nice day!");
    puts(RESET);
    exit(0);
}
// action taker
void actionChooser(){
    while(1){
        int choice = menu();
        function functions[] = {&addNote, &addToNote, &deleteNote, &quit};

        if(choice <= 4) 
            functions[choice - 1]();
        else
            continue;

        hold();
        
    }
}

#endif // AUXFUNCTIONS