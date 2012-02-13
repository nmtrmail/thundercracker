/* -*- mode: C; c-basic-offset: 4; intent-tabs-mode: nil -*-
 *
 * Copyright <c> 2012 Sifteo, Inc. All rights reserved.
 */

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SIFTEO_BUDDIES_APP_H_
#define SIFTEO_BUDDIES_APP_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <sifteo/audio.h>
#include "Config.h"
#include "CubeWrapper.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

namespace Buddies {

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

class App
{
public:
    App();
    
    void Setup();
    void Tick(float dt);
    void Paint();
    
    void AddCube(Sifteo::Cube::ID cubeId);
    void RemoveCube(Sifteo::Cube::ID cubeId);
    
    CubeWrapper &GetWrapper(Sifteo::Cube::ID cubeId);
    
    void OnNeighborAdd(Sifteo::Cube::ID cubeId0, Sifteo::Cube::Side cubeSide0, Sifteo::Cube::ID cubeId1, Sifteo::Cube::Side cubeSide1);
    void OnTilt(Sifteo::Cube::ID cubeId);
    void OnShake(Sifteo::Cube::ID cubeId);
    
private:
    bool AnyTouching() const;
    bool AllSolved() const;
    
    void Reset();
    void ShufflePiece();
    
    CubeWrapper mWrappers[kNumCubes];
    Sifteo::AudioChannel mChannel;
    float mResetTimer;
    
    ShuffleState mShuffleState;
    float mShuffleStateTimer;
    float mShuffleScrambleTimer;
    bool mShufflePiecesMoved[NUM_SIDES * kNumCubes];
    float mShuffleScoreTime;
    
    SwapState mSwapState;
    unsigned int mSwapPiece0;
    unsigned int mSwapPiece1;
    int mSwapAnimationCounter;
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
