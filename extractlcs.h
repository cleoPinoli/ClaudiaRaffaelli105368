#ifndef CLAUDIARAFFAELLI105368_EXTRACTLCS_H
#define CLAUDIARAFFAELLI105368_EXTRACTLCS_H
typedef struct {
    int lcs_size;
    char* lcs_output;
} LCS_params;

typedef struct {
    int** adj;
    int* occurrences;
} matrix_params;


LCS_params* compute_lcs();




#endif
