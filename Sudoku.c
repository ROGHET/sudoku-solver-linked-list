#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 9

typedef struct Node {
    int r, c;
    struct Node *next;
} Node;

int board[N][N] = {
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},

    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},

    {0,6,0, 0,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9}
};

void print_board(int b[N][N]) {
    int i, j;
    printf("\n+-------+-------+-------+\n");
    for (i = 0; i < N; ++i) {
        printf("| ");
        for (j = 0; j < N; ++j) {
            if (b[i][j] == 0) printf(". ");
            else printf("%d ", b[i][j]);
            if ((j+1)%3 == 0) printf("| ");
        }
        printf("\n");
        if ((i+1)%3 == 0) printf("+-------+-------+-------+\n");
    }
    printf("\n");
}

int is_safe(int b[N][N], int r, int c, int num) {
    int i, j, startRow, startCol;
    for (i = 0; i < N; ++i) {
        if (b[r][i] == num) return 0;
        if (b[i][c] == num) return 0;
    }
    startRow = r - r % 3;
    startCol = c - c % 3;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j)
            if (b[startRow + i][startCol + j] == num) return 0;
    return 1;
}

Node* build_empty_list(int b[N][N]) {
    Node *head = NULL, *tail = NULL;
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (b[i][j] == 0) {
                Node *nd = (Node*)malloc(sizeof(Node));
                if (!nd) { perror("malloc"); exit(1); }
                nd->r = i; nd->c = j; nd->next = NULL;
                if (!head) head = tail = nd;
                else { tail->next = nd; tail = nd; }
            }
        }
    }
    return head;
}

void free_list(Node *head) {
    Node *cur = head;
    while (cur) {
        Node *tmp = cur->next;
        free(cur);
        cur = tmp;
    }
}

int solve_with_list(int b[N][N], Node *node) {
    if (node == NULL) return 1;
    int r = node->r, c = node->c, num;
    for (num = 1; num <= 9; ++num) {
        if (is_safe(b, r, c, num)) {
            b[r][c] = num;
            if (solve_with_list(b, node->next)) return 1;
            b[r][c] = 0;
        }
    }
    return 0;
}

void play_mode(int b[N][N]) {
    int r, c, num;
    char line[100];
    printf("Enter moves in the form: row col number (1-based). Enter 's' to show board, 'q' to quit.\n");
    while (1) {
        printf("command> ");
        if (!fgets(line, sizeof(line), stdin)) break;
        if (line[0] == 'q' || line[0] == 'Q') {
            printf("Quitting play mode.\n");
            break;
        } else if (line[0] == 's' || line[0] == 'S') {
            print_board(b);
            continue;
        }
        if (sscanf(line, "%d %d %d", &r, &c, &num) == 3) {
            if (r < 1 || r > 9 || c < 1 || c > 9 || num < 1 || num > 9) {
                printf("Invalid values. Rows/cols/numbers must be 1..9.\n");
                continue;
            }
            r--; c--;
            if (b[r][c] != 0) {
                printf("That cell is already filled (value %d). To change it, clear it first by entering 0 as the number.\n", b[r][c]);
                continue;
            }
            if (!is_safe(b, r, c, num)) {
                printf("Number %d cannot be placed at (%d,%d) due to Sudoku rules.\n", num, r+1, c+1);
                continue;
            }
            b[r][c] = num;
            print_board(b);
            int solved = 1, i, j;
            for (i = 0; i < N && solved; ++i)
                for (j = 0; j < N; ++j)
                    if (b[i][j] == 0) { solved = 0; break; }
            if (solved) {
                printf("Congratulations — puzzle looks filled. We'll verify correctness...\n");
                int ok = 1;
                for (i = 0; i < N && ok; ++i)
                    for (j = 0; j < N; ++j)
                        if (!is_safe(b, i, j, b[i][j])) { ok = 0; break; }
                if (ok) printf("Puzzle solved correctly!\n");
                else printf("Note: board is full but violates Sudoku rules somewhere.\n");
                break;
            }
        } else {
            printf("Couldn't parse input. Use: row col number OR 's' to show board, 'q' to quit.\n");
        }
    }
}

void copy_board(int src[N][N], int dst[N][N]) {
    int i, j;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j)
            dst[i][j] = src[i][j];
}

int main(void) {
    int choice;
    int working[N][N];
    Node *emptyList = NULL;

    printf("Simple Sudoku (C) with linked list of empty cells\n");
    copy_board(board, working);
    print_board(working);

    while (1) {
        printf("Choose: 1) Play manually 2) Auto-solve 3) Show initial puzzle 4) Exit\n");
        printf("Enter 1-4: ");
        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != EOF && ch != '\n');
            continue;
        }
        int ch; while ((ch = getchar()) != EOF && ch != '\n');

        if (choice == 1) {
            copy_board(board, working);
            print_board(working);
            printf("Entering play mode. To quit play mode type 'q' on a new line.\n");
            play_mode(working);
            printf("Returning to menu.\n");
        } else if (choice == 2) {
            copy_board(board, working);
            emptyList = build_empty_list(working);
            if (!emptyList) {
                printf("No empty cells: the puzzle is already full.\n");
                print_board(working);
            } else {
                printf("Solving...\n");
                if (solve_with_list(working, emptyList)) {
                    printf("Solved puzzle:\n");
                    print_board(working);
                } else {
                    printf("No solution exists for this puzzle.\n");
                }
            }
            free_list(emptyList);
            emptyList = NULL;
        } else if (choice == 3) {
            printf("Initial puzzle:\n");
            print_board(board);
        } else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}
