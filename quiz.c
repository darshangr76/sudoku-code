#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char question[200];
    char options[4][100];
    int answer;
} Question;

void showQuestion(Question q, int number) {
    printf("\n-----------------------------\n");
    printf("Question %d\n", number);
    printf("-----------------------------\n");

    printf("%s\n\n", q.question);

    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int main() {

    Question quiz[] = {

        {
            "Which language is mainly used for system programming?",
            {"Python", "C", "HTML", "SQL"},
            2
        },

        {
            "Which data structure follows LIFO?",
            {"Queue", "Stack", "Array", "Linked List"},
            2
        },

        {
            "What is the size of an int commonly on modern systems?",
            {"1 byte", "2 bytes", "4 bytes", "8 bytes"},
            3
        },

        {
            "Which symbol is used for a single-line comment in C?",
            {"//", "/*", "#", "<!--"},
            1
        },

        {
            "Which function is used to print output in C?",
            {"scanf()", "print()", "printf()", "display()"},
            3
        },

        {
            "Which keyword is used to define a constant variable?",
            {"constant", "const", "static", "fixed"},
            2
        },

        {
            "Which operator is used to compare two values?",
            {"=", "==", "!=", "+="},
            2
        },

        {
            "Which header file is required for printf()?",
            {"stdlib.h", "string.h", "stdio.h", "math.h"},
            3
        },

        {
            "Which loop executes at least once?",
            {"for", "while", "do-while", "if"},
            3
        },

        {
            "What does CPU stand for?",
            {"Central Processing Unit",
             "Computer Personal Unit",
             "Central Program Utility",
             "Control Processing Unit"},
            1
        }
    };

    int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);
    int score;
    int answer;
    char choice;

    do {

        score = 0;

        printf("\n====================================\n");
        printf("          C QUIZ GAME\n");
        printf("====================================\n");

        for (int i = 0; i < totalQuestions; i++) {

            showQuestion(quiz[i], i + 1);

            do {
                printf("\nEnter your answer (1-4): ");
                scanf("%d", &answer);

                if (answer < 1 || answer > 4) {
                    printf("Invalid choice! Please enter 1-4.\n");
                }

            } while (answer < 1 || answer > 4);

            if (answer == quiz[i].answer) {
                printf("Correct! ✓\n");
                score++;
            } else {
                printf("Wrong! ✗\n");
                printf("Correct answer: %s\n",
                       quiz[i].options[quiz[i].answer - 1]);
            }
        }

        printf("\n====================================\n");
        printf("             QUIZ RESULT\n");
        printf("====================================\n");

        printf("Score      : %d/%d\n", score, totalQuestions);
        printf("Percentage : %.2f%%\n",
               (score * 100.0) / totalQuestions);

        if (score == totalQuestions) {
            printf("Excellent! Perfect score!\n");
        } else if (score >= 7) {
            printf("Great job!\n");
        } else if (score >= 5) {
            printf("Good effort! Keep practicing.\n");
        } else {
            printf("Keep learning and try again!\n");
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThanks for playing!\n");

    return 0;
}