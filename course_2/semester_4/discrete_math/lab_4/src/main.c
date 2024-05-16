#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STATE_COUNT 2
#define ALPHABET_COUNT 4

typedef struct {
    int transitions[ALPHABET_COUNT][STATE_COUNT];
    bool output[ALPHABET_COUNT][STATE_COUNT];
    char alphabet[ALPHABET_COUNT];
    int state;
    int symbol;
} automata;

bool process_word(automata automata, char *word) {
    bool result;
    automata.state = 0;
    for (int char_index = 0;
         char_index < strlen(word);
         ++char_index)
    {
        automata.symbol = word[char_index];
        int alphabet_index;

        for (alphabet_index = 0;
             alphabet_index < ALPHABET_COUNT;
             ++alphabet_index)
        {
            if (automata.alphabet[alphabet_index] == automata.symbol)
                break;
        }

        if (alphabet_index == ALPHABET_COUNT &&
            automata.alphabet[alphabet_index] != automata.symbol)
        {
            printf("Unexpected characters\n");
            return false;
        }

        result = automata.output[alphabet_index][automata.state];
        automata.state = automata.transitions[alphabet_index][automata.state];
    }
    return result;
}

int main(int argc, char *argv[]) {
    automata automata = {0};
    automata.transitions[2][0] = 1;
    automata.output[2][0] = 1;
    automata.alphabet[0] = 'a';
    automata.alphabet[1] = 'b';
    automata.alphabet[2] = 'c';
    automata.alphabet[3] = 'd';

    if (argc == 2) {
        if (process_word(automata, argv[1]))
            printf("Input word \"%s\" is accepting\n", argv[1]);
        else
            printf("Input word \"%s\" doesn't accept\n", argv[1]);
    } else {
        int test_count = 14;
        char *tests[test_count];
        tests[0] = "abc";
        tests[1] = "abdc";
        tests[2] = "c";
        tests[3] = "caccc";
        tests[4] = "ccc";
        tests[5] = "ccccc";
        tests[6] = "abdcabac";
        tests[7] = "a";
        tests[8] = "abcb";
        tests[9] = "babcbbdbcc";
        tests[10] = "cc";
        tests[11] = "cccc";
        tests[12] = "cccccc";
        tests[13] = "bacabcccc";

        for (int test_index = 0; test_index < test_count; ++test_index)
            if (process_word(automata, tests[test_index]))
                printf("Input word \"%s\" is accepting\n", tests[test_index]);
            else
                printf("Input word \"%s\" doesn't accept\n", tests[test_index]);
    }

    return 0;
}
