int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){
    int num_live_neighbors = 0; //counter for live neighbors around a particular cell
    for(int i = row - 1; i <= row + 1; i++){
        if(i >= 0 && i < boardRowSize){ //border check 1
            for(int j = col - 1; j <= col + 1; j++){
                if(j >= 0 && j < boardColSize){ //border check 2
                    if(i != row || j != col){ //need to make sure it's not the same cell since we care about neighbors
                        if(board[i*boardColSize + j] == 1){ //if it is alive
                            num_live_neighbors++; 
                        }
                    }
                }
            }
        }
    } 
    return num_live_neighbors; 
}

void updateBoard(int* board, int boardRowSize, int boardColSize) {
    int count_live; //basically the output from running 1st function
    int newBoard[boardRowSize * boardColSize]; //need to create new board because updating as we go messes up our computation
    for(int i = 0; i < boardRowSize; i++){
        for(int j = 0; j < boardColSize; j++){
            newBoard[i * boardColSize + j] = board[i * boardColSize + j]; 
        }
    } 
    //new board copied from original
    for(int i = 0; i < boardRowSize; i++){
        for(int j = 0; j < boardColSize; j++){
            count_live = countLiveNeighbor(board, boardRowSize, boardColSize, i, j);
            if(board[i * boardColSize + j] == 1){
                if(count_live < 2 || count_live > 3){
                    newBoard[i * boardColSize + j] = 0; 
                }
            }
                else{
                    if(count_live == 3){
                        newBoard[i * boardColSize + j] = 1; 
                    }
                }
            } 
        }
    //logic completed based on what to do in different possible scenarios as mentioned in directions

    for(int i = 0; i < boardRowSize * boardColSize; i++){ //restoring 
        board[i] = newBoard[i]; 
    }
    }


int aliveStable(int* board, int boardRowSize, int boardColSize){

    int secondBoard[boardRowSize * boardColSize]; //need to create a new board for comparison 
    for(int i = 0; i < boardRowSize; i++){
        for(int j = 0; j < boardColSize; j++){
            secondBoard[i * boardColSize + j] = board[i * boardColSize + j];
        }
    }

    updateBoard(secondBoard, boardRowSize, boardColSize); //updating new board because updating original is an unintended side effect
    
    for(int i = 0; i < boardRowSize; i++){
        for(int j = 0; j < boardColSize; j++){
            if(secondBoard[i * boardColSize + j] != board[i * boardColSize + j]){
                return 0; //immediately know it is different if even one cell is off 
            }
        }
    }
    return 1; //if program makes it till here then the boards are identical so return 1 
}
