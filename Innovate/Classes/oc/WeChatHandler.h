//
//  WeChatHandler.hpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/15.
//
//

#ifndef WeChatHandler_hpp
#define WeChatHandler_hpp

#import "WXApi.h"

@class WeChatHandler;

@interface WeChatHandler : NSObject <WXApiDelegate>

+ (instancetype)sharedManager;

- (void)dealloc;


#pragma mark - WXApiDelegate
- (void)onResp:(BaseResp *)resp;

- (void)onReq:(BaseReq *)req;

@end

#endif /* WeChatHandler_hpp */
