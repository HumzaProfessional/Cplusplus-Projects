.global fast_choice
.global check_riddle

@ Optimized jump table for choices
fast_choice:
    CMP R0, #2         @ If input > 2, invalid choice
    BHI invalid_choice
    SUB R0, R0, #1     @ Convert 1-based input to 0-based index
    BX LR              @ Return index in R0

invalid_choice:
    MOV R0, #-1        @ Return -1 for invalid input
    BX LR

@ Puzzle checking function
check_riddle:
    CMP R0, #1         @ Check if puzzle ID is 1 (right path puzzle)
    BEQ right_riddle
    MOV R0, #0         @ If invalid puzzle ID, return 0 (fail)
    BX LR

right_riddle:
    LDR R1, =correct_answer1
    BL strcmp          @ Call C strcmp function
    CMP R0, #0
    MOVEQ R0, #1       @ Return 1 if correct
    MOVNE R0, #0       @ Return 0 if incorrect
    BX LR

@ Data Section
correct_answer1: .asciz "keyboard"
