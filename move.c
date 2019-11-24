#include <stdio.h>
#include <stdlib.h>
#include "move.h"

boolean isAlly (int team1, int team2){
    return (team1 == team2);
}

boolean isPieces (char pieces){
    return (pieces != ' ');
}

boolean isCheckMate (List L, List AllyMovement, TabChar T, int *team){
    List EnemyMovement, EnemyKingKiller; Path PL, EKPL;
    addressList P, KingP, EnemyKingKillerP; addressPath PP, EKPP;
    boolean found; coordinat CurrCoor, NextCoor;

    if (*team == white){
        *team = black;
    }else if (*team == black){
        *team = white;
    }

    piecesMove(L,&EnemyMovement,T,team);

    if (*team == white){
        KingP = SearchListPieces(L,'k');
    }else if (*team == black){
        KingP = SearchListPieces(L,'K');
    }

    printf("(%c,%d)\n", Horizontal(KingP), Vertical(KingP));

    P = First(AllyMovement); P = Next(P);
    PrintInfoList(AllyMovement);
    CreateEmptyList(&EnemyKingKiller);
    while (P != Nil){
        posMove(L,P,T,&PL);
        PP = First(PL); found = false;
        while ((PP != Nil) && (!found)){
            if ((Horizontal(PP) == Horizontal(KingP)) && (Vertical(PP) == Vertical(KingP))){
                printf("NYAMPE");
                InsVLastList(&EnemyKingKiller,Info(P),Team(P),Coor(P));
                found = true;
            }
            PP = Next(PP);
        }
        P = Next(P);
    }

    PrintInfoList(EnemyKingKiller);

    EnemyKingKillerP = First(EnemyKingKiller);
    if (EnemyKingKillerP != Nil){
        CreateEmptyPath(&EKPL);
        kingsPath(L,T,&EKPL,Coor(KingP));
        EKPP = First(EKPL);
        while((EKPP != Nil) && (!found)){
            P = First(AllyMovement);
            CreateEmptyList(&EnemyKingKiller);
            while (P != Nil){
                posMove(L,P,T,&PL);
                PP = First(PL); found = false;
                while ((PP != Nil) && (!found)){
                    if ((Horizontal(PP) == Horizontal(EKPP)) && (Vertical(PP) == Vertical(EKPP))){
                        InsVFirstList(&EnemyKingKiller,Info(P),Team(P),Coor(P));
                        found = true;
                    }
                    PP = Next(PP);
                }
                P = Next(P);
            }
            EnemyKingKillerP = First(EnemyKingKiller);
            if (EnemyKingKillerP != Nil){
                EKPP = Next(EKPP);
            }else{
                found = true;
            }
        }
    }

    if (found){
        return false;
    }else{
        return true;
    }


    /*
    found = false;
    P = First(M);
    while ((P != Nil) && (!found)){
        if (Info(P) == 'P'){
            blackpawnsPath(L,T,&PL,CurrCoor);
        }else if (Info(P) == 'p'){
            whitepawnsPath(L,T,&PL,CurrCoor);
        }else if ((Info(P) == 'R') || (Info(P) == 'r')){
            rooksPath(L,T,&PL,CurrCoor);
        }else if ((Info(P) == 'H') || (Info(P) == 'h')){
            horsesPath(L,T,&PL,CurrCoor);
        }else if ((Info(P) == 'B') || (Info(P) == 'b')){
            bishopsPath(L,T,&PL,CurrCoor);
        }else if ((Info(P) == 'Q') || (Info(P) == 'q')){
            queesPath(L,T,&PL,CurrCoor);
        }else if ((Info(P) == 'K') || (Info(P) == 'k')){
            kingsPath(L,T,&PL,CurrCoor);
        }
    }
    */
}

boolean isKingDead (List L){
    addressList P; int found;

    P = First(L);
    found = 0;
    while (P != Nil){
        if ((Info(P) == 'K') || (Info(P) == 'k')){
            found++;
        }
        P = Next(P);
    }
    return (found != 2);
}

boolean isPiecesMove (List L, TabChar T, char pieces, coordinat CurrCoor){
    coordinat NextCoor;
    addressList CurrP, NextP;

    CurrP = SearchList(L,pieces,CurrCoor);

    if ((pieces == 'R') || (pieces == 'r')){
        NextCoor.ver = CurrCoor.ver + 1;
        NextCoor.hor = CurrCoor.hor;
        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
        if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
            return true;  
        }else{
            NextCoor.ver = CurrCoor.ver;
            NextCoor.hor = CurrCoor.hor + 1;
            NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                return true;  
            }else{
                NextCoor.ver = CurrCoor.ver - 1;
                NextCoor.hor = CurrCoor.hor;
                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                    return true;
                }else{
                    NextCoor.ver = CurrCoor.ver;
                    NextCoor.hor = CurrCoor.hor - 1;
                    NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                    if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                        return true;
                    }else{
                        return false;
                    }
                }
            }
        }
    }else if ((pieces == 'H') || (pieces == 'h')){
        NextCoor.hor = CurrCoor.hor - 2;
        NextCoor.ver = CurrCoor.ver + 1;
        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
        if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && ((!isAlly(Team(CurrP),Team(NextP))))){
            return true;
        }else{
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver + 2;
            NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && ((!isAlly(Team(CurrP),Team(NextP))))){
                return true;
            }else{
                NextCoor.hor = CurrCoor.hor + 1;
                NextCoor.ver = CurrCoor.ver + 2;
                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && ((!isAlly(Team(CurrP),Team(NextP))))){
                    return true;
                }else{
                    NextCoor.hor = CurrCoor.hor + 2;
                    NextCoor.ver = CurrCoor.ver + 1;
                    NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                    if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && ((!isAlly(Team(CurrP),Team(NextP))))){
                        return true;
                    }else{
                        NextCoor.hor = CurrCoor.hor + 2;
                        NextCoor.ver = CurrCoor.ver - 1;
                        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                        if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && ((!isAlly(Team(CurrP),Team(NextP))))){
                            return true;
                        }else{
                            NextCoor.hor = CurrCoor.hor + 1;
                            NextCoor.ver = CurrCoor.ver - 2;
                            NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && ((!isAlly(Team(CurrP),Team(NextP))))){
                                return true;
                            }else{
                                NextCoor.hor = CurrCoor.hor - 1;
                                NextCoor.ver = CurrCoor.ver - 2;
                                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                                if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && ((!isAlly(Team(CurrP),Team(NextP))))){
                                    return true;
                                }else{
                                    NextCoor.hor = CurrCoor.hor - 2;
                                    NextCoor.ver = CurrCoor.ver - 1;
                                    NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                                    if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && ((!isAlly(Team(CurrP),Team(NextP))))){
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
    }else if ((pieces == 'B') || (pieces == 'b')){
        NextCoor.hor = CurrCoor.hor + 1;
        NextCoor.ver = CurrCoor.ver + 1;
        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
        if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
            return true;
        }else{
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver - 1;
            NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                return true;
            }else{
                NextCoor.hor = CurrCoor.hor - 1;
                NextCoor.ver = CurrCoor.ver - 1;
                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                    return true;
                }else{
                    NextCoor.hor = CurrCoor.hor - 1;
                    NextCoor.ver = CurrCoor.ver + 1;
                    NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                    if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                        return true;
                    }else{
                        return false;
                    }
                }
            }
        }
    }else if ((pieces == 'K') || (pieces == 'Q') || (pieces == 'k') || (pieces == 'q')){
        NextCoor.ver = CurrCoor.ver + 1;
        NextCoor.hor = CurrCoor.hor;
        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
        if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
            return true;  
        }else{
            NextCoor.ver = CurrCoor.ver;
            NextCoor.hor = CurrCoor.hor + 1;
            NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                return true;  
            }else{
                NextCoor.ver = CurrCoor.ver - 1;
                NextCoor.hor = CurrCoor.hor;
                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                    return true;
                }else{
                    NextCoor.ver = CurrCoor.ver;
                    NextCoor.hor = CurrCoor.hor - 1;
                    NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                    if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                        return true;
                    }else{
                        NextCoor.hor = CurrCoor.hor + 1;
                        NextCoor.ver = CurrCoor.ver + 1;
                        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                        if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                            return true;
                        }else{
                            NextCoor.hor = CurrCoor.hor + 1;
                            NextCoor.ver = CurrCoor.ver - 1;
                            NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                                return true;
                            }else{
                                NextCoor.hor = CurrCoor.hor - 1;
                                NextCoor.ver = CurrCoor.ver - 1;
                                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                                if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
                                    return true;
                                }else{
                                    NextCoor.hor = CurrCoor.hor - 1;
                                    NextCoor.ver = CurrCoor.ver + 1;
                                    NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                                    if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8) && (!isAlly(Team(CurrP),Team(NextP)))){
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
    }else if (pieces == 'p'){
        NextCoor.ver = CurrCoor.ver + 1;
        NextCoor.hor = CurrCoor.hor;
        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
        if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver < 8) && (!isPieces(Info(NextP))) && (!isAlly(Team(CurrP),Team(NextP)))){
            return true;
        }else{
            NextCoor.ver = CurrCoor.ver + 1;
            NextCoor.hor = CurrCoor.hor + 1;
            NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver < 8) && (isPieces(Info(NextP))) && (!isAlly(Team(CurrP),Team(NextP)))){
                return true;
            }else{
                NextCoor.ver = CurrCoor.ver + 1;
                NextCoor.hor = CurrCoor.hor - 1;
                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver < 8) && (isPieces(Info(NextP))) && (!isAlly(Team(CurrP),Team(NextP)))){
                    return true;
                }else{
                    return false;
                }
            }
        }
    }else if (pieces == 'P'){
        NextCoor.ver = CurrCoor.ver - 1;
        NextCoor.hor = CurrCoor.hor;
        NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
        if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver > 1) && (NextCoor.ver <= 8) && (!isPieces(Info(NextP))) && (!isAlly(Team(CurrP),Team(NextP)))){
            return true;
        }else{
            NextCoor.ver = CurrCoor.ver - 1;
            NextCoor.hor = CurrCoor.hor + 1;
            NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver > 1) && (NextCoor.ver <= 8) && (isPieces(Info(NextP))) && (!isAlly(Team(CurrP),Team(NextP)))){
                return true;
            }else{
                NextCoor.ver = CurrCoor.ver - 1;
                NextCoor.hor = CurrCoor.hor - 1;
                NextP = SearchList(L,T.TI[NextCoor.ver][NextCoor.hor],NextCoor);
                if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver > 1) && (NextCoor.ver <= 8) && (isPieces(Info(NextP))) && (!isAlly(Team(CurrP),Team(NextP)))){
                    return true;
                }else{
                    return false;
                }
            }
        }
    }
}

void whitepawnsPath (List L, TabChar T, Path *PL, coordinat CurrCoor){
    addressList CurrP, NextP;
    coordinat NextCoor;
    char CurrPieces, NextPieces;
    int check = 1;

    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    if (CurrCoor.ver == 2){
        NextCoor.hor = CurrCoor.hor;
        NextCoor.ver = CurrCoor.ver + 1;
        NextPieces = T.TI[NextCoor.ver][NextCoor.hor]; 
        while ((!isPieces(NextPieces)) && (NextCoor.ver <= 4)){
            InsVFirstPath(PL, NextCoor);
            NextCoor.ver++;
        }
    }else if (CurrCoor.ver < 8){
        NextCoor.hor = CurrCoor.hor;
        NextCoor.ver = CurrCoor.ver + 1;
        NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
        if (!isPieces(NextPieces)){
            InsVFirstPath(PL, NextCoor);
        }
    }

    while (check <= 2){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver + 1;
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver + 1;
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
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

    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    if (CurrCoor.ver == 7){
        NextCoor.hor = CurrCoor.hor;
        NextCoor.ver = CurrCoor.ver - 1;
        NextPieces = T.TI[NextCoor.ver][NextCoor.hor]; 
        while ((!isPieces(NextPieces)) && (NextCoor.ver >= 5)){
            InsVFirstPath(PL, NextCoor);
            NextCoor.ver--;
        }
    }else if (CurrCoor.ver > 1){
        NextCoor.hor = CurrCoor.hor;
        NextCoor.ver = CurrCoor.ver - 1;
        NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
        if (!isPieces(NextPieces)){
            InsVFirstPath(PL, NextCoor);
        }
    }

    while (check <= 2){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver - 1;
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver - 1;
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
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
    int check = 1; boolean blocked;

    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    while (check <= 4){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver;
            blocked = false;
            while ((NextCoor.hor >= 97) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor--;
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor;
            NextCoor.ver = CurrCoor.ver + 1;
            blocked = false;
            while ((NextCoor.ver <= 8) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.ver++;
            }
            check++;
        }else if (check == 3){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver;
            blocked = false;
            while ((NextCoor.hor <= 104) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor++;
            }
            check++;
        }else if (check == 4){
            NextCoor.hor = CurrCoor.hor;
            NextCoor.ver = CurrCoor.ver - 1;
            blocked = false;
            while ((NextCoor.ver >= 1) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
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

    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    while (check <= 8){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 2;
            NextCoor.ver = CurrCoor.ver + 1;
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver + 2;
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 3){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver + 2;
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 4){
            NextCoor.hor = CurrCoor.hor + 2;
            NextCoor.ver = CurrCoor.ver + 1;
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 5){
            NextCoor.hor = CurrCoor.hor + 2;
            NextCoor.ver = CurrCoor.ver - 1;
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 6){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver - 2;
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 7){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver - 2;
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 8){
            NextCoor.hor = CurrCoor.hor - 2;
            NextCoor.ver = CurrCoor.ver - 1;
            if ((NextCoor.hor >= 97) && (NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
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
    int check = 1; boolean blocked;

    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    while (check <= 4){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver + 1;
            blocked = false;
            while ((NextCoor.hor >= 97) && (NextCoor.ver <= 8) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor--;
                NextCoor.ver++;
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver + 1;
            blocked = false;
            while ((NextCoor.hor <= 104) && (NextCoor.ver <= 8) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor++;
                NextCoor.ver++;
            }
            check++;
        }else if (check == 3){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver - 1;
            blocked = false;
            while ((NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor++;
                NextCoor.ver--;
            }
            check++;
        }else if (check == 4){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver - 1;
            blocked = false;
            while ((NextCoor.hor >= 97) && (NextCoor.ver >= 1) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
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
    int check = 1; boolean blocked;

    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    while (check <= 8){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver;
            blocked = false;
            while ((NextCoor.hor >= 97) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor--;
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver + 1;
            blocked = false;
            while ((NextCoor.hor >= 97) && (NextCoor.ver <= 8) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor--;
                NextCoor.ver++;
            }
            check++;
        }else if (check == 3){
            NextCoor.hor = CurrCoor.hor;
            NextCoor.ver = CurrCoor.ver + 1;
            blocked = false;
            while ((NextCoor.ver <= 8) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.ver++;
            }
            check++;
        }else if (check == 4){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver + 1;
            blocked = false;
            while ((NextCoor.hor <= 104) && (NextCoor.ver <= 8) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor++;
                NextCoor.ver++;
            }
            check++;
        }else if (check == 5){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver;
            blocked = false;
            while ((NextCoor.hor <= 104) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor++;
            }
            check++;
        }else if (check == 6){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver - 1;
            blocked = false;
            while ((NextCoor.hor <= 104) && (NextCoor.ver >= 1) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.hor++;
                NextCoor.ver--;
            }
            check++;
        }else if (check == 7){
            NextCoor.hor = CurrCoor.hor;
            NextCoor.ver = CurrCoor.ver - 1;
            blocked = false;
            while ((NextCoor.ver >= 1) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
                NextCoor.ver--;
            }
            check++;
        }else if (check == 8){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver - 1;
            blocked = false;
            while ((NextCoor.hor >= 97) && (NextCoor.ver >= 1) && (!blocked)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if ((isPieces(Info(NextP))) && (!isAlly(Team(CurrP), Team(NextP)))){
                    InsVFirstPath(PL, NextCoor);
                    blocked = true;
                }else if ((isPieces(Info(NextP))) && (isAlly(Team(CurrP), Team(NextP)))){
                    blocked = true;
                }else if (!isPieces(Info(NextP))){
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

    CurrPieces = T.TI[CurrCoor.ver][CurrCoor.hor];
    CurrP = SearchList(L,CurrPieces,CurrCoor);

    while (check <= 8){
        if (check == 1){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver;
            if (NextCoor.hor >= 97){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 2){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver + 1;
            if ((NextCoor.hor >= 97) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
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
                if (!isAlly(Team(CurrP), Team(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 4){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver + 1;
            if ((NextCoor.hor <= 104) && (NextCoor.ver <= 8)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 5){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver;
            if (NextCoor.hor <= 104){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 6){
            NextCoor.hor = CurrCoor.hor + 1;
            NextCoor.ver = CurrCoor.ver - 1;
            if ((NextCoor.hor <= 104) && (NextCoor.ver >= 1)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
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
                if (!isAlly(Team(CurrP), Team(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }else if (check == 8){
            NextCoor.hor = CurrCoor.hor - 1;
            NextCoor.ver = CurrCoor.ver - 1;
            if ((NextCoor.hor >= 97) && (NextCoor.ver >= 1)){
                NextPieces = T.TI[NextCoor.ver][NextCoor.hor];
                NextP = SearchList(L,NextPieces,NextCoor);
                if (!isAlly(Team(CurrP), Team(NextP))){
                    InsVFirstPath(PL, NextCoor);
                }
            }
            check++;
        }
    }
}