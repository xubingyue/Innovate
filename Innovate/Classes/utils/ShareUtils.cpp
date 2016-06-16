//
//  ShareUtils.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/15.
//
//


#include "ShareUtils.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS|| CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
#include "../oc/OCNative.h"
#endif



void ShareUtils::shareToWeChat()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS|| CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    OCNative::shareToWeChat();
#endif
}