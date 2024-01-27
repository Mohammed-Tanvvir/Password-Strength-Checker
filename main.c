#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a digit
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a character is an uppercase letter
int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a lowercase letter
int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to check if a character is a special character
int is_special(char c) {
    return !is_digit(c) && !is_upper(c) && !is_lower(c);
}

// Function to check the strength of a password
int check_password_strength(char *password) {
    int length = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

    // Check each character in the password
    for (int i = 0; i < length; i++) {
        if (is_digit(password[i])) {
            has_digit = 1;
        } else if (is_upper(password[i])) {
            has_upper = 1;
        } else if (is_lower(password[i])) {
            has_lower = 1;
        } else if (is_special(password[i])) {
            has_special = 1;
        }
    }

    // Evaluate password strength based on criteria
    int strength = 0;
    if (length >= 8 && has_upper && has_lower && has_digit && has_special) {
        strength = 4; // Strong password
    } else if (length >= 6 && ((has_upper && has_lower) || (has_lower && has_digit))) {
        strength = 3; // Medium password
    } else if (length >= 4 && (has_upper || has_lower || has_digit)) {
        strength = 2; // Weak password
    } else {
        strength = 1; // Very weak password
    }

    return strength;
}

int main() {
    char password[50];

    printf("Enter your password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    // Print the strength of the password
    switch (strength) {
        case 1:
            printf("Very weak password.\n");
            break;
        case 2:
            printf("Weak password.\n");
            break;
        case 3:
            printf("Medium password.\n");
            break;
        case 4:
            printf("Strong password.\n");
            break;
        default:
            printf("Invalid password.\n");
    }

    return 0;
}
