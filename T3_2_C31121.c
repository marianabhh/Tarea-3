#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

int NumeroValido(const char *str) {
    if (str == NULL || *str == '\0') {
        return 0;
    }
    
    // Verificar cada caracter
    for (const char *p = str; *p != '\0'; p++) {
        if (*p == '\n') continue; // Ignorar salto de línea
        if (!isdigit(*p)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char line[MAX_LINE_LENGTH];
    int line_num = 0;

    while (fgets(line, sizeof(line), stdin)) {
        line_num++;
        // Eliminar salto de línea
        line[strcspn(line, "\n")] = '\0';
        
        if (NumeroValido(line)) {
            // Escribir a stdout (redirigido a output.txt)
            printf("Número: '%s'\n", line);
        } else {
            // Escribir a stderr (redirigido a error.txt)
            fprintf(stderr, "Error - Línea inválida: '%s'\n", line);
        }
    }

    return 0;
}