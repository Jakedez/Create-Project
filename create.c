#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>

const char * C_LANGUAGE = "cproject";
const char * C_PLUS_PLUS = "cplusproject";
const char * C_SHARP = "csproject";
const char * PYTHON = "pyproject";
const char * PERL = "plproject";
const char * RAYLIB = "rlproject";
const char * ASM = "asm";

bool hasSpaces(char * string){
    int length = strlen(string);
    for (int i = 0; i < length; i++){
        if (string[i] == 32){
            return true;
        }
    }
    return false;
}

void addExtension(char * filename, char * extension){
    if (strcmp(&filename[strlen(filename)-strlen(extension)], extension)){
        strcat(filename, extension);
    }
    return;
}



void switchSpaces(char * target, char * destination){
    int length = strlen(target);
    for (int i = 0; i < length; i++){
        if (target[i] != 32){ // if target character is not [space]
            destination[i] = target[i];
        }
        else{
            destination[i] = 95; //switches spaces with underscores '_'
        }
    }
    destination[length] = 0;
    return;
}

void displayHelp(void){
    puts("\nCreates a new project");
    puts("Usage: create [project-type] [project-name]\n");
    puts(" Types:");
    puts("  cproject          Creates a C language Project");
    puts("  cplusproject      Creates a C Plus Plus Project");
    puts("  csproject         Creates a C-Sharp Project using .NET framework");
    puts("  pyproject         Creates a Python Project");
    puts("  plproject         Creates a Perl Project");
    puts("  rlproject         Creates a Raylib Project in C for a VSCode Workspace\n\n");
    puts("  asm               Creates an assembly template with at&t syntax");
    return;
}

int main(int argc, char ** argv){

    if (argc < 2){
        displayHelp();
    }
    else{
        FILE * file;
        #ifdef _WIN64
        errno_t result;
        #endif
        char filename[FILENAME_MAX];
        if (!strcmp(argv[1], C_LANGUAGE) && argc > 2){
            strcpy(filename, argv[2]);
            addExtension(filename, ".c");
        #ifdef _WIN64
            result = fopen_s(&file, filename, "wt");
            if (!result){
        #endif
        #ifdef __linux__
            file = fopen(filename, "wt");
            if (file){
        #endif
                fprintf(file, "#include <stdio.h>\n");
                fprintf(file, "#include <stdlib.h>\n\n");
                fprintf(file, "int main(int argc, char ** argv){\n\n");
                fprintf(file, "    return EXIT_SUCCESS;\n");
                fprintf(file, "}");
                fclose(file);
            }
        }
        else if (!strcmp(argv[1], PYTHON) && argc > 2){
            strcpy(filename, argv[2]);
            addExtension(filename, ".py");
        #ifdef _WIN64
            result = fopen_s(&file, filename, "wt");
            if (!result){
        #endif
        #ifdef __linux__
            file = fopen(filename, "wt");
            if (file){
        #endif
                fprintf(file, "def main():\n");
                fprintf(file, "    \n");
                fprintf(file, "    return\n\n\n");
                fprintf(file, "if __name__ == \"__main__\":\n");
                fprintf(file, "    main()\n");
                
                fclose(file);
            }
        }
        else if (!strcmp(argv[1], C_PLUS_PLUS) && argc > 2){
            strcpy(filename, argv[2]);
            addExtension(filename, ".cpp");
        #ifdef _WIN64
            result = fopen_s(&file, filename, "wt");
            if (!result){
        #endif
        #ifdef __linux__
            file = fopen(filename, "wt");
            if (file){
        #endif
                fprintf(file, "#include <cstdio>\n");
                fprintf(file, "#include <cstdlib>\n\n");
                fprintf(file, "int main(int argc, char ** argv){\n\n");
                fprintf(file, "    return EXIT_SUCCESS;\n");
                fprintf(file, "}");
                
                fclose(file);
            }
        }
        else if (!strcmp(argv[1], PERL) && argc > 2){
            strcpy(filename, argv[2]);
            addExtension(filename, ".pl");
        #ifdef _WIN64
            result = fopen_s(&file, filename, "wt");
            if (!result){
        #endif
        #ifdef __linux__
            file = fopen(filename, "wt");
            if (file){
        #endif
                fprintf(file, "sub main{\n");
                fprintf(file, "    \n");
                fprintf(file, "    return;\n");
                fprintf(file, "}\n\n");
                fprintf(file, "main();");
                
                fclose(file);
            }
        }
        else if (!strcmp(argv[1], C_SHARP) && argc > 2){
            char folderCMD[FILENAME_MAX] = "mkdir ";
            char makecmd[FILENAME_MAX] = "dotnet new console -o ";
            char programName[FILENAME_MAX];
            if (hasSpaces(argv[2])){
                char temp[FILENAME_MAX] = "\"";
                strcat(temp, argv[2]);
                strcat(temp, "\"");
                strcat(folderCMD, temp);
                strcat(makecmd, temp);
            }
            else{
                strcat(folderCMD, argv[2]);
                strcat(makecmd, argv[2]);
            }
            system(folderCMD);
            system(makecmd);
            strcat(programName, argv[2]);
            strcat(programName, "/");
            strcat(programName, "Program.cs");
            char namespace[FILENAME_MAX];
            switchSpaces(argv[2], namespace);
        #ifdef _WIN64
            result = fopen_s(&file, filename, "wt");
            if (!result){
        #endif
        #ifdef __linux__
            file = fopen(filename, "wt");
            if (file){
        #endif
                fprintf(file, "using System;\n");
                fprintf(file, "using System.Collections.Generic;\n\n\n");
                fprintf(file, "namespace %s{\n", namespace);
                fprintf(file, "    public class Program{\n");
                fprintf(file, "        public static void Main(string[] argv){\n");
                fprintf(file, "            \n");
                fprintf(file, "            return;\n");
                fprintf(file, "        }\n");
                fprintf(file, "    }\n");
                fprintf(file, "}\n");
                fclose(file);
            }
        }
        else if (!strcmp(argv[1], RAYLIB) && argc > 2){
            struct stat sb;
            if (stat("C:\\raylib\\raylib\\projects\\VSCode", &sb) == 0 && S_ISDIR(sb.st_mode)){
                strcpy(filename, argv[2]);
                if (hasSpaces(argv[2])){
                    strcpy(filename, "\"");
                    strcat(filename, argv[2]);
                    strcat(filename, "\"");
                }
                else{
                    strcpy(filename, argv[2]);
                }
                char folderCMD[FILENAME_MAX] = "mkdir ";
                char makecmd[FILENAME_MAX] = "xcopy /E C:\\raylib\\raylib\\projects\\VSCode ";
                strcat(folderCMD, filename);
                strcat(makecmd, filename);
                system(folderCMD);
                system(makecmd);
            }
            else{
                puts("Raylib is either not installed, or is not installed at the expected directory");
            }
        }
        else if (!strcmp(argv[1], "/?")){
            displayHelp();
        }
        else if (!strcmp(argv[1], ASM) && argc > 2){
            strcpy(filename, argv[2]);
            addExtension(filename, ".s");
        #ifdef _WIN64
            result = fopen_s(&file, filename, "wt");
            if (!result){
        #endif
        #ifdef __linux__
            file = fopen(filename, "wt");
            if (file){
        #endif
                fprintf(file, ".section .data\n\n\n\n");
                fprintf(file, ".section .text\n\n");
                fprintf(file, ".globl main\n\n");
                fprintf(file, "main:\n");
                fprintf(file, "pushq %%rbp\n");
                fprintf(file, "movq %%rsp, %%rbp\n\n\n\n");
                
                
        #ifdef _WIN64
                fprintf(file, "popq %%rbp\n");
        #endif
        #ifdef __linux__
                fprintf(file, "leave\n");
        #endif
                fprintf(file, "retq\n");
                fprintf(file, "\n");
                
                fclose(file);
            }
        }
        else if (argc == 2 && (!strcmp(argv[1], C_SHARP) || !strcmp(argv[1], PYTHON) || !strcmp(argv[1], C_LANGUAGE) || !strcmp(argv[1], C_PLUS_PLUS)  || !strcmp(argv[1], PERL) || !strcmp(argv[1], RAYLIB) || !strcmp(argv[1], ASM))){
            displayHelp();

        }
        else{
            strcpy(filename, argv[1]);
            addExtension(filename, ".c");
        #ifdef _WIN64
            result = fopen_s(&file, filename, "wt");
            if (!result){
        #endif
        #ifdef __linux__
            file = fopen(filename, "wt");
            if (file){
        #endif
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