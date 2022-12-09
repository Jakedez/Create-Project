#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addExtension(char * filename, char * extension){
    if (strcmp(&filename[strlen(filename)-strlen(extension)], extension)){
        strcat(filename, extension);
    }
    return;
}

void displayHelp(void){
    puts("\nCreates a new project");
    puts("Usage: create [project-type] [project-name]\n");
    puts(" Types:");
    puts("  cproject          Creates a C language Project");
    puts("  cplusproject      Creates a C Plus Plus Project");
    puts("  csproject         Creates a C-Sharp Project");
    puts("  pyproject         Creates a Python Project");
    puts("  plproject         Creates a Perl Project\n\n");
    return;
}

int main(int argc, char ** argv){
    if (argc < 2){
        displayHelp();
    }
    else{
        FILE * file;
        errno_t result;
        char filename[FILENAME_MAX];
        if (!strcmp(argv[1], "cproject") && argc > 2){
            strcpy(filename, argv[2]);
            addExtension(filename, ".c");
            result = fopen_s(&file, filename, "wt");
            if (!result){
                fprintf(file, "#include <stdio.h>\n");
                fprintf(file, "#include <stdlib.h>\n\n");
                fprintf(file, "int main(int argc, char ** argv){\n\n");
                fprintf(file, "    return EXIT_SUCCESS;");
                fprintf(file, "}");
                fclose(file);
            }
        }
        else if (!strcmp(argv[1], "pyproject") && argc > 2){
            strcpy(filename, argv[2]);
            addExtension(filename, ".py");
            result = fopen_s(&file, filename, "wt");
            if (!result){
                fprintf(file, "def main():\n");
                fprintf(file, "    \n");
                fprintf(file, "    return\n\n\n");
                fprintf(file, "if __name__ == \"__main__\":\n");
                fprintf(file, "    main()\n");
                
                fclose(file);
            }
        }
        else if (!strcmp(argv[1], "cplusproject") && argc > 2){
            strcpy(filename, argv[2]);
            addExtension(filename, ".cpp");
            result = fopen_s(&file, filename, "wt");
            if (!result){
                fprintf(file, "#include <cstdio>\n");
                fprintf(file, "#include <cstdlib>\n\n");
                fprintf(file, "int main(int argc, char ** argv){\n\n");
                fprintf(file, "    return EXIT_SUCCESS;");
                fprintf(file, "}");
                
                fclose(file);
            }
        }
        else if (!strcmp(argv[1], "plproject") && argc > 2){
            strcpy(filename, argv[2]);
            addExtension(filename, ".pl");
            result = fopen_s(&file, filename, "wt");
            if (!result){
                fprintf(file, "sub main{\n");
                fprintf(file, "    \n");
                fprintf(file, "    return;\n");
                fprintf(file, "}\n\n");
                fprintf(file, "main();");
                
                fclose(file);
            }
        }
        else if (!strcmp(argv[1], "csproject") && argc > 2){
            char folderCMD[FILENAME_MAX] = "mkdir ";
            char makecmd[FILENAME_MAX] = "dotnet new console -o ";
            strcat(folderCMD, argv[2]);
            strcat(makecmd, argv[2]);
            system(folderCMD);
            system(makecmd);
        }
        else if (!strcmp(argv[1], "/?")){
            displayHelp();
        }
        else if (argc == 2 && (!strcmp(argv[1], "csproject") || !strcmp(argv[1], "pyproject") || !strcmp(argv[1], "cproject") || !strcmp(argv[1], "cplusproject")  || !strcmp(argv[1], "plproject"))){
            displayHelp();

        }
        else{
            strcpy(filename, argv[1]);
            addExtension(filename, ".c");
            result = fopen_s(&file, filename, "wt");
            if (!result){
                fprintf(file, "#include <stdio.h>\n");
                fprintf(file, "#include <stdlib.h>\n\n");
                fprintf(file, "int main(int argc, char ** argv){\n\n");
                fprintf(file, "    return EXIT_SUCCESS;\n");
                fprintf(file, "}");
                fclose(file);
            }
        }
    }
    return EXIT_SUCCESS;
}