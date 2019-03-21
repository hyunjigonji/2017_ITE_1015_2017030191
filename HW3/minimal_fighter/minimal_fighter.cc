#include <stdio.h>
#include "minimal_fighter.h"

MinimalFighter::MinimalFighter(){
    mHp = 0;
    mPower = 0;
    mStatus = Invalid;
}

MinimalFighter::MinimalFighter(int _hp,int _power){
    mHp = _hp;
    mPower = _power;
    if(mHp<=0) mStatus = Dead;
    else mStatus = Alive;
}

int MinimalFighter::hp() const{
    return mHp;
}

int MinimalFighter::power() const{
    return mPower;
}

FighterStatus MinimalFighter::status() const{
    if(mHp<=0) return Dead;
    else return Alive;
}

void MinimalFighter::setHp(int _hp){
    mHp = _hp;
}

void MinimalFighter::hit(MinimalFighter *_enemy){
    mHp -= _enemy->mPower;
    _enemy->mHp -= mPower;
}

void MinimalFighter::attack(MinimalFighter *_target){
    _target->mHp -= mPower;
    mPower = 0;
}

void MinimalFighter::fight(MinimalFighter *_enemy){
    while(mHp!=0 && _enemy->mHp!=0){
        mHp -= _enemy->mPower;
        _enemy->mHp -= mPower;
    }
}
