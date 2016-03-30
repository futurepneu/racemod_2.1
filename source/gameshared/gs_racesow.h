#ifndef __GS_RACESOW_H
#define __GS_RACESOW_H

#ifdef __cplusplus
extern "C" {
#endif

void RS_ResetPjState(int playerNum);
bool RS_QueryPjState(int playerNum);
void RS_IncrementWallJumps(int playerNum);
void RS_IncrementDashes(int playerNum);
void RS_IncrementJumps(int playerNum);

#ifdef __cplusplus
};
#endif

#endif // __GS_RACESOW_H