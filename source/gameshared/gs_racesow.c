#include "q_arch.h"
#include "q_math.h"
#include "q_shared.h"
#include "q_comref.h"
#include "q_collision.h"
#include "gs_public.h"

// Prejump validation
static int pj_jumps[MAX_CLIENTS] = {0};
static int pj_dashes[MAX_CLIENTS] = {0};
static int pj_walljumps[MAX_CLIENTS] = {0};

/**
 * RS_ResetPjState
 * Fully reset the prejump state for a given player
 * @param playerNum the player's client number
 */
void RS_ResetPjState(int playerNum)
{
	pj_jumps[playerNum] = 0;
	pj_dashes[playerNum] = 0;
	pj_walljumps[playerNum] = 0;
}

/**
 * RS_IncrementJumps
 * Increment the jump count for a given player
 * @param playerNum the player's client number
 */
void RS_IncrementJumps(int playerNum)
{
	pj_jumps[playerNum]++;
}

/**
 * RS_IncrementDashes
 * Increment the dash count for a given player
 * @param playerNum the player's client number
 */
void RS_IncrementDashes(int playerNum)
{
	pj_dashes[playerNum]++;
}

/**
 * RS_IncrementWallJumps
 * Increment the dash count for a given player
 * @param playerNum the player's client number
 */
void RS_IncrementWallJumps(int playerNum)
{
	pj_walljumps[playerNum]++;
}

/**
 * RS_QueryPjState
 * Determines if the player has prejumped or not
 * @param playerNum the player's client number
 * @return true if the player has prejumped
 */
bool RS_QueryPjState(int playerNum)
{
	if ( pj_jumps[playerNum] > 1 ||
		pj_dashes[playerNum] > 1 ||
		pj_walljumps[playerNum] > 1 )
		return true;
	else
		return false;
}