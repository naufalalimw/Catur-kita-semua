#include <stdio.h>
#include <stdlib.h>
#include "move.h"

boolean isAlly (int team1, int team2){
    return (team1 == team2);
}

boolean isPieces (char pieces){
    return (pieces != ' ');
}

boolean isPiecesMove (List L, TabChar T, char pieces, coordinat CurrCoor){
    coordinat NextCoor;
    addressList CurrP, NextP;

    CurrCoor.hor = CharToInt(&CurrCoor.hor);

    CurrP = SearchList(L,pieces,CurrCoor);

    if ((pieces == 'R') && (pieces == 'r')){
        NextCoor.ver = CurrCoor.ver + 1;
        NextCoor.hor = CurrCoor.hor;
        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
        if (NextP != Nil){
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                return true;  
            }else{
                NextCoor.ver = CurrCoor.ver;
                NextCoor.hor = CurrCoor.hor + 1;
                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                    return true;  
                }else{
                    NextCoor.ver = CurrCoor.ver - 1;
                    NextCoor.hor = CurrCoor.hor;
                    NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                    if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                        return true;
                    }else{
                        NextCoor.ver = CurrCoor.ver;
                        NextCoor.hor = CurrCoor.hor - 1;
                        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                        if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                            return true;
                        }else{
                            return false;
                        }
                    }
                }
            }
        }else{
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                return true;  
            }else{
                NextCoor.ver = CurrCoor.ver;
                NextCoor.hor = CurrCoor.hor + 1;
                if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                    return true;  
                }else{
                    NextCoor.ver = CurrCoor.ver - 1;
                    NextCoor.hor = CurrCoor.hor;
                    if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                        return true;
                    }else{
                        NextCoor.ver = CurrCoor.ver;
                        NextCoor.hor = CurrCoor.hor - 1;
                        if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                            return true;
                        }else{
                            return false;
                        }
                    }
                }
            }
        }
    }else if ((pieces == 'H') && (pieces == 'h')){
        NextCoor.hor = CurrCoor.hor - 2;
        NextCoor.ver = CurrCoor.ver + 1;
        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
        if (NextP != Nil){
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                return true;  
            }else{
                NextCoor.hor = CurrCoor.hor - 1;
                NextCoor.ver = CurrCoor.ver + 2;
                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                    return true;
                }else{
                    NextCoor.hor = CurrCoor.hor + 1;
                    NextCoor.ver = CurrCoor.ver + 2;
                    NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                    if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                        return true;
                    }else{
                        NextCoor.hor = CurrCoor.hor + 2;
                        NextCoor.ver = CurrCoor.ver + 1;
                        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                        if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                            return true;
                        }else{
                            NextCoor.hor = CurrCoor.hor + 2;
                            NextCoor.ver = CurrCoor.ver - 1;
                            NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                                return true;
                            }else{
                                NextCoor.hor = CurrCoor.hor + 1;
                                NextCoor.ver = CurrCoor.ver - 2;
                                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                                if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                                    return true;
                                }else{
                                    NextCoor.hor = CurrCoor.hor - 1;
                                    NextCoor.ver = CurrCoor.ver - 2;
                                    NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                                    if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                                        return true;
                                    }else{
                                        NextCoor.hor = CurrCoor.hor - 2;
                                        NextCoor.ver = CurrCoor.ver - 1;
                                        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                                        if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                                            return true;
                                        }else{
                                            return false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }else{
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                return true;  
            }else{
                NextCoor.hor = CurrCoor.hor - 1;
                NextCoor.ver = CurrCoor.ver + 2;
                if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                    return true;
                }else{
                    NextCoor.hor = CurrCoor.hor + 1;
                    NextCoor.ver = CurrCoor.ver + 2;
                    if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                        return true;
                    }else{
                        NextCoor.hor = CurrCoor.hor + 2;
                        NextCoor.ver = CurrCoor.ver + 1;
                        if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                            return true;
                        }else{
                            NextCoor.hor = CurrCoor.hor + 2;
                            NextCoor.ver = CurrCoor.ver - 1;
                            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                                return true;
                            }else{
                                NextCoor.hor = CurrCoor.hor + 1;
                                NextCoor.ver = CurrCoor.ver - 2;
                                if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                                    return true;
                                }else{
                                    NextCoor.hor = CurrCoor.hor - 1;
                                    NextCoor.ver = CurrCoor.ver - 2;
                                    if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                                        return true;
                                    }else{
                                        NextCoor.hor = CurrCoor.hor - 2;
                                        NextCoor.ver = CurrCoor.ver - 1;
                                        if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                                            return true;
                                        }else{
                                            return false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if ((pieces = 'B') && (pieces = 'b')){
        NextCoor.hor = CurrCoor.hor + 1;
        NextCoor.ver = CurrCoor.ver + 1;
        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
        if (NextP != Nil){
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                return true;
            }else{
                NextCoor.hor = CurrCoor.hor + 1;
                NextCoor.ver = CurrCoor.ver - 1;
                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                    return true;
                }else{
                    NextCoor.hor = CurrCoor.hor - 1;
                    NextCoor.ver = CurrCoor.ver - 1;
                    NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                    if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                        return true;
                    }else{
                        NextCoor.hor = CurrCoor.hor - 1;
                        NextCoor.ver = CurrCoor.ver + 1;
                        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                        if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                            return true;
                        }else{
                            return false;
                        }
                    }
                }
            }
        }else{
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                return true;
            }else{
                NextCoor.hor = CurrCoor.hor + 1;
                NextCoor.ver = CurrCoor.ver - 1;
                if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                    return true;
                }else{
                    NextCoor.hor = CurrCoor.hor - 1;
                    NextCoor.ver = CurrCoor.ver - 1;
                    if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                        return true;
                    }else{
                        NextCoor.hor = CurrCoor.hor - 1;
                        NextCoor.ver = CurrCoor.ver + 1;
                        if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                            return true;
                        }else{
                            return false;
                        }
                    }
                }
            }
        }
    }else if ((pieces == 'K') && (pieces == 'Q') && (pieces == 'k') && (pieces == 'q')){
        NextCoor.ver = CurrCoor.ver + 1;
        NextCoor.hor = CurrCoor.hor;
        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
        if (NextP != Nil){
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                return true;  
            }else{
                NextCoor.ver = CurrCoor.ver;
                NextCoor.hor = CurrCoor.hor + 1;
                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                    return true;  
                }else{
                    NextCoor.ver = CurrCoor.ver - 1;
                    NextCoor.hor = CurrCoor.hor;
                    NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                    if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                        return true;
                    }else{
                        NextCoor.ver = CurrCoor.ver;
                        NextCoor.hor = CurrCoor.hor - 1;
                        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                        if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                            return true;
                        }else{
                            NextCoor.hor = CurrCoor.hor + 1;
                            NextCoor.ver = CurrCoor.ver + 1;
                            NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                                return true;
                            }else{
                                NextCoor.hor = CurrCoor.hor + 1;
                                NextCoor.ver = CurrCoor.ver - 1;
                                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                                if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                                    return true;
                                }else{
                                    NextCoor.hor = CurrCoor.hor - 1;
                                    NextCoor.ver = CurrCoor.ver - 1;
                                    NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                                    if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                                        return true;
                                    }else{
                                        NextCoor.hor = CurrCoor.hor - 1;
                                        NextCoor.ver = CurrCoor.ver + 1;
                                        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                                        if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                                            return true;
                                        }else{
                                            return false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }else{
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                return true;  
            }else{
                NextCoor.ver = CurrCoor.ver;
                NextCoor.hor = CurrCoor.hor + 1;
                if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                    return true;  
                }else{
                    NextCoor.ver = CurrCoor.ver - 1;
                    NextCoor.hor = CurrCoor.hor;
                    if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                        return true;
                    }else{
                        NextCoor.ver = CurrCoor.ver;
                        NextCoor.hor = CurrCoor.hor - 1;
                        if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                            return true;
                        }else{
                            NextCoor.hor = CurrCoor.hor + 1;
                            NextCoor.ver = CurrCoor.ver + 1;
                            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                                return true;
                            }else{
                                NextCoor.hor = CurrCoor.hor + 1;
                                NextCoor.ver = CurrCoor.ver - 1;
                                if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                                    return true;
                                }else{
                                    NextCoor.hor = CurrCoor.hor - 1;
                                    NextCoor.ver = CurrCoor.ver - 1;
                                    if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                                        return true;
                                    }else{
                                        NextCoor.hor = CurrCoor.hor - 1;
                                        NextCoor.ver = CurrCoor.ver + 1;
                                        if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                                            return true;
                                        }else{
                                            return false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if (pieces == 'p'){
        NextCoor.ver = CurrCoor.ver + 1;
        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
        if (NextP != Nil){
            if ((NextCoor.hor >= 1) && (NextCoor.hor < 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                return true;
            }else{
                return false;
            }
        }else{
            if ((NextCoor.hor >= 1) && (NextCoor.hor < 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                return true;
            }else{
                return false;
            }
        }
    }else if (pieces == 'P'){
        NextCoor.ver = CurrCoor.ver - 1;
        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
        if (NextP != Nil){
            if ((NextCoor.hor > 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                return true;
            }else{
                return false;
            }
        }else{
            if ((NextCoor.hor > 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isPieces(T.TI[NextCoor.ver][NextCoor.hor]))){
                return true;
            }else{
                return false;
            }
        }
    }
}

void whitepawnsPath (List L, TabChar T, Path *PL, coordinat CurrCoor){
    addressList CurrP, NextP;
    coordinat NextCoor;
    char CurrPieces, NextPieces;
    int check = 1;

    CurrCoor.hor = CharToInt(&CurrCoor.hor);
    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    if (CurrCoor.ver == 2){
        NextCoor.hor = CurrCoor.hor;
        NextCoor.ver = CurrCoor.ver + 1;
        NextPieces = T.TI[NextCoor.ver][NextCoor.hor]; 
        while ((!isPieces(NextPieces)) && (NextCoor.ver <= 4)){
            NextCoor.hor = IntToChar(NextCoor.hor);
            InsVFirstPath(PL, NextCoor);
            NextCoor.ver++;
        }
    }else if (CurrCoor.ver < 8){
        NextCoor.hor = CurrCoor.hor;
        NextCoor.ver = CurrCoor.ver + 1;
        NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
        if (!isPieces(NextPieces)){
            NextCoor.hor = IntToChar(NextCoor.hor);
            InsVFirstPath(PL, NextCoor);
        }
    }

    while (check <= 2){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver + 1;
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver + 1;
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }
            }
            check++;
        }
    }
}

void blackpawnsPath (List L, TabChar T, Path *PL, coordinat CurrCoor){
    addressList CurrP, NextP;
    coordinat NextCoor;
    char CurrPieces, NextPieces;
    int check = 1;

    CurrCoor.hor = CharToInt(&CurrCoor.hor);
    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    if (CurrCoor.ver == 7){
        NextCoor.hor = CurrCoor.hor;
        NextCoor.ver = CurrCoor.ver - 1;
        NextPieces = T.TI[NextCoor.ver][NextCoor.hor]; 
        while ((!isPieces(NextPieces)) && (NextCoor.ver >= 5)){
            NextCoor.hor = IntToChar(NextCoor.hor);
            InsVFirstPath(PL, NextCoor);
            NextCoor.ver++;
        }
    }else if (CurrCoor.ver > 1){
        NextCoor.hor = CurrCoor.hor;
        NextCoor.ver = CurrCoor.ver - 1;
        NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
        if (!isPieces(NextPieces)){
            NextCoor.hor = IntToChar(NextCoor.hor);
            InsVFirstPath(PL, NextCoor);
        }
    }

    while (check <= 2){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver - 1;
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver - 1;
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }
            }
            check++;
        }
    }
}

void rooksPath (List L, TabChar T, Path *PL, coordinat CurrCoor){
    addressList CurrP, NextP;
    coordinat NextCoor;
    char CurrPieces, NextPieces;
    int check = 1; 
    
    CurrCoor.hor = CharToInt(&CurrCoor.hor);
    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    while (check <= 4){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver;
            while (NextCoor.hor >= 1){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor--;
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor;
            NextCoor.ver = CurrCoor.ver + 1;
            while (NextCoor.ver <= 8){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.ver++;
            }
            check++;
        }else if (check == 3){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver;
            while (NextCoor.hor <= 8){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor++;
            }
            check++;
        }else if (check == 4){
            NextCoor.hor = CurrCoor.hor;
            NextCoor.ver = CurrCoor.ver - 1;
            while (NextCoor.ver >= 1){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.ver--;
            }
            check++;
        }
    }
}

void horsesPath (List L, TabChar T, Path *PL, coordinat CurrCoor){
    addressList CurrP, NextP;
    coordinat NextCoor;
    char CurrPieces, NextPieces;
    int check = 1; 
    
    CurrCoor.hor = CharToInt(&CurrCoor.hor);
    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    while (check <= 8){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 2;
            NextCoor.ver = CurrCoor.ver + 1;
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver + 2;
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 3){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver + 2;
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 4){
            NextCoor.hor = CurrCoor.hor + 2;
            NextCoor.ver = CurrCoor.ver + 1;
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 5){
            NextCoor.hor = CurrCoor.hor + 2;
            NextCoor.ver = CurrCoor.ver - 1;
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 6){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver - 2;
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 7){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver - 2;
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 8){
            NextCoor.hor = CurrCoor.hor - 2;
            NextCoor.ver = CurrCoor.ver - 1;
            if ((NextCoor.hor >= 1) && (NextCoor.hor <= 8) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }
    }
}

void bishopsPath (List L, TabChar T, Path *PL, coordinat CurrCoor){
    addressList CurrP, NextP;
    coordinat NextCoor;
    char CurrPieces, NextPieces;
    int check = 1; 
    
    CurrCoor.hor = CharToInt(&CurrCoor.hor);
    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    while (check <= 4){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver + 1;
            while ((NextCoor.hor >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor--;
                NextCoor.ver++;
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver + 1;
            while ((NextCoor.hor <= 8) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor++;
                NextCoor.ver++;
            }
            check++;
        }else if (check == 3){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver - 1;
            while ((NextCoor.hor <= 8) && (NextCoor.ver >= 1)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor++;
                NextCoor.ver--;
            }
            check++;
        }else if (check == 4){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver - 1;
            while ((NextCoor.hor >= 1) && (NextCoor.ver >= 1)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor--;
                NextCoor.ver--;
            }
            check++;
        }
    }
}

void queesPath (List L, TabChar T, Path *PL, coordinat CurrCoor){
    addressList CurrP, NextP;
    coordinat NextCoor;
    char CurrPieces, NextPieces;
    int check = 1; 

    CurrCoor.hor = CharToInt(&CurrCoor.hor);
    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    while (check <= 8){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver;
            while (NextCoor.hor >= 1){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor--;
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver + 1;
            while ((NextCoor.hor >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor--;
                NextCoor.ver++;
            }
            check++;
        }else if (check == 3){
            NextCoor.hor = CurrCoor.hor;
            NextCoor.ver = CurrCoor.ver + 1;
            while (NextCoor.ver <= 8){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.ver++;
            }
            check++;
        }else if (check == 4){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver + 1;
            while ((NextCoor.hor <= 8) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor++;
                NextCoor.ver++;
            }
            check++;
        }else if (check == 5){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver;
            while (NextCoor.hor <= 8){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor++;
            }
            check++;
        }else if (check == 6){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver - 1;
            while ((NextCoor.hor <= 8) && (NextCoor.ver >= 1)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor++;
                NextCoor.ver--;
            }
            check++;
        }else if (check == 7){
            NextCoor.hor = CurrCoor.hor;
            NextCoor.ver = CurrCoor.ver - 1;
            while (NextCoor.ver >= 1){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.ver--;
            }
            check++;
        }else if (check == 8){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver - 1;
            while ((NextCoor.hor >= 1) && (NextCoor.ver >= 1)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor--;
                NextCoor.ver--;
            }
            check++;
        }
    }
}

void kingsPath (List L, TabChar T, Path *PL, coordinat CurrCoor){
    addressList CurrP, NextP;
    coordinat NextCoor;
    char CurrPieces, NextPieces;
    int check = 1; 

    CurrCoor.hor = CharToInt(&CurrCoor.hor);
    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    while (check <= 8){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver;
            if (NextCoor.hor >= 1){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver + 1;
            if ((NextCoor.hor >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 3){
            NextCoor.hor = CurrCoor.hor;
            NextCoor.ver = CurrCoor.ver + 1;
            if (NextCoor.ver <= 8){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 4){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver + 1;
            if ((NextCoor.hor <= 8) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 5){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver;
            if (NextCoor.hor <= 8){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 6){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver - 1;
            if ((NextCoor.hor <= 8) && (NextCoor.ver >= 1)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 7){
            NextCoor.hor = CurrCoor.hor;
            NextCoor.ver = CurrCoor.ver - 1;
            if (NextCoor.ver >= 1){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 8){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver - 1;
            if ((NextCoor.hor >= 1) && (NextCoor.ver >= 1)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (NextP != Nil){
                    if (!isAlly(Team(CurrP), Team(NextP))){
                        InsVFirstPath(PL, NextCoor);
                    }
                }else{
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }
    }
}

void kill (List L, TabChar T, coordinat CurrCoor, coordinat NextCoor)
{
    addressList CurrP, NextP;
    char CurrPieces, NextPieces;


    CurrCoor.hor = CharToInt(&CurrCoor.hor);
    NextCoor.hor = CharToInt(&NextCoor.hor);
    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);
    NextP = SearchList(L,NextPieces,NextCoor);


    if (isPiecesMove(L,T,pieces,CurrCoor) && (!isAlly(Team(CurrP),Team(NextP)))) 
    {
        Info(NextP) = Info(CurrP);
        DealokasiList(CurrP);
    }    
}


void castling(List L, TabChar T, coordinat KingCoor, coordinat RooksCoor)
{
    addressList KingP, RooksP;
    char KingPieces, RooksPieces;


    KingCoor.hor = CharToInt(&KingCoor.hor);
    RooksCoor.hor = CharToInt(&RooksCoor.hor);
    KingPieces = T.TI[KingCoor.ver][KingCoor.hor];
    RooksPieces = T.TI[RooksCoor.ver][RooksCoor.hor];
    KingP = SearchList(L,KingPieces,KingCoor);
    RooksP = SearchList(L,RooksPieces,RooksCoor);

    if (Iscastling(L,T,KingCoor,RooksCoor))
    {
        if (Team(King) == 200)
        {
            Horizontal(KingP) = Horizontal(KingP) + 2;
            Horizontal(RooksP) = Horizontal (RooksP) - 2;
        } else if (Team(King)==100)
        {
            Horizontal(KingP) = Horizontal(KingP) - 2;
            Horizontal(RooksP) = Horizontal(RooksP) + 2;
        }
    }
    
}

boolean Iscastling (List L, TabChar T, coordinat KingCoor, coordinat RooksCoor)
{
    addressList KingP, RooksP;
    char KingPieces, RooksPieces;


    KingCoor.hor = CharToInt(&KingCoor.hor);
    RooksCoor.hor = CharToInt(&RooksCoor.hor);
    KingPieces = T.TI[KingCoor.ver][KingCoor.hor];
    RooksPieces = T.TI[RooksCoor.ver][RooksCoor.hor];
    KingP = SearchList(L,KingPieces,KingCoor);
    RooksP = SearchList(L,RooksPieces,RooksCoor);

    if (((Info(KingP)=='K') || (Info(KingP)=='k')) && ((Info(RooksP)=='R') || (Info(RooksP)=='r')) )
    {
        if ((KingCoor.hor == 5) && (KingCoor.ver == 8) && (RooksCoor.hor == 8) && (RooksCoor.ver == 8))
        {
            return true;
        } else if ((KingCoor.hor == 4) && (KingCoor.ver == 1) && (RooksCoor.hor == 1) && (RooksCoor.ver == 1))
        {
            return true;
        } else
        {
            return false;
        }
    }
}