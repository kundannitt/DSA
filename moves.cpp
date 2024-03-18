/* 
    chess - knight:-
    int dx[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
    int dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
    for(int i=0;i<8;i++){
        int nrow = row + dx[i];
        int ncol = col + dy[i];
    }
*/

/*
    8-adjacency
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int nrow = row + i;
            int ncol = col + j;
        }
    }
*/

/*
    4-adjacency
    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};
    for(int i=0;i<4;i++){
        int nrow = row + dx[i];
        int ncol = col + dy[i];
    }
*/
