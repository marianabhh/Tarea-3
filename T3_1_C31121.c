#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char ch;
    int count = 0;

    printf("Ingrese un string: "); // El usuario ingresa el string
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Esta línea elimina el carácter \n que se genera por presionar "enter"

    printf("Ingrese el caracter a contar: ");
    scanf("%c", &ch);

    for (int i = 0; str[i] != '\0'; i++) { // Cuenta el caracter que se especificó anteriormente
        if (str[i] == ch) {
            count++;
        }
    }

    printf("El caracter '%c' aparece %d veces.\n", ch, count); 

    printf("String en orden inverso: "); // Recorre el string y lo imrprime al revés
    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}